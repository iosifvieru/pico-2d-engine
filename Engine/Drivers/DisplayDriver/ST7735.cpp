// Iosif Vieru

#include "ST7735.h"
#include "pico/stdlib.h"
#include "Engine/Utils/Utils.h"
#include "hardware/spi.h"

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

        spi_init(spi0, 10000* 1000);
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

        this->send_command(0x11);
        sleep_ms(120);

        this->send_command(0x36);
        this->send_data(0x08);

        this->send_command(0x3A);
        this->send_data(0x05);

        this->send_command(0x29);
        sleep_ms(120);

    }

void ST7735::set_addr_window(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1){
    this->send_command(ST7735_CASET);
    this->send_data(0x00);

    this->send_data(x0);
    this->send_data(0x00);

    this->send_data(x1);

    this->send_command(ST7735_RASET);
    this->send_data(0x00);

    this->send_data(y0);
    this->send_data(0x00);
    this->send_data(y1);

    this->send_command(ST7735_RAMWR);
}

/*
    draws a buffer to the display
*/
void ST7735::flush(const uint16_t* buffer){
    set_addr_window(0, 0, 0 + ST7735_WIDTH - 1, 0 + ST7735_HEIGHT - 1);
    //this->send_command(ST7735_RAMWR);
    for(int i = 0; i < ST7735_HEIGHT; i++){
        for(int j = 0; j < ST7735_WIDTH; j++){
            this->send_data(buffer[i * ST7735_WIDTH + j] >> 8);
            this->send_data(buffer[i * ST7735_WIDTH + j]);
        }
    }
}

ST7735::~ST7735(){
        
}

