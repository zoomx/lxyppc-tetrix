/*
  June 2012

  BaseFlightPlus Rev -

  An Open Source STM32 Based Multicopter

  Includes code and/or ideas from:

  1)AeroQuad
  2)BaseFlight
  3)CH Robotics
  4)MultiWii
  5)S.O.H. Madgwick

  Designed to run on Naze32 Flight Control Board

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "bsp.h"

///////////////////////////////////////////////////////////////////////////////
// MPU3050 Defines and Variables
///////////////////////////////////////////////////////////////////////////////

// Address

#include "mpu6050.h"
#include "mpu60x0.h"

// Bits

#define FS_SEL_2000_DPS       0x18

#define ACTL                  0x00
#define OPEN                  0x00
#define LATCH_INT_EN          0x20
#define INT_ANYRD_2CLEAR      0x10
#define RAW_RDY_EN            0x01

#define H_RESET               0x80
#define INTERNAL_OSC          0x00
#define PLL_WITH_X            0x01
#define PLL_WITH_Y            0x02
#define PLL_WITH_Z            0x03
#define PLL_WITH_EXT_32K      0x04
#define PLL_WITH_EXT_19M      0x05
#define STOP_CLK              0x07

///////////////////////////////////////

#define LOW_PASS_FILTER 0x18    // 256 Hz Low pass filter, 8 kHz internal sample rate
//#define LOW_PASS_FILTER 0x19  // 188 Hz Low pass filter, 1 kHz internal sample rate
//#define LOW_PASS_FILTER 0x1A  //  98 Hz Low pass filter, 1 kHz internal sample rate
//#define LOW_PASS_FILTER 0x1B  //  42 Hz Low pass filter, 1 kHz internal sample rate
//#define LOW_PASS_FILTER 0x1C  //  20 Hz Low pass filter, 1 kHz internal sample rate
//#define LOW_PASS_FILTER 0x1D  //  10 Hz Low pass filter, 1 kHz internal sample rate
//#define LOW_PASS_FILTER 0x1E  //   5 Hz Low pass filter, 1 kHz internal sample rate

#if (LOW_PASS_FILTER == 0x18)
#define SAMPLE_RATE_DIVISOR 0x07        // 1000 Hz = 8000/(7 + 1)
#else
#define SAMPLE_RATE_DIVISOR 0x00        // 1000 Hz = 1000/(0 + 1)
#endif

#define swap_(x,y)  do{uint8_t t =x; x = y; y = t;}while(0)

///////////////////////////////////////////////////////////////////////////////
// Read Gyro
///////////////////////////////////////////////////////////////////////////////
void MPU6050_gyro_read(int16_t * data)
{
    uint8_t* buf = (uint8_t*) data;
    MPU6050_Read_Buffer(MPU6050_ADDRESS, MPU60X0_REG_GYRO_XOUT_H, (uint8_t*)data, 6);    
    // setting is MSB, need to swap bytes order
    swap_(buf[0],buf[1]);
    swap_(buf[2],buf[3]);
    swap_(buf[4],buf[5]);
}

void MPU6050_temp_read(int16_t * data)
{
    uint8_t* buf = (uint8_t*) data;
    MPU6050_Read_Buffer(MPU6050_ADDRESS, MPU60X0_REG_TEMP_OUT_H, (uint8_t*)data, 2);    
    // setting is MSB, need to swap bytes order
    swap_(buf[0],buf[1]);
}

///////////////////////////////////////////////////////////////////////////////
// Compute Gyro Temperature Compensation Bias
///////////////////////////////////////////////////////////////////////////////

void MPU6050_compute_gyro_TC_bias(float *bias, int16_t temp)
{
    float gyroTemperature = (float) (temp + 13200) / 280.0f + 35.0f;

    bias[0] = gyroTemperature*0.00001f;
    bias[1] = gyroTemperature*0.00002f;
    bias[2] = gyroTemperature*0.00003f;
    //bias[0] = sensorConfig.gyroTCBiasSlope[0] * gyroTemperature;// + sensorConfig.gyroTCBiasIntercept[ROLL];
    //bias[0] = sensorConfig.gyroTCBiasSlope[0] * gyroTemperature;// + sensorConfig.gyroTCBiasIntercept[PITCH];
    //bias[0] = sensorConfig.gyroTCBiasSlope[0] * gyroTemperature;// + sensorConfig.gyroTCBiasIntercept[YAW];
}

void MPU6050_compute_gyro_runtime_bias(float* bias, uint32_t samples)
{
    int16_t gyro[3];
    uint32_t i;
    int32_t sum[3] = {0};
    MPU6050_DI();
    for(i=0;i<samples;i++){
        while(!GYRO_DATA_READY()); // wait data ready
        MPU6050_gyro_read(gyro);
        sum[0] += gyro[0];
        sum[1] += gyro[1];
        sum[2] += gyro[2];
    }
    bias[0] = (float)sum[0]/(float)samples;
    bias[1] = (float)sum[1]/(float)samples;
    bias[2] = (float)sum[2]/(float)samples;
    MPU6050_EI();
}

///////////////////////////////////////////////////////////////////////////////
// Gyro Initialization
///////////////////////////////////////////////////////////////////////////////
void MPU6050_gyro_init(void)
{
    MPU6050_INIT();
    MPU6050_Write_Byte(MPU6050_ADDRESS, MPU60X0_REG_PWR_MGMT_1, H_RESET);
    delay_ms(5);
    MPU6050_Write_Byte(MPU6050_ADDRESS, MPU60X0_REG_PWR_MGMT_1, PLL_WITH_Z);
    MPU6050_Write_Byte(MPU6050_ADDRESS, MPU60X0_REG_CONFIG, 0); //EXT_SYNC_SET 0 (disable input pin for data sync) ; default DLPF_CFG = 0 => ACC bandwidth = 260Hz  GYRO bandwidth = 256Hz)
    MPU6050_Write_Byte(MPU6050_ADDRESS, MPU60X0_REG_GYRO_CONFIG, 0x18); //GYRO_CONFIG   -- FS_SEL = 3: Full scale set to 2000 deg/sec
    
    //MPU6050_Write_Byte(MPU6050_ADDRESS, MPU60X0_REG_INT_PIN_CFG, 0x02); //INT_PIN_CFG   -- INT_LEVEL=0 ; INT_OPEN=0 ; LATCH_INT_EN=0 ; INT_RD_CLEAR=0 ; FSYNC_INT_LEVEL=0 ; FSYNC_INT_EN=0 ; I2C_BYPASS_EN=1 ; CLKOUT_EN=0
    delay_ms(100);
    
    MPU6050_IO_INT_SETUP();
    //computeGyroRTBias();
}

///////////////////////////////////////////////////////////////////////////////
// Read Accel
///////////////////////////////////////////////////////////////////////////////

void MPU6050_acc_read(int16_t* data)
{
    uint8_t* buf = (uint8_t*)data;

    MPU6050_Read_Buffer(MPU6050_ADDRESS, MPU60X0_REG_ACCEL_XOUT_H, buf, 6);
    
    swap_(buf[0],buf[1]);
    swap_(buf[2],buf[3]);
    swap_(buf[4],buf[5]);
}

///////////////////////////////////////////////////////////////////////////////
// Accel Initialization
///////////////////////////////////////////////////////////////////////////////

void MPU6050_acc_init(void)
{
    MPU6050_INIT();
    MPU6050_Write_Byte(MPU6050_ADDRESS, MPU60X0_REG_ACCEL_CONFIG, 0x1c); //ACCEL_CONFIG  -- AFS_SEL=2 (Full Scale = +/-8G)  ; ACCELL_HPF=0   //note something is wrong in the spec.

#if defined(MPU6050_I2C_AUX_MASTER)
    //at this stage, the MAG is configured via the original MAG init function in I2C bypass mode
    //now we configure MPU as a I2C Master device to handle the MAG via the I2C AUX port (done here for HMC5883)
    MPU6050_Write_Byte(MPU6050_ADDRESS, 0x6A, 0b00100000);       //USER_CTRL     -- DMP_EN=0 ; FIFO_EN=0 ; I2C_MST_EN=1 (I2C master mode) ; I2C_IF_DIS=0 ; FIFO_RESET=0 ; I2C_MST_RESET=0 ; SIG_COND_RESET=0
    MPU6050_Write_Byte(MPU6050_ADDRESS, 0x37, 0x00);             //INT_PIN_CFG   -- INT_LEVEL=0 ; INT_OPEN=0 ; LATCH_INT_EN=0 ; INT_RD_CLEAR=0 ; FSYNC_INT_LEVEL=0 ; FSYNC_INT_EN=0 ; I2C_BYPASS_EN=0 ; CLKOUT_EN=0
    MPU6050_Write_Byte(MPU6050_ADDRESS, 0x24, 0x0D);             //I2C_MST_CTRL  -- MULT_MST_EN=0 ; WAIT_FOR_ES=0 ; SLV_3_FIFO_EN=0 ; I2C_MST_P_NSR=0 ; I2C_MST_CLK=13 (I2C slave speed bus = 400kHz)
    MPU6050_Write_Byte(MPU6050_ADDRESS, 0x25, 0x80|MAG_ADDRESS);//I2C_SLV0_ADDR -- I2C_SLV4_RW=1 (read operation) ; I2C_SLV4_ADDR=MAG_ADDRESS
    MPU6050_Write_Byte(MPU6050_ADDRESS, 0x26, MAG_DATA_REGISTER);//I2C_SLV0_REG  -- 6 data bytes of MAG are stored in 6 registers. First register address is MAG_DATA_REGISTER
    MPU6050_Write_Byte(MPU6050_ADDRESS, 0x27, 0x86);             //I2C_SLV0_CTRL -- I2C_SLV0_EN=1 ; I2C_SLV0_BYTE_SW=0 ; I2C_SLV0_REG_DIS=0 ; I2C_SLV0_GRP=0 ; I2C_SLV0_LEN=3 (3x2 bytes)
#endif
}
///////////////////////////////////////////////////////////////////////////////
