#ifndef _PONG_GLOBALS_H_
#define _PONG_GLOBALS_H_

#include "Engine/Entity/Entity.h"

#define Y_TOP_LIMIT 2
#define Y_BOTTOM_LIMIT 128
#define X_RIGHT_LIMIT 128

#define PLAYER_START_X 2
#define PLAYER_START_Y 20

#define ENEMY_START_X 117
#define ENEMY_START_Y 20

#define BALL_START_X 64
#define BALL_START_Y 64
#define BALL_RANDOMNESS 1000

uint16_t PADDLE_WIDTH = 10;
uint16_t PADDLE_HEIGHT = 50;

uint16_t BALL_WIDTH = 8;
uint16_t BALL_HEIGHT = 8;

uint16_t PLAYER_SCORE = 0;
uint16_t ENEMY_SCORE = 0;

float PLAYER_SPEED = 1.2;
float BALL_SPEED = 1.0;

extern bool has_scored;

/* fast pointers to the entities */
extern Entity* Pong_UI;
extern Entity* Ball;
extern Entity* Enemy;

#endif