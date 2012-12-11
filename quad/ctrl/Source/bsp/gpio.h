#ifndef GPIO_H
#define GPIO_H

#define  IO_SET(port, pin)  GPIO##port->BSRR = (1<<(pin))
#define  IO_RESET(port, pin)  GPIO##port->BRR = (1<<(pin))



void setup_io(void);



#endif
