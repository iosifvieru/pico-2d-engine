#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include "pico/stdlib.h"

/*
Interface for display
*/
class Display {
public:
    virtual ~Display() = default;
    
    /*
    draws a buffer to the display.
    each display implements it s on way to communicate with the hardware.

    for example in the ST7735's case the communication is made using SPI.
    */
    virtual void flush(const uint16_t* buffer) = 0;

    virtual uint16_t get_height() = 0;
    virtual uint16_t get_width() = 0;
};

#endif