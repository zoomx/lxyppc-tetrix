#ifndef GPIO_H
#define GPIO_H

//#define  IO_SET(port, pin)    GPIO##port->BSRR = (1<<(pin))
//#define  IO_RESET(port, pin)  GPIO##port->BRR = (1<<(pin))
//#define  IO_READ(port, pin)   (GPIO##port->IDR & (1<<(pin)))

//#define   NRF_CE_SET        IO_SET(A,3)
//#define   NRF_CE_RESET      IO_RESET(A,3)
//#define   NRF_CS_SET        IO_SET(A,4)
//#define   NRF_CS_RESET      IO_RESET(A,4)
//#define   NRF_IRQ           IO_READ(C,4)
#include "stdint.h"
#define   NRF_CE_SET        nrf_ce_set()
#define   NRF_CE_RESET      nrf_ce_reset()
#define   NRF_CS_SET        nrf_cs_set()
#define   NRF_CS_RESET      nrf_cs_reset()
#define   NRF_IRQ           nrf_irq()

void setup_io(void);
void nrf_ce_set(void);
void nrf_ce_reset(void);
void nrf_cs_set(void);
void nrf_cs_reset(void);
uint32_t nrf_irq(void);

#endif
