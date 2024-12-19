#include "Engine/Systems/MovementSystem.h"
#include "Engine/Components/VelocityComponent.h"
#include "Engine/Components/PositionComponent.h"

void MovementSystem::update(std::list<Entity*> entities){
    for(auto& entity: entities){

        PositionComponent* p = (PositionComponent*) (entity->get_component("PositionComponent"));
        if(p == nullptr) continue;

        VelocityComponent* velocity = (VelocityComponent*)(entity->get_component("VelocityComponent"));
        if(velocity == nullptr) continue;

        p->x += velocity->v_x;
        p->y += velocity->v_y;
        
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