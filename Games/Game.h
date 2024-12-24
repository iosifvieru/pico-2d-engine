#ifndef _GAME_H_
#define _GAME_H_

#include "Engine/Engine.h"

void game_init();
void create_enemy(uint16_t x, uint16_t y);
void create_player(uint16_t x, uint16_t y);
void create_projectile(uint16_t x, uint16_t y);

#endif