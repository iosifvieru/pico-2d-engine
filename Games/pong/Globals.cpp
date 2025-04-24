#include "Games/pong/Globals.h"

uint16_t PADDLE_WIDTH = 6;
uint16_t PADDLE_HEIGHT = 40;

uint16_t BALL_WIDTH = 6;
uint16_t BALL_HEIGHT = 6;

uint16_t PLAYER_SCORE = 0;
uint16_t ENEMY_SCORE = 0;

float PLAYER_SPEED = 1.2;
float BALL_SPEED = 1.0;

bool has_scored = false;
bool game_over = false;