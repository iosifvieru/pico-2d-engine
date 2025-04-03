#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Engine/Engine.h"
#include "Engine/Components/PositionComponent.h"
#include "Engine/Components/VelocityComponent.h"
#include "Engine/Components/TagComponent.h"
#include "Engine/Components/SquareComponent.h"
#include "Engine/Components/GravityComponent.h"
#include "Games/platformer_game/Assets.h"

void create_enemy(int x, int y){
    Entity* enemy = Entity::create();
    if(enemy == nullptr) return;

    enemy->add_component(new PositionComponent(x, y));
    enemy->add_component(player_frame1);
    enemy->add_component(new VelocityComponent());
    enemy->add_component(new GravityComponent());
    enemy->add_component(new SquareComponent(x, y, TILE_WIDTH, TILE_HEIGHT + 2));
    enemy->add_component(new TagComponent(TAG::ENEMY));

    Engine::getInstance().add_entity(enemy);
}

#endif