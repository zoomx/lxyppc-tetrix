#ifndef GPIO_H
#define GPIO_H
#include "stm32f30x.h"
#define  IO_SET(port, pin)  GPIO##port->BSRR = (1<<(pin))
#define  IO_RESET(port, pin)  GPIO##port->BRR = (1<<(pin))
#define  IO_READ(port, pin)   (GPIO##port->IDR & (1<<(pin)))
#define  IO_TOGGLE(port, pin)    GPIO##port->ODR ^= (1<<(pin))

#define   NRF_CE_SET        IO_SET(B,11)
#define   NRF_CE_RESET      IO_RESET(B,11)
#define   NRF_CS_SET        IO_SET(B,12)
#define   NRF_CS_RESET      IO_RESET(B,12)
#define   NRF_IRQ           IO_READ(B,10)

#define   L3GD20_CS_SET     IO_SET(E,3)
#define   L3GD20_CS_RESET   IO_RESET(E,3)
#define   L3GD20_INT1       IO_READ(E,0)
#define   L3GD20_INT2       IO_READ(E,1)

#define   LSM303_DRDY       IO_READ(E,2)
#define   LSM303_INT1       IO_READ(E,4)
#define   LSM303_INT2       IO_READ(E,5)

#define   LED3_TOGGLE       IO_TOGGLE(E,9)
#define   LED4_TOGGLE       IO_TOGGLE(E,8)
#define   LED5_TOGGLE       IO_TOGGLE(E,10)
#define   LED6_TOGGLE       IO_TOGGLE(E,15)
#define   LED7_TOGGLE       IO_TOGGLE(E,11)
#define   LED8_TOGGLE       IO_TOGGLE(E,14)
#define   LED9_TOGGLE       IO_TOGGLE(E,12)
#define   LED10_TOGGLE      IO_TOGGLE(E,13)

#define   LED3_OFF       IO_RESET(E,9)
#define   LED4_OFF       IO_RESET(E,8)
#define   LED5_OFF       IO_RESET(E,10)
#define   LED6_OFF       IO_RESET(E,15)
#define   LED7_OFF       IO_RESET(E,11)
#define   LED8_OFF       IO_RESET(E,14)
#define   LED9_OFF       IO_RESET(E,12)
#define   LED10_OFF      IO_RESET(E,13)

void setup_io_l3gd20(void);
void setup_l3gd20_io_interrupt(void);
void enable_l3gd20_interrupt(void);
void disable_l3gd20_interrupt(void);
void setup_io_lsm303dlhc(void);
void setup_io_nrf24l01(void);
void setup_io_leds(void);
void setup_io_usb(void);

#endif
