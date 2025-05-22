#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <stdarg.h>
#include <cstdio>

#define LOG 1

class Logger {
public:
    /*
    sends a string to stdout.
    also adds \n to the end of string.1
    */
    static void log(const char* msg, ...) {
        #if LOG == 1
        va_list args;
        va_start(args, msg);
        vprintf(msg, args);
        va_end(args);
        printf("\n");
        #endif
    }
};

#endif