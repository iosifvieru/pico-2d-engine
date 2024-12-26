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
#include "Games/universe-invader/CustomSystems/ShootingSystem.h"
#include "Games/universe-invader/CustomSystems/ProjectileSystem.h"

// entity
#include "Engine/Entity/Entity.h"

// components
#include "Engine/Components/SpriteComponent.h"
#include "Engine/Components/PositionComponent.h"
#include "Engine/Components/VelocityComponent.h"

#include "Engine/Engine.h"
#include "Games/universe-invader/Game.h"
#include "Games/universe-invader/CustomSystems/CollisionHandler.h"
#include "Games/universe-invader/CustomSystems/EnemySystem.h"
#include "Games/universe-invader/CustomSystems/InputSystem.h"

#include "Engine/Random.h"

int main() { 
    stdio_init_all();

    Keyboard& keyboard = Keyboard::getInstance();
    keyboard.config(8);
    keyboard.config(14);
    keyboard.config(13);

    Display& display = ST7735::getInstance();

    BufferedCanvas canvas = BufferedCanvas(display.get_width(), display.get_height());    

    RenderSystem r(canvas, display);
    InputSystem input_system;
    MovementSystem mv_system;
    CollisionSystem collision_system;
    ShootingSystem shooting_system;
    ProjectileSystem projectile_system;
    CollisionHandler collision_handler;
    EnemySystem ems;

    Engine& engine = Engine::getInstance();
    engine.init();

    engine.add_system(&shooting_system);
    engine.add_system(&projectile_system);
    engine.add_system(&mv_system);
    engine.add_system(&collision_system);
    engine.add_system(&r);
    engine.add_system(&collision_handler);
    engine.add_system(&ems);
    engine.add_system(&input_system);

    game_init();
    
    create_player(100, 100);

    create_enemy(100, 20);

    for (;;) {
        engine.update();
    }

    return 0;
}