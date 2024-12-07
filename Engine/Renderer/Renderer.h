#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "Engine/Drivers/DisplayDriver/Display.h"
#include "Engine/Canvas/Canvas.h"
#include "Engine/Logger/Logger.h"

#include <vector>

/*
Renderer class.
it has a canvas and a display.
*/
class Renderer {
protected:
    Display& display;
    std::vector<Canvas*> layers;
public:
    Renderer(Display& display)
        : display(display)  {
        
        Logger::log("Renderer initialized.");
    }
    
    virtual void Render() = 0;

    void add_layer(Canvas *layer){
        layers.push_back(layer);
    }

    void remove_layer(Canvas& layer){
        
    }
};

#endif