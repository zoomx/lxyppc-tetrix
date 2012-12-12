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

PIDdata_t PID[NUMBER_OF_PIDS];

uint8_t holdIntegrators = true;

#define F_CUT 20.0f
float rc;

///////////////////////////////////////////////////////////////////////////////

void initPID(void)
{
    uint8_t index;

    rc = 1.0f / ( TWO_PI * F_CUT );

    for (index = 0; index < NUMBER_OF_PIDS; index++)
    {
		PID[index].lastError = 0.0f;
		PID[index].dTerm1    = 0.0f;
		PID[index].dTerm2    = 0.0f;
	}
}

///////////////////////////////////////////////////////////////////////////////

float updatePID(float command, float state, float deltaT, uint8_t iHold, struct PIDdata *PIDparameters)
{
    float error;
    float dTerm;
    float dSum;

    error = command - state;

    if (PIDparameters->type == 1)
        error = standardRadianFormat(error);

    if ( iHold == false )
    {
    	PIDparameters->iTerm += error * deltaT;
    	PIDparameters->iTerm = constrain(PIDparameters->iTerm, -PIDparameters->windupGuard, PIDparameters->windupGuard);
    }

    dTerm = (error - PIDparameters->lastError) / deltaT;
    // Discrete low pass filter, cuts out the
    // high frequency noise that can drive controller crazy
    dTerm = PIDparameters->lastError + (deltaT / (rc + deltaT)) * (dTerm - PIDparameters->lastError);

    PIDparameters->lastError = error;

    dSum =  dTerm + PIDparameters->dTerm1 + PIDparameters->dTerm2;
    PIDparameters->dTerm2 = PIDparameters->dTerm1;
    PIDparameters->dTerm1 = dTerm;

    if (PIDparameters->type == 1)
        return(standardRadianFormat(PIDparameters->P * error) + (PIDparameters->I * (PIDparameters->iTerm)) + (PIDparameters->D * dSum));
    else
        return(PIDparameters->P * error) + (PIDparameters->I * (PIDparameters->iTerm)) + (PIDparameters->D * dSum);
}

///////////////////////////////////////////////////////////////////////////////

void setIntegralError(uint8_t IDPid, float value)
{
    PID[IDPid].iTerm = value;
}

///////////////////////////////////////////////////////////////////////////////

void zeroIntegralError(void)
{
    uint8_t index;

    for (index = 0; index < NUMBER_OF_PIDS; index++)
    {
        setIntegralError(index, 0.0f);
    }
}

///////////////////////////////////////////////////////////////////////////////

void zeroLastError(void)
{
    uint8_t index;

    for (index = 0; index < NUMBER_OF_PIDS; index++)
    {
    	PID[index].lastError = 0.0f;
    }
}

///////////////////////////////////////////////////////////////////////////////


