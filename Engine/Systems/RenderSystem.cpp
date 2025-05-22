#include "Engine/Systems/RenderSystem.h"
#include "Engine/Logger/Logger.h"
#include "Engine/Components/PositionComponent.h"
#include "Engine/Components/SpriteComponent.h"
#include "Engine/Components/SquareComponent.h"
#include "Engine/Components/CameraComponent.h"
#include "Engine/Components/TextComponent.h"

#define COLL_DEBUG 0

/* loading the text spritesheet. */
TextureManager TextComponent::tm = TextureManager(font, FONT_SH_WIDTH, FONT_SH_HEIGHT, FONT_WIDTH, FONT_HEIGHT);

RenderSystem::RenderSystem(Canvas* canvas, Display* display): canvas(canvas), display(display) {}

void RenderSystem::update(const std::vector<Entity*>& entities){
    /* get camera if null. */
    if(this->camera == nullptr){ this->camera = search_for_camera(entities); }

    const int camera_right = camera->x + camera->width;
    const int camera_bottom =camera->y + camera->height;

    /* redraws everything. */
    canvas->clear();

    for(const auto& entity : entities){

        /* getting sprite and position components. */
        SpriteComponent* sprite = (SpriteComponent*) entity->get_component("SpriteComponent");
        PositionComponent* p = (PositionComponent*) entity->get_component("PositionComponent");

        /* rendering textures */
        if(sprite && p){
            
            /* skipping components that are not in the scene. */
            if (p->x + sprite->width < camera->x || p->x > camera_right || 
                p->y + sprite->height < camera->y || p->y > camera_bottom) {
                continue;
            }

            const uint16_t* texture = sprite->get_sprite();
            if(texture == nullptr) continue;

            int screen_x = (p->x - this->camera->x) * this->camera->zoom;
            int screen_y = (p->y - this->camera->y) * this->camera->zoom; 

            canvas->draw_sprite(screen_x, screen_y, sprite->width, sprite->height, texture);
        }

        /* rendering text */
        TextComponent* text = (TextComponent*) entity->get_component("TextComponent");
        if (text) {
            int text_x = (text->x - this->camera->x) * this->camera->zoom;
            int text_y = (text->y - this->camera->y) * this->camera->zoom;

            const char* str = text->text.c_str();
            while (*str) {

                /* get_tile dinamically allocates memory. */
                const uint16_t* c_texture = TextComponent::tm.get_tile(*str);

                canvas->draw_sprite(text_x, text_y, FONT_WIDTH, FONT_HEIGHT, c_texture);
                text_x += FONT_WIDTH;
                str++;

                /* taking care of memory =) */
                delete[] c_texture;
            }
        }

        /* DEBUG DIRECTIVE */
        #if COLL_DEBUG == 1
        /* rendering squares */
        SquareComponent* sq = (SquareComponent*) entity->get_component("SquareComponent");
        if(sq && p){
            if (sq->is_visible) {
                // int screen_x = (p->x - this->camera->x) * this->camera->zoom;
                // int screen_y = (p->y - this->camera->y) * this->camera->zoom;
                // int screen_w = (p->x + sq->get_width() - this->camera->x) * this->camera->zoom;
                // int screen_h = (p->y + sq->get_height() - this->camera->y) * this->camera->zoom;

                int screen_x = (p->x - camera->x) * camera->zoom;
                int screen_y = (p->y - camera->y) * camera->zoom;
                int screen_w = sq->get_width() * camera->zoom;
                int screen_h = sq->get_height() * camera->zoom;
                

                if (screen_x + screen_w < 0 || screen_x > canvas->get_width() ||
                screen_y + screen_h < 0 || screen_y > canvas->get_height()) {
                    continue;
                }

                canvas->draw_rect(screen_x, screen_y, screen_w, screen_h, sq->get_color());
            }
        }
        #endif
    
    }
    /* flushes to display. */
    display->flush(canvas->get_buffer());
}

/* 
    search for the first entity that has a camera component 
    if no entity have a camera then create a static one at (0, 0);
*/
CameraComponent* RenderSystem::search_for_camera(const std::vector<Entity*>& entities){
    /* this new piece of code seems unefficient... i'm testing sth and will 100% modify it later..*/
    CameraComponent* camera = nullptr;

    /* searching for the camera */
    for(const auto& entity: entities){
        if(entity->has_component("CameraComponent")){
            camera = (CameraComponent*) entity->get_component("CameraComponent");
            break;
        }
    }
    
    /* if no camera then create a static camera in (0,0) */
    if(!camera){
        camera = new CameraComponent(0, 0, 128, 128, 1);
    }

    /* return camera */
    return camera;
}