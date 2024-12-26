#ifndef _PONG_H_
#define _PONG_H_

#include "Engine/Engine.h"
#include "Engine/Canvas/BufferedCanvas.h"
#include "Engine/Drivers/DisplayDriver/ST7735.h"
#include "Engine/Drivers/InputDriver/Keyboard.h"

/* systems */
#include "Engine/Systems/RenderSystem.h"
#include "Engine/Systems/MovementSystem.h"
#include "Games/pong/PongSystems/InputSystem.h"
#include "Engine/Systems/CollisionSystem.h"

/* ball */
#include "Games/pong/Ball.h"

/* player */
#include "Games/pong/Player.h"

#define UP_KEY 8
#define DOWN_KEY 14

class Pong {
private:
    bool is_running = true;
    uint8_t framerate = 30;
public:
    Pong();
    ~Pong();

    void loop();

    void set_framerate(uint8_t framerate){
        this->framerate = framerate;
    }

};

#endif