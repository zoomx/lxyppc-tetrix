#ifndef GPIO_H
#define GPIO_H
#include "NUC1xx.h"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvSPI.h"
//#define  IO_SET(port, pin)  GPIO##port->BSRR = (1<<(pin))
//#define  IO_RESET(port, pin)  GPIO##port->BRR = (1<<(pin))
//#define  IO_READ(port, pin)   (GPIO##port->IDR & (1<<(pin)))

#define   NRF_CE_SET        DrvGPIO_SetBit(E_GPA,14)
#define   NRF_CE_RESET      DrvGPIO_ClrBit(E_GPA,14)
#define   NRF_CS_SET        DrvSPI_ClrSS(eDRVSPI_PORT0, eDRVSPI_SS0)
#define   NRF_CS_RESET      DrvSPI_SetSS(eDRVSPI_PORT0, eDRVSPI_SS0)
#define   NRF_IRQ           DrvGPIO_GetBit(E_GPB,14)



void setup_io(void);



#endif
