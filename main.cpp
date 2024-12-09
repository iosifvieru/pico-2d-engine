#include "pico/stdlib.h"
#include "pico/multicore.h"
#include <time.h>
#include <stdio.h>

#include "Engine/Drivers/DisplayDriver/ST7735.h"
#include "Engine/Canvas/BufferedCanvas.h"
#include "Engine/Renderer/BasicRenderer.h"
#include "Engine/Nodes/SpriteNode.h"
#include "Engine/Nodes/SceneNode.h"
#include "Engine/Nodes/PlayerNode.h"

int main() {
    stdio_init_all();
    const uint16_t test[4] = {
        0xF211, 0xF211,
        0xF211, 0xF211
    };

    const uint16_t test2[4] = {
        0x001f, 0x001f,
        0x001f, 0x001f
    };

    Display& display = ST7735::getInstance();
    Canvas* canvas = new BufferedCanvas(display.get_width(), display.get_height());
    SceneNode scene;
    BasicRenderer renderer = BasicRenderer(display, *canvas);
    
    InputNode input = InputNode(0, 0);
    
    SpriteNode playerSprite = SpriteNode(0, 0, 2, 2, test2);
    Player player = Player(&playerSprite, input);

    renderer.set_scene(&scene);

    scene.add_node(&player);

    for (;;) {
        scene.update();

        renderer.Render();
    }
    return 0;
}