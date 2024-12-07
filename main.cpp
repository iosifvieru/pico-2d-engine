#include "pico/stdlib.h"
#include <time.h>
#include <stdio.h>

#include "Engine/Drivers/DisplayDriver/ST7735.h"
#include "Engine/Canvas/BufferedCanvas.h"
#include "Engine/Renderer/BasicRenderer.h"
#include "Engine/Nodes/SpriteNode.h"

uint16_t x = 10;
uint16_t y = 10;


int main() {
    stdio_init_all();

    gpio_init(8);
    gpio_set_dir(8, GPIO_IN);
    gpio_pull_up(8);

    gpio_init(14);
    gpio_set_dir(14, GPIO_IN);
    gpio_pull_up(14);

    Display& display = ST7735::getInstance();


    Canvas* canvas = new BufferedCanvas(display.get_width(), display.get_height());

    /* test sprite */
    const uint16_t sprite[8] = {
        0xffff, 0xf10f,
        0xabc1, 0x11fb,
        0x1111, 0x1212,
        0x1444, 0x1BCA
    };

    const uint16_t spritee[4] = {
        0xF211, 0xF211,
        0xF211, 0xF211
    };

    Node* main = new SpriteNode(50, 50, 2, 2, spritee);

    Node* player = new SpriteNode(10, 10, 4, 2, sprite);

    main->add_node(player);

    Renderer* renderer = new BasicRenderer(display, *canvas);

    renderer->set_scene(main);

    for (;;) {
        bool is_pressed_x = !gpio_get(8);
        bool is_pressed_y = !gpio_get(14);

        if (is_pressed_x) {
            x += 5;
            x = x % display.get_width();

            player->set_x(x);

            main->set_x(main->get_x() + 2);
        }

        if(is_pressed_y){
            y += 5;
            y = y % display.get_height();

            player->set_y(y);
            
            main->set_y(main->get_y() + 2);
        }

        renderer->Render();
    }
    return 0;
}