# Bachelor's Project: 2D Game Engine for Embedded Systems

This project focuses on developing a 2D Game engine for low-cost embedded systems.
My implementation is based on RP2040 microcontroller found on boards like Raspberry Pi Pico and Marble Pico.

### **RP2040**
RP2040 is a 32-bit dual ARM Cortex-M0+ microcontroller produced by Raspberry Pi Ltd.
This project is written in C++ but the microcontroller can also be programmed in MicroPython, Assembly, Rust, Go.

- Key features:
    - Dual ARM Cortex-M0+ cores 133Mhz.
    - 264 KB SRAM 
    - 30 GPIO Pins
    - Two UART controllers
    - Two SPI controllers
    - 16 PWM Channels.

The RP2040 Datasheet can be found [here](https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf).

### **ST7735**
ST7735 is a TFT LCD Display that I have used in my implementation. It supports 18, 16 and 12 bit colors and features 128x128 resolution.

- Key features:
    - TFT LCD display type.
    - 128x128 pixel resolution (there are also 128x160 pixel resolution variants)
    - 18, 16 or 12-bit color depth. My implementation uses 16-bit color depth.
    - SPI communication.
    - it operates at 3.3V but it can also be used at 5V.
    - backlight

The ST7735 Datasheet can be found [here](https://www.displayfuture.com/Display/datasheet/controller/ST7735.pdf).