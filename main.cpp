#include "pico/stdlib.h"
#include <time.h>
#include <stdio.h>
#include <string.h>

#include "Engine/Drivers/DisplayDriver/ST7735.h"
#include "Engine/Canvas/BufferedCanvas.h"
#include "Engine/Canvas/BasicCanvas.h"

#include "Engine/Nodes/RenderNode.h"
#include "Engine/Nodes/MovementNode.h"

#include "Engine/Systems/RenderSystem.h"
#include "Engine/Systems/MovementSystem.h"

#include "Engine/Entity/Entity.h"
#include "Engine/Engine.h"
#include "Engine/Drivers/InputDriver/Keyboard.h"

#include "Games/Player.h"
#include "Games/Enemy.h"
#include "Games/Projectile.h"

int main() { 
    stdio_init_all();

    Keyboard& keyboard = Keyboard::getInstance();

    Display& display = ST7735::getInstance();
    Canvas *canvas = new BufferedCanvas(display.get_width(), display.get_height());
    
    RenderSystem r(*canvas, display);
    MovementSystem mv_system;
    Engine& engine = Engine::getInstance();
    
    for(int k = 0; k < 5; k++){
        for(int j = 0; j < 10; j++){
            Enemy *enemy = new Enemy(k * 10, j * 5);
            engine.add_entity(enemy);
        }
    }

    Player player;
    engine.add_entity(&player);

    engine.add_system(&r);
    engine.add_system(&mv_system);

    for(;;){
        engine.update();
    }

    return 0;
}