
#ifndef _GAME_LOGIC_H_
#define _GAME_LOGIC_H_

#include "Engine/Systems/System.h"

#include "Engine/Components/TagComponent.h"
#include "Engine/Drivers/InputDriver/Keyboard.h"
#include "Engine/Components/PositionComponent.h"
#include "Engine/Components/VelocityComponent.h"
#include "Games/pong/Globals.h"

#include "Engine/Random.h"

bool has_scored = false;

class PongGameSystem : public System {
    void update(const std::vector<Entity*>& entities){
        if(!has_scored) return;
        if(has_scored == true){
            if(Keyboard::getInstance().is_pressed_once(ENTER)){
                VelocityComponent* v = (VelocityComponent*) Ball->get_component("VelocityComponent");
                if(v == nullptr) return;
                
                float offset_x = ((rnd() % BALL_RANDOMNESS) / 1000.0f);
                float offset_y = ((rnd() % BALL_RANDOMNESS) / 1000.0f);
    
                v->v_x = (rnd() % 2 == 0 ? 1 : -1) * (BALL_SPEED + offset_x);
                v->v_y = (rnd() % 2 == 0 ? 1 : -1) * (BALL_SPEED + offset_y);

                has_scored = false;
            }
        }
    }
};


#endif