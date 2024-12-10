#include <iostream>

#include "BufferedCanvas.h"
#include "Engine/Logger/Logger.h"


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
}

BufferedCanvas::~BufferedCanvas(){
    delete[] this->back_buffer;
    delete[] this->front_buffer;
}

uint16_t* BufferedCanvas::get_buffer(){
    /* swap */
    this->swap_buffers();
    return this->front_buffer;
}

void BufferedCanvas::draw_sprite(uint16_t x, uint16_t y, uint16_t sprite_width, uint16_t sprite_height, const uint16_t* sprite){
    for (uint16_t j = 0; j < sprite_height; ++j) {
        for (uint16_t i = 0; i < sprite_width; ++i) {
            uint16_t canvas_x = x + i;
            uint16_t canvas_y = y + j;

            if (canvas_x < width && canvas_y < height) {
                uint16_t color = sprite[j * sprite_width + i];

                this->back_buffer[canvas_y * width + canvas_x] = color;
            }
        }
    }
}

void BufferedCanvas::fill(uint16_t color){

    // TODO: maybe a better way to do this.
    for(int i = 0; i < this->height * this->width; i++){
        this->back_buffer[i] = color;
    }

}

void BufferedCanvas::set_pixel(uint16_t x, uint16_t y, uint16_t color) {
    if(x > width || x < 0){
        return;
    }

    if(y > height || y < 0){
        return;
    }

    this->back_buffer[x * width + y] = color;
}