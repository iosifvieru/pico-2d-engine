#ifndef _ASSETS_H_
#define _ASSETS_H_

#include "Engine/TextureManager.h"
#include "Games/Hero.h"

TextureManager* t = new TextureManager(spritesheet, 144, 48, 16, 16);

const uint16_t* hero_front = t->get_tile(0);
const uint16_t* hero_left = t->get_tile(4);
const uint16_t* hero_up = t->get_tile(8);
const uint16_t* hero_right = t->get_tile(4, true);

const uint16_t* other_sprite = t->get_tile(9);

/* creating sprite components for tiles */
TextureManager* t_m = new TextureManager(indoor_tileset, 208, 144, 16, 16);

const uint16_t* road_left = t_m->get_tile(11);
const uint16_t* road_right = t_m->get_tile(12);

const uint16_t* grass = t_m->get_tile(8);
const uint16_t* grass2 = t_m->get_tile(9);

const uint16_t* road = t_m->get_tile(35);

const uint16_t* postal1 = t_m->get_tile(60);
const uint16_t* postal2 = t_m->get_tile(73);

#endif
