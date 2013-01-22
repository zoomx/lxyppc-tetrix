#ifndef GPIO_H
#define GPIO_H
#include "stm32f10x.h"
#define  IO_SET(port, pin)  GPIO##port->BSRR = (1<<(pin))
#define  IO_RESET(port, pin)  GPIO##port->BRR = (1<<(pin))
#define  IO_READ(port, pin)   (GPIO##port->IDR & (1<<(pin)))
#define  IO_TOGGLE(port, pin)    GPIO##port->ODR ^= (1<<(pin))

#define   NRF_CE_SET        IO_SET(B,2)
#define   NRF_CE_RESET      IO_RESET(B,2)
#define   NRF_CS_SET        IO_SET(A,4)
#define   NRF_CS_RESET      IO_RESET(A,4)
#define   NRF_IRQ           IO_READ(B,0)

#define   MPU6050_INT       IO_READ(A,12)

#define   HMC5883_DRDY      IO_READ(B,3)
#define   BMP085_EOC        IO_READ(A,8)
#define   BMP085_XCLR_SET   IO_SET(A,11)
#define   BMP085_XCLR_RESET IO_RESET(A,11)

#define   LED1_TOGGLE       IO_TOGGLE(B,11)
#define   LED2_TOGGLE       IO_TOGGLE(B,10)

#define   LED1_OFF       IO_SET(B,11)
#define   LED2_OFF       IO_SET(B,10)
#define   LED1_ON        IO_RESET(B,11)
#define   LED2_ON        IO_RESET(B,10)


void setup_io_mpu6050(void);
void setup_mpu6050_io_interrupt(void);
void enable_mpu6050_interrupt(void);
void disable_mpu6050_interrupt(void);
void setup_io_hmc5883(void);
void setup_io_bmp085(void);
void setup_io_nrf24l01(void);
void setup_io_leds(void);
void setup_io_usb(void);

#endif
