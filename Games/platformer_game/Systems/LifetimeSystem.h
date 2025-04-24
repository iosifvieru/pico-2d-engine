#ifndef _LIFETIME_SYSTEM_H_
#define _LIFETIME_SYSTEM_H_

#include "Engine/Engine.h"
#include "Engine/Systems/System.h"

#include "Games/platformer_game/Components/LifetimeComponent.h"

class LifetimeSystem : public System {
public:
    void update(const std::vector<Entity*>& entities) override;
};

#endif