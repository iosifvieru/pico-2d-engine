#include "pico/stdlib.h"

/* menu */
#include "Menu/Menu.h"

// #define LOG_BENCHMARKS 1

#ifdef LOG_BENCHMARKS
#include "Tests/Benchmarks.h"
#endif

int main() { 
    stdio_init_all();
    
    #ifdef LOG_BENCHMARKS
    
    // running benchmarks
    uint64_t flush_time = flush_benchmark();
    uint64_t flush_time2 = ON2_flush_benchmark();
    uint64_t render_time_5e = render_entity_benchmark(5);
    uint64_t render_time_10e = render_entity_benchmark(10);
    uint64_t render_time_30e = render_entity_benchmark(30);
    uint64_t render_time_100e = render_entity_benchmark(100);
    uint64_t render_time_200e = render_entity_benchmark(200);
    uint64_t render_time_300e = render_entity_benchmark(300);
    uint64_t render_time_400e = render_entity_benchmark(400);
    uint64_t render_time_500e = render_entity_benchmark(500);
    uint64_t render_time_1000e = render_entity_benchmark(1000);

    while(true){
        Logger::log("ST7735_flush: %llu milisecunde", flush_time);
        Logger::log("O(N)^2 flush: %llu milisecunde.", flush_time2);
        Logger::log("render_time with 5 entities: %llu miliseconds.", render_time_5e);
        Logger::log("render_time with 10 entities: %llu miliseconds.", render_time_10e);
        Logger::log("render_time with 30 entities: %llu miliseconds.", render_time_30e);
        Logger::log("render_time with 100 entities: %llu miliseconds.", render_time_100e);
        Logger::log("render_time with 200 entities: %llu miliseconds.", render_time_200e);
        Logger::log("render_time with 300 entities: %llu miliseconds.", render_time_300e);
        Logger::log("render_time with 400 entities: %llu miliseconds.", render_time_400e);
        Logger::log("render_time with 500 entities: %llu miliseconds", render_time_500e);
        Logger::log("render_time with 1000 entities: %llu miliseconds.", render_time_1000e);
    }
    
    #endif

    #ifndef LOG_BENCHMARKS
    load_menu();
    Engine::getInstance().run(60);
    #endif
    return 0;
}