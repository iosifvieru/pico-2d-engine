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
    static std::unordered_map<uint8_t, bool> last_state;

    bool is_pressed_rn = !gpio_get(button_pin);

    if (is_pressed_rn && !last_state[button_pin]) {
        last_state[button_pin] = true;
        return true;
    }

    if (!is_pressed_rn) {
        last_state[button_pin] = false;
    }

    return false;
}