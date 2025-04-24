#ifndef _PLATFORMER_H_
#define _PLATFORMER_H_

#include "Engine/Core.h"

/* game specific includes */
#include "Games/platformer_game/Assets.h"
#include "Games/platformer_game/Map.h"
#include "Games/platformer_game/Systems/PlayerSystem.h"
#include "Games/platformer_game/Systems/LifetimeSystem.h"
#include "Games/platformer_game/Systems/EnemySystem.h"
#include "Games/platformer_game/Enemy.h"

void load_level(const uint16_t* level, uint8_t width, uint8_t height){
    for(int i = 0; i < width * height; i++){
        uint16_t x = (i % width) * TILE_WIDTH + 1;
        uint16_t y = (i / height) * TILE_HEIGHT + 1;

        Entity* e = Entity::create();
        if(e == nullptr) continue;
        
        e->add_component(new PositionComponent(x, y));
        e->add_component(get_sprite_component(level[i]));

        if(level[i] == 13 || level[i] == 12 || level[i] == 14 || level[i] == 15){
            SquareComponent* sq = new SquareComponent(x, y, 16, 16);
            sq->is_visible = false;
            e->add_component(sq);
        }

        Engine::getInstance().add_entity(e);
    }
}

void platformer_init(){
    /* reference to engine */
    Engine& engine = Engine::getInstance();
    
    /* reference to display */
    Display& display = ST7735::getInstance();

    /* creating a canvas */
    BufferedCanvas* canvas = new BufferedCanvas(display.get_width(), display.get_height());

    /* render system */
    RenderSystem* render_system = new RenderSystem(canvas, &display);

    /* camera system */
    CameraSystem* camera_system = new CameraSystem();

    /* player system */
    PlayerSystem* player_system = new PlayerSystem();

    engine.add_system(new CollisionSystem());
    engine.add_system(new PhysicsSystem());
    engine.add_system(player_system);
    engine.add_system(new EnemySystem());
    engine.add_system(new MovementSystem());
    engine.add_system(new LifetimeSystem());
    engine.add_system(camera_system);
    engine.add_system(render_system);

    /* init keyboard */
    Keyboard& keyboard = Keyboard::getInstance();

    keyboard.config(A);
    keyboard.config(S);
    keyboard.config(W);
    keyboard.config(D);

    load_level(level1, MAP_HEIGHT, MAP_WIDTH);
    init_player(0, 0);
    create_enemy(200, 20);
}

#endif