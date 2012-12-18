/* Automatically generated from /home/iwow/work/paparazzi/paparazzi/conf/messages.xml */
/* Please DO NOT EDIT */
/* Macros to send and receive messages of class telemetry */
#ifndef _VAR_MESSAGES2_telemetry_H_
#define _VAR_MESSAGES2_telemetry_H_
#include "downlink_transport.h"
#ifdef DOWNLINK
#define DL_BOOT 1
#define DL_ALIVE 2
#define DL_PONG 3
#define DL_TAKEOFF 4
#define DL_ATTITUDE 6
#define DL_IR_SENSORS 7
#define DL_GPS 8
#define DL_NAVIGATION_REF 9
#define DL_NAVIGATION 10
#define DL_PPRZ_MODE 11
#define DL_BAT 12
#define DL_DEBUG_MCU_LINK 13
#define DL_CALIBRATION 14
#define DL_SETTINGS 15
#define DL_DESIRED 16
#define DL_GPS_SOL 17
#define DL_ADC_GENERIC 18
#define DL_TEST_FORMAT 19
#define DL_CAM 20
#define DL_CIRCLE 21
#define DL_SEGMENT 22
#define DL_DOWNLINK_STATUS 23
#define DL_MODEM_STATUS 24
#define DL_SVINFO 25
#define DL_DEBUG 26
#define DL_SURVEY 27
#define DL_WC_RSSI 28
#define DL_RANGEFINDER 29
#define DL_DOWNLINK 30
#define DL_DL_VALUE 31
#define DL_MARK 32
#define DL_SYS_MON 33
#define DL_MOTOR 34
#define DL_WP_MOVED 35
#define DL_ENERGY 37
#define DL_BARO_BMP85_CALIB 38
#define DL_BARO_BMP85 39
#define DL_SPEED_LOOP 40
#define DL_ALT_KALMAN 41
#define DL_ESTIMATOR 42
#define DL_TUNE_ROLL 43
#define DL_BARO_MS5534A 44
#define DL_PRESSURE 45
#define DL_BARO_WORDS 46
#define DL_WP_MOVED_LLA 47
#define DL_CHRONO 48
#define DL_WP_MOVED_ENU 49
#define DL_WINDTURBINE_STATUS_ 50
#define DL_RC_3CH_ 51
#define DL_MPPT 52
#define DL_DEBUG_IR_I2C 53
#define DL_AIRSPEED 54
#define DL_XSENS 55
#define DL_BARO_ETS 56
#define DL_AIRSPEED_ETS 57
#define DL_PBN 58
#define DL_GPS_LLA 59
#define DL_H_CTL_A 60
#define DL_TURB_PRESSURE_RAW 61
#define DL_TURB_PRESSURE_VOLTAGE 62
#define DL_CAM_POINT 63
#define DL_DC_INFO 64
#define DL_AMSYS_BARO 65
#define DL_AMSYS_AIRSPEED 66
#define DL_FLIGHT_BENCHMARK 67
#define DL_AOA_adc 69
#define DL_XTEND_RSSI 70
#define DL_VF_UPDATE 76
#define DL_VF_PREDICT 77
#define DL_CROSS_TRACK_ERROR 80
#define DL_GENERIC_COM 81
#define DL_FORMATION_SLOT_TM 82
#define DL_FORMATION_STATUS_TM 83
#define DL_BMP_STATUS 84
#define DL_MLX_STATUS 85
#define DL_TMP_STATUS 86
#define DL_WIND_INFO_RET 87
#define DL_SCP_STATUS 88
#define DL_SHT_STATUS 89
#define DL_ENOSE_STATUS 90
#define DL_DPICCO_STATUS 91
#define DL_ANTENNA_DEBUG 92
#define DL_ANTENNA_STATUS 93
#define DL_MOTOR_BENCH_STATUS 94
#define DL_MOTOR_BENCH_STATIC 95
#define DL_HIH_STATUS 96
#define DL_TEMT_STATUS 97
#define DL_GP2Y_STATUS 98
#define DL_SHT_I2C_SERIAL 99
#define DL_PPM 100
#define DL_RC 101
#define DL_COMMANDS 102
#define DL_FBW_STATUS 103
#define DL_ADC 104
#define DL_ACTUATORS 105
#define DL_BETH 106
#define DL_BETH_ESTIMATOR 107
#define DL_BETH_CONTROLLER 108
#define DL_BETH_CONTROLLER_TWIST 109
#define DL_DC_SHOT 110
#define DL_TEST_BOARD_RESULTS 111
#define DL_BETH_CONTROLLER_SFB 112
#define DL_MLX_SERIAL 113
#define DL_PAYLOAD 114
#define DL_HTM_STATUS 115
#define DL_BARO_MS5611 116
#define DL_MS5611_COEFF 117
#define DL_ATMOSPHERE_CHARGE 118
#define DL_SOLAR_RADIATION 119
#define DL_TCAS_TA 120
#define DL_TCAS_RA 121
#define DL_TCAS_RESOLVED 122
#define DL_TCAS_DEBUG 123
#define DL_POTENTIAL 124
#define DL_VERTICAL_ENERGY 125
#define DL_TEMP_TCOUPLE 126
#define DL_SHT_I2C_STATUS 127
#define DL_CAMERA_SNAPSHOT 128
#define DL_TIMESTAMP 129
#define DL_STAB_ATTITUDE_FLOAT 130
#define DL_IMU_GYRO_SCALED 131
#define DL_IMU_ACCEL_SCALED 132
#define DL_IMU_MAG_SCALED 133
#define DL_FILTER 134
#define DL_FILTER2 135
#define DL_RATE_LOOP 136
#define DL_FILTER_ALIGNER 137
#define DL_FILTER_COR 139
#define DL_STAB_ATTITUDE_INT 140
#define DL_STAB_ATTITUDE_REF_INT 141
#define DL_STAB_ATTITUDE_REF_FLOAT 142
#define DL_ROTORCRAFT_CMD 143
#define DL_GUIDANCE 144
#define DL_VERT_LOOP 145
#define DL_HOVER_LOOP 146
#define DL_ROTORCRAFT_FP 147
#define DL_BOOZ2_FMS_INFO 148
#define DL_GUIDANCE_H_REF_INT 149
#define DL_ROTORCRAFT_TUNE_HOVER 150
#define DL_INS_Z 151
#define DL_PCAP01_STATUS 152
#define DL_GEIGER_COUNTER 153
#define DL_INS_REF 154
#define DL_GPS_INT 155
#define DL_AHRS_EULER_INT 156
#define DL_AHRS_QUAT_INT 157
#define DL_AHRS_RMAT_INT 158
#define DL_ROTORCRAFT_NAV_STATUS 159
#define DL_ROTORCRAFT_RADIO_CONTROL 160
#define DL_VFF 162
#define DL_BOOZ2_TUNE_FF 163
#define DL_HFF 164
#define DL_HFF_DBG 165
#define DL_HFF_GPS 166
#define DL_BOOZ2_SONAR 167
#define DL_BOOZ2_CAM 168
#define DL_AHRS_REF_QUAT 169
#define DL_EKF7_XHAT 170
#define DL_EKF7_Y 171
#define DL_EKF7_P_DIAG 172
#define DL_AHRS_EULER 173
#define DL_AHRS_MEASUREMENT_EULER 174
#define DL_WT 175
#define DL_CSC_CAN_DEBUG 176
#define DL_CSC_CAN_MSG 177
#define DL_AHRS_GYRO_BIAS_INT 178
#define DL_FMS_TIME 180
#define DL_LOADCELL 181
#define DL_FLA_DEBUG 182
#define DL_BLMC_FAULT_STATUS 183
#define DL_BLMC_SPEEDS 184
#define DL_AHRS_DEBUG_QUAT 185
#define DL_BLMC_BUSVOLTS 186
#define DL_SYSTEM_STATUS 187
#define DL_DYNAMIXEL 188
#define DL_RMAT_DEBUG 189
#define DL_SIMPLE_COMMANDS 190
#define DL_VANE_SENSOR 191
#define DL_CONTROLLER_GAINS 192
#define DL_AHRS_LKF 193
#define DL_AHRS_LKF_DEBUG 194
#define DL_AHRS_LKF_ACC_DBG 195
#define DL_AHRS_LKF_MAG_DBG 196
#define DL_NPS_SENSORS_SCALED 197
#define DL_INS 198
#define DL_GPS_ERROR 199
#define DL_IMU_GYRO 200
#define DL_IMU_MAG 201
#define DL_IMU_ACCEL 202
#define DL_IMU_GYRO_RAW 203
#define DL_IMU_ACCEL_RAW 204
#define DL_IMU_MAG_RAW 205
#define DL_IMU_MAG_SETTINGS 206
#define DL_IMU_GYRO_LP 209
#define DL_IMU_PRESSURE 210
#define DL_IMU_HS_GYRO 211
#define DL_TEST_PASSTHROUGH_STATUS 212
#define DL_WEATHER 219
#define DL_IMU_TURNTABLE 220
#define DL_BARO_RAW 221
#define DL_TIME 227
#define DL_ROTORCRAFT_STATUS 231
#define DL_STATE_FILTER_STATUS 232
#define DL_OPTICFLOW 234
#define DL_VISUALTARGET 235
#define DL_NPS_POS_LLH 238
#define DL_NPS_RPMS 239
#define DL_NPS_SPEED_POS 240
#define DL_NPS_RATE_ATTITUDE 241
#define DL_NPS_GYRO_BIAS 242
#define DL_NPS_RANGE_METER 243
#define DL_NPS_WIND 244
#define DL_BOOZ_DEBUG_FOO 245
#define DL_BOOZ_MAX1167_ERR 246
#define DL_PPRZ_DEBUG 247
#define DL_NPS_ACCEL_LTP 248
#define DL_LOOSE_INS_GPS 249
#define DL_AFL_COEFFS 250
#define DL_BOOZ_ATT_REF_MODEL 251
#define DL_BOOZ2_FF_ADAP 252
#define DL_I2C_ERRORS 253
#define DL_RDYB_TRAJECTORY 254
#define DL_HENRY_GNSS 255
#define DL_MSG_telemetry_NB 223

#define MSG_telemetry_LENGTHS {0,(2+0+2),(2+0+1+nb_md5sum*1),(2+0),(2+0+2),0,(2+0+4+4+4),(2+0+2+2+2+2+2),(2+0+1+4+4+2+4+2+2+2+4+1+1),(2+0+4+4+1),(2+0+1+1+4+4+4+4+1+1),(2+0+1+1+1+1+1+1),(2+0+2+1+2+2+1+2+2+2),(2+0+1+1+1),(2+0+4+1),(2+0+4+4),(2+0+4+4+4+4+4+4+4),(2+0+4+4+2+1),(2+0+2+2),(2+0+8+4),(2+0+2+2+2+2),(2+0+4+4+4),(2+0+4+4+4+4),(2+0+4+4+4+4+4+4+4),(2+0+1+4+1+4+4+4),(2+0+1+1+1+1+1+1+2),(2+0+1+nb_msg*1),(2+0+4+4+4+4),(2+0+1),(2+0+2+4+4+4+4+4+1),(2+0+1+2+2),(2+0+1+4),(2+0+1+4+4),(2+0+2+2+2+2+2+1),(2+0+2+4),(2+0+1+4+4+4+1),0,(2+0+4+4+2+4),(2+0+2+2+2+2+2+2+2+2+2+2+2),(2+0+4+4+4+4+4),(2+0+4+4+4+4+4+4),(2+0+4+4+4+4),(2+0+4+4),(2+0+4+4+4),(2+0+4+2+4),(2+0+4+4+4+4),(2+0+2+2+2+2),(2+0+1+4+4+4),(2+0+1+4),(2+0+1+4+4+4),(2+0+1+1+4+4),(2+0+1+1+1),(2+0+1+nb_values*2),(2+0+2+2+2),(2+0+4+4+4+4),(2+0+2+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+1+1+1+1+4+2+1+1),(2+0+2+2+4),(2+0+2+2+4),(2+0+2+2+4+4+2+2),(2+0+4+4+4+2+2+2+2+4+1+1),(2+0+4+4+4+4),(2+0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4),(2+0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4),(2+0+2+4+4),(2+0+2+4+4+4+1+4+4+4+4+4+4+4+2+1),(2+0+2+4+4+4+4+4+4),(2+0+2+4+4+4+4),(2+0+4+4+4+4+4+4),0,(2+0+2+4),(2+0+2+1+1),0,0,0,0,0,(2+0+4+4),(2+0+4),0,0,(2+0+4+4),(2+0+4+4+2+2+2+2+1+1+1+1+1+2),(2+0+1+1+4+4+4),(2+0+1+1+1),(2+0+4+4+4+4),(2+0+2+4+2+4),(2+0+2+4),(2+0+4+4+4),(2+0+4+2),(2+0+2+2+4+4),(2+0+2+2+2+2+1+nb_heat*1),(2+0+2+2+4+4),(2+0+4+4+4+4+4+4+4+1+1),(2+0+4+4+1+1),(2+0+4+4+4+4+4+4+2+1),(2+0+4+4+4+2),(2+0+2+4+4),(2+0+2+4),(2+0+2+4),(2+0+4+4),(2+0+1+1+nb_values*2),(2+0+1+nb_values*2),(2+0+1+nb_values*2),(2+0+1+1+1+1+4),(2+0+1+1+nb_values*2),(2+0+1+nb_values*2),(2+0+2+2+2+4+2+2+1+1),(2+0+4+4+4+4+4+4),(2+0+4+4+4+4+4+4+4+4+4+4+4+4+4),(2+0+4+4+4+4),(2+0+2+4+4+4+1+2+2+2+2+4),(2+0+1+1+1+nb_servo*2),(2+0+4),(2+0+4+4),(2+0+1+nb_values*1),(2+0+2+2+4+4),(2+0+4+4+4+4),(2+0+2+2+2+2+2+2+2+2),(2+0+2+2+2+2+2+2+2+2+2+2),(2+0+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2),(2+0+1),(2+0+1+1),(2+0+1),(2+0+1+4),(2+0+4+4+4+4+4),(2+0+4+4+4+4+4+4+4),(2+0+4+4+4+4+4+4+4+4+2+2+2+2+2+2+2+2),(2+0+2+2+4+4),(2+0+2),(2+0+4),(2+0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4),(2+0+4+4+4),(2+0+4+4+4),(2+0+4+4+4),(2+0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4),(2+0+4+4+4+4+4+4),(2+0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4),(2+0+4+4+4+4+4+4+4+4+1),0,(2+0+4+4+4+4+4+4+4),(2+0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4),(2+0+4+4+4+4+4+4+4+4+4+4+4+4),(2+0+4+4+4+4+4+4+4+4+4+4+4+4),(2+0+4+4+4+4),(2+0+4+4+4+4),(2+0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4),(2+0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4),(2+0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+2),(2+0+4),(2+0+4+4+4+4+4+4+4+4),(2+0+2+2+2+4+4+4+4+4+4+4+4+4+4),(2+0+4+4+4+4),(2+0+4+4+4+4),(2+0+4+4+2),(2+0+4+4+4+4+4+4+4+4),(2+0+4+4+4+4+4+4+4+4+4+4+4+4+4+2+1+1),(2+0+4+4+4+4+4+4),(2+0+4+4+4+4+4+4+4+4),(2+0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4),(2+0+2+2+1+1+1),(2+0+2+2+2+2+2+2+1),0,(2+0+4+4+4+4+4+4+4),(2+0+4+4+4),(2+0+4+4+4+4+4+4),(2+0+4+4+4+4+4+4+4+4),(2+0+2+2+2),(2+0+2+2+2+2),(2+0+2+2),(2+0+4+4+4+4+4+4+4+4),(2+0+4+4+4+4+4+4+4+4+4+4),(2+0+2+4+4+4+4+4+4+4+4+4),(2+0+4+4+4+4+4+4+4+4+4+4),(2+0+4+4+4),(2+0+4+4+4),(2+0+4),(2+0+4+4),(2+0+4+4+4+4),(2+0+4+4+4),0,(2+0+4+4+4),(2+0+4),(2+0+4+4+4+4),(2+0+1+nb_raw_fault*2),(2+0+1+nb_speeds*2),(2+0+4+4+4+4+4+4+4+4+4+4+4+4),(2+0+1+nb_busvolts*2),(2+0+4+4+4+4+4+4+4+1),(2+0+2+2+1+1+4+4+4+4+4),(2+0+4+4+4+4+4+4+4+4+4),(2+0+2+2+2),(2+0+4+4+4+4+4+4+4+4+4+4),(2+0+4+4+4+4+4+4+4+4+4),(2+0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4),(2+0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4),(2+0+4+4+4+4+4+4+4),(2+0+4+4+4+4+4+4+4),(2+0+4+4+4+4+4+4),(2+0+4+4+4+4+4+4+4+4+4),(2+0+4+4+4+4+4+4),(2+0+4+4+4),(2+0+4+4+4),(2+0+4+4+4),(2+0+4+4+4),(2+0+4+4+4),(2+0+4+4+4),(2+0+4+4+4+4+4),0,0,(2+0+4+4+4),(2+0+4),(2+0+1+1+nb_samples*4),(2+0+4+4+4+4+1),0,0,0,0,0,0,(2+0+4+4+4+4+4),(2+0+4),(2+0+4+4),0,0,0,0,0,(2+0+4),0,0,0,(2+0+4+1+1+1+1+1+1+1+1+1+1+2),(2+0+1+2),0,(2+0+2+4),(2+0+2+2),0,0,(2+0+4+4+4+4+4+4+4+4+4),(2+0+4+4+4+4),(2+0+4+4+4+4+4+4+4+4+4),(2+0+4+4+4+4+4+4),(2+0+4+4+4),(2+0+4),(2+0+4+4+4),(2+0+1),(2+0+1),(2+0+1+1),(2+0+4+4+4),(2+0+1+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+4+4+4),(2+0+4+4+4+4+4+4+4+4+4),(2+0+4+4+4+4+4+4),(2+0+4+4+4),(2+0+2+2+2+2+2+2+2+2+4+1),(2+0+4+4+4+4+4+4),(2+0+4+8+1+8+8+8+8+8+8+1+1+8+8+8),}

/*
 Size for non variable messages
173 : LOOSE_INS_GPS
96 : STAB_ATTITUDE_FLOAT
87 : HENRY_GNSS
84 : STAB_ATTITUDE_INT
84 : HOVER_LOOP
76 : RATE_LOOP
74 : XSENS
72 : AHRS_RMAT_INT
64 : TURB_PRESSURE_RAW
64 : TURB_PRESSURE_VOLTAGE
64 : AHRS_LKF
60 : FILTER
60 : VERT_LOOP
60 : AHRS_LKF_DEBUG
58 : ROTORCRAFT_FP
56 : GPS_INT
52 : BETH_CONTROLLER
48 : TEMP_TCOUPLE
48 : STAB_ATTITUDE_REF_INT
48 : STAB_ATTITUDE_REF_FLOAT
48 : AHRS_DEBUG_QUAT
46 : DC_INFO
46 : ROTORCRAFT_TUNE_HOVER
40 : SOLAR_RADIATION
40 : EKF7_XHAT
40 : EKF7_P_DIAG
40 : VANE_SENSOR
38 : EKF7_Y
36 : RMAT_DEBUG
36 : CONTROLLER_GAINS
36 : INS
36 : NPS_POS_LLH
36 : NPS_SPEED_POS
36 : AFL_COEFFS
33 : FILTER_ALIGNER
32 : GUIDANCE_H_REF_INT
32 : INS_REF
32 : AHRS_QUAT_INT
32 : HFF_DBG
32 : AHRS_REF_QUAT
30 : ANTENNA_DEBUG
29 : SYSTEM_STATUS
28 : DESIRED
28 : DOWNLINK_STATUS
28 : VERTICAL_ENERGY
28 : FILTER_COR
28 : VFF
28 : AHRS_LKF_ACC_DBG
28 : AHRS_LKF_MAG_DBG
27 : GPS
27 : MOTOR_BENCH_STATUS
27 : DC_SHOT
26 : GPS_LLA
26 : AMSYS_BARO
26 : DYNAMIXEL
24 : SPEED_LOOP
24 : FLIGHT_BENCHMARK
24 : BETH_ESTIMATOR
24 : FILTER2
24 : AHRS_EULER_INT
24 : HFF
24 : NPS_SENSORS_SCALED
24 : GPS_ERROR
24 : NPS_RATE_ATTITUDE
24 : BOOZ_ATT_REF_MODEL
24 : RDYB_TRAJECTORY
23 : RANGEFINDER
23 : GENERIC_COM
22 : BARO_BMP85_CALIB
21 : I2C_ERRORS
20 : NAVIGATION
20 : BARO_BMP85
20 : ATMOSPHERE_CHARGE
20 : POTENTIAL
20 : IMU_MAG_SETTINGS
20 : WEATHER
18 : MODEM_STATUS
18 : AMSYS_AIRSPEED
17 : TEST_PASSTHROUGH_STATUS
16 : SEGMENT
16 : SURVEY
16 : ALT_KALMAN
16 : PRESSURE
16 : AIRSPEED
16 : PBN
16 : H_CTL_A
16 : BMP_STATUS
16 : BETH
16 : BETH_CONTROLLER_TWIST
16 : BARO_MS5611
16 : MS5611_COEFF
16 : ROTORCRAFT_CMD
16 : GUIDANCE
16 : INS_Z
16 : PCAP01_STATUS
16 : CSC_CAN_MSG
16 : FLA_DEBUG
16 : ROTORCRAFT_STATUS
16 : NPS_RPMS
14 : BAT
14 : WP_MOVED
14 : ENERGY
14 : FORMATION_SLOT_TM
14 : MOTOR_BENCH_STATIC
13 : WP_MOVED_LLA
13 : WP_MOVED_ENU
13 : ROTORCRAFT_RADIO_CONTROL
12 : ATTITUDE
12 : TEST_FORMAT
12 : CIRCLE
12 : TUNE_ROLL
12 : MLX_STATUS
12 : WIND_INFO_RET
12 : SHT_STATUS
12 : DPICCO_STATUS
12 : HTM_STATUS
12 : SHT_I2C_STATUS
12 : IMU_GYRO_SCALED
12 : IMU_ACCEL_SCALED
12 : IMU_MAG_SCALED
12 : BOOZ2_TUNE_FF
12 : AHRS_EULER
12 : AHRS_MEASUREMENT_EULER
12 : AHRS_GYRO_BIAS_INT
12 : FMS_TIME
12 : IMU_GYRO
12 : IMU_MAG
12 : IMU_ACCEL
12 : IMU_GYRO_RAW
12 : IMU_ACCEL_RAW
12 : IMU_MAG_RAW
12 : IMU_GYRO_LP
12 : NPS_GYRO_BIAS
12 : NPS_WIND
12 : NPS_ACCEL_LTP
12 : BOOZ2_FF_ADAP
11 : GPS_SOL
11 : SYS_MON
10 : IR_SENSORS
10 : BARO_MS5534A
10 : WINDTURBINE_STATUS_
10 : CAM_POINT
10 : ANTENNA_STATUS
10 : HIH_STATUS
10 : GEIGER_COUNTER
 9 : NAVIGATION_REF
 9 : MARK
 8 : SETTINGS
 8 : CAM
 8 : SVINFO
 8 : ESTIMATOR
 8 : BARO_WORDS
 8 : BARO_ETS
 8 : AIRSPEED_ETS
 8 : VF_UPDATE
 8 : CROSS_TRACK_ERROR
 8 : SHT_I2C_SERIAL
 8 : FBW_STATUS
 8 : MLX_SERIAL
 8 : BOOZ2_SONAR
 8 : CSC_CAN_DEBUG
 8 : BARO_RAW
 7 : ROTORCRAFT_NAV_STATUS
 6 : PPRZ_MODE
 6 : MOTOR
 6 : DEBUG_IR_I2C
 6 : AOA_adc
 6 : TMP_STATUS
 6 : SCP_STATUS
 6 : TEMT_STATUS
 6 : GP2Y_STATUS
 6 : HFF_GPS
 6 : SIMPLE_COMMANDS
 6 : OPTICFLOW
 5 : CALIBRATION
 5 : DOWNLINK
 5 : DL_VALUE
 5 : CHRONO
 5 : TCAS_DEBUG
 4 : ADC_GENERIC
 4 : XTEND_RSSI
 4 : VF_PREDICT
 4 : BETH_CONTROLLER_SFB
 4 : TIMESTAMP
 4 : BOOZ2_FMS_INFO
 4 : BOOZ2_CAM
 4 : WT
 4 : LOADCELL
 4 : IMU_PRESSURE
 4 : IMU_TURNTABLE
 4 : TIME
 4 : VISUALTARGET
 4 : NPS_RANGE_METER
 3 : DEBUG_MCU_LINK
 3 : RC_3CH_
 3 : FORMATION_STATUS_TM
 3 : STATE_FILTER_STATUS
 2 : BOOT
 2 : TAKEOFF
 2 : TCAS_RA
 2 : CAMERA_SNAPSHOT
 2 : PPRZ_DEBUG
 1 : WC_RSSI
 1 : TCAS_TA
 1 : TCAS_RESOLVED
 1 : BOOZ_DEBUG_FOO
 1 : BOOZ_MAX1167_ERR
 0 : ALIVE
 0 : PONG
 0 : DEBUG
 0 : MPPT
 0 : ENOSE_STATUS
 0 : PPM
 0 : RC
 0 : COMMANDS
 0 : ADC
 0 : ACTUATORS
 0 : TEST_BOARD_RESULTS
 0 : PAYLOAD
 0 : BLMC_FAULT_STATUS
 0 : BLMC_SPEEDS
 0 : BLMC_BUSVOLTS
 0 : IMU_HS_GYRO
*/
static inline void DOWNLINK_SEND_BOOT(struct DownlinkTransport *tp, uint16_t *_version){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2)); 
	  tp->StartMessage(tp->impl, "BOOT", DL_BOOT, 0+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _version); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_ALIVE(struct DownlinkTransport *tp, uint8_t nb_md5sum, uint8_t *_md5sum){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+nb_md5sum*1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+nb_md5sum*1)); 
	  tp->StartMessage(tp->impl, "ALIVE", DL_ALIVE, 0+1+nb_md5sum*1); 
	  tp->PutBytes(tp->impl, DL_TYPE_ARRAY_LENGTH, 1, (void *) &nb_md5sum); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1 * nb_md5sum, (void *) _md5sum); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_PONG(struct DownlinkTransport *tp ){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0)); 
	  tp->StartMessage(tp->impl, "PONG", DL_PONG, 0); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_TAKEOFF(struct DownlinkTransport *tp, uint16_t *_cpu_time){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2)); 
	  tp->StartMessage(tp->impl, "TAKEOFF", DL_TAKEOFF, 0+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _cpu_time); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_ATTITUDE(struct DownlinkTransport *tp, float *_phi, float *_psi, float *_theta){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4)); 
	  tp->StartMessage(tp->impl, "ATTITUDE", DL_ATTITUDE, 0+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _psi); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _theta); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_IR_SENSORS(struct DownlinkTransport *tp, int16_t *_ir1, int16_t *_ir2, int16_t *_longitudinal, int16_t *_lateral, int16_t *_vertical){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+2+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+2+2)); 
	  tp->StartMessage(tp->impl, "IR_SENSORS", DL_IR_SENSORS, 0+2+2+2+2+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _ir1); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _ir2); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _longitudinal); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _lateral); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _vertical); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_GPS(struct DownlinkTransport *tp, uint8_t *_mode, int32_t *_utm_east, int32_t *_utm_north, int16_t *_course, int32_t *_alt, uint16_t *_speed, int16_t *_climb, uint16_t *_week, uint32_t *_itow, uint8_t *_utm_zone, uint8_t *_gps_nb_err){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+4+4+2+4+2+2+2+4+1+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+4+4+2+4+2+2+2+4+1+1)); 
	  tp->StartMessage(tp->impl, "GPS", DL_GPS, 0+1+4+4+2+4+2+2+2+4+1+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _mode); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _utm_east); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _utm_north); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _course); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _alt); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _speed); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _climb); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _week); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _itow); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _utm_zone); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _gps_nb_err); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_NAVIGATION_REF(struct DownlinkTransport *tp, int32_t *_utm_east, int32_t *_utm_north, uint8_t *_utm_zone){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+1)); 
	  tp->StartMessage(tp->impl, "NAVIGATION_REF", DL_NAVIGATION_REF, 0+4+4+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _utm_east); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _utm_north); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _utm_zone); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_NAVIGATION(struct DownlinkTransport *tp, uint8_t *_cur_block, uint8_t *_cur_stage, float *_pos_x, float *_pos_y, float *_dist2_wp, float *_dist2_home, uint8_t *_circle_count, uint8_t *_oval_count){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+4+4+4+4+1+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+4+4+4+4+1+1)); 
	  tp->StartMessage(tp->impl, "NAVIGATION", DL_NAVIGATION, 0+1+1+4+4+4+4+1+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _cur_block); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _cur_stage); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _pos_x); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _pos_y); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _dist2_wp); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _dist2_home); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _circle_count); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _oval_count); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_PPRZ_MODE(struct DownlinkTransport *tp, uint8_t *_ap_mode, uint8_t *_ap_gaz, uint8_t *_ap_lateral, uint8_t *_ap_horizontal, uint8_t *_if_calib_mode, uint8_t *_mcu1_status){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1+1+1+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1+1+1+1)); 
	  tp->StartMessage(tp->impl, "PPRZ_MODE", DL_PPRZ_MODE, 0+1+1+1+1+1+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ap_mode); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ap_gaz); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ap_lateral); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ap_horizontal); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _if_calib_mode); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _mcu1_status); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BAT(struct DownlinkTransport *tp, int16_t *_throttle, uint8_t *_voltage, int16_t *_amps, uint16_t *_flight_time, uint8_t *_kill_auto_throttle, uint16_t *_block_time, uint16_t *_stage_time, int16_t *_energy){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+1+2+2+1+2+2+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+1+2+2+1+2+2+2)); 
	  tp->StartMessage(tp->impl, "BAT", DL_BAT, 0+2+1+2+2+1+2+2+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _throttle); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _voltage); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _amps); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _flight_time); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _kill_auto_throttle); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _block_time); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _stage_time); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _energy); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_DEBUG_MCU_LINK(struct DownlinkTransport *tp, uint8_t *_i2c_nb_err, uint8_t *_i2c_mcu1_nb_err, uint8_t *_ppm_rate){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1)); 
	  tp->StartMessage(tp->impl, "DEBUG_MCU_LINK", DL_DEBUG_MCU_LINK, 0+1+1+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _i2c_nb_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _i2c_mcu1_nb_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ppm_rate); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_CALIBRATION(struct DownlinkTransport *tp, float *_climb_sum_err, uint8_t *_climb_gaz_submode){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+1)); 
	  tp->StartMessage(tp->impl, "CALIBRATION", DL_CALIBRATION, 0+4+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _climb_sum_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _climb_gaz_submode); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_SETTINGS(struct DownlinkTransport *tp, float *_slider_1_val, float *_slider_2_val){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4)); 
	  tp->StartMessage(tp->impl, "SETTINGS", DL_SETTINGS, 0+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _slider_1_val); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _slider_2_val); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_DESIRED(struct DownlinkTransport *tp, float *_roll, float *_pitch, float *_course, float *_x, float *_y, float *_altitude, float *_climb){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "DESIRED", DL_DESIRED, 0+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _roll); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _pitch); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _course); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _x); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _y); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _altitude); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _climb); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_GPS_SOL(struct DownlinkTransport *tp, uint32_t *_Pacc, uint32_t *_Sacc, uint16_t *_PDOP, uint8_t *_numSV){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+2+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+2+1)); 
	  tp->StartMessage(tp->impl, "GPS_SOL", DL_GPS_SOL, 0+4+4+2+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _Pacc); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _Sacc); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _PDOP); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _numSV); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_ADC_GENERIC(struct DownlinkTransport *tp, uint16_t *_val1, uint16_t *_val2){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2)); 
	  tp->StartMessage(tp->impl, "ADC_GENERIC", DL_ADC_GENERIC, 0+2+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _val1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _val2); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_TEST_FORMAT(struct DownlinkTransport *tp, double *_val1, float *_val2){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+8+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+8+4)); 
	  tp->StartMessage(tp->impl, "TEST_FORMAT", DL_TEST_FORMAT, 0+8+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _val1); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _val2); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_CAM(struct DownlinkTransport *tp, int16_t *_phi, int16_t *_theta, int16_t *_target_x, int16_t *_target_y){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+2)); 
	  tp->StartMessage(tp->impl, "CAM", DL_CAM, 0+2+2+2+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _target_x); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _target_y); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_CIRCLE(struct DownlinkTransport *tp, float *_center_east, float *_center_north, float *_radius){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4)); 
	  tp->StartMessage(tp->impl, "CIRCLE", DL_CIRCLE, 0+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _center_east); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _center_north); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _radius); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_SEGMENT(struct DownlinkTransport *tp, float *_segment_east_1, float *_segment_north_1, float *_segment_east_2, float *_segment_north_2){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "SEGMENT", DL_SEGMENT, 0+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _segment_east_1); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _segment_north_1); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _segment_east_2); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _segment_north_2); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_DOWNLINK_STATUS(struct DownlinkTransport *tp, uint32_t *_run_time, uint32_t *_rx_bytes, uint32_t *_rx_msgs, uint32_t *_rx_err, float *_rx_bytes_rate, float *_rx_msgs_rate, float *_ping_time){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "DOWNLINK_STATUS", DL_DOWNLINK_STATUS, 0+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _run_time); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _rx_bytes); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _rx_msgs); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _rx_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _rx_bytes_rate); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _rx_msgs_rate); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ping_time); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_MODEM_STATUS(struct DownlinkTransport *tp, uint8_t *_detected, float *_valim, uint8_t *_cd, uint32_t *_nb_byte, uint32_t *_nb_msg, uint32_t *_nb_err){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+4+1+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+4+1+4+4+4)); 
	  tp->StartMessage(tp->impl, "MODEM_STATUS", DL_MODEM_STATUS, 0+1+4+1+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _detected); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _valim); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _cd); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _nb_byte); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _nb_msg); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _nb_err); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_SVINFO(struct DownlinkTransport *tp, uint8_t *_chn, uint8_t *_SVID, uint8_t *_Flags, uint8_t *_QI, uint8_t *_CNO, int8_t *_Elev, int16_t *_Azim){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1+1+1+1+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1+1+1+1+2)); 
	  tp->StartMessage(tp->impl, "SVINFO", DL_SVINFO, 0+1+1+1+1+1+1+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _chn); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _SVID); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _Flags); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _QI); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _CNO); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT8, 1, (void *) _Elev); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _Azim); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_DEBUG(struct DownlinkTransport *tp, uint8_t nb_msg, uint8_t *_msg){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+nb_msg*1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+nb_msg*1)); 
	  tp->StartMessage(tp->impl, "DEBUG", DL_DEBUG, 0+1+nb_msg*1); 
	  tp->PutBytes(tp->impl, DL_TYPE_ARRAY_LENGTH, 1, (void *) &nb_msg); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1 * nb_msg, (void *) _msg); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_SURVEY(struct DownlinkTransport *tp, float *_east, float *_north, float *_west, float *_south){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "SURVEY", DL_SURVEY, 0+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _east); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _north); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _west); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _south); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_WC_RSSI(struct DownlinkTransport *tp, uint8_t *_raw_level){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1)); 
	  tp->StartMessage(tp->impl, "WC_RSSI", DL_WC_RSSI, 0+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _raw_level); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_RANGEFINDER(struct DownlinkTransport *tp, uint16_t *_range, float *_z_dot, float *_z_dot_sum_err, float *_z_dot_setpoint, float *_z_sum_err, float *_z_setpoint, uint8_t *_flying){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+4+4+4+4+4+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+4+4+4+4+4+1)); 
	  tp->StartMessage(tp->impl, "RANGEFINDER", DL_RANGEFINDER, 0+2+4+4+4+4+4+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _range); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _z_dot); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _z_dot_sum_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _z_dot_setpoint); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _z_sum_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _z_setpoint); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _flying); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_DOWNLINK(struct DownlinkTransport *tp, uint8_t *_nb_ovrn, uint16_t *_rate, uint16_t *_nb_msgs){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+2+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+2+2)); 
	  tp->StartMessage(tp->impl, "DOWNLINK", DL_DOWNLINK, 0+1+2+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _nb_ovrn); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _rate); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _nb_msgs); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_DL_VALUE(struct DownlinkTransport *tp, uint8_t *_index, float *_value){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+4)); 
	  tp->StartMessage(tp->impl, "DL_VALUE", DL_DL_VALUE, 0+1+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _index); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _value); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_MARK(struct DownlinkTransport *tp, uint8_t *_ac_id, float *_lat, float *_long){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+4+4)); 
	  tp->StartMessage(tp->impl, "MARK", DL_MARK, 0+1+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _lat); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _long); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_SYS_MON(struct DownlinkTransport *tp, uint16_t *_periodic_time, uint16_t *_periodic_cycle, uint16_t *_periodic_cycle_min, uint16_t *_periodic_cycle_max, uint16_t *_event_number, uint8_t *_cpu_load){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+2+2+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+2+2+1)); 
	  tp->StartMessage(tp->impl, "SYS_MON", DL_SYS_MON, 0+2+2+2+2+2+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _periodic_time); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _periodic_cycle); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _periodic_cycle_min); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _periodic_cycle_max); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _event_number); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _cpu_load); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_MOTOR(struct DownlinkTransport *tp, uint16_t *_rpm, int32_t *_current){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+4)); 
	  tp->StartMessage(tp->impl, "MOTOR", DL_MOTOR, 0+2+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _rpm); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _current); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_WP_MOVED(struct DownlinkTransport *tp, uint8_t *_wp_id, float *_utm_east, float *_utm_north, float *_alt, uint8_t *_utm_zone){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+4+4+4+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+4+4+4+1)); 
	  tp->StartMessage(tp->impl, "WP_MOVED", DL_WP_MOVED, 0+1+4+4+4+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _wp_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _utm_east); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _utm_north); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _alt); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _utm_zone); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_ENERGY(struct DownlinkTransport *tp, float *_bat, float *_amp, uint16_t *_energy, float *_power){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+2+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+2+4)); 
	  tp->StartMessage(tp->impl, "ENERGY", DL_ENERGY, 0+4+4+2+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _bat); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _amp); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _energy); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _power); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BARO_BMP85_CALIB(struct DownlinkTransport *tp, int16_t *_a1, int16_t *_a2, int16_t *_a3, uint16_t *_a4, uint16_t *_a5, uint16_t *_a6, int16_t *_b1, int16_t *_b2, int16_t *_mb, int16_t *_mc, int16_t *_md){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+2+2+2+2+2+2+2+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+2+2+2+2+2+2+2+2)); 
	  tp->StartMessage(tp->impl, "BARO_BMP85_CALIB", DL_BARO_BMP85_CALIB, 0+2+2+2+2+2+2+2+2+2+2+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _a1); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _a2); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _a3); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _a4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _a5); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _a6); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _b1); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _b2); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _mb); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _mc); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _md); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BARO_BMP85(struct DownlinkTransport *tp, int32_t *_UT, int32_t *_UP, uint32_t *_P, float *_T, float *_MSL){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "BARO_BMP85", DL_BARO_BMP85, 0+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _UT); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _UP); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _P); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _T); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _MSL); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_SPEED_LOOP(struct DownlinkTransport *tp, float *_ve_set_point, float *_ve, float *_vn_set_point, float *_vn, float *_north_sp, float *_east_sp){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "SPEED_LOOP", DL_SPEED_LOOP, 0+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ve_set_point); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ve); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _vn_set_point); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _vn); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _north_sp); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _east_sp); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_ALT_KALMAN(struct DownlinkTransport *tp, float *_p00, float *_p01, float *_p10, float *_p11){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "ALT_KALMAN", DL_ALT_KALMAN, 0+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _p00); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _p01); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _p10); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _p11); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_ESTIMATOR(struct DownlinkTransport *tp, float *_z, float *_z_dot){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4)); 
	  tp->StartMessage(tp->impl, "ESTIMATOR", DL_ESTIMATOR, 0+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _z); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _z_dot); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_TUNE_ROLL(struct DownlinkTransport *tp, float *_p, float *_phi, float *_phi_sp){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4)); 
	  tp->StartMessage(tp->impl, "TUNE_ROLL", DL_TUNE_ROLL, 0+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _p); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _phi_sp); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BARO_MS5534A(struct DownlinkTransport *tp, uint32_t *_pressure, uint16_t *_temp, float *_alt){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+2+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+2+4)); 
	  tp->StartMessage(tp->impl, "BARO_MS5534A", DL_BARO_MS5534A, 0+4+2+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _pressure); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _temp); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _alt); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_PRESSURE(struct DownlinkTransport *tp, float *_airspeed_adc, float *_airspeed, float *_altitude_adc, float *_altitude){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "PRESSURE", DL_PRESSURE, 0+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _airspeed_adc); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _airspeed); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _altitude_adc); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _altitude); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BARO_WORDS(struct DownlinkTransport *tp, uint16_t *_w1, uint16_t *_w2, uint16_t *_w3, uint16_t *_w4){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+2)); 
	  tp->StartMessage(tp->impl, "BARO_WORDS", DL_BARO_WORDS, 0+2+2+2+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _w1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _w2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _w3); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _w4); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_WP_MOVED_LLA(struct DownlinkTransport *tp, uint8_t *_wp_id, int32_t *_lat, int32_t *_lon, int32_t *_alt){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+4+4+4)); 
	  tp->StartMessage(tp->impl, "WP_MOVED_LLA", DL_WP_MOVED_LLA, 0+1+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _wp_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _lat); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _lon); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _alt); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_CHRONO(struct DownlinkTransport *tp, uint8_t *_tag, uint32_t *_time){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+4)); 
	  tp->StartMessage(tp->impl, "CHRONO", DL_CHRONO, 0+1+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _tag); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _time); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_WP_MOVED_ENU(struct DownlinkTransport *tp, uint8_t *_wp_id, int32_t *_east, int32_t *_north, int32_t *_up){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+4+4+4)); 
	  tp->StartMessage(tp->impl, "WP_MOVED_ENU", DL_WP_MOVED_ENU, 0+1+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _wp_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _east); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _north); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _up); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_WINDTURBINE_STATUS_(struct DownlinkTransport *tp, uint8_t *_ac_id, uint8_t *_tb_id, uint32_t *_sync_itow, uint32_t *_cycle_time){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+4+4)); 
	  tp->StartMessage(tp->impl, "WINDTURBINE_STATUS_", DL_WINDTURBINE_STATUS_, 0+1+1+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _tb_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _sync_itow); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _cycle_time); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_RC_3CH_(struct DownlinkTransport *tp, uint8_t *_throttle_mode, int8_t *_roll, int8_t *_pitch){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1)); 
	  tp->StartMessage(tp->impl, "RC_3CH_", DL_RC_3CH_, 0+1+1+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _throttle_mode); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT8, 1, (void *) _roll); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT8, 1, (void *) _pitch); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_MPPT(struct DownlinkTransport *tp, uint8_t nb_values, int16_t *_values){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+nb_values*2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+nb_values*2)); 
	  tp->StartMessage(tp->impl, "MPPT", DL_MPPT, 0+1+nb_values*2); 
	  tp->PutBytes(tp->impl, DL_TYPE_ARRAY_LENGTH, 1, (void *) &nb_values); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2 * nb_values, (void *) _values); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_DEBUG_IR_I2C(struct DownlinkTransport *tp, int16_t *_ir1, int16_t *_ir2, int16_t *_top){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2)); 
	  tp->StartMessage(tp->impl, "DEBUG_IR_I2C", DL_DEBUG_IR_I2C, 0+2+2+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _ir1); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _ir2); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _top); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_AIRSPEED(struct DownlinkTransport *tp, float *_airspeed, float *_airspeed_sp, float *_airspeed_cnt, float *_groundspeed_sp){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "AIRSPEED", DL_AIRSPEED, 0+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _airspeed); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _airspeed_sp); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _airspeed_cnt); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _groundspeed_sp); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_XSENS(struct DownlinkTransport *tp, int16_t *_counter, float *_p, float *_q, float *_r, float *_phi, float *_theta, float *_psi, float *_ax, float *_ay, float *_az, float *_vx, float *_vy, float *_vz, float *_lat, float *_lon, float *_alt, uint8_t *_status, uint8_t *_hour, uint8_t *_min, uint8_t *_sec, uint32_t *_nanosec, uint16_t *_year, uint8_t *_month, uint8_t *_day){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+1+1+1+1+4+2+1+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+1+1+1+1+4+2+1+1)); 
	  tp->StartMessage(tp->impl, "XSENS", DL_XSENS, 0+2+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+1+1+1+1+4+2+1+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _counter); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _p); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _q); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _r); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _psi); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ax); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ay); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _az); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _vx); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _vy); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _vz); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _lat); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _lon); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _alt); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _status); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _hour); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _min); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _sec); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _nanosec); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _year); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _month); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _day); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BARO_ETS(struct DownlinkTransport *tp, uint16_t *_adc, uint16_t *_offset, float *_scaled){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2+4)); 
	  tp->StartMessage(tp->impl, "BARO_ETS", DL_BARO_ETS, 0+2+2+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _adc); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _offset); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _scaled); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_AIRSPEED_ETS(struct DownlinkTransport *tp, uint16_t *_adc, uint16_t *_offset, float *_scaled){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2+4)); 
	  tp->StartMessage(tp->impl, "AIRSPEED_ETS", DL_AIRSPEED_ETS, 0+2+2+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _adc); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _offset); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _scaled); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_PBN(struct DownlinkTransport *tp, uint16_t *_airspeed_adc, uint16_t *_altitude_adc, float *_airspeed, float *_altitude, uint16_t *_airspeed_offset, uint16_t *_altitude_offset){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2+4+4+2+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2+4+4+2+2)); 
	  tp->StartMessage(tp->impl, "PBN", DL_PBN, 0+2+2+4+4+2+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _airspeed_adc); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _altitude_adc); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _airspeed); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _altitude); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _airspeed_offset); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _altitude_offset); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_GPS_LLA(struct DownlinkTransport *tp, int32_t *_lat, int32_t *_lon, int32_t *_alt, int16_t *_course, uint16_t *_speed, int16_t *_climb, uint16_t *_week, uint32_t *_itow, uint8_t *_mode, uint8_t *_gps_nb_err){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+2+2+2+2+4+1+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+2+2+2+2+4+1+1)); 
	  tp->StartMessage(tp->impl, "GPS_LLA", DL_GPS_LLA, 0+4+4+4+2+2+2+2+4+1+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _lat); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _lon); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _alt); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _course); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _speed); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _climb); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _week); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _itow); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _mode); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _gps_nb_err); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_H_CTL_A(struct DownlinkTransport *tp, float *_roll_sum_err, float *_ref_roll_angle, float *_pitch_sum_err, float *_ref_pitch_angle){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "H_CTL_A", DL_H_CTL_A, 0+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _roll_sum_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ref_roll_angle); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _pitch_sum_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ref_pitch_angle); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_TURB_PRESSURE_RAW(struct DownlinkTransport *tp, int32_t *_ch_0, int32_t *_ch_1, int32_t *_ch_2, int32_t *_ch_3, int32_t *_ch_4, int32_t *_ch_5, int32_t *_ch_6, int32_t *_ch_7, int32_t *_ch_8, int32_t *_ch_9, int32_t *_ch_10, int32_t *_ch_11, int32_t *_ch_12, int32_t *_ch_13, int32_t *_ch_14, int32_t *_ch_15){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "TURB_PRESSURE_RAW", DL_TURB_PRESSURE_RAW, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ch_0); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ch_1); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ch_2); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ch_3); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ch_4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ch_5); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ch_6); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ch_7); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ch_8); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ch_9); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ch_10); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ch_11); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ch_12); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ch_13); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ch_14); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ch_15); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_TURB_PRESSURE_VOLTAGE(struct DownlinkTransport *tp, float *_ch_1_p, float *_ch_1_t, float *_ch_2_p, float *_ch_2_t, float *_ch_3_p, float *_ch_3_t, float *_ch_4_p, float *_ch_4_t, float *_ch_5_p, float *_ch_5_t, float *_ch_6_p, float *_ch_6_t, float *_ch_7_p, float *_ch_7_t, float *_gnd1, float *_gnd2){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "TURB_PRESSURE_VOLTAGE", DL_TURB_PRESSURE_VOLTAGE, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ch_1_p); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ch_1_t); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ch_2_p); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ch_2_t); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ch_3_p); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ch_3_t); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ch_4_p); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ch_4_t); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ch_5_p); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ch_5_t); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ch_6_p); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ch_6_t); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ch_7_p); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ch_7_t); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _gnd1); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _gnd2); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_CAM_POINT(struct DownlinkTransport *tp, uint16_t *_cam_point_distance_from_home, float *_cam_point_lat, float *_cam_point_lon){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+4+4)); 
	  tp->StartMessage(tp->impl, "CAM_POINT", DL_CAM_POINT, 0+2+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _cam_point_distance_from_home); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _cam_point_lat); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _cam_point_lon); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_DC_INFO(struct DownlinkTransport *tp, int16_t *_mode, float *_utm_east, float *_utm_north, float *_course, int8_t *_buffer, float *_dist, float *_next_dist, float *_start_x, float *_start_y, float *_start_angle, float *_angle, float *_last_block, int16_t *_count, uint8_t *_shutter){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+4+4+4+1+4+4+4+4+4+4+4+2+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+4+4+4+1+4+4+4+4+4+4+4+2+1)); 
	  tp->StartMessage(tp->impl, "DC_INFO", DL_DC_INFO, 0+2+4+4+4+1+4+4+4+4+4+4+4+2+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _mode); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _utm_east); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _utm_north); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _course); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT8, 1, (void *) _buffer); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _dist); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _next_dist); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _start_x); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _start_y); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _start_angle); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _angle); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _last_block); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _count); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _shutter); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_AMSYS_BARO(struct DownlinkTransport *tp, uint16_t *_pBaroRaw, float *_pBaro, float *_pHomePressure, float *_AltOffset, float *_aktuell, float *_Over_Ground, float *_tempBaro){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "AMSYS_BARO", DL_AMSYS_BARO, 0+2+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _pBaroRaw); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _pBaro); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _pHomePressure); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _AltOffset); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _aktuell); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _Over_Ground); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _tempBaro); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_AMSYS_AIRSPEED(struct DownlinkTransport *tp, uint16_t *_asRaw, float *_asPresure, float *_asAirspeed, float *_asAirsFilt, float *_asTemp){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "AMSYS_AIRSPEED", DL_AMSYS_AIRSPEED, 0+2+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _asRaw); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _asPresure); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _asAirspeed); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _asAirsFilt); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _asTemp); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_FLIGHT_BENCHMARK(struct DownlinkTransport *tp, float *_SE_As, float *_SE_Alt, float *_SE_Pos, float *_Err_As, float *_Err_Alt, float *_Err_Pos){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "FLIGHT_BENCHMARK", DL_FLIGHT_BENCHMARK, 0+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _SE_As); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _SE_Alt); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _SE_Pos); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _Err_As); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _Err_Alt); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _Err_Pos); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_AOA_adc(struct DownlinkTransport *tp, uint16_t *_adcVal, float *_AOA){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+4)); 
	  tp->StartMessage(tp->impl, "AOA_adc", DL_AOA_adc, 0+2+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _adcVal); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _AOA); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_XTEND_RSSI(struct DownlinkTransport *tp, uint16_t *_datalink_time, uint8_t *_rssi_fade_margin, uint8_t *_duty){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+1+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+1+1)); 
	  tp->StartMessage(tp->impl, "XTEND_RSSI", DL_XTEND_RSSI, 0+2+1+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _datalink_time); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _rssi_fade_margin); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _duty); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_VF_UPDATE(struct DownlinkTransport *tp, float *_baro, float *_range_meter){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4)); 
	  tp->StartMessage(tp->impl, "VF_UPDATE", DL_VF_UPDATE, 0+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _baro); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _range_meter); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_VF_PREDICT(struct DownlinkTransport *tp, float *_accel){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4)); 
	  tp->StartMessage(tp->impl, "VF_PREDICT", DL_VF_PREDICT, 0+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _accel); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_CROSS_TRACK_ERROR(struct DownlinkTransport *tp, float *_cross_track_error, float *_cte_int){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4)); 
	  tp->StartMessage(tp->impl, "CROSS_TRACK_ERROR", DL_CROSS_TRACK_ERROR, 0+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _cross_track_error); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _cte_int); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_GENERIC_COM(struct DownlinkTransport *tp, int32_t *_lat, int32_t *_lon, int16_t *_alt, uint16_t *_gspeed, int16_t *_course, uint16_t *_airspeed, uint8_t *_vsupply, uint8_t *_energy, uint8_t *_throttle, uint8_t *_ap_mode, uint8_t *_nav_block, uint16_t *_flight_time){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+2+2+2+2+1+1+1+1+1+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+2+2+2+2+1+1+1+1+1+2)); 
	  tp->StartMessage(tp->impl, "GENERIC_COM", DL_GENERIC_COM, 0+4+4+2+2+2+2+1+1+1+1+1+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _lat); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _lon); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _alt); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _gspeed); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _course); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _airspeed); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _vsupply); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _energy); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _throttle); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ap_mode); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _nav_block); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _flight_time); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_FORMATION_SLOT_TM(struct DownlinkTransport *tp, uint8_t *_ac_id, uint8_t *_mode, float *_slot_east, float *_slot_north, float *_slot_alt){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+4+4+4)); 
	  tp->StartMessage(tp->impl, "FORMATION_SLOT_TM", DL_FORMATION_SLOT_TM, 0+1+1+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _mode); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _slot_east); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _slot_north); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _slot_alt); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_FORMATION_STATUS_TM(struct DownlinkTransport *tp, uint8_t *_ac_id, uint8_t *_leader_id, uint8_t *_status){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1)); 
	  tp->StartMessage(tp->impl, "FORMATION_STATUS_TM", DL_FORMATION_STATUS_TM, 0+1+1+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _leader_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _status); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BMP_STATUS(struct DownlinkTransport *tp, int32_t *_UP, int32_t *_UT, int32_t *_press, int32_t *_temp){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "BMP_STATUS", DL_BMP_STATUS, 0+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _UP); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _UT); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _press); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _temp); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_MLX_STATUS(struct DownlinkTransport *tp, uint16_t *_itemp_case, float *_temp_case, uint16_t *_itemp_obj, float *_temp_obj){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+4+2+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+4+2+4)); 
	  tp->StartMessage(tp->impl, "MLX_STATUS", DL_MLX_STATUS, 0+2+4+2+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _itemp_case); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _temp_case); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _itemp_obj); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _temp_obj); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_TMP_STATUS(struct DownlinkTransport *tp, uint16_t *_itemp, float *_temp){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+4)); 
	  tp->StartMessage(tp->impl, "TMP_STATUS", DL_TMP_STATUS, 0+2+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _itemp); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _temp); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_WIND_INFO_RET(struct DownlinkTransport *tp, float *_east, float *_north, float *_airspeed){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4)); 
	  tp->StartMessage(tp->impl, "WIND_INFO_RET", DL_WIND_INFO_RET, 0+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _east); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _north); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _airspeed); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_SCP_STATUS(struct DownlinkTransport *tp, uint32_t *_press, int16_t *_temp){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+2)); 
	  tp->StartMessage(tp->impl, "SCP_STATUS", DL_SCP_STATUS, 0+4+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _press); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _temp); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_SHT_STATUS(struct DownlinkTransport *tp, uint16_t *_ihumid, uint16_t *_itemp, float *_humid, float *_temp){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2+4+4)); 
	  tp->StartMessage(tp->impl, "SHT_STATUS", DL_SHT_STATUS, 0+2+2+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _ihumid); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _itemp); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _humid); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _temp); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_ENOSE_STATUS(struct DownlinkTransport *tp, uint16_t *_val1, uint16_t *_val2, uint16_t *_val3, uint16_t *_PID, uint8_t nb_heat, uint8_t *_heat){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+2+1+nb_heat*1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+2+1+nb_heat*1)); 
	  tp->StartMessage(tp->impl, "ENOSE_STATUS", DL_ENOSE_STATUS, 0+2+2+2+2+1+nb_heat*1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _val1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _val2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _val3); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _PID); 
	  tp->PutBytes(tp->impl, DL_TYPE_ARRAY_LENGTH, 1, (void *) &nb_heat); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1 * nb_heat, (void *) _heat); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_DPICCO_STATUS(struct DownlinkTransport *tp, uint16_t *_humid, uint16_t *_temp, float *_fhumid, float *_ftemp){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2+4+4)); 
	  tp->StartMessage(tp->impl, "DPICCO_STATUS", DL_DPICCO_STATUS, 0+2+2+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _humid); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _temp); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _fhumid); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ftemp); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_ANTENNA_DEBUG(struct DownlinkTransport *tp, int32_t *_mag_xraw, int32_t *_mag_yraw, float *_mag_xcal, float *_mag_ycal, float *_mag_heading, float *_mag_magnitude, float *_mag_temp, uint8_t *_mag_distor, uint8_t *_mag_cal_status){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+1+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+1+1)); 
	  tp->StartMessage(tp->impl, "ANTENNA_DEBUG", DL_ANTENNA_DEBUG, 0+4+4+4+4+4+4+4+1+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _mag_xraw); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _mag_yraw); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _mag_xcal); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _mag_ycal); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _mag_heading); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _mag_magnitude); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _mag_temp); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _mag_distor); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _mag_cal_status); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_ANTENNA_STATUS(struct DownlinkTransport *tp, float *_azim_sp, float *_elev_sp, uint8_t *_id_sp, uint8_t *_mode){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+1+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+1+1)); 
	  tp->StartMessage(tp->impl, "ANTENNA_STATUS", DL_ANTENNA_STATUS, 0+4+4+1+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _azim_sp); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _elev_sp); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _id_sp); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _mode); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_MOTOR_BENCH_STATUS(struct DownlinkTransport *tp, uint32_t *_time_ticks, float *_throttle, float *_rpm, float *_current, float *_thrust, float *_torque, uint16_t *_time_s, uint8_t *_mode){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+2+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+2+1)); 
	  tp->StartMessage(tp->impl, "MOTOR_BENCH_STATUS", DL_MOTOR_BENCH_STATUS, 0+4+4+4+4+4+4+2+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _time_ticks); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _throttle); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _rpm); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _current); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _thrust); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _torque); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _time_s); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _mode); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_MOTOR_BENCH_STATIC(struct DownlinkTransport *tp, float *_av_rpm, float *_av_thrust, float *_av_current, uint16_t *_throttle){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+2)); 
	  tp->StartMessage(tp->impl, "MOTOR_BENCH_STATIC", DL_MOTOR_BENCH_STATIC, 0+4+4+4+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _av_rpm); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _av_thrust); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _av_current); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _throttle); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_HIH_STATUS(struct DownlinkTransport *tp, uint16_t *_humid, float *_fhumid, float *_ftemp){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+4+4)); 
	  tp->StartMessage(tp->impl, "HIH_STATUS", DL_HIH_STATUS, 0+2+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _humid); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _fhumid); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ftemp); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_TEMT_STATUS(struct DownlinkTransport *tp, uint16_t *_light, float *_f_light){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+4)); 
	  tp->StartMessage(tp->impl, "TEMT_STATUS", DL_TEMT_STATUS, 0+2+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _light); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _f_light); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_GP2Y_STATUS(struct DownlinkTransport *tp, uint16_t *_idensity, float *_density){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+4)); 
	  tp->StartMessage(tp->impl, "GP2Y_STATUS", DL_GP2Y_STATUS, 0+2+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _idensity); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _density); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_SHT_I2C_SERIAL(struct DownlinkTransport *tp, uint32_t *_serial0, uint32_t *_serial1){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4)); 
	  tp->StartMessage(tp->impl, "SHT_I2C_SERIAL", DL_SHT_I2C_SERIAL, 0+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _serial0); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _serial1); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_PPM(struct DownlinkTransport *tp, uint8_t *_ppm_rate, uint8_t nb_values, uint16_t *_values){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+nb_values*2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+nb_values*2)); 
	  tp->StartMessage(tp->impl, "PPM", DL_PPM, 0+1+1+nb_values*2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ppm_rate); 
	  tp->PutBytes(tp->impl, DL_TYPE_ARRAY_LENGTH, 1, (void *) &nb_values); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2 * nb_values, (void *) _values); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_RC(struct DownlinkTransport *tp, uint8_t nb_values, int16_t *_values){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+nb_values*2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+nb_values*2)); 
	  tp->StartMessage(tp->impl, "RC", DL_RC, 0+1+nb_values*2); 
	  tp->PutBytes(tp->impl, DL_TYPE_ARRAY_LENGTH, 1, (void *) &nb_values); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2 * nb_values, (void *) _values); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_COMMANDS(struct DownlinkTransport *tp, uint8_t nb_values, int16_t *_values){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+nb_values*2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+nb_values*2)); 
	  tp->StartMessage(tp->impl, "COMMANDS", DL_COMMANDS, 0+1+nb_values*2); 
	  tp->PutBytes(tp->impl, DL_TYPE_ARRAY_LENGTH, 1, (void *) &nb_values); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2 * nb_values, (void *) _values); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_FBW_STATUS(struct DownlinkTransport *tp, uint8_t *_rc_status, uint8_t *_frame_rate, uint8_t *_mode, uint8_t *_vsupply, int32_t *_current){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1+1+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1+1+4)); 
	  tp->StartMessage(tp->impl, "FBW_STATUS", DL_FBW_STATUS, 0+1+1+1+1+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _rc_status); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _frame_rate); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _mode); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _vsupply); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _current); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_ADC(struct DownlinkTransport *tp, uint8_t *_mcu, uint8_t nb_values, uint16_t *_values){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+nb_values*2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+nb_values*2)); 
	  tp->StartMessage(tp->impl, "ADC", DL_ADC, 0+1+1+nb_values*2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _mcu); 
	  tp->PutBytes(tp->impl, DL_TYPE_ARRAY_LENGTH, 1, (void *) &nb_values); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2 * nb_values, (void *) _values); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_ACTUATORS(struct DownlinkTransport *tp, uint8_t nb_values, uint16_t *_values){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+nb_values*2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+nb_values*2)); 
	  tp->StartMessage(tp->impl, "ACTUATORS", DL_ACTUATORS, 0+1+nb_values*2); 
	  tp->PutBytes(tp->impl, DL_TYPE_ARRAY_LENGTH, 1, (void *) &nb_values); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2 * nb_values, (void *) _values); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BETH(struct DownlinkTransport *tp, int16_t *_azimuth, int16_t *_elevation, int16_t *_tilt, uint32_t *_counter, uint16_t *_can_errs, uint16_t *_spi_errs, int8_t *_thrust_out, int8_t *_pitch_out){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+4+2+2+1+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+4+2+2+1+1)); 
	  tp->StartMessage(tp->impl, "BETH", DL_BETH, 0+2+2+2+4+2+2+1+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _azimuth); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _elevation); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _tilt); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _counter); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _can_errs); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _spi_errs); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT8, 1, (void *) _thrust_out); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT8, 1, (void *) _pitch_out); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BETH_ESTIMATOR(struct DownlinkTransport *tp, float *_tilt, float *_tilt_dot, float *_elevation, float *_elevation_dot, float *_azimuth, float *_azimuth_dot){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "BETH_ESTIMATOR", DL_BETH_ESTIMATOR, 0+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _tilt); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _tilt_dot); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _elevation); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _elevation_dot); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _azimuth); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _azimuth_dot); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BETH_CONTROLLER(struct DownlinkTransport *tp, float *_pitch, float *_thrust, float *_pitch_ff, float *_pitch_fb, float *_thrust_ff, float *_thrust_fb, float *_tilt_sp, float *_tilt_ref, float *_tilt_dot_ref, float *_elevation_sp , float *_elevation_ref , float *_elevation_dot_ref, float *_azimuth_sp){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "BETH_CONTROLLER", DL_BETH_CONTROLLER, 0+4+4+4+4+4+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _pitch); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _thrust); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _pitch_ff); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _pitch_fb); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _thrust_ff); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _thrust_fb); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _tilt_sp); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _tilt_ref); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _tilt_dot_ref); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _elevation_sp ); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _elevation_ref ); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _elevation_dot_ref); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _azimuth_sp); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BETH_CONTROLLER_TWIST(struct DownlinkTransport *tp, float *_S, float *_S_dot, float *_U_twt, float *_error){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "BETH_CONTROLLER_TWIST", DL_BETH_CONTROLLER_TWIST, 0+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _S); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _S_dot); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _U_twt); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _error); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_DC_SHOT(struct DownlinkTransport *tp, int16_t *_photo_nr, int32_t *_utm_east, int32_t *_utm_north, float *_z, uint8_t *_utm_zone, int16_t *_phi, int16_t *_theta, int16_t *_course, uint16_t *_speed, uint32_t *_itow){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+4+4+4+1+2+2+2+2+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+4+4+4+1+2+2+2+2+4)); 
	  tp->StartMessage(tp->impl, "DC_SHOT", DL_DC_SHOT, 0+2+4+4+4+1+2+2+2+2+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _photo_nr); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _utm_east); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _utm_north); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _z); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _utm_zone); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _course); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _speed); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _itow); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_TEST_BOARD_RESULTS(struct DownlinkTransport *tp, uint8_t *_uart, uint8_t *_ppm, uint8_t nb_servo, uint16_t *_servo){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1+nb_servo*2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1+nb_servo*2)); 
	  tp->StartMessage(tp->impl, "TEST_BOARD_RESULTS", DL_TEST_BOARD_RESULTS, 0+1+1+1+nb_servo*2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _uart); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ppm); 
	  tp->PutBytes(tp->impl, DL_TYPE_ARRAY_LENGTH, 1, (void *) &nb_servo); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2 * nb_servo, (void *) _servo); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BETH_CONTROLLER_SFB(struct DownlinkTransport *tp, float *_one){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4)); 
	  tp->StartMessage(tp->impl, "BETH_CONTROLLER_SFB", DL_BETH_CONTROLLER_SFB, 0+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _one); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_MLX_SERIAL(struct DownlinkTransport *tp, uint32_t *_serial0, uint32_t *_serial1){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4)); 
	  tp->StartMessage(tp->impl, "MLX_SERIAL", DL_MLX_SERIAL, 0+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _serial0); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _serial1); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_PAYLOAD(struct DownlinkTransport *tp, uint8_t nb_values, uint8_t *_values){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+nb_values*1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+nb_values*1)); 
	  tp->StartMessage(tp->impl, "PAYLOAD", DL_PAYLOAD, 0+1+nb_values*1); 
	  tp->PutBytes(tp->impl, DL_TYPE_ARRAY_LENGTH, 1, (void *) &nb_values); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1 * nb_values, (void *) _values); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_HTM_STATUS(struct DownlinkTransport *tp, uint16_t *_ihumid, uint16_t *_itemp, float *_humid, float *_temp){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2+4+4)); 
	  tp->StartMessage(tp->impl, "HTM_STATUS", DL_HTM_STATUS, 0+2+2+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _ihumid); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _itemp); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _humid); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _temp); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BARO_MS5611(struct DownlinkTransport *tp, uint32_t *_d1, uint32_t *_d2, float *_pressure, float *_temp){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "BARO_MS5611", DL_BARO_MS5611, 0+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _d1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _d2); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _pressure); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _temp); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_MS5611_COEFF(struct DownlinkTransport *tp, uint16_t *_c0, uint16_t *_c1, uint16_t *_c2, uint16_t *_c3, uint16_t *_c4, uint16_t *_c5, uint16_t *_c6, uint16_t *_c7){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+2+2+2+2+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+2+2+2+2+2)); 
	  tp->StartMessage(tp->impl, "MS5611_COEFF", DL_MS5611_COEFF, 0+2+2+2+2+2+2+2+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _c0); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _c1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _c2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _c3); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _c4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _c5); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _c6); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _c7); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_ATMOSPHERE_CHARGE(struct DownlinkTransport *tp, uint16_t *_t0, uint16_t *_t1, uint16_t *_t2, uint16_t *_t3, uint16_t *_t4, uint16_t *_t5, uint16_t *_t6, uint16_t *_t7, uint16_t *_t8, uint16_t *_t9){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+2+2+2+2+2+2+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+2+2+2+2+2+2+2)); 
	  tp->StartMessage(tp->impl, "ATMOSPHERE_CHARGE", DL_ATMOSPHERE_CHARGE, 0+2+2+2+2+2+2+2+2+2+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _t0); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _t1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _t2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _t3); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _t4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _t5); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _t6); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _t7); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _t8); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _t9); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_SOLAR_RADIATION(struct DownlinkTransport *tp, uint16_t *_up_t0, uint16_t *_dn_t0, uint16_t *_up_t1, uint16_t *_dn_t1, uint16_t *_up_t2, uint16_t *_dn_t2, uint16_t *_up_t3, uint16_t *_dn_t3, uint16_t *_up_t4, uint16_t *_dn_t4, uint16_t *_up_t5, uint16_t *_dn_t5, uint16_t *_up_t6, uint16_t *_dn_t6, uint16_t *_up_t7, uint16_t *_dn_t7, uint16_t *_up_t8, uint16_t *_dn_t8, uint16_t *_up_t9, uint16_t *_dn_t9){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2)); 
	  tp->StartMessage(tp->impl, "SOLAR_RADIATION", DL_SOLAR_RADIATION, 0+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _up_t0); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _dn_t0); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _up_t1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _dn_t1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _up_t2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _dn_t2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _up_t3); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _dn_t3); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _up_t4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _dn_t4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _up_t5); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _dn_t5); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _up_t6); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _dn_t6); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _up_t7); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _dn_t7); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _up_t8); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _dn_t8); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _up_t9); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _dn_t9); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_TCAS_TA(struct DownlinkTransport *tp, uint8_t *_ac_id){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1)); 
	  tp->StartMessage(tp->impl, "TCAS_TA", DL_TCAS_TA, 0+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_TCAS_RA(struct DownlinkTransport *tp, uint8_t *_ac_id, uint8_t *_resolve){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1)); 
	  tp->StartMessage(tp->impl, "TCAS_RA", DL_TCAS_RA, 0+1+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _resolve); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_TCAS_RESOLVED(struct DownlinkTransport *tp, uint8_t *_ac_id){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1)); 
	  tp->StartMessage(tp->impl, "TCAS_RESOLVED", DL_TCAS_RESOLVED, 0+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_TCAS_DEBUG(struct DownlinkTransport *tp, uint8_t *_ac_id, float *_tau){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+4)); 
	  tp->StartMessage(tp->impl, "TCAS_DEBUG", DL_TCAS_DEBUG, 0+1+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _tau); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_POTENTIAL(struct DownlinkTransport *tp, float *_east, float *_north, float *_alt, float *_speed, float *_climb){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "POTENTIAL", DL_POTENTIAL, 0+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _east); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _north); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _alt); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _speed); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _climb); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_VERTICAL_ENERGY(struct DownlinkTransport *tp, float *_Epot_err, float *_Ekin_err, float *_Etot_err, float *_Edis_err, float *_throttle, float *_nav_pitch, float *_speed_sp){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "VERTICAL_ENERGY", DL_VERTICAL_ENERGY, 0+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _Epot_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _Ekin_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _Etot_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _Edis_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _throttle); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _nav_pitch); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _speed_sp); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_TEMP_TCOUPLE(struct DownlinkTransport *tp, float *_fval0, float *_fval1, float *_fval2, float *_fval3, float *_fref0, float *_fref1, float *_fref2, float *_fref3, uint16_t *_val0, uint16_t *_val1, uint16_t *_val2, uint16_t *_val3, uint16_t *_ref0, uint16_t *_ref1, uint16_t *_ref2, uint16_t *_ref3){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+2+2+2+2+2+2+2+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+2+2+2+2+2+2+2+2)); 
	  tp->StartMessage(tp->impl, "TEMP_TCOUPLE", DL_TEMP_TCOUPLE, 0+4+4+4+4+4+4+4+4+2+2+2+2+2+2+2+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _fval0); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _fval1); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _fval2); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _fval3); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _fref0); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _fref1); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _fref2); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _fref3); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _val0); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _val1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _val2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _val3); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _ref0); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _ref1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _ref2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _ref3); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_SHT_I2C_STATUS(struct DownlinkTransport *tp, uint16_t *_ihumid, uint16_t *_itemp, float *_humid, float *_temp){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2+4+4)); 
	  tp->StartMessage(tp->impl, "SHT_I2C_STATUS", DL_SHT_I2C_STATUS, 0+2+2+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _ihumid); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _itemp); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _humid); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _temp); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_CAMERA_SNAPSHOT(struct DownlinkTransport *tp, uint16_t *_snapshot_image_number){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2)); 
	  tp->StartMessage(tp->impl, "CAMERA_SNAPSHOT", DL_CAMERA_SNAPSHOT, 0+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _snapshot_image_number); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_TIMESTAMP(struct DownlinkTransport *tp, uint32_t *_timestamp){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4)); 
	  tp->StartMessage(tp->impl, "TIMESTAMP", DL_TIMESTAMP, 0+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _timestamp); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_STAB_ATTITUDE_FLOAT(struct DownlinkTransport *tp, float *_est_p, float *_est_q, float *_est_r, float *_est_phi, float *_est_theta, float *_est_psi, float *_ref_phi, float *_ref_theta, float *_ref_psi, float *_sum_err_phi, float *_sum_err_theta, float *_sum_err_psi, float *_delta_a_fb, float *_delta_e_fb, float *_delta_r_fb, float *_delta_a_ff, float *_delta_e_ff, float *_delta_r_ff, int32_t *_delta_a, int32_t *_delta_e, int32_t *_delta_r, float *_est_p_d, float *_est_q_d, float *_est_r_d){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "STAB_ATTITUDE_FLOAT", DL_STAB_ATTITUDE_FLOAT, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _est_p); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _est_q); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _est_r); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _est_phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _est_theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _est_psi); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ref_phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ref_theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ref_psi); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _sum_err_phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _sum_err_theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _sum_err_psi); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _delta_a_fb); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _delta_e_fb); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _delta_r_fb); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _delta_a_ff); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _delta_e_ff); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _delta_r_ff); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _delta_a); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _delta_e); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _delta_r); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _est_p_d); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _est_q_d); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _est_r_d); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_IMU_GYRO_SCALED(struct DownlinkTransport *tp, int32_t *_gp, int32_t *_gq, int32_t *_gr){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4)); 
	  tp->StartMessage(tp->impl, "IMU_GYRO_SCALED", DL_IMU_GYRO_SCALED, 0+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _gp); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _gq); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _gr); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_IMU_ACCEL_SCALED(struct DownlinkTransport *tp, int32_t *_ax, int32_t *_ay, int32_t *_az){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4)); 
	  tp->StartMessage(tp->impl, "IMU_ACCEL_SCALED", DL_IMU_ACCEL_SCALED, 0+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ax); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ay); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _az); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_IMU_MAG_SCALED(struct DownlinkTransport *tp, int32_t *_mx, int32_t *_my, int32_t *_mz){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4)); 
	  tp->StartMessage(tp->impl, "IMU_MAG_SCALED", DL_IMU_MAG_SCALED, 0+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _mx); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _my); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _mz); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_FILTER(struct DownlinkTransport *tp, int32_t *_phi, int32_t *_theta, int32_t *_psi, int32_t *_measure_phi, int32_t *_measure_theta, int32_t *_measure_psi, int32_t *_corrected_phi, int32_t *_corrected_theta, int32_t *_corrected_psi, int32_t *_correction_phi, int32_t *_correction_theta, int32_t *_correction_psi, int32_t *_bp, int32_t *_bq, int32_t *_br){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "FILTER", DL_FILTER, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _psi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _measure_phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _measure_theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _measure_psi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _corrected_phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _corrected_theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _corrected_psi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _correction_phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _correction_theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _correction_psi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _bp); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _bq); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _br); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_FILTER2(struct DownlinkTransport *tp, int32_t *_px, int32_t *_py, int32_t *_pz, int32_t *_gsx, int32_t *_gsy, int32_t *_gsz){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "FILTER2", DL_FILTER2, 0+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _px); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _py); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _pz); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _gsx); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _gsy); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _gsz); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_RATE_LOOP(struct DownlinkTransport *tp, int32_t *_sp_p, int32_t *_sp_q, int32_t *_sp_r, int32_t *_ref_p, int32_t *_ref_q, int32_t *_ref_r, int32_t *_refdot_p, int32_t *_refdot_q, int32_t *_refdot_r, int32_t *_sumerr_p, int32_t *_sumerr_q, int32_t *_sumerr_r, int32_t *_ff_p, int32_t *_ff_q, int32_t *_ff_r, int32_t *_fb_p, int32_t *_fb_q, int32_t *_fb_r, int32_t *_delta_t){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "RATE_LOOP", DL_RATE_LOOP, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _sp_p); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _sp_q); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _sp_r); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ref_p); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ref_q); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ref_r); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _refdot_p); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _refdot_q); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _refdot_r); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _sumerr_p); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _sumerr_q); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _sumerr_r); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ff_p); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ff_q); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ff_r); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _fb_p); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _fb_q); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _fb_r); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _delta_t); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_FILTER_ALIGNER(struct DownlinkTransport *tp, int32_t *_lp_gp, int32_t *_lp_gq, int32_t *_lp_gr, int32_t *_gp, int32_t *_gq, int32_t *_gr, int32_t *_noise, int32_t *_cnt, uint8_t *_status){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+1)); 
	  tp->StartMessage(tp->impl, "FILTER_ALIGNER", DL_FILTER_ALIGNER, 0+4+4+4+4+4+4+4+4+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _lp_gp); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _lp_gq); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _lp_gr); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _gp); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _gq); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _gr); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _noise); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _cnt); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _status); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_FILTER_COR(struct DownlinkTransport *tp, int32_t *_mphi, int32_t *_mtheta, int32_t *_mpsi, int32_t *_qi, int32_t *_qx, int32_t *_qy, int32_t *_qz){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "FILTER_COR", DL_FILTER_COR, 0+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _mphi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _mtheta); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _mpsi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _qi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _qx); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _qy); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _qz); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_STAB_ATTITUDE_INT(struct DownlinkTransport *tp, int32_t *_est_p, int32_t *_est_q, int32_t *_est_r, int32_t *_est_phi, int32_t *_est_theta, int32_t *_est_psi, int32_t *_sp_phi, int32_t *_sp_theta, int32_t *_sp_psi, int32_t *_sum_err_phi, int32_t *_sum_err_theta, int32_t *_sum_err_psi, int32_t *_delta_a_fb, int32_t *_delta_e_fb, int32_t *_delta_r_fb, int32_t *_delta_a_ff, int32_t *_delta_e_ff, int32_t *_delta_r_ff, int32_t *_delta_a, int32_t *_delta_e, int32_t *_delta_r){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "STAB_ATTITUDE_INT", DL_STAB_ATTITUDE_INT, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _est_p); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _est_q); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _est_r); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _est_phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _est_theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _est_psi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _sp_phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _sp_theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _sp_psi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _sum_err_phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _sum_err_theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _sum_err_psi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _delta_a_fb); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _delta_e_fb); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _delta_r_fb); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _delta_a_ff); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _delta_e_ff); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _delta_r_ff); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _delta_a); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _delta_e); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _delta_r); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_STAB_ATTITUDE_REF_INT(struct DownlinkTransport *tp, int32_t *_sp_phi, int32_t *_sp_theta, int32_t *_sp_psi, int32_t *_ref_phi, int32_t *_ref_theta, int32_t *_ref_psi, int32_t *_ref_p, int32_t *_ref_q, int32_t *_ref_r, int32_t *_ref_pd, int32_t *_ref_qd, int32_t *_ref_rd){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "STAB_ATTITUDE_REF_INT", DL_STAB_ATTITUDE_REF_INT, 0+4+4+4+4+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _sp_phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _sp_theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _sp_psi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ref_phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ref_theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ref_psi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ref_p); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ref_q); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ref_r); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ref_pd); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ref_qd); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ref_rd); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_STAB_ATTITUDE_REF_FLOAT(struct DownlinkTransport *tp, float *_sp_phi, float *_sp_theta, float *_sp_psi, float *_ref_phi, float *_ref_theta, float *_ref_psi, float *_ref_p, float *_ref_q, float *_ref_r, float *_ref_pd, float *_ref_qd, float *_ref_rd){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "STAB_ATTITUDE_REF_FLOAT", DL_STAB_ATTITUDE_REF_FLOAT, 0+4+4+4+4+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _sp_phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _sp_theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _sp_psi); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ref_phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ref_theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ref_psi); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ref_p); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ref_q); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ref_r); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ref_pd); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ref_qd); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ref_rd); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_ROTORCRAFT_CMD(struct DownlinkTransport *tp, int32_t *_cmd_roll, int32_t *_cmd_pitch, int32_t *_cmd_yaw, int32_t *_cmd_thrust){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "ROTORCRAFT_CMD", DL_ROTORCRAFT_CMD, 0+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _cmd_roll); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _cmd_pitch); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _cmd_yaw); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _cmd_thrust); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_GUIDANCE(struct DownlinkTransport *tp, int32_t *_pos_n, int32_t *_pos_e, int32_t *_sp_pos_n, int32_t *_sp_pos_e){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "GUIDANCE", DL_GUIDANCE, 0+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _pos_n); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _pos_e); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _sp_pos_n); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _sp_pos_e); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_VERT_LOOP(struct DownlinkTransport *tp, int32_t *_z_sp, int32_t *_zd_sp, int32_t *_est_z, int32_t *_est_zd, int32_t *_est_zdd, int32_t *_ref_z, int32_t *_ref_zd, int32_t *_ref_zdd, int32_t *_adp_inv_m, int32_t *_adp_cov, int32_t *_adp_meas, int32_t *_sum_err, int32_t *_ff_cmd, int32_t *_fb_cmd, int32_t *_delta_t){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "VERT_LOOP", DL_VERT_LOOP, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _z_sp); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _zd_sp); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _est_z); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _est_zd); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _est_zdd); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ref_z); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ref_zd); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ref_zdd); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _adp_inv_m); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _adp_cov); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _adp_meas); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _sum_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ff_cmd); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _fb_cmd); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _delta_t); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_HOVER_LOOP(struct DownlinkTransport *tp, int32_t *_sp_x, int32_t *_sp_y, int32_t *_est_x, int32_t *_est_y, int32_t *_est_xd, int32_t *_est_yd, int32_t *_est_xdd, int32_t *_est_ydd, int32_t *_err_x, int32_t *_err_y, int32_t *_err_xd, int32_t *_err_yd, int32_t *_err_sum_x, int32_t *_err_sum_y, int32_t *_err_nav_x, int32_t *_err_nav_y, int32_t *_cmd_x, int32_t *_cmd_y, int32_t *_cmd_phi, int32_t *_cmd_theta, int32_t *_cmd_psi){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "HOVER_LOOP", DL_HOVER_LOOP, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _sp_x); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _sp_y); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _est_x); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _est_y); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _est_xd); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _est_yd); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _est_xdd); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _est_ydd); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _err_x); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _err_y); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _err_xd); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _err_yd); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _err_sum_x); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _err_sum_y); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _err_nav_x); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _err_nav_y); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _cmd_x); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _cmd_y); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _cmd_phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _cmd_theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _cmd_psi); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_ROTORCRAFT_FP(struct DownlinkTransport *tp, int32_t *_east, int32_t *_north, int32_t *_up, int32_t *_veast, int32_t *_vnorth, int32_t *_vup, int32_t *_phi, int32_t *_theta, int32_t *_psi, int32_t *_carrot_east, int32_t *_carrot_north, int32_t *_carrot_up, int32_t *_carrot_psi, int32_t *_thrust, uint16_t *_flight_time){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+2)); 
	  tp->StartMessage(tp->impl, "ROTORCRAFT_FP", DL_ROTORCRAFT_FP, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _east); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _north); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _up); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _veast); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _vnorth); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _vup); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _psi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _carrot_east); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _carrot_north); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _carrot_up); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _carrot_psi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _thrust); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _flight_time); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BOOZ2_FMS_INFO(struct DownlinkTransport *tp, float *_tbd){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4)); 
	  tp->StartMessage(tp->impl, "BOOZ2_FMS_INFO", DL_BOOZ2_FMS_INFO, 0+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _tbd); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_GUIDANCE_H_REF_INT(struct DownlinkTransport *tp, int32_t *_sp_x, int32_t *_ref_x, int32_t *_ref_xd, int32_t *_ref_xdd, int32_t *_sp_y, int32_t *_ref_y, int32_t *_ref_yd, int32_t *_ref_ydd){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "GUIDANCE_H_REF_INT", DL_GUIDANCE_H_REF_INT, 0+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _sp_x); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ref_x); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ref_xd); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ref_xdd); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _sp_y); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ref_y); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ref_yd); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ref_ydd); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_ROTORCRAFT_TUNE_HOVER(struct DownlinkTransport *tp, int16_t *_rc_roll, int16_t *_rc_pitch, int16_t *_rc_yaw, int32_t *_cmd_roll, int32_t *_cmd_pitch, int32_t *_cmd_yaw, int32_t *_cmd_thrust, int32_t *_imu_phi, int32_t *_imu_theta, int32_t *_imu_psi, int32_t *_body_phi, int32_t *_body_theta, int32_t *_body_psi){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+4+4+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+4+4+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "ROTORCRAFT_TUNE_HOVER", DL_ROTORCRAFT_TUNE_HOVER, 0+2+2+2+4+4+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _rc_roll); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _rc_pitch); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _rc_yaw); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _cmd_roll); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _cmd_pitch); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _cmd_yaw); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _cmd_thrust); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _imu_phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _imu_theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _imu_psi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _body_phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _body_theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _body_psi); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_INS_Z(struct DownlinkTransport *tp, int32_t *_baro_alt, int32_t *_ins_z, int32_t *_ins_zd, int32_t *_ins_zdd){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "INS_Z", DL_INS_Z, 0+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _baro_alt); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ins_z); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ins_zd); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ins_zdd); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_PCAP01_STATUS(struct DownlinkTransport *tp, uint32_t *_ihumid, uint32_t *_itemp, float *_humid, float *_temp){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "PCAP01_STATUS", DL_PCAP01_STATUS, 0+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _ihumid); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _itemp); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _humid); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _temp); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_GEIGER_COUNTER(struct DownlinkTransport *tp, uint32_t *_tube1, uint32_t *_tube2, uint16_t *_vsupply){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+2)); 
	  tp->StartMessage(tp->impl, "GEIGER_COUNTER", DL_GEIGER_COUNTER, 0+4+4+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _tube1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _tube2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _vsupply); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_INS_REF(struct DownlinkTransport *tp, int32_t *_ecef_x0, int32_t *_ecef_y0, int32_t *_ecef_z0, int32_t *_lat0, int32_t *_lon0, int32_t *_alt0, int32_t *_hmsl0, int32_t *_baro_qfe){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "INS_REF", DL_INS_REF, 0+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ecef_x0); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ecef_y0); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ecef_z0); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _lat0); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _lon0); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _alt0); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _hmsl0); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _baro_qfe); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_GPS_INT(struct DownlinkTransport *tp, int32_t *_ecef_x, int32_t *_ecef_y, int32_t *_ecef_z, int32_t *_lat, int32_t *_lon, int32_t *_alt, int32_t *_hmsl, int32_t *_ecef_xd, int32_t *_ecef_yd, int32_t *_ecef_zd, int32_t *_pacc, int32_t *_sacc, uint32_t *_tow, uint16_t *_pdop, uint8_t *_numsv, uint8_t *_fix){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+2+1+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+2+1+1)); 
	  tp->StartMessage(tp->impl, "GPS_INT", DL_GPS_INT, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+2+1+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ecef_x); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ecef_y); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ecef_z); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _lat); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _lon); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _alt); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _hmsl); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ecef_xd); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ecef_yd); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ecef_zd); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _pacc); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _sacc); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _tow); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _pdop); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _numsv); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _fix); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_AHRS_EULER_INT(struct DownlinkTransport *tp, int32_t *_imu_phi, int32_t *_imu_theta, int32_t *_imu_psi, int32_t *_body_phi, int32_t *_body_theta, int32_t *_body_psi){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "AHRS_EULER_INT", DL_AHRS_EULER_INT, 0+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _imu_phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _imu_theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _imu_psi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _body_phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _body_theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _body_psi); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_AHRS_QUAT_INT(struct DownlinkTransport *tp, int32_t *_imu_qi, int32_t *_imu_qx, int32_t *_imu_qy, int32_t *_imu_qz, int32_t *_body_qi, int32_t *_body_qx, int32_t *_body_qy, int32_t *_body_qz){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "AHRS_QUAT_INT", DL_AHRS_QUAT_INT, 0+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _imu_qi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _imu_qx); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _imu_qy); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _imu_qz); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _body_qi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _body_qx); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _body_qy); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _body_qz); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_AHRS_RMAT_INT(struct DownlinkTransport *tp, int32_t *_imu_m00, int32_t *_imu_m01, int32_t *_imu_m02, int32_t *_imu_m10, int32_t *_imu_m11, int32_t *_imu_m12, int32_t *_imu_m20, int32_t *_imu_m21, int32_t *_imu_m22, int32_t *_body_m00, int32_t *_body_m01, int32_t *_body_m02, int32_t *_body_m10, int32_t *_body_m11, int32_t *_body_m12, int32_t *_body_m20, int32_t *_body_m21, int32_t *_body_m22){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "AHRS_RMAT_INT", DL_AHRS_RMAT_INT, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _imu_m00); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _imu_m01); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _imu_m02); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _imu_m10); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _imu_m11); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _imu_m12); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _imu_m20); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _imu_m21); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _imu_m22); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _body_m00); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _body_m01); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _body_m02); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _body_m10); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _body_m11); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _body_m12); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _body_m20); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _body_m21); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _body_m22); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_ROTORCRAFT_NAV_STATUS(struct DownlinkTransport *tp, uint16_t *_block_time, uint16_t *_stage_time, uint8_t *_cur_block, uint8_t *_cur_stage, uint8_t *_horizontal_mode){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2+1+1+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2+1+1+1)); 
	  tp->StartMessage(tp->impl, "ROTORCRAFT_NAV_STATUS", DL_ROTORCRAFT_NAV_STATUS, 0+2+2+1+1+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _block_time); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _stage_time); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _cur_block); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _cur_stage); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _horizontal_mode); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_ROTORCRAFT_RADIO_CONTROL(struct DownlinkTransport *tp, int16_t *_roll, int16_t *_pitch, int16_t *_yaw, int16_t *_throttle, int16_t *_mode, int16_t *_kill, uint8_t *_status){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+2+2+2+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+2+2+2+1)); 
	  tp->StartMessage(tp->impl, "ROTORCRAFT_RADIO_CONTROL", DL_ROTORCRAFT_RADIO_CONTROL, 0+2+2+2+2+2+2+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _roll); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _pitch); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _yaw); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _throttle); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _mode); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _kill); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _status); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_VFF(struct DownlinkTransport *tp, float *_measure, float *_z, float *_zd, float *_bias, float *_Pzz, float *_Pzdzd, float *_Pbb){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "VFF", DL_VFF, 0+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _measure); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _z); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _zd); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _bias); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _Pzz); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _Pzdzd); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _Pbb); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BOOZ2_TUNE_FF(struct DownlinkTransport *tp, float *_fb_rms, float *_dg, float *_g){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4)); 
	  tp->StartMessage(tp->impl, "BOOZ2_TUNE_FF", DL_BOOZ2_TUNE_FF, 0+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _fb_rms); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _dg); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _g); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_HFF(struct DownlinkTransport *tp, float *_x, float *_y, float *_xd, float *_yd, float *_xdd, float *_ydd){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "HFF", DL_HFF, 0+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _x); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _y); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _xd); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _yd); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _xdd); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ydd); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_HFF_DBG(struct DownlinkTransport *tp, float *_x_measure, float *_y_measure, float *_yd_measure, float *_xd_measure, float *_Pxx, float *_Pyy, float *_Pxdxd, float *_Pydyd){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "HFF_DBG", DL_HFF_DBG, 0+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _x_measure); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _y_measure); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _yd_measure); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _xd_measure); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _Pxx); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _Pyy); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _Pxdxd); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _Pydyd); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_HFF_GPS(struct DownlinkTransport *tp, uint16_t *_lag_cnt, int16_t *_lag_cnt_err, int16_t *_save_cnt){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2)); 
	  tp->StartMessage(tp->impl, "HFF_GPS", DL_HFF_GPS, 0+2+2+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _lag_cnt); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _lag_cnt_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _save_cnt); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BOOZ2_SONAR(struct DownlinkTransport *tp, uint16_t *_front, uint16_t *_back, uint16_t *_right, uint16_t *_left){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+2)); 
	  tp->StartMessage(tp->impl, "BOOZ2_SONAR", DL_BOOZ2_SONAR, 0+2+2+2+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _front); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _back); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _right); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _left); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BOOZ2_CAM(struct DownlinkTransport *tp, int16_t *_tilt, int16_t *_pan){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2)); 
	  tp->StartMessage(tp->impl, "BOOZ2_CAM", DL_BOOZ2_CAM, 0+2+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _tilt); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _pan); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_AHRS_REF_QUAT(struct DownlinkTransport *tp, int32_t *_ref_qi, int32_t *_ref_qx, int32_t *_ref_qy, int32_t *_ref_qz, int32_t *_body_qi, int32_t *_body_qx, int32_t *_body_qy, int32_t *_body_qz){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "AHRS_REF_QUAT", DL_AHRS_REF_QUAT, 0+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ref_qi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ref_qx); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ref_qy); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ref_qz); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _body_qi); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _body_qx); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _body_qy); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _body_qz); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_EKF7_XHAT(struct DownlinkTransport *tp, float *_c, float *_s1, float *_s2, float *_s3, float *_p, float *_q, float *_r, float *_bp, float *_bq, float *_br){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "EKF7_XHAT", DL_EKF7_XHAT, 0+4+4+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _c); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _s1); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _s2); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _s3); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _p); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _q); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _r); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _bp); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _bq); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _br); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_EKF7_Y(struct DownlinkTransport *tp, uint16_t *_timecount, float *_g1, float *_g2, float *_g3, float *_m1, float *_m2, float *_m3, float *_p, float *_q, float *_r){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+4+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+4+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "EKF7_Y", DL_EKF7_Y, 0+2+4+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _timecount); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _g1); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _g2); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _g3); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _m1); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _m2); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _m3); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _p); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _q); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _r); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_EKF7_P_DIAG(struct DownlinkTransport *tp, float *_c, float *_s1, float *_s2, float *_s3, float *_p, float *_q, float *_r, float *_bp, float *_bq, float *_br){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "EKF7_P_DIAG", DL_EKF7_P_DIAG, 0+4+4+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _c); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _s1); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _s2); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _s3); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _p); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _q); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _r); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _bp); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _bq); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _br); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_AHRS_EULER(struct DownlinkTransport *tp, float *_phi, float *_theta, float *_psi){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4)); 
	  tp->StartMessage(tp->impl, "AHRS_EULER", DL_AHRS_EULER, 0+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _psi); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_AHRS_MEASUREMENT_EULER(struct DownlinkTransport *tp, float *_phi, float *_theta, float *_psi){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4)); 
	  tp->StartMessage(tp->impl, "AHRS_MEASUREMENT_EULER", DL_AHRS_MEASUREMENT_EULER, 0+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _psi); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_WT(struct DownlinkTransport *tp, float *_rpm){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4)); 
	  tp->StartMessage(tp->impl, "WT", DL_WT, 0+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _rpm); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_CSC_CAN_DEBUG(struct DownlinkTransport *tp, uint32_t *_err_nb, uint32_t *_err_code){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4)); 
	  tp->StartMessage(tp->impl, "CSC_CAN_DEBUG", DL_CSC_CAN_DEBUG, 0+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _err_nb); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _err_code); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_CSC_CAN_MSG(struct DownlinkTransport *tp, uint32_t *_frame, uint32_t *_id, uint32_t *_data_a, uint32_t *_data_b){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "CSC_CAN_MSG", DL_CSC_CAN_MSG, 0+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _frame); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _id); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _data_a); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _data_b); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_AHRS_GYRO_BIAS_INT(struct DownlinkTransport *tp, int32_t *_bp, int32_t *_bq, int32_t *_br){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4)); 
	  tp->StartMessage(tp->impl, "AHRS_GYRO_BIAS_INT", DL_AHRS_GYRO_BIAS_INT, 0+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _bp); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _bq); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _br); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_FMS_TIME(struct DownlinkTransport *tp, uint32_t *_tv_sec, uint32_t *_tv_nsec, uint32_t *_delay_ns){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4)); 
	  tp->StartMessage(tp->impl, "FMS_TIME", DL_FMS_TIME, 0+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _tv_sec); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _tv_nsec); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _delay_ns); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_LOADCELL(struct DownlinkTransport *tp, int32_t *_load){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4)); 
	  tp->StartMessage(tp->impl, "LOADCELL", DL_LOADCELL, 0+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _load); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_FLA_DEBUG(struct DownlinkTransport *tp, float *_past_input, float *_imu_rate, float *_desired_accel, float *_motor_command){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "FLA_DEBUG", DL_FLA_DEBUG, 0+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _past_input); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _imu_rate); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _desired_accel); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _motor_command); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BLMC_FAULT_STATUS(struct DownlinkTransport *tp, uint8_t nb_raw_fault, uint16_t *_raw_fault){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+nb_raw_fault*2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+nb_raw_fault*2)); 
	  tp->StartMessage(tp->impl, "BLMC_FAULT_STATUS", DL_BLMC_FAULT_STATUS, 0+1+nb_raw_fault*2); 
	  tp->PutBytes(tp->impl, DL_TYPE_ARRAY_LENGTH, 1, (void *) &nb_raw_fault); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2 * nb_raw_fault, (void *) _raw_fault); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BLMC_SPEEDS(struct DownlinkTransport *tp, uint8_t nb_speeds, int16_t *_speeds){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+nb_speeds*2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+nb_speeds*2)); 
	  tp->StartMessage(tp->impl, "BLMC_SPEEDS", DL_BLMC_SPEEDS, 0+1+nb_speeds*2); 
	  tp->PutBytes(tp->impl, DL_TYPE_ARRAY_LENGTH, 1, (void *) &nb_speeds); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2 * nb_speeds, (void *) _speeds); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_AHRS_DEBUG_QUAT(struct DownlinkTransport *tp, float *_jqi, float *_jqx, float *_jqy, float *_jqz, float *_xqi, float *_xqx, float *_xqy, float *_xqz, float *_mqi, float *_mqx, float *_mqy, float *_mqz){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "AHRS_DEBUG_QUAT", DL_AHRS_DEBUG_QUAT, 0+4+4+4+4+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _jqi); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _jqx); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _jqy); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _jqz); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _xqi); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _xqx); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _xqy); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _xqz); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _mqi); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _mqx); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _mqy); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _mqz); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BLMC_BUSVOLTS(struct DownlinkTransport *tp, uint8_t nb_busvolts, uint16_t *_busvolts){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+nb_busvolts*2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+nb_busvolts*2)); 
	  tp->StartMessage(tp->impl, "BLMC_BUSVOLTS", DL_BLMC_BUSVOLTS, 0+1+nb_busvolts*2); 
	  tp->PutBytes(tp->impl, DL_TYPE_ARRAY_LENGTH, 1, (void *) &nb_busvolts); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2 * nb_busvolts, (void *) _busvolts); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_SYSTEM_STATUS(struct DownlinkTransport *tp, uint32_t *_csc1_loop_count, uint32_t *_csc1_msg_count, uint32_t *_csc2_loop_count, uint32_t *_csc2_msg_count, uint32_t *_can_rx_err, uint32_t *_can_tx_err, uint32_t *_rc_parser_err, uint8_t *_system_fault){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+1)); 
	  tp->StartMessage(tp->impl, "SYSTEM_STATUS", DL_SYSTEM_STATUS, 0+4+4+4+4+4+4+4+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _csc1_loop_count); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _csc1_msg_count); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _csc2_loop_count); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _csc2_msg_count); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _can_rx_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _can_tx_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _rc_parser_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _system_fault); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_DYNAMIXEL(struct DownlinkTransport *tp, uint16_t *_left_wing, uint16_t *_right_wing, uint8_t *_left_wing_flag, uint8_t *_right_wing_flag, uint32_t *_invalid_position, uint32_t *_timeout_events, uint32_t *_checksum_errors, float *_fuse_rotation_angle, float *_fuse_rotation_rate){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2+1+1+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2+1+1+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "DYNAMIXEL", DL_DYNAMIXEL, 0+2+2+1+1+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _left_wing); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _right_wing); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _left_wing_flag); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _right_wing_flag); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _invalid_position); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _timeout_events); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _checksum_errors); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _fuse_rotation_angle); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _fuse_rotation_rate); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_RMAT_DEBUG(struct DownlinkTransport *tp, float *_a, float *_b, float *_c, float *_d, float *_e, float *_f, float *_g, float *_h, float *_i){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "RMAT_DEBUG", DL_RMAT_DEBUG, 0+4+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _a); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _b); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _c); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _d); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _e); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _f); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _g); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _h); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _i); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_SIMPLE_COMMANDS(struct DownlinkTransport *tp, int16_t *_roll, int16_t *_pitch, int16_t *_yaw){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2)); 
	  tp->StartMessage(tp->impl, "SIMPLE_COMMANDS", DL_SIMPLE_COMMANDS, 0+2+2+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _roll); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _pitch); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _yaw); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_VANE_SENSOR(struct DownlinkTransport *tp, float *_alpha, float *_alpha_filtered, float *_alpha_target, float *_alpha_vane_error, float *_alpha2, float *_beta, float *_beta_filtered, float *_beta_target, float *_beta_vane_error, float *_beta2){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "VANE_SENSOR", DL_VANE_SENSOR, 0+4+4+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _alpha); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _alpha_filtered); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _alpha_target); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _alpha_vane_error); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _alpha2); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _beta); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _beta_filtered); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _beta_target); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _beta_vane_error); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _beta2); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_CONTROLLER_GAINS(struct DownlinkTransport *tp, float *_roll_gamma_p, float *_roll_gamma_d, float *_roll_gamma_i, float *_pitch_gamma_p, float *_pitch_gamma_d, float *_pitch_gamma_i, float *_yaw_gamma_p, float *_yaw_gamma_d, float *_yaw_gamma_i){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "CONTROLLER_GAINS", DL_CONTROLLER_GAINS, 0+4+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _roll_gamma_p); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _roll_gamma_d); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _roll_gamma_i); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _pitch_gamma_p); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _pitch_gamma_d); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _pitch_gamma_i); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _yaw_gamma_p); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _yaw_gamma_d); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _yaw_gamma_i); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_AHRS_LKF(struct DownlinkTransport *tp, float *_phi, float *_theta, float *_psi, float *_qi, float *_qx, float *_qy, float *_qz, float *_p, float *_q, float *_r, float *_ax, float *_ay, float *_az, float *_mx, float *_my, float *_mz){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "AHRS_LKF", DL_AHRS_LKF, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _psi); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _qi); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _qx); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _qy); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _qz); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _p); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _q); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _r); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ax); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ay); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _az); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _mx); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _my); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _mz); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_AHRS_LKF_DEBUG(struct DownlinkTransport *tp, float *_phi_err, float *_theta_err, float *_psi_err, float *_bp, float *_bq, float *_br, float *_quat_norm, float *_phi_accel, float *_theta_accel, float *_phi_cov, float *_theta_cov, float *_psi_cov, float *_bp_cov, float *_bq_cov, float *_br_cov){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "AHRS_LKF_DEBUG", DL_AHRS_LKF_DEBUG, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _phi_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _theta_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _psi_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _bp); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _bq); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _br); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _quat_norm); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _phi_accel); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _theta_accel); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _phi_cov); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _theta_cov); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _psi_cov); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _bp_cov); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _bq_cov); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _br_cov); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_AHRS_LKF_ACC_DBG(struct DownlinkTransport *tp, float *_qi_err, float *_qx_err, float *_qy_err, float *_qz_err, float *_bp_err, float *_bq_err, float *_br_err){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "AHRS_LKF_ACC_DBG", DL_AHRS_LKF_ACC_DBG, 0+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _qi_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _qx_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _qy_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _qz_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _bp_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _bq_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _br_err); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_AHRS_LKF_MAG_DBG(struct DownlinkTransport *tp, float *_qi_err, float *_qx_err, float *_qy_err, float *_qz_err, float *_bp_err, float *_bq_err, float *_br_err){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "AHRS_LKF_MAG_DBG", DL_AHRS_LKF_MAG_DBG, 0+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _qi_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _qx_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _qy_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _qz_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _bp_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _bq_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _br_err); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_NPS_SENSORS_SCALED(struct DownlinkTransport *tp, float *_acc_x, float *_acc_y, float *_acc_z, float *_mag_x, float *_mag_y, float *_mag_z){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "NPS_SENSORS_SCALED", DL_NPS_SENSORS_SCALED, 0+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _acc_x); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _acc_y); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _acc_z); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _mag_x); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _mag_y); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _mag_z); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_INS(struct DownlinkTransport *tp, int32_t *_ins_x, int32_t *_ins_y, int32_t *_ins_z, int32_t *_ins_xd, int32_t *_ins_yd, int32_t *_ins_zd, int32_t *_ins_xdd, int32_t *_ins_ydd, int32_t *_ins_zdd){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "INS", DL_INS, 0+4+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ins_x); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ins_y); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ins_z); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ins_xd); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ins_yd); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ins_zd); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ins_xdd); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ins_ydd); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ins_zdd); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_GPS_ERROR(struct DownlinkTransport *tp, float *_x_position, float *_y_position, float *_z_position, float *_x_velocity, float *_y_velocity, float *_z_velocity){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "GPS_ERROR", DL_GPS_ERROR, 0+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _x_position); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _y_position); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _z_position); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _x_velocity); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _y_velocity); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _z_velocity); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_IMU_GYRO(struct DownlinkTransport *tp, float *_gp, float *_gq, float *_gr){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4)); 
	  tp->StartMessage(tp->impl, "IMU_GYRO", DL_IMU_GYRO, 0+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _gp); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _gq); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _gr); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_IMU_MAG(struct DownlinkTransport *tp, float *_mx, float *_my, float *_mz){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4)); 
	  tp->StartMessage(tp->impl, "IMU_MAG", DL_IMU_MAG, 0+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _mx); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _my); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _mz); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_IMU_ACCEL(struct DownlinkTransport *tp, float *_ax, float *_ay, float *_az){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4)); 
	  tp->StartMessage(tp->impl, "IMU_ACCEL", DL_IMU_ACCEL, 0+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ax); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ay); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _az); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_IMU_GYRO_RAW(struct DownlinkTransport *tp, int32_t *_gp, int32_t *_gq, int32_t *_gr){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4)); 
	  tp->StartMessage(tp->impl, "IMU_GYRO_RAW", DL_IMU_GYRO_RAW, 0+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _gp); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _gq); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _gr); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_IMU_ACCEL_RAW(struct DownlinkTransport *tp, int32_t *_ax, int32_t *_ay, int32_t *_az){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4)); 
	  tp->StartMessage(tp->impl, "IMU_ACCEL_RAW", DL_IMU_ACCEL_RAW, 0+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ax); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _ay); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _az); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_IMU_MAG_RAW(struct DownlinkTransport *tp, int32_t *_mx, int32_t *_my, int32_t *_mz){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4)); 
	  tp->StartMessage(tp->impl, "IMU_MAG_RAW", DL_IMU_MAG_RAW, 0+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _mx); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _my); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _mz); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_IMU_MAG_SETTINGS(struct DownlinkTransport *tp, float *_inclination, float *_declination, float *_hardiron_x, float *_hardiron_y, float *_hardiron_z){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "IMU_MAG_SETTINGS", DL_IMU_MAG_SETTINGS, 0+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _inclination); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _declination); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _hardiron_x); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _hardiron_y); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _hardiron_z); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_IMU_GYRO_LP(struct DownlinkTransport *tp, float *_gp, float *_gq, float *_gr){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4)); 
	  tp->StartMessage(tp->impl, "IMU_GYRO_LP", DL_IMU_GYRO_LP, 0+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _gp); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _gq); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _gr); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_IMU_PRESSURE(struct DownlinkTransport *tp, float *_p){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4)); 
	  tp->StartMessage(tp->impl, "IMU_PRESSURE", DL_IMU_PRESSURE, 0+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _p); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_IMU_HS_GYRO(struct DownlinkTransport *tp, uint8_t *_axis, uint8_t nb_samples, uint32_t *_samples){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+nb_samples*4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+nb_samples*4)); 
	  tp->StartMessage(tp->impl, "IMU_HS_GYRO", DL_IMU_HS_GYRO, 0+1+1+nb_samples*4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _axis); 
	  tp->PutBytes(tp->impl, DL_TYPE_ARRAY_LENGTH, 1, (void *) &nb_samples); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4 * nb_samples, (void *) _samples); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_TEST_PASSTHROUGH_STATUS(struct DownlinkTransport *tp, uint32_t *_io_proc_msg_cnt, uint32_t *_io_proc_err_cnt, uint32_t *_io_link_msg_cnt, uint32_t *_io_link_err_cnt, uint8_t *_rc_status){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+1)); 
	  tp->StartMessage(tp->impl, "TEST_PASSTHROUGH_STATUS", DL_TEST_PASSTHROUGH_STATUS, 0+4+4+4+4+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _io_proc_msg_cnt); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _io_proc_err_cnt); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _io_link_msg_cnt); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _io_link_err_cnt); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _rc_status); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_WEATHER(struct DownlinkTransport *tp, float *_p_amb, float *_t_amb, float *_windspeed, float *_wind_from, float *_humidity){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "WEATHER", DL_WEATHER, 0+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _p_amb); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _t_amb); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _windspeed); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _wind_from); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _humidity); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_IMU_TURNTABLE(struct DownlinkTransport *tp, float *_omega){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4)); 
	  tp->StartMessage(tp->impl, "IMU_TURNTABLE", DL_IMU_TURNTABLE, 0+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _omega); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BARO_RAW(struct DownlinkTransport *tp, int32_t *_abs, int32_t *_diff){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4)); 
	  tp->StartMessage(tp->impl, "BARO_RAW", DL_BARO_RAW, 0+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _abs); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _diff); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_TIME(struct DownlinkTransport *tp, uint32_t *_t){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4)); 
	  tp->StartMessage(tp->impl, "TIME", DL_TIME, 0+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _t); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_ROTORCRAFT_STATUS(struct DownlinkTransport *tp, uint32_t *_link_imu_nb_err, uint8_t *_blmc_nb_err, uint8_t *_rc_status, uint8_t *_frame_rate, uint8_t *_gps_status, uint8_t *_ap_mode, uint8_t *_ap_in_flight, uint8_t *_ap_motors_on, uint8_t *_ap_h_mode, uint8_t *_ap_v_mode, uint8_t *_vsupply, uint16_t *_cpu_time){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+1+1+1+1+1+1+1+1+1+1+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+1+1+1+1+1+1+1+1+1+1+2)); 
	  tp->StartMessage(tp->impl, "ROTORCRAFT_STATUS", DL_ROTORCRAFT_STATUS, 0+4+1+1+1+1+1+1+1+1+1+1+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _link_imu_nb_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _blmc_nb_err); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _rc_status); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _frame_rate); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _gps_status); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ap_mode); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ap_in_flight); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ap_motors_on); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ap_h_mode); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ap_v_mode); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _vsupply); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _cpu_time); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_STATE_FILTER_STATUS(struct DownlinkTransport *tp, uint8_t *_state_filter_mode, uint16_t *_value){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+2)); 
	  tp->StartMessage(tp->impl, "STATE_FILTER_STATUS", DL_STATE_FILTER_STATUS, 0+1+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _state_filter_mode); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _value); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_OPTICFLOW(struct DownlinkTransport *tp, uint16_t *_flow, float *_ref_alt){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+4)); 
	  tp->StartMessage(tp->impl, "OPTICFLOW", DL_OPTICFLOW, 0+2+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _flow); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ref_alt); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_VISUALTARGET(struct DownlinkTransport *tp, uint16_t *_x, uint16_t *_y){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2)); 
	  tp->StartMessage(tp->impl, "VISUALTARGET", DL_VISUALTARGET, 0+2+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _x); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _y); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_NPS_POS_LLH(struct DownlinkTransport *tp, float *_pprz_lat, float *_lat_geod, float *_lat_geoc, float *_pprz_lon, float *_lon, float *_pprz_alt, float *_alt_geod, float *_agl, float *_asl){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "NPS_POS_LLH", DL_NPS_POS_LLH, 0+4+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _pprz_lat); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _lat_geod); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _lat_geoc); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _pprz_lon); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _lon); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _pprz_alt); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _alt_geod); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _agl); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _asl); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_NPS_RPMS(struct DownlinkTransport *tp, float *_front, float *_back, float *_right, float *_left){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "NPS_RPMS", DL_NPS_RPMS, 0+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _front); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _back); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _right); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _left); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_NPS_SPEED_POS(struct DownlinkTransport *tp, float *_ltpp_xdd, float *_ltpp_ydd, float *_ltpp_zdd, float *_ltpp_xd, float *_ltpp_yd, float *_ltpp_zd, float *_ltpp_x, float *_ltpp_y, float *_ltpp_z){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "NPS_SPEED_POS", DL_NPS_SPEED_POS, 0+4+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ltpp_xdd); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ltpp_ydd); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ltpp_zdd); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ltpp_xd); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ltpp_yd); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ltpp_zd); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ltpp_x); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ltpp_y); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ltpp_z); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_NPS_RATE_ATTITUDE(struct DownlinkTransport *tp, float *_p, float *_q, float *_r, float *_phi, float *_theta, float *_psi){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "NPS_RATE_ATTITUDE", DL_NPS_RATE_ATTITUDE, 0+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _p); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _q); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _r); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _psi); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_NPS_GYRO_BIAS(struct DownlinkTransport *tp, float *_bp, float *_bq, float *_br){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4)); 
	  tp->StartMessage(tp->impl, "NPS_GYRO_BIAS", DL_NPS_GYRO_BIAS, 0+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _bp); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _bq); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _br); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_NPS_RANGE_METER(struct DownlinkTransport *tp, float *_dist){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4)); 
	  tp->StartMessage(tp->impl, "NPS_RANGE_METER", DL_NPS_RANGE_METER, 0+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _dist); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_NPS_WIND(struct DownlinkTransport *tp, float *_vx, float *_vy, float *_vz){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4)); 
	  tp->StartMessage(tp->impl, "NPS_WIND", DL_NPS_WIND, 0+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _vx); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _vy); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _vz); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BOOZ_DEBUG_FOO(struct DownlinkTransport *tp, uint8_t *_ami_stat){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1)); 
	  tp->StartMessage(tp->impl, "BOOZ_DEBUG_FOO", DL_BOOZ_DEBUG_FOO, 0+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ami_stat); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BOOZ_MAX1167_ERR(struct DownlinkTransport *tp, uint8_t *_erno){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1)); 
	  tp->StartMessage(tp->impl, "BOOZ_MAX1167_ERR", DL_BOOZ_MAX1167_ERR, 0+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _erno); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_PPRZ_DEBUG(struct DownlinkTransport *tp, uint8_t *_module, uint8_t *_errno){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1)); 
	  tp->StartMessage(tp->impl, "PPRZ_DEBUG", DL_PPRZ_DEBUG, 0+1+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _module); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _errno); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_NPS_ACCEL_LTP(struct DownlinkTransport *tp, float *_xdd, float *_ydd, float *_zdd){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4)); 
	  tp->StartMessage(tp->impl, "NPS_ACCEL_LTP", DL_NPS_ACCEL_LTP, 0+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _xdd); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _ydd); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _zdd); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_LOOSE_INS_GPS(struct DownlinkTransport *tp, uint8_t *_status, double *_time_running, double *_q0, double *_q1, double *_q2, double *_q3, double *_phi, double *_theta, double *_psi, double *_north, double *_east, double *_down, double *_v_north, double *_v_east, double *_v_down, double *_est_p, double *_est_q, double *_est_r, double *_gyroBias_x, double *_gyroBias_y, double *_gyroBias_z, uint32_t *_imuCallbacks, uint32_t *_gpsCallbacks, uint32_t *_baroCallbacks){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+4+4+4)); 
	  tp->StartMessage(tp->impl, "LOOSE_INS_GPS", DL_LOOSE_INS_GPS, 0+1+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _status); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _time_running); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _q0); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _q1); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _q2); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _q3); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _psi); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _north); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _east); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _down); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _v_north); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _v_east); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _v_down); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _est_p); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _est_q); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _est_r); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _gyroBias_x); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _gyroBias_y); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _gyroBias_z); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _imuCallbacks); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _gpsCallbacks); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _baroCallbacks); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_AFL_COEFFS(struct DownlinkTransport *tp, float *_roll_a, float *_roll_b, float *_roll_c, float *_pitch_a, float *_pitch_b, float *_pitch_c, float *_yaw_a, float *_yaw_b, float *_yaw_c){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "AFL_COEFFS", DL_AFL_COEFFS, 0+4+4+4+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _roll_a); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _roll_b); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _roll_c); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _pitch_a); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _pitch_b); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _pitch_c); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _yaw_a); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _yaw_b); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _yaw_c); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BOOZ_ATT_REF_MODEL(struct DownlinkTransport *tp, float *_omega_p, float *_zeta_p, float *_omega_q, float *_zeta_q, float *_omega_r, float *_zeta_r){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "BOOZ_ATT_REF_MODEL", DL_BOOZ_ATT_REF_MODEL, 0+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _omega_p); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _zeta_p); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _omega_q); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _zeta_q); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _omega_r); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _zeta_r); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BOOZ2_FF_ADAP(struct DownlinkTransport *tp, float *_roll, float *_pitch, float *_yaw){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4)); 
	  tp->StartMessage(tp->impl, "BOOZ2_FF_ADAP", DL_BOOZ2_FF_ADAP, 0+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _roll); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _pitch); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _yaw); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_I2C_ERRORS(struct DownlinkTransport *tp, uint16_t *_acknowledge_failure_cnt, uint16_t *_misplaced_start_or_stop_cnt, uint16_t *_arbitration_lost_cnt, uint16_t *_overrun_or_underrun_cnt, uint16_t *_pec_error_in_reception_cnt, uint16_t *_timeout_or_tlow_error_cnt, uint16_t *_smbus_alert_cnt, uint16_t *_unexpected_event_cnt, uint32_t *_last_unexpected_event, uint8_t *_bus_number){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+2+2+2+2+2+4+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+2+2+2+2+2+4+1)); 
	  tp->StartMessage(tp->impl, "I2C_ERRORS", DL_I2C_ERRORS, 0+2+2+2+2+2+2+2+2+4+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _acknowledge_failure_cnt); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _misplaced_start_or_stop_cnt); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _arbitration_lost_cnt); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _overrun_or_underrun_cnt); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _pec_error_in_reception_cnt); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _timeout_or_tlow_error_cnt); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _smbus_alert_cnt); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _unexpected_event_cnt); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _last_unexpected_event); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _bus_number); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_RDYB_TRAJECTORY(struct DownlinkTransport *tp, float *_commanded_phi, float *_commanded_theta, float *_commanded_psi, float *_setpoint_x, float *_setpoint_y, float *_setpoint_z){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+4+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "RDYB_TRAJECTORY", DL_RDYB_TRAJECTORY, 0+4+4+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _commanded_phi); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _commanded_theta); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _commanded_psi); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _setpoint_x); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _setpoint_y); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _setpoint_z); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_HENRY_GNSS(struct DownlinkTransport *tp, uint32_t *_last_imu_update, double *_GPS_time, uint8_t *_GPS_solution_valid, double *_latitude, double *_longitude, double *_altitude, double *_North, double *_East, double *_Down, uint8_t *_SVs_Tracked, uint8_t *_SVs_PVT, double *_V_North, double *_V_East, double *_V_Down){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+4+8+1+8+8+8+8+8+8+1+1+8+8+8))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+4+8+1+8+8+8+8+8+8+1+1+8+8+8)); 
	  tp->StartMessage(tp->impl, "HENRY_GNSS", DL_HENRY_GNSS, 0+4+8+1+8+8+8+8+8+8+1+1+8+8+8); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _last_imu_update); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _GPS_time); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _GPS_solution_valid); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _latitude); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _longitude); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _altitude); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _North); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _East); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _Down); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _SVs_Tracked); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _SVs_PVT); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _V_North); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _V_East); 
	  tp->PutBytes(tp->impl, DL_TYPE_DOUBLE, 8, (void *) _V_Down); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

#else // DOWNLINK
void DOWNLINK_SEND_BOOT(struct DownlinkTransport *tp, uint16_t *_version) {}
void DOWNLINK_SEND_ALIVE(struct DownlinkTransport *tp, uint8_t nb_md5sum, uint8_t *_md5sum) {}
void DOWNLINK_SEND_PONG(struct DownlinkTransport *tp) {}
void DOWNLINK_SEND_TAKEOFF(struct DownlinkTransport *tp, uint16_t *_cpu_time) {}
void DOWNLINK_SEND_ATTITUDE(struct DownlinkTransport *tp, float *_phi, float *_psi, float *_theta) {}
void DOWNLINK_SEND_IR_SENSORS(struct DownlinkTransport *tp, int16_t *_ir1, int16_t *_ir2, int16_t *_longitudinal, int16_t *_lateral, int16_t *_vertical) {}
void DOWNLINK_SEND_GPS(struct DownlinkTransport *tp, uint8_t *_mode, int32_t *_utm_east, int32_t *_utm_north, int16_t *_course, int32_t *_alt, uint16_t *_speed, int16_t *_climb, uint16_t *_week, uint32_t *_itow, uint8_t *_utm_zone, uint8_t *_gps_nb_err) {}
void DOWNLINK_SEND_NAVIGATION_REF(struct DownlinkTransport *tp, int32_t *_utm_east, int32_t *_utm_north, uint8_t *_utm_zone) {}
void DOWNLINK_SEND_NAVIGATION(struct DownlinkTransport *tp, uint8_t *_cur_block, uint8_t *_cur_stage, float *_pos_x, float *_pos_y, float *_dist2_wp, float *_dist2_home, uint8_t *_circle_count, uint8_t *_oval_count) {}
void DOWNLINK_SEND_PPRZ_MODE(struct DownlinkTransport *tp, uint8_t *_ap_mode, uint8_t *_ap_gaz, uint8_t *_ap_lateral, uint8_t *_ap_horizontal, uint8_t *_if_calib_mode, uint8_t *_mcu1_status) {}
void DOWNLINK_SEND_BAT(struct DownlinkTransport *tp, int16_t *_throttle, uint8_t *_voltage, int16_t *_amps, uint16_t *_flight_time, uint8_t *_kill_auto_throttle, uint16_t *_block_time, uint16_t *_stage_time, int16_t *_energy) {}
void DOWNLINK_SEND_DEBUG_MCU_LINK(struct DownlinkTransport *tp, uint8_t *_i2c_nb_err, uint8_t *_i2c_mcu1_nb_err, uint8_t *_ppm_rate) {}
void DOWNLINK_SEND_CALIBRATION(struct DownlinkTransport *tp, float *_climb_sum_err, uint8_t *_climb_gaz_submode) {}
void DOWNLINK_SEND_SETTINGS(struct DownlinkTransport *tp, float *_slider_1_val, float *_slider_2_val) {}
void DOWNLINK_SEND_DESIRED(struct DownlinkTransport *tp, float *_roll, float *_pitch, float *_course, float *_x, float *_y, float *_altitude, float *_climb) {}
void DOWNLINK_SEND_GPS_SOL(struct DownlinkTransport *tp, uint32_t *_Pacc, uint32_t *_Sacc, uint16_t *_PDOP, uint8_t *_numSV) {}
void DOWNLINK_SEND_ADC_GENERIC(struct DownlinkTransport *tp, uint16_t *_val1, uint16_t *_val2) {}
void DOWNLINK_SEND_TEST_FORMAT(struct DownlinkTransport *tp, double *_val1, float *_val2) {}
void DOWNLINK_SEND_CAM(struct DownlinkTransport *tp, int16_t *_phi, int16_t *_theta, int16_t *_target_x, int16_t *_target_y) {}
void DOWNLINK_SEND_CIRCLE(struct DownlinkTransport *tp, float *_center_east, float *_center_north, float *_radius) {}
void DOWNLINK_SEND_SEGMENT(struct DownlinkTransport *tp, float *_segment_east_1, float *_segment_north_1, float *_segment_east_2, float *_segment_north_2) {}
void DOWNLINK_SEND_DOWNLINK_STATUS(struct DownlinkTransport *tp, uint32_t *_run_time, uint32_t *_rx_bytes, uint32_t *_rx_msgs, uint32_t *_rx_err, float *_rx_bytes_rate, float *_rx_msgs_rate, float *_ping_time) {}
void DOWNLINK_SEND_MODEM_STATUS(struct DownlinkTransport *tp, uint8_t *_detected, float *_valim, uint8_t *_cd, uint32_t *_nb_byte, uint32_t *_nb_msg, uint32_t *_nb_err) {}
void DOWNLINK_SEND_SVINFO(struct DownlinkTransport *tp, uint8_t *_chn, uint8_t *_SVID, uint8_t *_Flags, uint8_t *_QI, uint8_t *_CNO, int8_t *_Elev, int16_t *_Azim) {}
void DOWNLINK_SEND_DEBUG(struct DownlinkTransport *tp, uint8_t nb_msg, uint8_t *_msg) {}
void DOWNLINK_SEND_SURVEY(struct DownlinkTransport *tp, float *_east, float *_north, float *_west, float *_south) {}
void DOWNLINK_SEND_WC_RSSI(struct DownlinkTransport *tp, uint8_t *_raw_level) {}
void DOWNLINK_SEND_RANGEFINDER(struct DownlinkTransport *tp, uint16_t *_range, float *_z_dot, float *_z_dot_sum_err, float *_z_dot_setpoint, float *_z_sum_err, float *_z_setpoint, uint8_t *_flying) {}
void DOWNLINK_SEND_DOWNLINK(struct DownlinkTransport *tp, uint8_t *_nb_ovrn, uint16_t *_rate, uint16_t *_nb_msgs) {}
void DOWNLINK_SEND_DL_VALUE(struct DownlinkTransport *tp, uint8_t *_index, float *_value) {}
void DOWNLINK_SEND_MARK(struct DownlinkTransport *tp, uint8_t *_ac_id, float *_lat, float *_long) {}
void DOWNLINK_SEND_SYS_MON(struct DownlinkTransport *tp, uint16_t *_periodic_time, uint16_t *_periodic_cycle, uint16_t *_periodic_cycle_min, uint16_t *_periodic_cycle_max, uint16_t *_event_number, uint8_t *_cpu_load) {}
void DOWNLINK_SEND_MOTOR(struct DownlinkTransport *tp, uint16_t *_rpm, int32_t *_current) {}
void DOWNLINK_SEND_WP_MOVED(struct DownlinkTransport *tp, uint8_t *_wp_id, float *_utm_east, float *_utm_north, float *_alt, uint8_t *_utm_zone) {}
void DOWNLINK_SEND_ENERGY(struct DownlinkTransport *tp, float *_bat, float *_amp, uint16_t *_energy, float *_power) {}
void DOWNLINK_SEND_BARO_BMP85_CALIB(struct DownlinkTransport *tp, int16_t *_a1, int16_t *_a2, int16_t *_a3, uint16_t *_a4, uint16_t *_a5, uint16_t *_a6, int16_t *_b1, int16_t *_b2, int16_t *_mb, int16_t *_mc, int16_t *_md) {}
void DOWNLINK_SEND_BARO_BMP85(struct DownlinkTransport *tp, int32_t *_UT, int32_t *_UP, uint32_t *_P, float *_T, float *_MSL) {}
void DOWNLINK_SEND_SPEED_LOOP(struct DownlinkTransport *tp, float *_ve_set_point, float *_ve, float *_vn_set_point, float *_vn, float *_north_sp, float *_east_sp) {}
void DOWNLINK_SEND_ALT_KALMAN(struct DownlinkTransport *tp, float *_p00, float *_p01, float *_p10, float *_p11) {}
void DOWNLINK_SEND_ESTIMATOR(struct DownlinkTransport *tp, float *_z, float *_z_dot) {}
void DOWNLINK_SEND_TUNE_ROLL(struct DownlinkTransport *tp, float *_p, float *_phi, float *_phi_sp) {}
void DOWNLINK_SEND_BARO_MS5534A(struct DownlinkTransport *tp, uint32_t *_pressure, uint16_t *_temp, float *_alt) {}
void DOWNLINK_SEND_PRESSURE(struct DownlinkTransport *tp, float *_airspeed_adc, float *_airspeed, float *_altitude_adc, float *_altitude) {}
void DOWNLINK_SEND_BARO_WORDS(struct DownlinkTransport *tp, uint16_t *_w1, uint16_t *_w2, uint16_t *_w3, uint16_t *_w4) {}
void DOWNLINK_SEND_WP_MOVED_LLA(struct DownlinkTransport *tp, uint8_t *_wp_id, int32_t *_lat, int32_t *_lon, int32_t *_alt) {}
void DOWNLINK_SEND_CHRONO(struct DownlinkTransport *tp, uint8_t *_tag, uint32_t *_time) {}
void DOWNLINK_SEND_WP_MOVED_ENU(struct DownlinkTransport *tp, uint8_t *_wp_id, int32_t *_east, int32_t *_north, int32_t *_up) {}
void DOWNLINK_SEND_WINDTURBINE_STATUS_(struct DownlinkTransport *tp, uint8_t *_ac_id, uint8_t *_tb_id, uint32_t *_sync_itow, uint32_t *_cycle_time) {}
void DOWNLINK_SEND_RC_3CH_(struct DownlinkTransport *tp, uint8_t *_throttle_mode, int8_t *_roll, int8_t *_pitch) {}
void DOWNLINK_SEND_MPPT(struct DownlinkTransport *tp, uint8_t nb_values, int16_t *_values) {}
void DOWNLINK_SEND_DEBUG_IR_I2C(struct DownlinkTransport *tp, int16_t *_ir1, int16_t *_ir2, int16_t *_top) {}
void DOWNLINK_SEND_AIRSPEED(struct DownlinkTransport *tp, float *_airspeed, float *_airspeed_sp, float *_airspeed_cnt, float *_groundspeed_sp) {}
void DOWNLINK_SEND_XSENS(struct DownlinkTransport *tp, int16_t *_counter, float *_p, float *_q, float *_r, float *_phi, float *_theta, float *_psi, float *_ax, float *_ay, float *_az, float *_vx, float *_vy, float *_vz, float *_lat, float *_lon, float *_alt, uint8_t *_status, uint8_t *_hour, uint8_t *_min, uint8_t *_sec, uint32_t *_nanosec, uint16_t *_year, uint8_t *_month, uint8_t *_day) {}
void DOWNLINK_SEND_BARO_ETS(struct DownlinkTransport *tp, uint16_t *_adc, uint16_t *_offset, float *_scaled) {}
void DOWNLINK_SEND_AIRSPEED_ETS(struct DownlinkTransport *tp, uint16_t *_adc, uint16_t *_offset, float *_scaled) {}
void DOWNLINK_SEND_PBN(struct DownlinkTransport *tp, uint16_t *_airspeed_adc, uint16_t *_altitude_adc, float *_airspeed, float *_altitude, uint16_t *_airspeed_offset, uint16_t *_altitude_offset) {}
void DOWNLINK_SEND_GPS_LLA(struct DownlinkTransport *tp, int32_t *_lat, int32_t *_lon, int32_t *_alt, int16_t *_course, uint16_t *_speed, int16_t *_climb, uint16_t *_week, uint32_t *_itow, uint8_t *_mode, uint8_t *_gps_nb_err) {}
void DOWNLINK_SEND_H_CTL_A(struct DownlinkTransport *tp, float *_roll_sum_err, float *_ref_roll_angle, float *_pitch_sum_err, float *_ref_pitch_angle) {}
void DOWNLINK_SEND_TURB_PRESSURE_RAW(struct DownlinkTransport *tp, int32_t *_ch_0, int32_t *_ch_1, int32_t *_ch_2, int32_t *_ch_3, int32_t *_ch_4, int32_t *_ch_5, int32_t *_ch_6, int32_t *_ch_7, int32_t *_ch_8, int32_t *_ch_9, int32_t *_ch_10, int32_t *_ch_11, int32_t *_ch_12, int32_t *_ch_13, int32_t *_ch_14, int32_t *_ch_15) {}
void DOWNLINK_SEND_TURB_PRESSURE_VOLTAGE(struct DownlinkTransport *tp, float *_ch_1_p, float *_ch_1_t, float *_ch_2_p, float *_ch_2_t, float *_ch_3_p, float *_ch_3_t, float *_ch_4_p, float *_ch_4_t, float *_ch_5_p, float *_ch_5_t, float *_ch_6_p, float *_ch_6_t, float *_ch_7_p, float *_ch_7_t, float *_gnd1, float *_gnd2) {}
void DOWNLINK_SEND_CAM_POINT(struct DownlinkTransport *tp, uint16_t *_cam_point_distance_from_home, float *_cam_point_lat, float *_cam_point_lon) {}
void DOWNLINK_SEND_DC_INFO(struct DownlinkTransport *tp, int16_t *_mode, float *_utm_east, float *_utm_north, float *_course, int8_t *_buffer, float *_dist, float *_next_dist, float *_start_x, float *_start_y, float *_start_angle, float *_angle, float *_last_block, int16_t *_count, uint8_t *_shutter) {}
void DOWNLINK_SEND_AMSYS_BARO(struct DownlinkTransport *tp, uint16_t *_pBaroRaw, float *_pBaro, float *_pHomePressure, float *_AltOffset, float *_aktuell, float *_Over_Ground, float *_tempBaro) {}
void DOWNLINK_SEND_AMSYS_AIRSPEED(struct DownlinkTransport *tp, uint16_t *_asRaw, float *_asPresure, float *_asAirspeed, float *_asAirsFilt, float *_asTemp) {}
void DOWNLINK_SEND_FLIGHT_BENCHMARK(struct DownlinkTransport *tp, float *_SE_As, float *_SE_Alt, float *_SE_Pos, float *_Err_As, float *_Err_Alt, float *_Err_Pos) {}
void DOWNLINK_SEND_AOA_adc(struct DownlinkTransport *tp, uint16_t *_adcVal, float *_AOA) {}
void DOWNLINK_SEND_XTEND_RSSI(struct DownlinkTransport *tp, uint16_t *_datalink_time, uint8_t *_rssi_fade_margin, uint8_t *_duty) {}
void DOWNLINK_SEND_VF_UPDATE(struct DownlinkTransport *tp, float *_baro, float *_range_meter) {}
void DOWNLINK_SEND_VF_PREDICT(struct DownlinkTransport *tp, float *_accel) {}
void DOWNLINK_SEND_CROSS_TRACK_ERROR(struct DownlinkTransport *tp, float *_cross_track_error, float *_cte_int) {}
void DOWNLINK_SEND_GENERIC_COM(struct DownlinkTransport *tp, int32_t *_lat, int32_t *_lon, int16_t *_alt, uint16_t *_gspeed, int16_t *_course, uint16_t *_airspeed, uint8_t *_vsupply, uint8_t *_energy, uint8_t *_throttle, uint8_t *_ap_mode, uint8_t *_nav_block, uint16_t *_flight_time) {}
void DOWNLINK_SEND_FORMATION_SLOT_TM(struct DownlinkTransport *tp, uint8_t *_ac_id, uint8_t *_mode, float *_slot_east, float *_slot_north, float *_slot_alt) {}
void DOWNLINK_SEND_FORMATION_STATUS_TM(struct DownlinkTransport *tp, uint8_t *_ac_id, uint8_t *_leader_id, uint8_t *_status) {}
void DOWNLINK_SEND_BMP_STATUS(struct DownlinkTransport *tp, int32_t *_UP, int32_t *_UT, int32_t *_press, int32_t *_temp) {}
void DOWNLINK_SEND_MLX_STATUS(struct DownlinkTransport *tp, uint16_t *_itemp_case, float *_temp_case, uint16_t *_itemp_obj, float *_temp_obj) {}
void DOWNLINK_SEND_TMP_STATUS(struct DownlinkTransport *tp, uint16_t *_itemp, float *_temp) {}
void DOWNLINK_SEND_WIND_INFO_RET(struct DownlinkTransport *tp, float *_east, float *_north, float *_airspeed) {}
void DOWNLINK_SEND_SCP_STATUS(struct DownlinkTransport *tp, uint32_t *_press, int16_t *_temp) {}
void DOWNLINK_SEND_SHT_STATUS(struct DownlinkTransport *tp, uint16_t *_ihumid, uint16_t *_itemp, float *_humid, float *_temp) {}
void DOWNLINK_SEND_ENOSE_STATUS(struct DownlinkTransport *tp, uint16_t *_val1, uint16_t *_val2, uint16_t *_val3, uint16_t *_PID, uint8_t nb_heat, uint8_t *_heat) {}
void DOWNLINK_SEND_DPICCO_STATUS(struct DownlinkTransport *tp, uint16_t *_humid, uint16_t *_temp, float *_fhumid, float *_ftemp) {}
void DOWNLINK_SEND_ANTENNA_DEBUG(struct DownlinkTransport *tp, int32_t *_mag_xraw, int32_t *_mag_yraw, float *_mag_xcal, float *_mag_ycal, float *_mag_heading, float *_mag_magnitude, float *_mag_temp, uint8_t *_mag_distor, uint8_t *_mag_cal_status) {}
void DOWNLINK_SEND_ANTENNA_STATUS(struct DownlinkTransport *tp, float *_azim_sp, float *_elev_sp, uint8_t *_id_sp, uint8_t *_mode) {}
void DOWNLINK_SEND_MOTOR_BENCH_STATUS(struct DownlinkTransport *tp, uint32_t *_time_ticks, float *_throttle, float *_rpm, float *_current, float *_thrust, float *_torque, uint16_t *_time_s, uint8_t *_mode) {}
void DOWNLINK_SEND_MOTOR_BENCH_STATIC(struct DownlinkTransport *tp, float *_av_rpm, float *_av_thrust, float *_av_current, uint16_t *_throttle) {}
void DOWNLINK_SEND_HIH_STATUS(struct DownlinkTransport *tp, uint16_t *_humid, float *_fhumid, float *_ftemp) {}
void DOWNLINK_SEND_TEMT_STATUS(struct DownlinkTransport *tp, uint16_t *_light, float *_f_light) {}
void DOWNLINK_SEND_GP2Y_STATUS(struct DownlinkTransport *tp, uint16_t *_idensity, float *_density) {}
void DOWNLINK_SEND_SHT_I2C_SERIAL(struct DownlinkTransport *tp, uint32_t *_serial0, uint32_t *_serial1) {}
void DOWNLINK_SEND_PPM(struct DownlinkTransport *tp, uint8_t *_ppm_rate, uint8_t nb_values, uint16_t *_values) {}
void DOWNLINK_SEND_RC(struct DownlinkTransport *tp, uint8_t nb_values, int16_t *_values) {}
void DOWNLINK_SEND_COMMANDS(struct DownlinkTransport *tp, uint8_t nb_values, int16_t *_values) {}
void DOWNLINK_SEND_FBW_STATUS(struct DownlinkTransport *tp, uint8_t *_rc_status, uint8_t *_frame_rate, uint8_t *_mode, uint8_t *_vsupply, int32_t *_current) {}
void DOWNLINK_SEND_ADC(struct DownlinkTransport *tp, uint8_t *_mcu, uint8_t nb_values, uint16_t *_values) {}
void DOWNLINK_SEND_ACTUATORS(struct DownlinkTransport *tp, uint8_t nb_values, uint16_t *_values) {}
void DOWNLINK_SEND_BETH(struct DownlinkTransport *tp, int16_t *_azimuth, int16_t *_elevation, int16_t *_tilt, uint32_t *_counter, uint16_t *_can_errs, uint16_t *_spi_errs, int8_t *_thrust_out, int8_t *_pitch_out) {}
void DOWNLINK_SEND_BETH_ESTIMATOR(struct DownlinkTransport *tp, float *_tilt, float *_tilt_dot, float *_elevation, float *_elevation_dot, float *_azimuth, float *_azimuth_dot) {}
void DOWNLINK_SEND_BETH_CONTROLLER(struct DownlinkTransport *tp, float *_pitch, float *_thrust, float *_pitch_ff, float *_pitch_fb, float *_thrust_ff, float *_thrust_fb, float *_tilt_sp, float *_tilt_ref, float *_tilt_dot_ref, float *_elevation_sp , float *_elevation_ref , float *_elevation_dot_ref, float *_azimuth_sp) {}
void DOWNLINK_SEND_BETH_CONTROLLER_TWIST(struct DownlinkTransport *tp, float *_S, float *_S_dot, float *_U_twt, float *_error) {}
void DOWNLINK_SEND_DC_SHOT(struct DownlinkTransport *tp, int16_t *_photo_nr, int32_t *_utm_east, int32_t *_utm_north, float *_z, uint8_t *_utm_zone, int16_t *_phi, int16_t *_theta, int16_t *_course, uint16_t *_speed, uint32_t *_itow) {}
void DOWNLINK_SEND_TEST_BOARD_RESULTS(struct DownlinkTransport *tp, uint8_t *_uart, uint8_t *_ppm, uint8_t nb_servo, uint16_t *_servo) {}
void DOWNLINK_SEND_BETH_CONTROLLER_SFB(struct DownlinkTransport *tp, float *_one) {}
void DOWNLINK_SEND_MLX_SERIAL(struct DownlinkTransport *tp, uint32_t *_serial0, uint32_t *_serial1) {}
void DOWNLINK_SEND_PAYLOAD(struct DownlinkTransport *tp, uint8_t nb_values, uint8_t *_values) {}
void DOWNLINK_SEND_HTM_STATUS(struct DownlinkTransport *tp, uint16_t *_ihumid, uint16_t *_itemp, float *_humid, float *_temp) {}
void DOWNLINK_SEND_BARO_MS5611(struct DownlinkTransport *tp, uint32_t *_d1, uint32_t *_d2, float *_pressure, float *_temp) {}
void DOWNLINK_SEND_MS5611_COEFF(struct DownlinkTransport *tp, uint16_t *_c0, uint16_t *_c1, uint16_t *_c2, uint16_t *_c3, uint16_t *_c4, uint16_t *_c5, uint16_t *_c6, uint16_t *_c7) {}
void DOWNLINK_SEND_ATMOSPHERE_CHARGE(struct DownlinkTransport *tp, uint16_t *_t0, uint16_t *_t1, uint16_t *_t2, uint16_t *_t3, uint16_t *_t4, uint16_t *_t5, uint16_t *_t6, uint16_t *_t7, uint16_t *_t8, uint16_t *_t9) {}
void DOWNLINK_SEND_SOLAR_RADIATION(struct DownlinkTransport *tp, uint16_t *_up_t0, uint16_t *_dn_t0, uint16_t *_up_t1, uint16_t *_dn_t1, uint16_t *_up_t2, uint16_t *_dn_t2, uint16_t *_up_t3, uint16_t *_dn_t3, uint16_t *_up_t4, uint16_t *_dn_t4, uint16_t *_up_t5, uint16_t *_dn_t5, uint16_t *_up_t6, uint16_t *_dn_t6, uint16_t *_up_t7, uint16_t *_dn_t7, uint16_t *_up_t8, uint16_t *_dn_t8, uint16_t *_up_t9, uint16_t *_dn_t9) {}
void DOWNLINK_SEND_TCAS_TA(struct DownlinkTransport *tp, uint8_t *_ac_id) {}
void DOWNLINK_SEND_TCAS_RA(struct DownlinkTransport *tp, uint8_t *_ac_id, uint8_t *_resolve) {}
void DOWNLINK_SEND_TCAS_RESOLVED(struct DownlinkTransport *tp, uint8_t *_ac_id) {}
void DOWNLINK_SEND_TCAS_DEBUG(struct DownlinkTransport *tp, uint8_t *_ac_id, float *_tau) {}
void DOWNLINK_SEND_POTENTIAL(struct DownlinkTransport *tp, float *_east, float *_north, float *_alt, float *_speed, float *_climb) {}
void DOWNLINK_SEND_VERTICAL_ENERGY(struct DownlinkTransport *tp, float *_Epot_err, float *_Ekin_err, float *_Etot_err, float *_Edis_err, float *_throttle, float *_nav_pitch, float *_speed_sp) {}
void DOWNLINK_SEND_TEMP_TCOUPLE(struct DownlinkTransport *tp, float *_fval0, float *_fval1, float *_fval2, float *_fval3, float *_fref0, float *_fref1, float *_fref2, float *_fref3, uint16_t *_val0, uint16_t *_val1, uint16_t *_val2, uint16_t *_val3, uint16_t *_ref0, uint16_t *_ref1, uint16_t *_ref2, uint16_t *_ref3) {}
void DOWNLINK_SEND_SHT_I2C_STATUS(struct DownlinkTransport *tp, uint16_t *_ihumid, uint16_t *_itemp, float *_humid, float *_temp) {}
void DOWNLINK_SEND_CAMERA_SNAPSHOT(struct DownlinkTransport *tp, uint16_t *_snapshot_image_number) {}
void DOWNLINK_SEND_TIMESTAMP(struct DownlinkTransport *tp, uint32_t *_timestamp) {}
void DOWNLINK_SEND_STAB_ATTITUDE_FLOAT(struct DownlinkTransport *tp, float *_est_p, float *_est_q, float *_est_r, float *_est_phi, float *_est_theta, float *_est_psi, float *_ref_phi, float *_ref_theta, float *_ref_psi, float *_sum_err_phi, float *_sum_err_theta, float *_sum_err_psi, float *_delta_a_fb, float *_delta_e_fb, float *_delta_r_fb, float *_delta_a_ff, float *_delta_e_ff, float *_delta_r_ff, int32_t *_delta_a, int32_t *_delta_e, int32_t *_delta_r, float *_est_p_d, float *_est_q_d, float *_est_r_d) {}
void DOWNLINK_SEND_IMU_GYRO_SCALED(struct DownlinkTransport *tp, int32_t *_gp, int32_t *_gq, int32_t *_gr) {}
void DOWNLINK_SEND_IMU_ACCEL_SCALED(struct DownlinkTransport *tp, int32_t *_ax, int32_t *_ay, int32_t *_az) {}
void DOWNLINK_SEND_IMU_MAG_SCALED(struct DownlinkTransport *tp, int32_t *_mx, int32_t *_my, int32_t *_mz) {}
void DOWNLINK_SEND_FILTER(struct DownlinkTransport *tp, int32_t *_phi, int32_t *_theta, int32_t *_psi, int32_t *_measure_phi, int32_t *_measure_theta, int32_t *_measure_psi, int32_t *_corrected_phi, int32_t *_corrected_theta, int32_t *_corrected_psi, int32_t *_correction_phi, int32_t *_correction_theta, int32_t *_correction_psi, int32_t *_bp, int32_t *_bq, int32_t *_br) {}
void DOWNLINK_SEND_FILTER2(struct DownlinkTransport *tp, int32_t *_px, int32_t *_py, int32_t *_pz, int32_t *_gsx, int32_t *_gsy, int32_t *_gsz) {}
void DOWNLINK_SEND_RATE_LOOP(struct DownlinkTransport *tp, int32_t *_sp_p, int32_t *_sp_q, int32_t *_sp_r, int32_t *_ref_p, int32_t *_ref_q, int32_t *_ref_r, int32_t *_refdot_p, int32_t *_refdot_q, int32_t *_refdot_r, int32_t *_sumerr_p, int32_t *_sumerr_q, int32_t *_sumerr_r, int32_t *_ff_p, int32_t *_ff_q, int32_t *_ff_r, int32_t *_fb_p, int32_t *_fb_q, int32_t *_fb_r, int32_t *_delta_t) {}
void DOWNLINK_SEND_FILTER_ALIGNER(struct DownlinkTransport *tp, int32_t *_lp_gp, int32_t *_lp_gq, int32_t *_lp_gr, int32_t *_gp, int32_t *_gq, int32_t *_gr, int32_t *_noise, int32_t *_cnt, uint8_t *_status) {}
void DOWNLINK_SEND_FILTER_COR(struct DownlinkTransport *tp, int32_t *_mphi, int32_t *_mtheta, int32_t *_mpsi, int32_t *_qi, int32_t *_qx, int32_t *_qy, int32_t *_qz) {}
void DOWNLINK_SEND_STAB_ATTITUDE_INT(struct DownlinkTransport *tp, int32_t *_est_p, int32_t *_est_q, int32_t *_est_r, int32_t *_est_phi, int32_t *_est_theta, int32_t *_est_psi, int32_t *_sp_phi, int32_t *_sp_theta, int32_t *_sp_psi, int32_t *_sum_err_phi, int32_t *_sum_err_theta, int32_t *_sum_err_psi, int32_t *_delta_a_fb, int32_t *_delta_e_fb, int32_t *_delta_r_fb, int32_t *_delta_a_ff, int32_t *_delta_e_ff, int32_t *_delta_r_ff, int32_t *_delta_a, int32_t *_delta_e, int32_t *_delta_r) {}
void DOWNLINK_SEND_STAB_ATTITUDE_REF_INT(struct DownlinkTransport *tp, int32_t *_sp_phi, int32_t *_sp_theta, int32_t *_sp_psi, int32_t *_ref_phi, int32_t *_ref_theta, int32_t *_ref_psi, int32_t *_ref_p, int32_t *_ref_q, int32_t *_ref_r, int32_t *_ref_pd, int32_t *_ref_qd, int32_t *_ref_rd) {}
void DOWNLINK_SEND_STAB_ATTITUDE_REF_FLOAT(struct DownlinkTransport *tp, float *_sp_phi, float *_sp_theta, float *_sp_psi, float *_ref_phi, float *_ref_theta, float *_ref_psi, float *_ref_p, float *_ref_q, float *_ref_r, float *_ref_pd, float *_ref_qd, float *_ref_rd) {}
void DOWNLINK_SEND_ROTORCRAFT_CMD(struct DownlinkTransport *tp, int32_t *_cmd_roll, int32_t *_cmd_pitch, int32_t *_cmd_yaw, int32_t *_cmd_thrust) {}
void DOWNLINK_SEND_GUIDANCE(struct DownlinkTransport *tp, int32_t *_pos_n, int32_t *_pos_e, int32_t *_sp_pos_n, int32_t *_sp_pos_e) {}
void DOWNLINK_SEND_VERT_LOOP(struct DownlinkTransport *tp, int32_t *_z_sp, int32_t *_zd_sp, int32_t *_est_z, int32_t *_est_zd, int32_t *_est_zdd, int32_t *_ref_z, int32_t *_ref_zd, int32_t *_ref_zdd, int32_t *_adp_inv_m, int32_t *_adp_cov, int32_t *_adp_meas, int32_t *_sum_err, int32_t *_ff_cmd, int32_t *_fb_cmd, int32_t *_delta_t) {}
void DOWNLINK_SEND_HOVER_LOOP(struct DownlinkTransport *tp, int32_t *_sp_x, int32_t *_sp_y, int32_t *_est_x, int32_t *_est_y, int32_t *_est_xd, int32_t *_est_yd, int32_t *_est_xdd, int32_t *_est_ydd, int32_t *_err_x, int32_t *_err_y, int32_t *_err_xd, int32_t *_err_yd, int32_t *_err_sum_x, int32_t *_err_sum_y, int32_t *_err_nav_x, int32_t *_err_nav_y, int32_t *_cmd_x, int32_t *_cmd_y, int32_t *_cmd_phi, int32_t *_cmd_theta, int32_t *_cmd_psi) {}
void DOWNLINK_SEND_ROTORCRAFT_FP(struct DownlinkTransport *tp, int32_t *_east, int32_t *_north, int32_t *_up, int32_t *_veast, int32_t *_vnorth, int32_t *_vup, int32_t *_phi, int32_t *_theta, int32_t *_psi, int32_t *_carrot_east, int32_t *_carrot_north, int32_t *_carrot_up, int32_t *_carrot_psi, int32_t *_thrust, uint16_t *_flight_time) {}
void DOWNLINK_SEND_BOOZ2_FMS_INFO(struct DownlinkTransport *tp, float *_tbd) {}
void DOWNLINK_SEND_GUIDANCE_H_REF_INT(struct DownlinkTransport *tp, int32_t *_sp_x, int32_t *_ref_x, int32_t *_ref_xd, int32_t *_ref_xdd, int32_t *_sp_y, int32_t *_ref_y, int32_t *_ref_yd, int32_t *_ref_ydd) {}
void DOWNLINK_SEND_ROTORCRAFT_TUNE_HOVER(struct DownlinkTransport *tp, int16_t *_rc_roll, int16_t *_rc_pitch, int16_t *_rc_yaw, int32_t *_cmd_roll, int32_t *_cmd_pitch, int32_t *_cmd_yaw, int32_t *_cmd_thrust, int32_t *_imu_phi, int32_t *_imu_theta, int32_t *_imu_psi, int32_t *_body_phi, int32_t *_body_theta, int32_t *_body_psi) {}
void DOWNLINK_SEND_INS_Z(struct DownlinkTransport *tp, int32_t *_baro_alt, int32_t *_ins_z, int32_t *_ins_zd, int32_t *_ins_zdd) {}
void DOWNLINK_SEND_PCAP01_STATUS(struct DownlinkTransport *tp, uint32_t *_ihumid, uint32_t *_itemp, float *_humid, float *_temp) {}
void DOWNLINK_SEND_GEIGER_COUNTER(struct DownlinkTransport *tp, uint32_t *_tube1, uint32_t *_tube2, uint16_t *_vsupply) {}
void DOWNLINK_SEND_INS_REF(struct DownlinkTransport *tp, int32_t *_ecef_x0, int32_t *_ecef_y0, int32_t *_ecef_z0, int32_t *_lat0, int32_t *_lon0, int32_t *_alt0, int32_t *_hmsl0, int32_t *_baro_qfe) {}
void DOWNLINK_SEND_GPS_INT(struct DownlinkTransport *tp, int32_t *_ecef_x, int32_t *_ecef_y, int32_t *_ecef_z, int32_t *_lat, int32_t *_lon, int32_t *_alt, int32_t *_hmsl, int32_t *_ecef_xd, int32_t *_ecef_yd, int32_t *_ecef_zd, int32_t *_pacc, int32_t *_sacc, uint32_t *_tow, uint16_t *_pdop, uint8_t *_numsv, uint8_t *_fix) {}
void DOWNLINK_SEND_AHRS_EULER_INT(struct DownlinkTransport *tp, int32_t *_imu_phi, int32_t *_imu_theta, int32_t *_imu_psi, int32_t *_body_phi, int32_t *_body_theta, int32_t *_body_psi) {}
void DOWNLINK_SEND_AHRS_QUAT_INT(struct DownlinkTransport *tp, int32_t *_imu_qi, int32_t *_imu_qx, int32_t *_imu_qy, int32_t *_imu_qz, int32_t *_body_qi, int32_t *_body_qx, int32_t *_body_qy, int32_t *_body_qz) {}
void DOWNLINK_SEND_AHRS_RMAT_INT(struct DownlinkTransport *tp, int32_t *_imu_m00, int32_t *_imu_m01, int32_t *_imu_m02, int32_t *_imu_m10, int32_t *_imu_m11, int32_t *_imu_m12, int32_t *_imu_m20, int32_t *_imu_m21, int32_t *_imu_m22, int32_t *_body_m00, int32_t *_body_m01, int32_t *_body_m02, int32_t *_body_m10, int32_t *_body_m11, int32_t *_body_m12, int32_t *_body_m20, int32_t *_body_m21, int32_t *_body_m22) {}
void DOWNLINK_SEND_ROTORCRAFT_NAV_STATUS(struct DownlinkTransport *tp, uint16_t *_block_time, uint16_t *_stage_time, uint8_t *_cur_block, uint8_t *_cur_stage, uint8_t *_horizontal_mode) {}
void DOWNLINK_SEND_ROTORCRAFT_RADIO_CONTROL(struct DownlinkTransport *tp, int16_t *_roll, int16_t *_pitch, int16_t *_yaw, int16_t *_throttle, int16_t *_mode, int16_t *_kill, uint8_t *_status) {}
void DOWNLINK_SEND_VFF(struct DownlinkTransport *tp, float *_measure, float *_z, float *_zd, float *_bias, float *_Pzz, float *_Pzdzd, float *_Pbb) {}
void DOWNLINK_SEND_BOOZ2_TUNE_FF(struct DownlinkTransport *tp, float *_fb_rms, float *_dg, float *_g) {}
void DOWNLINK_SEND_HFF(struct DownlinkTransport *tp, float *_x, float *_y, float *_xd, float *_yd, float *_xdd, float *_ydd) {}
void DOWNLINK_SEND_HFF_DBG(struct DownlinkTransport *tp, float *_x_measure, float *_y_measure, float *_yd_measure, float *_xd_measure, float *_Pxx, float *_Pyy, float *_Pxdxd, float *_Pydyd) {}
void DOWNLINK_SEND_HFF_GPS(struct DownlinkTransport *tp, uint16_t *_lag_cnt, int16_t *_lag_cnt_err, int16_t *_save_cnt) {}
void DOWNLINK_SEND_BOOZ2_SONAR(struct DownlinkTransport *tp, uint16_t *_front, uint16_t *_back, uint16_t *_right, uint16_t *_left) {}
void DOWNLINK_SEND_BOOZ2_CAM(struct DownlinkTransport *tp, int16_t *_tilt, int16_t *_pan) {}
void DOWNLINK_SEND_AHRS_REF_QUAT(struct DownlinkTransport *tp, int32_t *_ref_qi, int32_t *_ref_qx, int32_t *_ref_qy, int32_t *_ref_qz, int32_t *_body_qi, int32_t *_body_qx, int32_t *_body_qy, int32_t *_body_qz) {}
void DOWNLINK_SEND_EKF7_XHAT(struct DownlinkTransport *tp, float *_c, float *_s1, float *_s2, float *_s3, float *_p, float *_q, float *_r, float *_bp, float *_bq, float *_br) {}
void DOWNLINK_SEND_EKF7_Y(struct DownlinkTransport *tp, uint16_t *_timecount, float *_g1, float *_g2, float *_g3, float *_m1, float *_m2, float *_m3, float *_p, float *_q, float *_r) {}
void DOWNLINK_SEND_EKF7_P_DIAG(struct DownlinkTransport *tp, float *_c, float *_s1, float *_s2, float *_s3, float *_p, float *_q, float *_r, float *_bp, float *_bq, float *_br) {}
void DOWNLINK_SEND_AHRS_EULER(struct DownlinkTransport *tp, float *_phi, float *_theta, float *_psi) {}
void DOWNLINK_SEND_AHRS_MEASUREMENT_EULER(struct DownlinkTransport *tp, float *_phi, float *_theta, float *_psi) {}
void DOWNLINK_SEND_WT(struct DownlinkTransport *tp, float *_rpm) {}
void DOWNLINK_SEND_CSC_CAN_DEBUG(struct DownlinkTransport *tp, uint32_t *_err_nb, uint32_t *_err_code) {}
void DOWNLINK_SEND_CSC_CAN_MSG(struct DownlinkTransport *tp, uint32_t *_frame, uint32_t *_id, uint32_t *_data_a, uint32_t *_data_b) {}
void DOWNLINK_SEND_AHRS_GYRO_BIAS_INT(struct DownlinkTransport *tp, int32_t *_bp, int32_t *_bq, int32_t *_br) {}
void DOWNLINK_SEND_FMS_TIME(struct DownlinkTransport *tp, uint32_t *_tv_sec, uint32_t *_tv_nsec, uint32_t *_delay_ns) {}
void DOWNLINK_SEND_LOADCELL(struct DownlinkTransport *tp, int32_t *_load) {}
void DOWNLINK_SEND_FLA_DEBUG(struct DownlinkTransport *tp, float *_past_input, float *_imu_rate, float *_desired_accel, float *_motor_command) {}
void DOWNLINK_SEND_BLMC_FAULT_STATUS(struct DownlinkTransport *tp, uint8_t nb_raw_fault, uint16_t *_raw_fault) {}
void DOWNLINK_SEND_BLMC_SPEEDS(struct DownlinkTransport *tp, uint8_t nb_speeds, int16_t *_speeds) {}
void DOWNLINK_SEND_AHRS_DEBUG_QUAT(struct DownlinkTransport *tp, float *_jqi, float *_jqx, float *_jqy, float *_jqz, float *_xqi, float *_xqx, float *_xqy, float *_xqz, float *_mqi, float *_mqx, float *_mqy, float *_mqz) {}
void DOWNLINK_SEND_BLMC_BUSVOLTS(struct DownlinkTransport *tp, uint8_t nb_busvolts, uint16_t *_busvolts) {}
void DOWNLINK_SEND_SYSTEM_STATUS(struct DownlinkTransport *tp, uint32_t *_csc1_loop_count, uint32_t *_csc1_msg_count, uint32_t *_csc2_loop_count, uint32_t *_csc2_msg_count, uint32_t *_can_rx_err, uint32_t *_can_tx_err, uint32_t *_rc_parser_err, uint8_t *_system_fault) {}
void DOWNLINK_SEND_DYNAMIXEL(struct DownlinkTransport *tp, uint16_t *_left_wing, uint16_t *_right_wing, uint8_t *_left_wing_flag, uint8_t *_right_wing_flag, uint32_t *_invalid_position, uint32_t *_timeout_events, uint32_t *_checksum_errors, float *_fuse_rotation_angle, float *_fuse_rotation_rate) {}
void DOWNLINK_SEND_RMAT_DEBUG(struct DownlinkTransport *tp, float *_a, float *_b, float *_c, float *_d, float *_e, float *_f, float *_g, float *_h, float *_i) {}
void DOWNLINK_SEND_SIMPLE_COMMANDS(struct DownlinkTransport *tp, int16_t *_roll, int16_t *_pitch, int16_t *_yaw) {}
void DOWNLINK_SEND_VANE_SENSOR(struct DownlinkTransport *tp, float *_alpha, float *_alpha_filtered, float *_alpha_target, float *_alpha_vane_error, float *_alpha2, float *_beta, float *_beta_filtered, float *_beta_target, float *_beta_vane_error, float *_beta2) {}
void DOWNLINK_SEND_CONTROLLER_GAINS(struct DownlinkTransport *tp, float *_roll_gamma_p, float *_roll_gamma_d, float *_roll_gamma_i, float *_pitch_gamma_p, float *_pitch_gamma_d, float *_pitch_gamma_i, float *_yaw_gamma_p, float *_yaw_gamma_d, float *_yaw_gamma_i) {}
void DOWNLINK_SEND_AHRS_LKF(struct DownlinkTransport *tp, float *_phi, float *_theta, float *_psi, float *_qi, float *_qx, float *_qy, float *_qz, float *_p, float *_q, float *_r, float *_ax, float *_ay, float *_az, float *_mx, float *_my, float *_mz) {}
void DOWNLINK_SEND_AHRS_LKF_DEBUG(struct DownlinkTransport *tp, float *_phi_err, float *_theta_err, float *_psi_err, float *_bp, float *_bq, float *_br, float *_quat_norm, float *_phi_accel, float *_theta_accel, float *_phi_cov, float *_theta_cov, float *_psi_cov, float *_bp_cov, float *_bq_cov, float *_br_cov) {}
void DOWNLINK_SEND_AHRS_LKF_ACC_DBG(struct DownlinkTransport *tp, float *_qi_err, float *_qx_err, float *_qy_err, float *_qz_err, float *_bp_err, float *_bq_err, float *_br_err) {}
void DOWNLINK_SEND_AHRS_LKF_MAG_DBG(struct DownlinkTransport *tp, float *_qi_err, float *_qx_err, float *_qy_err, float *_qz_err, float *_bp_err, float *_bq_err, float *_br_err) {}
void DOWNLINK_SEND_NPS_SENSORS_SCALED(struct DownlinkTransport *tp, float *_acc_x, float *_acc_y, float *_acc_z, float *_mag_x, float *_mag_y, float *_mag_z) {}
void DOWNLINK_SEND_INS(struct DownlinkTransport *tp, int32_t *_ins_x, int32_t *_ins_y, int32_t *_ins_z, int32_t *_ins_xd, int32_t *_ins_yd, int32_t *_ins_zd, int32_t *_ins_xdd, int32_t *_ins_ydd, int32_t *_ins_zdd) {}
void DOWNLINK_SEND_GPS_ERROR(struct DownlinkTransport *tp, float *_x_position, float *_y_position, float *_z_position, float *_x_velocity, float *_y_velocity, float *_z_velocity) {}
void DOWNLINK_SEND_IMU_GYRO(struct DownlinkTransport *tp, float *_gp, float *_gq, float *_gr) {}
void DOWNLINK_SEND_IMU_MAG(struct DownlinkTransport *tp, float *_mx, float *_my, float *_mz) {}
void DOWNLINK_SEND_IMU_ACCEL(struct DownlinkTransport *tp, float *_ax, float *_ay, float *_az) {}
void DOWNLINK_SEND_IMU_GYRO_RAW(struct DownlinkTransport *tp, int32_t *_gp, int32_t *_gq, int32_t *_gr) {}
void DOWNLINK_SEND_IMU_ACCEL_RAW(struct DownlinkTransport *tp, int32_t *_ax, int32_t *_ay, int32_t *_az) {}
void DOWNLINK_SEND_IMU_MAG_RAW(struct DownlinkTransport *tp, int32_t *_mx, int32_t *_my, int32_t *_mz) {}
void DOWNLINK_SEND_IMU_MAG_SETTINGS(struct DownlinkTransport *tp, float *_inclination, float *_declination, float *_hardiron_x, float *_hardiron_y, float *_hardiron_z) {}
void DOWNLINK_SEND_IMU_GYRO_LP(struct DownlinkTransport *tp, float *_gp, float *_gq, float *_gr) {}
void DOWNLINK_SEND_IMU_PRESSURE(struct DownlinkTransport *tp, float *_p) {}
void DOWNLINK_SEND_IMU_HS_GYRO(struct DownlinkTransport *tp, uint8_t *_axis, uint8_t nb_samples, uint32_t *_samples) {}
void DOWNLINK_SEND_TEST_PASSTHROUGH_STATUS(struct DownlinkTransport *tp, uint32_t *_io_proc_msg_cnt, uint32_t *_io_proc_err_cnt, uint32_t *_io_link_msg_cnt, uint32_t *_io_link_err_cnt, uint8_t *_rc_status) {}
void DOWNLINK_SEND_WEATHER(struct DownlinkTransport *tp, float *_p_amb, float *_t_amb, float *_windspeed, float *_wind_from, float *_humidity) {}
void DOWNLINK_SEND_IMU_TURNTABLE(struct DownlinkTransport *tp, float *_omega) {}
void DOWNLINK_SEND_BARO_RAW(struct DownlinkTransport *tp, int32_t *_abs, int32_t *_diff) {}
void DOWNLINK_SEND_TIME(struct DownlinkTransport *tp, uint32_t *_t) {}
void DOWNLINK_SEND_ROTORCRAFT_STATUS(struct DownlinkTransport *tp, uint32_t *_link_imu_nb_err, uint8_t *_blmc_nb_err, uint8_t *_rc_status, uint8_t *_frame_rate, uint8_t *_gps_status, uint8_t *_ap_mode, uint8_t *_ap_in_flight, uint8_t *_ap_motors_on, uint8_t *_ap_h_mode, uint8_t *_ap_v_mode, uint8_t *_vsupply, uint16_t *_cpu_time) {}
void DOWNLINK_SEND_STATE_FILTER_STATUS(struct DownlinkTransport *tp, uint8_t *_state_filter_mode, uint16_t *_value) {}
void DOWNLINK_SEND_OPTICFLOW(struct DownlinkTransport *tp, uint16_t *_flow, float *_ref_alt) {}
void DOWNLINK_SEND_VISUALTARGET(struct DownlinkTransport *tp, uint16_t *_x, uint16_t *_y) {}
void DOWNLINK_SEND_NPS_POS_LLH(struct DownlinkTransport *tp, float *_pprz_lat, float *_lat_geod, float *_lat_geoc, float *_pprz_lon, float *_lon, float *_pprz_alt, float *_alt_geod, float *_agl, float *_asl) {}
void DOWNLINK_SEND_NPS_RPMS(struct DownlinkTransport *tp, float *_front, float *_back, float *_right, float *_left) {}
void DOWNLINK_SEND_NPS_SPEED_POS(struct DownlinkTransport *tp, float *_ltpp_xdd, float *_ltpp_ydd, float *_ltpp_zdd, float *_ltpp_xd, float *_ltpp_yd, float *_ltpp_zd, float *_ltpp_x, float *_ltpp_y, float *_ltpp_z) {}
void DOWNLINK_SEND_NPS_RATE_ATTITUDE(struct DownlinkTransport *tp, float *_p, float *_q, float *_r, float *_phi, float *_theta, float *_psi) {}
void DOWNLINK_SEND_NPS_GYRO_BIAS(struct DownlinkTransport *tp, float *_bp, float *_bq, float *_br) {}
void DOWNLINK_SEND_NPS_RANGE_METER(struct DownlinkTransport *tp, float *_dist) {}
void DOWNLINK_SEND_NPS_WIND(struct DownlinkTransport *tp, float *_vx, float *_vy, float *_vz) {}
void DOWNLINK_SEND_BOOZ_DEBUG_FOO(struct DownlinkTransport *tp, uint8_t *_ami_stat) {}
void DOWNLINK_SEND_BOOZ_MAX1167_ERR(struct DownlinkTransport *tp, uint8_t *_erno) {}
void DOWNLINK_SEND_PPRZ_DEBUG(struct DownlinkTransport *tp, uint8_t *_module, uint8_t *_errno) {}
void DOWNLINK_SEND_NPS_ACCEL_LTP(struct DownlinkTransport *tp, float *_xdd, float *_ydd, float *_zdd) {}
void DOWNLINK_SEND_LOOSE_INS_GPS(struct DownlinkTransport *tp, uint8_t *_status, double *_time_running, double *_q0, double *_q1, double *_q2, double *_q3, double *_phi, double *_theta, double *_psi, double *_north, double *_east, double *_down, double *_v_north, double *_v_east, double *_v_down, double *_est_p, double *_est_q, double *_est_r, double *_gyroBias_x, double *_gyroBias_y, double *_gyroBias_z, uint32_t *_imuCallbacks, uint32_t *_gpsCallbacks, uint32_t *_baroCallbacks) {}
void DOWNLINK_SEND_AFL_COEFFS(struct DownlinkTransport *tp, float *_roll_a, float *_roll_b, float *_roll_c, float *_pitch_a, float *_pitch_b, float *_pitch_c, float *_yaw_a, float *_yaw_b, float *_yaw_c) {}
void DOWNLINK_SEND_BOOZ_ATT_REF_MODEL(struct DownlinkTransport *tp, float *_omega_p, float *_zeta_p, float *_omega_q, float *_zeta_q, float *_omega_r, float *_zeta_r) {}
void DOWNLINK_SEND_BOOZ2_FF_ADAP(struct DownlinkTransport *tp, float *_roll, float *_pitch, float *_yaw) {}
void DOWNLINK_SEND_I2C_ERRORS(struct DownlinkTransport *tp, uint16_t *_acknowledge_failure_cnt, uint16_t *_misplaced_start_or_stop_cnt, uint16_t *_arbitration_lost_cnt, uint16_t *_overrun_or_underrun_cnt, uint16_t *_pec_error_in_reception_cnt, uint16_t *_timeout_or_tlow_error_cnt, uint16_t *_smbus_alert_cnt, uint16_t *_unexpected_event_cnt, uint32_t *_last_unexpected_event, uint8_t *_bus_number) {}
void DOWNLINK_SEND_RDYB_TRAJECTORY(struct DownlinkTransport *tp, float *_commanded_phi, float *_commanded_theta, float *_commanded_psi, float *_setpoint_x, float *_setpoint_y, float *_setpoint_z) {}
void DOWNLINK_SEND_HENRY_GNSS(struct DownlinkTransport *tp, uint32_t *_last_imu_update, double *_GPS_time, uint8_t *_GPS_solution_valid, double *_latitude, double *_longitude, double *_altitude, double *_North, double *_East, double *_Down, uint8_t *_SVs_Tracked, uint8_t *_SVs_PVT, double *_V_North, double *_V_East, double *_V_Down) {}
#endif // DOWNLINK

#define DL_BOOT_version(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))

#define DL_ALIVE_md5sum_length(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_ALIVE_md5sum(_payload) ((uint8_t*)(_payload+3))


#define DL_TAKEOFF_cpu_time(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))

#define DL_ATTITUDE_phi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_ATTITUDE_psi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_ATTITUDE_theta(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))

#define DL_IR_SENSORS_ir1(_payload) ((int16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_IR_SENSORS_ir2(_payload) ((int16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_IR_SENSORS_longitudinal(_payload) ((int16_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8))
#define DL_IR_SENSORS_lateral(_payload) ((int16_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8))
#define DL_IR_SENSORS_vertical(_payload) ((int16_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8))

#define DL_GPS_mode(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_GPS_utm_east(_payload) ((int32_t)(*((uint8_t*)_payload+3)|*((uint8_t*)_payload+3+1)<<8|((uint32_t)*((uint8_t*)_payload+3+2))<<16|((uint32_t)*((uint8_t*)_payload+3+3))<<24))
#define DL_GPS_utm_north(_payload) ((int32_t)(*((uint8_t*)_payload+7)|*((uint8_t*)_payload+7+1)<<8|((uint32_t)*((uint8_t*)_payload+7+2))<<16|((uint32_t)*((uint8_t*)_payload+7+3))<<24))
#define DL_GPS_course(_payload) ((int16_t)(*((uint8_t*)_payload+11)|*((uint8_t*)_payload+11+1)<<8))
#define DL_GPS_alt(_payload) ((int32_t)(*((uint8_t*)_payload+13)|*((uint8_t*)_payload+13+1)<<8|((uint32_t)*((uint8_t*)_payload+13+2))<<16|((uint32_t)*((uint8_t*)_payload+13+3))<<24))
#define DL_GPS_speed(_payload) ((uint16_t)(*((uint8_t*)_payload+17)|*((uint8_t*)_payload+17+1)<<8))
#define DL_GPS_climb(_payload) ((int16_t)(*((uint8_t*)_payload+19)|*((uint8_t*)_payload+19+1)<<8))
#define DL_GPS_week(_payload) ((uint16_t)(*((uint8_t*)_payload+21)|*((uint8_t*)_payload+21+1)<<8))
#define DL_GPS_itow(_payload) ((uint32_t)(*((uint8_t*)_payload+23)|*((uint8_t*)_payload+23+1)<<8|((uint32_t)*((uint8_t*)_payload+23+2))<<16|((uint32_t)*((uint8_t*)_payload+23+3))<<24))
#define DL_GPS_utm_zone(_payload) ((uint8_t)(*((uint8_t*)_payload+27)))
#define DL_GPS_gps_nb_err(_payload) ((uint8_t)(*((uint8_t*)_payload+28)))

#define DL_NAVIGATION_REF_utm_east(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_NAVIGATION_REF_utm_north(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_NAVIGATION_REF_utm_zone(_payload) ((uint8_t)(*((uint8_t*)_payload+10)))

#define DL_NAVIGATION_cur_block(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_NAVIGATION_cur_stage(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_NAVIGATION_pos_x(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))
#define DL_NAVIGATION_pos_y(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24); _f.f; }))
#define DL_NAVIGATION_dist2_wp(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24); _f.f; }))
#define DL_NAVIGATION_dist2_home(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8|((uint32_t)*((uint8_t*)_payload+16+2))<<16|((uint32_t)*((uint8_t*)_payload+16+3))<<24); _f.f; }))
#define DL_NAVIGATION_circle_count(_payload) ((uint8_t)(*((uint8_t*)_payload+20)))
#define DL_NAVIGATION_oval_count(_payload) ((uint8_t)(*((uint8_t*)_payload+21)))

#define DL_PPRZ_MODE_ap_mode(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_PPRZ_MODE_ap_gaz(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_PPRZ_MODE_ap_lateral(_payload) ((uint8_t)(*((uint8_t*)_payload+4)))
#define DL_PPRZ_MODE_ap_horizontal(_payload) ((uint8_t)(*((uint8_t*)_payload+5)))
#define DL_PPRZ_MODE_if_calib_mode(_payload) ((uint8_t)(*((uint8_t*)_payload+6)))
#define DL_PPRZ_MODE_mcu1_status(_payload) ((uint8_t)(*((uint8_t*)_payload+7)))

#define DL_BAT_throttle(_payload) ((int16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_BAT_voltage(_payload) ((uint8_t)(*((uint8_t*)_payload+4)))
#define DL_BAT_amps(_payload) ((int16_t)(*((uint8_t*)_payload+5)|*((uint8_t*)_payload+5+1)<<8))
#define DL_BAT_flight_time(_payload) ((uint16_t)(*((uint8_t*)_payload+7)|*((uint8_t*)_payload+7+1)<<8))
#define DL_BAT_kill_auto_throttle(_payload) ((uint8_t)(*((uint8_t*)_payload+9)))
#define DL_BAT_block_time(_payload) ((uint16_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8))
#define DL_BAT_stage_time(_payload) ((uint16_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8))
#define DL_BAT_energy(_payload) ((int16_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8))

#define DL_DEBUG_MCU_LINK_i2c_nb_err(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_DEBUG_MCU_LINK_i2c_mcu1_nb_err(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_DEBUG_MCU_LINK_ppm_rate(_payload) ((uint8_t)(*((uint8_t*)_payload+4)))

#define DL_CALIBRATION_climb_sum_err(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_CALIBRATION_climb_gaz_submode(_payload) ((uint8_t)(*((uint8_t*)_payload+6)))

#define DL_SETTINGS_slider_1_val(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_SETTINGS_slider_2_val(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))

#define DL_DESIRED_roll(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_DESIRED_pitch(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_DESIRED_course(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_DESIRED_x(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_DESIRED_y(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_DESIRED_altitude(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))
#define DL_DESIRED_climb(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24); _f.f; }))

#define DL_GPS_SOL_Pacc(_payload) ((uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_GPS_SOL_Sacc(_payload) ((uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_GPS_SOL_PDOP(_payload) ((uint16_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8))
#define DL_GPS_SOL_numSV(_payload) ((uint8_t)(*((uint8_t*)_payload+12)))

#define DL_ADC_GENERIC_val1(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_ADC_GENERIC_val2(_payload) ((uint16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))

#define DL_TEST_FORMAT_val1(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+2)|((uint64_t)*((uint8_t*)_payload+2+1))<<8|((uint64_t)*((uint8_t*)_payload+2+2))<<16|((uint64_t)*((uint8_t*)_payload+2+3))<<24|((uint64_t)*((uint8_t*)_payload+2+4))<<32|((uint64_t)*((uint8_t*)_payload+2+5))<<40|((uint64_t)*((uint8_t*)_payload+2+6))<<48|((uint64_t)*((uint8_t*)_payload+2+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_TEST_FORMAT_val2(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))

#define DL_CAM_phi(_payload) ((int16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_CAM_theta(_payload) ((int16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_CAM_target_x(_payload) ((int16_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8))
#define DL_CAM_target_y(_payload) ((int16_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8))

#define DL_CIRCLE_center_east(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_CIRCLE_center_north(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_CIRCLE_radius(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))

#define DL_SEGMENT_segment_east_1(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_SEGMENT_segment_north_1(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_SEGMENT_segment_east_2(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_SEGMENT_segment_north_2(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))

#define DL_DOWNLINK_STATUS_run_time(_payload) ((uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_DOWNLINK_STATUS_rx_bytes(_payload) ((uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_DOWNLINK_STATUS_rx_msgs(_payload) ((uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_DOWNLINK_STATUS_rx_err(_payload) ((uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24))
#define DL_DOWNLINK_STATUS_rx_bytes_rate(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_DOWNLINK_STATUS_rx_msgs_rate(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))
#define DL_DOWNLINK_STATUS_ping_time(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24); _f.f; }))

#define DL_MODEM_STATUS_detected(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_MODEM_STATUS_valim(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+3)|*((uint8_t*)_payload+3+1)<<8|((uint32_t)*((uint8_t*)_payload+3+2))<<16|((uint32_t)*((uint8_t*)_payload+3+3))<<24); _f.f; }))
#define DL_MODEM_STATUS_cd(_payload) ((uint8_t)(*((uint8_t*)_payload+7)))
#define DL_MODEM_STATUS_nb_byte(_payload) ((uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24))
#define DL_MODEM_STATUS_nb_msg(_payload) ((uint32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24))
#define DL_MODEM_STATUS_nb_err(_payload) ((uint32_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8|((uint32_t)*((uint8_t*)_payload+16+2))<<16|((uint32_t)*((uint8_t*)_payload+16+3))<<24))

#define DL_SVINFO_chn(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_SVINFO_SVID(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_SVINFO_Flags(_payload) ((uint8_t)(*((uint8_t*)_payload+4)))
#define DL_SVINFO_QI(_payload) ((uint8_t)(*((uint8_t*)_payload+5)))
#define DL_SVINFO_CNO(_payload) ((uint8_t)(*((uint8_t*)_payload+6)))
#define DL_SVINFO_Elev(_payload) ((int8_t)(*((uint8_t*)_payload+7)))
#define DL_SVINFO_Azim(_payload) ((int16_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8))

#define DL_DEBUG_msg_length(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_DEBUG_msg(_payload) ((uint8_t*)(_payload+3))

#define DL_SURVEY_east(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_SURVEY_north(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_SURVEY_west(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_SURVEY_south(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))

#define DL_WC_RSSI_raw_level(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))

#define DL_RANGEFINDER_range(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_RANGEFINDER_z_dot(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))
#define DL_RANGEFINDER_z_dot_sum_err(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24); _f.f; }))
#define DL_RANGEFINDER_z_dot_setpoint(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24); _f.f; }))
#define DL_RANGEFINDER_z_sum_err(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8|((uint32_t)*((uint8_t*)_payload+16+2))<<16|((uint32_t)*((uint8_t*)_payload+16+3))<<24); _f.f; }))
#define DL_RANGEFINDER_z_setpoint(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+20)|*((uint8_t*)_payload+20+1)<<8|((uint32_t)*((uint8_t*)_payload+20+2))<<16|((uint32_t)*((uint8_t*)_payload+20+3))<<24); _f.f; }))
#define DL_RANGEFINDER_flying(_payload) ((uint8_t)(*((uint8_t*)_payload+24)))

#define DL_DOWNLINK_nb_ovrn(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_DOWNLINK_rate(_payload) ((uint16_t)(*((uint8_t*)_payload+3)|*((uint8_t*)_payload+3+1)<<8))
#define DL_DOWNLINK_nb_msgs(_payload) ((uint16_t)(*((uint8_t*)_payload+5)|*((uint8_t*)_payload+5+1)<<8))

#define DL_DL_VALUE_index(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_DL_VALUE_value(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+3)|*((uint8_t*)_payload+3+1)<<8|((uint32_t)*((uint8_t*)_payload+3+2))<<16|((uint32_t)*((uint8_t*)_payload+3+3))<<24); _f.f; }))

#define DL_MARK_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_MARK_lat(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+3)|*((uint8_t*)_payload+3+1)<<8|((uint32_t)*((uint8_t*)_payload+3+2))<<16|((uint32_t)*((uint8_t*)_payload+3+3))<<24); _f.f; }))
#define DL_MARK_long(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+7)|*((uint8_t*)_payload+7+1)<<8|((uint32_t)*((uint8_t*)_payload+7+2))<<16|((uint32_t)*((uint8_t*)_payload+7+3))<<24); _f.f; }))

#define DL_SYS_MON_periodic_time(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_SYS_MON_periodic_cycle(_payload) ((uint16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_SYS_MON_periodic_cycle_min(_payload) ((uint16_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8))
#define DL_SYS_MON_periodic_cycle_max(_payload) ((uint16_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8))
#define DL_SYS_MON_event_number(_payload) ((uint16_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8))
#define DL_SYS_MON_cpu_load(_payload) ((uint8_t)(*((uint8_t*)_payload+12)))

#define DL_MOTOR_rpm(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_MOTOR_current(_payload) ((int32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24))

#define DL_WP_MOVED_wp_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_WP_MOVED_utm_east(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+3)|*((uint8_t*)_payload+3+1)<<8|((uint32_t)*((uint8_t*)_payload+3+2))<<16|((uint32_t)*((uint8_t*)_payload+3+3))<<24); _f.f; }))
#define DL_WP_MOVED_utm_north(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+7)|*((uint8_t*)_payload+7+1)<<8|((uint32_t)*((uint8_t*)_payload+7+2))<<16|((uint32_t)*((uint8_t*)_payload+7+3))<<24); _f.f; }))
#define DL_WP_MOVED_alt(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+11)|*((uint8_t*)_payload+11+1)<<8|((uint32_t)*((uint8_t*)_payload+11+2))<<16|((uint32_t)*((uint8_t*)_payload+11+3))<<24); _f.f; }))
#define DL_WP_MOVED_utm_zone(_payload) ((uint8_t)(*((uint8_t*)_payload+15)))

#define DL_ENERGY_bat(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_ENERGY_amp(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_ENERGY_energy(_payload) ((uint16_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8))
#define DL_ENERGY_power(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24); _f.f; }))

#define DL_BARO_BMP85_CALIB_a1(_payload) ((int16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_BARO_BMP85_CALIB_a2(_payload) ((int16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_BARO_BMP85_CALIB_a3(_payload) ((int16_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8))
#define DL_BARO_BMP85_CALIB_a4(_payload) ((uint16_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8))
#define DL_BARO_BMP85_CALIB_a5(_payload) ((uint16_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8))
#define DL_BARO_BMP85_CALIB_a6(_payload) ((uint16_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8))
#define DL_BARO_BMP85_CALIB_b1(_payload) ((int16_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8))
#define DL_BARO_BMP85_CALIB_b2(_payload) ((int16_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8))
#define DL_BARO_BMP85_CALIB_mb(_payload) ((int16_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8))
#define DL_BARO_BMP85_CALIB_mc(_payload) ((int16_t)(*((uint8_t*)_payload+20)|*((uint8_t*)_payload+20+1)<<8))
#define DL_BARO_BMP85_CALIB_md(_payload) ((int16_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8))

#define DL_BARO_BMP85_UT(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_BARO_BMP85_UP(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_BARO_BMP85_P(_payload) ((uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_BARO_BMP85_T(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_BARO_BMP85_MSL(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))

#define DL_SPEED_LOOP_ve_set_point(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_SPEED_LOOP_ve(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_SPEED_LOOP_vn_set_point(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_SPEED_LOOP_vn(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_SPEED_LOOP_north_sp(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_SPEED_LOOP_east_sp(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))

#define DL_ALT_KALMAN_p00(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_ALT_KALMAN_p01(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_ALT_KALMAN_p10(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_ALT_KALMAN_p11(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))

#define DL_ESTIMATOR_z(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_ESTIMATOR_z_dot(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))

#define DL_TUNE_ROLL_p(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_TUNE_ROLL_phi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_TUNE_ROLL_phi_sp(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))

#define DL_BARO_MS5534A_pressure(_payload) ((uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_BARO_MS5534A_temp(_payload) ((uint16_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8))
#define DL_BARO_MS5534A_alt(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24); _f.f; }))

#define DL_PRESSURE_airspeed_adc(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_PRESSURE_airspeed(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_PRESSURE_altitude_adc(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_PRESSURE_altitude(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))

#define DL_BARO_WORDS_w1(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_BARO_WORDS_w2(_payload) ((uint16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_BARO_WORDS_w3(_payload) ((uint16_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8))
#define DL_BARO_WORDS_w4(_payload) ((uint16_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8))

#define DL_WP_MOVED_LLA_wp_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_WP_MOVED_LLA_lat(_payload) ((int32_t)(*((uint8_t*)_payload+3)|*((uint8_t*)_payload+3+1)<<8|((uint32_t)*((uint8_t*)_payload+3+2))<<16|((uint32_t)*((uint8_t*)_payload+3+3))<<24))
#define DL_WP_MOVED_LLA_lon(_payload) ((int32_t)(*((uint8_t*)_payload+7)|*((uint8_t*)_payload+7+1)<<8|((uint32_t)*((uint8_t*)_payload+7+2))<<16|((uint32_t)*((uint8_t*)_payload+7+3))<<24))
#define DL_WP_MOVED_LLA_alt(_payload) ((int32_t)(*((uint8_t*)_payload+11)|*((uint8_t*)_payload+11+1)<<8|((uint32_t)*((uint8_t*)_payload+11+2))<<16|((uint32_t)*((uint8_t*)_payload+11+3))<<24))

#define DL_CHRONO_tag(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_CHRONO_time(_payload) ((uint32_t)(*((uint8_t*)_payload+3)|*((uint8_t*)_payload+3+1)<<8|((uint32_t)*((uint8_t*)_payload+3+2))<<16|((uint32_t)*((uint8_t*)_payload+3+3))<<24))

#define DL_WP_MOVED_ENU_wp_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_WP_MOVED_ENU_east(_payload) ((int32_t)(*((uint8_t*)_payload+3)|*((uint8_t*)_payload+3+1)<<8|((uint32_t)*((uint8_t*)_payload+3+2))<<16|((uint32_t)*((uint8_t*)_payload+3+3))<<24))
#define DL_WP_MOVED_ENU_north(_payload) ((int32_t)(*((uint8_t*)_payload+7)|*((uint8_t*)_payload+7+1)<<8|((uint32_t)*((uint8_t*)_payload+7+2))<<16|((uint32_t)*((uint8_t*)_payload+7+3))<<24))
#define DL_WP_MOVED_ENU_up(_payload) ((int32_t)(*((uint8_t*)_payload+11)|*((uint8_t*)_payload+11+1)<<8|((uint32_t)*((uint8_t*)_payload+11+2))<<16|((uint32_t)*((uint8_t*)_payload+11+3))<<24))

#define DL_WINDTURBINE_STATUS__ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_WINDTURBINE_STATUS__tb_id(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_WINDTURBINE_STATUS__sync_itow(_payload) ((uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24))
#define DL_WINDTURBINE_STATUS__cycle_time(_payload) ((uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24))

#define DL_RC_3CH__throttle_mode(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_RC_3CH__roll(_payload) ((int8_t)(*((uint8_t*)_payload+3)))
#define DL_RC_3CH__pitch(_payload) ((int8_t)(*((uint8_t*)_payload+4)))

#define DL_MPPT_values_length(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_MPPT_values(_payload) ((int16_t*)(_payload+3))

#define DL_DEBUG_IR_I2C_ir1(_payload) ((int16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_DEBUG_IR_I2C_ir2(_payload) ((int16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_DEBUG_IR_I2C_top(_payload) ((int16_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8))

#define DL_AIRSPEED_airspeed(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_AIRSPEED_airspeed_sp(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_AIRSPEED_airspeed_cnt(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_AIRSPEED_groundspeed_sp(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))

#define DL_XSENS_counter(_payload) ((int16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_XSENS_p(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))
#define DL_XSENS_q(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24); _f.f; }))
#define DL_XSENS_r(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24); _f.f; }))
#define DL_XSENS_phi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8|((uint32_t)*((uint8_t*)_payload+16+2))<<16|((uint32_t)*((uint8_t*)_payload+16+3))<<24); _f.f; }))
#define DL_XSENS_theta(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+20)|*((uint8_t*)_payload+20+1)<<8|((uint32_t)*((uint8_t*)_payload+20+2))<<16|((uint32_t)*((uint8_t*)_payload+20+3))<<24); _f.f; }))
#define DL_XSENS_psi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+24)|*((uint8_t*)_payload+24+1)<<8|((uint32_t)*((uint8_t*)_payload+24+2))<<16|((uint32_t)*((uint8_t*)_payload+24+3))<<24); _f.f; }))
#define DL_XSENS_ax(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+28)|*((uint8_t*)_payload+28+1)<<8|((uint32_t)*((uint8_t*)_payload+28+2))<<16|((uint32_t)*((uint8_t*)_payload+28+3))<<24); _f.f; }))
#define DL_XSENS_ay(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+32)|*((uint8_t*)_payload+32+1)<<8|((uint32_t)*((uint8_t*)_payload+32+2))<<16|((uint32_t)*((uint8_t*)_payload+32+3))<<24); _f.f; }))
#define DL_XSENS_az(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+36)|*((uint8_t*)_payload+36+1)<<8|((uint32_t)*((uint8_t*)_payload+36+2))<<16|((uint32_t)*((uint8_t*)_payload+36+3))<<24); _f.f; }))
#define DL_XSENS_vx(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+40)|*((uint8_t*)_payload+40+1)<<8|((uint32_t)*((uint8_t*)_payload+40+2))<<16|((uint32_t)*((uint8_t*)_payload+40+3))<<24); _f.f; }))
#define DL_XSENS_vy(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+44)|*((uint8_t*)_payload+44+1)<<8|((uint32_t)*((uint8_t*)_payload+44+2))<<16|((uint32_t)*((uint8_t*)_payload+44+3))<<24); _f.f; }))
#define DL_XSENS_vz(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+48)|*((uint8_t*)_payload+48+1)<<8|((uint32_t)*((uint8_t*)_payload+48+2))<<16|((uint32_t)*((uint8_t*)_payload+48+3))<<24); _f.f; }))
#define DL_XSENS_lat(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+52)|*((uint8_t*)_payload+52+1)<<8|((uint32_t)*((uint8_t*)_payload+52+2))<<16|((uint32_t)*((uint8_t*)_payload+52+3))<<24); _f.f; }))
#define DL_XSENS_lon(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+56)|*((uint8_t*)_payload+56+1)<<8|((uint32_t)*((uint8_t*)_payload+56+2))<<16|((uint32_t)*((uint8_t*)_payload+56+3))<<24); _f.f; }))
#define DL_XSENS_alt(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+60)|*((uint8_t*)_payload+60+1)<<8|((uint32_t)*((uint8_t*)_payload+60+2))<<16|((uint32_t)*((uint8_t*)_payload+60+3))<<24); _f.f; }))
#define DL_XSENS_status(_payload) ((uint8_t)(*((uint8_t*)_payload+64)))
#define DL_XSENS_hour(_payload) ((uint8_t)(*((uint8_t*)_payload+65)))
#define DL_XSENS_min(_payload) ((uint8_t)(*((uint8_t*)_payload+66)))
#define DL_XSENS_sec(_payload) ((uint8_t)(*((uint8_t*)_payload+67)))
#define DL_XSENS_nanosec(_payload) ((uint32_t)(*((uint8_t*)_payload+68)|*((uint8_t*)_payload+68+1)<<8|((uint32_t)*((uint8_t*)_payload+68+2))<<16|((uint32_t)*((uint8_t*)_payload+68+3))<<24))
#define DL_XSENS_year(_payload) ((uint16_t)(*((uint8_t*)_payload+72)|*((uint8_t*)_payload+72+1)<<8))
#define DL_XSENS_month(_payload) ((uint8_t)(*((uint8_t*)_payload+74)))
#define DL_XSENS_day(_payload) ((uint8_t)(*((uint8_t*)_payload+75)))

#define DL_BARO_ETS_adc(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_BARO_ETS_offset(_payload) ((uint16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_BARO_ETS_scaled(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))

#define DL_AIRSPEED_ETS_adc(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_AIRSPEED_ETS_offset(_payload) ((uint16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_AIRSPEED_ETS_scaled(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))

#define DL_PBN_airspeed_adc(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_PBN_altitude_adc(_payload) ((uint16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_PBN_airspeed(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_PBN_altitude(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_PBN_airspeed_offset(_payload) ((uint16_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8))
#define DL_PBN_altitude_offset(_payload) ((uint16_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8))

#define DL_GPS_LLA_lat(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_GPS_LLA_lon(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_GPS_LLA_alt(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_GPS_LLA_course(_payload) ((int16_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8))
#define DL_GPS_LLA_speed(_payload) ((uint16_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8))
#define DL_GPS_LLA_climb(_payload) ((int16_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8))
#define DL_GPS_LLA_week(_payload) ((uint16_t)(*((uint8_t*)_payload+20)|*((uint8_t*)_payload+20+1)<<8))
#define DL_GPS_LLA_itow(_payload) ((uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24))
#define DL_GPS_LLA_mode(_payload) ((uint8_t)(*((uint8_t*)_payload+26)))
#define DL_GPS_LLA_gps_nb_err(_payload) ((uint8_t)(*((uint8_t*)_payload+27)))

#define DL_H_CTL_A_roll_sum_err(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_H_CTL_A_ref_roll_angle(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_H_CTL_A_pitch_sum_err(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_H_CTL_A_ref_pitch_angle(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))

#define DL_TURB_PRESSURE_RAW_ch_0(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_TURB_PRESSURE_RAW_ch_1(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_TURB_PRESSURE_RAW_ch_2(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_TURB_PRESSURE_RAW_ch_3(_payload) ((int32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24))
#define DL_TURB_PRESSURE_RAW_ch_4(_payload) ((int32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24))
#define DL_TURB_PRESSURE_RAW_ch_5(_payload) ((int32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24))
#define DL_TURB_PRESSURE_RAW_ch_6(_payload) ((int32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24))
#define DL_TURB_PRESSURE_RAW_ch_7(_payload) ((int32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24))
#define DL_TURB_PRESSURE_RAW_ch_8(_payload) ((int32_t)(*((uint8_t*)_payload+34)|*((uint8_t*)_payload+34+1)<<8|((uint32_t)*((uint8_t*)_payload+34+2))<<16|((uint32_t)*((uint8_t*)_payload+34+3))<<24))
#define DL_TURB_PRESSURE_RAW_ch_9(_payload) ((int32_t)(*((uint8_t*)_payload+38)|*((uint8_t*)_payload+38+1)<<8|((uint32_t)*((uint8_t*)_payload+38+2))<<16|((uint32_t)*((uint8_t*)_payload+38+3))<<24))
#define DL_TURB_PRESSURE_RAW_ch_10(_payload) ((int32_t)(*((uint8_t*)_payload+42)|*((uint8_t*)_payload+42+1)<<8|((uint32_t)*((uint8_t*)_payload+42+2))<<16|((uint32_t)*((uint8_t*)_payload+42+3))<<24))
#define DL_TURB_PRESSURE_RAW_ch_11(_payload) ((int32_t)(*((uint8_t*)_payload+46)|*((uint8_t*)_payload+46+1)<<8|((uint32_t)*((uint8_t*)_payload+46+2))<<16|((uint32_t)*((uint8_t*)_payload+46+3))<<24))
#define DL_TURB_PRESSURE_RAW_ch_12(_payload) ((int32_t)(*((uint8_t*)_payload+50)|*((uint8_t*)_payload+50+1)<<8|((uint32_t)*((uint8_t*)_payload+50+2))<<16|((uint32_t)*((uint8_t*)_payload+50+3))<<24))
#define DL_TURB_PRESSURE_RAW_ch_13(_payload) ((int32_t)(*((uint8_t*)_payload+54)|*((uint8_t*)_payload+54+1)<<8|((uint32_t)*((uint8_t*)_payload+54+2))<<16|((uint32_t)*((uint8_t*)_payload+54+3))<<24))
#define DL_TURB_PRESSURE_RAW_ch_14(_payload) ((int32_t)(*((uint8_t*)_payload+58)|*((uint8_t*)_payload+58+1)<<8|((uint32_t)*((uint8_t*)_payload+58+2))<<16|((uint32_t)*((uint8_t*)_payload+58+3))<<24))
#define DL_TURB_PRESSURE_RAW_ch_15(_payload) ((int32_t)(*((uint8_t*)_payload+62)|*((uint8_t*)_payload+62+1)<<8|((uint32_t)*((uint8_t*)_payload+62+2))<<16|((uint32_t)*((uint8_t*)_payload+62+3))<<24))

#define DL_TURB_PRESSURE_VOLTAGE_ch_1_p(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_TURB_PRESSURE_VOLTAGE_ch_1_t(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_TURB_PRESSURE_VOLTAGE_ch_2_p(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_TURB_PRESSURE_VOLTAGE_ch_2_t(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_TURB_PRESSURE_VOLTAGE_ch_3_p(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_TURB_PRESSURE_VOLTAGE_ch_3_t(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))
#define DL_TURB_PRESSURE_VOLTAGE_ch_4_p(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24); _f.f; }))
#define DL_TURB_PRESSURE_VOLTAGE_ch_4_t(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24); _f.f; }))
#define DL_TURB_PRESSURE_VOLTAGE_ch_5_p(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+34)|*((uint8_t*)_payload+34+1)<<8|((uint32_t)*((uint8_t*)_payload+34+2))<<16|((uint32_t)*((uint8_t*)_payload+34+3))<<24); _f.f; }))
#define DL_TURB_PRESSURE_VOLTAGE_ch_5_t(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+38)|*((uint8_t*)_payload+38+1)<<8|((uint32_t)*((uint8_t*)_payload+38+2))<<16|((uint32_t)*((uint8_t*)_payload+38+3))<<24); _f.f; }))
#define DL_TURB_PRESSURE_VOLTAGE_ch_6_p(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+42)|*((uint8_t*)_payload+42+1)<<8|((uint32_t)*((uint8_t*)_payload+42+2))<<16|((uint32_t)*((uint8_t*)_payload+42+3))<<24); _f.f; }))
#define DL_TURB_PRESSURE_VOLTAGE_ch_6_t(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+46)|*((uint8_t*)_payload+46+1)<<8|((uint32_t)*((uint8_t*)_payload+46+2))<<16|((uint32_t)*((uint8_t*)_payload+46+3))<<24); _f.f; }))
#define DL_TURB_PRESSURE_VOLTAGE_ch_7_p(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+50)|*((uint8_t*)_payload+50+1)<<8|((uint32_t)*((uint8_t*)_payload+50+2))<<16|((uint32_t)*((uint8_t*)_payload+50+3))<<24); _f.f; }))
#define DL_TURB_PRESSURE_VOLTAGE_ch_7_t(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+54)|*((uint8_t*)_payload+54+1)<<8|((uint32_t)*((uint8_t*)_payload+54+2))<<16|((uint32_t)*((uint8_t*)_payload+54+3))<<24); _f.f; }))
#define DL_TURB_PRESSURE_VOLTAGE_gnd1(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+58)|*((uint8_t*)_payload+58+1)<<8|((uint32_t)*((uint8_t*)_payload+58+2))<<16|((uint32_t)*((uint8_t*)_payload+58+3))<<24); _f.f; }))
#define DL_TURB_PRESSURE_VOLTAGE_gnd2(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+62)|*((uint8_t*)_payload+62+1)<<8|((uint32_t)*((uint8_t*)_payload+62+2))<<16|((uint32_t)*((uint8_t*)_payload+62+3))<<24); _f.f; }))

#define DL_CAM_POINT_cam_point_distance_from_home(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_CAM_POINT_cam_point_lat(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))
#define DL_CAM_POINT_cam_point_lon(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24); _f.f; }))

#define DL_DC_INFO_mode(_payload) ((int16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_DC_INFO_utm_east(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))
#define DL_DC_INFO_utm_north(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24); _f.f; }))
#define DL_DC_INFO_course(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24); _f.f; }))
#define DL_DC_INFO_buffer(_payload) ((int8_t)(*((uint8_t*)_payload+16)))
#define DL_DC_INFO_dist(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+17)|*((uint8_t*)_payload+17+1)<<8|((uint32_t)*((uint8_t*)_payload+17+2))<<16|((uint32_t)*((uint8_t*)_payload+17+3))<<24); _f.f; }))
#define DL_DC_INFO_next_dist(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+21)|*((uint8_t*)_payload+21+1)<<8|((uint32_t)*((uint8_t*)_payload+21+2))<<16|((uint32_t)*((uint8_t*)_payload+21+3))<<24); _f.f; }))
#define DL_DC_INFO_start_x(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+25)|*((uint8_t*)_payload+25+1)<<8|((uint32_t)*((uint8_t*)_payload+25+2))<<16|((uint32_t)*((uint8_t*)_payload+25+3))<<24); _f.f; }))
#define DL_DC_INFO_start_y(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+29)|*((uint8_t*)_payload+29+1)<<8|((uint32_t)*((uint8_t*)_payload+29+2))<<16|((uint32_t)*((uint8_t*)_payload+29+3))<<24); _f.f; }))
#define DL_DC_INFO_start_angle(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+33)|*((uint8_t*)_payload+33+1)<<8|((uint32_t)*((uint8_t*)_payload+33+2))<<16|((uint32_t)*((uint8_t*)_payload+33+3))<<24); _f.f; }))
#define DL_DC_INFO_angle(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+37)|*((uint8_t*)_payload+37+1)<<8|((uint32_t)*((uint8_t*)_payload+37+2))<<16|((uint32_t)*((uint8_t*)_payload+37+3))<<24); _f.f; }))
#define DL_DC_INFO_last_block(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+41)|*((uint8_t*)_payload+41+1)<<8|((uint32_t)*((uint8_t*)_payload+41+2))<<16|((uint32_t)*((uint8_t*)_payload+41+3))<<24); _f.f; }))
#define DL_DC_INFO_count(_payload) ((int16_t)(*((uint8_t*)_payload+45)|*((uint8_t*)_payload+45+1)<<8))
#define DL_DC_INFO_shutter(_payload) ((uint8_t)(*((uint8_t*)_payload+47)))

#define DL_AMSYS_BARO_pBaroRaw(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_AMSYS_BARO_pBaro(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))
#define DL_AMSYS_BARO_pHomePressure(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24); _f.f; }))
#define DL_AMSYS_BARO_AltOffset(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24); _f.f; }))
#define DL_AMSYS_BARO_aktuell(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8|((uint32_t)*((uint8_t*)_payload+16+2))<<16|((uint32_t)*((uint8_t*)_payload+16+3))<<24); _f.f; }))
#define DL_AMSYS_BARO_Over_Ground(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+20)|*((uint8_t*)_payload+20+1)<<8|((uint32_t)*((uint8_t*)_payload+20+2))<<16|((uint32_t)*((uint8_t*)_payload+20+3))<<24); _f.f; }))
#define DL_AMSYS_BARO_tempBaro(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+24)|*((uint8_t*)_payload+24+1)<<8|((uint32_t)*((uint8_t*)_payload+24+2))<<16|((uint32_t)*((uint8_t*)_payload+24+3))<<24); _f.f; }))

#define DL_AMSYS_AIRSPEED_asRaw(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_AMSYS_AIRSPEED_asPresure(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))
#define DL_AMSYS_AIRSPEED_asAirspeed(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24); _f.f; }))
#define DL_AMSYS_AIRSPEED_asAirsFilt(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24); _f.f; }))
#define DL_AMSYS_AIRSPEED_asTemp(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8|((uint32_t)*((uint8_t*)_payload+16+2))<<16|((uint32_t)*((uint8_t*)_payload+16+3))<<24); _f.f; }))

#define DL_FLIGHT_BENCHMARK_SE_As(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_FLIGHT_BENCHMARK_SE_Alt(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_FLIGHT_BENCHMARK_SE_Pos(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_FLIGHT_BENCHMARK_Err_As(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_FLIGHT_BENCHMARK_Err_Alt(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_FLIGHT_BENCHMARK_Err_Pos(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))

#define DL_AOA_adc_adcVal(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_AOA_adc_AOA(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))

#define DL_XTEND_RSSI_datalink_time(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_XTEND_RSSI_rssi_fade_margin(_payload) ((uint8_t)(*((uint8_t*)_payload+4)))
#define DL_XTEND_RSSI_duty(_payload) ((uint8_t)(*((uint8_t*)_payload+5)))

#define DL_VF_UPDATE_baro(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_VF_UPDATE_range_meter(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))

#define DL_VF_PREDICT_accel(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))

#define DL_CROSS_TRACK_ERROR_cross_track_error(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_CROSS_TRACK_ERROR_cte_int(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))

#define DL_GENERIC_COM_lat(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_GENERIC_COM_lon(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_GENERIC_COM_alt(_payload) ((int16_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8))
#define DL_GENERIC_COM_gspeed(_payload) ((uint16_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8))
#define DL_GENERIC_COM_course(_payload) ((int16_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8))
#define DL_GENERIC_COM_airspeed(_payload) ((uint16_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8))
#define DL_GENERIC_COM_vsupply(_payload) ((uint8_t)(*((uint8_t*)_payload+18)))
#define DL_GENERIC_COM_energy(_payload) ((uint8_t)(*((uint8_t*)_payload+19)))
#define DL_GENERIC_COM_throttle(_payload) ((uint8_t)(*((uint8_t*)_payload+20)))
#define DL_GENERIC_COM_ap_mode(_payload) ((uint8_t)(*((uint8_t*)_payload+21)))
#define DL_GENERIC_COM_nav_block(_payload) ((uint8_t)(*((uint8_t*)_payload+22)))
#define DL_GENERIC_COM_flight_time(_payload) ((uint16_t)(*((uint8_t*)_payload+23)|*((uint8_t*)_payload+23+1)<<8))

#define DL_FORMATION_SLOT_TM_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_FORMATION_SLOT_TM_mode(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_FORMATION_SLOT_TM_slot_east(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))
#define DL_FORMATION_SLOT_TM_slot_north(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24); _f.f; }))
#define DL_FORMATION_SLOT_TM_slot_alt(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24); _f.f; }))

#define DL_FORMATION_STATUS_TM_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_FORMATION_STATUS_TM_leader_id(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_FORMATION_STATUS_TM_status(_payload) ((uint8_t)(*((uint8_t*)_payload+4)))

#define DL_BMP_STATUS_UP(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_BMP_STATUS_UT(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_BMP_STATUS_press(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_BMP_STATUS_temp(_payload) ((int32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24))

#define DL_MLX_STATUS_itemp_case(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_MLX_STATUS_temp_case(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))
#define DL_MLX_STATUS_itemp_obj(_payload) ((uint16_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8))
#define DL_MLX_STATUS_temp_obj(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))

#define DL_TMP_STATUS_itemp(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_TMP_STATUS_temp(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))

#define DL_WIND_INFO_RET_east(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_WIND_INFO_RET_north(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_WIND_INFO_RET_airspeed(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))

#define DL_SCP_STATUS_press(_payload) ((uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_SCP_STATUS_temp(_payload) ((int16_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8))

#define DL_SHT_STATUS_ihumid(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_SHT_STATUS_itemp(_payload) ((uint16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_SHT_STATUS_humid(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_SHT_STATUS_temp(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))

#define DL_ENOSE_STATUS_val1(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_ENOSE_STATUS_val2(_payload) ((uint16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_ENOSE_STATUS_val3(_payload) ((uint16_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8))
#define DL_ENOSE_STATUS_PID(_payload) ((uint16_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8))
#define DL_ENOSE_STATUS_heat_length(_payload) ((uint8_t)(*((uint8_t*)_payload+10)))
#define DL_ENOSE_STATUS_heat(_payload) ((uint8_t*)(_payload+11))

#define DL_DPICCO_STATUS_humid(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_DPICCO_STATUS_temp(_payload) ((uint16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_DPICCO_STATUS_fhumid(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_DPICCO_STATUS_ftemp(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))

#define DL_ANTENNA_DEBUG_mag_xraw(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_ANTENNA_DEBUG_mag_yraw(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_ANTENNA_DEBUG_mag_xcal(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_ANTENNA_DEBUG_mag_ycal(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_ANTENNA_DEBUG_mag_heading(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_ANTENNA_DEBUG_mag_magnitude(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))
#define DL_ANTENNA_DEBUG_mag_temp(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24); _f.f; }))
#define DL_ANTENNA_DEBUG_mag_distor(_payload) ((uint8_t)(*((uint8_t*)_payload+30)))
#define DL_ANTENNA_DEBUG_mag_cal_status(_payload) ((uint8_t)(*((uint8_t*)_payload+31)))

#define DL_ANTENNA_STATUS_azim_sp(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_ANTENNA_STATUS_elev_sp(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_ANTENNA_STATUS_id_sp(_payload) ((uint8_t)(*((uint8_t*)_payload+10)))
#define DL_ANTENNA_STATUS_mode(_payload) ((uint8_t)(*((uint8_t*)_payload+11)))

#define DL_MOTOR_BENCH_STATUS_time_ticks(_payload) ((uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_MOTOR_BENCH_STATUS_throttle(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_MOTOR_BENCH_STATUS_rpm(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_MOTOR_BENCH_STATUS_current(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_MOTOR_BENCH_STATUS_thrust(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_MOTOR_BENCH_STATUS_torque(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))
#define DL_MOTOR_BENCH_STATUS_time_s(_payload) ((uint16_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8))
#define DL_MOTOR_BENCH_STATUS_mode(_payload) ((uint8_t)(*((uint8_t*)_payload+28)))

#define DL_MOTOR_BENCH_STATIC_av_rpm(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_MOTOR_BENCH_STATIC_av_thrust(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_MOTOR_BENCH_STATIC_av_current(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_MOTOR_BENCH_STATIC_throttle(_payload) ((uint16_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8))

#define DL_HIH_STATUS_humid(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_HIH_STATUS_fhumid(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))
#define DL_HIH_STATUS_ftemp(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24); _f.f; }))

#define DL_TEMT_STATUS_light(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_TEMT_STATUS_f_light(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))

#define DL_GP2Y_STATUS_idensity(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_GP2Y_STATUS_density(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))

#define DL_SHT_I2C_SERIAL_serial0(_payload) ((uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_SHT_I2C_SERIAL_serial1(_payload) ((uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))

#define DL_PPM_ppm_rate(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_PPM_values_length(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_PPM_values(_payload) ((uint16_t*)(_payload+4))

#define DL_RC_values_length(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_RC_values(_payload) ((int16_t*)(_payload+3))

#define DL_COMMANDS_values_length(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_COMMANDS_values(_payload) ((int16_t*)(_payload+3))

#define DL_FBW_STATUS_rc_status(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_FBW_STATUS_frame_rate(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_FBW_STATUS_mode(_payload) ((uint8_t)(*((uint8_t*)_payload+4)))
#define DL_FBW_STATUS_vsupply(_payload) ((uint8_t)(*((uint8_t*)_payload+5)))
#define DL_FBW_STATUS_current(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))

#define DL_ADC_mcu(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_ADC_values_length(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_ADC_values(_payload) ((uint16_t*)(_payload+4))

#define DL_ACTUATORS_values_length(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_ACTUATORS_values(_payload) ((uint16_t*)(_payload+3))

#define DL_BETH_azimuth(_payload) ((int16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_BETH_elevation(_payload) ((int16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_BETH_tilt(_payload) ((int16_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8))
#define DL_BETH_counter(_payload) ((uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24))
#define DL_BETH_can_errs(_payload) ((uint16_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8))
#define DL_BETH_spi_errs(_payload) ((uint16_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8))
#define DL_BETH_thrust_out(_payload) ((int8_t)(*((uint8_t*)_payload+16)))
#define DL_BETH_pitch_out(_payload) ((int8_t)(*((uint8_t*)_payload+17)))

#define DL_BETH_ESTIMATOR_tilt(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_BETH_ESTIMATOR_tilt_dot(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_BETH_ESTIMATOR_elevation(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_BETH_ESTIMATOR_elevation_dot(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_BETH_ESTIMATOR_azimuth(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_BETH_ESTIMATOR_azimuth_dot(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))

#define DL_BETH_CONTROLLER_pitch(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_BETH_CONTROLLER_thrust(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_BETH_CONTROLLER_pitch_ff(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_BETH_CONTROLLER_pitch_fb(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_BETH_CONTROLLER_thrust_ff(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_BETH_CONTROLLER_thrust_fb(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))
#define DL_BETH_CONTROLLER_tilt_sp(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24); _f.f; }))
#define DL_BETH_CONTROLLER_tilt_ref(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24); _f.f; }))
#define DL_BETH_CONTROLLER_tilt_dot_ref(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+34)|*((uint8_t*)_payload+34+1)<<8|((uint32_t)*((uint8_t*)_payload+34+2))<<16|((uint32_t)*((uint8_t*)_payload+34+3))<<24); _f.f; }))
#define DL_BETH_CONTROLLER_elevation_sp (_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+38)|*((uint8_t*)_payload+38+1)<<8|((uint32_t)*((uint8_t*)_payload+38+2))<<16|((uint32_t)*((uint8_t*)_payload+38+3))<<24); _f.f; }))
#define DL_BETH_CONTROLLER_elevation_ref (_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+42)|*((uint8_t*)_payload+42+1)<<8|((uint32_t)*((uint8_t*)_payload+42+2))<<16|((uint32_t)*((uint8_t*)_payload+42+3))<<24); _f.f; }))
#define DL_BETH_CONTROLLER_elevation_dot_ref(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+46)|*((uint8_t*)_payload+46+1)<<8|((uint32_t)*((uint8_t*)_payload+46+2))<<16|((uint32_t)*((uint8_t*)_payload+46+3))<<24); _f.f; }))
#define DL_BETH_CONTROLLER_azimuth_sp(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+50)|*((uint8_t*)_payload+50+1)<<8|((uint32_t)*((uint8_t*)_payload+50+2))<<16|((uint32_t)*((uint8_t*)_payload+50+3))<<24); _f.f; }))

#define DL_BETH_CONTROLLER_TWIST_S(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_BETH_CONTROLLER_TWIST_S_dot(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_BETH_CONTROLLER_TWIST_U_twt(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_BETH_CONTROLLER_TWIST_error(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))

#define DL_DC_SHOT_photo_nr(_payload) ((int16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_DC_SHOT_utm_east(_payload) ((int32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24))
#define DL_DC_SHOT_utm_north(_payload) ((int32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24))
#define DL_DC_SHOT_z(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24); _f.f; }))
#define DL_DC_SHOT_utm_zone(_payload) ((uint8_t)(*((uint8_t*)_payload+16)))
#define DL_DC_SHOT_phi(_payload) ((int16_t)(*((uint8_t*)_payload+17)|*((uint8_t*)_payload+17+1)<<8))
#define DL_DC_SHOT_theta(_payload) ((int16_t)(*((uint8_t*)_payload+19)|*((uint8_t*)_payload+19+1)<<8))
#define DL_DC_SHOT_course(_payload) ((int16_t)(*((uint8_t*)_payload+21)|*((uint8_t*)_payload+21+1)<<8))
#define DL_DC_SHOT_speed(_payload) ((uint16_t)(*((uint8_t*)_payload+23)|*((uint8_t*)_payload+23+1)<<8))
#define DL_DC_SHOT_itow(_payload) ((uint32_t)(*((uint8_t*)_payload+25)|*((uint8_t*)_payload+25+1)<<8|((uint32_t)*((uint8_t*)_payload+25+2))<<16|((uint32_t)*((uint8_t*)_payload+25+3))<<24))

#define DL_TEST_BOARD_RESULTS_uart(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_TEST_BOARD_RESULTS_ppm(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_TEST_BOARD_RESULTS_servo_length(_payload) ((uint8_t)(*((uint8_t*)_payload+4)))
#define DL_TEST_BOARD_RESULTS_servo(_payload) ((uint16_t*)(_payload+5))

#define DL_BETH_CONTROLLER_SFB_one(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))

#define DL_MLX_SERIAL_serial0(_payload) ((uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_MLX_SERIAL_serial1(_payload) ((uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))

#define DL_PAYLOAD_values_length(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_PAYLOAD_values(_payload) ((uint8_t*)(_payload+3))

#define DL_HTM_STATUS_ihumid(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_HTM_STATUS_itemp(_payload) ((uint16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_HTM_STATUS_humid(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_HTM_STATUS_temp(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))

#define DL_BARO_MS5611_d1(_payload) ((uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_BARO_MS5611_d2(_payload) ((uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_BARO_MS5611_pressure(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_BARO_MS5611_temp(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))

#define DL_MS5611_COEFF_c0(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_MS5611_COEFF_c1(_payload) ((uint16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_MS5611_COEFF_c2(_payload) ((uint16_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8))
#define DL_MS5611_COEFF_c3(_payload) ((uint16_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8))
#define DL_MS5611_COEFF_c4(_payload) ((uint16_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8))
#define DL_MS5611_COEFF_c5(_payload) ((uint16_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8))
#define DL_MS5611_COEFF_c6(_payload) ((uint16_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8))
#define DL_MS5611_COEFF_c7(_payload) ((uint16_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8))

#define DL_ATMOSPHERE_CHARGE_t0(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_ATMOSPHERE_CHARGE_t1(_payload) ((uint16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_ATMOSPHERE_CHARGE_t2(_payload) ((uint16_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8))
#define DL_ATMOSPHERE_CHARGE_t3(_payload) ((uint16_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8))
#define DL_ATMOSPHERE_CHARGE_t4(_payload) ((uint16_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8))
#define DL_ATMOSPHERE_CHARGE_t5(_payload) ((uint16_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8))
#define DL_ATMOSPHERE_CHARGE_t6(_payload) ((uint16_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8))
#define DL_ATMOSPHERE_CHARGE_t7(_payload) ((uint16_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8))
#define DL_ATMOSPHERE_CHARGE_t8(_payload) ((uint16_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8))
#define DL_ATMOSPHERE_CHARGE_t9(_payload) ((uint16_t)(*((uint8_t*)_payload+20)|*((uint8_t*)_payload+20+1)<<8))

#define DL_SOLAR_RADIATION_up_t0(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_SOLAR_RADIATION_dn_t0(_payload) ((uint16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_SOLAR_RADIATION_up_t1(_payload) ((uint16_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8))
#define DL_SOLAR_RADIATION_dn_t1(_payload) ((uint16_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8))
#define DL_SOLAR_RADIATION_up_t2(_payload) ((uint16_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8))
#define DL_SOLAR_RADIATION_dn_t2(_payload) ((uint16_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8))
#define DL_SOLAR_RADIATION_up_t3(_payload) ((uint16_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8))
#define DL_SOLAR_RADIATION_dn_t3(_payload) ((uint16_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8))
#define DL_SOLAR_RADIATION_up_t4(_payload) ((uint16_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8))
#define DL_SOLAR_RADIATION_dn_t4(_payload) ((uint16_t)(*((uint8_t*)_payload+20)|*((uint8_t*)_payload+20+1)<<8))
#define DL_SOLAR_RADIATION_up_t5(_payload) ((uint16_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8))
#define DL_SOLAR_RADIATION_dn_t5(_payload) ((uint16_t)(*((uint8_t*)_payload+24)|*((uint8_t*)_payload+24+1)<<8))
#define DL_SOLAR_RADIATION_up_t6(_payload) ((uint16_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8))
#define DL_SOLAR_RADIATION_dn_t6(_payload) ((uint16_t)(*((uint8_t*)_payload+28)|*((uint8_t*)_payload+28+1)<<8))
#define DL_SOLAR_RADIATION_up_t7(_payload) ((uint16_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8))
#define DL_SOLAR_RADIATION_dn_t7(_payload) ((uint16_t)(*((uint8_t*)_payload+32)|*((uint8_t*)_payload+32+1)<<8))
#define DL_SOLAR_RADIATION_up_t8(_payload) ((uint16_t)(*((uint8_t*)_payload+34)|*((uint8_t*)_payload+34+1)<<8))
#define DL_SOLAR_RADIATION_dn_t8(_payload) ((uint16_t)(*((uint8_t*)_payload+36)|*((uint8_t*)_payload+36+1)<<8))
#define DL_SOLAR_RADIATION_up_t9(_payload) ((uint16_t)(*((uint8_t*)_payload+38)|*((uint8_t*)_payload+38+1)<<8))
#define DL_SOLAR_RADIATION_dn_t9(_payload) ((uint16_t)(*((uint8_t*)_payload+40)|*((uint8_t*)_payload+40+1)<<8))

#define DL_TCAS_TA_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))

#define DL_TCAS_RA_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_TCAS_RA_resolve(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))

#define DL_TCAS_RESOLVED_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))

#define DL_TCAS_DEBUG_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_TCAS_DEBUG_tau(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+3)|*((uint8_t*)_payload+3+1)<<8|((uint32_t)*((uint8_t*)_payload+3+2))<<16|((uint32_t)*((uint8_t*)_payload+3+3))<<24); _f.f; }))

#define DL_POTENTIAL_east(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_POTENTIAL_north(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_POTENTIAL_alt(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_POTENTIAL_speed(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_POTENTIAL_climb(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))

#define DL_VERTICAL_ENERGY_Epot_err(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_VERTICAL_ENERGY_Ekin_err(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_VERTICAL_ENERGY_Etot_err(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_VERTICAL_ENERGY_Edis_err(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_VERTICAL_ENERGY_throttle(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_VERTICAL_ENERGY_nav_pitch(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))
#define DL_VERTICAL_ENERGY_speed_sp(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24); _f.f; }))

#define DL_TEMP_TCOUPLE_fval0(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_TEMP_TCOUPLE_fval1(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_TEMP_TCOUPLE_fval2(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_TEMP_TCOUPLE_fval3(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_TEMP_TCOUPLE_fref0(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_TEMP_TCOUPLE_fref1(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))
#define DL_TEMP_TCOUPLE_fref2(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24); _f.f; }))
#define DL_TEMP_TCOUPLE_fref3(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24); _f.f; }))
#define DL_TEMP_TCOUPLE_val0(_payload) ((uint16_t)(*((uint8_t*)_payload+34)|*((uint8_t*)_payload+34+1)<<8))
#define DL_TEMP_TCOUPLE_val1(_payload) ((uint16_t)(*((uint8_t*)_payload+36)|*((uint8_t*)_payload+36+1)<<8))
#define DL_TEMP_TCOUPLE_val2(_payload) ((uint16_t)(*((uint8_t*)_payload+38)|*((uint8_t*)_payload+38+1)<<8))
#define DL_TEMP_TCOUPLE_val3(_payload) ((uint16_t)(*((uint8_t*)_payload+40)|*((uint8_t*)_payload+40+1)<<8))
#define DL_TEMP_TCOUPLE_ref0(_payload) ((uint16_t)(*((uint8_t*)_payload+42)|*((uint8_t*)_payload+42+1)<<8))
#define DL_TEMP_TCOUPLE_ref1(_payload) ((uint16_t)(*((uint8_t*)_payload+44)|*((uint8_t*)_payload+44+1)<<8))
#define DL_TEMP_TCOUPLE_ref2(_payload) ((uint16_t)(*((uint8_t*)_payload+46)|*((uint8_t*)_payload+46+1)<<8))
#define DL_TEMP_TCOUPLE_ref3(_payload) ((uint16_t)(*((uint8_t*)_payload+48)|*((uint8_t*)_payload+48+1)<<8))

#define DL_SHT_I2C_STATUS_ihumid(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_SHT_I2C_STATUS_itemp(_payload) ((uint16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_SHT_I2C_STATUS_humid(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_SHT_I2C_STATUS_temp(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))

#define DL_CAMERA_SNAPSHOT_snapshot_image_number(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))

#define DL_TIMESTAMP_timestamp(_payload) ((uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))

#define DL_STAB_ATTITUDE_FLOAT_est_p(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_FLOAT_est_q(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_FLOAT_est_r(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_FLOAT_est_phi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_FLOAT_est_theta(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_FLOAT_est_psi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_FLOAT_ref_phi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_FLOAT_ref_theta(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_FLOAT_ref_psi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+34)|*((uint8_t*)_payload+34+1)<<8|((uint32_t)*((uint8_t*)_payload+34+2))<<16|((uint32_t)*((uint8_t*)_payload+34+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_FLOAT_sum_err_phi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+38)|*((uint8_t*)_payload+38+1)<<8|((uint32_t)*((uint8_t*)_payload+38+2))<<16|((uint32_t)*((uint8_t*)_payload+38+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_FLOAT_sum_err_theta(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+42)|*((uint8_t*)_payload+42+1)<<8|((uint32_t)*((uint8_t*)_payload+42+2))<<16|((uint32_t)*((uint8_t*)_payload+42+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_FLOAT_sum_err_psi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+46)|*((uint8_t*)_payload+46+1)<<8|((uint32_t)*((uint8_t*)_payload+46+2))<<16|((uint32_t)*((uint8_t*)_payload+46+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_FLOAT_delta_a_fb(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+50)|*((uint8_t*)_payload+50+1)<<8|((uint32_t)*((uint8_t*)_payload+50+2))<<16|((uint32_t)*((uint8_t*)_payload+50+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_FLOAT_delta_e_fb(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+54)|*((uint8_t*)_payload+54+1)<<8|((uint32_t)*((uint8_t*)_payload+54+2))<<16|((uint32_t)*((uint8_t*)_payload+54+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_FLOAT_delta_r_fb(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+58)|*((uint8_t*)_payload+58+1)<<8|((uint32_t)*((uint8_t*)_payload+58+2))<<16|((uint32_t)*((uint8_t*)_payload+58+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_FLOAT_delta_a_ff(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+62)|*((uint8_t*)_payload+62+1)<<8|((uint32_t)*((uint8_t*)_payload+62+2))<<16|((uint32_t)*((uint8_t*)_payload+62+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_FLOAT_delta_e_ff(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+66)|*((uint8_t*)_payload+66+1)<<8|((uint32_t)*((uint8_t*)_payload+66+2))<<16|((uint32_t)*((uint8_t*)_payload+66+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_FLOAT_delta_r_ff(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+70)|*((uint8_t*)_payload+70+1)<<8|((uint32_t)*((uint8_t*)_payload+70+2))<<16|((uint32_t)*((uint8_t*)_payload+70+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_FLOAT_delta_a(_payload) ((int32_t)(*((uint8_t*)_payload+74)|*((uint8_t*)_payload+74+1)<<8|((uint32_t)*((uint8_t*)_payload+74+2))<<16|((uint32_t)*((uint8_t*)_payload+74+3))<<24))
#define DL_STAB_ATTITUDE_FLOAT_delta_e(_payload) ((int32_t)(*((uint8_t*)_payload+78)|*((uint8_t*)_payload+78+1)<<8|((uint32_t)*((uint8_t*)_payload+78+2))<<16|((uint32_t)*((uint8_t*)_payload+78+3))<<24))
#define DL_STAB_ATTITUDE_FLOAT_delta_r(_payload) ((int32_t)(*((uint8_t*)_payload+82)|*((uint8_t*)_payload+82+1)<<8|((uint32_t)*((uint8_t*)_payload+82+2))<<16|((uint32_t)*((uint8_t*)_payload+82+3))<<24))
#define DL_STAB_ATTITUDE_FLOAT_est_p_d(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+86)|*((uint8_t*)_payload+86+1)<<8|((uint32_t)*((uint8_t*)_payload+86+2))<<16|((uint32_t)*((uint8_t*)_payload+86+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_FLOAT_est_q_d(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+90)|*((uint8_t*)_payload+90+1)<<8|((uint32_t)*((uint8_t*)_payload+90+2))<<16|((uint32_t)*((uint8_t*)_payload+90+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_FLOAT_est_r_d(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+94)|*((uint8_t*)_payload+94+1)<<8|((uint32_t)*((uint8_t*)_payload+94+2))<<16|((uint32_t)*((uint8_t*)_payload+94+3))<<24); _f.f; }))

#define DL_IMU_GYRO_SCALED_gp(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_IMU_GYRO_SCALED_gq(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_IMU_GYRO_SCALED_gr(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))

#define DL_IMU_ACCEL_SCALED_ax(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_IMU_ACCEL_SCALED_ay(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_IMU_ACCEL_SCALED_az(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))

#define DL_IMU_MAG_SCALED_mx(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_IMU_MAG_SCALED_my(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_IMU_MAG_SCALED_mz(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))

#define DL_FILTER_phi(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_FILTER_theta(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_FILTER_psi(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_FILTER_measure_phi(_payload) ((int32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24))
#define DL_FILTER_measure_theta(_payload) ((int32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24))
#define DL_FILTER_measure_psi(_payload) ((int32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24))
#define DL_FILTER_corrected_phi(_payload) ((int32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24))
#define DL_FILTER_corrected_theta(_payload) ((int32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24))
#define DL_FILTER_corrected_psi(_payload) ((int32_t)(*((uint8_t*)_payload+34)|*((uint8_t*)_payload+34+1)<<8|((uint32_t)*((uint8_t*)_payload+34+2))<<16|((uint32_t)*((uint8_t*)_payload+34+3))<<24))
#define DL_FILTER_correction_phi(_payload) ((int32_t)(*((uint8_t*)_payload+38)|*((uint8_t*)_payload+38+1)<<8|((uint32_t)*((uint8_t*)_payload+38+2))<<16|((uint32_t)*((uint8_t*)_payload+38+3))<<24))
#define DL_FILTER_correction_theta(_payload) ((int32_t)(*((uint8_t*)_payload+42)|*((uint8_t*)_payload+42+1)<<8|((uint32_t)*((uint8_t*)_payload+42+2))<<16|((uint32_t)*((uint8_t*)_payload+42+3))<<24))
#define DL_FILTER_correction_psi(_payload) ((int32_t)(*((uint8_t*)_payload+46)|*((uint8_t*)_payload+46+1)<<8|((uint32_t)*((uint8_t*)_payload+46+2))<<16|((uint32_t)*((uint8_t*)_payload+46+3))<<24))
#define DL_FILTER_bp(_payload) ((int32_t)(*((uint8_t*)_payload+50)|*((uint8_t*)_payload+50+1)<<8|((uint32_t)*((uint8_t*)_payload+50+2))<<16|((uint32_t)*((uint8_t*)_payload+50+3))<<24))
#define DL_FILTER_bq(_payload) ((int32_t)(*((uint8_t*)_payload+54)|*((uint8_t*)_payload+54+1)<<8|((uint32_t)*((uint8_t*)_payload+54+2))<<16|((uint32_t)*((uint8_t*)_payload+54+3))<<24))
#define DL_FILTER_br(_payload) ((int32_t)(*((uint8_t*)_payload+58)|*((uint8_t*)_payload+58+1)<<8|((uint32_t)*((uint8_t*)_payload+58+2))<<16|((uint32_t)*((uint8_t*)_payload+58+3))<<24))

#define DL_FILTER2_px(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_FILTER2_py(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_FILTER2_pz(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_FILTER2_gsx(_payload) ((int32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24))
#define DL_FILTER2_gsy(_payload) ((int32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24))
#define DL_FILTER2_gsz(_payload) ((int32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24))

#define DL_RATE_LOOP_sp_p(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_RATE_LOOP_sp_q(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_RATE_LOOP_sp_r(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_RATE_LOOP_ref_p(_payload) ((int32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24))
#define DL_RATE_LOOP_ref_q(_payload) ((int32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24))
#define DL_RATE_LOOP_ref_r(_payload) ((int32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24))
#define DL_RATE_LOOP_refdot_p(_payload) ((int32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24))
#define DL_RATE_LOOP_refdot_q(_payload) ((int32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24))
#define DL_RATE_LOOP_refdot_r(_payload) ((int32_t)(*((uint8_t*)_payload+34)|*((uint8_t*)_payload+34+1)<<8|((uint32_t)*((uint8_t*)_payload+34+2))<<16|((uint32_t)*((uint8_t*)_payload+34+3))<<24))
#define DL_RATE_LOOP_sumerr_p(_payload) ((int32_t)(*((uint8_t*)_payload+38)|*((uint8_t*)_payload+38+1)<<8|((uint32_t)*((uint8_t*)_payload+38+2))<<16|((uint32_t)*((uint8_t*)_payload+38+3))<<24))
#define DL_RATE_LOOP_sumerr_q(_payload) ((int32_t)(*((uint8_t*)_payload+42)|*((uint8_t*)_payload+42+1)<<8|((uint32_t)*((uint8_t*)_payload+42+2))<<16|((uint32_t)*((uint8_t*)_payload+42+3))<<24))
#define DL_RATE_LOOP_sumerr_r(_payload) ((int32_t)(*((uint8_t*)_payload+46)|*((uint8_t*)_payload+46+1)<<8|((uint32_t)*((uint8_t*)_payload+46+2))<<16|((uint32_t)*((uint8_t*)_payload+46+3))<<24))
#define DL_RATE_LOOP_ff_p(_payload) ((int32_t)(*((uint8_t*)_payload+50)|*((uint8_t*)_payload+50+1)<<8|((uint32_t)*((uint8_t*)_payload+50+2))<<16|((uint32_t)*((uint8_t*)_payload+50+3))<<24))
#define DL_RATE_LOOP_ff_q(_payload) ((int32_t)(*((uint8_t*)_payload+54)|*((uint8_t*)_payload+54+1)<<8|((uint32_t)*((uint8_t*)_payload+54+2))<<16|((uint32_t)*((uint8_t*)_payload+54+3))<<24))
#define DL_RATE_LOOP_ff_r(_payload) ((int32_t)(*((uint8_t*)_payload+58)|*((uint8_t*)_payload+58+1)<<8|((uint32_t)*((uint8_t*)_payload+58+2))<<16|((uint32_t)*((uint8_t*)_payload+58+3))<<24))
#define DL_RATE_LOOP_fb_p(_payload) ((int32_t)(*((uint8_t*)_payload+62)|*((uint8_t*)_payload+62+1)<<8|((uint32_t)*((uint8_t*)_payload+62+2))<<16|((uint32_t)*((uint8_t*)_payload+62+3))<<24))
#define DL_RATE_LOOP_fb_q(_payload) ((int32_t)(*((uint8_t*)_payload+66)|*((uint8_t*)_payload+66+1)<<8|((uint32_t)*((uint8_t*)_payload+66+2))<<16|((uint32_t)*((uint8_t*)_payload+66+3))<<24))
#define DL_RATE_LOOP_fb_r(_payload) ((int32_t)(*((uint8_t*)_payload+70)|*((uint8_t*)_payload+70+1)<<8|((uint32_t)*((uint8_t*)_payload+70+2))<<16|((uint32_t)*((uint8_t*)_payload+70+3))<<24))
#define DL_RATE_LOOP_delta_t(_payload) ((int32_t)(*((uint8_t*)_payload+74)|*((uint8_t*)_payload+74+1)<<8|((uint32_t)*((uint8_t*)_payload+74+2))<<16|((uint32_t)*((uint8_t*)_payload+74+3))<<24))

#define DL_FILTER_ALIGNER_lp_gp(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_FILTER_ALIGNER_lp_gq(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_FILTER_ALIGNER_lp_gr(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_FILTER_ALIGNER_gp(_payload) ((int32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24))
#define DL_FILTER_ALIGNER_gq(_payload) ((int32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24))
#define DL_FILTER_ALIGNER_gr(_payload) ((int32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24))
#define DL_FILTER_ALIGNER_noise(_payload) ((int32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24))
#define DL_FILTER_ALIGNER_cnt(_payload) ((int32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24))
#define DL_FILTER_ALIGNER_status(_payload) ((uint8_t)(*((uint8_t*)_payload+34)))

#define DL_FILTER_COR_mphi(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_FILTER_COR_mtheta(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_FILTER_COR_mpsi(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_FILTER_COR_qi(_payload) ((int32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24))
#define DL_FILTER_COR_qx(_payload) ((int32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24))
#define DL_FILTER_COR_qy(_payload) ((int32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24))
#define DL_FILTER_COR_qz(_payload) ((int32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24))

#define DL_STAB_ATTITUDE_INT_est_p(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_STAB_ATTITUDE_INT_est_q(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_STAB_ATTITUDE_INT_est_r(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_STAB_ATTITUDE_INT_est_phi(_payload) ((int32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24))
#define DL_STAB_ATTITUDE_INT_est_theta(_payload) ((int32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24))
#define DL_STAB_ATTITUDE_INT_est_psi(_payload) ((int32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24))
#define DL_STAB_ATTITUDE_INT_sp_phi(_payload) ((int32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24))
#define DL_STAB_ATTITUDE_INT_sp_theta(_payload) ((int32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24))
#define DL_STAB_ATTITUDE_INT_sp_psi(_payload) ((int32_t)(*((uint8_t*)_payload+34)|*((uint8_t*)_payload+34+1)<<8|((uint32_t)*((uint8_t*)_payload+34+2))<<16|((uint32_t)*((uint8_t*)_payload+34+3))<<24))
#define DL_STAB_ATTITUDE_INT_sum_err_phi(_payload) ((int32_t)(*((uint8_t*)_payload+38)|*((uint8_t*)_payload+38+1)<<8|((uint32_t)*((uint8_t*)_payload+38+2))<<16|((uint32_t)*((uint8_t*)_payload+38+3))<<24))
#define DL_STAB_ATTITUDE_INT_sum_err_theta(_payload) ((int32_t)(*((uint8_t*)_payload+42)|*((uint8_t*)_payload+42+1)<<8|((uint32_t)*((uint8_t*)_payload+42+2))<<16|((uint32_t)*((uint8_t*)_payload+42+3))<<24))
#define DL_STAB_ATTITUDE_INT_sum_err_psi(_payload) ((int32_t)(*((uint8_t*)_payload+46)|*((uint8_t*)_payload+46+1)<<8|((uint32_t)*((uint8_t*)_payload+46+2))<<16|((uint32_t)*((uint8_t*)_payload+46+3))<<24))
#define DL_STAB_ATTITUDE_INT_delta_a_fb(_payload) ((int32_t)(*((uint8_t*)_payload+50)|*((uint8_t*)_payload+50+1)<<8|((uint32_t)*((uint8_t*)_payload+50+2))<<16|((uint32_t)*((uint8_t*)_payload+50+3))<<24))
#define DL_STAB_ATTITUDE_INT_delta_e_fb(_payload) ((int32_t)(*((uint8_t*)_payload+54)|*((uint8_t*)_payload+54+1)<<8|((uint32_t)*((uint8_t*)_payload+54+2))<<16|((uint32_t)*((uint8_t*)_payload+54+3))<<24))
#define DL_STAB_ATTITUDE_INT_delta_r_fb(_payload) ((int32_t)(*((uint8_t*)_payload+58)|*((uint8_t*)_payload+58+1)<<8|((uint32_t)*((uint8_t*)_payload+58+2))<<16|((uint32_t)*((uint8_t*)_payload+58+3))<<24))
#define DL_STAB_ATTITUDE_INT_delta_a_ff(_payload) ((int32_t)(*((uint8_t*)_payload+62)|*((uint8_t*)_payload+62+1)<<8|((uint32_t)*((uint8_t*)_payload+62+2))<<16|((uint32_t)*((uint8_t*)_payload+62+3))<<24))
#define DL_STAB_ATTITUDE_INT_delta_e_ff(_payload) ((int32_t)(*((uint8_t*)_payload+66)|*((uint8_t*)_payload+66+1)<<8|((uint32_t)*((uint8_t*)_payload+66+2))<<16|((uint32_t)*((uint8_t*)_payload+66+3))<<24))
#define DL_STAB_ATTITUDE_INT_delta_r_ff(_payload) ((int32_t)(*((uint8_t*)_payload+70)|*((uint8_t*)_payload+70+1)<<8|((uint32_t)*((uint8_t*)_payload+70+2))<<16|((uint32_t)*((uint8_t*)_payload+70+3))<<24))
#define DL_STAB_ATTITUDE_INT_delta_a(_payload) ((int32_t)(*((uint8_t*)_payload+74)|*((uint8_t*)_payload+74+1)<<8|((uint32_t)*((uint8_t*)_payload+74+2))<<16|((uint32_t)*((uint8_t*)_payload+74+3))<<24))
#define DL_STAB_ATTITUDE_INT_delta_e(_payload) ((int32_t)(*((uint8_t*)_payload+78)|*((uint8_t*)_payload+78+1)<<8|((uint32_t)*((uint8_t*)_payload+78+2))<<16|((uint32_t)*((uint8_t*)_payload+78+3))<<24))
#define DL_STAB_ATTITUDE_INT_delta_r(_payload) ((int32_t)(*((uint8_t*)_payload+82)|*((uint8_t*)_payload+82+1)<<8|((uint32_t)*((uint8_t*)_payload+82+2))<<16|((uint32_t)*((uint8_t*)_payload+82+3))<<24))

#define DL_STAB_ATTITUDE_REF_INT_sp_phi(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_STAB_ATTITUDE_REF_INT_sp_theta(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_STAB_ATTITUDE_REF_INT_sp_psi(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_STAB_ATTITUDE_REF_INT_ref_phi(_payload) ((int32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24))
#define DL_STAB_ATTITUDE_REF_INT_ref_theta(_payload) ((int32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24))
#define DL_STAB_ATTITUDE_REF_INT_ref_psi(_payload) ((int32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24))
#define DL_STAB_ATTITUDE_REF_INT_ref_p(_payload) ((int32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24))
#define DL_STAB_ATTITUDE_REF_INT_ref_q(_payload) ((int32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24))
#define DL_STAB_ATTITUDE_REF_INT_ref_r(_payload) ((int32_t)(*((uint8_t*)_payload+34)|*((uint8_t*)_payload+34+1)<<8|((uint32_t)*((uint8_t*)_payload+34+2))<<16|((uint32_t)*((uint8_t*)_payload+34+3))<<24))
#define DL_STAB_ATTITUDE_REF_INT_ref_pd(_payload) ((int32_t)(*((uint8_t*)_payload+38)|*((uint8_t*)_payload+38+1)<<8|((uint32_t)*((uint8_t*)_payload+38+2))<<16|((uint32_t)*((uint8_t*)_payload+38+3))<<24))
#define DL_STAB_ATTITUDE_REF_INT_ref_qd(_payload) ((int32_t)(*((uint8_t*)_payload+42)|*((uint8_t*)_payload+42+1)<<8|((uint32_t)*((uint8_t*)_payload+42+2))<<16|((uint32_t)*((uint8_t*)_payload+42+3))<<24))
#define DL_STAB_ATTITUDE_REF_INT_ref_rd(_payload) ((int32_t)(*((uint8_t*)_payload+46)|*((uint8_t*)_payload+46+1)<<8|((uint32_t)*((uint8_t*)_payload+46+2))<<16|((uint32_t)*((uint8_t*)_payload+46+3))<<24))

#define DL_STAB_ATTITUDE_REF_FLOAT_sp_phi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_REF_FLOAT_sp_theta(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_REF_FLOAT_sp_psi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_REF_FLOAT_ref_phi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_REF_FLOAT_ref_theta(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_REF_FLOAT_ref_psi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_REF_FLOAT_ref_p(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_REF_FLOAT_ref_q(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_REF_FLOAT_ref_r(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+34)|*((uint8_t*)_payload+34+1)<<8|((uint32_t)*((uint8_t*)_payload+34+2))<<16|((uint32_t)*((uint8_t*)_payload+34+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_REF_FLOAT_ref_pd(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+38)|*((uint8_t*)_payload+38+1)<<8|((uint32_t)*((uint8_t*)_payload+38+2))<<16|((uint32_t)*((uint8_t*)_payload+38+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_REF_FLOAT_ref_qd(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+42)|*((uint8_t*)_payload+42+1)<<8|((uint32_t)*((uint8_t*)_payload+42+2))<<16|((uint32_t)*((uint8_t*)_payload+42+3))<<24); _f.f; }))
#define DL_STAB_ATTITUDE_REF_FLOAT_ref_rd(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+46)|*((uint8_t*)_payload+46+1)<<8|((uint32_t)*((uint8_t*)_payload+46+2))<<16|((uint32_t)*((uint8_t*)_payload+46+3))<<24); _f.f; }))

#define DL_ROTORCRAFT_CMD_cmd_roll(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_ROTORCRAFT_CMD_cmd_pitch(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_ROTORCRAFT_CMD_cmd_yaw(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_ROTORCRAFT_CMD_cmd_thrust(_payload) ((int32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24))

#define DL_GUIDANCE_pos_n(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_GUIDANCE_pos_e(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_GUIDANCE_sp_pos_n(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_GUIDANCE_sp_pos_e(_payload) ((int32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24))

#define DL_VERT_LOOP_z_sp(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_VERT_LOOP_zd_sp(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_VERT_LOOP_est_z(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_VERT_LOOP_est_zd(_payload) ((int32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24))
#define DL_VERT_LOOP_est_zdd(_payload) ((int32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24))
#define DL_VERT_LOOP_ref_z(_payload) ((int32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24))
#define DL_VERT_LOOP_ref_zd(_payload) ((int32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24))
#define DL_VERT_LOOP_ref_zdd(_payload) ((int32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24))
#define DL_VERT_LOOP_adp_inv_m(_payload) ((int32_t)(*((uint8_t*)_payload+34)|*((uint8_t*)_payload+34+1)<<8|((uint32_t)*((uint8_t*)_payload+34+2))<<16|((uint32_t)*((uint8_t*)_payload+34+3))<<24))
#define DL_VERT_LOOP_adp_cov(_payload) ((int32_t)(*((uint8_t*)_payload+38)|*((uint8_t*)_payload+38+1)<<8|((uint32_t)*((uint8_t*)_payload+38+2))<<16|((uint32_t)*((uint8_t*)_payload+38+3))<<24))
#define DL_VERT_LOOP_adp_meas(_payload) ((int32_t)(*((uint8_t*)_payload+42)|*((uint8_t*)_payload+42+1)<<8|((uint32_t)*((uint8_t*)_payload+42+2))<<16|((uint32_t)*((uint8_t*)_payload+42+3))<<24))
#define DL_VERT_LOOP_sum_err(_payload) ((int32_t)(*((uint8_t*)_payload+46)|*((uint8_t*)_payload+46+1)<<8|((uint32_t)*((uint8_t*)_payload+46+2))<<16|((uint32_t)*((uint8_t*)_payload+46+3))<<24))
#define DL_VERT_LOOP_ff_cmd(_payload) ((int32_t)(*((uint8_t*)_payload+50)|*((uint8_t*)_payload+50+1)<<8|((uint32_t)*((uint8_t*)_payload+50+2))<<16|((uint32_t)*((uint8_t*)_payload+50+3))<<24))
#define DL_VERT_LOOP_fb_cmd(_payload) ((int32_t)(*((uint8_t*)_payload+54)|*((uint8_t*)_payload+54+1)<<8|((uint32_t)*((uint8_t*)_payload+54+2))<<16|((uint32_t)*((uint8_t*)_payload+54+3))<<24))
#define DL_VERT_LOOP_delta_t(_payload) ((int32_t)(*((uint8_t*)_payload+58)|*((uint8_t*)_payload+58+1)<<8|((uint32_t)*((uint8_t*)_payload+58+2))<<16|((uint32_t)*((uint8_t*)_payload+58+3))<<24))

#define DL_HOVER_LOOP_sp_x(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_HOVER_LOOP_sp_y(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_HOVER_LOOP_est_x(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_HOVER_LOOP_est_y(_payload) ((int32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24))
#define DL_HOVER_LOOP_est_xd(_payload) ((int32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24))
#define DL_HOVER_LOOP_est_yd(_payload) ((int32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24))
#define DL_HOVER_LOOP_est_xdd(_payload) ((int32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24))
#define DL_HOVER_LOOP_est_ydd(_payload) ((int32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24))
#define DL_HOVER_LOOP_err_x(_payload) ((int32_t)(*((uint8_t*)_payload+34)|*((uint8_t*)_payload+34+1)<<8|((uint32_t)*((uint8_t*)_payload+34+2))<<16|((uint32_t)*((uint8_t*)_payload+34+3))<<24))
#define DL_HOVER_LOOP_err_y(_payload) ((int32_t)(*((uint8_t*)_payload+38)|*((uint8_t*)_payload+38+1)<<8|((uint32_t)*((uint8_t*)_payload+38+2))<<16|((uint32_t)*((uint8_t*)_payload+38+3))<<24))
#define DL_HOVER_LOOP_err_xd(_payload) ((int32_t)(*((uint8_t*)_payload+42)|*((uint8_t*)_payload+42+1)<<8|((uint32_t)*((uint8_t*)_payload+42+2))<<16|((uint32_t)*((uint8_t*)_payload+42+3))<<24))
#define DL_HOVER_LOOP_err_yd(_payload) ((int32_t)(*((uint8_t*)_payload+46)|*((uint8_t*)_payload+46+1)<<8|((uint32_t)*((uint8_t*)_payload+46+2))<<16|((uint32_t)*((uint8_t*)_payload+46+3))<<24))
#define DL_HOVER_LOOP_err_sum_x(_payload) ((int32_t)(*((uint8_t*)_payload+50)|*((uint8_t*)_payload+50+1)<<8|((uint32_t)*((uint8_t*)_payload+50+2))<<16|((uint32_t)*((uint8_t*)_payload+50+3))<<24))
#define DL_HOVER_LOOP_err_sum_y(_payload) ((int32_t)(*((uint8_t*)_payload+54)|*((uint8_t*)_payload+54+1)<<8|((uint32_t)*((uint8_t*)_payload+54+2))<<16|((uint32_t)*((uint8_t*)_payload+54+3))<<24))
#define DL_HOVER_LOOP_err_nav_x(_payload) ((int32_t)(*((uint8_t*)_payload+58)|*((uint8_t*)_payload+58+1)<<8|((uint32_t)*((uint8_t*)_payload+58+2))<<16|((uint32_t)*((uint8_t*)_payload+58+3))<<24))
#define DL_HOVER_LOOP_err_nav_y(_payload) ((int32_t)(*((uint8_t*)_payload+62)|*((uint8_t*)_payload+62+1)<<8|((uint32_t)*((uint8_t*)_payload+62+2))<<16|((uint32_t)*((uint8_t*)_payload+62+3))<<24))
#define DL_HOVER_LOOP_cmd_x(_payload) ((int32_t)(*((uint8_t*)_payload+66)|*((uint8_t*)_payload+66+1)<<8|((uint32_t)*((uint8_t*)_payload+66+2))<<16|((uint32_t)*((uint8_t*)_payload+66+3))<<24))
#define DL_HOVER_LOOP_cmd_y(_payload) ((int32_t)(*((uint8_t*)_payload+70)|*((uint8_t*)_payload+70+1)<<8|((uint32_t)*((uint8_t*)_payload+70+2))<<16|((uint32_t)*((uint8_t*)_payload+70+3))<<24))
#define DL_HOVER_LOOP_cmd_phi(_payload) ((int32_t)(*((uint8_t*)_payload+74)|*((uint8_t*)_payload+74+1)<<8|((uint32_t)*((uint8_t*)_payload+74+2))<<16|((uint32_t)*((uint8_t*)_payload+74+3))<<24))
#define DL_HOVER_LOOP_cmd_theta(_payload) ((int32_t)(*((uint8_t*)_payload+78)|*((uint8_t*)_payload+78+1)<<8|((uint32_t)*((uint8_t*)_payload+78+2))<<16|((uint32_t)*((uint8_t*)_payload+78+3))<<24))
#define DL_HOVER_LOOP_cmd_psi(_payload) ((int32_t)(*((uint8_t*)_payload+82)|*((uint8_t*)_payload+82+1)<<8|((uint32_t)*((uint8_t*)_payload+82+2))<<16|((uint32_t)*((uint8_t*)_payload+82+3))<<24))

#define DL_ROTORCRAFT_FP_east(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_ROTORCRAFT_FP_north(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_ROTORCRAFT_FP_up(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_ROTORCRAFT_FP_veast(_payload) ((int32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24))
#define DL_ROTORCRAFT_FP_vnorth(_payload) ((int32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24))
#define DL_ROTORCRAFT_FP_vup(_payload) ((int32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24))
#define DL_ROTORCRAFT_FP_phi(_payload) ((int32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24))
#define DL_ROTORCRAFT_FP_theta(_payload) ((int32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24))
#define DL_ROTORCRAFT_FP_psi(_payload) ((int32_t)(*((uint8_t*)_payload+34)|*((uint8_t*)_payload+34+1)<<8|((uint32_t)*((uint8_t*)_payload+34+2))<<16|((uint32_t)*((uint8_t*)_payload+34+3))<<24))
#define DL_ROTORCRAFT_FP_carrot_east(_payload) ((int32_t)(*((uint8_t*)_payload+38)|*((uint8_t*)_payload+38+1)<<8|((uint32_t)*((uint8_t*)_payload+38+2))<<16|((uint32_t)*((uint8_t*)_payload+38+3))<<24))
#define DL_ROTORCRAFT_FP_carrot_north(_payload) ((int32_t)(*((uint8_t*)_payload+42)|*((uint8_t*)_payload+42+1)<<8|((uint32_t)*((uint8_t*)_payload+42+2))<<16|((uint32_t)*((uint8_t*)_payload+42+3))<<24))
#define DL_ROTORCRAFT_FP_carrot_up(_payload) ((int32_t)(*((uint8_t*)_payload+46)|*((uint8_t*)_payload+46+1)<<8|((uint32_t)*((uint8_t*)_payload+46+2))<<16|((uint32_t)*((uint8_t*)_payload+46+3))<<24))
#define DL_ROTORCRAFT_FP_carrot_psi(_payload) ((int32_t)(*((uint8_t*)_payload+50)|*((uint8_t*)_payload+50+1)<<8|((uint32_t)*((uint8_t*)_payload+50+2))<<16|((uint32_t)*((uint8_t*)_payload+50+3))<<24))
#define DL_ROTORCRAFT_FP_thrust(_payload) ((int32_t)(*((uint8_t*)_payload+54)|*((uint8_t*)_payload+54+1)<<8|((uint32_t)*((uint8_t*)_payload+54+2))<<16|((uint32_t)*((uint8_t*)_payload+54+3))<<24))
#define DL_ROTORCRAFT_FP_flight_time(_payload) ((uint16_t)(*((uint8_t*)_payload+58)|*((uint8_t*)_payload+58+1)<<8))

#define DL_BOOZ2_FMS_INFO_tbd(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))

#define DL_GUIDANCE_H_REF_INT_sp_x(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_GUIDANCE_H_REF_INT_ref_x(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_GUIDANCE_H_REF_INT_ref_xd(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_GUIDANCE_H_REF_INT_ref_xdd(_payload) ((int32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24))
#define DL_GUIDANCE_H_REF_INT_sp_y(_payload) ((int32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24))
#define DL_GUIDANCE_H_REF_INT_ref_y(_payload) ((int32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24))
#define DL_GUIDANCE_H_REF_INT_ref_yd(_payload) ((int32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24))
#define DL_GUIDANCE_H_REF_INT_ref_ydd(_payload) ((int32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24))

#define DL_ROTORCRAFT_TUNE_HOVER_rc_roll(_payload) ((int16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_ROTORCRAFT_TUNE_HOVER_rc_pitch(_payload) ((int16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_ROTORCRAFT_TUNE_HOVER_rc_yaw(_payload) ((int16_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8))
#define DL_ROTORCRAFT_TUNE_HOVER_cmd_roll(_payload) ((int32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24))
#define DL_ROTORCRAFT_TUNE_HOVER_cmd_pitch(_payload) ((int32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24))
#define DL_ROTORCRAFT_TUNE_HOVER_cmd_yaw(_payload) ((int32_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8|((uint32_t)*((uint8_t*)_payload+16+2))<<16|((uint32_t)*((uint8_t*)_payload+16+3))<<24))
#define DL_ROTORCRAFT_TUNE_HOVER_cmd_thrust(_payload) ((int32_t)(*((uint8_t*)_payload+20)|*((uint8_t*)_payload+20+1)<<8|((uint32_t)*((uint8_t*)_payload+20+2))<<16|((uint32_t)*((uint8_t*)_payload+20+3))<<24))
#define DL_ROTORCRAFT_TUNE_HOVER_imu_phi(_payload) ((int32_t)(*((uint8_t*)_payload+24)|*((uint8_t*)_payload+24+1)<<8|((uint32_t)*((uint8_t*)_payload+24+2))<<16|((uint32_t)*((uint8_t*)_payload+24+3))<<24))
#define DL_ROTORCRAFT_TUNE_HOVER_imu_theta(_payload) ((int32_t)(*((uint8_t*)_payload+28)|*((uint8_t*)_payload+28+1)<<8|((uint32_t)*((uint8_t*)_payload+28+2))<<16|((uint32_t)*((uint8_t*)_payload+28+3))<<24))
#define DL_ROTORCRAFT_TUNE_HOVER_imu_psi(_payload) ((int32_t)(*((uint8_t*)_payload+32)|*((uint8_t*)_payload+32+1)<<8|((uint32_t)*((uint8_t*)_payload+32+2))<<16|((uint32_t)*((uint8_t*)_payload+32+3))<<24))
#define DL_ROTORCRAFT_TUNE_HOVER_body_phi(_payload) ((int32_t)(*((uint8_t*)_payload+36)|*((uint8_t*)_payload+36+1)<<8|((uint32_t)*((uint8_t*)_payload+36+2))<<16|((uint32_t)*((uint8_t*)_payload+36+3))<<24))
#define DL_ROTORCRAFT_TUNE_HOVER_body_theta(_payload) ((int32_t)(*((uint8_t*)_payload+40)|*((uint8_t*)_payload+40+1)<<8|((uint32_t)*((uint8_t*)_payload+40+2))<<16|((uint32_t)*((uint8_t*)_payload+40+3))<<24))
#define DL_ROTORCRAFT_TUNE_HOVER_body_psi(_payload) ((int32_t)(*((uint8_t*)_payload+44)|*((uint8_t*)_payload+44+1)<<8|((uint32_t)*((uint8_t*)_payload+44+2))<<16|((uint32_t)*((uint8_t*)_payload+44+3))<<24))

#define DL_INS_Z_baro_alt(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_INS_Z_ins_z(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_INS_Z_ins_zd(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_INS_Z_ins_zdd(_payload) ((int32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24))

#define DL_PCAP01_STATUS_ihumid(_payload) ((uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_PCAP01_STATUS_itemp(_payload) ((uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_PCAP01_STATUS_humid(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_PCAP01_STATUS_temp(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))

#define DL_GEIGER_COUNTER_tube1(_payload) ((uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_GEIGER_COUNTER_tube2(_payload) ((uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_GEIGER_COUNTER_vsupply(_payload) ((uint16_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8))

#define DL_INS_REF_ecef_x0(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_INS_REF_ecef_y0(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_INS_REF_ecef_z0(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_INS_REF_lat0(_payload) ((int32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24))
#define DL_INS_REF_lon0(_payload) ((int32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24))
#define DL_INS_REF_alt0(_payload) ((int32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24))
#define DL_INS_REF_hmsl0(_payload) ((int32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24))
#define DL_INS_REF_baro_qfe(_payload) ((int32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24))

#define DL_GPS_INT_ecef_x(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_GPS_INT_ecef_y(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_GPS_INT_ecef_z(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_GPS_INT_lat(_payload) ((int32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24))
#define DL_GPS_INT_lon(_payload) ((int32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24))
#define DL_GPS_INT_alt(_payload) ((int32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24))
#define DL_GPS_INT_hmsl(_payload) ((int32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24))
#define DL_GPS_INT_ecef_xd(_payload) ((int32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24))
#define DL_GPS_INT_ecef_yd(_payload) ((int32_t)(*((uint8_t*)_payload+34)|*((uint8_t*)_payload+34+1)<<8|((uint32_t)*((uint8_t*)_payload+34+2))<<16|((uint32_t)*((uint8_t*)_payload+34+3))<<24))
#define DL_GPS_INT_ecef_zd(_payload) ((int32_t)(*((uint8_t*)_payload+38)|*((uint8_t*)_payload+38+1)<<8|((uint32_t)*((uint8_t*)_payload+38+2))<<16|((uint32_t)*((uint8_t*)_payload+38+3))<<24))
#define DL_GPS_INT_pacc(_payload) ((int32_t)(*((uint8_t*)_payload+42)|*((uint8_t*)_payload+42+1)<<8|((uint32_t)*((uint8_t*)_payload+42+2))<<16|((uint32_t)*((uint8_t*)_payload+42+3))<<24))
#define DL_GPS_INT_sacc(_payload) ((int32_t)(*((uint8_t*)_payload+46)|*((uint8_t*)_payload+46+1)<<8|((uint32_t)*((uint8_t*)_payload+46+2))<<16|((uint32_t)*((uint8_t*)_payload+46+3))<<24))
#define DL_GPS_INT_tow(_payload) ((uint32_t)(*((uint8_t*)_payload+50)|*((uint8_t*)_payload+50+1)<<8|((uint32_t)*((uint8_t*)_payload+50+2))<<16|((uint32_t)*((uint8_t*)_payload+50+3))<<24))
#define DL_GPS_INT_pdop(_payload) ((uint16_t)(*((uint8_t*)_payload+54)|*((uint8_t*)_payload+54+1)<<8))
#define DL_GPS_INT_numsv(_payload) ((uint8_t)(*((uint8_t*)_payload+56)))
#define DL_GPS_INT_fix(_payload) ((uint8_t)(*((uint8_t*)_payload+57)))

#define DL_AHRS_EULER_INT_imu_phi(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_AHRS_EULER_INT_imu_theta(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_AHRS_EULER_INT_imu_psi(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_AHRS_EULER_INT_body_phi(_payload) ((int32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24))
#define DL_AHRS_EULER_INT_body_theta(_payload) ((int32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24))
#define DL_AHRS_EULER_INT_body_psi(_payload) ((int32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24))

#define DL_AHRS_QUAT_INT_imu_qi(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_AHRS_QUAT_INT_imu_qx(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_AHRS_QUAT_INT_imu_qy(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_AHRS_QUAT_INT_imu_qz(_payload) ((int32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24))
#define DL_AHRS_QUAT_INT_body_qi(_payload) ((int32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24))
#define DL_AHRS_QUAT_INT_body_qx(_payload) ((int32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24))
#define DL_AHRS_QUAT_INT_body_qy(_payload) ((int32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24))
#define DL_AHRS_QUAT_INT_body_qz(_payload) ((int32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24))

#define DL_AHRS_RMAT_INT_imu_m00(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_AHRS_RMAT_INT_imu_m01(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_AHRS_RMAT_INT_imu_m02(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_AHRS_RMAT_INT_imu_m10(_payload) ((int32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24))
#define DL_AHRS_RMAT_INT_imu_m11(_payload) ((int32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24))
#define DL_AHRS_RMAT_INT_imu_m12(_payload) ((int32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24))
#define DL_AHRS_RMAT_INT_imu_m20(_payload) ((int32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24))
#define DL_AHRS_RMAT_INT_imu_m21(_payload) ((int32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24))
#define DL_AHRS_RMAT_INT_imu_m22(_payload) ((int32_t)(*((uint8_t*)_payload+34)|*((uint8_t*)_payload+34+1)<<8|((uint32_t)*((uint8_t*)_payload+34+2))<<16|((uint32_t)*((uint8_t*)_payload+34+3))<<24))
#define DL_AHRS_RMAT_INT_body_m00(_payload) ((int32_t)(*((uint8_t*)_payload+38)|*((uint8_t*)_payload+38+1)<<8|((uint32_t)*((uint8_t*)_payload+38+2))<<16|((uint32_t)*((uint8_t*)_payload+38+3))<<24))
#define DL_AHRS_RMAT_INT_body_m01(_payload) ((int32_t)(*((uint8_t*)_payload+42)|*((uint8_t*)_payload+42+1)<<8|((uint32_t)*((uint8_t*)_payload+42+2))<<16|((uint32_t)*((uint8_t*)_payload+42+3))<<24))
#define DL_AHRS_RMAT_INT_body_m02(_payload) ((int32_t)(*((uint8_t*)_payload+46)|*((uint8_t*)_payload+46+1)<<8|((uint32_t)*((uint8_t*)_payload+46+2))<<16|((uint32_t)*((uint8_t*)_payload+46+3))<<24))
#define DL_AHRS_RMAT_INT_body_m10(_payload) ((int32_t)(*((uint8_t*)_payload+50)|*((uint8_t*)_payload+50+1)<<8|((uint32_t)*((uint8_t*)_payload+50+2))<<16|((uint32_t)*((uint8_t*)_payload+50+3))<<24))
#define DL_AHRS_RMAT_INT_body_m11(_payload) ((int32_t)(*((uint8_t*)_payload+54)|*((uint8_t*)_payload+54+1)<<8|((uint32_t)*((uint8_t*)_payload+54+2))<<16|((uint32_t)*((uint8_t*)_payload+54+3))<<24))
#define DL_AHRS_RMAT_INT_body_m12(_payload) ((int32_t)(*((uint8_t*)_payload+58)|*((uint8_t*)_payload+58+1)<<8|((uint32_t)*((uint8_t*)_payload+58+2))<<16|((uint32_t)*((uint8_t*)_payload+58+3))<<24))
#define DL_AHRS_RMAT_INT_body_m20(_payload) ((int32_t)(*((uint8_t*)_payload+62)|*((uint8_t*)_payload+62+1)<<8|((uint32_t)*((uint8_t*)_payload+62+2))<<16|((uint32_t)*((uint8_t*)_payload+62+3))<<24))
#define DL_AHRS_RMAT_INT_body_m21(_payload) ((int32_t)(*((uint8_t*)_payload+66)|*((uint8_t*)_payload+66+1)<<8|((uint32_t)*((uint8_t*)_payload+66+2))<<16|((uint32_t)*((uint8_t*)_payload+66+3))<<24))
#define DL_AHRS_RMAT_INT_body_m22(_payload) ((int32_t)(*((uint8_t*)_payload+70)|*((uint8_t*)_payload+70+1)<<8|((uint32_t)*((uint8_t*)_payload+70+2))<<16|((uint32_t)*((uint8_t*)_payload+70+3))<<24))

#define DL_ROTORCRAFT_NAV_STATUS_block_time(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_ROTORCRAFT_NAV_STATUS_stage_time(_payload) ((uint16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_ROTORCRAFT_NAV_STATUS_cur_block(_payload) ((uint8_t)(*((uint8_t*)_payload+6)))
#define DL_ROTORCRAFT_NAV_STATUS_cur_stage(_payload) ((uint8_t)(*((uint8_t*)_payload+7)))
#define DL_ROTORCRAFT_NAV_STATUS_horizontal_mode(_payload) ((uint8_t)(*((uint8_t*)_payload+8)))

#define DL_ROTORCRAFT_RADIO_CONTROL_roll(_payload) ((int16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_ROTORCRAFT_RADIO_CONTROL_pitch(_payload) ((int16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_ROTORCRAFT_RADIO_CONTROL_yaw(_payload) ((int16_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8))
#define DL_ROTORCRAFT_RADIO_CONTROL_throttle(_payload) ((int16_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8))
#define DL_ROTORCRAFT_RADIO_CONTROL_mode(_payload) ((int16_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8))
#define DL_ROTORCRAFT_RADIO_CONTROL_kill(_payload) ((int16_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8))
#define DL_ROTORCRAFT_RADIO_CONTROL_status(_payload) ((uint8_t)(*((uint8_t*)_payload+14)))

#define DL_VFF_measure(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_VFF_z(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_VFF_zd(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_VFF_bias(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_VFF_Pzz(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_VFF_Pzdzd(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))
#define DL_VFF_Pbb(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24); _f.f; }))

#define DL_BOOZ2_TUNE_FF_fb_rms(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_BOOZ2_TUNE_FF_dg(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_BOOZ2_TUNE_FF_g(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))

#define DL_HFF_x(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_HFF_y(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_HFF_xd(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_HFF_yd(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_HFF_xdd(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_HFF_ydd(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))

#define DL_HFF_DBG_x_measure(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_HFF_DBG_y_measure(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_HFF_DBG_yd_measure(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_HFF_DBG_xd_measure(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_HFF_DBG_Pxx(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_HFF_DBG_Pyy(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))
#define DL_HFF_DBG_Pxdxd(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24); _f.f; }))
#define DL_HFF_DBG_Pydyd(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24); _f.f; }))

#define DL_HFF_GPS_lag_cnt(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_HFF_GPS_lag_cnt_err(_payload) ((int16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_HFF_GPS_save_cnt(_payload) ((int16_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8))

#define DL_BOOZ2_SONAR_front(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_BOOZ2_SONAR_back(_payload) ((uint16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_BOOZ2_SONAR_right(_payload) ((uint16_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8))
#define DL_BOOZ2_SONAR_left(_payload) ((uint16_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8))

#define DL_BOOZ2_CAM_tilt(_payload) ((int16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_BOOZ2_CAM_pan(_payload) ((int16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))

#define DL_AHRS_REF_QUAT_ref_qi(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_AHRS_REF_QUAT_ref_qx(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_AHRS_REF_QUAT_ref_qy(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_AHRS_REF_QUAT_ref_qz(_payload) ((int32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24))
#define DL_AHRS_REF_QUAT_body_qi(_payload) ((int32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24))
#define DL_AHRS_REF_QUAT_body_qx(_payload) ((int32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24))
#define DL_AHRS_REF_QUAT_body_qy(_payload) ((int32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24))
#define DL_AHRS_REF_QUAT_body_qz(_payload) ((int32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24))

#define DL_EKF7_XHAT_c(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_EKF7_XHAT_s1(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_EKF7_XHAT_s2(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_EKF7_XHAT_s3(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_EKF7_XHAT_p(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_EKF7_XHAT_q(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))
#define DL_EKF7_XHAT_r(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24); _f.f; }))
#define DL_EKF7_XHAT_bp(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24); _f.f; }))
#define DL_EKF7_XHAT_bq(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+34)|*((uint8_t*)_payload+34+1)<<8|((uint32_t)*((uint8_t*)_payload+34+2))<<16|((uint32_t)*((uint8_t*)_payload+34+3))<<24); _f.f; }))
#define DL_EKF7_XHAT_br(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+38)|*((uint8_t*)_payload+38+1)<<8|((uint32_t)*((uint8_t*)_payload+38+2))<<16|((uint32_t)*((uint8_t*)_payload+38+3))<<24); _f.f; }))

#define DL_EKF7_Y_timecount(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_EKF7_Y_g1(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))
#define DL_EKF7_Y_g2(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24); _f.f; }))
#define DL_EKF7_Y_g3(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24); _f.f; }))
#define DL_EKF7_Y_m1(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8|((uint32_t)*((uint8_t*)_payload+16+2))<<16|((uint32_t)*((uint8_t*)_payload+16+3))<<24); _f.f; }))
#define DL_EKF7_Y_m2(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+20)|*((uint8_t*)_payload+20+1)<<8|((uint32_t)*((uint8_t*)_payload+20+2))<<16|((uint32_t)*((uint8_t*)_payload+20+3))<<24); _f.f; }))
#define DL_EKF7_Y_m3(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+24)|*((uint8_t*)_payload+24+1)<<8|((uint32_t)*((uint8_t*)_payload+24+2))<<16|((uint32_t)*((uint8_t*)_payload+24+3))<<24); _f.f; }))
#define DL_EKF7_Y_p(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+28)|*((uint8_t*)_payload+28+1)<<8|((uint32_t)*((uint8_t*)_payload+28+2))<<16|((uint32_t)*((uint8_t*)_payload+28+3))<<24); _f.f; }))
#define DL_EKF7_Y_q(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+32)|*((uint8_t*)_payload+32+1)<<8|((uint32_t)*((uint8_t*)_payload+32+2))<<16|((uint32_t)*((uint8_t*)_payload+32+3))<<24); _f.f; }))
#define DL_EKF7_Y_r(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+36)|*((uint8_t*)_payload+36+1)<<8|((uint32_t)*((uint8_t*)_payload+36+2))<<16|((uint32_t)*((uint8_t*)_payload+36+3))<<24); _f.f; }))

#define DL_EKF7_P_DIAG_c(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_EKF7_P_DIAG_s1(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_EKF7_P_DIAG_s2(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_EKF7_P_DIAG_s3(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_EKF7_P_DIAG_p(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_EKF7_P_DIAG_q(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))
#define DL_EKF7_P_DIAG_r(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24); _f.f; }))
#define DL_EKF7_P_DIAG_bp(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24); _f.f; }))
#define DL_EKF7_P_DIAG_bq(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+34)|*((uint8_t*)_payload+34+1)<<8|((uint32_t)*((uint8_t*)_payload+34+2))<<16|((uint32_t)*((uint8_t*)_payload+34+3))<<24); _f.f; }))
#define DL_EKF7_P_DIAG_br(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+38)|*((uint8_t*)_payload+38+1)<<8|((uint32_t)*((uint8_t*)_payload+38+2))<<16|((uint32_t)*((uint8_t*)_payload+38+3))<<24); _f.f; }))

#define DL_AHRS_EULER_phi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_AHRS_EULER_theta(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_AHRS_EULER_psi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))

#define DL_AHRS_MEASUREMENT_EULER_phi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_AHRS_MEASUREMENT_EULER_theta(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_AHRS_MEASUREMENT_EULER_psi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))

#define DL_WT_rpm(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))

#define DL_CSC_CAN_DEBUG_err_nb(_payload) ((uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_CSC_CAN_DEBUG_err_code(_payload) ((uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))

#define DL_CSC_CAN_MSG_frame(_payload) ((uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_CSC_CAN_MSG_id(_payload) ((uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_CSC_CAN_MSG_data_a(_payload) ((uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_CSC_CAN_MSG_data_b(_payload) ((uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24))

#define DL_AHRS_GYRO_BIAS_INT_bp(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_AHRS_GYRO_BIAS_INT_bq(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_AHRS_GYRO_BIAS_INT_br(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))

#define DL_FMS_TIME_tv_sec(_payload) ((uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_FMS_TIME_tv_nsec(_payload) ((uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_FMS_TIME_delay_ns(_payload) ((uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))

#define DL_LOADCELL_load(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))

#define DL_FLA_DEBUG_past_input(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_FLA_DEBUG_imu_rate(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_FLA_DEBUG_desired_accel(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_FLA_DEBUG_motor_command(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))

#define DL_BLMC_FAULT_STATUS_raw_fault_length(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_BLMC_FAULT_STATUS_raw_fault(_payload) ((uint16_t*)(_payload+3))

#define DL_BLMC_SPEEDS_speeds_length(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_BLMC_SPEEDS_speeds(_payload) ((int16_t*)(_payload+3))

#define DL_AHRS_DEBUG_QUAT_jqi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_AHRS_DEBUG_QUAT_jqx(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_AHRS_DEBUG_QUAT_jqy(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_AHRS_DEBUG_QUAT_jqz(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_AHRS_DEBUG_QUAT_xqi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_AHRS_DEBUG_QUAT_xqx(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))
#define DL_AHRS_DEBUG_QUAT_xqy(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24); _f.f; }))
#define DL_AHRS_DEBUG_QUAT_xqz(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24); _f.f; }))
#define DL_AHRS_DEBUG_QUAT_mqi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+34)|*((uint8_t*)_payload+34+1)<<8|((uint32_t)*((uint8_t*)_payload+34+2))<<16|((uint32_t)*((uint8_t*)_payload+34+3))<<24); _f.f; }))
#define DL_AHRS_DEBUG_QUAT_mqx(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+38)|*((uint8_t*)_payload+38+1)<<8|((uint32_t)*((uint8_t*)_payload+38+2))<<16|((uint32_t)*((uint8_t*)_payload+38+3))<<24); _f.f; }))
#define DL_AHRS_DEBUG_QUAT_mqy(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+42)|*((uint8_t*)_payload+42+1)<<8|((uint32_t)*((uint8_t*)_payload+42+2))<<16|((uint32_t)*((uint8_t*)_payload+42+3))<<24); _f.f; }))
#define DL_AHRS_DEBUG_QUAT_mqz(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+46)|*((uint8_t*)_payload+46+1)<<8|((uint32_t)*((uint8_t*)_payload+46+2))<<16|((uint32_t)*((uint8_t*)_payload+46+3))<<24); _f.f; }))

#define DL_BLMC_BUSVOLTS_busvolts_length(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_BLMC_BUSVOLTS_busvolts(_payload) ((uint16_t*)(_payload+3))

#define DL_SYSTEM_STATUS_csc1_loop_count(_payload) ((uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_SYSTEM_STATUS_csc1_msg_count(_payload) ((uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_SYSTEM_STATUS_csc2_loop_count(_payload) ((uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_SYSTEM_STATUS_csc2_msg_count(_payload) ((uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24))
#define DL_SYSTEM_STATUS_can_rx_err(_payload) ((uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24))
#define DL_SYSTEM_STATUS_can_tx_err(_payload) ((uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24))
#define DL_SYSTEM_STATUS_rc_parser_err(_payload) ((uint32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24))
#define DL_SYSTEM_STATUS_system_fault(_payload) ((uint8_t)(*((uint8_t*)_payload+30)))

#define DL_DYNAMIXEL_left_wing(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_DYNAMIXEL_right_wing(_payload) ((uint16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_DYNAMIXEL_left_wing_flag(_payload) ((uint8_t)(*((uint8_t*)_payload+6)))
#define DL_DYNAMIXEL_right_wing_flag(_payload) ((uint8_t)(*((uint8_t*)_payload+7)))
#define DL_DYNAMIXEL_invalid_position(_payload) ((uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24))
#define DL_DYNAMIXEL_timeout_events(_payload) ((uint32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24))
#define DL_DYNAMIXEL_checksum_errors(_payload) ((uint32_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8|((uint32_t)*((uint8_t*)_payload+16+2))<<16|((uint32_t)*((uint8_t*)_payload+16+3))<<24))
#define DL_DYNAMIXEL_fuse_rotation_angle(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+20)|*((uint8_t*)_payload+20+1)<<8|((uint32_t)*((uint8_t*)_payload+20+2))<<16|((uint32_t)*((uint8_t*)_payload+20+3))<<24); _f.f; }))
#define DL_DYNAMIXEL_fuse_rotation_rate(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+24)|*((uint8_t*)_payload+24+1)<<8|((uint32_t)*((uint8_t*)_payload+24+2))<<16|((uint32_t)*((uint8_t*)_payload+24+3))<<24); _f.f; }))

#define DL_RMAT_DEBUG_a(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_RMAT_DEBUG_b(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_RMAT_DEBUG_c(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_RMAT_DEBUG_d(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_RMAT_DEBUG_e(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_RMAT_DEBUG_f(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))
#define DL_RMAT_DEBUG_g(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24); _f.f; }))
#define DL_RMAT_DEBUG_h(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24); _f.f; }))
#define DL_RMAT_DEBUG_i(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+34)|*((uint8_t*)_payload+34+1)<<8|((uint32_t)*((uint8_t*)_payload+34+2))<<16|((uint32_t)*((uint8_t*)_payload+34+3))<<24); _f.f; }))

#define DL_SIMPLE_COMMANDS_roll(_payload) ((int16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_SIMPLE_COMMANDS_pitch(_payload) ((int16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_SIMPLE_COMMANDS_yaw(_payload) ((int16_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8))

#define DL_VANE_SENSOR_alpha(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_VANE_SENSOR_alpha_filtered(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_VANE_SENSOR_alpha_target(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_VANE_SENSOR_alpha_vane_error(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_VANE_SENSOR_alpha2(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_VANE_SENSOR_beta(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))
#define DL_VANE_SENSOR_beta_filtered(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24); _f.f; }))
#define DL_VANE_SENSOR_beta_target(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24); _f.f; }))
#define DL_VANE_SENSOR_beta_vane_error(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+34)|*((uint8_t*)_payload+34+1)<<8|((uint32_t)*((uint8_t*)_payload+34+2))<<16|((uint32_t)*((uint8_t*)_payload+34+3))<<24); _f.f; }))
#define DL_VANE_SENSOR_beta2(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+38)|*((uint8_t*)_payload+38+1)<<8|((uint32_t)*((uint8_t*)_payload+38+2))<<16|((uint32_t)*((uint8_t*)_payload+38+3))<<24); _f.f; }))

#define DL_CONTROLLER_GAINS_roll_gamma_p(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_CONTROLLER_GAINS_roll_gamma_d(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_CONTROLLER_GAINS_roll_gamma_i(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_CONTROLLER_GAINS_pitch_gamma_p(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_CONTROLLER_GAINS_pitch_gamma_d(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_CONTROLLER_GAINS_pitch_gamma_i(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))
#define DL_CONTROLLER_GAINS_yaw_gamma_p(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24); _f.f; }))
#define DL_CONTROLLER_GAINS_yaw_gamma_d(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24); _f.f; }))
#define DL_CONTROLLER_GAINS_yaw_gamma_i(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+34)|*((uint8_t*)_payload+34+1)<<8|((uint32_t)*((uint8_t*)_payload+34+2))<<16|((uint32_t)*((uint8_t*)_payload+34+3))<<24); _f.f; }))

#define DL_AHRS_LKF_phi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_AHRS_LKF_theta(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_AHRS_LKF_psi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_AHRS_LKF_qi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_AHRS_LKF_qx(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_AHRS_LKF_qy(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))
#define DL_AHRS_LKF_qz(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24); _f.f; }))
#define DL_AHRS_LKF_p(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24); _f.f; }))
#define DL_AHRS_LKF_q(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+34)|*((uint8_t*)_payload+34+1)<<8|((uint32_t)*((uint8_t*)_payload+34+2))<<16|((uint32_t)*((uint8_t*)_payload+34+3))<<24); _f.f; }))
#define DL_AHRS_LKF_r(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+38)|*((uint8_t*)_payload+38+1)<<8|((uint32_t)*((uint8_t*)_payload+38+2))<<16|((uint32_t)*((uint8_t*)_payload+38+3))<<24); _f.f; }))
#define DL_AHRS_LKF_ax(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+42)|*((uint8_t*)_payload+42+1)<<8|((uint32_t)*((uint8_t*)_payload+42+2))<<16|((uint32_t)*((uint8_t*)_payload+42+3))<<24); _f.f; }))
#define DL_AHRS_LKF_ay(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+46)|*((uint8_t*)_payload+46+1)<<8|((uint32_t)*((uint8_t*)_payload+46+2))<<16|((uint32_t)*((uint8_t*)_payload+46+3))<<24); _f.f; }))
#define DL_AHRS_LKF_az(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+50)|*((uint8_t*)_payload+50+1)<<8|((uint32_t)*((uint8_t*)_payload+50+2))<<16|((uint32_t)*((uint8_t*)_payload+50+3))<<24); _f.f; }))
#define DL_AHRS_LKF_mx(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+54)|*((uint8_t*)_payload+54+1)<<8|((uint32_t)*((uint8_t*)_payload+54+2))<<16|((uint32_t)*((uint8_t*)_payload+54+3))<<24); _f.f; }))
#define DL_AHRS_LKF_my(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+58)|*((uint8_t*)_payload+58+1)<<8|((uint32_t)*((uint8_t*)_payload+58+2))<<16|((uint32_t)*((uint8_t*)_payload+58+3))<<24); _f.f; }))
#define DL_AHRS_LKF_mz(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+62)|*((uint8_t*)_payload+62+1)<<8|((uint32_t)*((uint8_t*)_payload+62+2))<<16|((uint32_t)*((uint8_t*)_payload+62+3))<<24); _f.f; }))

#define DL_AHRS_LKF_DEBUG_phi_err(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_AHRS_LKF_DEBUG_theta_err(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_AHRS_LKF_DEBUG_psi_err(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_AHRS_LKF_DEBUG_bp(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_AHRS_LKF_DEBUG_bq(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_AHRS_LKF_DEBUG_br(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))
#define DL_AHRS_LKF_DEBUG_quat_norm(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24); _f.f; }))
#define DL_AHRS_LKF_DEBUG_phi_accel(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24); _f.f; }))
#define DL_AHRS_LKF_DEBUG_theta_accel(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+34)|*((uint8_t*)_payload+34+1)<<8|((uint32_t)*((uint8_t*)_payload+34+2))<<16|((uint32_t)*((uint8_t*)_payload+34+3))<<24); _f.f; }))
#define DL_AHRS_LKF_DEBUG_phi_cov(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+38)|*((uint8_t*)_payload+38+1)<<8|((uint32_t)*((uint8_t*)_payload+38+2))<<16|((uint32_t)*((uint8_t*)_payload+38+3))<<24); _f.f; }))
#define DL_AHRS_LKF_DEBUG_theta_cov(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+42)|*((uint8_t*)_payload+42+1)<<8|((uint32_t)*((uint8_t*)_payload+42+2))<<16|((uint32_t)*((uint8_t*)_payload+42+3))<<24); _f.f; }))
#define DL_AHRS_LKF_DEBUG_psi_cov(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+46)|*((uint8_t*)_payload+46+1)<<8|((uint32_t)*((uint8_t*)_payload+46+2))<<16|((uint32_t)*((uint8_t*)_payload+46+3))<<24); _f.f; }))
#define DL_AHRS_LKF_DEBUG_bp_cov(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+50)|*((uint8_t*)_payload+50+1)<<8|((uint32_t)*((uint8_t*)_payload+50+2))<<16|((uint32_t)*((uint8_t*)_payload+50+3))<<24); _f.f; }))
#define DL_AHRS_LKF_DEBUG_bq_cov(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+54)|*((uint8_t*)_payload+54+1)<<8|((uint32_t)*((uint8_t*)_payload+54+2))<<16|((uint32_t)*((uint8_t*)_payload+54+3))<<24); _f.f; }))
#define DL_AHRS_LKF_DEBUG_br_cov(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+58)|*((uint8_t*)_payload+58+1)<<8|((uint32_t)*((uint8_t*)_payload+58+2))<<16|((uint32_t)*((uint8_t*)_payload+58+3))<<24); _f.f; }))

#define DL_AHRS_LKF_ACC_DBG_qi_err(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_AHRS_LKF_ACC_DBG_qx_err(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_AHRS_LKF_ACC_DBG_qy_err(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_AHRS_LKF_ACC_DBG_qz_err(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_AHRS_LKF_ACC_DBG_bp_err(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_AHRS_LKF_ACC_DBG_bq_err(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))
#define DL_AHRS_LKF_ACC_DBG_br_err(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24); _f.f; }))

#define DL_AHRS_LKF_MAG_DBG_qi_err(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_AHRS_LKF_MAG_DBG_qx_err(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_AHRS_LKF_MAG_DBG_qy_err(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_AHRS_LKF_MAG_DBG_qz_err(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_AHRS_LKF_MAG_DBG_bp_err(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_AHRS_LKF_MAG_DBG_bq_err(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))
#define DL_AHRS_LKF_MAG_DBG_br_err(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24); _f.f; }))

#define DL_NPS_SENSORS_SCALED_acc_x(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_NPS_SENSORS_SCALED_acc_y(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_NPS_SENSORS_SCALED_acc_z(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_NPS_SENSORS_SCALED_mag_x(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_NPS_SENSORS_SCALED_mag_y(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_NPS_SENSORS_SCALED_mag_z(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))

#define DL_INS_ins_x(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_INS_ins_y(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_INS_ins_z(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_INS_ins_xd(_payload) ((int32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24))
#define DL_INS_ins_yd(_payload) ((int32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24))
#define DL_INS_ins_zd(_payload) ((int32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24))
#define DL_INS_ins_xdd(_payload) ((int32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24))
#define DL_INS_ins_ydd(_payload) ((int32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24))
#define DL_INS_ins_zdd(_payload) ((int32_t)(*((uint8_t*)_payload+34)|*((uint8_t*)_payload+34+1)<<8|((uint32_t)*((uint8_t*)_payload+34+2))<<16|((uint32_t)*((uint8_t*)_payload+34+3))<<24))

#define DL_GPS_ERROR_x_position(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_GPS_ERROR_y_position(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_GPS_ERROR_z_position(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_GPS_ERROR_x_velocity(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_GPS_ERROR_y_velocity(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_GPS_ERROR_z_velocity(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))

#define DL_IMU_GYRO_gp(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_IMU_GYRO_gq(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_IMU_GYRO_gr(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))

#define DL_IMU_MAG_mx(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_IMU_MAG_my(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_IMU_MAG_mz(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))

#define DL_IMU_ACCEL_ax(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_IMU_ACCEL_ay(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_IMU_ACCEL_az(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))

#define DL_IMU_GYRO_RAW_gp(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_IMU_GYRO_RAW_gq(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_IMU_GYRO_RAW_gr(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))

#define DL_IMU_ACCEL_RAW_ax(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_IMU_ACCEL_RAW_ay(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_IMU_ACCEL_RAW_az(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))

#define DL_IMU_MAG_RAW_mx(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_IMU_MAG_RAW_my(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_IMU_MAG_RAW_mz(_payload) ((int32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))

#define DL_IMU_MAG_SETTINGS_inclination(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_IMU_MAG_SETTINGS_declination(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_IMU_MAG_SETTINGS_hardiron_x(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_IMU_MAG_SETTINGS_hardiron_y(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_IMU_MAG_SETTINGS_hardiron_z(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))

#define DL_IMU_GYRO_LP_gp(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_IMU_GYRO_LP_gq(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_IMU_GYRO_LP_gr(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))

#define DL_IMU_PRESSURE_p(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))

#define DL_IMU_HS_GYRO_axis(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_IMU_HS_GYRO_samples_length(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_IMU_HS_GYRO_samples(_payload) ((uint32_t*)(_payload+4))

#define DL_TEST_PASSTHROUGH_STATUS_io_proc_msg_cnt(_payload) ((uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_TEST_PASSTHROUGH_STATUS_io_proc_err_cnt(_payload) ((uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))
#define DL_TEST_PASSTHROUGH_STATUS_io_link_msg_cnt(_payload) ((uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24))
#define DL_TEST_PASSTHROUGH_STATUS_io_link_err_cnt(_payload) ((uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24))
#define DL_TEST_PASSTHROUGH_STATUS_rc_status(_payload) ((uint8_t)(*((uint8_t*)_payload+18)))

#define DL_WEATHER_p_amb(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_WEATHER_t_amb(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_WEATHER_windspeed(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_WEATHER_wind_from(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_WEATHER_humidity(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))

#define DL_IMU_TURNTABLE_omega(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))

#define DL_BARO_RAW_abs(_payload) ((int32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_BARO_RAW_diff(_payload) ((int32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24))

#define DL_TIME_t(_payload) ((uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))

#define DL_ROTORCRAFT_STATUS_link_imu_nb_err(_payload) ((uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_ROTORCRAFT_STATUS_blmc_nb_err(_payload) ((uint8_t)(*((uint8_t*)_payload+6)))
#define DL_ROTORCRAFT_STATUS_rc_status(_payload) ((uint8_t)(*((uint8_t*)_payload+7)))
#define DL_ROTORCRAFT_STATUS_frame_rate(_payload) ((uint8_t)(*((uint8_t*)_payload+8)))
#define DL_ROTORCRAFT_STATUS_gps_status(_payload) ((uint8_t)(*((uint8_t*)_payload+9)))
#define DL_ROTORCRAFT_STATUS_ap_mode(_payload) ((uint8_t)(*((uint8_t*)_payload+10)))
#define DL_ROTORCRAFT_STATUS_ap_in_flight(_payload) ((uint8_t)(*((uint8_t*)_payload+11)))
#define DL_ROTORCRAFT_STATUS_ap_motors_on(_payload) ((uint8_t)(*((uint8_t*)_payload+12)))
#define DL_ROTORCRAFT_STATUS_ap_h_mode(_payload) ((uint8_t)(*((uint8_t*)_payload+13)))
#define DL_ROTORCRAFT_STATUS_ap_v_mode(_payload) ((uint8_t)(*((uint8_t*)_payload+14)))
#define DL_ROTORCRAFT_STATUS_vsupply(_payload) ((uint8_t)(*((uint8_t*)_payload+15)))
#define DL_ROTORCRAFT_STATUS_cpu_time(_payload) ((uint16_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8))

#define DL_STATE_FILTER_STATUS_state_filter_mode(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_STATE_FILTER_STATUS_value(_payload) ((uint16_t)(*((uint8_t*)_payload+3)|*((uint8_t*)_payload+3+1)<<8))

#define DL_OPTICFLOW_flow(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_OPTICFLOW_ref_alt(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))

#define DL_VISUALTARGET_x(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_VISUALTARGET_y(_payload) ((uint16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))

#define DL_NPS_POS_LLH_pprz_lat(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_NPS_POS_LLH_lat_geod(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_NPS_POS_LLH_lat_geoc(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_NPS_POS_LLH_pprz_lon(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_NPS_POS_LLH_lon(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_NPS_POS_LLH_pprz_alt(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))
#define DL_NPS_POS_LLH_alt_geod(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24); _f.f; }))
#define DL_NPS_POS_LLH_agl(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24); _f.f; }))
#define DL_NPS_POS_LLH_asl(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+34)|*((uint8_t*)_payload+34+1)<<8|((uint32_t)*((uint8_t*)_payload+34+2))<<16|((uint32_t)*((uint8_t*)_payload+34+3))<<24); _f.f; }))

#define DL_NPS_RPMS_front(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_NPS_RPMS_back(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_NPS_RPMS_right(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_NPS_RPMS_left(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))

#define DL_NPS_SPEED_POS_ltpp_xdd(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_NPS_SPEED_POS_ltpp_ydd(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_NPS_SPEED_POS_ltpp_zdd(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_NPS_SPEED_POS_ltpp_xd(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_NPS_SPEED_POS_ltpp_yd(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_NPS_SPEED_POS_ltpp_zd(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))
#define DL_NPS_SPEED_POS_ltpp_x(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24); _f.f; }))
#define DL_NPS_SPEED_POS_ltpp_y(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24); _f.f; }))
#define DL_NPS_SPEED_POS_ltpp_z(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+34)|*((uint8_t*)_payload+34+1)<<8|((uint32_t)*((uint8_t*)_payload+34+2))<<16|((uint32_t)*((uint8_t*)_payload+34+3))<<24); _f.f; }))

#define DL_NPS_RATE_ATTITUDE_p(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_NPS_RATE_ATTITUDE_q(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_NPS_RATE_ATTITUDE_r(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_NPS_RATE_ATTITUDE_phi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_NPS_RATE_ATTITUDE_theta(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_NPS_RATE_ATTITUDE_psi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))

#define DL_NPS_GYRO_BIAS_bp(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_NPS_GYRO_BIAS_bq(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_NPS_GYRO_BIAS_br(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))

#define DL_NPS_RANGE_METER_dist(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))

#define DL_NPS_WIND_vx(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_NPS_WIND_vy(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_NPS_WIND_vz(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))

#define DL_BOOZ_DEBUG_FOO_ami_stat(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))

#define DL_BOOZ_MAX1167_ERR_erno(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))

#define DL_PPRZ_DEBUG_module(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_PPRZ_DEBUG_errno(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))

#define DL_NPS_ACCEL_LTP_xdd(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_NPS_ACCEL_LTP_ydd(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_NPS_ACCEL_LTP_zdd(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))

#define DL_LOOSE_INS_GPS_status(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_LOOSE_INS_GPS_time_running(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+3)|((uint64_t)*((uint8_t*)_payload+3+1))<<8|((uint64_t)*((uint8_t*)_payload+3+2))<<16|((uint64_t)*((uint8_t*)_payload+3+3))<<24|((uint64_t)*((uint8_t*)_payload+3+4))<<32|((uint64_t)*((uint8_t*)_payload+3+5))<<40|((uint64_t)*((uint8_t*)_payload+3+6))<<48|((uint64_t)*((uint8_t*)_payload+3+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_LOOSE_INS_GPS_q0(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+11)|((uint64_t)*((uint8_t*)_payload+11+1))<<8|((uint64_t)*((uint8_t*)_payload+11+2))<<16|((uint64_t)*((uint8_t*)_payload+11+3))<<24|((uint64_t)*((uint8_t*)_payload+11+4))<<32|((uint64_t)*((uint8_t*)_payload+11+5))<<40|((uint64_t)*((uint8_t*)_payload+11+6))<<48|((uint64_t)*((uint8_t*)_payload+11+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_LOOSE_INS_GPS_q1(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+19)|((uint64_t)*((uint8_t*)_payload+19+1))<<8|((uint64_t)*((uint8_t*)_payload+19+2))<<16|((uint64_t)*((uint8_t*)_payload+19+3))<<24|((uint64_t)*((uint8_t*)_payload+19+4))<<32|((uint64_t)*((uint8_t*)_payload+19+5))<<40|((uint64_t)*((uint8_t*)_payload+19+6))<<48|((uint64_t)*((uint8_t*)_payload+19+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_LOOSE_INS_GPS_q2(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+27)|((uint64_t)*((uint8_t*)_payload+27+1))<<8|((uint64_t)*((uint8_t*)_payload+27+2))<<16|((uint64_t)*((uint8_t*)_payload+27+3))<<24|((uint64_t)*((uint8_t*)_payload+27+4))<<32|((uint64_t)*((uint8_t*)_payload+27+5))<<40|((uint64_t)*((uint8_t*)_payload+27+6))<<48|((uint64_t)*((uint8_t*)_payload+27+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_LOOSE_INS_GPS_q3(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+35)|((uint64_t)*((uint8_t*)_payload+35+1))<<8|((uint64_t)*((uint8_t*)_payload+35+2))<<16|((uint64_t)*((uint8_t*)_payload+35+3))<<24|((uint64_t)*((uint8_t*)_payload+35+4))<<32|((uint64_t)*((uint8_t*)_payload+35+5))<<40|((uint64_t)*((uint8_t*)_payload+35+6))<<48|((uint64_t)*((uint8_t*)_payload+35+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_LOOSE_INS_GPS_phi(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+43)|((uint64_t)*((uint8_t*)_payload+43+1))<<8|((uint64_t)*((uint8_t*)_payload+43+2))<<16|((uint64_t)*((uint8_t*)_payload+43+3))<<24|((uint64_t)*((uint8_t*)_payload+43+4))<<32|((uint64_t)*((uint8_t*)_payload+43+5))<<40|((uint64_t)*((uint8_t*)_payload+43+6))<<48|((uint64_t)*((uint8_t*)_payload+43+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_LOOSE_INS_GPS_theta(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+51)|((uint64_t)*((uint8_t*)_payload+51+1))<<8|((uint64_t)*((uint8_t*)_payload+51+2))<<16|((uint64_t)*((uint8_t*)_payload+51+3))<<24|((uint64_t)*((uint8_t*)_payload+51+4))<<32|((uint64_t)*((uint8_t*)_payload+51+5))<<40|((uint64_t)*((uint8_t*)_payload+51+6))<<48|((uint64_t)*((uint8_t*)_payload+51+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_LOOSE_INS_GPS_psi(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+59)|((uint64_t)*((uint8_t*)_payload+59+1))<<8|((uint64_t)*((uint8_t*)_payload+59+2))<<16|((uint64_t)*((uint8_t*)_payload+59+3))<<24|((uint64_t)*((uint8_t*)_payload+59+4))<<32|((uint64_t)*((uint8_t*)_payload+59+5))<<40|((uint64_t)*((uint8_t*)_payload+59+6))<<48|((uint64_t)*((uint8_t*)_payload+59+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_LOOSE_INS_GPS_north(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+67)|((uint64_t)*((uint8_t*)_payload+67+1))<<8|((uint64_t)*((uint8_t*)_payload+67+2))<<16|((uint64_t)*((uint8_t*)_payload+67+3))<<24|((uint64_t)*((uint8_t*)_payload+67+4))<<32|((uint64_t)*((uint8_t*)_payload+67+5))<<40|((uint64_t)*((uint8_t*)_payload+67+6))<<48|((uint64_t)*((uint8_t*)_payload+67+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_LOOSE_INS_GPS_east(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+75)|((uint64_t)*((uint8_t*)_payload+75+1))<<8|((uint64_t)*((uint8_t*)_payload+75+2))<<16|((uint64_t)*((uint8_t*)_payload+75+3))<<24|((uint64_t)*((uint8_t*)_payload+75+4))<<32|((uint64_t)*((uint8_t*)_payload+75+5))<<40|((uint64_t)*((uint8_t*)_payload+75+6))<<48|((uint64_t)*((uint8_t*)_payload+75+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_LOOSE_INS_GPS_down(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+83)|((uint64_t)*((uint8_t*)_payload+83+1))<<8|((uint64_t)*((uint8_t*)_payload+83+2))<<16|((uint64_t)*((uint8_t*)_payload+83+3))<<24|((uint64_t)*((uint8_t*)_payload+83+4))<<32|((uint64_t)*((uint8_t*)_payload+83+5))<<40|((uint64_t)*((uint8_t*)_payload+83+6))<<48|((uint64_t)*((uint8_t*)_payload+83+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_LOOSE_INS_GPS_v_north(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+91)|((uint64_t)*((uint8_t*)_payload+91+1))<<8|((uint64_t)*((uint8_t*)_payload+91+2))<<16|((uint64_t)*((uint8_t*)_payload+91+3))<<24|((uint64_t)*((uint8_t*)_payload+91+4))<<32|((uint64_t)*((uint8_t*)_payload+91+5))<<40|((uint64_t)*((uint8_t*)_payload+91+6))<<48|((uint64_t)*((uint8_t*)_payload+91+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_LOOSE_INS_GPS_v_east(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+99)|((uint64_t)*((uint8_t*)_payload+99+1))<<8|((uint64_t)*((uint8_t*)_payload+99+2))<<16|((uint64_t)*((uint8_t*)_payload+99+3))<<24|((uint64_t)*((uint8_t*)_payload+99+4))<<32|((uint64_t)*((uint8_t*)_payload+99+5))<<40|((uint64_t)*((uint8_t*)_payload+99+6))<<48|((uint64_t)*((uint8_t*)_payload+99+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_LOOSE_INS_GPS_v_down(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+107)|((uint64_t)*((uint8_t*)_payload+107+1))<<8|((uint64_t)*((uint8_t*)_payload+107+2))<<16|((uint64_t)*((uint8_t*)_payload+107+3))<<24|((uint64_t)*((uint8_t*)_payload+107+4))<<32|((uint64_t)*((uint8_t*)_payload+107+5))<<40|((uint64_t)*((uint8_t*)_payload+107+6))<<48|((uint64_t)*((uint8_t*)_payload+107+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_LOOSE_INS_GPS_est_p(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+115)|((uint64_t)*((uint8_t*)_payload+115+1))<<8|((uint64_t)*((uint8_t*)_payload+115+2))<<16|((uint64_t)*((uint8_t*)_payload+115+3))<<24|((uint64_t)*((uint8_t*)_payload+115+4))<<32|((uint64_t)*((uint8_t*)_payload+115+5))<<40|((uint64_t)*((uint8_t*)_payload+115+6))<<48|((uint64_t)*((uint8_t*)_payload+115+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_LOOSE_INS_GPS_est_q(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+123)|((uint64_t)*((uint8_t*)_payload+123+1))<<8|((uint64_t)*((uint8_t*)_payload+123+2))<<16|((uint64_t)*((uint8_t*)_payload+123+3))<<24|((uint64_t)*((uint8_t*)_payload+123+4))<<32|((uint64_t)*((uint8_t*)_payload+123+5))<<40|((uint64_t)*((uint8_t*)_payload+123+6))<<48|((uint64_t)*((uint8_t*)_payload+123+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_LOOSE_INS_GPS_est_r(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+131)|((uint64_t)*((uint8_t*)_payload+131+1))<<8|((uint64_t)*((uint8_t*)_payload+131+2))<<16|((uint64_t)*((uint8_t*)_payload+131+3))<<24|((uint64_t)*((uint8_t*)_payload+131+4))<<32|((uint64_t)*((uint8_t*)_payload+131+5))<<40|((uint64_t)*((uint8_t*)_payload+131+6))<<48|((uint64_t)*((uint8_t*)_payload+131+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_LOOSE_INS_GPS_gyroBias_x(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+139)|((uint64_t)*((uint8_t*)_payload+139+1))<<8|((uint64_t)*((uint8_t*)_payload+139+2))<<16|((uint64_t)*((uint8_t*)_payload+139+3))<<24|((uint64_t)*((uint8_t*)_payload+139+4))<<32|((uint64_t)*((uint8_t*)_payload+139+5))<<40|((uint64_t)*((uint8_t*)_payload+139+6))<<48|((uint64_t)*((uint8_t*)_payload+139+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_LOOSE_INS_GPS_gyroBias_y(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+147)|((uint64_t)*((uint8_t*)_payload+147+1))<<8|((uint64_t)*((uint8_t*)_payload+147+2))<<16|((uint64_t)*((uint8_t*)_payload+147+3))<<24|((uint64_t)*((uint8_t*)_payload+147+4))<<32|((uint64_t)*((uint8_t*)_payload+147+5))<<40|((uint64_t)*((uint8_t*)_payload+147+6))<<48|((uint64_t)*((uint8_t*)_payload+147+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_LOOSE_INS_GPS_gyroBias_z(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+155)|((uint64_t)*((uint8_t*)_payload+155+1))<<8|((uint64_t)*((uint8_t*)_payload+155+2))<<16|((uint64_t)*((uint8_t*)_payload+155+3))<<24|((uint64_t)*((uint8_t*)_payload+155+4))<<32|((uint64_t)*((uint8_t*)_payload+155+5))<<40|((uint64_t)*((uint8_t*)_payload+155+6))<<48|((uint64_t)*((uint8_t*)_payload+155+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_LOOSE_INS_GPS_imuCallbacks(_payload) ((uint32_t)(*((uint8_t*)_payload+163)|*((uint8_t*)_payload+163+1)<<8|((uint32_t)*((uint8_t*)_payload+163+2))<<16|((uint32_t)*((uint8_t*)_payload+163+3))<<24))
#define DL_LOOSE_INS_GPS_gpsCallbacks(_payload) ((uint32_t)(*((uint8_t*)_payload+167)|*((uint8_t*)_payload+167+1)<<8|((uint32_t)*((uint8_t*)_payload+167+2))<<16|((uint32_t)*((uint8_t*)_payload+167+3))<<24))
#define DL_LOOSE_INS_GPS_baroCallbacks(_payload) ((uint32_t)(*((uint8_t*)_payload+171)|*((uint8_t*)_payload+171+1)<<8|((uint32_t)*((uint8_t*)_payload+171+2))<<16|((uint32_t)*((uint8_t*)_payload+171+3))<<24))

#define DL_AFL_COEFFS_roll_a(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_AFL_COEFFS_roll_b(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_AFL_COEFFS_roll_c(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_AFL_COEFFS_pitch_a(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_AFL_COEFFS_pitch_b(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_AFL_COEFFS_pitch_c(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))
#define DL_AFL_COEFFS_yaw_a(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+26)|*((uint8_t*)_payload+26+1)<<8|((uint32_t)*((uint8_t*)_payload+26+2))<<16|((uint32_t)*((uint8_t*)_payload+26+3))<<24); _f.f; }))
#define DL_AFL_COEFFS_yaw_b(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+30)|*((uint8_t*)_payload+30+1)<<8|((uint32_t)*((uint8_t*)_payload+30+2))<<16|((uint32_t)*((uint8_t*)_payload+30+3))<<24); _f.f; }))
#define DL_AFL_COEFFS_yaw_c(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+34)|*((uint8_t*)_payload+34+1)<<8|((uint32_t)*((uint8_t*)_payload+34+2))<<16|((uint32_t)*((uint8_t*)_payload+34+3))<<24); _f.f; }))

#define DL_BOOZ_ATT_REF_MODEL_omega_p(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_BOOZ_ATT_REF_MODEL_zeta_p(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_BOOZ_ATT_REF_MODEL_omega_q(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_BOOZ_ATT_REF_MODEL_zeta_q(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_BOOZ_ATT_REF_MODEL_omega_r(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_BOOZ_ATT_REF_MODEL_zeta_r(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))

#define DL_BOOZ2_FF_ADAP_roll(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_BOOZ2_FF_ADAP_pitch(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_BOOZ2_FF_ADAP_yaw(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))

#define DL_I2C_ERRORS_acknowledge_failure_cnt(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_I2C_ERRORS_misplaced_start_or_stop_cnt(_payload) ((uint16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_I2C_ERRORS_arbitration_lost_cnt(_payload) ((uint16_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8))
#define DL_I2C_ERRORS_overrun_or_underrun_cnt(_payload) ((uint16_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8))
#define DL_I2C_ERRORS_pec_error_in_reception_cnt(_payload) ((uint16_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8))
#define DL_I2C_ERRORS_timeout_or_tlow_error_cnt(_payload) ((uint16_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8))
#define DL_I2C_ERRORS_smbus_alert_cnt(_payload) ((uint16_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8))
#define DL_I2C_ERRORS_unexpected_event_cnt(_payload) ((uint16_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8))
#define DL_I2C_ERRORS_last_unexpected_event(_payload) ((uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24))
#define DL_I2C_ERRORS_bus_number(_payload) ((uint8_t)(*((uint8_t*)_payload+22)))

#define DL_RDYB_TRAJECTORY_commanded_phi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24); _f.f; }))
#define DL_RDYB_TRAJECTORY_commanded_theta(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8|((uint32_t)*((uint8_t*)_payload+6+2))<<16|((uint32_t)*((uint8_t*)_payload+6+3))<<24); _f.f; }))
#define DL_RDYB_TRAJECTORY_commanded_psi(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+10)|*((uint8_t*)_payload+10+1)<<8|((uint32_t)*((uint8_t*)_payload+10+2))<<16|((uint32_t)*((uint8_t*)_payload+10+3))<<24); _f.f; }))
#define DL_RDYB_TRAJECTORY_setpoint_x(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+14)|*((uint8_t*)_payload+14+1)<<8|((uint32_t)*((uint8_t*)_payload+14+2))<<16|((uint32_t)*((uint8_t*)_payload+14+3))<<24); _f.f; }))
#define DL_RDYB_TRAJECTORY_setpoint_y(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+18)|*((uint8_t*)_payload+18+1)<<8|((uint32_t)*((uint8_t*)_payload+18+2))<<16|((uint32_t)*((uint8_t*)_payload+18+3))<<24); _f.f; }))
#define DL_RDYB_TRAJECTORY_setpoint_z(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8|((uint32_t)*((uint8_t*)_payload+22+2))<<16|((uint32_t)*((uint8_t*)_payload+22+3))<<24); _f.f; }))

#define DL_HENRY_GNSS_last_imu_update(_payload) ((uint32_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8|((uint32_t)*((uint8_t*)_payload+2+2))<<16|((uint32_t)*((uint8_t*)_payload+2+3))<<24))
#define DL_HENRY_GNSS_GPS_time(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+6)|((uint64_t)*((uint8_t*)_payload+6+1))<<8|((uint64_t)*((uint8_t*)_payload+6+2))<<16|((uint64_t)*((uint8_t*)_payload+6+3))<<24|((uint64_t)*((uint8_t*)_payload+6+4))<<32|((uint64_t)*((uint8_t*)_payload+6+5))<<40|((uint64_t)*((uint8_t*)_payload+6+6))<<48|((uint64_t)*((uint8_t*)_payload+6+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_HENRY_GNSS_GPS_solution_valid(_payload) ((uint8_t)(*((uint8_t*)_payload+14)))
#define DL_HENRY_GNSS_latitude(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+15)|((uint64_t)*((uint8_t*)_payload+15+1))<<8|((uint64_t)*((uint8_t*)_payload+15+2))<<16|((uint64_t)*((uint8_t*)_payload+15+3))<<24|((uint64_t)*((uint8_t*)_payload+15+4))<<32|((uint64_t)*((uint8_t*)_payload+15+5))<<40|((uint64_t)*((uint8_t*)_payload+15+6))<<48|((uint64_t)*((uint8_t*)_payload+15+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_HENRY_GNSS_longitude(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+23)|((uint64_t)*((uint8_t*)_payload+23+1))<<8|((uint64_t)*((uint8_t*)_payload+23+2))<<16|((uint64_t)*((uint8_t*)_payload+23+3))<<24|((uint64_t)*((uint8_t*)_payload+23+4))<<32|((uint64_t)*((uint8_t*)_payload+23+5))<<40|((uint64_t)*((uint8_t*)_payload+23+6))<<48|((uint64_t)*((uint8_t*)_payload+23+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_HENRY_GNSS_altitude(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+31)|((uint64_t)*((uint8_t*)_payload+31+1))<<8|((uint64_t)*((uint8_t*)_payload+31+2))<<16|((uint64_t)*((uint8_t*)_payload+31+3))<<24|((uint64_t)*((uint8_t*)_payload+31+4))<<32|((uint64_t)*((uint8_t*)_payload+31+5))<<40|((uint64_t)*((uint8_t*)_payload+31+6))<<48|((uint64_t)*((uint8_t*)_payload+31+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_HENRY_GNSS_North(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+39)|((uint64_t)*((uint8_t*)_payload+39+1))<<8|((uint64_t)*((uint8_t*)_payload+39+2))<<16|((uint64_t)*((uint8_t*)_payload+39+3))<<24|((uint64_t)*((uint8_t*)_payload+39+4))<<32|((uint64_t)*((uint8_t*)_payload+39+5))<<40|((uint64_t)*((uint8_t*)_payload+39+6))<<48|((uint64_t)*((uint8_t*)_payload+39+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_HENRY_GNSS_East(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+47)|((uint64_t)*((uint8_t*)_payload+47+1))<<8|((uint64_t)*((uint8_t*)_payload+47+2))<<16|((uint64_t)*((uint8_t*)_payload+47+3))<<24|((uint64_t)*((uint8_t*)_payload+47+4))<<32|((uint64_t)*((uint8_t*)_payload+47+5))<<40|((uint64_t)*((uint8_t*)_payload+47+6))<<48|((uint64_t)*((uint8_t*)_payload+47+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_HENRY_GNSS_Down(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+55)|((uint64_t)*((uint8_t*)_payload+55+1))<<8|((uint64_t)*((uint8_t*)_payload+55+2))<<16|((uint64_t)*((uint8_t*)_payload+55+3))<<24|((uint64_t)*((uint8_t*)_payload+55+4))<<32|((uint64_t)*((uint8_t*)_payload+55+5))<<40|((uint64_t)*((uint8_t*)_payload+55+6))<<48|((uint64_t)*((uint8_t*)_payload+55+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_HENRY_GNSS_SVs_Tracked(_payload) ((uint8_t)(*((uint8_t*)_payload+63)))
#define DL_HENRY_GNSS_SVs_PVT(_payload) ((uint8_t)(*((uint8_t*)_payload+64)))
#define DL_HENRY_GNSS_V_North(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+65)|((uint64_t)*((uint8_t*)_payload+65+1))<<8|((uint64_t)*((uint8_t*)_payload+65+2))<<16|((uint64_t)*((uint8_t*)_payload+65+3))<<24|((uint64_t)*((uint8_t*)_payload+65+4))<<32|((uint64_t)*((uint8_t*)_payload+65+5))<<40|((uint64_t)*((uint8_t*)_payload+65+6))<<48|((uint64_t)*((uint8_t*)_payload+65+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_HENRY_GNSS_V_East(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+73)|((uint64_t)*((uint8_t*)_payload+73+1))<<8|((uint64_t)*((uint8_t*)_payload+73+2))<<16|((uint64_t)*((uint8_t*)_payload+73+3))<<24|((uint64_t)*((uint8_t*)_payload+73+4))<<32|((uint64_t)*((uint8_t*)_payload+73+5))<<40|((uint64_t)*((uint8_t*)_payload+73+6))<<48|((uint64_t)*((uint8_t*)_payload+73+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#define DL_HENRY_GNSS_V_Down(_payload) (({ union { uint64_t u; double f; } _f; _f.u = (uint64_t)(*((uint8_t*)_payload+81)|((uint64_t)*((uint8_t*)_payload+81+1))<<8|((uint64_t)*((uint8_t*)_payload+81+2))<<16|((uint64_t)*((uint8_t*)_payload+81+3))<<24|((uint64_t)*((uint8_t*)_payload+81+4))<<32|((uint64_t)*((uint8_t*)_payload+81+5))<<40|((uint64_t)*((uint8_t*)_payload+81+6))<<48|((uint64_t)*((uint8_t*)_payload+81+7))<<56); Swap32IfBigEndian(_f.u); _f.f; }))
#endif // _VAR_MESSAGES2_telemetry_H_
