#include "Games/pong/Player.h"

void create_player(int x, int y, bool enemy){
    Entity* player = new Entity();
    if(player == nullptr) return;

    SpriteComponent* player_sprite = new SpriteComponent(3, 24, player_texture);
    if(player_sprite == nullptr) return;

    player->add_component(player_sprite);

    PositionComponent* position = new PositionComponent(x, y, 0, 0);
    if(position == nullptr) return;

    player->add_component(position);

    VelocityComponent* velocity = new VelocityComponent(0, 0);
    if(velocity == nullptr) return;

    player->add_component(velocity);

    if(enemy == true){
        TagComponent* tag = new TagComponent(TAG::ENEMY);
        if(tag == nullptr) return;

        player->add_component(tag);
    } else {
        TagComponent* tag = new TagComponent(TAG::PLAYER);
        if(tag == nullptr) return;

        player->add_component(tag);
    }

    SquareComponent* square = new SquareComponent(position->x, position->y, player_sprite->width, player_sprite->height);
    if(square == nullptr) return;

    player->add_component(square);

    Engine::getInstance().add_entity(player);
}