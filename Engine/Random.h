#ifndef _RANDOM_H_
#define _RANDOM_H_

#include "pico/stdlib.h"
#include "hardware/regs/rosc.h"
#include "hardware/regs/addressmap.h"

/*
random number generator. found here ->
https://forums.raspberrypi.com/viewtopic.php?t=302960
*/

uint32_t rnd(void){
    int k, random=0;
    volatile uint32_t *rnd_reg=(uint32_t *)(ROSC_BASE + ROSC_RANDOMBIT_OFFSET);
    
    for(k=0;k<32;k++){
    
    random = random << 1;
    random = random + (0x00000001 & (*rnd_reg));

    }
    return random;
}

#endif