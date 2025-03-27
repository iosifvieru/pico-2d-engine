#ifndef _ASSETS_H_
#define _ASSETS_H_

#include "Engine/TextureManager.h"
#include "Games/test_game/Hero.h"

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

const uint16_t* bush1 = t_m->get_tile(78);
const uint16_t* bush2 = t_m->get_tile(79);
const uint16_t* bush3 = t_m->get_tile(80);

const uint16_t* bush4 = t_m->get_tile(91);
const uint16_t* bush5 = t_m->get_tile(92);
const uint16_t* bush6 = t_m->get_tile(93);

const uint16_t* bush7 = t_m->get_tile(104);
const uint16_t* bush8 = t_m->get_tile(105);
const uint16_t* bush9 = t_m->get_tile(106);


#endif
