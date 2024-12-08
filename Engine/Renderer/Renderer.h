#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "Engine/Drivers/DisplayDriver/Display.h"
#include "Engine/Canvas/Canvas.h"
#include "Engine/Logger/Logger.h"
#include "Engine/Nodes/Node.h"

#include <vector>

/*
Renderer class.
it has a canvas and a display.
*/
class Renderer {
protected:
    Display& display;
    Canvas& canvas;
    Node* scene;
    //std::vector<Canvas*> layers;
public:
    Renderer(Display& display, Canvas& canvas)
        : display(display), canvas(canvas)  {
        
        Logger::log("Renderer initialized.");
    }
    
    virtual void Render() = 0;

    void set_scene(Node* scene){
        if(scene == nullptr){
            return;
        }

        this->scene = scene;
    }
};

#endif