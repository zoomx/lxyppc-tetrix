#ifndef GPIO_H
#define GPIO_H
#include "stm32f10x.h"
#define  IO_SET(port, pin)  GPIO##port->BSRR = (1<<(pin))
#define  IO_RESET(port, pin)  GPIO##port->BRR = (1<<(pin))
#define  IO_READ(port, pin)   (GPIO##port->IDR & (1<<(pin)))

#define   NRF_CE_SET        IO_SET(B,2)
#define   NRF_CE_RESET      IO_RESET(B,2)
#define   NRF_CS_SET        IO_SET(A,4)
#define   NRF_CS_RESET      IO_RESET(A,4)
#define   NRF_IRQ           IO_READ(A,8)



void setup_io(void);



#endif
