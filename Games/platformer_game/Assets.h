#ifndef _PLATFORMER_GAME_ASSETS_
#define _PLATFORMER_GAME_ASSETS_

#include "Engine/Core.h"
#include "Games/platformer_game/Spritesheet.h"

#define TILE_WIDTH 16
#define TILE_HEIGHT 16

/* tiles spritesheet */
extern TextureManager* ts;

extern SpriteComponent* tile1;
extern SpriteComponent* tile2;
extern SpriteComponent* tile3;
extern SpriteComponent* tile4;

extern SpriteComponent* tile5;
extern SpriteComponent* tile6;
extern SpriteComponent* tile7;
extern SpriteComponent* tile8;

extern SpriteComponent* tile9;
extern SpriteComponent* tile10;
extern SpriteComponent* tile11;
extern SpriteComponent* tile12;
 
extern SpriteComponent* tile13;
extern SpriteComponent* tile14;
extern SpriteComponent* tile15;
extern SpriteComponent* tile16;

extern SpriteComponent* tile17;
extern SpriteComponent* tile18;
extern SpriteComponent* tile19;
extern SpriteComponent* tile20;

extern SpriteComponent* box_up;

/* player spritesheet */
extern TextureManager* ps;
extern SpriteComponent* player_frame1;
extern SpriteComponent* player_frame1_flipped;

extern SpriteComponent* player_shooting;
extern SpriteComponent* player_shooting_flipped;

extern SpriteComponent* player_falling;
extern SpriteComponent* player_falling_flipped;


/* items spritesheet */
extern TextureManager* is;
extern SpriteComponent* bullet_frame1;
extern SpriteComponent* bullet_frame1_flipped;

SpriteComponent* get_sprite_component(int value);

#endif