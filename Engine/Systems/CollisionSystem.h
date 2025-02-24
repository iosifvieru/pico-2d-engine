#ifndef _COLLISION_SYSTEM_H_
#define _COLLISION_SYSTEM_H_

#include "Engine/Systems/System.h"
#include "Engine/Components/SquareComponent.h"

class CollisionSystem : public System {
public:
    void update(const std::vector<Entity*>& entities) override;
};

/* this function takes two square components as input and returns true if collided. */
bool has_collided(SquareComponent* e1, SquareComponent* e2);

#endif