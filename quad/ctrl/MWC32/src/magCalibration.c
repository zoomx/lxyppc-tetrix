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

uint8_t magCalibrating = false;

///////////////////////////////////////////////////////////////////////////////
// Magnetometer Calibration
///////////////////////////////////////////////////////////////////////////////

void magCalibration(void)
{
    float maxMagX = 0.0f;
    float minMagX = 0.0f;
    float maxMagY = 0.0f;
    float minMagY = 0.0f;
    float maxMagZ = 0.0f;
    float minMagZ = 0.0f;

    char numberString[12];

    magCalibrating = true;

    uartPrint("\nMagnetometer Calibration:\n\n");

    uartPrint("Rotate magnetometer around all axes multiple times\n");
    uartPrint("  Send a character when complete\n\n");

    while (uartAvailable() == false) {
        readMag();

        if ((float) rawMag[XAXIS].value * magScaleFactor[XAXIS] > maxMagX)
            maxMagX = (float) rawMag[XAXIS].value * magScaleFactor[XAXIS];
        if ((float) rawMag[XAXIS].value * magScaleFactor[XAXIS] < minMagX)
            minMagX = (float) rawMag[XAXIS].value * magScaleFactor[XAXIS];

        if ((float) rawMag[YAXIS].value * magScaleFactor[YAXIS] > maxMagY)
            maxMagY = (float) rawMag[YAXIS].value * magScaleFactor[YAXIS];
        if ((float) rawMag[YAXIS].value * magScaleFactor[YAXIS] < minMagY)
            minMagY = (float) rawMag[YAXIS].value * magScaleFactor[YAXIS];

        if ((float) rawMag[ZAXIS].value * magScaleFactor[ZAXIS] > maxMagZ)
            maxMagZ = (float) rawMag[ZAXIS].value * magScaleFactor[ZAXIS];
        if ((float) rawMag[ZAXIS].value * magScaleFactor[ZAXIS] < minMagZ)
            minMagZ = (float) rawMag[ZAXIS].value * magScaleFactor[ZAXIS];

        delay(20);
    };

    sensorConfig.magBias[XAXIS] = (maxMagX + minMagX) / 2.0f;
    sensorConfig.magBias[YAXIS] = (maxMagY + minMagY) / 2.0f;
    sensorConfig.magBias[ZAXIS] = (maxMagZ + minMagZ) / 2.0f;

    ftoa(sensorConfig.magBias[XAXIS], numberString);
    uartPrint(numberString);
    uartPrint(", ");
    ftoa(sensorConfig.magBias[YAXIS], numberString);
    uartPrint(numberString);
    uartPrint(", ");
    ftoa(sensorConfig.magBias[ZAXIS], numberString);
    uartPrint(numberString);
    uartPrint("\n");

    uartPrint("\nMagnetometer Calibration Complete.\n");

    magCalibrating = false;
}

///////////////////////////////////////////////////////////////////////////////
