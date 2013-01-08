#ifndef BSP_H
#define BSP_H
#include "gpio.h"
#include "spi.h"
#include "i2c.h"


#define NRF_TRANSFER_BYTE(x)    spi_transfer_byte(x)

#define NRF_INIT()     \
    do{\
        setup_io();\
        spi_init();\
    }while(0)

#define LSM303DLHC_INIT()   \
    do{\
        setup_io_lsm303dlhc();\
        i2c1_init();\
    }while(0)
    
#define  LSM303DLHC_Write_Byte(devAddr, regAddr, byte)  \
    do{\
        uint8_t b = byte;\
        i2c1_write(devAddr, regAddr, &b, 1);\
    }while(0)
    
#define  LSM303DLHC_Write_Buffer(devAddr, regAddr, buffer, len)  \
    do{\
        i2c1_write(devAddr, (len>1? regAddr|0x80 : regAddr), buffer, len);\
    }while(0)
    
#define LSM303DLHC_Read_Buffer(devAddr, regAddr, buffer, len)  \
    do{\
        i2c1_read(devAddr, (len>1? regAddr|0x80 : regAddr), buffer, len);\
    }while(0)

void delay_ms(uint32_t ms);
void delay_us(uint32_t usec);



#endif
