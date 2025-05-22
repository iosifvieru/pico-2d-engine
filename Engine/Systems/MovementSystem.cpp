#include "Engine/Core.h"
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
        
        SquareComponent* collision = (SquareComponent*) (entity->get_component("SquareComponent"));
        if (collision) {

            switch (collision->collision_sides) {
                case CollisionSide::BOTTOM:
                    if (velocity->v_y > 0) velocity->v_y = 0;
                    break;
                case CollisionSide::TOP:
                    if (velocity->v_y < 0) velocity->v_y = 0;
                    break;
                case CollisionSide::LEFT:
                    if (velocity->v_x < 0) velocity->v_x = 0;
                    break;
                case CollisionSide::RIGHT:
                    if (velocity->v_x > 0) velocity->v_x = 0;
                    break;
                default:
                    break;
            }

            Logger::log("collision: %d", collision->collision_sides);
        }

        p->x += velocity->v_x;
        p->y += velocity->v_y; 
    }
}