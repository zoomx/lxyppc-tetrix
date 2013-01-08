#ifndef I2C_H
#define I2C_H

#include "stm32f30x.h"
#include "stdint.h"

void i2c1_init(void);
uint8_t i2c1_write(uint8_t DeviceAddr, uint8_t RegAddr, const uint8_t* pBuffer, uint16_t len);
uint8_t i2c1_read(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t* pBuffer, uint16_t len);
#endif
