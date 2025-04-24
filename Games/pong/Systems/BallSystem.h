#ifndef _PONG_BALL_SYSTEM_H_
#define _PONG_BALL_SYSTEM_H_

#include "Engine/Core.h"
#include "Games/pong/Globals.h"

void ball_reset();

class BallSystem : public System {
public:
    void update(const std::vector<Entity*>& entities) override;
};


#endif