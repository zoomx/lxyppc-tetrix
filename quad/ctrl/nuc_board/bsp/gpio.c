#include "gpio.h"
#include "Driver\DrvGPIO.h"


void EINT0Callback(void)
{
    // IRQ happen
}

void setup_io(void)
{
    DrvGPIO_Open(E_GPB, 14, E_IO_INPUT);
    DrvGPIO_EnableEINT0(E_IO_BOTH_EDGE, E_MODE_EDGE, EINT0Callback);
    
    DrvGPIO_Open(E_GPA, 14, E_IO_OUTPUT);
}





