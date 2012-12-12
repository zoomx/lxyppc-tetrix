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
// AHRS Reference Vector Calibration
///////////////////////////////////////////////////////////////////////////////

uint8_t ahrsCalibrating = false;

void ahrsCalibration(void)
{
    int16_t index;

    uint8_t temp;

    char numberString[12];

    ahrsCalibrating = true;

    sensorConfig.accelRefVector[XAXIS] = 0.0f;
    sensorConfig.accelRefVector[YAXIS] = 0.0f;
    sensorConfig.accelRefVector[ZAXIS] = 0.0f;

    sensorConfig.magRefVector[XAXIS] = 0.0f;
    sensorConfig.magRefVector[YAXIS] = 0.0f;
    sensorConfig.magRefVector[ZAXIS] = 0.0f;

    uartPrint("\nAHRS Reference Vector Calibration:\n\n");

    ///////////////////////////////////

    uartPrint("Place sensor board right side up, facing magnetic north.\n");
    uartPrint("  Send a character when ready to proceed\n\n");

    while (uartAvailable() == false) {
    };
    temp = uartRead();

    uartPrint("  Gathering Data...\n\n");

    for (index = 0; index < 2000; index++) {
        readAccel();
        sensorConfig.accelRefVector[XAXIS] += -((float) rawAccel[XAXIS].value - sensorConfig.accelBias[XAXIS]) * sensorConfig.accelScaleFactor[XAXIS];
        sensorConfig.accelRefVector[YAXIS] += -((float) rawAccel[YAXIS].value - sensorConfig.accelBias[YAXIS]) * sensorConfig.accelScaleFactor[YAXIS];
        sensorConfig.accelRefVector[ZAXIS] += -((float) rawAccel[ZAXIS].value - sensorConfig.accelBias[ZAXIS]) * sensorConfig.accelScaleFactor[ZAXIS];
        delayMicroseconds(1000);
    }

    sensorConfig.accelRefVector[XAXIS] /= 2000.0f;
    sensorConfig.accelRefVector[YAXIS] /= 2000.0f;
    sensorConfig.accelRefVector[ZAXIS] /= 2000.0f;

    for (index = 0; index < 100; index++) {
        readMag();
        sensorConfig.magRefVector[XAXIS] += -((float) rawMag[XAXIS].value - sensorConfig.magBias[XAXIS]);
        sensorConfig.magRefVector[YAXIS] += (float) rawMag[YAXIS].value - sensorConfig.magBias[YAXIS];
        sensorConfig.magRefVector[ZAXIS] += -((float) rawMag[ZAXIS].value - sensorConfig.magBias[ZAXIS]);
        delay(20);
    }

    sensorConfig.magRefVector[XAXIS] /= 100.0f;
    sensorConfig.magRefVector[YAXIS] /= 100.0f;
    sensorConfig.magRefVector[ZAXIS] /= 100.0f;

    /////////////////////////////////////

    uartPrint("\nAccel Reference Vector:\n");
    ftoa(sensorConfig.accelRefVector[XAXIS], numberString);
    uartPrint(numberString);
    uartPrint(", ");
    ftoa(sensorConfig.accelRefVector[YAXIS], numberString);
    uartPrint(numberString);
    uartPrint(", ");
    ftoa(sensorConfig.accelRefVector[ZAXIS], numberString);
    uartPrint(numberString);
    uartPrint("\n");

    uartPrint("\nMag Reference Vector:\n");
    ftoa(sensorConfig.magRefVector[XAXIS], numberString);
    uartPrint(numberString);
    uartPrint(", ");
    ftoa(sensorConfig.magRefVector[YAXIS], numberString);
    uartPrint(numberString);
    uartPrint(", ");
    ftoa(sensorConfig.magRefVector[ZAXIS], numberString);
    uartPrint(numberString);
    uartPrint("\n");

    uartPrint("\nAHRS Reference Vector Calibration Complete.\n");

    ahrsCalibrating = false;
}

///////////////////////////////////////////////////////////////////////////////
