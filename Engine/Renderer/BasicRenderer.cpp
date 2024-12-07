#include "BasicRenderer.h"
#include "Engine/Canvas/BufferedCanvas.h"

BasicRenderer::BasicRenderer(Display& display, Canvas& canvas)
    : Renderer(display, canvas) {
        Logger::log("BasicRenderer().");
}

void BasicRenderer::Render() {

    /* reset */
    canvas.fill(0x0000);

    this->scene->render(canvas);

    display.flush(canvas.get_buffer());

    Logger::log("Renderer...");
}
