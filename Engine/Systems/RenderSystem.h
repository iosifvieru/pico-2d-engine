#ifndef _RENDER_SYSTEM_H_
#define _RENDER_SYSTEM_H_

#include <vector>
#include "Engine/Systems/System.h"
#include "Engine/Canvas/Canvas.h"
#include "Engine/Drivers/DisplayDriver/Display.h"

/* 
    RenderSystem implements System inteface.
    has a canvas, a display and render nodes that are drawn to the display.
*/
class RenderSystem : public System {
private:
    Canvas& canvas;
    Display& display;

public:
    RenderSystem(Canvas& canvas, Display& display);
    ~RenderSystem();

    /* system interface implementation */
    void update(std::vector<Entity*> entities) override;
};

#endif