#include "BasicCanvas.h"
#include "Engine/Logger/Logger.h"

#include <string.h>

/* constructor */
BasicCanvas::BasicCanvas(uint16_t width, uint16_t height) : Canvas(width, height){
    this->buffer = new uint16_t[width * height];

    // fill screen with a certain color
    fill(0x0000);

    Logger::log("BasicCanvas().");
}

/* delets front buffer and back buffer. */
BasicCanvas::~BasicCanvas(){
    if(buffer != nullptr){
        delete[] buffer;
    }

    Logger::log("~BasicCanvas().");
}

/* returns the pointer to the buffer. */
uint16_t* BasicCanvas::get_buffer(){
    return this->buffer;
}

/* fills the canvas with a certain color. */
void BasicCanvas::fill(uint16_t color){

    // TODO: maybe a better way to do this.
    for(int i = 0; i < this->height * this->width; i++){
        this->buffer[i] = color;
    }
   //memset(this->buffer, color, width*height * sizeof(uint16_t));
}

/* sets a pixel's color */
void BasicCanvas::set_pixel(uint16_t x, uint16_t y, uint16_t color){
    if(x > width || x < 0){
        return;
    }

    if(y > height || y < 0){
        return;
    }

    this->buffer[x * width + y] = color;
};

/* gets a color of a pixel. */
uint16_t BasicCanvas::get_pixel(uint16_t x, uint16_t y){
    if(x > width || x < 0){
        // TODO: wtf do i do if the x or y is invalid? do i return 0??
        return 0;
    }

    if(y > height | y < 0){
        return 0;
    }

    return buffer[x * width + y];
}

/* draw a sprite */
void BasicCanvas::draw_sprite(
    uint16_t x, uint16_t y, 
    uint16_t sprite_width, uint16_t sprite_height, const uint16_t* sprite){

    for (uint16_t j = 0; j < sprite_height; ++j) {
        for (uint16_t i = 0; i < sprite_width; ++i) {
            uint16_t canvas_x = x + i;
            uint16_t canvas_y = y + j;

            if (canvas_x < width && canvas_y < height) {
                uint16_t color = sprite[j * sprite_width + i];

                buffer[canvas_y * width + canvas_x] = color;
            }
        }
    }
}

/* clear the buffer */
void BasicCanvas::clear() {
    /*
    for(int i = 0; i < width * height; i++){
        buffer[i] = 0x0000;
    } */

   this->fill(0x0000);
}