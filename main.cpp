#include "pico/stdlib.h"
#include <time.h>
#include <stdio.h>

#include "Engine/Drivers/DisplayDriver/ST7735.h"
#include "Engine/Canvas/BufferedCanvas.h"
#include "Engine/Canvas/BasicCanvas.h"
#include "Engine/Renderer/BasicRenderer.h"
#include "Engine/Nodes/SpriteNode.h"
#include "Engine/Nodes/SceneNode.h"
#include "Engine/Nodes/PlayerNode.h"

#include "assets.h"

int main() {
    stdio_init_all();
    const uint16_t test[4] = {
        0xF211, 0xF211,
        0xF211, 0xF211
    };

    Display& display = ST7735::getInstance();
    Canvas* canvas = new BufferedCanvas(display.get_width(), display.get_height());
    SceneNode scene;
    BasicRenderer renderer = BasicRenderer(display, *canvas);
    
    InputNode input = InputNode(0, 0);
    SpriteNode playerSprite = SpriteNode(0, 0, 48, 16, test);
    Player player = Player(&playerSprite, input);

    renderer.set_scene(&scene);

    scene.add_node(&player);
    for (;;) {
        scene.update();
        renderer.Render();
    }
    return 0;
}