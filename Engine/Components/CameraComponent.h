#ifndef _CAMERA_COMPONENT_H_
#define _CAMERA_COMPONENT_H_

#include "Engine/Components/Component.h"

/*
CameraComponent represents the scene that will be flushed to the screen.alignas

x, y -> the position of the camera
width, height -> the dimensions of the camera.
zoom -> feature not implemented yet (should be set to 1 for the moment) due to the fact that there is no 
        actual way of scaling up or down the sprites. 
*/
class CameraComponent: public Component {
public:
    int16_t x, y;
    uint16_t width, height;
    float zoom;

    CameraComponent(int16_t x, int16_t y, uint16_t width, uint16_t height, float zoom){
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->zoom = zoom;
    }

    const char* get_component_name() const {
        return "CameraComponent";
    }
};

#endif