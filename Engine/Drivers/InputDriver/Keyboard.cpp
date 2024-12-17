#include "Engine/Drivers/InputDriver/Keyboard.h"

#include "string.h"
#include "pico/stdlib.h"

Keyboard* Keyboard::instance = nullptr;


Keyboard::Keyboard(){
    //
}

Keyboard::~Keyboard(){
    //
}


void Keyboard::config(uint8_t button_pin){
    gpio_init(button_pin);
    gpio_set_dir(button_pin, GPIO_IN);
    gpio_pull_up(button_pin);
}

bool Keyboard::is_pressed(uint8_t button_pin) {
    uint32_t currentTime = time_us_32() / 1000;

    if (!gpio_get(button_pin)) {
        if (lastPressTimes.find(button_pin) == lastPressTimes.end() || 
            (currentTime - lastPressTimes[button_pin]) > debounce_ms) {
            
            lastPressTimes[button_pin] = currentTime;
            return true;
        }
    }

   //return (!gpio_get(button_pin));
   return false;
}