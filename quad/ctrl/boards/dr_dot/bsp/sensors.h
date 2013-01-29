#ifndef SENSORS_H
#define SENSORS_H

#include "mpu6050.h"
#include "hmc5883.h"
#define   ACC_SCALE_FACTOR      (0.5f/1000.0f)
#ifndef GYRO_SCALE_FACTOR
#define   GYRO_SCALE_FACTOR     0.00121414f       //  MPU3050 14.375 LSBs per dps
#endif
//#define   GYRO_SCALE_FACTOR     (17.5f*PI/180.0f/1000.0f)  //  L3GD20 -FS500 17.50 mdps/digi .. refer to L3G20 RM
//#define   GYRO_SCALE_FACTOR   (70.0f*__PI/180.0f/1000.0f)   //  L3GD20 -FS2000 70 mdps/digi


#define  read_raw_acc(buf)  MPU6050_acc_read(buf)
#define  read_raw_mag(buf)  HMC5883_mag_read(buf)
#define  read_raw_gyro(buf) MPU6050_gyro_read(buf)
#define  read_raw_pressure(buf) BMP085_pressure_read(buf)

#define  compute_gyro_runtime_bias(bias,cnt) MPU6050_compute_gyro_runtime_bias(bias,cnt)

// convert raw sensor data to the algorithm need type
void board_2_flight_gyro(float* gyro, int32_t *raw);
void board_2_flight_acc(float* acc, int32_t *raw);
void board_2_flight_mag(float* mag, int32_t *raw);

#endif


