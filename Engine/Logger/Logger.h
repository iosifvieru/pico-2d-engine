#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <stdarg.h>
#include <cstdio>

//#define _LOG_ 1

class Logger {
public:

    /*
    sends a string to stdout.
    also adds \n to the end of string.
    */
    static void log(const char* msg, ...) {
        #ifdef _LOG_
        va_list args;
        va_start(args, msg);
        vprintf(msg, args);
        va_end(args);
        printf("\n");
        #endif
    }
};

#endif