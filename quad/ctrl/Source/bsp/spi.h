#ifndef SPI_H
#define SPI_H

#include "stdint.h"
void spi_init(void);
uint8_t spi_tranfer_byte(uint8_t byte);

#endif
