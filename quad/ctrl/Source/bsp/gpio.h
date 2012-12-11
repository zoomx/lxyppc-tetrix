#ifndef GPIO_H
#define GPIO_H
#include "stm32f10x.h"
#define  IO_SET(port, pin)  GPIO##port->BSRR = (1<<(pin))
#define  IO_RESET(port, pin)  GPIO##port->BRR = (1<<(pin))
#define  IO_READ(port, pin)   (GPIO##port->IDR & (1<<(pin)))

#define   NRF_CE_SET        IO_SET(A,3)
#define   NRF_CE_RESET      IO_RESET(A,3)
#define   NRF_CS_SET        IO_SET(A,4)
#define   NRF_CS_RESET      IO_RESET(A,4)
#define   NRF_IRQ           IO_READ(C,4)



void setup_io(void);



#endif
