#ifndef ALG_TYPES_H
#define ALG_TYPES_H
#include "stdint.h"

#define  Gravity 9.8065f
#define  PI     3.14159265f
#define  PIx2   6.28318531f

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

#endif

