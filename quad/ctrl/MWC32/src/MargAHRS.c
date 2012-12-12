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

//=====================================================================================================
// AHRS.c
// S.O.H. Madgwick
// 25th August 2010
//
// 1 June 2012 Modified by J. Ihlein
//=====================================================================================================
// Description:
//
// Quaternion implementation of the 'DCM filter' [Mayhony et al].  Incorporates the magnetic distortion
// compensation algorithms from my filter [Madgwick] which eliminates the need for a reference
// direction of flux (bx bz) to be predefined and limits the effect of magnetic distortions to yaw
// axis only.
//
// User must define 'halfT' as the (sample period / 2), and the filter gains 'Kp' and 'Ki'.
//
// Global variables 'q0', 'q1', 'q2', 'q3' are the quaternion elements representing the estimated
// orientation.  See my report for an overview of the use of quaternions in this application.
//
// User must call 'AHRSupdate()' every sample period and parse calibrated gyroscope ('gx', 'gy', 'gz'),
// accelerometer ('ax', 'ay', 'ay') and magnetometer ('mx', 'my', 'mz') data.  Gyroscope units are
// radians/second, accelerometer and magnetometer units are irrelevant as the vector is normalised.
//
//=====================================================================================================

//----------------------------------------------------------------------------------------------------
// Header files

#include "board.h"

//----------------------------------------------------------------------------------------------------
// Variable definitions

float exInt = 0.0f, eyInt = 0.0f, ezInt = 0.0f; // scaled integral error
float exAcc = 0.0f, eyAcc = 0.0f, ezAcc = 0.0f; // accel errors
float exMag = 0.0f, eyMag = 0.0f, ezMag = 0.0f; // mag errors

// auxiliary variables to reduce number of repeated operations
float q0q0, q0q1, q0q2, q0q3;
float q1q1, q1q2, q1q3;
float q2q2, q2q3;
float q3q3;

float halfT;

uint8_t MargAHRSinitialized = false;

//====================================================================================================
// Initialization
//====================================================================================================

void MargAHRSinit(float ax, float ay, float az, float mx, float my, float mz)
{
    float initialRoll, initialPitch;
    float cosRoll, sinRoll, cosPitch, sinPitch;
    float magX, magY;
    float initialHdg, cosHeading, sinHeading;

    initialRoll = atan2(-ay, -az);
    initialPitch = atan2(ax, -az);

    cosRoll = cosf(initialRoll);
    sinRoll = sinf(initialRoll);
    cosPitch = cosf(initialPitch);
    sinPitch = sinf(initialPitch);

    magX = mx * cosPitch + my * sinRoll * sinPitch + mz * cosRoll * sinPitch;

    magY = my * cosRoll - mz * sinRoll;

    initialHdg = atan2f(-magY, magX);

    cosRoll = cosf(initialRoll * 0.5f);
    sinRoll = sinf(initialRoll * 0.5f);

    cosPitch = cosf(initialPitch * 0.5f);
    sinPitch = sinf(initialPitch * 0.5f);

    cosHeading = cosf(initialHdg * 0.5f);
    sinHeading = sinf(initialHdg * 0.5f);

    q0 = cosRoll * cosPitch * cosHeading + sinRoll * sinPitch * sinHeading;
    q1 = sinRoll * cosPitch * cosHeading - cosRoll * sinPitch * sinHeading;
    q2 = cosRoll * sinPitch * cosHeading + sinRoll * cosPitch * sinHeading;
    q3 = cosRoll * cosPitch * sinHeading - sinRoll * sinPitch * cosHeading;

    // auxillary variables to reduce number of repeated operations, for 1st pass
    q0q0 = q0 * q0;
    q0q1 = q0 * q1;
    q0q2 = q0 * q2;
    q0q3 = q0 * q3;
    q1q1 = q1 * q1;
    q1q2 = q1 * q2;
    q1q3 = q1 * q3;
    q2q2 = q2 * q2;
    q2q3 = q2 * q3;
    q3q3 = q3 * q3;
}

//====================================================================================================
// Function
//====================================================================================================

void MargAHRSupdate(float gx, float gy, float gz, float ax, float ay, float az, float mx, float my, float mz, float accelCutoff, uint8_t newMagData, float dt)
{
    float norm;
    float hx, hy, hz, bx, bz;
    float vx, vy, vz, wx, wy, wz;
    float q0i, q1i, q2i, q3i;

    //-------------------------------------------

    if ((MargAHRSinitialized == false) && (newMagData == true))
    {
        MargAHRSinit(ax, ay, az, mx, my, mz);

        MargAHRSinitialized = true;
    }
    //-------------------------------------------

    if (MargAHRSinitialized == true) {
        halfT = dt * 0.5f;

        norm = sqrt(ax * ax + ay * ay + az * az);

        if ((abs(norm - 9.8065) < sensorConfig.accelCutoff) && (norm != 0.0f)) {
            ax = ax / norm;
            ay = ay / norm;
            az = az / norm;

            // estimated direction of gravity (v)
            vx = 2 * (q1q3 - q0q2);
            vy = 2 * (q0q1 + q2q3);
            vz = q0q0 - q1q1 - q2q2 + q3q3;

            exAcc = (vy * az - vz * ay);
            eyAcc = (vz * ax - vx * az);
            ezAcc = (vx * ay - vy * ax);

            exInt += exAcc * sensorConfig.KiAcc;
            eyInt += eyAcc * sensorConfig.KiAcc;
            ezInt += ezAcc * sensorConfig.KiAcc;
        }
        //-------------------------------------------

        norm = sqrt(mx * mx + my * my + mz * mz);

        if ((newMagData == true) && (norm != 0.0f)) {
            mx = mx / norm;
            my = my / norm;
            mz = mz / norm;

            // compute reference direction of flux
            hx = 2 * mx * (0.5 - q2q2 - q3q3) + 2 * my * (q1q2 - q0q3) + 2 * mz * (q1q3 + q0q2);
            hy = 2 * mx * (q1q2 + q0q3) + 2 * my * (0.5 - q1q1 - q3q3) + 2 * mz * (q2q3 - q0q1);
            hz = 2 * mx * (q1q3 - q0q2) + 2 * my * (q2q3 + q0q1) + 2 * mz * (0.5 - q1q1 - q2q2);
            bx = sqrt((hx * hx) + (hy * hy));
            bz = hz;

            // estimated direction of flux (w)
            wx = 2 * bx * (0.5 - q2q2 - q3q3) + 2 * bz * (q1q3 - q0q2);
            wy = 2 * bx * (q1q2 - q0q3) + 2 * bz * (q0q1 + q2q3);
            wz = 2 * bx * (q0q2 + q1q3) + 2 * bz * (0.5 - q1q1 - q2q2);

            exMag = (my * wz - mz * wy);
            eyMag = (mz * wx - mx * wz);
            ezMag = (mx * wy - my * wx);

            exInt += exMag * sensorConfig.KiMag;
            eyInt += eyMag * sensorConfig.KiMag;
            ezInt += ezMag * sensorConfig.KiMag;
        }
        //-------------------------------------------

        // error is sum of cross product between reference direction of fields and direction measured by sensors
        // ex = (ay*vz - az*vy) + (my*wz - mz*wy);
        // ey = (az*vx - ax*vz) + (mz*wx - mx*wz);
        // ez = (ax*vy - ay*vx) + (mx*wy - my*wx);

        // integral error scaled integral gain
        // exInt = exInt + ex * Ki;
        // eyInt = eyInt + ey * Ki;
        // ezInt = ezInt + ez * Ki;

        // adjusted gyroscope measurements
        // gx = gx + Kp * ex + exInt;
        // gy = gy + Kp * ey + eyInt;
        // gz = gz + Kp * ez + ezInt;

        gx = gx + exAcc * sensorConfig.KpAcc + exMag * sensorConfig.KpMag + exInt;
        gy = gy + eyAcc * sensorConfig.KpAcc + eyMag * sensorConfig.KpMag + eyInt;
        gz = gz + ezAcc * sensorConfig.KpAcc + ezMag * sensorConfig.KpMag + ezInt;

        // integrate quaternion rate
        q0i = (-q1 * gx - q2 * gy - q3 * gz) * halfT;
        q1i = (q0 * gx + q2 * gz - q3 * gy) * halfT;
        q2i = (q0 * gy - q1 * gz + q3 * gx) * halfT;
        q3i = (q0 * gz + q1 * gy - q2 * gx) * halfT;
        q0 += q0i;
        q1 += q1i;
        q2 += q2i;
        q3 += q3i;

        // normalise quaternion
        norm = sqrt(q0 * q0 + q1 * q1 + q2 * q2 + q3 * q3);
        q0 = q0 / norm;
        q1 = q1 / norm;
        q2 = q2 / norm;
        q3 = q3 / norm;

        // auxiliary variables to reduce number of repeated operations
        q0q0 = q0 * q0;
        q0q1 = q0 * q1;
        q0q2 = q0 * q2;
        q0q3 = q0 * q3;
        q1q1 = q1 * q1;
        q1q2 = q1 * q2;
        q1q3 = q1 * q3;
        q2q2 = q2 * q2;
        q2q3 = q2 * q3;
        q3q3 = q3 * q3;
    }
}

//====================================================================================================
// END OF CODE
//====================================================================================================
