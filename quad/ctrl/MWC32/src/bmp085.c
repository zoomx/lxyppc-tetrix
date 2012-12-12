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
// BMP085 Variables
///////////////////////////////////////////////////////////////////////////////

#define BMP085_ADDRESS 0x77

///////////////////////////////////

//#define OSS 0  //  4.5 mSec conversion time (222.22 Hz)
#define OSS 1                   //  7.5 mSec conversion time (133.33 Hz)
//#define OSS 2  // 13.5 mSec conversion time ( 74.07 Hz)
//#define OSS 3  // 25.5 mSec conversion time ( 39.22 Hz)

///////////////////////////////////////

#define BMP085_PROM_START_ADDR  0xAA
#define BMP085_PROM_DATA_LEN    22

#define BMP085_T_MEASURE        0x2E    // temperature measurement
#define BMP085_P_MEASURE        0x34 + (OSS<<6) // pressure measurement
#define BMP085_CTRL_MEAS_REG    0xF4
#define BMP085_ADC_OUT_MSB_REG  0xF6

///////////////////////////////////////

float pressureAlt;

int32_t pressureAverage;

int32_t pressureSum;

int32andUint8_t uncompensatedPressure;

int32andUint8_t uncompensatedTemperature;

int16andUint8_t ac1, ac2, ac3, b1, b2, mb, mc, md;

uint16andUint8_t ac4, ac5, ac6;

int32_t x1, x2, x3, b3, b5, b6, p;

uint32_t b4, b7;

///////////////////////////////////////////////////////////////////////////////
// Read Temperature Request Pressure
///////////////////////////////////////////////////////////////////////////////
void readTemperatureRequestPressure(void)
{
    uint8_t data[2];

    i2cRead(BMP085_ADDRESS, BMP085_ADC_OUT_MSB_REG, 2, data);

    uncompensatedTemperature.bytes[1] = data[0];
    uncompensatedTemperature.bytes[0] = data[1];

    i2cWrite(BMP085_ADDRESS, BMP085_CTRL_MEAS_REG, BMP085_P_MEASURE);
}

///////////////////////////////////////////////////////////////////////////////
// ReadPressureRequestPressure
///////////////////////////////////////////////////////////////////////////////

void readPressureRequestPressure(void)
{
    uint8_t data[3];

    i2cRead(BMP085_ADDRESS, BMP085_ADC_OUT_MSB_REG, 3, data);

    uncompensatedPressure.bytes[2] = data[0];
    uncompensatedPressure.bytes[1] = data[1];
    uncompensatedPressure.bytes[0] = data[2];

    uncompensatedPressure.value = uncompensatedPressure.value >> (8 - OSS);

    i2cWrite(BMP085_ADDRESS, BMP085_CTRL_MEAS_REG, BMP085_P_MEASURE);
}

///////////////////////////////////////////////////////////////////////////////
// Read Pressure Request Temperature
///////////////////////////////////////////////////////////////////////////////

void readPressureRequestTemperature(void)
{
    uint8_t data[3];

    i2cRead(BMP085_ADDRESS, BMP085_ADC_OUT_MSB_REG, 3, data);

    uncompensatedPressure.bytes[2] = data[0];
    uncompensatedPressure.bytes[1] = data[1];
    uncompensatedPressure.bytes[0] = data[2];

    uncompensatedPressure.value = uncompensatedPressure.value >> (8 - OSS);

    i2cWrite(BMP085_ADDRESS, BMP085_CTRL_MEAS_REG, BMP085_T_MEASURE);
}

///////////////////////////////////////////////////////////////////////////////
// Calculate Temperature
///////////////////////////////////////////////////////////////////////////////

void calculateTemperature(void)
{
    x1 = ((uncompensatedTemperature.value - (int32_t) ac6.value) * (int32_t) ac5.value) >> 15;
    x2 = ((int32_t) mc.value << 11) / (x1 + md.value);
    b5 = x1 + x2;
}

///////////////////////////////////////////////////////////////////////////////
// Calculate Pressure Altitude
///////////////////////////////////////////////////////////////////////////////

void calculatePressureAltitude(void)
{
    b6 = b5 - 4000;
    x1 = (b2.value * (b6 * b6 >> 12)) >> 11;
    x2 = ac2.value * b6 >> 11;
    x3 = x1 + x2;
    b3 = ((((int32_t) ac1.value * 4 + x3) << OSS) + 2) >> 2;
    x1 = (ac3.value * b6) >> 13;
    x2 = (b1.value * ((b6 * b6) >> 12)) >> 16;
    x3 = ((x1 + x2) + 2) >> 2;
    b4 = (ac4.value * (uint32_t) (x3 + 32768)) >> 15;
    b7 = (uint32_t) (pressureAverage - b3) * (50000 >> OSS);
    p = b7 < 0x80000000 ? (b7 << 1) / b4 : (b7 / b4) << 1;
    x1 = (p >> 8) * (p >> 8);
    x1 = (x1 * 3038) >> 16;
    x2 = (-7357 * p) >> 16;
    p = p + ((x1 + x2 + 3791) >> 4);

    pressureAlt = (44330.0f * (1.0f - pow((float) p / 101325.0f, 0.190295f)));
}

///////////////////////////////////////////////////////////////////////////////
// Pressure Initialization
///////////////////////////////////////////////////////////////////////////////

void initPressure(void)
{
    uint8_t promData[BMP085_PROM_DATA_LEN];

    delay(15);

    i2cRead(BMP085_ADDRESS, BMP085_PROM_START_ADDR, BMP085_PROM_DATA_LEN, promData);

    ac1.bytes[1] = promData[0];
    ac1.bytes[0] = promData[1];
    ac2.bytes[1] = promData[2];
    ac2.bytes[0] = promData[3];
    ac3.bytes[1] = promData[4];
    ac3.bytes[0] = promData[5];
    ac4.bytes[1] = promData[6];
    ac4.bytes[0] = promData[7];
    ac5.bytes[1] = promData[8];
    ac5.bytes[0] = promData[9];
    ac6.bytes[1] = promData[10];
    ac6.bytes[0] = promData[11];

    b1.bytes[1] = promData[12];
    b1.bytes[0] = promData[13];
    b2.bytes[1] = promData[14];
    b2.bytes[0] = promData[15];

    mb.bytes[1] = promData[16];
    mb.bytes[0] = promData[17];
    mc.bytes[1] = promData[18];
    mc.bytes[0] = promData[19];
    md.bytes[1] = promData[20];
    md.bytes[0] = promData[21];

    i2cWrite(BMP085_ADDRESS, BMP085_CTRL_MEAS_REG, BMP085_T_MEASURE);

    delay(10);

    readTemperatureRequestPressure();

    delay(10);

    readPressureRequestTemperature();

    delay(10);

    calculateTemperature();
    calculatePressureAltitude();
}

///////////////////////////////////////////////////////////////////////////////
