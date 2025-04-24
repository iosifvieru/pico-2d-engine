/*
This file contains includes to the most important components and systems
mostly used in all games.
*/

#pragma once

/* engine specific includes */
#include "Engine/Engine.h"
#include "Engine/Random.h"
#include "Engine/TextureManager.h"
#include "Engine/Font.h"

/* menu */
#include "Menu/Menu.h"

/* core components mostly used everywhere */
#include "Engine/Components/PositionComponent.h"
#include "Engine/Components/SpriteComponent.h"
#include "Engine/Components/VelocityComponent.h"
#include "Engine/Components/TextComponent.h"
#include "Engine/Components/SquareComponent.h"
#include "Engine/Components/GravityComponent.h"
#include "Engine/Components/TagComponent.h"

/* core systems */
#include "Engine/Systems/MenuSystem.h"
#include "Engine/Systems/MovementSystem.h"
#include "Engine/Systems/CollisionSystem.h"
#include "Engine/Systems/RenderSystem.h"
#include "Engine/Systems/CameraSystem.h"
#include "Engine/Systems/PhysicsSystem.h"

/* core drivers */
#include "Engine/Drivers/DisplayDriver/ST7735.h"
#include "Engine/Drivers/InputDriver/Keyboard.h"

/* entity */
#include "Engine/Entity/Entity.h"

/* logger */
#include "Engine/Logger/Logger.h"

/* core canvas */
#include "Engine/Canvas/BufferedCanvas.h"