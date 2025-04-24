#ifndef _RANDOM_H_
#define _RANDOM_H_

#include "pico/stdlib.h"
#include "hardware/regs/rosc.h"
#include "hardware/regs/addressmap.h"

/*
random number generator. found here ->
https://forums.raspberrypi.com/viewtopic.php?t=302960
*/

uint32_t rnd(void);

#endif