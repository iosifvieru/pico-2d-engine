/*
    This is a buffered canvas.
    It is responsible with managing a double buffered canvas.
    the color 0x0000 is ignored for now for PNG like behaviour.
*/

#include "BufferedCanvas.h"
#include "Engine/Logger/Logger.h"
#include <math.h>

BufferedCanvas::BufferedCanvas(uint16_t width, uint16_t height) : Canvas(width, height){
    this->back_buffer = new uint16_t[width * height];
    
    if(this->back_buffer == nullptr){
        Logger::log("[BufferedCanvas] Eroare la alocarea memoriei pentru back_buffer.");
        exit(EXIT_FAILURE);
    }

    this->front_buffer = new uint16_t[width * height];
    if(this->front_buffer == nullptr){
        Logger::log("[BufferedCanvas] Eroare la alocarea memoriei pentru front_buffer.");
        exit(EXIT_FAILURE);
    }

    std::fill(back_buffer, back_buffer + width * height, 0x0000);
    std::fill(front_buffer, front_buffer + width * height, 0x0000);
}

/* destructor */
BufferedCanvas::~BufferedCanvas(){
    delete[] this->back_buffer;
    delete[] this->front_buffer;
}

/* swaps the buffers and returns the front buffer */
const uint16_t* BufferedCanvas::get_buffer(){
    std::swap(back_buffer, front_buffer);
    return this->front_buffer;
}

/* 
    draws a sprite to the canvas.
*/
void BufferedCanvas::draw_sprite(uint16_t x, uint16_t y, uint16_t sprite_width, uint16_t sprite_height, const uint16_t* sprite){
    for (int16_t j = 0; j < sprite_height; ++j) {
        int16_t canvas_y = y + j;

        if (canvas_y >= height || canvas_y < 0) { continue; }
        for (uint16_t i = 0; i < sprite_width; ++i) {
            int16_t canvas_x = x + i;

            if (canvas_x >= width || canvas_x < 0) { continue; }

            if (canvas_x < width && canvas_y < height) {
                uint16_t color = sprite[j * sprite_width + i];

                /* 0x0000 will be ignored */
                if(color == 0x0000) continue;

                /* avoiding unnecessary writings. */
                if (this->back_buffer[canvas_y * width + canvas_x] != color) {
                    this->back_buffer[canvas_y * width + canvas_x] = color;
                }
            }
        }
    }
}

/* fills the canvas with a color. */
void BufferedCanvas::fill(uint16_t color){
    std::fill(back_buffer, back_buffer + width * height, color);
}

/* sets a color to a pixel */
void BufferedCanvas::set_pixel(uint16_t x, uint16_t y, uint16_t color) {
    if(x >= width || x <= 0) return;
    if(y >= height || y <= 0) return;

    this->back_buffer[y * width + x] = color;
}

/* 
    draws a line to the canvas. 
    https://rosettacode.org/wiki/Bitmap/Bresenham's_line_algorithm    
*/
void BufferedCanvas::draw_line(uint16_t x_start, uint16_t y_start, uint16_t x_end, uint16_t y_end, uint16_t color) {

    int dx = abs((int)x_end - (int)x_start);
    int dy = abs((int)y_end - (int)y_start);

    int sx = (x_start < x_end) ? 1 : -1;
    int sy = (y_start < y_end) ? 1 : -1;
    int err = dx - dy;

    while(true){
        this->set_pixel(x_start, y_start, color);
        if(x_start == x_end && y_start == y_end) break;

        int e2 = 2 * err;
        if(e2 > -dy){
            err -= dy;
            x_start += sx;
        }
        if(e2 < dx){
            err += dx;
            y_start += sy;
        }
    }
};

/* returns the color of a pixel. */
uint16_t BufferedCanvas::get_pixel(uint16_t x, uint16_t y){
    if(x > width || x < 0){
        return 0x0000;
    }

    if(y > height || y < 0){
        return 0x0000;
    }

    return this->front_buffer[x * width + y];
};

/*
    x1,y2-------------x2,y2
    |                   |
    |                   |
    |                   |
    x1,y1-------------x2,y1  
*/
void BufferedCanvas::draw_rect(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color){
    // for (uint16_t i = 0; i < y2; ++i) {
    //     for (uint16_t j = 0; j < x2; ++j) {
    //         this->set_pixel(x1 + j, y1 + i, color);
    //     }
    // }

    // liniile de sus si jos
    for (uint16_t i = 0; i < x2; ++i) {
        set_pixel(x1 + i, y1, color);
        set_pixel(x1 + i, y1 + y2 - 1, color);
    }

    // liniile din stanga dreapta
    for (uint16_t i = 0; i < y2; ++i) {
        set_pixel(x1, y1 + i, color);
        set_pixel(x1 + x2 - 1, y1 + i, color);
    }
}
