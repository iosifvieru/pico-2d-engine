#ifndef _PONG_PLAYER_SYSTEM_H_
#define _PONG_PLAYER_SYSTEM_H_

#include "Engine/Core.h"
#include "Games/pong/Globals.h"

class PongPlayerSystem : public System {
public:
    void update(const std::vector<Entity*>& entities) override;
};

#endif