#ifndef _COMPONENTS_H_
#define _COMPONENTS_H_

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
};

struct SpriteComponent : public Component {
    uint8_t width;
    uint16_t height;
    uint16_t* sprite;
};

#endif