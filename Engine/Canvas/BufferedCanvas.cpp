#include "BufferedCanvas.h"
#include "Engine/Logger/Logger.h"

#include <string.h>

/* constructor */
BufferedCanvas::BufferedCanvas(uint16_t width, uint16_t height) : Canvas(width, height){
    this->buffer = new uint16_t[width * height];

    // fill screen with a certain color
    fill(0x0000);

    Logger::log("BufferedCanvas().");
}

/* delets front buffer and back buffer. */
BufferedCanvas::~BufferedCanvas(){
    if(buffer != nullptr){
        delete[] buffer;
    }

    Logger::log("~BufferedCanvas().");
}

uint16_t* BufferedCanvas::get_buffer(){
    return this->buffer;
}

void BufferedCanvas::fill(uint16_t color){

    // TODO: maybe a better way to do this.
    /*for(int i = 0; i < this->height * this->width; i++){
        this->buffer[i] = color;
    }*/
   memset(this->buffer, color, width*height * sizeof(uint16_t));
}

void BufferedCanvas::set_pixel(uint16_t x, uint16_t y, uint16_t color){
    if(x > width || x < 0){
        return;
    }

    if(y > height || y < 0){
        return;
    }

    this->buffer[x * width + y] = color;
};

uint16_t BufferedCanvas::get_pixel(uint16_t x, uint16_t y){
    if(x > width || x < 0){
        // TODO: wtf do i do if the x or y is invalid? do i return 0??
        return 0;
    }

    if(y > height | y < 0){
        return 0;
    }

    return buffer[x * width + y];
}

void BufferedCanvas::draw_sprite(
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

void BufferedCanvas::draw_sprite(
    uint16_t x, uint16_t y, 
    uint16_t scale_factor, uint16_t sprite_width, uint16_t sprite_height, 
    const uint16_t* sprite) {
        
    for (uint16_t j = 0; j < sprite_height * scale_factor; ++j) {
        for (uint16_t i = 0; i < sprite_width * scale_factor; ++i) {
            uint16_t orig_x = i / scale_factor;
            uint16_t orig_y = j / scale_factor;

            uint16_t canvas_x = x + i;
            uint16_t canvas_y = y + j;

            if (canvas_x < width && canvas_y < height) {
                uint16_t color = sprite[orig_y * sprite_width + orig_x];

                buffer[canvas_y * width + canvas_x] = color;
            }
        }
    }
}

void BufferedCanvas::clear() {
    for(int i = 0; i < width * height; i++){
        buffer[i] = 0x0000;
    }
}

void BufferedCanvas::clear_pixel(uint16_t x, uint16_t y){
    this->buffer[x * width + y] = 0x0000;
}