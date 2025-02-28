#ifndef _RENDER_SYSTEM_H_
#define _RENDER_SYSTEM_H_

#include <vector>
#include "Engine/Systems/System.h"
#include "Engine/Canvas/Canvas.h"
#include "Engine/Drivers/DisplayDriver/Display.h"
#include "Engine/Components/CameraComponent.h"

/* 
    RenderSystem implements System inteface.
    has a canvas, a display and render nodes that are drawn to the display.
*/
class RenderSystem : public System {
private:
    Canvas& canvas;
    Display& display;

    CameraComponent* camera = nullptr;

public:
    RenderSystem(Canvas& canvas, Display& display);
    ~RenderSystem();

    /* system interface implementation */
    void update(const std::vector<Entity*>& entities) override;

    CameraComponent* search_for_camera(const std::vector<Entity*>& entities);
};

#endif