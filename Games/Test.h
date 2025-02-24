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

#include "Engine/Random.h"

#include "Games/Hero.h"

uint16_t sprite[16] = {
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
};

uint16_t player[9] = {
    0xffc0, 0xffc0, 0xffc0,
    0xf800, 0xFFFF, 0xf800,
    0xFFFF, 0xffc0, 0xFFFF,
};

#define A 8
#define D 14
#define W 13
#define S 15

#define SPEED 1

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

        /* keyboard configuration */
        Keyboard& keyboard = Keyboard::getInstance();
        keyboard.config(A);
        keyboard.config(D);
        keyboard.config(W);
        keyboard.config(S);

        engine.add_system(render_system);
        engine.add_system(camera_system);
        engine.add_system(new MovementSystem());
    }
    void run() {

        /* some test entity with camera !! */
        Entity* e = new Entity();
        e->add_component(new PositionComponent(40, 55));
        e->add_component(new SpriteComponent(16, 16, hero));
        e->add_component(new VelocityComponent(1, 0));
        e->add_component(new CameraComponent(0, 0, 128, 128, 1));

        Engine::getInstance().add_entity(e);

        SpriteComponent* spriteC = new SpriteComponent(4, 4, sprite);

        /* creating some entities so i can test the camera feature. */
        for(int i = 0; i < 10; i++){
            Entity* e2 = new Entity();
            e2->add_component(new PositionComponent(rnd() % 200, rnd() % 100));
            e2->add_component(spriteC);

            Engine::getInstance().add_entity(e2);
        }

        while(1){
            Engine::getInstance().update();

            /* some basic movement */
            if(Keyboard::getInstance().is_pressed(A)){
                VelocityComponent* v = (VelocityComponent*) e->get_component("VelocityComponent");
                v->v_x = -SPEED;
            }
            else if(Keyboard::getInstance().is_pressed(D)){
                VelocityComponent* v = (VelocityComponent*) e->get_component("VelocityComponent");
                v->v_x = SPEED;
            }
            else if(Keyboard::getInstance().is_pressed(S)){
                VelocityComponent* v = (VelocityComponent*) e->get_component("VelocityComponent");
                v->v_y = -SPEED;
            }

            else if(Keyboard::getInstance().is_pressed(W)){
                VelocityComponent* v = (VelocityComponent*) e->get_component("VelocityComponent");
                v->v_y = SPEED;
            } else {
                VelocityComponent* v = (VelocityComponent*) e->get_component("VelocityComponent");
                v->v_x = 0;
                v->v_y = 0;
            }
        }
    }
};

#endif