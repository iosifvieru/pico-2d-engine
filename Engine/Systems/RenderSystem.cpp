#include "RenderSystem.h"

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
        if(entity->has_component("RenderNode")){
            RenderNode *rn = (RenderNode*) entity->get_component("RenderNode");

            if(rn == nullptr){
                continue;
            }

            PositionComponent p = *rn->position;
            SpriteComponent sprite = *rn->sprite;
            
            canvas.draw_sprite(p.x, p.y, sprite.width, sprite.height, sprite.sprite);
        }
    }

    /* flushes to display. */
    display.flush(canvas.get_buffer());
}