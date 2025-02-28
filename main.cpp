#include "pico/stdlib.h"
//#include "Games/pong/Pong.h"

#include "Games/Test.h"

int main() { 
    stdio_init_all();
    
    Test t;
    t.run();

    return 0;
}