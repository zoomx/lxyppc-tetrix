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

#pragma once

///////////////////////////////////////////////////////////////////////////////

//#define USE_ACCEL_RT_BIAS

//#define USE_MADGWICK_AHRS

#define USE_MARG_AHRS

//#define USE_CHR6DM_AHRS

#if !defined(USE_MADGWICK_AHRS) && !defined(USE_MARG_AHRS) && !defined(USE_CHR6DM_AHRS)
#error Define AHRS!!!
#endif

///////////////////////////////////////////////////////////////////////////////

#define     PI 3.14159265f
#define TWO_PI 6.28318531f

///////////////////////////////////////////////////////////////////////////////

#define ROLL     0
#define PITCH    1
#define YAW      2
#define THROTTLE 3
#define AUX1     4
#define AUX2     5
#define AUX3     6
#define AUX4     7

#define XAXIS    0
#define YAXIS    1
#define ZAXIS    2

#define MINCOMMAND  2000
#define MIDCOMMAND  3000
#define MAXCOMMAND  4000

///////////////////////////////////////////////////////////////////////////////
// Misc Type Definitions
///////////////////////////////////////////////////////////////////////////////

typedef union {
    int16_t value;
    uint8_t bytes[2];
} int16andUint8_t;

typedef union {
    int32_t value;
    uint8_t bytes[4];
} int32andUint8_t;

typedef union {
    uint16_t value;
    uint8_t bytes[2];
} uint16andUint8_t;

///////////////////////////////////////////////////////////////////////////////
// Sensor Variables
///////////////////////////////////////////////////////////////////////////////

typedef struct sensors_t {
    float accel200Hz[3];
    float accel100Hz[3];
    float attitude200Hz[3];
    float gyro500Hz[3];
    float gyro200Hz[3];
    float gyro100Hz[3];
    float mag10Hz[3];
    float pressureAltitude10Hz;

} sensors_t;

extern sensors_t sensors;

///////////////////////////////////////////////////////////////////////////////
// PID Definitions
///////////////////////////////////////////////////////////////////////////////

#define NUMBER_OF_PIDS 6

#define ROLL_RATE_PID  0
#define PITCH_RATE_PID 1
#define YAW_RATE_PID   2

#define ROLL_ATT_PID   3
#define PITCH_ATT_PID  4
#define HEADING_PID    5

///////////////////////////////////////////////////////////////////////////////
// MultiCopter Configurations
///////////////////////////////////////////////////////////////////////////////

typedef enum MultiType {
    MULTITYPE_TRI = 1,
    MULTITYPE_QUADP = 2,
    MULTITYPE_QUADX = 3,
    MULTITYPE_BI = 4,
    MULTITYPE_GIMBAL = 5,
    MULTITYPE_Y6 = 6,
    MULTITYPE_HEX6P = 7,
    MULTITYPE_Y4 = 9,
    MULTITYPE_HEX6X = 10,
    MULTITYPE_VTAIL4 = 17,
    MULTITYPE_FREEMIX = 18,
    MULTITYPE_FLYING_WING = 21
} MultiType;

///////////////////////////////////////////////////////////////////////////////
// EEPROM
///////////////////////////////////////////////////////////////////////////////

typedef struct sensorConfig_t {
    uint8_t version;

    float accelBias[3];
    float accelScaleFactor[3];

    float gyroTCBiasSlope[3];
    float gyroTCBiasIntercept[3];

    float magBias[3];

    float accelCutoff;

    // For Madgwick AHRS

    float beta;

    // For MARG AHRS

    float KpAcc;

    float KiAcc;

    float KpMag;

    float KiMag;

    // For CHR6DM AHRS

    float accelVariance;

    float magVariance;

    float processVariance;

    float accelRefVector[3];

    float magRefVector[3];

} sensorConfig_t;

extern sensorConfig_t sensorConfig;

///////////////////////////////////////

typedef struct systemConfig_t {
    uint8_t version;

    uint8_t useSerialPWMflag;

    uint8_t rcMap[8];

    uint16_t escPwmRate;
    uint16_t servoPwmRate;

    uint8_t mixerConfiguration;
    float yawDirection;

    float midCommand;
    float minCheck;
    float maxCheck;
    float minThrottle;
    float maxThrottle;

    PIDdata_t PID[NUMBER_OF_PIDS];

    float biLeftServoMin;
    float biLeftServoMid;
    float biLeftServoMax;

    float biRightServoMin;
    float biRightServoMid;
    float biRightServoMax;

    float triYawServoMin;
    float triYawServoMid;
    float triYawServoMax;

    float gimbalRollServoMin;
    float gimbalRollServoMid;
    float gimbalRollServoMax;
    float gimbalRollServoGain;

    float gimbalPitchServoMin;
    float gimbalPitchServoMid;
    float gimbalPitchServoMax;
    float gimbalPitchServoGain;

    uint8_t freeMixMotors;

    float freeMix[6][3];

    float rollDirectionLeft;
    float rollDirectionRight;
    float pitchDirectionLeft;
    float pitchDirectionRight;
    float wingLeftMinimum;
    float wingLeftMaximum;
    float wingRightMinimum;
    float wingRightMaximum;

} systemConfig_t;

extern systemConfig_t systemConfig;

///////////////////////////////////////////////////////////////////////////////
