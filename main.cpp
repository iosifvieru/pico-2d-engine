#include "pico/stdlib.h"

// drivers
#include "Engine/Drivers/DisplayDriver/ST7735.h"
#include "Engine/Drivers/InputDriver/Keyboard.h"

// rendering
#include "Engine/Canvas/BufferedCanvas.h"

// systems
#include "Engine/Systems/RenderSystem.h"
#include "Engine/Systems/CollisionSystem.h"
#include "Engine/Systems/MovementSystem.h"
#include "Games/CustomSystems/ShootingSystem.h"
#include "Games/CustomSystems/ProjectileSystem.h"

// entity
#include "Engine/Entity/Entity.h"

// components
#include "Engine/Components/SpriteComponent.h"
#include "Engine/Components/PositionComponent.h"
#include "Engine/Components/VelocityComponent.h"

#include "Engine/Engine.h"
#include "Games/Game.h"


int main() { 
    stdio_init_all();

    Keyboard& keyboard = Keyboard::getInstance();
    keyboard.config(8);
    keyboard.config(14);
    keyboard.config(13);

    Display& display = ST7735::getInstance();

    BufferedCanvas canvas = BufferedCanvas(display.get_width(), display.get_height());    

    RenderSystem r(canvas, display);
    MovementSystem mv_system;
    CollisionSystem collision_system;
    ShootingSystem shooting_system;
    ProjectileSystem projectile_system;

    Engine& engine = Engine::getInstance();

    engine.add_system(&mv_system);
    engine.add_system(&collision_system);
    engine.add_system(&r);
    engine.add_system(&shooting_system);
    engine.add_system(&projectile_system);

    game_init();

    for(int i = 0; i < 20; i++){
        create_enemy(rand() % 120, rand() % 50);
    }

    create_player(100, 100);

    for (;;) {

        engine.update();
    }
    return 0;
}