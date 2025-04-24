#include "Games/pong/Systems/UISystem.h"

void PongUISystem::update(const std::vector<Entity*>& entities){
    if(Pong_UI == nullptr){ return; }
    if(game_over) return;

    TextComponent* UI_Score = (TextComponent*) Pong_UI->get_component("TextComponent");

    std::string score_text = std::to_string(PLAYER_SCORE) + ":" + std::to_string(ENEMY_SCORE);
    UI_Score->text = score_text;
    UI_Score->x = 60 - ((score_text.size()-1) / 2) * FONT_WIDTH;
}