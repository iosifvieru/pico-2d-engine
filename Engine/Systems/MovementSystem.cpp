#include "Engine/Systems/MovementSystem.h"
#include "Engine/Components/VelocityComponent.h"
#include "Engine/Components/PositionComponent.h"
#include "math.h"

void MovementSystem::update(const std::vector<Entity*>& entities){
    for(const auto& entity: entities){
        VelocityComponent* velocity = (VelocityComponent*)(entity->get_component("VelocityComponent"));
        if(velocity == nullptr) continue;
        
        PositionComponent* p = (PositionComponent*) (entity->get_component("PositionComponent"));
        if(p == nullptr) continue;

        /* normalization for diagonal movement */
        /*
        if (velocity->v_x != 0 && velocity->v_y != 0) {
            float magnitude = std::sqrt(velocity->v_x * velocity->v_x + velocity->v_y * velocity->v_y);

            if (magnitude > 1.0f) {
                velocity->v_x /= magnitude;
                velocity->v_y /= magnitude;
            }
        } */
        
        p->x += velocity->v_x;
        p->y += velocity->v_y; 
    }
}