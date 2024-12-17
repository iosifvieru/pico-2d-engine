#include "Engine/Systems/MovementSystem.h"
#include "Engine/Nodes/MovementNode.h"

void MovementSystem::update(std::list<Entity*> entities){
    for(auto& entity: entities){
        if(entity->has_component("MovementNode")){
            MovementNode* mvm = (MovementNode*) (entity->get_component("MovementNode"));

            if(mvm == nullptr){
                continue;
            }

            mvm->position->x += mvm->velocity->v_x;
            mvm->position->y += mvm->velocity->v_y;
        }
    }
}