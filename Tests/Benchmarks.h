/*
This file contains benchmarks for some of the modules in the project.
*/

#ifndef _BENCHMARKS_H_
#define _BENCHMARKS_H_

#include "pico/stdlib.h"
#include "Engine/Drivers/DisplayDriver/ST7735.h"

/* This function times the flush method implemented in the ST7735 driver.*/
uint64_t flush_benchmark(){
    ST7735& display = ST7735::getInstance();
    const uint16_t width = display.get_width();
    const uint16_t height = display.get_height();

    uint16_t* buffer_to_be_sent = new uint16_t[width*height];    
    if(buffer_to_be_sent == nullptr) return -1;

    for(int i = 0; i < width*height; i++){
        buffer_to_be_sent[i] = 0x0000;
    }

    /* get time */
    volatile uint64_t start = time_us_64();

    /* call flush */
    
    display.flush(buffer_to_be_sent);
    
    /* get time */
    volatile uint64_t end = time_us_64();
    
    /* calculate time */
    volatile uint64_t duration_us = end - start;

    delete[] buffer_to_be_sent;
    return duration_us;
}

/*
This functions times a flush with a O(N)^2 implementation.
*/
uint64_t ON2_flush_benchmark(){
    ST7735& display = ST7735::getInstance();
    const uint16_t width = display.get_width();
    const uint16_t height = display.get_height();

    uint16_t* buffer_to_be_sent = new uint16_t[width*height];    
    if(buffer_to_be_sent == nullptr) return -1;

    for(int i = 0; i < width*height; i++){
        buffer_to_be_sent[i] = 0x0000;
    }

    /* get time */
    volatile uint64_t start = time_us_64();

    for(int i = 0; i < ST7735_WIDTH; i++){
        for(int j = 0; j < ST7735_HEIGHT; j++){
            display.send_data(buffer_to_be_sent[i * ST7735_WIDTH + j] >> 8);
            display.send_data(buffer_to_be_sent[i * ST7735_WIDTH + j]);
        }
    }

    volatile uint64_t end = time_us_64();

    volatile uint64_t duration_us = end - start;

    delete[] buffer_to_be_sent;
    return duration_us;
}


#endif