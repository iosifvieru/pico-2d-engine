#include "Games/platformer_game/Platformer.h"
#include "Games/pong/Pong.h"

#include "Menu/Menu.h"

#define Y_OFFSET 3
#define Y_MAX_OFFSET 9

void MenuSystem::update(const std::vector<Entity*>& entities){
    if(arrow == nullptr){
        arrow = Entity::create();
        arrow->add_component(new TextComponent(5, game_no * FONT_HEIGHT, ">"));
        Engine::getInstance().add_entity(arrow);
    }

    TextComponent* t = (TextComponent*) arrow->get_component("TextComponent");
    if(Keyboard::getInstance().is_pressed_once(W)){
        game_no--;

        if(game_no < 0){
            game_no = 0;
        }
    }

    if(Keyboard::getInstance().is_pressed_once(S)){
        game_no++;

        if(game_no > games.size() -1){
            game_no = games.size()-1;
        }
    }

    if(Keyboard::getInstance().is_pressed_once(ENTER)){
        switch(game_no){
            case 0:
                Engine::getInstance().clear();
                platformer_init();
                return;
            case 1:
                Engine::getInstance().clear();
                pong_init();
                return;
            
            /* ... */
            default:
                break;
        }
    }
    Logger::log("%d", game_no);

    if(t == nullptr) return;
    t->y = (game_no + Y_OFFSET) * FONT_HEIGHT;
}