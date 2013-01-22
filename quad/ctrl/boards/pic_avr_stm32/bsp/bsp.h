#ifndef BSP_H
#define BSP_H
#include "gpio.h"
#include "spi.h"
#include "i2c.h"


#define NRF_TRANSFER_BYTE(x)    spi2_transfer_byte(x)

#define NRF_INIT()     \
    do{\
        setup_io_nrf24l01();\
        spi2_init();\
    }while(0)

#define MPU6050_INIT()   \
    do{\
        setup_io_mpu6050();\
        i2c1_init();\
    }while(0)

#define HMC5883_INIT()   \
    do{\
        setup_io_hmc5883();\
        i2c1_init();\
    }while(0)    
    
#define  MPU6050_Write_Byte(devAddr, regAddr, byte)  \
    do{\
        uint8_t b = byte;\
        i2c1_write(devAddr, regAddr, &b, 1);\
    }while(0)
    
#define  MPU6050_Write_Buffer(devAddr, regAddr, buffer, len)  \
    do{\
        i2c1_write(devAddr, regAddr, buffer, len);\
    }while(0)
    
#define MPU6050_Read_Buffer(devAddr, regAddr, buffer, len)  \
    do{\
        i2c1_read(devAddr, regAddr, buffer, len);\
    }while(0)


#define HMC5883_Write_Byte(devAddr, regAddr, byte)  MPU6050_Write_Byte(devAddr, regAddr, byte)
#define HMC5883_Write_Buffer(devAddr, regAddr, buffer, len)  MPU6050_Write_Buffer(devAddr, regAddr, buffer, len)
#define HMC5883_Read_Buffer(devAddr, regAddr, buffer, len)  MPU6050_Read_Buffer(devAddr, regAddr, buffer, len)
    
#define BMP085_Write_Byte(devAddr, regAddr, byte)  MPU6050_Write_Byte(devAddr, regAddr, byte)
#define BMP085_Write_Buffer(devAddr, regAddr, buffer, len)  MPU6050_Write_Buffer(devAddr, regAddr, buffer, len)
#define BMP085_Read_Buffer(devAddr, regAddr, buffer, len)  MPU6050_Read_Buffer(devAddr, regAddr, buffer, len)


#define MPU6050_IO_INT_SETUP()   \
    do{ setup_mpu6050_io_interrupt(); }while(0)
    
#define MPU6050_DI() \
    do{disable_mpu6050_interrupt();}while(0)
    
#define MPU6050_EI() \
    do{enable_mpu6050_interrupt();}while(0)

#define  GYRO_INIT()            MPU6050_gyro_init()
#define  ACC_INIT()             MPU6050_acc_init()
#define  MAG_INIT()             HMC5883_mag_init()
#define  PRESSURE_INIT()        BMP085_pressure_init()

#define  GYRO_DATA_READY()      (!(MPU6050_INT))

void delay_ms(uint32_t ms);
void delay_us(uint32_t usec);
uint32_t get_tick_count(void);
uint32_t current_us(void);
void setup_systick(void);
void enable_tick_count(void);
#endif
