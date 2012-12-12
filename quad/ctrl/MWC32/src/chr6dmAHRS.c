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

  Description: Function definitions for CHR-6dm state estimation.
------------------------------------------------------------------------------ */

#include "board.h"

AHRS_states gEstimatedStates;

uint8_t EKF_Initialized = false;

/*******************************************************************************
* Function Name  : EKF_Init
* Input          : None
* Output         : Pre-initialized state estimate structure
* Return         : None
* Description    : Fills an AHRS_states structure with zero initial values.
*******************************************************************************/

void EKF_Init(float axSensor, float aySensor, float azSensor, float mxSensor, float mySensor, float mzSensor)
{
    int i, j;

    float cosRoll, sinRoll, cosPitch, sinPitch;
    float magX, magY;

    gEstimatedStates.phi = atan2f(-aySensor, -azSensor);
    gEstimatedStates.theta = atan2f(axSensor, -azSensor);

    cosRoll = cosf(gEstimatedStates.phi);
    sinRoll = sinf(gEstimatedStates.phi);
    cosPitch = cosf(gEstimatedStates.theta);
    sinPitch = sinf(gEstimatedStates.theta);

    magX = mxSensor * cosPitch + mySensor * sinRoll * sinPitch + mzSensor * cosRoll * sinPitch;

    magY = mySensor * cosRoll - mzSensor * sinRoll;

    gEstimatedStates.psi = atan2f(-magY, magX);

    gEstimatedStates.phi_dot = 0.0f;
    gEstimatedStates.theta_dot = 0.0f;
    gEstimatedStates.psi_dot = 0.0f;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            gEstimatedStates.P.data[i][j] = 0.0f;
            gEstimatedStates.Q.data[i][j] = 0.0f;
            gEstimatedStates.Racc.data[i][j] = 0.0f;
            gEstimatedStates.Rmag.data[i][j] = 0.0f;

            if (i == j) {
                gEstimatedStates.P.data[i][j] = sensorConfig.processVariance;
                gEstimatedStates.Q.data[i][j] = sensorConfig.processVariance;
                gEstimatedStates.Racc.data[i][j] = sensorConfig.accelVariance;
                gEstimatedStates.Rmag.data[i][j] = sensorConfig.magVariance;
            }
        }
    }

    EKF_Initialized = true;
}

/*******************************************************************************
* Function Name  : unroll_states
* Input          : AHRS_states* states
* Output         : None
* Return         : None
* Description    : Keeps all angle estimates in the range of -360 to 360 degrees
*******************************************************************************/

void unroll_states(void)
{
    while (gEstimatedStates.phi > PI)
        gEstimatedStates.phi -= TWO_PI;
    while (gEstimatedStates.phi < -PI)
        gEstimatedStates.phi += TWO_PI;

    while (gEstimatedStates.theta > PI)
        gEstimatedStates.theta -= TWO_PI;
    while (gEstimatedStates.theta < -PI)
        gEstimatedStates.theta += TWO_PI;

    while (gEstimatedStates.psi > PI)
        gEstimatedStates.psi -= TWO_PI;
    while (gEstimatedStates.psi < -PI)
        gEstimatedStates.psi += TWO_PI;
}

/*******************************************************************************
* Function Name  : EKF_Predict
* Input          : AHRS_states* estimated_states, RawSensorData* sensor_data
* Output         : None
* Return         : None
* Description    : EKF prediction step.  Uses rate gyros to make new orientation
						 estimate.
*******************************************************************************/

void EKF_Predict(float p, float q, float r, float T)
{
    float cos_phi, sin_phi, cos_theta, sin_theta, tan_theta;
    fmat3x3 A, A_transpose, AP, PA_transpose, temp;

    cos_phi = cos(gEstimatedStates.phi);
    sin_phi = sin(gEstimatedStates.phi);
    cos_theta = cos(gEstimatedStates.theta);
    sin_theta = sin(gEstimatedStates.theta);
    tan_theta = tan(gEstimatedStates.theta);

    // Compute expected angle rates based on gyro outputs.  Note that to do this, the measured rotations
    // must be transformed into the inertial frame (we can't just integrate the gyro outputs).
    gEstimatedStates.phi_dot = p + sin_phi * tan_theta * q + cos_phi * tan_theta * r;
    gEstimatedStates.theta_dot = cos_phi * q - sin_phi * r;
    gEstimatedStates.psi_dot = (sin_phi / cos_theta) * q + (cos_phi / cos_theta) * r;

    // Compute new angle estimates
    gEstimatedStates.phi += T * gEstimatedStates.phi_dot;
    gEstimatedStates.theta += T * gEstimatedStates.theta_dot;
    gEstimatedStates.psi += T * gEstimatedStates.psi_dot;

    // Linearize propogation equation for covariance estimation (build the matrix A)
    /*
       [     q*cos(phi)*tan(theta) - r*sin(phi)*tan(theta),               r*cos(phi)*(tan(theta)^2 + 1) + q*sin(phi)*(tan(theta)^2 + 1), 0]
       [                         - r*cos(phi) - q*sin(phi),                                                                           0, 0]
       [ (q*cos(phi))/cos(theta) - (r*sin(phi))/cos(theta), (r*cos(phi)*sin(theta))/cos(theta)^2 + (q*sin(phi)*sin(theta))/cos(theta)^2, 0]
     */

    A.data[0][0] = q * cos_phi * tan_theta - r * sin_phi * tan_theta;
    A.data[0][1] = r * cos_phi * (tan_theta * tan_theta + 1) + q * sin_phi * (tan_theta * tan_theta + 1);
    A.data[0][2] = 0.0f;

    A.data[1][0] = -r * cos_phi - q * sin_phi;
    A.data[1][1] = 0.0f;
    A.data[1][2] = 0.0f;

    A.data[2][0] = (q * cos_phi) / cos_theta - (r * sin_phi) / cos_theta;
    A.data[2][1] = (r * cos_phi * sin_theta) / (cos_theta * cos_theta) + (q * sin_phi * sin_theta) / (cos_theta * cos_theta);
    A.data[2][2] = 0.0f;

    // Compute new covariance: P = P + T*(AP + PA^T + Q)
    MatMult3x3(&A, &gEstimatedStates.P, &AP);
    MatTrans3x3(&A, &A_transpose);
    MatMult3x3(&gEstimatedStates.P, &A_transpose, &PA_transpose);
    MatAdd3x3(&AP, &PA_transpose, &temp);
    MatAdd3x3(&temp, &gEstimatedStates.Q, &temp);
    ScalarMatMult3x3(T, &temp, &temp);
    MatAdd3x3(&temp, &gEstimatedStates.P, &gEstimatedStates.P);

    unroll_states();
}

/*******************************************************************************
* Function Name  : EKF_Update
* Input          : AHRS_states* estimated_states, RawSensorData* sensor_data
* Output         : None
* Return         : None
* Description    : EKF update step.  Uses accels to correct pitch and roll errors,
						 and magnetic sensors to correct yaw errors.  Compensation is
						 only applied when new data is available, as specified by the
						 new_mag_data and new_accel_data flags in the sensor_data structure.
*******************************************************************************/

void EKF_Update(float axSensor, float aySensor, float azSensor, float mxSensor, float mySensor, float mzSensor, float accelCutoff, uint8_t newMagData)
{
    float accelMagnitude;
    float cos_phi, cos_theta, cos_psi;
    float sin_phi, sin_theta, sin_psi;
    fmat3x3 R, L, C, Ctrans, PCtrans, LC, temp, I;
    fvect3x1 accel_ref;
    float ax, ay, az;
    fvect3x1 acc_hat;
    fvect3x1 acc_vect, correction;
    fvect3x1 mag_ref;
    float mx, my, mz;
    fvect3x1 mag_vect;

    CreateIdentity3x3(&I);

    accelMagnitude = sqrtf(axSensor * axSensor + aySensor * aySensor + azSensor * azSensor);

    if (fabs(accelMagnitude - 9.8065) < accelCutoff) {
        cos_phi = cos(gEstimatedStates.phi);
        cos_theta = cos(gEstimatedStates.theta);
        cos_psi = cos(gEstimatedStates.psi);

        sin_phi = sin(gEstimatedStates.phi);
        sin_theta = sin(gEstimatedStates.theta);
        sin_psi = sin(gEstimatedStates.psi);

        // Build rotation matrix from inertial frame to body frame (for computing expected sensor outputs given yaw, pitch, and roll angles)
        /*
           [                              cos(psi)*cos(theta),                              cos(theta)*sin(psi),         -sin(theta)]
           [ cos(psi)*sin(phi)*sin(theta) - cos(phi)*sin(psi), cos(phi)*cos(psi) + sin(phi)*sin(psi)*sin(theta), cos(theta)*sin(phi)]
           [ sin(phi)*sin(psi) + cos(phi)*cos(psi)*sin(theta), cos(phi)*sin(psi)*sin(theta) - cos(psi)*sin(phi), cos(phi)*cos(theta)]
         */

        R.data[0][0] = cos_psi * cos_theta;
        R.data[0][1] = cos_theta * sin_psi;
        R.data[0][2] = -sin_theta;

        R.data[1][0] = cos_psi * sin_phi * sin_theta - cos_phi * sin_psi;
        R.data[1][1] = cos_phi * cos_psi + sin_phi * sin_psi * sin_theta;
        R.data[1][2] = cos_theta * sin_phi;

        R.data[2][0] = sin_phi * sin_psi + cos_phi * cos_psi * sin_theta;
        R.data[2][1] = cos_phi * sin_psi * sin_theta - cos_psi * sin_phi;
        R.data[2][2] = cos_phi * cos_theta;

        accel_ref.data[0] = sensorConfig.accelRefVector[XAXIS];
        accel_ref.data[1] = sensorConfig.accelRefVector[YAXIS];
        accel_ref.data[2] = sensorConfig.accelRefVector[ZAXIS];

        ax = accel_ref.data[0];
        ay = accel_ref.data[1];
        az = accel_ref.data[2];

        // Compute expected accelerometer output based on yaw, pitch, and roll angles
        MatVectMult3(&R, &accel_ref, &acc_hat);

        // Compute C matrix for Kalman gain calculation
        /*
           [                                                                                                                                      0,                          - az*cos(theta) - ax*cos(psi)*sin(theta) - ay*sin(psi)*sin(theta),                                                                 ay*cos(psi)*cos(theta) - ax*cos(theta)*sin(psi)]
           [ ax*(sin(phi)*sin(psi) + cos(phi)*cos(psi)*sin(theta)) - ay*(cos(psi)*sin(phi) - cos(phi)*sin(psi)*sin(theta)) + az*cos(phi)*cos(theta), ax*cos(psi)*cos(theta)*sin(phi) - az*sin(phi)*sin(theta) + ay*cos(theta)*sin(phi)*sin(psi), - ax*(cos(phi)*cos(psi) + sin(phi)*sin(psi)*sin(theta)) - ay*(cos(phi)*sin(psi) - cos(psi)*sin(phi)*sin(theta))]
           [ ax*(cos(phi)*sin(psi) - cos(psi)*sin(phi)*sin(theta)) - ay*(cos(phi)*cos(psi) + sin(phi)*sin(psi)*sin(theta)) - az*cos(theta)*sin(phi), ax*cos(phi)*cos(psi)*cos(theta) - az*cos(phi)*sin(theta) + ay*cos(phi)*cos(theta)*sin(psi),   ax*(cos(psi)*sin(phi) - cos(phi)*sin(psi)*sin(theta)) + ay*(sin(phi)*sin(psi) + cos(phi)*cos(psi)*sin(theta))]
         */

        C.data[0][0] = 0.0f;
        C.data[0][1] = -az * cos_theta - ax * cos_psi * sin_theta - ay * sin_psi * sin_theta;
        C.data[0][2] = ay * cos_psi * cos_theta - ax * cos_theta * sin_psi;

        C.data[1][0] = ax * (sin_phi * sin_psi + cos_phi * cos_psi * sin_theta) - ay * (cos_psi * sin_phi - cos_phi * sin_psi * sin_theta) + az * cos_phi * cos_theta;
        C.data[1][1] = ax * cos_psi * cos_theta * sin_phi - az * sin_phi * sin_theta + ay * cos_theta * sin_phi * sin_psi;
        C.data[1][2] = -ax * (cos_phi * cos_psi + sin_phi * sin_psi * sin_theta) - ay * (cos_phi * sin_psi - cos_psi * sin_phi * sin_theta);

        C.data[2][0] = ax * (cos_phi * sin_psi - cos_psi * sin_phi * sin_theta) - ay * (cos_phi * cos_psi + sin_phi * sin_psi * sin_theta) - az * cos_theta * sin_phi;
        C.data[2][1] = ax * cos_phi * cos_psi * cos_theta - az * cos_phi * sin_theta + ay * cos_phi * cos_theta * sin_psi;
        C.data[2][2] = ax * (cos_psi * sin_phi - cos_phi * sin_psi * sin_theta) + ay * (sin_phi * sin_psi + cos_phi * cos_psi * sin_theta);

        // Compute Kalman gain: L = PC^T * (R + CPC^T)^(-1)
        MatTrans3x3(&C, &Ctrans);
        MatMult3x3(&gEstimatedStates.P, &Ctrans, &PCtrans);
        MatMult3x3(&C, &PCtrans, &temp);
        MatAdd3x3(&temp, &gEstimatedStates.Racc, &temp);
        MatInv3x3(&temp, &temp);
        MatMult3x3(&PCtrans, &temp, &L);

        // Compute new covariance
        MatMult3x3(&L, &C, &LC);
        ScalarMatMult3x3(-1.0f, &LC, &temp);
        MatAdd3x3(&I, &temp, &temp);
        MatMult3x3(&temp, &gEstimatedStates.P, &gEstimatedStates.P);

        acc_vect.data[0] = axSensor;
        acc_vect.data[1] = aySensor;
        acc_vect.data[2] = azSensor;

        // Now subtract the reference vector
        acc_vect.data[0] = acc_vect.data[0] - acc_hat.data[0];
        acc_vect.data[1] = acc_vect.data[1] - acc_hat.data[1];
        acc_vect.data[2] = acc_vect.data[2] - acc_hat.data[2];

        // Multiply by Kalman gain
        MatVectMult3(&L, &acc_vect, &correction);

        // Apply correction
        gEstimatedStates.phi += correction.data[0];
        gEstimatedStates.theta += correction.data[1];
        gEstimatedStates.psi += correction.data[2];

        // "Unroll" angle estimates to be in the range from -PI to PI radians
        unroll_states();
    }
    // If new magnetometer data is available, perform update
    if (newMagData == true) {
        cos_phi = cos(gEstimatedStates.phi);
        cos_theta = cos(gEstimatedStates.theta);
        cos_psi = cos(gEstimatedStates.psi);

        sin_phi = sin(gEstimatedStates.phi);
        sin_theta = sin(gEstimatedStates.theta);
        sin_psi = sin(gEstimatedStates.psi);

        // Compute magnetic field reference vector
        mag_ref.data[0] = sensorConfig.magRefVector[XAXIS];
        mag_ref.data[1] = sensorConfig.magRefVector[YAXIS];
        mag_ref.data[2] = sensorConfig.magRefVector[ZAXIS];

        // Compute C based on magnetic field data in inertial frame
        mx = mag_ref.data[0];
        my = mag_ref.data[1];
        mz = mag_ref.data[2];

        C.data[0][0] = 0.0f;
        C.data[0][1] = 0.0f;
        C.data[0][2] = my * cos_psi - mx * sin_psi;

        C.data[1][0] = 0.0f;
        C.data[1][1] = 0.0f;
        C.data[1][2] = -mx * cos_psi - my * sin_psi;

        C.data[2][0] = 0.0f;
        C.data[2][1] = 0.0f;
        C.data[2][2] = 0.0f;

        // Rotate reference vector into vehicle-1 frame
        R.data[0][0] = cos_psi;
        R.data[0][1] = sin_psi;
        R.data[0][2] = 0.0f;

        R.data[1][0] = -sin_psi;
        R.data[1][1] = cos_psi;
        R.data[1][2] = 0.0f;

        R.data[2][0] = 0.0f;
        R.data[2][1] = 0.0f;
        R.data[2][2] = 1.0f;

        MatVectMult3(&R, &mag_ref, &mag_ref);

        // Get magnetic field measurement
        mag_vect.data[0] = mxSensor;
        mag_vect.data[1] = mySensor;
        mag_vect.data[2] = mzSensor;

        // Build rotation matrix from body frame to vehicle-1 frame (ie. only yaw remains uncorrected)
        /*
           [  cos(theta), sin(phi)*sin(theta), cos(phi)*sin(theta)]
           [           0,            cos(phi),           -sin(phi)]
           [ -sin(theta), cos(theta)*sin(phi), cos(phi)*cos(theta)]
         */

        R.data[0][0] = cos_theta;
        R.data[0][1] = sin_phi * sin_theta;
        R.data[0][2] = cos_phi * sin_theta;

        R.data[1][0] = 0.0f;
        R.data[1][1] = cos_phi;
        R.data[1][2] = -sin_phi;

        R.data[2][0] = -sin_theta;
        R.data[2][1] = cos_theta * sin_phi;
        R.data[2][2] = cos_phi * cos_theta;

        // Rotate measurement into vehicle-1 frame
        MatVectMult3(&R, &mag_vect, &mag_vect);

        // Subtract reference vector
        mag_vect.data[0] = mag_vect.data[0] - mag_ref.data[0];
        mag_vect.data[1] = mag_vect.data[1] - mag_ref.data[1];
        mag_vect.data[2] = mag_vect.data[2] - mag_ref.data[2];

        // Compute Kalman gain: L = PC^T * (R + CPC^T)^(-1)
        MatTrans3x3(&C, &Ctrans);
        MatMult3x3(&gEstimatedStates.P, &Ctrans, &PCtrans);
        MatMult3x3(&C, &PCtrans, &temp);
        MatAdd3x3(&temp, &gEstimatedStates.Rmag, &temp);
        MatInv3x3(&temp, &temp);
        MatMult3x3(&PCtrans, &temp, &L);

        // Compute new covariance
        MatMult3x3(&L, &C, &LC);
        ScalarMatMult3x3(-1.0f, &LC, &temp);
        MatAdd3x3(&I, &temp, &temp);
        MatMult3x3(&temp, &gEstimatedStates.P, &gEstimatedStates.P);

        // Perform state update
        MatVectMult3(&L, &mag_vect, &correction);

        gEstimatedStates.phi += correction.data[0];
        gEstimatedStates.theta += correction.data[1];
        gEstimatedStates.psi += correction.data[2];

        // "Unroll" angle estimates to be in the range from -PI to PI radians
        unroll_states();
    }
}
