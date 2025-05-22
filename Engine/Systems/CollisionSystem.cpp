#include "Engine/Systems/CollisionSystem.h"
#include "Engine/Components/PositionComponent.h"
#include "Engine/Components/SquareComponent.h"
#include "Engine/Components/VelocityComponent.h"

#include "Engine/Logger/Logger.h"

/*
this is the update function of the collision system.
this function iterates through every entity and checking if two collide.

it is only responsible for detecting collision. it DOES NOT handle it in some way.
*/
void CollisionSystem::update(const std::vector<Entity*>& entities) {
    for(const auto& entity1 : entities){
        /* pointer to square component. */
        SquareComponent* square_component1 = (SquareComponent*) entity1->get_component("SquareComponent");
        if(square_component1 == nullptr) continue;

        /* pointer to position component. */
        PositionComponent* position1 = (PositionComponent*) entity1->get_component("PositionComponent");
        if(position1 == nullptr) continue;

        /* resetting all the flags. */
        square_component1->collided = false;

        /* TODO:
            find a better way to check for collisions.
            so far the implementation is a O(n^2)..
            which is really slow.. but for now it looks good.
        */

        /* modifing the collision square's position. */
        square_component1->set_x(position1->x);
        square_component1->set_y(position1->y);
        for(const auto& entity2: entities){
            /* skipping if comparing the entity with itself. */
            if(entity1 == entity2) continue;

            SquareComponent* square_component2 = (SquareComponent*) entity2->get_component("SquareComponent");
            if(square_component2 == nullptr) continue;

            /*
            COLLISION BUG FIXED!!!!!!!

            the problem was that i was not breaking the loop and i was further
            checking for collisions, setting the collided variable to false
            because the implementation looked like this:
            
            square_component1->collided = square_component1->has_collided(...);
            */

            uint8_t collision_info = has_collided(square_component1, square_component2);
            if(collision_info != CollisionSide::NONE){
                square_component1->collided = true;
                square_component1->collision_sides = collision_info;
                break;
            } else {
                square_component1->collided = false;
                square_component1->collision_sides = CollisionSide::NONE;
            }
        }
    }
}

/* this function takes two square components as input and returns true if collided. */
uint8_t has_collided(SquareComponent* e1, SquareComponent* e2){
    uint8_t collision = CollisionSide::NONE;

    if(e1->get_max_x() < e2->get_x() || e1->get_x() > e2->get_max_x()) {
        return CollisionSide::NONE;
    }

    if(e1->get_max_y() < e2->get_y() || e1->get_y() > e2->get_max_y()){
        return CollisionSide::NONE;
    }

    /* getting distances from each side */
    int dx_right = e1->get_max_x() - e2->get_x();
    int dx_left = e2->get_max_x() - e1->get_x();
    int dy_bottom = e1->get_max_y() - e2->get_y();
    int dy_top = e2->get_max_y() - e1->get_y();

    int min_dx = std::min(dx_right, dx_left);
    int min_dy = std::min(dy_bottom, dy_top);

    if(min_dx < min_dy){
        if(dx_right < dx_left){
            // return CollisionSide::RIGHT;
            collision |= CollisionSide::RIGHT;
        } else {
            // return CollisionSide::LEFT;
            collision |= CollisionSide::LEFT;
        }
    } else {
        if(dy_bottom < dy_top){
            // return CollisionSide::BOTTOM;
            collision |= CollisionSide::BOTTOM;
        } else {
            // return CollisionSide::TOP;
            collision |= CollisionSide::TOP;
        }
    }

    return collision;
}