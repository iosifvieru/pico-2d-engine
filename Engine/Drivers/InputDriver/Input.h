#ifndef _INPUT_H_
#define _INPUT_H_

#include "pico/stdlib.h"

class Input {
public:
    virtual ~Input() = default;

    void config(uint8_t button_pin);
    bool is_pressed(uint8_t button_pin);
    bool is_pressed_once(uint8_t button_pin);
};

#endif