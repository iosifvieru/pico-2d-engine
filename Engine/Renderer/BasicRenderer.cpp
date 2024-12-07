#include "BasicRenderer.h"
#include "Engine/Canvas/BufferedCanvas.h"

BasicRenderer::BasicRenderer(Display& display)
    : Renderer(display) {
        Logger::log("BasicRenderer().");
}

extern uint16_t x;
extern uint16_t y;

void BasicRenderer::Render() {
    Logger::log("x: %d  y: %d", x, y);

    int h = display.get_height();
    int w =  display.get_width();
    uint16_t* buffer = new uint16_t[w * h];

    for(int i = 0; i < w * h; i++){
        buffer[i] = 0x0000;
    }

    buffer[y * w + x] = 0xFFFF;

    buffer[100 * w + 3] = 0xF12F;
    buffer[100 * w + 4] = 0xF12F;
    buffer[99 * w + 3] = 0xF12F;
    buffer[99 * w + 4] = 0xF12F;

    display.flush(buffer);

    delete[] buffer;

    Logger::log("Renderer...");
}
