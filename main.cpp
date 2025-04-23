#include "pico/stdlib.h"

/* menu */
#include "Menu/Menu.h"

int main() { 
    stdio_init_all();
    
    load_menu();
    Engine::getInstance().run(60);
    return 0;
}