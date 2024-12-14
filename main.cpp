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

int main() { 
    stdio_init_all();

    uint16_t test[4] = {
        0xF211, 0xF211, 
        0xF211, 0xF211
    };

    Display& display = ST7735::getInstance();
    Canvas *canvas = new BufferedCanvas(display.get_width(), display.get_height());
    
    RenderSystem r(*canvas, display);
    MovementSystem mv_system;

    PositionComponent player_position(50, 20, 0, 0);

    RenderNode render_node_1(
        &player_position, new SpriteComponent(2, 2, test)
    );
    
    VelocityComponent player_velocity(10, 0);

    MovementNode player_movement(&player_position, &player_velocity);

    Entity player;
    player.add_component("RenderNode", &render_node_1);
    player.add_component("MovementNode", &player_movement);

    Engine engine;
    engine.add_entity(&player);

    engine.add_system(&r);
    engine.add_system(&mv_system);

    for(;;){
        player_position.x %= 128;
        engine.update();
    }

    return 0;
}