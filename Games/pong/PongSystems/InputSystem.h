#ifndef _INPUT_SYSTEM_H_
#define _INPUT_SYSTEM_H_

#include "Engine/Systems/System.h"

#include "Engine/Components/VelocityComponent.h"
#include "Engine/Drivers/InputDriver/Keyboard.h"
#include "Engine/Components/TagComponent.h"
#include "Engine/Components/SquareComponent.h"

#include "Games/pong/Ball.h"

class InputSystem : public System {
public:
    void update(const std::vector<Entity*>& entities) override;
};

#endif