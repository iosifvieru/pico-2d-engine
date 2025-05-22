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
    SquareComponent* collision = (SquareComponent*) entity->get_component("SquareComponent");

    if (!velocity || !g) return;

    if (collision && collision->collided) {
        // Stop vertical motion only if falling downward and hit something below
        if (collision->collision_sides == CollisionSide::BOTTOM && velocity->v_y > 0) {
            velocity->v_y = 0;
            g->is_falling = false;
            g->is_grounded = true;
        }

        // Optional: stop horizontal motion if hitting wall
        if ((collision->collision_sides == CollisionSide::LEFT && velocity->v_x < 0) ||
            (collision->collision_sides == CollisionSide::RIGHT && velocity->v_x > 0)) {
            velocity->v_x = 0;
        }

    } else {
        // Apply gravity
        g->is_falling = true;
        g->is_grounded = false;

        velocity->v_y += g->gravity;

        if (velocity->v_y > MAX_GRAVITY) {
            velocity->v_y = MAX_GRAVITY;
        }
    }
}