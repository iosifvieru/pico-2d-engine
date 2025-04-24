#include "Games/platformer_game/Enemy.h"

void create_enemy(int x, int y){
    Entity* enemy = Entity::create();
    if(enemy == nullptr) return;

    enemy->add_component(new PositionComponent(x, y));
    enemy->add_component(player_frame1);
    enemy->add_component(new VelocityComponent());
    enemy->add_component(new GravityComponent());

    SquareComponent* sq = new SquareComponent(x, y, TILE_WIDTH, TILE_HEIGHT+2);
    sq->is_visible = false;
    enemy->add_component(sq);
    enemy->add_component(new TagComponent(TAG::ENEMY));

    Engine::getInstance().add_entity(enemy);
}
