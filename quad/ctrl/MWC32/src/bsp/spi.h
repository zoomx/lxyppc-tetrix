#ifndef SPI_H
#define SPI_H

#include "stm32f10x.h"
#include "stdint.h"
void spi_init(void);
uint8_t spi_transfer_byte(uint8_t byte);

#endif
