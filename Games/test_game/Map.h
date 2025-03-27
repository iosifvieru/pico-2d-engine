#ifndef _MAP_H_
#define _MAP_H_

#define MAP_WIDTH 16
#define MAP_HEIGHT 16

#define TILE_WIDTH 16
#define TILE_HEIGHT 16

#include "Engine/Components/SpriteComponent.h"
#include "Engine/Components/PositionComponent.h"

#include "Engine/TextureManager.h"
#include "Games/test_game/Assets.h"
#include "Engine/Engine.h"

/* making some shared sprite components for the map */
SpriteComponent* grass_sprite_component = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, grass);
SpriteComponent* grass2_sprite_component = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, grass2);

SpriteComponent* road_sprite_component = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, road);

SpriteComponent* post1_sprite_component = new SpriteComponent(TILE_HEIGHT, TILE_WIDTH, postal1);
SpriteComponent* post2_sprite_component = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, postal2);

/* bush */
SpriteComponent* bush1_sprite_component = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, bush1);
SpriteComponent* bush2_sprite_component = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, bush2);
SpriteComponent* bush3_sprite_component = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, bush3);

SpriteComponent* bush4_sprite_component = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, bush4);
SpriteComponent* bush5_sprite_component = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, bush5);
SpriteComponent* bush6_sprite_component = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, bush6);

SpriteComponent* bush7_sprite_component = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, bush7);
SpriteComponent* bush8_sprite_component = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, bush8);
SpriteComponent* bush9_sprite_component = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, bush9);


const uint8_t map[MAP_WIDTH*MAP_HEIGHT] = {
    2, 2, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1,
    0, 2, 2, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1,
    1, 1, 2, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0,
    0, 0, 2, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1,
    0, 1, 2, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0,
    0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0, 0, 0, 1, 1,
    1, 0, 1, 0, 1, 0, 1, 0, 0, 2, 2, 0, 1, 0, 0, 0,
    0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 2, 0, 0, 0, 1, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 2, 2, 2, 0, 1, 1,
    1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 2, 0, 1, 1,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 2, 2, 1, 0,
    0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 2, 2, 2,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0
};

const uint8_t map_overlay[MAP_WIDTH*MAP_HEIGHT] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0,
    0, 0, 0, 3, 0, 0, 0, 0, 0, 11, 13, 0, 0, 0, 0, 0,
    0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 5, 6, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 8, 9, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 11, 12, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 13, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

SpriteComponent* get_sprite_component(uint8_t tile_nr){
    switch(tile_nr){
        case 0:
            return grass_sprite_component;
        case 1:
            return grass2_sprite_component;
        case 2:
            return road_sprite_component;
        case 3:
            return post1_sprite_component;
        case 4:
            return post2_sprite_component;
        case 5:
            return bush1_sprite_component;
        case 6:
            return bush2_sprite_component;
        case 7:
            return bush3_sprite_component;
        case 8:
            return bush4_sprite_component;
        case 9:
            return bush5_sprite_component;
        case 10:
            return bush6_sprite_component;
        case 11:
            return bush7_sprite_component;
        case 12:
            return bush8_sprite_component;
        case 13:
            return bush9_sprite_component;
        default:
            return grass_sprite_component;
    }
}

void map_init(){
    for (int i = 0; i < MAP_WIDTH * MAP_HEIGHT; i++) {
        uint16_t x = (i % MAP_WIDTH) * TILE_WIDTH + 1;
        uint16_t y = (i / MAP_HEIGHT) * TILE_HEIGHT + 1;

        Entity* e = new Entity();
        e->add_component(new PositionComponent(x, y));
        e->add_component(get_sprite_component(map[i]));

        Engine::getInstance().add_entity(e);
    }

    for(int i = 0; i < MAP_WIDTH * MAP_HEIGHT; i++){
        uint16_t x = (i % MAP_WIDTH) * TILE_WIDTH + 1;
        uint16_t y = (i / MAP_HEIGHT) * TILE_HEIGHT + 1;

        if(map_overlay[i] == 0) continue;

        Entity* e = new Entity();
        e->add_component(new PositionComponent(x, y));
        e->add_component(get_sprite_component(map_overlay[i]));

        Engine::getInstance().add_entity(e);
    }
}
#endif