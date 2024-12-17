#ifndef _COMPONENTS_H_
#define _COMPONENTS_H_

#include "pico/stdlib.h"

/*
in this file all the components will be defined for now.
*/

/* i will use structs for now for less overhead. */

struct Component {
    virtual ~Component() = default;
};

struct PositionComponent : public Component {
    uint16_t x = 0;
    uint16_t y = 0;
    uint16_t z = 0;
    uint16_t angle = 0;

    PositionComponent() {};
    PositionComponent(uint16_t x, uint16_t y, uint16_t z, uint16_t angle) 
        : x(x), y(y), z(z), angle(angle) {};

    ~PositionComponent() {
        
    }
};

struct SpriteComponent : public Component {
    uint8_t width = 0;
    uint8_t height = 0;
    uint16_t* sprite = nullptr;

    SpriteComponent() {};
    SpriteComponent(uint8_t width, uint8_t height, uint16_t* sprite){
        this->width = width;
        this->height = height;
        this->sprite = sprite;
    }

    ~SpriteComponent(){
        // not deleting the sprite
    }
};

struct VelocityComponent : public Component {
    int8_t v_x = 0;
    int8_t v_y = 0;

    VelocityComponent(int8_t x, int8_t y) : v_x(x), v_y(y) {};
    VelocityComponent() {};

    ~VelocityComponent() {

    }
};

struct SquareComponent : public Component {
    uint16_t min_x = 0;
    uint16_t min_y = 0;
    uint16_t max_x = 0;
    uint16_t max_y = 0;

    SquareComponent() {};
    ~SquareComponent() {};

    SquareComponent(uint16_t min_x, uint16_t min_y, uint16_t max_x, uint16_t max_y){
        this->min_x = min_x;
        this->min_y = min_y;
        this->max_x = max_x;
        this->max_y = max_y;
    }
};

#endif