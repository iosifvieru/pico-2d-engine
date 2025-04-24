
#ifndef _GAME_LOGIC_H_
#define _GAME_LOGIC_H_

#include "Engine/Core.h"
#include "Games/pong/Globals.h"

enum class PongWinner {
    PLAYER,
    ENEMY,
    NONE
};

void declare_winner(PongWinner winner);

class PongGameSystem : public System {
    void update(const std::vector<Entity*>& entities) override;
};

#endif