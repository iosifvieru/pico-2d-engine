#include "pico/stdlib.h"
#include <time.h>
#include <stdio.h>
#include <string.h>

#include "Engine/Drivers/DisplayDriver/ST7735.h"
#include "Engine/Canvas/BufferedCanvas.h"
#include "Engine/Canvas/BasicCanvas.h"
#include "Engine/Nodes/RenderNode.h"
#include "Engine/Systems/RenderSystem.h"

#include "Engine/Entity/Entity.h"

int main() { 
    stdio_init_all();

    uint16_t test[64] = {
        0xF211, 0xF211, 0xF211, 0xF211, 0xF211, 0xF211, 0xF211, 0xF211,
        0xF211, 0xF211, 0xF211, 0xF211, 0xF211, 0xF211, 0xF211, 0xF211,
        0xF211, 0xF211, 0xF211, 0xF211, 0xF211, 0xF211, 0xF211, 0xF211,
        0xF211, 0xF211, 0xF211, 0xF211, 0xF211, 0xF211, 0xF211, 0xF211,
        0xF211, 0xF211, 0xF211, 0xF211, 0xF211, 0xF211, 0xF211, 0xF211,
        0xF211, 0xF211, 0xF211, 0xF211, 0xF211, 0xF211, 0xF211, 0xF211,
        0xF211, 0xF211, 0xF211, 0xF211, 0xF211, 0xF211, 0xF211, 0xF211,
        0xF211, 0xF211, 0xF211, 0xF211, 0xF211, 0xF211, 0xF211, 0xF211
    };

    Display& display = ST7735::getInstance();
    Canvas *canvas = new BufferedCanvas(display.get_width(), display.get_height());
    
    RenderSystem r(*canvas, display);

    SpriteComponent sp;
    sp.width = 8;
    sp.height = 8;
    sp.sprite = test;

    PositionComponent p;
    p.x = 10;
    p.y = 10;

    PositionComponent p2;
    p2.x = 0;
    p2.y = 0;

    RenderNode test_node;
    test_node.position = &p;
    test_node.sprite = &sp;

    RenderNode test_node2;
    test_node2.position = &p2;
    test_node2.sprite = &sp;

    Entity e;
    e.add_component("RenderNode", &test_node2);

    Entity e2;
    e2.add_component("RenderNode", &test_node);

    PositionComponent p4;
    p4.x = 55;
    p4.y = 40;

    RenderNode rn1;
    rn1.position = &p4;
    rn1.sprite = &sp;

    Entity e4;
    e4.add_component("RenderNode", &rn1);

    r.addEntity(&e);
    //r.addEntity(&e2);
    //r.addEntity(&e4);

    for(;;){
    
        p.x++;
        p.x %= 128;

        p2.x++;
        p2.x %=128;

        p4.x++;
        p4.x %= 128;

        /* updating the render. */
        r.update();


        sleep_ms(50);
    }

    return 0;
}