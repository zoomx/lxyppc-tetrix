#include "alg_types.h"
#include "sensors.h"
#include "alg_setup.h"

sensorConfig_t sensorConfig;

void init_sensor_config(void)
{
    // Default settings
    sensorConfig.version = 0x01;
    
    ///////////////////////////////
    
    sensorConfig.accelBias[XAXIS] = 0.0f;
    sensorConfig.accelBias[YAXIS] = 0.0f;
    sensorConfig.accelBias[ZAXIS] = 0.0f;
    
    ///////////////////////////////
    
    sensorConfig.accelScaleFactor[XAXIS] = ACC_SCALE_FACTOR; //Gravity / 2048.0f;
    sensorConfig.accelScaleFactor[YAXIS] = ACC_SCALE_FACTOR; //Gravity / 2048.0f;
    sensorConfig.accelScaleFactor[ZAXIS] = ACC_SCALE_FACTOR; //Gravity / 2048.0f;
    
    ///////////////////////////////
    
    sensorConfig.gyroTCBiasSlope[ROLL ] = 0.0f;
    sensorConfig.gyroTCBiasSlope[PITCH] = 0.0f;
    sensorConfig.gyroTCBiasSlope[YAW  ] = 0.0f;
    
    ///////////////////////////////

    sensorConfig.gyroTCBiasIntercept[ROLL ] = 0.0f;
    sensorConfig.gyroTCBiasIntercept[PITCH] = 0.0f;
    sensorConfig.gyroTCBiasIntercept[YAW  ] = 0.0f;

    ///////////////////////////////

    sensorConfig.magBias[XAXIS] = 0.0f;
    sensorConfig.magBias[YAXIS] = 0.0f;
    sensorConfig.magBias[ZAXIS] = 0.0f;

    ///////////////////////////////

    sensorConfig.accelCutoff = 1.0f;

    ///////////////////////////////

    sensorConfig.beta = 0.1f;

    ///////////////////////////////

    sensorConfig.KpAcc = 2.0f;    // proportional gain governs rate of convergence to accelerometer
    sensorConfig.KiAcc = 0.005f;  // integral gain governs rate of convergence of gyroscope biases
    sensorConfig.KpMag = 2.0f;    // proportional gain governs rate of convergence to magnetometer
    sensorConfig.KiMag = 0.005f;  // integral gain governs rate of convergence of gyroscope biases

    ///////////////////////////////

    sensorConfig.accelVariance = 2.0f;

    sensorConfig.magVariance = 2.0f;

    sensorConfig.processVariance = 0.1f;

    sensorConfig.accelRefVector[XAXIS] =  0.0f;
    sensorConfig.accelRefVector[YAXIS] =  0.0f;
    sensorConfig.accelRefVector[ZAXIS] = -Gravity;

    sensorConfig.magRefVector[XAXIS] = 255.0f;
    sensorConfig.magRefVector[YAXIS] = 0.0f;
    sensorConfig.magRefVector[ZAXIS] = 666.0f;

}


