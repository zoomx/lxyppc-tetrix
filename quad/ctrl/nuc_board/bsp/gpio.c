#include "gpio.h"
#include "Driver\DrvGPIO.h"


void EINT0Callback(void)
{
    // IRQ happen
    static uint8_t cnt = 0;
    cnt++;
    if(cnt&1){
        DrvGPIO_SetBit(E_GPA,3);
    }else{
        DrvGPIO_ClrBit(E_GPA,3);
    }
    nrf_irq_handler();
}

void setup_io(void)
{
    DrvGPIO_Open(E_GPB, 14, E_IO_INPUT);
    DrvGPIO_EnableEINT0(E_IO_FALLING, E_MODE_EDGE, EINT0Callback);
    
    DrvGPIO_Open(E_GPA, 14, E_IO_OUTPUT);
    DrvGPIO_Open(E_GPA, 15, E_IO_OUTPUT);
}





