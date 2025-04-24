#ifndef _PONG_UI_SYSTEM_H_
#define _PONG_UI_SYSTEM_H_

#include "Engine/Core.h"
#include "Games/pong/Globals.h"

class PongUISystem : public System {
public:
    void update(const std::vector<Entity*>& entities) override;
};

#endif