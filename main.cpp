#include "pico/stdlib.h"

/* menu */
#include "Menu/Menu.h"

#define LOG_BENCHMARKS 1

#ifdef LOG_BENCHMARKS
#include "Tests/Benchmarks.h"
#endif

int main() { 
    stdio_init_all();
    
    #ifdef LOG_BENCHMARKS
    
    // running benchmarks
    uint64_t flush_time = flush_benchmark();
    uint64_t flush_time2 = ON2_flush_benchmark();


    while(true){
        Logger::log("ST7735_flush: %llu milisecunde", flush_time);
        Logger::log("O(N)^2 flush: %llu milisecunde.", flush_time2);
    }
    
    #endif

    #ifndef LOG_BENCHMARKS
    load_menu();
    Engine::getInstance().run(60);
    #endif
    return 0;
}