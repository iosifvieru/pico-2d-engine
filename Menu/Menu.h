#ifndef _MENU_H_
#define _MENU_H_

/*
This is the header file for the Pico Menu.
*/

#include <list>
#include <string>

#include "Engine/Engine.h"
#include "Engine/Entity/Entity.h"
#include "Engine/Components/PositionComponent.h"
#include "Engine/Components/TextComponent.h"
#include "Engine/Drivers/InputDriver/Keyboard.h"
#include "Engine/Systems/MenuSystem.h"
#include "Engine/Canvas/Canvas.h"
#include "Engine/Canvas/BufferedCanvas.h"
#include "Engine/Systems/RenderSystem.h"
#include "Engine/Systems/CameraSystem.h"

extern std::list<std::string> games;

void load_menu();
void config_keyboard();
void config_display();
void config_game_list();
void config_title();

#endif
