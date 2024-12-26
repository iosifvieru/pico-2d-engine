#ifndef _BALL_H_
#define _BALL_H_

#include "Engine/Components/PositionComponent.h"
#include "Engine/Components/SpriteComponent.h"
#include "Engine/Components/VelocityComponent.h"
#include "Engine/Components/TagComponent.h"
#include "Engine/Components/SquareComponent.h"

#include "Engine/Entity/Entity.h"
#include "Engine/Engine.h"

#include "Games/pong/Assets.h"

void create_ball(uint16_t x, uint16_t y, int8_t speed);
PositionComponent* get_ball_position();

#endif