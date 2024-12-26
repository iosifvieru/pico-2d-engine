#include "pico/stdlib.h"
#include "Games/pong/Pong.h"

int main() { 
    stdio_init_all();

    Pong game;
    game.loop();
    
    return 0;
}