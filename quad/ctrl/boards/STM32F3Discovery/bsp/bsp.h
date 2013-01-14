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


#define L3GD20_INIT()   \
    do{\
        setup_io_l3gd20();\
        spi1_init();\
    }while(0)

#define L3GD20_XFER_BYTE(x)   spi1_transfer_byte(x)
    
#define L3GD20_CS_LOW()       L3GD20_CS_RESET
#define L3GD20_CS_HIGH()      L3GD20_CS_SET

#define  GYRO_INIT()            L3GD20_gyro_init()
#define  ACC_INIT()             LSM303DLHC_acc_init()
#define  MAG_INIT()             LSM303DLHC_mag_init()

void delay_ms(uint32_t ms);
void delay_us(uint32_t usec);
uint32_t get_tick_count(void);
void setup_systick(void);
void enable_tick_count(void);
#endif
