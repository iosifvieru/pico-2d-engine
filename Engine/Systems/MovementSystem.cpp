#include "Engine/Systems/MovementSystem.h"
#include "Engine/Components/VelocityComponent.h"
#include "Engine/Components/PositionComponent.h"

void MovementSystem::update(const std::vector<Entity*>& entities){
    for(const auto& entity: entities){

        PositionComponent* p = (PositionComponent*) (entity->get_component("PositionComponent"));
        if(p == nullptr) continue;

        VelocityComponent* velocity = (VelocityComponent*)(entity->get_component("VelocityComponent"));
        if(velocity == nullptr) continue;

        if((p->x + velocity->v_x) != p->x){
            p->x += velocity->v_x;
            
            /* entity moved so it needs redraw */
            entity->set_flag(true);
        }
        
        if((p->y + velocity->v_y) != p->y) {
            p->y += velocity->v_y;
            entity->set_flag(true);
        }
        /* 
        if(entity->has_component("MovementNode")){
            MovementNode* mvm = (MovementNode*) (entity->get_component("MovementNode"));

            if(mvm == nullptr){
                continue;
            }

            mvm->position->x += mvm->velocity->v_x;
            mvm->position->y += mvm->velocity->v_y;
        }*/
    }
}