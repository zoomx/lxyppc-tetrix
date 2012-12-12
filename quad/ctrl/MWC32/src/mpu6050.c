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

#include "board.h"

///////////////////////////////////////////////////////////////////////////////
// MPU3050 Defines and Variables
///////////////////////////////////////////////////////////////////////////////

// Address

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


///////////////////////////////////////

uint8_t gyroCalibrating = false;

float gyroRTBias[3];

int32_t gyroSum100Hz[3] = { 0, 0, 0 };

int32_t gyroSum200Hz[3] = { 0, 0, 0 };

int32_t gyroSum500Hz[3] = { 0, 0, 0 };

int32_t gyroSummedSamples100Hz[3];

int32_t gyroSummedSamples200Hz[3];

int32_t gyroSummedSamples500Hz[3];

float gyroTCBias[3];

float gyroTemperature;

int16andUint8_t rawGyro[3];

int16andUint8_t rawGyroTemperature;

///////////////////////////////////////////////////////////////////////////////
// Read Gyro
///////////////////////////////////////////////////////////////////////////////

void readGyro(void)
{
    uint8_t I2C2_Buffer_Rx[8];

    // Get data from device
    i2cRead(MPU6050_ADDRESS, MPU60X0_REG_TEMP_OUT_H, 8, I2C2_Buffer_Rx);

    rawGyroTemperature.bytes[1] = I2C2_Buffer_Rx[0];
    rawGyroTemperature.bytes[0] = I2C2_Buffer_Rx[1];

    rawGyro[ROLL].bytes[1] = I2C2_Buffer_Rx[2];
    rawGyro[ROLL].bytes[0] = I2C2_Buffer_Rx[3];
    rawGyro[PITCH].bytes[1] = I2C2_Buffer_Rx[4];
    rawGyro[PITCH].bytes[0] = I2C2_Buffer_Rx[5];
    rawGyro[YAW].bytes[1] = I2C2_Buffer_Rx[6];
    rawGyro[YAW].bytes[0] = I2C2_Buffer_Rx[7];
}

///////////////////////////////////////////////////////////////////////////////
// Compute Gyro Temperature Compensation Bias
///////////////////////////////////////////////////////////////////////////////

void computeGyroTCBias(void)
{
    gyroTemperature = (float) (rawGyroTemperature.value + 13200) / 280.0f + 35.0f;

    gyroTCBias[ROLL] = sensorConfig.gyroTCBiasSlope[ROLL] * gyroTemperature + sensorConfig.gyroTCBiasIntercept[ROLL];
    gyroTCBias[PITCH] = sensorConfig.gyroTCBiasSlope[PITCH] * gyroTemperature + sensorConfig.gyroTCBiasIntercept[PITCH];
    gyroTCBias[YAW] = sensorConfig.gyroTCBiasSlope[YAW] * gyroTemperature + sensorConfig.gyroTCBiasIntercept[YAW];
}

///////////////////////////////////////////////////////////////////////////////
// Compute Gyro Runtime Bias
///////////////////////////////////////////////////////////////////////////////

void computeGyroRTBias(void)
{
    uint8_t axis;
    uint16_t samples;
    float gyroSum[3] = { 0.0f, 0.0f, 0.0f };

    gyroCalibrating = true;

    for (samples = 0; samples < 2000; samples++) {
        readGyro();

        computeGyroTCBias();

        gyroSum[ROLL] += rawGyro[ROLL].value - gyroTCBias[ROLL];
        gyroSum[PITCH] += rawGyro[PITCH].value - gyroTCBias[PITCH];
        gyroSum[YAW] += rawGyro[YAW].value - gyroTCBias[YAW];

        delayMicroseconds(1000);
    }

    for (axis = ROLL; axis < 3; axis++) {
        gyroRTBias[axis] = (float) gyroSum[axis] / 2000.0f;

    }

    gyroCalibrating = false;
}

///////////////////////////////////////////////////////////////////////////////
// Gyro Initialization
///////////////////////////////////////////////////////////////////////////////

void initGyro(void)
{
    i2cWrite(MPU6050_ADDRESS, MPU60X0_REG_PWR_MGMT_1, H_RESET);
    i2cWrite(MPU6050_ADDRESS, MPU60X0_REG_PWR_MGMT_1, PLL_WITH_Z);
    i2cWrite(MPU6050_ADDRESS, MPU60X0_REG_CONFIG, 0); //EXT_SYNC_SET 0 (disable input pin for data sync) ; default DLPF_CFG = 0 => ACC bandwidth = 260Hz  GYRO bandwidth = 256Hz)
    i2cWrite(MPU6050_ADDRESS, MPU60X0_REG_GYRO_CONFIG, 0x18); //GYRO_CONFIG   -- FS_SEL = 3: Full scale set to 2000 deg/sec
    
    //i2cWrite(MPU6050_ADDRESS, MPU60X0_REG_INT_PIN_CFG, 0x02); //INT_PIN_CFG   -- INT_LEVEL=0 ; INT_OPEN=0 ; LATCH_INT_EN=0 ; INT_RD_CLEAR=0 ; FSYNC_INT_LEVEL=0 ; FSYNC_INT_EN=0 ; I2C_BYPASS_EN=1 ; CLKOUT_EN=0

    delay(100);

    computeGyroRTBias();
}



///////////////////////////////////

uint8_t accelCalibrating = false;

float accelRTBias[3] = { 0.0f, 0.0f, 0.0f };

int32_t accelSum100Hz[3] = { 0, 0, 0 };

int32_t accelSum200Hz[3] = { 0, 0, 0 };

int32_t accelSummedSamples100Hz[3];

int32_t accelSummedSamples200Hz[3];

int16andUint8_t rawAccel[3];

///////////////////////////////////////////////////////////////////////////////
// Compute Accel Runtime Bias
///////////////////////////////////////////////////////////////////////////////

void computeAccelRTBias(void)
{
    uint16_t samples;
    float accelSum[3] = { 0, 0, 0 };

    accelCalibrating = true;

    for (samples = 0; samples < 2000; samples++) {
        readAccel();

        accelSum[XAXIS] += rawAccel[XAXIS].value;
        accelSum[YAXIS] += rawAccel[YAXIS].value;
        accelSum[ZAXIS] += rawAccel[ZAXIS].value;

        delayMicroseconds(1000);
    }

    accelRTBias[XAXIS] = accelSum[XAXIS] / 2000.0f;
    accelRTBias[YAXIS] = accelSum[YAXIS] / 2000.0f;
    accelRTBias[ZAXIS] = (accelSum[ZAXIS] / 2000.0f) - (9.8056f / fabs(sensorConfig.accelScaleFactor[ZAXIS]));

    accelCalibrating = false;
}

///////////////////////////////////////////////////////////////////////////////
// Read Accel
///////////////////////////////////////////////////////////////////////////////

void readAccel(void)
{
    uint8_t buffer[6];

    i2cRead(MPU6050_ADDRESS, MPU60X0_REG_ACCEL_XOUT_H, 6, buffer);

    rawAccel[YAXIS].bytes[0] = buffer[0];
    rawAccel[YAXIS].bytes[1] = buffer[1];
    rawAccel[XAXIS].bytes[0] = buffer[2];
    rawAccel[XAXIS].bytes[1] = buffer[3];
    rawAccel[ZAXIS].bytes[0] = buffer[4];
    rawAccel[ZAXIS].bytes[1] = buffer[5];
}

///////////////////////////////////////////////////////////////////////////////
// Accel Initialization
///////////////////////////////////////////////////////////////////////////////

void initAccel(void)
{
    i2cWrite(MPU6050_ADDRESS, MPU60X0_REG_ACCEL_CONFIG, 0x1c); //ACCEL_CONFIG  -- AFS_SEL=2 (Full Scale = +/-8G)  ; ACCELL_HPF=0   //note something is wrong in the spec.

#if defined(MPU6050_I2C_AUX_MASTER)
    //at this stage, the MAG is configured via the original MAG init function in I2C bypass mode
    //now we configure MPU as a I2C Master device to handle the MAG via the I2C AUX port (done here for HMC5883)
    i2cWrite(MPU6050_ADDRESS, 0x6A, 0b00100000);       //USER_CTRL     -- DMP_EN=0 ; FIFO_EN=0 ; I2C_MST_EN=1 (I2C master mode) ; I2C_IF_DIS=0 ; FIFO_RESET=0 ; I2C_MST_RESET=0 ; SIG_COND_RESET=0
    i2cWrite(MPU6050_ADDRESS, 0x37, 0x00);             //INT_PIN_CFG   -- INT_LEVEL=0 ; INT_OPEN=0 ; LATCH_INT_EN=0 ; INT_RD_CLEAR=0 ; FSYNC_INT_LEVEL=0 ; FSYNC_INT_EN=0 ; I2C_BYPASS_EN=0 ; CLKOUT_EN=0
    i2cWrite(MPU6050_ADDRESS, 0x24, 0x0D);             //I2C_MST_CTRL  -- MULT_MST_EN=0 ; WAIT_FOR_ES=0 ; SLV_3_FIFO_EN=0 ; I2C_MST_P_NSR=0 ; I2C_MST_CLK=13 (I2C slave speed bus = 400kHz)
    i2cWrite(MPU6050_ADDRESS, 0x25, 0x80|MAG_ADDRESS);//I2C_SLV0_ADDR -- I2C_SLV4_RW=1 (read operation) ; I2C_SLV4_ADDR=MAG_ADDRESS
    i2cWrite(MPU6050_ADDRESS, 0x26, MAG_DATA_REGISTER);//I2C_SLV0_REG  -- 6 data bytes of MAG are stored in 6 registers. First register address is MAG_DATA_REGISTER
    i2cWrite(MPU6050_ADDRESS, 0x27, 0x86);             //I2C_SLV0_CTRL -- I2C_SLV0_EN=1 ; I2C_SLV0_BYTE_SW=0 ; I2C_SLV0_REG_DIS=0 ; I2C_SLV0_GRP=0 ; I2C_SLV0_LEN=3 (3x2 bytes)
#endif
    
    
#ifdef USE_ACCEL_RT_BIAS
    computeAccelRTBias();
#else
    accelRTBias[XAXIS] = 0.0f;
    accelRTBias[YAXIS] = 0.0f;
    accelRTBias[ZAXIS] = 0.0f;
#endif
}
///////////////////////////////////////////////////////////////////////////////
