#ifndef SIMPLE_IO_H
#define SIMPLE_IO_H
#include "stdint.h"

// init i2c address config
void init_addr_config(void);
// init led 
void init_led(void);

// get current i2c address
uint8_t get_i2c_addr(void);

// set led bright, valid value [0~100]
void adj_led(uint8_t led1, uint8_t led2);


#endif
