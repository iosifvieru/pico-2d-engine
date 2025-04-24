// Iosif Vieru

#ifndef ST7735_H_
#define ST7735_H_

#include "pico/stdlib.h"
#include "Display.h"

/* SPI defines */
#define SCK 18
#define MOSI 19
#define CS 17
#define RST 21
#define DC 20

/* 
    ST7735 address defines 
    via datasheet -> https://www.displayfuture.com/Display/datasheet/controller/ST7735.pdf
*/
#define ST7735_CASET 0x2A
#define ST7735_RASET 0x2B
#define ST7735_RAMWR 0x2C
#define ST7735_SLPOUT 0x11
#define ST7735_MADCTL 0x36
#define ST7735_COLMOD 0x3A
#define ST7735_DISPON 0x29

#define X_START 2
#define Y_START 1

#define ST7735_WIDTH 129
#define ST7735_HEIGHT 130

/*
ST7735 is a singleton object that implements the "Display" interface.
*/
class ST7735: public Display {
private:
    /* pins for SPI communication */
    uint8_t sck_pin;
    uint8_t mosi_pin;
    uint8_t cs;
    uint8_t rst;
    uint8_t dc;

    inline void set_mosi(bool level);
    inline void set_sck(bool level);
    inline void set_cs(bool level);
    inline void set_dc(bool level);
    inline void set_rst(bool level);

    /* sends a byte using SPI communication to display */
    inline void send_byte(uint8_t byte);

    /* sends a command to display */
    void send_command(uint8_t command);

    /* sends data to display */
    void send_data(uint8_t data);

    void set_addr_window(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1);

    /* sends a 16 bit RGB565 color to display */
    inline void send_color(uint16_t color);

    /* resets the display */
    void reset();

    /*
    private constructor.
    ST7735 - singleton implementation
    */
    ST7735(
        uint8_t sck_pin,
        uint8_t mosi_pin,
        uint8_t cs,
        uint8_t rst,
        uint8_t dc
    );

    /* private destructor */
    ~ST7735();

    /* instance */
    static ST7735* instance;
public:

    /* returns the ST7735 instance */
    static ST7735& getInstance(){
        if(instance == nullptr){
            instance = new ST7735(SCK, MOSI, CS, RST, DC);
        }

        return *instance;
    }

    /* overloading the copy constructor. */
    ST7735(const ST7735&) = delete;

    /* overloading the assignment operator */
    ST7735& operator=(const ST7735&) = delete;

    /*
        Display interface implementation.
    */
    void flush(const uint16_t* buffer) override;

    /* returns the height of the ST7735 display. */
    uint16_t get_height() override{
        return ST7735_HEIGHT;
    }

    /* returns the width of the ST7735 display. */
    uint16_t get_width() override {
        return ST7735_WIDTH;
    }
};

#endif