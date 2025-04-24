#ifndef _ENEMY_SYSTEM_H_
#define _ENEMY_SYSTEM_H_

#include "Engine/Systems/System.h"

#include "Games/platformer_game/Player.h"
#include "Games/platformer_game/Enemy.h"

#define ENEMY_SPEED 0.20f

class EnemySystem : public System {
public:
    void update(const std::vector<Entity*>& entities) override;
};

#endif