#ifndef _PLAYER_SYSTEM_H_
#define _PLAYER_SYSTEM_H_

#include "Engine/Core.h"

#include "Games/platformer_game/Components/LifetimeComponent.h"
#include "Games/platformer_game/Player.h"

#define GRAVITY 0.05f
#define MAX_GRAVITY 5.0f
#define JUMP_FORCE -1.5f
#define BULLET_SPEED 2.1f

void shoot(float x, float y, bool flip);

class PlayerSystem : public System {
public:
    void update(const std::vector<Entity*>& entities) override; 
};

#endif
