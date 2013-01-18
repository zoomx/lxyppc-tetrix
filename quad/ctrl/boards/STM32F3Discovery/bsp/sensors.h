#ifndef SENSORS_H
#define SENSORS_H

#include "lsm303dlhc.h"
#include "l3gd20.h"
#define   ACC_SCALE_FACTOR      (0.5f/1000.0f)
//#define   GYRO_SCALE_FACTOR     0.00121414f       //  MPU3050 14.375 LSBs per dps
#define   GYRO_SCALE_FACTOR     (17.5f*PI/180.0f/1000.0f)  //  L3GD20 -FS500 17.50 mdps/digi .. refer to L3G20 RM
//#define   GYRO_SCALE_FACTOR   (70.0f*__PI/180.0f/1000.0f)   //  L3GD20 -FS2000 70 mdps/digi


#define  read_raw_acc(buf)  LSM303DLHC_acc_read(buf)
#define  read_raw_mag(buf)  LSM303DLHC_mag_read(buf)
#define  read_raw_gyro(buf) L3GD20_gyro_read(buf)

#define  compute_gyro_runtime_bias(bias,cnt) L3GD20_compute_gyro_runtime_bias(bias,cnt)
#endif


