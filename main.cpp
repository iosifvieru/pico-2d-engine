#include "pico/stdlib.h"
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <random>

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
#include "Engine/Nodes/SquareCollider.h"
#include "Engine/Systems/CollisionSystem.h"

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
    CollisionSystem collision_system;

    Engine& engine = Engine::getInstance();

    Player player;
    engine.add_entity(&player);

    engine.add_system(&collision_system);
    engine.add_system(&mv_system);
    engine.add_system(&r);

    for(int i = 0 ; i < 30; i++){
        Enemy* e = new Enemy(random() % 120 + 5, random() % 30 + 5);
        engine.add_entity(e);
    }

    for(;;){
        engine.update();

        sleep_ms(17);
    }

    return 0;
}