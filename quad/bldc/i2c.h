#ifndef I2C_H
#define I2C_H
#include "stdint.h"

#define     I2C_DevStructure    I2C1_DevStructure


#define OWN_ADDRESS             get_i2c_addr()//0x74
#define I2C_ADDR_PREFIX         0x50
#define I2C_TIMING              0x00731012 

void init_i2c(void);
uint8_t get_i2c_addr(void);

#endif
