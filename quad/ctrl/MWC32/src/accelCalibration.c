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
// Accelerometer Calibration
///////////////////////////////////////////////////////////////////////////////

void accelCalibration(void)
{
    float noseUp = 0.0f;
    float noseDown = 0.0f;
    float leftWingDown = 0.0f;
    float rightWingDown = 0.0f;
    float upSideDown = 0.0f;
    float rightSideUp = 0.0f;

    int16_t index;

    uint8_t temp;

    char numberString[12];

    accelCalibrating = true;

    uartPrint("\nAccelerometer Calibration:\n\n");

    ///////////////////////////////////

    uartPrint("Place accelerometer right side up\n");
    uartPrint("  Send a character when ready to proceed\n\n");

    while (uartAvailable() == false) {
    };
    temp = uartRead();

    uartPrint("  Gathering Data...\n\n");

    for (index = 0; index < 5000; index++) {
        readAccel();
        rightSideUp += (float) rawAccel[ZAXIS].value;
        delayMicroseconds(1000);
    }

    rightSideUp /= 5000.0f;

    ftoa(rightSideUp, numberString);
    uartPrint(numberString);
    uartPrint("\n\n");

    uartPrint("Place accelerometer up side down\n");
    uartPrint("  Send a character when ready to proceed\n\n");

    while (uartAvailable() == false) {
    };
    temp = uartRead();

    uartPrint("  Gathering Data...\n\n");

    for (index = 0; index < 5000; index++) {
        readAccel();
        upSideDown += (float) rawAccel[ZAXIS].value;
        delayMicroseconds(1000);
    }

    upSideDown /= 5000.0f;

    ftoa(upSideDown, numberString);
    uartPrint(numberString);
    uartPrint("\n\n");

    sensorConfig.accelBias[ZAXIS] = (rightSideUp + upSideDown) / 2.0f;

    sensorConfig.accelScaleFactor[ZAXIS] = (2.0f * 9.8065f) / (fabs(rightSideUp) + fabs(upSideDown));

    ///////////////////////////////////

    uartPrint("Place accelerometer left edge down\n");
    uartPrint("  Send a character when ready to proceed\n\n");

    while (uartAvailable() == false) {
    };
    temp = uartRead();

    uartPrint("  Gathering Data...\n\n");

    for (index = 0; index < 5000; index++) {
        readAccel();
        leftWingDown += (float) rawAccel[YAXIS].value;
        delayMicroseconds(1000);
    }

    leftWingDown /= 5000.0f;

    ftoa(leftWingDown, numberString);
    uartPrint(numberString);
    uartPrint("\n\n");

    uartPrint("Place accelerometer right edge down\n");
    uartPrint("  Send a character when ready to proceed\n\n");

    while (uartAvailable() == false) {
    };
    temp = uartRead();

    uartPrint("  Gathering Data...\n\n");

    for (index = 0; index < 5000; index++) {
        readAccel();
        rightWingDown += (float) rawAccel[YAXIS].value;
        delayMicroseconds(1000);
    }

    rightWingDown /= 5000.0f;

    ftoa(rightWingDown, numberString);
    uartPrint(numberString);
    uartPrint("\n\n");

    sensorConfig.accelBias[YAXIS] = (leftWingDown + rightWingDown) / 2.0f;

    sensorConfig.accelScaleFactor[YAXIS] = (2.0f * 9.8065f) / (fabs(leftWingDown) + fabs(rightWingDown));

    ///////////////////////////////////

    uartPrint("Place accelerometer rear edge down\n");
    uartPrint("  Send a character when ready to proceed\n\n");

    while (uartAvailable() == false) {
    };
    temp = uartRead();

    uartPrint("  Gathering Data...\n\n");

    for (index = 0; index < 5000; index++) {
        readAccel();
        noseUp += (float) rawAccel[XAXIS].value;
        delayMicroseconds(1000);
    }

    noseUp /= 5000.0f;

    ftoa(noseUp, numberString);
    uartPrint(numberString);
    uartPrint("\n\n");

    uartPrint("Place accelerometer front edge down\n");
    uartPrint("  Send a character when ready to proceed\n\n");

    while (uartAvailable() == false) {
    };
    temp = uartRead();

    uartPrint("  Gathering Data...\n\n");

    for (index = 0; index < 5000; index++) {
        readAccel();
        noseDown += (float) rawAccel[XAXIS].value;
        delayMicroseconds(1000);
    }

    noseDown /= 5000.0f;

    ftoa(noseDown, numberString);
    uartPrint(numberString);
    uartPrint("\n\n");

    sensorConfig.accelBias[XAXIS] = (noseUp + noseDown) / 2.0f;

    sensorConfig.accelScaleFactor[XAXIS] = (2.0f * 9.8065f) / (fabs(noseUp) + fabs(noseDown));

    ///////////////////////////////////

    ftoa(noseUp, numberString);
    uartPrint(numberString);
    uartPrint(", ");
    ftoa(noseDown, numberString);
    uartPrint(numberString);
    uartPrint(", ");
    ftoa(sensorConfig.accelScaleFactor[XAXIS], numberString);
    uartPrint(numberString);
    uartPrint(", ");
    ftoa(sensorConfig.accelBias[XAXIS], numberString);
    uartPrint(numberString);
    uartPrint(", ");
    ftoa((noseUp - sensorConfig.accelBias[XAXIS]) * sensorConfig.accelScaleFactor[XAXIS], numberString);
    uartPrint(numberString);
    uartPrint(", ");
    ftoa((noseDown - sensorConfig.accelBias[XAXIS]) * sensorConfig.accelScaleFactor[XAXIS], numberString);
    uartPrint(numberString);
    uartPrint("\n\n");

    ftoa(leftWingDown, numberString);
    uartPrint(numberString);
    uartPrint(", ");
    ftoa(rightWingDown, numberString);
    uartPrint(numberString);
    uartPrint(", ");
    ftoa(sensorConfig.accelScaleFactor[YAXIS], numberString);
    uartPrint(numberString);
    uartPrint(", ");
    ftoa(sensorConfig.accelBias[YAXIS], numberString);
    uartPrint(numberString);
    uartPrint(", ");
    ftoa((leftWingDown - sensorConfig.accelBias[YAXIS]) * sensorConfig.accelScaleFactor[YAXIS], numberString);
    uartPrint(numberString);
    uartPrint(", ");
    ftoa((rightWingDown - sensorConfig.accelBias[YAXIS]) * sensorConfig.accelScaleFactor[YAXIS], numberString);
    uartPrint(numberString);
    uartPrint("\n\n");

    ftoa(upSideDown, numberString);
    uartPrint(numberString);
    uartPrint(", ");
    ftoa(rightSideUp, numberString);
    uartPrint(numberString);
    uartPrint(", ");
    ftoa(sensorConfig.accelScaleFactor[ZAXIS], numberString);
    uartPrint(numberString);
    uartPrint(", ");
    ftoa(sensorConfig.accelBias[ZAXIS], numberString);
    uartPrint(numberString);
    uartPrint(", ");
    ftoa((upSideDown - sensorConfig.accelBias[ZAXIS]) * sensorConfig.accelScaleFactor[ZAXIS], numberString);
    uartPrint(numberString);
    uartPrint(", ");
    ftoa((rightSideUp - sensorConfig.accelBias[ZAXIS]) * sensorConfig.accelScaleFactor[ZAXIS], numberString);
    uartPrint(numberString);
    uartPrint("\n");

    uartPrint("\nAccel Calibration Complete.\n");

    accelCalibrating = false;
}

///////////////////////////////////////////////////////////////////////////////
