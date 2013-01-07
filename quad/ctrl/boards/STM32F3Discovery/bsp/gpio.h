#ifndef GPIO_H
#define GPIO_H
#include "stm32f30x.h"
#define  IO_SET(port, pin)  GPIO##port->BSRR = (1<<(pin))
#define  IO_RESET(port, pin)  GPIO##port->BRR = (1<<(pin))
#define  IO_READ(port, pin)   (GPIO##port->IDR & (1<<(pin)))

#define   NRF_CE_SET        IO_SET(B,2)
#define   NRF_CE_RESET      IO_RESET(B,2)
#define   NRF_CS_SET        IO_SET(A,4)
#define   NRF_CS_RESET      IO_RESET(A,4)
#define   NRF_IRQ           IO_READ(A,8)

#define   L3GD20_CS_SET     IO_SET(E,3)
#define   L3GD20_CS_RESET   IO_RESET(E,3)
#define   L3GD20_INT1       IO_READ(E,0)
#define   L3GD20_INT2       IO_READ(E,1)


void setup_io(void);



#endif
