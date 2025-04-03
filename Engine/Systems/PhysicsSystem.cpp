#include "Engine/Systems/PhysicsSystem.h"
#include "Engine/Components/GravityComponent.h"
#include "Engine/Components/VelocityComponent.h"
#include "Engine/Components/SquareComponent.h"

void PhysicsSystem::update(const std::vector<Entity*>& entities){
    for(const auto& entity : entities){
        apply_gravity(entity);
    }
}

void apply_gravity(Entity* entity) {
    VelocityComponent* velocity = (VelocityComponent*) entity->get_component("VelocityComponent");
    GravityComponent* g = (GravityComponent*) entity->get_component("GravityComponent");
    if(!velocity || !g) return;

    SquareComponent* collision = (SquareComponent*) entity->get_component("SquareComponent");

    if (collision != nullptr && collision->collided) {
        velocity->v_y = 0;
        velocity->v_x = 0;

        g->is_falling = false;
        g->is_grounded = true;
    } else {
        g->is_falling = true;
        g->is_grounded = false;

        velocity->v_y += g->gravity;
        
        if(velocity->v_y > MAX_GRAVITY) {
            velocity->v_y = MAX_GRAVITY;
        }
    }
}
