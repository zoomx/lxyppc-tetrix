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

fourthOrderData_t fourthOrder100Hz[3];
fourthOrderData_t fourthOrder200Hz[3];

///////////////////////////////////////////////////////////////////////////////
//  4th Order Low Pass Filter for 100 Hz Data
///////////////////////////////////////////////////////////////////////////////

float computeFourthOrder100Hz(float currentInput, fourthOrderData_t * filterParameters)
{
    // cheby2(4,60,12.5/50)
#define B0_100HZ  0.001893594048567f
#define B1_100HZ -0.002220262954039f
#define B2_100HZ  0.003389066536478f
#define B3_100HZ -0.002220262954039f
#define B4_100HZ  0.001893594048567f

#define A1_100HZ -3.362256889209355f
#define A2_100HZ  4.282608240117919f
#define A3_100HZ -2.444765517272841f
#define A4_100HZ  0.527149895089809f

    float output;

    output = B0_100HZ * currentInput + B1_100HZ * filterParameters->inputTm1 + B2_100HZ * filterParameters->inputTm2 + B3_100HZ * filterParameters->inputTm3 + B4_100HZ * filterParameters->inputTm4 - A1_100HZ * filterParameters->outputTm1 - A2_100HZ * filterParameters->outputTm2 - A3_100HZ * filterParameters->outputTm3 - A4_100HZ * filterParameters->outputTm4;

    filterParameters->inputTm4 = filterParameters->inputTm3;
    filterParameters->inputTm3 = filterParameters->inputTm2;
    filterParameters->inputTm2 = filterParameters->inputTm1;
    filterParameters->inputTm1 = currentInput;

    filterParameters->outputTm4 = filterParameters->outputTm3;
    filterParameters->outputTm3 = filterParameters->outputTm2;
    filterParameters->outputTm2 = filterParameters->outputTm1;
    filterParameters->outputTm1 = output;

    return output;
}

///////////////////////////////////////////////////////////////////////////////

void setupFourthOrder100Hz(void)
{
    fourthOrder100Hz[AX_FILTER].inputTm1 = 0.0f;
    fourthOrder100Hz[AX_FILTER].inputTm2 = 0.0f;
    fourthOrder100Hz[AX_FILTER].inputTm3 = 0.0f;
    fourthOrder100Hz[AX_FILTER].inputTm4 = 0.0f;

    fourthOrder100Hz[AX_FILTER].outputTm1 = 0.0f;
    fourthOrder100Hz[AX_FILTER].outputTm2 = 0.0f;
    fourthOrder100Hz[AX_FILTER].outputTm3 = 0.0f;
    fourthOrder100Hz[AX_FILTER].outputTm4 = 0.0f;

    /////////////////////////////////////

    fourthOrder100Hz[AY_FILTER].inputTm1 = 0.0f;
    fourthOrder100Hz[AY_FILTER].inputTm2 = 0.0f;
    fourthOrder100Hz[AY_FILTER].inputTm3 = 0.0f;
    fourthOrder100Hz[AY_FILTER].inputTm4 = 0.0f;

    fourthOrder100Hz[AY_FILTER].outputTm1 = 0.0f;
    fourthOrder100Hz[AY_FILTER].outputTm2 = 0.0f;
    fourthOrder100Hz[AY_FILTER].outputTm3 = 0.0f;
    fourthOrder100Hz[AY_FILTER].outputTm4 = 0.0f;

    /////////////////////////////////////

    fourthOrder100Hz[AZ_FILTER].inputTm1 = -9.8065f;
    fourthOrder100Hz[AZ_FILTER].inputTm2 = -9.8065f;
    fourthOrder100Hz[AZ_FILTER].inputTm3 = -9.8065f;
    fourthOrder100Hz[AZ_FILTER].inputTm4 = -9.8065f;

    fourthOrder100Hz[AZ_FILTER].outputTm1 = -9.8065f;
    fourthOrder100Hz[AZ_FILTER].outputTm2 = -9.8065f;
    fourthOrder100Hz[AZ_FILTER].outputTm3 = -9.8065f;
    fourthOrder100Hz[AZ_FILTER].outputTm4 = -9.8065f;
}

///////////////////////////////////////////////////////////////////////////////
//  4th Order Low Pass Filter for 200 Hz Data
///////////////////////////////////////////////////////////////////////////////

float computeFourthOrder200Hz(float currentInput, fourthOrderData_t * filterParameters)
{
    // cheby2(4,60,12.5/100)
#define B0_200HZ  0.001139392787073f
#define B1_200HZ -0.003386240693441f
#define B2_200HZ  0.004665482032666f
#define B3_200HZ -0.003386240693441f
#define B4_200HZ  0.001139392787073f

#define A1_200HZ -3.692341608388116f
#define A2_200HZ  5.123502002652351f
#define A3_200HZ -3.165946995349404f
#define A4_200HZ  0.734958387305099f

    float output;

    output = B0_200HZ * currentInput + B1_200HZ * filterParameters->inputTm1 + B2_200HZ * filterParameters->inputTm2 + B3_200HZ * filterParameters->inputTm3 + B4_200HZ * filterParameters->inputTm4 - A1_200HZ * filterParameters->outputTm1 - A2_200HZ * filterParameters->outputTm2 - A3_200HZ * filterParameters->outputTm3 - A4_200HZ * filterParameters->outputTm4;

    filterParameters->inputTm4 = filterParameters->inputTm3;
    filterParameters->inputTm3 = filterParameters->inputTm2;
    filterParameters->inputTm2 = filterParameters->inputTm1;
    filterParameters->inputTm1 = currentInput;

    filterParameters->outputTm4 = filterParameters->outputTm3;
    filterParameters->outputTm3 = filterParameters->outputTm2;
    filterParameters->outputTm2 = filterParameters->outputTm1;
    filterParameters->outputTm1 = output;

    return output;
}

///////////////////////////////////////////////////////////////////////////////

void setupFourthOrder200Hz(void)
{
    fourthOrder200Hz[AX_FILTER].inputTm1 = 0.0f;
    fourthOrder200Hz[AX_FILTER].inputTm2 = 0.0f;
    fourthOrder200Hz[AX_FILTER].inputTm3 = 0.0f;
    fourthOrder200Hz[AX_FILTER].inputTm4 = 0.0f;

    fourthOrder200Hz[AX_FILTER].outputTm1 = 0.0f;
    fourthOrder200Hz[AX_FILTER].outputTm2 = 0.0f;
    fourthOrder200Hz[AX_FILTER].outputTm3 = 0.0f;
    fourthOrder200Hz[AX_FILTER].outputTm4 = 0.0f;

    /////////////////////////////////////

    fourthOrder200Hz[AY_FILTER].inputTm1 = 0.0f;
    fourthOrder200Hz[AY_FILTER].inputTm2 = 0.0f;
    fourthOrder200Hz[AY_FILTER].inputTm3 = 0.0f;
    fourthOrder200Hz[AY_FILTER].inputTm4 = 0.0f;

    fourthOrder200Hz[AY_FILTER].outputTm1 = 0.0f;
    fourthOrder200Hz[AY_FILTER].outputTm2 = 0.0f;
    fourthOrder200Hz[AY_FILTER].outputTm3 = 0.0f;
    fourthOrder200Hz[AY_FILTER].outputTm4 = 0.0f;

    /////////////////////////////////////

    fourthOrder200Hz[AZ_FILTER].inputTm1 = -9.8065f;
    fourthOrder200Hz[AZ_FILTER].inputTm2 = -9.8065f;
    fourthOrder200Hz[AZ_FILTER].inputTm3 = -9.8065f;
    fourthOrder200Hz[AZ_FILTER].inputTm4 = -9.8065f;

    fourthOrder200Hz[AZ_FILTER].outputTm1 = -9.8065f;
    fourthOrder200Hz[AZ_FILTER].outputTm2 = -9.8065f;
    fourthOrder200Hz[AZ_FILTER].outputTm3 = -9.8065f;
    fourthOrder200Hz[AZ_FILTER].outputTm4 = -9.8065f;
}

///////////////////////////////////////////////////////////////////////////////
