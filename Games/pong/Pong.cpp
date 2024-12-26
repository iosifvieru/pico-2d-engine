#include "Games/pong/Pong.h"

#include "pico/stdlib.h"
#include <stdio.h>

/* THE GAME OF PONG ! */
Pong::Pong(){
    this->framerate = 60;

    this->is_running = true;

    /* reference to engine */
    Engine& engine = Engine::getInstance();
    
    /* reference to display */
    Display& display = ST7735::getInstance();

    /* creating a canvas */
    BufferedCanvas* canvas = new BufferedCanvas(display.get_width(), display.get_height());

    /* render system */
    RenderSystem* render_system = new RenderSystem(*canvas, display);

    /* movement system */
    MovementSystem* movement_system = new MovementSystem();

    /* input system */
    InputSystem* input_system = new InputSystem();

    /* collision system */
    CollisionSystem* collision_system = new CollisionSystem();

    /* keyboard configuration */
    Keyboard& keyboard = Keyboard::getInstance();
    keyboard.config(UP_KEY);
    keyboard.config(DOWN_KEY);

    /* adding systems */
    engine.add_system(render_system);
    engine.add_system(movement_system);
    engine.add_system(input_system);
    engine.add_system(collision_system);

    /* creating the ball */
    create_ball((display.get_height() / 2) + 10, display.get_width() / 2, 1);
    
    /* creating the player */
    create_player(0, 50, false);

    /* creating the enemy */
    create_player(display.get_width() - 4, 50, true);
};

Pong::~Pong(){

};

void Pong::loop(){
    uint64_t frame_time_us = 1000000 / this->framerate;
    uint64_t previous_time = time_us_64();

    while(this->is_running == true) {
        uint64_t current_time = time_us_64();
        uint64_t elapsed_time = current_time - previous_time;

        if(elapsed_time >= frame_time_us){
            float delta_time = elapsed_time / 1e6f;

            /* engine update */
            Engine::getInstance().update();

            previous_time = current_time;
            elapsed_time = time_us_64() - current_time;
            if(elapsed_time < frame_time_us){
                sleep_us(frame_time_us - elapsed_time);
            }
        }
    }
};