#ifndef _COLLISION_SYSTEM_H_
#define _COLLISION_SYSTEM_H_

#include "Engine/Systems/System.h"
#include "Engine/Components/SquareComponent.h"

/* this function takes two square components as input and returns true if collided. */
uint8_t has_collided(SquareComponent* e1, SquareComponent* e2);

class CollisionSystem : public System {
public:
    void update(const std::vector<Entity*>& entities) override;
};

#endif