#ifndef _PONG_UI_SYSTEM_H_
#define _PONG_UI_SYSTEM_H_

#include "Engine/Systems/System.h"

#include "Engine/Components/TextComponent.h"
#include "Engine/Drivers/InputDriver/Keyboard.h"

#include "Games/pong/Globals.h"

class PongUISystem : public System {
public:
    void update(const std::vector<Entity*>& entities){
        if(Pong_UI == nullptr){ return; }

        TextComponent* UI_Score = (TextComponent*) Pong_UI->get_component("TextComponent");

        std::string score_text = std::to_string(PLAYER_SCORE) + ":" + std::to_string(ENEMY_SCORE);

        UI_Score->text = score_text;
    }
};

#endif