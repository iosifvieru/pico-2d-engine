#ifndef _PHYSICS_SYSTEM_H_
#define _PHYSICS_SYSTEM_H_

#include "Engine/Systems/System.h"

class PhysicsSystem : public System {
public:
    void update(const std::vector<Entity*>& entities) override;
};

void apply_gravity(Entity* entity);

#endif