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
#include "Engine/Drivers/InputDriver/Keyboard.h"

#include "Games/Player.h"
#include "Games/Enemy.h"
#include "Games/Projectile.h"

int main() { 
    stdio_init_all();

    uint16_t test[4] = {
        0xF211, 0xF211, 
        0xF211, 0xF211
    };

    uint16_t texture_test[4] = {
        0xB22F, 0x31FB,
        0xFF11, 0x119b
    };

    Keyboard& keyboard = Keyboard::getInstance();

    Display& display = ST7735::getInstance();
    Canvas *canvas = new BufferedCanvas(display.get_width(), display.get_height());
    
    RenderSystem r(*canvas, display);
    MovementSystem mv_system;
    Engine engine;
    
    
    for(int k = 0; k < 20; k++){
        for(int j = 0; j < 10; j++){
            Enemy *enemy = new Enemy(k * 10, j * 5);
            engine.add_entity(enemy);
        }
    }

    Player player;
    PositionComponent* player_position = ((MovementNode*) player.get_component("MovementNode"))->position;

    engine.add_entity(&player);

    engine.add_system(&r);
    engine.add_system(&mv_system);

    /* keyboard test */
    keyboard.config(8);
    keyboard.config(14);
    keyboard.config(15);
    keyboard.config(13);

    for(;;){
        player.update();

        /* for now */
        if(keyboard.is_pressed(15)){
            if(Entity::no_entities < 250) {
                Projectile* projectile = new Projectile(player_position->x, player_position->y);
                engine.add_entity(projectile);
            }
        }

        engine.update();

        sleep_ms(16);
    }

    return 0;
}