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

#define MPU3050_ADDRESS 0x68

// Registers

#define MPU3050_X_OFFS_H      0x0C
#define MPU3050_X_OFFS_L      0x0D
#define MPU3050_Y_OFFS_H      0x0E
#define MPU3050_Y_OFFS_L      0x0F
#define MPU3050_Z_OFFS_H      0x10
#define MPU3050_Z_OFFS_L      0x11
#define MPU3050_SMPLRT_DIV    0x15
#define MPU3050_DLPF_FS_SYNC  0x16
#define MPU3050_INT_CFG       0x17
#define MPU3050_TEMP_OUT      0x1B
#define MPU3050_GYRO_OUT      0x1D
#define MPU3050_USER_CTRL     0x3D
#define MPU3050_PWR_MGM       0x3E

// Bits

#define FS_SEL_2000_DPS       0x18

#define ACTL                  0x00
#define OPEN                  0x00
#define LATCH_INT_EN          0x20
#define INT_ANYRD_2CLEAR      0x10
#define RAW_RDY_EN            0x01

#define H_RESET               0x80
#define INTERNAL_OSC          0x00

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
    i2cRead(MPU3050_ADDRESS, MPU3050_TEMP_OUT, 8, I2C2_Buffer_Rx);

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
    i2cWrite(MPU3050_ADDRESS, MPU3050_PWR_MGM, H_RESET);
    i2cWrite(MPU3050_ADDRESS, MPU3050_PWR_MGM, INTERNAL_OSC);
    i2cWrite(MPU3050_ADDRESS, MPU3050_DLPF_FS_SYNC, LOW_PASS_FILTER | FS_SEL_2000_DPS);
    i2cWrite(MPU3050_ADDRESS, MPU3050_SMPLRT_DIV, SAMPLE_RATE_DIVISOR);
    i2cWrite(MPU3050_ADDRESS, MPU3050_INT_CFG, 0);

    delay(100);

    computeGyroRTBias();
}

///////////////////////////////////////////////////////////////////////////////
