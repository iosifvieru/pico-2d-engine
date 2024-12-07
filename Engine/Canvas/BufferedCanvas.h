#ifndef _BUFFERED_CANVAS_H_
#define _BUFFERED_CANVAS_H_

#include "Canvas.h"

class BufferedCanvas : public Canvas {
private:
    uint16_t* buffer;
public:
    BufferedCanvas(uint16_t width, uint16_t height);
    ~BufferedCanvas();

    /* returns the canvas buffer */
    uint16_t* get_buffer();

    /* fills the canvas with a certain color */
    void fill(uint16_t color) override;

    void clear_pixel(uint16_t x, uint16_t y) override;

    /* sets a certain pixel's color */
    void set_pixel(uint16_t x, uint16_t y, uint16_t color) override;

    /* gets the color of a pixel */
    uint16_t get_pixel(uint16_t x, uint16_t y) override;

    /* draws a sprite to a certain x, y position. */
    void draw_sprite(uint16_t x, uint16_t y, uint16_t sprite_width, uint16_t sprite_height, const uint16_t* sprite) override;

    void clear_sprite(uint16_t x, uint16_t y, uint16_t sprite_width, uint16_t sprite_height) override;

    /* draw a line to the canvas */
    void draw_line(uint16_t x_start, uint16_t y_start, uint16_t x_end, uint16_t y_end, uint16_t color) override {};

    void clear() override;
};

#endif