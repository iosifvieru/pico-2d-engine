#ifndef PONG_H_
#define PONG_H_

/* core features */
#include "Engine/Core.h"

/* game specific includes */
#include "Games/pong/Systems/PlayerSystem.h"
#include "Games/pong/Systems/UISystem.h"
#include "Games/pong/Systems/BallSystem.h"
#include "Games/pong/Systems/GameLogic.h"
#include "Games/pong/Systems/EnemySystem.h"

#include "Games/pong/Globals.h"

/* games functions */
void load_walls();
void load_player(int x, int y);
void load_enemy(int x, int y);
void load_ball(int x, int y);
void load_UI();
void pong_init();

#endif