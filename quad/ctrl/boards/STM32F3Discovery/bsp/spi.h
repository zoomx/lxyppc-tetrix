#ifndef SPI_H
#define SPI_H

#include "stm32f30x.h"
#include "stdint.h"
void spi1_init(void);
uint8_t spi1_transfer_byte(uint8_t byte);

void spi2_init(void);
uint8_t spi2_transfer_byte(uint8_t byte);

#endif
