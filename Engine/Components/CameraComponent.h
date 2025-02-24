#ifndef _CAMERA_COMPONENT_H_
#define _CAMERA_COMPONENT_H_

#include "Engine/Components/Component.h"

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

    const char* get_component_name() {
        return "CameraComponent";
    }
};

#endif