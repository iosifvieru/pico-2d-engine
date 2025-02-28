#ifndef _PUSH_BUTTONS_H_
#define _PUSH_BUTTONS_H_

#include "Engine/Drivers/InputDriver/Input.h"
#include "pico/stdlib.h"
#include <unordered_map>

#define debounce_ms 50

class Keyboard: public Input {
private:
    Keyboard();
    ~Keyboard();

    /* instance */
    static Keyboard* instance;

    std::unordered_map<uint8_t, uint32_t> lastPressTimes;

public:
    void config(uint8_t button_pin);
    bool is_pressed(uint8_t button_pin);

    /* returns the Keyboard instance */
    static Keyboard& getInstance(){
        if(instance == nullptr){
            instance = new Keyboard();
        }

        return *instance;
    }

    /* overloading the copy constructor. */
    Keyboard(const Keyboard&) = delete;

    /* overloading the assignment operator */
    Keyboard& operator=(const Keyboard&) = delete;
};

#endif