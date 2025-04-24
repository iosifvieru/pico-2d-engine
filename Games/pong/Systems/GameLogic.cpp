#include "Games/pong/Systems/GameLogic.h"
#include "Games/pong/Systems/BallSystem.h"

#include "Engine/Core.h"

void declare_winner(PongWinner winner){
    std::string winner_text;

    switch(winner){
        case PongWinner::ENEMY:
            winner_text = "ENEMY WINS!";
            break;
        case PongWinner::PLAYER:
            winner_text = "PLAYER WINS!";
            break;

        /* not likely but default. */
        default:
            winner_text = "NO ONE WINS!";
            break;
    }

    if(Pong_UI == nullptr) return;

    TextComponent* UI_Text = (TextComponent*) Pong_UI->get_component("TextComponent");
    if(UI_Text == nullptr) return;

    UI_Text->text = winner_text;
    UI_Text->x = 60 - ((winner_text.size()-1) / 2) * FONT_WIDTH;
    ball_reset();
}

void PongGameSystem::update(const std::vector<Entity*>& entities){
    Keyboard& keyboard = Keyboard::getInstance();

    /* wait for button after scoring */
    if(has_scored == true){
        if(keyboard.is_pressed_once(ENTER)){
            VelocityComponent* v = (VelocityComponent*) Ball->get_component("VelocityComponent");
            if(v == nullptr) return;
            
            v->v_x = (rnd() % 2 == 0 ? 1 : -1) * (BALL_SPEED);
            v->v_y = (rnd() % 2 == 0 ? 1 : -1) * (BALL_SPEED);

            has_scored = false;
        }
    }

    /* check and declare winner */
    if(!game_over){
        if(PLAYER_SCORE >= 5){
            // declare winner
            declare_winner(PongWinner::PLAYER);

            game_over = true;
            has_scored = false;
        } else if(ENEMY_SCORE >= 5){
            // declare winner
            declare_winner(PongWinner::ENEMY);

            game_over = true;
            has_scored = false;
        }
    }

    /* restart game after winning */
    if(game_over){
        if(keyboard.is_pressed_once(ENTER)){
            VelocityComponent* v = (VelocityComponent*) Ball->get_component("VelocityComponent");
            if(v == nullptr) return;
            
            v->v_x = (rnd() % 2 == 0 ? 1 : -1) * (BALL_SPEED);
            v->v_y = (rnd() % 2 == 0 ? 1 : -1) * (BALL_SPEED);

            has_scored = false;

            game_over = false;
            PLAYER_SCORE = 0;
            ENEMY_SCORE = 0;
        }
    }
}
