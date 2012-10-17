#ifndef PPM_H
#define PPM_H

#include "stdint.h"


// idle time is 500 us
#define  PPM_IDLE                    500ul   /* 500 us*/

// valid duty is 0.5ms ~ 2.5ms, plus idle time,
// so max period should less than 3ms, 3000us
#define  PPM_MAX_PERIOD             4000ul  /* 4000 us */


void init_ppm(void);

uint32_t get_ppm(void* buf, uint32_t cnt);

#endif
