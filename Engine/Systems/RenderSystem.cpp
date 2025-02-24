#include "Engine/Systems/RenderSystem.h"
#include "Engine/Logger/Logger.h"
#include "Engine/Components/PositionComponent.h"
#include "Engine/Components/SpriteComponent.h"
#include "Engine/Components/SquareComponent.h"
#include "Engine/Components/CameraComponent.h"

RenderSystem::RenderSystem(Canvas& canvas, Display& display): canvas(canvas), display(display) {
    //

}

RenderSystem::~RenderSystem(){
    //
}

void RenderSystem::update(const std::vector<Entity*>& entities){
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

    /* clears the canvas*/
    canvas.fill(0x0000);

    /* redraws everything. */
    for(const auto& entity : entities){
        if(entity == nullptr || (entity->is_flagged() == false)) continue;

        PositionComponent* p = (PositionComponent*) entity->get_component("PositionComponent");
        SpriteComponent* sprite = (SpriteComponent*) entity->get_component("SpriteComponent");
        if(!sprite || !p) continue;
        
        const uint16_t* texture = sprite->get_sprite();
        if(texture == nullptr){
            continue;
        }

        int screen_x = (p->x - camera->x) * camera->zoom;
        int screen_y = (p->y - camera->y) * camera->zoom;

        if (screen_x + sprite->width < 0 || screen_x > camera->width ||
            screen_y + sprite->height < 0 || screen_y > camera->height) {
            continue;
        }

        canvas.draw_sprite(screen_x, screen_y, sprite->width, sprite->height, texture);

    }
    /* flushes to display. */
    display.flush(canvas.get_buffer());
}