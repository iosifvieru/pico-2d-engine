#include "Engine/Systems/RenderSystem.h"
#include "Engine/Logger/Logger.h"
#include "Engine/Components/PositionComponent.h"
#include "Engine/Components/SpriteComponent.h"
#include "Engine/Components/SquareComponent.h"

RenderSystem::RenderSystem(Canvas& canvas, Display& display): canvas(canvas), display(display) {
    //

}

RenderSystem::~RenderSystem(){
    //
}

void RenderSystem::update(std::vector<Entity*> entities){
    /* clears the canvas*/
    canvas.fill(0x0000);

    /* redraws everything. */
    for(auto& entity : entities){
        if(entity == nullptr || (entity->is_flagged() == false)) continue;

        PositionComponent* p = (PositionComponent*) entity->get_component("PositionComponent");
        SpriteComponent* sprite = (SpriteComponent*) entity->get_component("SpriteComponent");
        if(!sprite || !p) continue;
        
        canvas.draw_sprite(p->x, p->y, sprite->width, sprite->height, sprite->sprite);

        //entity->set_flag(false);

        SquareComponent* collision_border = (SquareComponent*) entity->get_component("SquareComponent");
        if(collision_border == nullptr) continue;

        if(collision_border->is_visible == false) continue;
        
        canvas.draw_rect(collision_border->get_x(), collision_border->get_y(),
                collision_border->get_max_x(), collision_border->get_max_y(),
                0x07c0);

        /* */
    }

    /* flushes to display. */
    display.flush(canvas.get_buffer());
}