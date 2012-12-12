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
// Process Pilot Commands Defines and Variables
///////////////////////////////////////////////////////////////////////////////

float    rxCommand[8] = { 0.0f, 0.0f, 0.0f, 2000.0f, 2000.0f, 2000.0f, 2000.0f, 2000.0f };

uint8_t  commandInDetent[3]         = { true, true, true };
uint8_t  previousCommandInDetent[3] = { true, true, true };

///////////////////////////////////////////////////////////////////////////////
// Flight Mode Defines and Variables
///////////////////////////////////////////////////////////////////////////////

uint8_t flightMode = RATE;

///////////////////////////////////////////////////////////////////////////////
// Arm State Variables
///////////////////////////////////////////////////////////////////////////////

uint8_t armed       = false;
uint8_t armingTimer = 0;

///////////////////////////////////////////////////////////////////////////////
// Read Flight Commands
///////////////////////////////////////////////////////////////////////////////

void processFlightCommands(void)
{
    uint8_t channel;

    if ( rcActive == true )
    {
		// Read receiver commands
        for (channel = 0; channel < 8; channel++)
            rxCommand[channel] = (float)pwmRead(systemConfig.rcMap[channel]);

        rxCommand[ROLL]  -= systemConfig.midCommand;                  // Roll Range    -1000:1000
        rxCommand[PITCH] -= systemConfig.midCommand;                  // Pitch Range   -1000:1000
        rxCommand[YAW]   -= systemConfig.midCommand;                  // Yaw Range     -1000:1000

        rxCommand[THROTTLE] -= systemConfig.midCommand - MIDCOMMAND;  // Throttle Range 2000:4000
        rxCommand[AUX1]     -= systemConfig.midCommand - MIDCOMMAND;  // Aux1 Range     2000:4000
        rxCommand[AUX2]     -= systemConfig.midCommand - MIDCOMMAND;  // Aux2 Range     2000:4000
        rxCommand[AUX3]     -= systemConfig.midCommand - MIDCOMMAND;  // Aux3 Range     2000:4000
        rxCommand[AUX4]     -= systemConfig.midCommand - MIDCOMMAND;  // Aux4 Range     2000:4000
    }

    // Set past command in detent values
    for (channel = 0; channel < 3; channel++)
    	previousCommandInDetent[channel] = commandInDetent[channel];

    // Apply deadbands and set detent discretes'
    for (channel = 0; channel < 3; channel++)
    {
    	if ((rxCommand[channel] <= DEADBAND) && (rxCommand[channel] >= -DEADBAND))
        {
            rxCommand[channel] = 0;
  	        commandInDetent[channel] = true;
  	    }
        else
  	    {
  	        commandInDetent[channel] = false;
  	        if (rxCommand[channel] > 0)
  	        {
  		        rxCommand[channel] = (rxCommand[channel] - DEADBAND) * DEADBAND_SLOPE;
  	        }
  	        else
  	        {
  	            rxCommand[channel] = (rxCommand[channel] + DEADBAND) * DEADBAND_SLOPE;
  	        }
        }
    }

    ///////////////////////////////////

    // Check for low throttle
    if ( rxCommand[THROTTLE] < systemConfig.minCheck )
    {
		// Check for disarm command ( low throttle, left yaw ), will disarm immediately
		if ( (rxCommand[YAW] < (systemConfig.minCheck - MIDCOMMAND)) && (armed == true) )
		{
			armed = false;
			// Zero PID integrators when disarmed
			zeroIntegralError();
			zeroLastError();
		}

		// Check for gyro bias command ( low throttle, left yaw, aft pitch, right roll )
		if ( (rxCommand[YAW  ] < (systemConfig.minCheck - MIDCOMMAND)) &&
		     (rxCommand[ROLL ] > (systemConfig.maxCheck - MIDCOMMAND)) &&
		     (rxCommand[PITCH] < (systemConfig.minCheck - MIDCOMMAND)) )
		{
			computeGyroRTBias();
			pulseMotors(3);
		}

		// Check for arm command ( low throttle, right yaw), must be present for 1 sec before arming
		if ( (rxCommand[YAW] > (systemConfig.maxCheck - MIDCOMMAND) ) && (armed == false) )
		{
			armingTimer++;

			if ( armingTimer > 50 )
			{
				zeroIntegralError();
				armed = true;
				armingTimer = 0;
			}
		}
		else
		{
			armingTimer = 0;
		}
	}

	// Check for armed true and throttle command > minThrottle
    if ( (armed == true) && (rxCommand[THROTTLE] > systemConfig.minThrottle) )
    	holdIntegrators = false;
    else
    	holdIntegrators = true;

    // Check AUX1 for rate or attitude mode
	if ( rxCommand[AUX1] > MIDCOMMAND )
	{
		flightMode = ATTITUDE;
	}
	else
	{
		flightMode = RATE;
	}
}

///////////////////////////////////////////////////////////////////////////////




