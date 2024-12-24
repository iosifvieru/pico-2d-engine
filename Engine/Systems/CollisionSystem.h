#ifndef _COLLISION_SYSTEM_H_
#define _COLLISION_SYSTEM_H_

#include "Engine/Systems/System.h"

class CollisionSystem : public System {
public:
    void update(const std::vector<Entity*>& entities) override;
};

#endif