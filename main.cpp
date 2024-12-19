#include "pico/stdlib.h"
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <random>

#include "Engine/Drivers/DisplayDriver/ST7735.h"
#include "Engine/Canvas/BufferedCanvas.h"
#include "Engine/Canvas/BasicCanvas.h"

#include "Engine/Systems/MovementSystem.h"

#include "Engine/Entity/Entity.h"
#include "Engine/Engine.h"
#include "Engine/Drivers/InputDriver/Keyboard.h"
#include "Engine/Systems/RenderSystem.h"
#include "Engine/Systems/CollisionSystem.h"

#include "Engine/Components/PositionComponent.h"
#include "Engine/Components/SpriteComponent.h"

#include "Games/TestEntity.h"

int main() { 
    stdio_init_all();

    Keyboard& keyboard = Keyboard::getInstance();
    Display& display = ST7735::getInstance();
    Canvas *canvas = new BufferedCanvas(display.get_width(), display.get_height());
    RenderSystem r(*canvas, display);
    
    MovementSystem mv_system;
    CollisionSystem collision_system;

    Engine& engine = Engine::getInstance();
    
    keyboard.config(13);

    engine.add_system(&mv_system);
    engine.add_system(&r);
    engine.add_system(&collision_system);

    TestEntity* test_entity = new TestEntity();
    engine.add_entity(test_entity);

    Enemy* static_enemy2 = new Enemy(100, 50);
    static_enemy2->set_velocity(0, 0);
    static_enemy2->set_lifespan(9999); 
    static_enemy2->collision->set_width(20);
    static_enemy2->collision->set_height(50);

    engine.add_entity(static_enemy2);

    for(;;){
        engine.update();
        sleep_ms(16);
    }


    return 0;
}