#include "Games/platformer_game/Assets.h"

/* tiles spritesheet */
TextureManager* ts = new TextureManager(platformer_tiles, 128, 80, TILE_WIDTH, TILE_HEIGHT); 

SpriteComponent* tile1 = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, ts->get_tile(0));
SpriteComponent* tile2 = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, ts->get_tile(1));
SpriteComponent* tile3 = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, ts->get_tile(2));
SpriteComponent* tile4 = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, ts->get_tile(3));

SpriteComponent* tile5 = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, ts->get_tile(8));
SpriteComponent* tile6 = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, ts->get_tile(9));
SpriteComponent* tile7 = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, ts->get_tile(10));
SpriteComponent* tile8 = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, ts->get_tile(11));

SpriteComponent* tile9 = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, ts->get_tile(16));
SpriteComponent* tile10 = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, ts->get_tile(17));
SpriteComponent* tile11 = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, ts->get_tile(18));
SpriteComponent* tile12 = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, ts->get_tile(19));

SpriteComponent* tile13 = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, ts->get_tile(24));
SpriteComponent* tile14 = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, ts->get_tile(25));
SpriteComponent* tile15 = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, ts->get_tile(26));
SpriteComponent* tile16 = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, ts->get_tile(27));

SpriteComponent* tile17 = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, ts->get_tile(32));
SpriteComponent* tile18 = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, ts->get_tile(33));
SpriteComponent* tile19 = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, ts->get_tile(34));
SpriteComponent* tile20 = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, ts->get_tile(35));

SpriteComponent* box_up = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, ts->get_tile(20));

/* player spritesheet */
TextureManager* ps = new TextureManager(player_spritesheet, 64, 32, TILE_WIDTH, TILE_HEIGHT);
SpriteComponent* player_frame1 = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, ps->get_tile(0));
SpriteComponent* player_frame1_flipped = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, ps->get_tile(0, true));

SpriteComponent* player_shooting = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, ps->get_tile(3));
SpriteComponent* player_shooting_flipped = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, ps->get_tile(3, true));


SpriteComponent* player_falling = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, ps->get_tile(4));
SpriteComponent* player_falling_flipped = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, ps->get_tile(4, true));


/* items spritesheet */
TextureManager* is = new TextureManager(items_spritesheet, 64, 64, TILE_WIDTH, TILE_HEIGHT);
SpriteComponent* bullet_frame1 = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, is->get_tile(8));
SpriteComponent* bullet_frame1_flipped = new SpriteComponent(TILE_WIDTH, TILE_HEIGHT, is->get_tile(8, true));

SpriteComponent* get_sprite_component(int value){
    switch(value){
        case 0:
            return tile1;
        case 1:
            return tile2;
        case 2:
            return tile3;
        case 3:
            return tile4;
        case 4:
            return tile5;
        case 5:
            return tile6;
        case 6:
            return tile7;
        case 7:
            return tile8;
        case 8:
            return tile9;
        case 9:
            return tile10;
        case 10:
            return tile11;
        case 11:
            return tile12;
        case 12:
            return tile13;
        case 13:
            return tile14;
        case 14:
            return tile15;
        case 15:
            return tile16;
        case 16:
            return box_up;
        case 17:
            return tile17;
        case 18:
            return tile18;
        case 19:
            return tile19;
        case 20:
            return tile20;
        default:
            return tile1;
    }
}
