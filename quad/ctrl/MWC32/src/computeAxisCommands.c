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

#define RATE_SCALING     0.005  // Stick to rate scaling (5 radians/sec)/(1000 RX PWM Steps) = 0.005
#define ATTITUDE_SCALING 0.001  // Stick to att scaling (1 radian)/(1000 RX PWM Steps) = 0.001

float   attCmd[3];

float   attPID[3];

float   axisPID[3];float rateCmd[3];

float   headingReference;



///////////////////////////////////////////////////////////////////////////////
// Compute Axis Commands
///////////////////////////////////////////////////////////////////////////////

void computeAxisCommands(float dt)
{
    if (flightMode == ATTITUDE)
    {
        attCmd[ROLL ] = rxCommand[ROLL ] * ATTITUDE_SCALING;
        attCmd[PITCH] = rxCommand[PITCH] * ATTITUDE_SCALING;
    }

    if (flightMode >= ATTITUDE)
    {
        attPID[ROLL]  = updatePID( attCmd[ROLL ],  sensors.attitude200Hz[ROLL ], dt, holdIntegrators, &systemConfig.PID[ROLL_ATT_PID ] );
        attPID[PITCH] = updatePID( attCmd[PITCH], -sensors.attitude200Hz[PITCH], dt, holdIntegrators, &systemConfig.PID[PITCH_ATT_PID] );
    }

    if (flightMode == RATE)
    {
        rateCmd[ROLL ] = rxCommand[ROLL ] * RATE_SCALING;
        rateCmd[PITCH] = rxCommand[PITCH] * RATE_SCALING;
    }
    else
    {
        rateCmd[ROLL ] = attPID[ROLL ];
        rateCmd[PITCH] = attPID[PITCH];
    }

    if ( (commandInDetent[YAW] == true) && (rxCommand[AUX2] > MIDCOMMAND) )  // Heading Hold is ON
    {
        if (previousCommandInDetent[YAW] == false)
        {
            setIntegralError(HEADING_PID, 0.0f);  // First pass in heading hold with new reference, zero integral PID error
        }
        rateCmd[YAW] = updatePID( headingReference, sensors.attitude200Hz[YAW], dt, holdIntegrators, &systemConfig.PID[HEADING_PID] );
    }
    else  // Heading Hold is OFF
    {
        rateCmd[YAW] = rxCommand[YAW] * RATE_SCALING;
        headingReference = sensors.attitude200Hz[YAW];
    }

    axisPID[ROLL ] = updatePID( rateCmd[ROLL ],  sensors.gyro100Hz[ROLL ], dt, holdIntegrators, &systemConfig.PID[ROLL_RATE_PID ] );
    axisPID[PITCH] = updatePID( rateCmd[PITCH], -sensors.gyro100Hz[PITCH], dt, holdIntegrators, &systemConfig.PID[PITCH_RATE_PID] );
    axisPID[YAW  ] = updatePID( rateCmd[YAW  ],  sensors.gyro100Hz[YAW  ], dt, holdIntegrators, &systemConfig.PID[YAW_RATE_PID  ] );
}

///////////////////////////////////////////////////////////////////////////////
