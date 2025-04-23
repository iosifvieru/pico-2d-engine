#ifndef _PUSH_BUTTONS_H_
#define _PUSH_BUTTONS_H_

#include "Engine/Drivers/InputDriver/Input.h"
#include "pico/stdlib.h"
#include <unordered_map>

#define debounce_ms 50

/* MY KEYS */
#define A 8
#define D 14
#define W 13
#define S 15
#define ENTER 3
#define ESC 4

class Keyboard: public Input {
private:
    Keyboard();
    ~Keyboard();

    /* instance */
    static Keyboard* instance;

public:
    void config(uint8_t button_pin);
    bool is_pressed(uint8_t button_pin);
    bool is_pressed_once(uint8_t button_pin);

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