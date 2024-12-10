#include "BasicRenderer.h"
#include "Engine/Canvas/BasicCanvas.h"

#include <string.h>

BasicRenderer::BasicRenderer(Display& display, Canvas& canvas)
    : Renderer(display, canvas) {
        Logger::log("BasicRenderer().");
}

void BasicRenderer::Render() {

    canvas.fill(0x0000);
    
    /* render everything */
    this->scene->render(canvas);

    /* flush it to display*/
    display.flush(canvas.get_buffer());
    
    Logger::log("Renderer...");
}
