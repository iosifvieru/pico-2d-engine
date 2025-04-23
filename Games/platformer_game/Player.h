#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Engine/Engine.h"
#include "Engine/Components/PositionComponent.h"
#include "Engine/Components/VelocityComponent.h"
#include "Engine/Components/TagComponent.h"
#include "Engine/Components/SquareComponent.h"
#include "Engine/Components/CameraComponent.h"
#include "Engine/Components/GravityComponent.h"

#include "Games/platformer_game/Assets.h"

Entity* player = nullptr;

void init_player(uint16_t x, uint16_t y){
    if(player == nullptr){
        player = Entity::create();

        if(player == nullptr) return;
    }

    player->add_component(new PositionComponent(x, y));
    player->add_component(new CameraComponent(x, y, 128, 128, 1));
    player->add_component(new VelocityComponent(0, 0));
    player->add_component(new TagComponent(TAG::PLAYER));
    player->add_component(player_frame1);
    player->add_component(new GravityComponent());

    SquareComponent* collision = new SquareComponent(x, y, TILE_WIDTH, TILE_HEIGHT + 2);
    collision->is_visible = false;

    player->add_component(collision);

    Engine::getInstance().add_entity(player);
}

#endif