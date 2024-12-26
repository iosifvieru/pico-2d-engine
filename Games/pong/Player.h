#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Engine/Components/PositionComponent.h"
#include "Engine/Components/SpriteComponent.h"
#include "Engine/Components/VelocityComponent.h"
#include "Engine/Components/TagComponent.h"
#include "Engine/Components/SquareComponent.h"

#include "Engine/Entity/Entity.h"
#include "Engine/Engine.h"

#include "Games/pong/Assets.h"

void create_player(int x, int y, bool enemy);

#endif