#ifndef BSP_H
#define BSP_H

#include "gpio.h"
#include "spi.h"


#define NRF_TRANSFER_BYTE(x)    spi_transfer_byte(x)

#define NRF_INIT()     \
    do{\
        setup_io();\
        spi_init();\
    }while(0)

void delay_ms(uint32_t ms);
void delay_us(uint32_t usec);

#endif
