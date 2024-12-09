// Iosif Vieru

#include "ST7735.h"
#include "pico/stdlib.h"
#include "Engine/Utils/Utils.h"
#include "hardware/spi.h"
#include <string.h>

ST7735* ST7735::instance = nullptr;

inline void ST7735::set_mosi(bool level){
    gpio_put(this->mosi_pin, level);   
}

inline void ST7735::set_sck(bool level){
    gpio_put(this->sck_pin, level);
}

inline void ST7735::set_cs(bool level){
    gpio_put(this->cs, level);
}

inline void ST7735::set_dc(bool level){
    gpio_put(this->dc, level);
}

inline void ST7735::set_rst(bool level){
    gpio_put(this->rst, level);
}

/*
    Sends a 16 bit color to ST7735 display.
*/
inline void ST7735::send_color(uint16_t color){
    this->send_data(color & 0xFF);
    this->send_data(color >> 8);
}

inline void ST7735::send_byte(uint8_t byte){
    /*for(int8_t i = 7; i >= 0; i--) {
        this->set_mosi((byte >> i) & 0x01);
        this->set_sck(1);
        sleep_us(1);
        this->set_sck(0);
        sleep_us(1);
    }*/

   spi_write_blocking(spi0, &byte, 1);
}

void ST7735::send_command(uint8_t command){
    this->set_cs(0);
    this->set_dc(0);
    this->send_byte(command);
    this->set_cs(1);
}

void ST7735::send_data(uint8_t data){
    this->set_cs(0);
    this->set_dc(1);
    this->send_byte(data);
    this->set_cs(1);
}

void ST7735::reset(){
    this->set_rst(0);
    sleep_ms(100);
    this->set_rst(1);
    sleep_ms(100);
}

ST7735::ST7735(
    uint8_t sck_pin,
    uint8_t mosi_pin,
    uint8_t cs,
    uint8_t rst,
    uint8_t dc) {
        this->sck_pin = sck_pin;
        this->mosi_pin = mosi_pin;
        this->cs = cs;
        this->rst = rst;
        this->dc = dc;

        spi_init(spi0, 10000 * 2000);
        gpio_set_function(sck_pin, GPIO_FUNC_SPI);
        gpio_set_function(mosi_pin, GPIO_FUNC_SPI);

        gpio_init(this->cs);
        gpio_set_dir(this->cs, GPIO_OUT);

        gpio_init(this->dc);
        gpio_set_dir(this->dc, GPIO_OUT);

        gpio_init(this->rst);
        gpio_set_dir(this->rst, GPIO_OUT);

        // inits the led display
        this->reset();

        /* turning off sleep mode. */
        this->send_command(ST7735_SLPOUT);
        sleep_ms(120);

        /* 
            MADCTL -> memory data access control

            this command defines the read/write scanning 
            direction of frame memory.
        */
        this->send_command(ST7735_MADCTL);
        this->send_data(0xC8);

        /*
            COLMOD -> interface pixel format.
            defines the format of the RGB picture data.

            011 -> 12 bit / pixel
            101 -> 16 bit / pixel
            110 -> 18 bit / pixel
        */
        this->send_command(ST7735_COLMOD);
        this->send_data(0x05);

        /* display ON */
        this->send_command(ST7735_DISPON);
        sleep_ms(120);

        set_addr_window(0, 0, ST7735_WIDTH-1, ST7735_HEIGHT-1);
    }

void ST7735::set_addr_window(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1) {
    x0 += X_START;
    x1 += X_START;
    y0 += Y_START;
    y1 += Y_START;

    // column address
    this->send_command(ST7735_CASET);
    this->send_data(0x00);
    this->send_data(x0);
    this->send_data(0x00);
    this->send_data(x1);

    // row address
    this->send_command(ST7735_RASET);
    this->send_data(0x00);
    this->send_data(y0);
    this->send_data(0x00);
    this->send_data(y1);

    // write command
    this->send_command(ST7735_RAMWR);
}

/*
    draws a buffer to the display
*/
void ST7735::flush(const uint16_t* buffer){
    /*
    TODO: a better flush method. maybe a faster way to send the data correctly.

    9.12.2024
    I have managed to make a faster flush method by sending all the data once.
    The old implementation looked sth. like this:
    for(int i = 0; i < ST7735_WIDTH; i++){
        for(int j = 0; j < ST7735_HEIGHT; j++){
            this->send_data(buffer[i * ST7735_WIDTH + j] >> 8);
            this->send_data(buffer[i * ST7735_WIDTH + j]);
        }
    }
    */

    /* i left this as a reminder to limit the use of dinamically allocated memory. */
    //uint8_t* bf = new uint8_t[ST7735_WIDTH * ST7735_HEIGHT * 2];

    static uint8_t bf[ST7735_WIDTH * ST7735_HEIGHT * 2];
    uint8_t *bf_ptr = bf;

    /* populating the bf with the pixel data in the correct order. */
    for (int i = 0; i < ST7735_HEIGHT * ST7735_WIDTH; i++) {
        //bf[i * 2] = buffer[i] >> 8;
        //bf[i * 2 + 1] = buffer[i];

        *bf_ptr++ = buffer[i] >> 8;
        *bf_ptr++ = buffer[i];
    }

    this->set_cs(0);
    this->set_dc(1);

    /* sending all of the data once. */
    spi_write_blocking(spi0, bf, sizeof(bf));

    /* this is not ok because it sends the color incorrectly. */
    //spi_write_blocking(spi0, (uint8_t*)buffer, ST7735_WIDTH * ST7735_HEIGHT * 2);

    this->set_cs(1);
}

ST7735::~ST7735(){
        
}

