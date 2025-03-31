#ifndef _PLATFORMER_H_
#define _PLATFORMER_H_

#include "Engine/Engine.h"
#include "Engine/Components/PositionComponent.h"
#include "Engine/Components/VelocityComponent.h"
#include "Engine/Components/TagComponent.h"
#include "Engine/Components/SquareComponent.h"
#include "Engine/Components/TextComponent.h"

#include "Engine/Drivers/DisplayDriver/ST7735.h"
#include "Engine/Drivers/InputDriver/Keyboard.h"

#include "Engine/Canvas/BufferedCanvas.h"
#include "Engine/Systems/RenderSystem.h"
#include "Engine/Systems/MovementSystem.h"
#include "Engine/Systems/CameraSystem.h"
#include "Engine/Systems/CollisionSystem.h"

#include "Games/platformer_game/Keys.h"

#include "Games/platformer_game/Assets.h"
#include "Games/platformer_game/Map.h"
#include "Games/platformer_game/Systems/PlayerSystem.h"
#include "Games/platformer_game/Systems/LifetimeSystem.h"


void load_level(const uint16_t* level, uint8_t width, uint8_t height){
    for(int i = 0; i < width * height; i++){
        uint16_t x = (i % width) * TILE_WIDTH + 1;
        uint16_t y = (i / height) * TILE_HEIGHT + 1;

        Entity* e = new Entity();
        e->add_component(new PositionComponent(x, y));
        e->add_component(get_sprite_component(level[i]));

        if(level[i] == 13 || level[i] == 12 || level[i] == 14 || level[i] == 15){
            e->add_component(new SquareComponent(x, y, 16, 16));
        }

        Engine::getInstance().add_entity(e);
    }
}

void game_init(){
    /* reference to engine */
    Engine& engine = Engine::getInstance();
    
    /* reference to display */
    Display& display = ST7735::getInstance();

    /* creating a canvas */
    BufferedCanvas* canvas = new BufferedCanvas(display.get_width(), display.get_height());

    /* render system */
    RenderSystem* render_system = new RenderSystem(*canvas, display);

    /* camera system */
    CameraSystem* camera_system = new CameraSystem();

    /* player system */
    PlayerSystem* player_system = new PlayerSystem();

    engine.add_system(new CollisionSystem());
    engine.add_system(player_system);
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

}

void run(uint8_t framerate){
    game_init();
    load_level(level1, MAP_HEIGHT, MAP_WIDTH);
    init_player(0, 0);

    uint64_t frame_time_us = 1000000 / framerate;
    uint64_t previous_time = time_us_64();

    /* engine reference for fast update call */
    Engine& engine = Engine::getInstance();

    Entity* e = new Entity();
    e->add_component(new TextComponent(100, 50, "Hello world!"));

    engine.add_entity(e);

    /* game loop */
    while(1){
        uint64_t current_time = time_us_64();
        uint64_t elapsed_time = current_time - previous_time;

        if(elapsed_time >= frame_time_us){
            /* update all systems */
            engine.update();
            
            previous_time = current_time;
            elapsed_time = time_us_64() - current_time;
            if(elapsed_time < frame_time_us){
                sleep_us(frame_time_us - elapsed_time);
            }
        }
    }
}

#endif