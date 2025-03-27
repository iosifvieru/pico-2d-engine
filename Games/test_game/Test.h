#ifndef _TEST_H_
#define _TEST_H_

#include "Engine/Engine.h"
#include "Engine/Canvas/BufferedCanvas.h"
#include "Engine/Drivers/DisplayDriver/ST7735.h"
#include "Engine/Drivers/InputDriver/Keyboard.h"

#include "Engine/Systems/RenderSystem.h"
#include "Engine/Systems/CameraSystem.h"
#include "Engine/Systems/MovementSystem.h"

#include "Engine/Components/PositionComponent.h"
#include "Engine/Components/SpriteComponent.h"
#include "Engine/Components/VelocityComponent.h"
#include "Engine/Components/TagComponent.h"
#include "Engine/Components/SquareComponent.h"
#include "Engine/Components/CameraComponent.h"

#include "Engine/TextureManager.h"

#include "Engine/Random.h"
#include "Games/test_game/Map.h"
#include "Games/test_game/Assets.h"

#define A 8
#define D 14
#define W 13
#define S 15

const uint16_t test_sprite[9] = {
    0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF
};

#define SPEED 3

class Test {
public:
    Test() {
        /* reference to engine */
        Engine& engine = Engine::getInstance();
    
        /* reference to display */
        Display& display = ST7735::getInstance();

        /* creating a canvas */
        BufferedCanvas* canvas = new BufferedCanvas(display.get_width(), display.get_height());

        /* render system */
        RenderSystem* render_system = new RenderSystem(*canvas, display);

        CameraSystem* camera_system = new CameraSystem();

        engine.add_system(render_system);
        engine.add_system(camera_system);
        engine.add_system(new MovementSystem());

        Keyboard& keyboard = Keyboard::getInstance();

        keyboard.config(A);
        keyboard.config(S);
        keyboard.config(W);
        keyboard.config(D);
    }

    void run() {
        /* some test entity with camera !! */
        Entity* e = new Entity();

        map_init();

        SpriteComponent* hero_texture = new SpriteComponent(16, 16, hero_front); 

        e->add_component(new PositionComponent(20, 50));
        e->add_component(hero_texture);
        e->add_component(new VelocityComponent(10, 0));
        e->add_component(new CameraComponent(0, 0, 128, 128, 1));

        Engine::getInstance().add_entity(e);

        Entity* e2 = new Entity();
        e2->add_component(new PositionComponent(70, 60));
        e2->add_component(new SpriteComponent(16, 16, other_sprite));
        
        Engine::getInstance().add_entity(e2);        

        VelocityComponent* v = (VelocityComponent*) e->get_component("VelocityComponent");
        PositionComponent* p = (PositionComponent*) e->get_component("PositionComponent");

        /* 60 fps*/
        uint64_t frame_time_us = 1000000 / 60;
        uint64_t previous_time = time_us_64();

        int i = 0;

        while(1){
            uint64_t current_time = time_us_64();
            uint64_t elapsed_time = current_time - previous_time;

            if(elapsed_time >= frame_time_us){

                Engine::getInstance().update();

                if(Keyboard::getInstance().is_pressed(A)){
                    v->v_x = -SPEED;
                    hero_texture->set_sprite(hero_left);

                } else if(Keyboard::getInstance().is_pressed(D)) {
                    v->v_x = SPEED;
                    hero_texture->set_sprite(hero_right);
                }
                else if(Keyboard::getInstance().is_pressed(W)) {
                    v->v_y = -SPEED;
                    hero_texture->set_sprite(hero_up);
                } else if(Keyboard::getInstance().is_pressed(S)) {
                    v->v_y = SPEED;
                    hero_texture->set_sprite(hero_front);

                } else {
                    v->v_x = 0;
                    v->v_y = 0;
                }

                previous_time = current_time;
                elapsed_time = time_us_64() - current_time;
                if(elapsed_time < frame_time_us){
                    sleep_us(frame_time_us - elapsed_time);
                }
            }
        }
    }
};

#endif