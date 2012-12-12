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

/* ------------------------------------------------------------------------------
  File: chr6dm_states.c
  Author: CH Robotics
  Version: 1.0

  Description: Function declarations for CHR-6dm state estimation.
------------------------------------------------------------------------------ */

#pragma once

// Structure for storing AHRS states
typedef struct __AHRS_states {

    // Orientation states
    float psi;
    float theta;
    float phi;

    // Orientation rate states
    float psi_dot;
    float theta_dot;
    float phi_dot;

    // Process noise matrix
    fmat3x3 Q;

    // Measurement noise matrix
    fmat3x3 Racc;
    fmat3x3 Rmag;

    // EKF covariance
    fmat3x3 P;

} AHRS_states;

extern AHRS_states gEstimatedStates;

extern uint8_t EKF_Initialized;

// Function declarations

void EKF_Init(float axSensor, float aySensor, float azSensor, float mxSensor, float mySensor, float mzSensor);

void EKF_Predict(float p, float q, float r, float T);

void EKF_Update(float axSensor, float aySensor, float azSensor, float mxSensor, float mySensor, float mzSensor, float accelCutoff, uint8_t newMagData);
