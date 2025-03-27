#ifndef _INPUT_H_
#define _INPUT_H_

#include "pico/stdlib.h"

class Input {
public:
    virtual ~Input() = default;

    virtual void config(uint8_t button_pin) = 0;
    virtual bool is_pressed(uint8_t button_pin) = 0;
    virtual bool is_pressed_once(uint8_t button_pin) = 0;
};

#endif