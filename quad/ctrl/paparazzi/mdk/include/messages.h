/* Automatically generated from /home/iwow/work/paparazzi/paparazzi/conf/messages.xml */
/* Please DO NOT EDIT */
/* Macros to send and receive messages of class telemetry */
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
#define DOWNLINK_SEND_BOOT(_trans, _dev, version){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2)); \
	  DownlinkStartMessage(_trans, _dev, "BOOT", DL_BOOT, 0+2) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (version)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_ALIVE(_trans, _dev, nb_md5sum, md5sum){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+nb_md5sum*1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+nb_md5sum*1)); \
	  DownlinkStartMessage(_trans, _dev, "ALIVE", DL_ALIVE, 0+1+nb_md5sum*1) \
	  DownlinkPutUint8Array(_trans, _dev, nb_md5sum, md5sum); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_PONG(_trans, _dev ){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0)); \
	  DownlinkStartMessage(_trans, _dev, "PONG", DL_PONG, 0) \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_TAKEOFF(_trans, _dev, cpu_time){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2)); \
	  DownlinkStartMessage(_trans, _dev, "TAKEOFF", DL_TAKEOFF, 0+2) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (cpu_time)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_ATTITUDE(_trans, _dev, phi, psi, theta){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "ATTITUDE", DL_ATTITUDE, 0+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (phi)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (psi)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (theta)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_IR_SENSORS(_trans, _dev, ir1, ir2, longitudinal, lateral, vertical){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+2+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+2+2)); \
	  DownlinkStartMessage(_trans, _dev, "IR_SENSORS", DL_IR_SENSORS, 0+2+2+2+2+2) \
	  DownlinkPutInt16ByAddr(_trans, _dev, (ir1)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (ir2)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (longitudinal)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (lateral)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (vertical)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_GPS(_trans, _dev, mode, utm_east, utm_north, course, alt, speed, climb, week, itow, utm_zone, gps_nb_err){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+4+4+2+4+2+2+2+4+1+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+4+4+2+4+2+2+2+4+1+1)); \
	  DownlinkStartMessage(_trans, _dev, "GPS", DL_GPS, 0+1+4+4+2+4+2+2+2+4+1+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (mode)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (utm_east)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (utm_north)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (course)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (alt)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (speed)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (climb)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (week)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (itow)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (utm_zone)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (gps_nb_err)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_NAVIGATION_REF(_trans, _dev, utm_east, utm_north, utm_zone){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+1)); \
	  DownlinkStartMessage(_trans, _dev, "NAVIGATION_REF", DL_NAVIGATION_REF, 0+4+4+1) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (utm_east)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (utm_north)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (utm_zone)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_NAVIGATION(_trans, _dev, cur_block, cur_stage, pos_x, pos_y, dist2_wp, dist2_home, circle_count, oval_count){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4+4+1+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4+4+1+1)); \
	  DownlinkStartMessage(_trans, _dev, "NAVIGATION", DL_NAVIGATION, 0+1+1+4+4+4+4+1+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (cur_block)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (cur_stage)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (pos_x)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (pos_y)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (dist2_wp)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (dist2_home)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (circle_count)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (oval_count)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_PPRZ_MODE(_trans, _dev, ap_mode, ap_gaz, ap_lateral, ap_horizontal, if_calib_mode, mcu1_status){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1+1+1+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1+1+1+1)); \
	  DownlinkStartMessage(_trans, _dev, "PPRZ_MODE", DL_PPRZ_MODE, 0+1+1+1+1+1+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ap_mode)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ap_gaz)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ap_lateral)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ap_horizontal)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (if_calib_mode)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (mcu1_status)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_BAT(_trans, _dev, throttle, voltage, amps, flight_time, kill_auto_throttle, block_time, stage_time, energy){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+1+2+2+1+2+2+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+1+2+2+1+2+2+2)); \
	  DownlinkStartMessage(_trans, _dev, "BAT", DL_BAT, 0+2+1+2+2+1+2+2+2) \
	  DownlinkPutInt16ByAddr(_trans, _dev, (throttle)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (voltage)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (amps)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (flight_time)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (kill_auto_throttle)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (block_time)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (stage_time)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (energy)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_DEBUG_MCU_LINK(_trans, _dev, i2c_nb_err, i2c_mcu1_nb_err, ppm_rate){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1)); \
	  DownlinkStartMessage(_trans, _dev, "DEBUG_MCU_LINK", DL_DEBUG_MCU_LINK, 0+1+1+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (i2c_nb_err)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (i2c_mcu1_nb_err)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ppm_rate)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_CALIBRATION(_trans, _dev, climb_sum_err, climb_gaz_submode){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+1)); \
	  DownlinkStartMessage(_trans, _dev, "CALIBRATION", DL_CALIBRATION, 0+4+1) \
	  DownlinkPutFloatByAddr(_trans, _dev, (climb_sum_err)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (climb_gaz_submode)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_SETTINGS(_trans, _dev, slider_1_val, slider_2_val){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "SETTINGS", DL_SETTINGS, 0+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (slider_1_val)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (slider_2_val)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_DESIRED(_trans, _dev, roll, pitch, course, x, y, altitude, climb){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "DESIRED", DL_DESIRED, 0+4+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (roll)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (pitch)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (course)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (x)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (y)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (altitude)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (climb)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_GPS_SOL(_trans, _dev, Pacc, Sacc, PDOP, numSV){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+2+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+2+1)); \
	  DownlinkStartMessage(_trans, _dev, "GPS_SOL", DL_GPS_SOL, 0+4+4+2+1) \
	  DownlinkPutUint32ByAddr(_trans, _dev, (Pacc)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (Sacc)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (PDOP)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (numSV)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_ADC_GENERIC(_trans, _dev, val1, val2){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2)); \
	  DownlinkStartMessage(_trans, _dev, "ADC_GENERIC", DL_ADC_GENERIC, 0+2+2) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (val1)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (val2)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_TEST_FORMAT(_trans, _dev, val1, val2){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+8+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+8+4)); \
	  DownlinkStartMessage(_trans, _dev, "TEST_FORMAT", DL_TEST_FORMAT, 0+8+4) \
	  DownlinkPutDoubleByAddr(_trans, _dev, (val1)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (val2)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_CAM(_trans, _dev, phi, theta, target_x, target_y){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+2)); \
	  DownlinkStartMessage(_trans, _dev, "CAM", DL_CAM, 0+2+2+2+2) \
	  DownlinkPutInt16ByAddr(_trans, _dev, (phi)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (theta)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (target_x)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (target_y)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_CIRCLE(_trans, _dev, center_east, center_north, radius){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "CIRCLE", DL_CIRCLE, 0+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (center_east)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (center_north)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (radius)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_SEGMENT(_trans, _dev, segment_east_1, segment_north_1, segment_east_2, segment_north_2){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "SEGMENT", DL_SEGMENT, 0+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (segment_east_1)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (segment_north_1)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (segment_east_2)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (segment_north_2)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_DOWNLINK_STATUS(_trans, _dev, run_time, rx_bytes, rx_msgs, rx_err, rx_bytes_rate, rx_msgs_rate, ping_time){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "DOWNLINK_STATUS", DL_DOWNLINK_STATUS, 0+4+4+4+4+4+4+4) \
	  DownlinkPutUint32ByAddr(_trans, _dev, (run_time)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (rx_bytes)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (rx_msgs)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (rx_err)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (rx_bytes_rate)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (rx_msgs_rate)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ping_time)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_MODEM_STATUS(_trans, _dev, detected, valim, cd, nb_byte, nb_msg, nb_err){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+4+1+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+4+1+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "MODEM_STATUS", DL_MODEM_STATUS, 0+1+4+1+4+4+4) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (detected)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (valim)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (cd)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (nb_byte)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (nb_msg)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (nb_err)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_SVINFO(_trans, _dev, chn, SVID, Flags, QI, CNO, Elev, Azim){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1+1+1+1+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1+1+1+1+2)); \
	  DownlinkStartMessage(_trans, _dev, "SVINFO", DL_SVINFO, 0+1+1+1+1+1+1+2) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (chn)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (SVID)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (Flags)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (QI)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (CNO)); \
	  DownlinkPutInt8ByAddr(_trans, _dev, (Elev)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (Azim)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_DEBUG(_trans, _dev, nb_msg, msg){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+nb_msg*1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+nb_msg*1)); \
	  DownlinkStartMessage(_trans, _dev, "DEBUG", DL_DEBUG, 0+1+nb_msg*1) \
	  DownlinkPutUint8Array(_trans, _dev, nb_msg, msg); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_SURVEY(_trans, _dev, east, north, west, south){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "SURVEY", DL_SURVEY, 0+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (east)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (north)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (west)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (south)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_WC_RSSI(_trans, _dev, raw_level){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1)); \
	  DownlinkStartMessage(_trans, _dev, "WC_RSSI", DL_WC_RSSI, 0+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (raw_level)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_RANGEFINDER(_trans, _dev, range, z_dot, z_dot_sum_err, z_dot_setpoint, z_sum_err, z_setpoint, flying){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4+4+4+4+4+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4+4+4+4+4+1)); \
	  DownlinkStartMessage(_trans, _dev, "RANGEFINDER", DL_RANGEFINDER, 0+2+4+4+4+4+4+1) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (range)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (z_dot)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (z_dot_sum_err)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (z_dot_setpoint)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (z_sum_err)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (z_setpoint)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (flying)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_DOWNLINK(_trans, _dev, nb_ovrn, rate, nb_msgs){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+2+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+2+2)); \
	  DownlinkStartMessage(_trans, _dev, "DOWNLINK", DL_DOWNLINK, 0+1+2+2) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (nb_ovrn)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (rate)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (nb_msgs)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_DL_VALUE(_trans, _dev, index, value){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+4)); \
	  DownlinkStartMessage(_trans, _dev, "DL_VALUE", DL_DL_VALUE, 0+1+4) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (index)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (value)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_MARK(_trans, _dev, ac_id, lat, long){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "MARK", DL_MARK, 0+1+4+4) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (lat)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (long)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_SYS_MON(_trans, _dev, periodic_time, periodic_cycle, periodic_cycle_min, periodic_cycle_max, event_number, cpu_load){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+2+2+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+2+2+1)); \
	  DownlinkStartMessage(_trans, _dev, "SYS_MON", DL_SYS_MON, 0+2+2+2+2+2+1) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (periodic_time)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (periodic_cycle)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (periodic_cycle_min)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (periodic_cycle_max)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (event_number)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (cpu_load)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_MOTOR(_trans, _dev, rpm, current){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4)); \
	  DownlinkStartMessage(_trans, _dev, "MOTOR", DL_MOTOR, 0+2+4) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (rpm)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (current)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_WP_MOVED(_trans, _dev, wp_id, utm_east, utm_north, alt, utm_zone){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+4+4+4+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+4+4+4+1)); \
	  DownlinkStartMessage(_trans, _dev, "WP_MOVED", DL_WP_MOVED, 0+1+4+4+4+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (wp_id)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (utm_east)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (utm_north)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (alt)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (utm_zone)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_ENERGY(_trans, _dev, bat, amp, energy, power){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+2+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+2+4)); \
	  DownlinkStartMessage(_trans, _dev, "ENERGY", DL_ENERGY, 0+4+4+2+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (bat)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (amp)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (energy)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (power)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_BARO_BMP85_CALIB(_trans, _dev, a1, a2, a3, a4, a5, a6, b1, b2, mb, mc, md){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+2+2+2+2+2+2+2+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+2+2+2+2+2+2+2+2)); \
	  DownlinkStartMessage(_trans, _dev, "BARO_BMP85_CALIB", DL_BARO_BMP85_CALIB, 0+2+2+2+2+2+2+2+2+2+2+2) \
	  DownlinkPutInt16ByAddr(_trans, _dev, (a1)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (a2)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (a3)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (a4)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (a5)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (a6)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (b1)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (b2)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (mb)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (mc)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (md)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_BARO_BMP85(_trans, _dev, UT, UP, P, T, MSL){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "BARO_BMP85", DL_BARO_BMP85, 0+4+4+4+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (UT)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (UP)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (P)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (T)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (MSL)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_SPEED_LOOP(_trans, _dev, ve_set_point, ve, vn_set_point, vn, north_sp, east_sp){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "SPEED_LOOP", DL_SPEED_LOOP, 0+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (ve_set_point)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ve)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (vn_set_point)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (vn)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (north_sp)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (east_sp)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_ALT_KALMAN(_trans, _dev, p00, p01, p10, p11){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "ALT_KALMAN", DL_ALT_KALMAN, 0+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (p00)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (p01)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (p10)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (p11)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_ESTIMATOR(_trans, _dev, z, z_dot){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "ESTIMATOR", DL_ESTIMATOR, 0+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (z)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (z_dot)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_TUNE_ROLL(_trans, _dev, p, phi, phi_sp){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "TUNE_ROLL", DL_TUNE_ROLL, 0+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (p)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (phi)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (phi_sp)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_BARO_MS5534A(_trans, _dev, pressure, temp, alt){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+2+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+2+4)); \
	  DownlinkStartMessage(_trans, _dev, "BARO_MS5534A", DL_BARO_MS5534A, 0+4+2+4) \
	  DownlinkPutUint32ByAddr(_trans, _dev, (pressure)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (temp)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (alt)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_PRESSURE(_trans, _dev, airspeed_adc, airspeed, altitude_adc, altitude){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "PRESSURE", DL_PRESSURE, 0+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (airspeed_adc)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (airspeed)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (altitude_adc)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (altitude)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_BARO_WORDS(_trans, _dev, w1, w2, w3, w4){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+2)); \
	  DownlinkStartMessage(_trans, _dev, "BARO_WORDS", DL_BARO_WORDS, 0+2+2+2+2) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (w1)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (w2)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (w3)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (w4)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_WP_MOVED_LLA(_trans, _dev, wp_id, lat, lon, alt){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "WP_MOVED_LLA", DL_WP_MOVED_LLA, 0+1+4+4+4) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (wp_id)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (lat)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (lon)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (alt)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_CHRONO(_trans, _dev, tag, time){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+4)); \
	  DownlinkStartMessage(_trans, _dev, "CHRONO", DL_CHRONO, 0+1+4) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (tag)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (time)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_WP_MOVED_ENU(_trans, _dev, wp_id, east, north, up){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "WP_MOVED_ENU", DL_WP_MOVED_ENU, 0+1+4+4+4) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (wp_id)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (east)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (north)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (up)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_WINDTURBINE_STATUS_(_trans, _dev, ac_id, tb_id, sync_itow, cycle_time){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "WINDTURBINE_STATUS_", DL_WINDTURBINE_STATUS_, 0+1+1+4+4) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (tb_id)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (sync_itow)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (cycle_time)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_RC_3CH_(_trans, _dev, throttle_mode, roll, pitch){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1)); \
	  DownlinkStartMessage(_trans, _dev, "RC_3CH_", DL_RC_3CH_, 0+1+1+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (throttle_mode)); \
	  DownlinkPutInt8ByAddr(_trans, _dev, (roll)); \
	  DownlinkPutInt8ByAddr(_trans, _dev, (pitch)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_MPPT(_trans, _dev, nb_values, values){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+nb_values*2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+nb_values*2)); \
	  DownlinkStartMessage(_trans, _dev, "MPPT", DL_MPPT, 0+1+nb_values*2) \
	  DownlinkPutInt16Array(_trans, _dev, nb_values, values); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_DEBUG_IR_I2C(_trans, _dev, ir1, ir2, top){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2)); \
	  DownlinkStartMessage(_trans, _dev, "DEBUG_IR_I2C", DL_DEBUG_IR_I2C, 0+2+2+2) \
	  DownlinkPutInt16ByAddr(_trans, _dev, (ir1)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (ir2)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (top)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_AIRSPEED(_trans, _dev, airspeed, airspeed_sp, airspeed_cnt, groundspeed_sp){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "AIRSPEED", DL_AIRSPEED, 0+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (airspeed)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (airspeed_sp)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (airspeed_cnt)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (groundspeed_sp)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_XSENS(_trans, _dev, counter, p, q, r, phi, theta, psi, ax, ay, az, vx, vy, vz, lat, lon, alt, status, hour, min, sec, nanosec, year, month, day){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+1+1+1+1+4+2+1+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+1+1+1+1+4+2+1+1)); \
	  DownlinkStartMessage(_trans, _dev, "XSENS", DL_XSENS, 0+2+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+1+1+1+1+4+2+1+1) \
	  DownlinkPutInt16ByAddr(_trans, _dev, (counter)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (p)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (q)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (r)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (phi)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (theta)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (psi)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ax)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ay)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (az)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (vx)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (vy)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (vz)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (lat)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (lon)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (alt)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (status)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (hour)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (min)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (sec)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (nanosec)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (year)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (month)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (day)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_BARO_ETS(_trans, _dev, adc, offset, scaled){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+4)); \
	  DownlinkStartMessage(_trans, _dev, "BARO_ETS", DL_BARO_ETS, 0+2+2+4) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (adc)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (offset)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (scaled)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_AIRSPEED_ETS(_trans, _dev, adc, offset, scaled){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+4)); \
	  DownlinkStartMessage(_trans, _dev, "AIRSPEED_ETS", DL_AIRSPEED_ETS, 0+2+2+4) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (adc)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (offset)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (scaled)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_PBN(_trans, _dev, airspeed_adc, altitude_adc, airspeed, altitude, airspeed_offset, altitude_offset){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+4+4+2+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+4+4+2+2)); \
	  DownlinkStartMessage(_trans, _dev, "PBN", DL_PBN, 0+2+2+4+4+2+2) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (airspeed_adc)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (altitude_adc)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (airspeed)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (altitude)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (airspeed_offset)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (altitude_offset)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_GPS_LLA(_trans, _dev, lat, lon, alt, course, speed, climb, week, itow, mode, gps_nb_err){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+2+2+2+2+4+1+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+2+2+2+2+4+1+1)); \
	  DownlinkStartMessage(_trans, _dev, "GPS_LLA", DL_GPS_LLA, 0+4+4+4+2+2+2+2+4+1+1) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (lat)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (lon)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (alt)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (course)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (speed)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (climb)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (week)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (itow)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (mode)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (gps_nb_err)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_H_CTL_A(_trans, _dev, roll_sum_err, ref_roll_angle, pitch_sum_err, ref_pitch_angle){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "H_CTL_A", DL_H_CTL_A, 0+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (roll_sum_err)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ref_roll_angle)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (pitch_sum_err)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ref_pitch_angle)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_TURB_PRESSURE_RAW(_trans, _dev, ch_0, ch_1, ch_2, ch_3, ch_4, ch_5, ch_6, ch_7, ch_8, ch_9, ch_10, ch_11, ch_12, ch_13, ch_14, ch_15){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "TURB_PRESSURE_RAW", DL_TURB_PRESSURE_RAW, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ch_0)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ch_1)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ch_2)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ch_3)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ch_4)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ch_5)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ch_6)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ch_7)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ch_8)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ch_9)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ch_10)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ch_11)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ch_12)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ch_13)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ch_14)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ch_15)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_TURB_PRESSURE_VOLTAGE(_trans, _dev, ch_1_p, ch_1_t, ch_2_p, ch_2_t, ch_3_p, ch_3_t, ch_4_p, ch_4_t, ch_5_p, ch_5_t, ch_6_p, ch_6_t, ch_7_p, ch_7_t, gnd1, gnd2){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "TURB_PRESSURE_VOLTAGE", DL_TURB_PRESSURE_VOLTAGE, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (ch_1_p)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ch_1_t)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ch_2_p)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ch_2_t)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ch_3_p)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ch_3_t)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ch_4_p)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ch_4_t)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ch_5_p)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ch_5_t)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ch_6_p)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ch_6_t)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ch_7_p)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ch_7_t)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (gnd1)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (gnd2)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_CAM_POINT(_trans, _dev, cam_point_distance_from_home, cam_point_lat, cam_point_lon){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "CAM_POINT", DL_CAM_POINT, 0+2+4+4) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (cam_point_distance_from_home)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (cam_point_lat)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (cam_point_lon)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_DC_INFO(_trans, _dev, mode, utm_east, utm_north, course, buffer, dist, next_dist, start_x, start_y, start_angle, angle, last_block, count, shutter){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4+4+4+1+4+4+4+4+4+4+4+2+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4+4+4+1+4+4+4+4+4+4+4+2+1)); \
	  DownlinkStartMessage(_trans, _dev, "DC_INFO", DL_DC_INFO, 0+2+4+4+4+1+4+4+4+4+4+4+4+2+1) \
	  DownlinkPutInt16ByAddr(_trans, _dev, (mode)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (utm_east)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (utm_north)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (course)); \
	  DownlinkPutInt8ByAddr(_trans, _dev, (buffer)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (dist)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (next_dist)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (start_x)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (start_y)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (start_angle)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (angle)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (last_block)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (count)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (shutter)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_AMSYS_BARO(_trans, _dev, pBaroRaw, pBaro, pHomePressure, AltOffset, aktuell, Over_Ground, tempBaro){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "AMSYS_BARO", DL_AMSYS_BARO, 0+2+4+4+4+4+4+4) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (pBaroRaw)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (pBaro)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (pHomePressure)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (AltOffset)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (aktuell)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (Over_Ground)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (tempBaro)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_AMSYS_AIRSPEED(_trans, _dev, asRaw, asPresure, asAirspeed, asAirsFilt, asTemp){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "AMSYS_AIRSPEED", DL_AMSYS_AIRSPEED, 0+2+4+4+4+4) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (asRaw)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (asPresure)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (asAirspeed)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (asAirsFilt)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (asTemp)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_FLIGHT_BENCHMARK(_trans, _dev, SE_As, SE_Alt, SE_Pos, Err_As, Err_Alt, Err_Pos){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "FLIGHT_BENCHMARK", DL_FLIGHT_BENCHMARK, 0+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (SE_As)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (SE_Alt)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (SE_Pos)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (Err_As)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (Err_Alt)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (Err_Pos)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_AOA_adc(_trans, _dev, adcVal, AOA){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4)); \
	  DownlinkStartMessage(_trans, _dev, "AOA_adc", DL_AOA_adc, 0+2+4) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (adcVal)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (AOA)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_XTEND_RSSI(_trans, _dev, datalink_time, rssi_fade_margin, duty){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+1+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+1+1)); \
	  DownlinkStartMessage(_trans, _dev, "XTEND_RSSI", DL_XTEND_RSSI, 0+2+1+1) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (datalink_time)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (rssi_fade_margin)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (duty)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_VF_UPDATE(_trans, _dev, baro, range_meter){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "VF_UPDATE", DL_VF_UPDATE, 0+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (baro)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (range_meter)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_VF_PREDICT(_trans, _dev, accel){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4)); \
	  DownlinkStartMessage(_trans, _dev, "VF_PREDICT", DL_VF_PREDICT, 0+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (accel)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_CROSS_TRACK_ERROR(_trans, _dev, cross_track_error, cte_int){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "CROSS_TRACK_ERROR", DL_CROSS_TRACK_ERROR, 0+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (cross_track_error)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (cte_int)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_GENERIC_COM(_trans, _dev, lat, lon, alt, gspeed, course, airspeed, vsupply, energy, throttle, ap_mode, nav_block, flight_time){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+2+2+2+2+1+1+1+1+1+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+2+2+2+2+1+1+1+1+1+2)); \
	  DownlinkStartMessage(_trans, _dev, "GENERIC_COM", DL_GENERIC_COM, 0+4+4+2+2+2+2+1+1+1+1+1+2) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (lat)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (lon)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (alt)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (gspeed)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (course)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (airspeed)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (vsupply)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (energy)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (throttle)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ap_mode)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (nav_block)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (flight_time)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_FORMATION_SLOT_TM(_trans, _dev, ac_id, mode, slot_east, slot_north, slot_alt){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "FORMATION_SLOT_TM", DL_FORMATION_SLOT_TM, 0+1+1+4+4+4) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (mode)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (slot_east)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (slot_north)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (slot_alt)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_FORMATION_STATUS_TM(_trans, _dev, ac_id, leader_id, status){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1)); \
	  DownlinkStartMessage(_trans, _dev, "FORMATION_STATUS_TM", DL_FORMATION_STATUS_TM, 0+1+1+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (leader_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (status)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_BMP_STATUS(_trans, _dev, UP, UT, press, temp){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "BMP_STATUS", DL_BMP_STATUS, 0+4+4+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (UP)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (UT)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (press)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (temp)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_MLX_STATUS(_trans, _dev, itemp_case, temp_case, itemp_obj, temp_obj){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4+2+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4+2+4)); \
	  DownlinkStartMessage(_trans, _dev, "MLX_STATUS", DL_MLX_STATUS, 0+2+4+2+4) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (itemp_case)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (temp_case)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (itemp_obj)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (temp_obj)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_TMP_STATUS(_trans, _dev, itemp, temp){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4)); \
	  DownlinkStartMessage(_trans, _dev, "TMP_STATUS", DL_TMP_STATUS, 0+2+4) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (itemp)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (temp)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_WIND_INFO_RET(_trans, _dev, east, north, airspeed){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "WIND_INFO_RET", DL_WIND_INFO_RET, 0+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (east)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (north)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (airspeed)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_SCP_STATUS(_trans, _dev, press, temp){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+2)); \
	  DownlinkStartMessage(_trans, _dev, "SCP_STATUS", DL_SCP_STATUS, 0+4+2) \
	  DownlinkPutUint32ByAddr(_trans, _dev, (press)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (temp)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_SHT_STATUS(_trans, _dev, ihumid, itemp, humid, temp){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "SHT_STATUS", DL_SHT_STATUS, 0+2+2+4+4) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (ihumid)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (itemp)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (humid)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (temp)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_ENOSE_STATUS(_trans, _dev, val1, val2, val3, PID, nb_heat, heat){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+2+1+nb_heat*1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+2+1+nb_heat*1)); \
	  DownlinkStartMessage(_trans, _dev, "ENOSE_STATUS", DL_ENOSE_STATUS, 0+2+2+2+2+1+nb_heat*1) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (val1)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (val2)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (val3)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (PID)); \
	  DownlinkPutUint8Array(_trans, _dev, nb_heat, heat); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_DPICCO_STATUS(_trans, _dev, humid, temp, fhumid, ftemp){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "DPICCO_STATUS", DL_DPICCO_STATUS, 0+2+2+4+4) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (humid)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (temp)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (fhumid)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ftemp)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_ANTENNA_DEBUG(_trans, _dev, mag_xraw, mag_yraw, mag_xcal, mag_ycal, mag_heading, mag_magnitude, mag_temp, mag_distor, mag_cal_status){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+1+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+1+1)); \
	  DownlinkStartMessage(_trans, _dev, "ANTENNA_DEBUG", DL_ANTENNA_DEBUG, 0+4+4+4+4+4+4+4+1+1) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (mag_xraw)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (mag_yraw)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (mag_xcal)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (mag_ycal)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (mag_heading)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (mag_magnitude)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (mag_temp)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (mag_distor)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (mag_cal_status)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_ANTENNA_STATUS(_trans, _dev, azim_sp, elev_sp, id_sp, mode){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+1+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+1+1)); \
	  DownlinkStartMessage(_trans, _dev, "ANTENNA_STATUS", DL_ANTENNA_STATUS, 0+4+4+1+1) \
	  DownlinkPutFloatByAddr(_trans, _dev, (azim_sp)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (elev_sp)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (id_sp)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (mode)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_MOTOR_BENCH_STATUS(_trans, _dev, time_ticks, throttle, rpm, current, thrust, torque, time_s, mode){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+2+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+2+1)); \
	  DownlinkStartMessage(_trans, _dev, "MOTOR_BENCH_STATUS", DL_MOTOR_BENCH_STATUS, 0+4+4+4+4+4+4+2+1) \
	  DownlinkPutUint32ByAddr(_trans, _dev, (time_ticks)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (throttle)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (rpm)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (current)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (thrust)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (torque)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (time_s)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (mode)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_MOTOR_BENCH_STATIC(_trans, _dev, av_rpm, av_thrust, av_current, throttle){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+2)); \
	  DownlinkStartMessage(_trans, _dev, "MOTOR_BENCH_STATIC", DL_MOTOR_BENCH_STATIC, 0+4+4+4+2) \
	  DownlinkPutFloatByAddr(_trans, _dev, (av_rpm)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (av_thrust)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (av_current)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (throttle)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_HIH_STATUS(_trans, _dev, humid, fhumid, ftemp){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "HIH_STATUS", DL_HIH_STATUS, 0+2+4+4) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (humid)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (fhumid)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ftemp)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_TEMT_STATUS(_trans, _dev, light, f_light){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4)); \
	  DownlinkStartMessage(_trans, _dev, "TEMT_STATUS", DL_TEMT_STATUS, 0+2+4) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (light)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (f_light)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_GP2Y_STATUS(_trans, _dev, idensity, density){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4)); \
	  DownlinkStartMessage(_trans, _dev, "GP2Y_STATUS", DL_GP2Y_STATUS, 0+2+4) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (idensity)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (density)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_SHT_I2C_SERIAL(_trans, _dev, serial0, serial1){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "SHT_I2C_SERIAL", DL_SHT_I2C_SERIAL, 0+4+4) \
	  DownlinkPutUint32ByAddr(_trans, _dev, (serial0)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (serial1)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_PPM(_trans, _dev, ppm_rate, nb_values, values){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+nb_values*2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+nb_values*2)); \
	  DownlinkStartMessage(_trans, _dev, "PPM", DL_PPM, 0+1+1+nb_values*2) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ppm_rate)); \
	  DownlinkPutUint16Array(_trans, _dev, nb_values, values); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_RC(_trans, _dev, nb_values, values){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+nb_values*2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+nb_values*2)); \
	  DownlinkStartMessage(_trans, _dev, "RC", DL_RC, 0+1+nb_values*2) \
	  DownlinkPutInt16Array(_trans, _dev, nb_values, values); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_COMMANDS(_trans, _dev, nb_values, values){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+nb_values*2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+nb_values*2)); \
	  DownlinkStartMessage(_trans, _dev, "COMMANDS", DL_COMMANDS, 0+1+nb_values*2) \
	  DownlinkPutInt16Array(_trans, _dev, nb_values, values); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_FBW_STATUS(_trans, _dev, rc_status, frame_rate, mode, vsupply, current){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1+1+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1+1+4)); \
	  DownlinkStartMessage(_trans, _dev, "FBW_STATUS", DL_FBW_STATUS, 0+1+1+1+1+4) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (rc_status)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (frame_rate)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (mode)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (vsupply)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (current)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_ADC(_trans, _dev, mcu, nb_values, values){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+nb_values*2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+nb_values*2)); \
	  DownlinkStartMessage(_trans, _dev, "ADC", DL_ADC, 0+1+1+nb_values*2) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (mcu)); \
	  DownlinkPutUint16Array(_trans, _dev, nb_values, values); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_ACTUATORS(_trans, _dev, nb_values, values){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+nb_values*2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+nb_values*2)); \
	  DownlinkStartMessage(_trans, _dev, "ACTUATORS", DL_ACTUATORS, 0+1+nb_values*2) \
	  DownlinkPutUint16Array(_trans, _dev, nb_values, values); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_BETH(_trans, _dev, azimuth, elevation, tilt, counter, can_errs, spi_errs, thrust_out, pitch_out){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+4+2+2+1+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+4+2+2+1+1)); \
	  DownlinkStartMessage(_trans, _dev, "BETH", DL_BETH, 0+2+2+2+4+2+2+1+1) \
	  DownlinkPutInt16ByAddr(_trans, _dev, (azimuth)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (elevation)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (tilt)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (counter)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (can_errs)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (spi_errs)); \
	  DownlinkPutInt8ByAddr(_trans, _dev, (thrust_out)); \
	  DownlinkPutInt8ByAddr(_trans, _dev, (pitch_out)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_BETH_ESTIMATOR(_trans, _dev, tilt, tilt_dot, elevation, elevation_dot, azimuth, azimuth_dot){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "BETH_ESTIMATOR", DL_BETH_ESTIMATOR, 0+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (tilt)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (tilt_dot)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (elevation)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (elevation_dot)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (azimuth)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (azimuth_dot)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_BETH_CONTROLLER(_trans, _dev, pitch, thrust, pitch_ff, pitch_fb, thrust_ff, thrust_fb, tilt_sp, tilt_ref, tilt_dot_ref, elevation_sp , elevation_ref , elevation_dot_ref, azimuth_sp){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "BETH_CONTROLLER", DL_BETH_CONTROLLER, 0+4+4+4+4+4+4+4+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (pitch)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (thrust)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (pitch_ff)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (pitch_fb)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (thrust_ff)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (thrust_fb)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (tilt_sp)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (tilt_ref)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (tilt_dot_ref)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (elevation_sp )); \
	  DownlinkPutFloatByAddr(_trans, _dev, (elevation_ref )); \
	  DownlinkPutFloatByAddr(_trans, _dev, (elevation_dot_ref)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (azimuth_sp)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_BETH_CONTROLLER_TWIST(_trans, _dev, S, S_dot, U_twt, error){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "BETH_CONTROLLER_TWIST", DL_BETH_CONTROLLER_TWIST, 0+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (S)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (S_dot)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (U_twt)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (error)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_DC_SHOT(_trans, _dev, photo_nr, utm_east, utm_north, z, utm_zone, phi, theta, course, speed, itow){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4+4+4+1+2+2+2+2+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4+4+4+1+2+2+2+2+4)); \
	  DownlinkStartMessage(_trans, _dev, "DC_SHOT", DL_DC_SHOT, 0+2+4+4+4+1+2+2+2+2+4) \
	  DownlinkPutInt16ByAddr(_trans, _dev, (photo_nr)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (utm_east)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (utm_north)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (z)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (utm_zone)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (phi)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (theta)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (course)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (speed)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (itow)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_TEST_BOARD_RESULTS(_trans, _dev, uart, ppm, nb_servo, servo){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1+nb_servo*2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+1+nb_servo*2)); \
	  DownlinkStartMessage(_trans, _dev, "TEST_BOARD_RESULTS", DL_TEST_BOARD_RESULTS, 0+1+1+1+nb_servo*2) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (uart)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ppm)); \
	  DownlinkPutUint16Array(_trans, _dev, nb_servo, servo); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_BETH_CONTROLLER_SFB(_trans, _dev, one){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4)); \
	  DownlinkStartMessage(_trans, _dev, "BETH_CONTROLLER_SFB", DL_BETH_CONTROLLER_SFB, 0+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (one)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_MLX_SERIAL(_trans, _dev, serial0, serial1){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "MLX_SERIAL", DL_MLX_SERIAL, 0+4+4) \
	  DownlinkPutUint32ByAddr(_trans, _dev, (serial0)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (serial1)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_PAYLOAD(_trans, _dev, nb_values, values){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+nb_values*1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+nb_values*1)); \
	  DownlinkStartMessage(_trans, _dev, "PAYLOAD", DL_PAYLOAD, 0+1+nb_values*1) \
	  DownlinkPutUint8Array(_trans, _dev, nb_values, values); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_HTM_STATUS(_trans, _dev, ihumid, itemp, humid, temp){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "HTM_STATUS", DL_HTM_STATUS, 0+2+2+4+4) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (ihumid)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (itemp)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (humid)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (temp)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_BARO_MS5611(_trans, _dev, d1, d2, pressure, temp){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "BARO_MS5611", DL_BARO_MS5611, 0+4+4+4+4) \
	  DownlinkPutUint32ByAddr(_trans, _dev, (d1)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (d2)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (pressure)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (temp)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_MS5611_COEFF(_trans, _dev, c0, c1, c2, c3, c4, c5, c6, c7){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+2+2+2+2+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+2+2+2+2+2)); \
	  DownlinkStartMessage(_trans, _dev, "MS5611_COEFF", DL_MS5611_COEFF, 0+2+2+2+2+2+2+2+2) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (c0)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (c1)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (c2)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (c3)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (c4)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (c5)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (c6)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (c7)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_ATMOSPHERE_CHARGE(_trans, _dev, t0, t1, t2, t3, t4, t5, t6, t7, t8, t9){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+2+2+2+2+2+2+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+2+2+2+2+2+2+2)); \
	  DownlinkStartMessage(_trans, _dev, "ATMOSPHERE_CHARGE", DL_ATMOSPHERE_CHARGE, 0+2+2+2+2+2+2+2+2+2+2) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (t0)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (t1)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (t2)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (t3)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (t4)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (t5)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (t6)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (t7)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (t8)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (t9)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_SOLAR_RADIATION(_trans, _dev, up_t0, dn_t0, up_t1, dn_t1, up_t2, dn_t2, up_t3, dn_t3, up_t4, dn_t4, up_t5, dn_t5, up_t6, dn_t6, up_t7, dn_t7, up_t8, dn_t8, up_t9, dn_t9){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2)); \
	  DownlinkStartMessage(_trans, _dev, "SOLAR_RADIATION", DL_SOLAR_RADIATION, 0+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2+2) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (up_t0)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (dn_t0)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (up_t1)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (dn_t1)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (up_t2)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (dn_t2)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (up_t3)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (dn_t3)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (up_t4)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (dn_t4)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (up_t5)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (dn_t5)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (up_t6)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (dn_t6)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (up_t7)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (dn_t7)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (up_t8)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (dn_t8)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (up_t9)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (dn_t9)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_TCAS_TA(_trans, _dev, ac_id){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1)); \
	  DownlinkStartMessage(_trans, _dev, "TCAS_TA", DL_TCAS_TA, 0+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_TCAS_RA(_trans, _dev, ac_id, resolve){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1)); \
	  DownlinkStartMessage(_trans, _dev, "TCAS_RA", DL_TCAS_RA, 0+1+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (resolve)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_TCAS_RESOLVED(_trans, _dev, ac_id){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1)); \
	  DownlinkStartMessage(_trans, _dev, "TCAS_RESOLVED", DL_TCAS_RESOLVED, 0+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_TCAS_DEBUG(_trans, _dev, ac_id, tau){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+4)); \
	  DownlinkStartMessage(_trans, _dev, "TCAS_DEBUG", DL_TCAS_DEBUG, 0+1+4) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ac_id)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (tau)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_POTENTIAL(_trans, _dev, east, north, alt, speed, climb){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "POTENTIAL", DL_POTENTIAL, 0+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (east)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (north)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (alt)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (speed)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (climb)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_VERTICAL_ENERGY(_trans, _dev, Epot_err, Ekin_err, Etot_err, Edis_err, throttle, nav_pitch, speed_sp){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "VERTICAL_ENERGY", DL_VERTICAL_ENERGY, 0+4+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (Epot_err)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (Ekin_err)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (Etot_err)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (Edis_err)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (throttle)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (nav_pitch)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (speed_sp)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_TEMP_TCOUPLE(_trans, _dev, fval0, fval1, fval2, fval3, fref0, fref1, fref2, fref3, val0, val1, val2, val3, ref0, ref1, ref2, ref3){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+2+2+2+2+2+2+2+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+2+2+2+2+2+2+2+2)); \
	  DownlinkStartMessage(_trans, _dev, "TEMP_TCOUPLE", DL_TEMP_TCOUPLE, 0+4+4+4+4+4+4+4+4+2+2+2+2+2+2+2+2) \
	  DownlinkPutFloatByAddr(_trans, _dev, (fval0)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (fval1)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (fval2)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (fval3)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (fref0)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (fref1)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (fref2)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (fref3)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (val0)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (val1)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (val2)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (val3)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (ref0)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (ref1)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (ref2)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (ref3)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_SHT_I2C_STATUS(_trans, _dev, ihumid, itemp, humid, temp){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "SHT_I2C_STATUS", DL_SHT_I2C_STATUS, 0+2+2+4+4) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (ihumid)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (itemp)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (humid)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (temp)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_CAMERA_SNAPSHOT(_trans, _dev, snapshot_image_number){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2)); \
	  DownlinkStartMessage(_trans, _dev, "CAMERA_SNAPSHOT", DL_CAMERA_SNAPSHOT, 0+2) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (snapshot_image_number)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_TIMESTAMP(_trans, _dev, timestamp){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4)); \
	  DownlinkStartMessage(_trans, _dev, "TIMESTAMP", DL_TIMESTAMP, 0+4) \
	  DownlinkPutUint32ByAddr(_trans, _dev, (timestamp)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_STAB_ATTITUDE_FLOAT(_trans, _dev, est_p, est_q, est_r, est_phi, est_theta, est_psi, ref_phi, ref_theta, ref_psi, sum_err_phi, sum_err_theta, sum_err_psi, delta_a_fb, delta_e_fb, delta_r_fb, delta_a_ff, delta_e_ff, delta_r_ff, delta_a, delta_e, delta_r, est_p_d, est_q_d, est_r_d){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "STAB_ATTITUDE_FLOAT", DL_STAB_ATTITUDE_FLOAT, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (est_p)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (est_q)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (est_r)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (est_phi)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (est_theta)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (est_psi)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ref_phi)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ref_theta)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ref_psi)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (sum_err_phi)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (sum_err_theta)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (sum_err_psi)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (delta_a_fb)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (delta_e_fb)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (delta_r_fb)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (delta_a_ff)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (delta_e_ff)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (delta_r_ff)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (delta_a)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (delta_e)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (delta_r)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (est_p_d)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (est_q_d)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (est_r_d)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_IMU_GYRO_SCALED(_trans, _dev, gp, gq, gr){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "IMU_GYRO_SCALED", DL_IMU_GYRO_SCALED, 0+4+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (gp)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (gq)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (gr)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_IMU_ACCEL_SCALED(_trans, _dev, ax, ay, az){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "IMU_ACCEL_SCALED", DL_IMU_ACCEL_SCALED, 0+4+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ax)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ay)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (az)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_IMU_MAG_SCALED(_trans, _dev, mx, my, mz){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "IMU_MAG_SCALED", DL_IMU_MAG_SCALED, 0+4+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (mx)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (my)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (mz)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_FILTER(_trans, _dev, phi, theta, psi, measure_phi, measure_theta, measure_psi, corrected_phi, corrected_theta, corrected_psi, correction_phi, correction_theta, correction_psi, bp, bq, br){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "FILTER", DL_FILTER, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (phi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (theta)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (psi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (measure_phi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (measure_theta)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (measure_psi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (corrected_phi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (corrected_theta)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (corrected_psi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (correction_phi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (correction_theta)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (correction_psi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (bp)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (bq)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (br)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_FILTER2(_trans, _dev, px, py, pz, gsx, gsy, gsz){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "FILTER2", DL_FILTER2, 0+4+4+4+4+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (px)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (py)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (pz)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (gsx)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (gsy)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (gsz)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_RATE_LOOP(_trans, _dev, sp_p, sp_q, sp_r, ref_p, ref_q, ref_r, refdot_p, refdot_q, refdot_r, sumerr_p, sumerr_q, sumerr_r, ff_p, ff_q, ff_r, fb_p, fb_q, fb_r, delta_t){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "RATE_LOOP", DL_RATE_LOOP, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (sp_p)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (sp_q)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (sp_r)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ref_p)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ref_q)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ref_r)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (refdot_p)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (refdot_q)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (refdot_r)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (sumerr_p)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (sumerr_q)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (sumerr_r)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ff_p)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ff_q)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ff_r)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (fb_p)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (fb_q)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (fb_r)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (delta_t)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_FILTER_ALIGNER(_trans, _dev, lp_gp, lp_gq, lp_gr, gp, gq, gr, noise, cnt, status){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+1)); \
	  DownlinkStartMessage(_trans, _dev, "FILTER_ALIGNER", DL_FILTER_ALIGNER, 0+4+4+4+4+4+4+4+4+1) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (lp_gp)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (lp_gq)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (lp_gr)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (gp)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (gq)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (gr)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (noise)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (cnt)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (status)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_FILTER_COR(_trans, _dev, mphi, mtheta, mpsi, qi, qx, qy, qz){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "FILTER_COR", DL_FILTER_COR, 0+4+4+4+4+4+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (mphi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (mtheta)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (mpsi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (qi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (qx)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (qy)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (qz)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_STAB_ATTITUDE_INT(_trans, _dev, est_p, est_q, est_r, est_phi, est_theta, est_psi, sp_phi, sp_theta, sp_psi, sum_err_phi, sum_err_theta, sum_err_psi, delta_a_fb, delta_e_fb, delta_r_fb, delta_a_ff, delta_e_ff, delta_r_ff, delta_a, delta_e, delta_r){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "STAB_ATTITUDE_INT", DL_STAB_ATTITUDE_INT, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (est_p)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (est_q)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (est_r)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (est_phi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (est_theta)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (est_psi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (sp_phi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (sp_theta)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (sp_psi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (sum_err_phi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (sum_err_theta)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (sum_err_psi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (delta_a_fb)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (delta_e_fb)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (delta_r_fb)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (delta_a_ff)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (delta_e_ff)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (delta_r_ff)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (delta_a)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (delta_e)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (delta_r)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_STAB_ATTITUDE_REF_INT(_trans, _dev, sp_phi, sp_theta, sp_psi, ref_phi, ref_theta, ref_psi, ref_p, ref_q, ref_r, ref_pd, ref_qd, ref_rd){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "STAB_ATTITUDE_REF_INT", DL_STAB_ATTITUDE_REF_INT, 0+4+4+4+4+4+4+4+4+4+4+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (sp_phi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (sp_theta)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (sp_psi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ref_phi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ref_theta)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ref_psi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ref_p)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ref_q)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ref_r)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ref_pd)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ref_qd)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ref_rd)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_STAB_ATTITUDE_REF_FLOAT(_trans, _dev, sp_phi, sp_theta, sp_psi, ref_phi, ref_theta, ref_psi, ref_p, ref_q, ref_r, ref_pd, ref_qd, ref_rd){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "STAB_ATTITUDE_REF_FLOAT", DL_STAB_ATTITUDE_REF_FLOAT, 0+4+4+4+4+4+4+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (sp_phi)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (sp_theta)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (sp_psi)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ref_phi)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ref_theta)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ref_psi)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ref_p)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ref_q)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ref_r)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ref_pd)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ref_qd)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ref_rd)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_ROTORCRAFT_CMD(_trans, _dev, cmd_roll, cmd_pitch, cmd_yaw, cmd_thrust){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "ROTORCRAFT_CMD", DL_ROTORCRAFT_CMD, 0+4+4+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (cmd_roll)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (cmd_pitch)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (cmd_yaw)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (cmd_thrust)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_GUIDANCE(_trans, _dev, pos_n, pos_e, sp_pos_n, sp_pos_e){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "GUIDANCE", DL_GUIDANCE, 0+4+4+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (pos_n)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (pos_e)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (sp_pos_n)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (sp_pos_e)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_VERT_LOOP(_trans, _dev, z_sp, zd_sp, est_z, est_zd, est_zdd, ref_z, ref_zd, ref_zdd, adp_inv_m, adp_cov, adp_meas, sum_err, ff_cmd, fb_cmd, delta_t){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "VERT_LOOP", DL_VERT_LOOP, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (z_sp)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (zd_sp)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (est_z)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (est_zd)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (est_zdd)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ref_z)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ref_zd)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ref_zdd)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (adp_inv_m)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (adp_cov)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (adp_meas)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (sum_err)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ff_cmd)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (fb_cmd)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (delta_t)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_HOVER_LOOP(_trans, _dev, sp_x, sp_y, est_x, est_y, est_xd, est_yd, est_xdd, est_ydd, err_x, err_y, err_xd, err_yd, err_sum_x, err_sum_y, err_nav_x, err_nav_y, cmd_x, cmd_y, cmd_phi, cmd_theta, cmd_psi){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "HOVER_LOOP", DL_HOVER_LOOP, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (sp_x)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (sp_y)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (est_x)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (est_y)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (est_xd)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (est_yd)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (est_xdd)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (est_ydd)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (err_x)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (err_y)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (err_xd)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (err_yd)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (err_sum_x)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (err_sum_y)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (err_nav_x)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (err_nav_y)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (cmd_x)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (cmd_y)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (cmd_phi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (cmd_theta)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (cmd_psi)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_ROTORCRAFT_FP(_trans, _dev, east, north, up, veast, vnorth, vup, phi, theta, psi, carrot_east, carrot_north, carrot_up, carrot_psi, thrust, flight_time){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+2)); \
	  DownlinkStartMessage(_trans, _dev, "ROTORCRAFT_FP", DL_ROTORCRAFT_FP, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+2) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (east)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (north)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (up)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (veast)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (vnorth)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (vup)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (phi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (theta)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (psi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (carrot_east)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (carrot_north)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (carrot_up)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (carrot_psi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (thrust)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (flight_time)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_BOOZ2_FMS_INFO(_trans, _dev, tbd){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4)); \
	  DownlinkStartMessage(_trans, _dev, "BOOZ2_FMS_INFO", DL_BOOZ2_FMS_INFO, 0+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (tbd)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_GUIDANCE_H_REF_INT(_trans, _dev, sp_x, ref_x, ref_xd, ref_xdd, sp_y, ref_y, ref_yd, ref_ydd){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "GUIDANCE_H_REF_INT", DL_GUIDANCE_H_REF_INT, 0+4+4+4+4+4+4+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (sp_x)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ref_x)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ref_xd)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ref_xdd)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (sp_y)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ref_y)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ref_yd)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ref_ydd)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_ROTORCRAFT_TUNE_HOVER(_trans, _dev, rc_roll, rc_pitch, rc_yaw, cmd_roll, cmd_pitch, cmd_yaw, cmd_thrust, imu_phi, imu_theta, imu_psi, body_phi, body_theta, body_psi){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+4+4+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+4+4+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "ROTORCRAFT_TUNE_HOVER", DL_ROTORCRAFT_TUNE_HOVER, 0+2+2+2+4+4+4+4+4+4+4+4+4+4) \
	  DownlinkPutInt16ByAddr(_trans, _dev, (rc_roll)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (rc_pitch)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (rc_yaw)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (cmd_roll)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (cmd_pitch)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (cmd_yaw)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (cmd_thrust)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (imu_phi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (imu_theta)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (imu_psi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (body_phi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (body_theta)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (body_psi)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_INS_Z(_trans, _dev, baro_alt, ins_z, ins_zd, ins_zdd){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "INS_Z", DL_INS_Z, 0+4+4+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (baro_alt)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ins_z)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ins_zd)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ins_zdd)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_PCAP01_STATUS(_trans, _dev, ihumid, itemp, humid, temp){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "PCAP01_STATUS", DL_PCAP01_STATUS, 0+4+4+4+4) \
	  DownlinkPutUint32ByAddr(_trans, _dev, (ihumid)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (itemp)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (humid)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (temp)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_GEIGER_COUNTER(_trans, _dev, tube1, tube2, vsupply){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+2)); \
	  DownlinkStartMessage(_trans, _dev, "GEIGER_COUNTER", DL_GEIGER_COUNTER, 0+4+4+2) \
	  DownlinkPutUint32ByAddr(_trans, _dev, (tube1)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (tube2)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (vsupply)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_INS_REF(_trans, _dev, ecef_x0, ecef_y0, ecef_z0, lat0, lon0, alt0, hmsl0, baro_qfe){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "INS_REF", DL_INS_REF, 0+4+4+4+4+4+4+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ecef_x0)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ecef_y0)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ecef_z0)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (lat0)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (lon0)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (alt0)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (hmsl0)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (baro_qfe)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_GPS_INT(_trans, _dev, ecef_x, ecef_y, ecef_z, lat, lon, alt, hmsl, ecef_xd, ecef_yd, ecef_zd, pacc, sacc, tow, pdop, numsv, fix){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+2+1+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+2+1+1)); \
	  DownlinkStartMessage(_trans, _dev, "GPS_INT", DL_GPS_INT, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+2+1+1) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ecef_x)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ecef_y)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ecef_z)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (lat)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (lon)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (alt)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (hmsl)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ecef_xd)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ecef_yd)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ecef_zd)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (pacc)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (sacc)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (tow)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (pdop)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (numsv)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (fix)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_AHRS_EULER_INT(_trans, _dev, imu_phi, imu_theta, imu_psi, body_phi, body_theta, body_psi){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "AHRS_EULER_INT", DL_AHRS_EULER_INT, 0+4+4+4+4+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (imu_phi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (imu_theta)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (imu_psi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (body_phi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (body_theta)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (body_psi)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_AHRS_QUAT_INT(_trans, _dev, imu_qi, imu_qx, imu_qy, imu_qz, body_qi, body_qx, body_qy, body_qz){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "AHRS_QUAT_INT", DL_AHRS_QUAT_INT, 0+4+4+4+4+4+4+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (imu_qi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (imu_qx)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (imu_qy)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (imu_qz)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (body_qi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (body_qx)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (body_qy)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (body_qz)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_AHRS_RMAT_INT(_trans, _dev, imu_m00, imu_m01, imu_m02, imu_m10, imu_m11, imu_m12, imu_m20, imu_m21, imu_m22, body_m00, body_m01, body_m02, body_m10, body_m11, body_m12, body_m20, body_m21, body_m22){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "AHRS_RMAT_INT", DL_AHRS_RMAT_INT, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (imu_m00)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (imu_m01)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (imu_m02)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (imu_m10)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (imu_m11)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (imu_m12)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (imu_m20)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (imu_m21)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (imu_m22)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (body_m00)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (body_m01)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (body_m02)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (body_m10)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (body_m11)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (body_m12)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (body_m20)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (body_m21)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (body_m22)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_ROTORCRAFT_NAV_STATUS(_trans, _dev, block_time, stage_time, cur_block, cur_stage, horizontal_mode){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+1+1+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+1+1+1)); \
	  DownlinkStartMessage(_trans, _dev, "ROTORCRAFT_NAV_STATUS", DL_ROTORCRAFT_NAV_STATUS, 0+2+2+1+1+1) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (block_time)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (stage_time)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (cur_block)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (cur_stage)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (horizontal_mode)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_ROTORCRAFT_RADIO_CONTROL(_trans, _dev, roll, pitch, yaw, throttle, mode, kill, status){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+2+2+2+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+2+2+2+1)); \
	  DownlinkStartMessage(_trans, _dev, "ROTORCRAFT_RADIO_CONTROL", DL_ROTORCRAFT_RADIO_CONTROL, 0+2+2+2+2+2+2+1) \
	  DownlinkPutInt16ByAddr(_trans, _dev, (roll)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (pitch)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (yaw)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (throttle)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (mode)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (kill)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (status)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_VFF(_trans, _dev, measure, z, zd, bias, Pzz, Pzdzd, Pbb){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "VFF", DL_VFF, 0+4+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (measure)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (z)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (zd)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (bias)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (Pzz)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (Pzdzd)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (Pbb)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_BOOZ2_TUNE_FF(_trans, _dev, fb_rms, dg, g){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "BOOZ2_TUNE_FF", DL_BOOZ2_TUNE_FF, 0+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (fb_rms)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (dg)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (g)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_HFF(_trans, _dev, x, y, xd, yd, xdd, ydd){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "HFF", DL_HFF, 0+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (x)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (y)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (xd)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (yd)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (xdd)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ydd)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_HFF_DBG(_trans, _dev, x_measure, y_measure, yd_measure, xd_measure, Pxx, Pyy, Pxdxd, Pydyd){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "HFF_DBG", DL_HFF_DBG, 0+4+4+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (x_measure)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (y_measure)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (yd_measure)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (xd_measure)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (Pxx)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (Pyy)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (Pxdxd)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (Pydyd)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_HFF_GPS(_trans, _dev, lag_cnt, lag_cnt_err, save_cnt){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2)); \
	  DownlinkStartMessage(_trans, _dev, "HFF_GPS", DL_HFF_GPS, 0+2+2+2) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (lag_cnt)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (lag_cnt_err)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (save_cnt)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_BOOZ2_SONAR(_trans, _dev, front, back, right, left){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+2)); \
	  DownlinkStartMessage(_trans, _dev, "BOOZ2_SONAR", DL_BOOZ2_SONAR, 0+2+2+2+2) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (front)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (back)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (right)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (left)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_BOOZ2_CAM(_trans, _dev, tilt, pan){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2)); \
	  DownlinkStartMessage(_trans, _dev, "BOOZ2_CAM", DL_BOOZ2_CAM, 0+2+2) \
	  DownlinkPutInt16ByAddr(_trans, _dev, (tilt)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (pan)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_AHRS_REF_QUAT(_trans, _dev, ref_qi, ref_qx, ref_qy, ref_qz, body_qi, body_qx, body_qy, body_qz){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "AHRS_REF_QUAT", DL_AHRS_REF_QUAT, 0+4+4+4+4+4+4+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ref_qi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ref_qx)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ref_qy)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ref_qz)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (body_qi)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (body_qx)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (body_qy)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (body_qz)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_EKF7_XHAT(_trans, _dev, c, s1, s2, s3, p, q, r, bp, bq, br){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "EKF7_XHAT", DL_EKF7_XHAT, 0+4+4+4+4+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (c)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (s1)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (s2)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (s3)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (p)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (q)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (r)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (bp)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (bq)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (br)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_EKF7_Y(_trans, _dev, timecount, g1, g2, g3, m1, m2, m3, p, q, r){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "EKF7_Y", DL_EKF7_Y, 0+2+4+4+4+4+4+4+4+4+4) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (timecount)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (g1)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (g2)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (g3)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (m1)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (m2)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (m3)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (p)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (q)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (r)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_EKF7_P_DIAG(_trans, _dev, c, s1, s2, s3, p, q, r, bp, bq, br){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "EKF7_P_DIAG", DL_EKF7_P_DIAG, 0+4+4+4+4+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (c)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (s1)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (s2)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (s3)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (p)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (q)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (r)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (bp)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (bq)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (br)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_AHRS_EULER(_trans, _dev, phi, theta, psi){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "AHRS_EULER", DL_AHRS_EULER, 0+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (phi)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (theta)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (psi)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_AHRS_MEASUREMENT_EULER(_trans, _dev, phi, theta, psi){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "AHRS_MEASUREMENT_EULER", DL_AHRS_MEASUREMENT_EULER, 0+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (phi)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (theta)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (psi)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_WT(_trans, _dev, rpm){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4)); \
	  DownlinkStartMessage(_trans, _dev, "WT", DL_WT, 0+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (rpm)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_CSC_CAN_DEBUG(_trans, _dev, err_nb, err_code){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "CSC_CAN_DEBUG", DL_CSC_CAN_DEBUG, 0+4+4) \
	  DownlinkPutUint32ByAddr(_trans, _dev, (err_nb)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (err_code)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_CSC_CAN_MSG(_trans, _dev, frame, id, data_a, data_b){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "CSC_CAN_MSG", DL_CSC_CAN_MSG, 0+4+4+4+4) \
	  DownlinkPutUint32ByAddr(_trans, _dev, (frame)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (id)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (data_a)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (data_b)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_AHRS_GYRO_BIAS_INT(_trans, _dev, bp, bq, br){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "AHRS_GYRO_BIAS_INT", DL_AHRS_GYRO_BIAS_INT, 0+4+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (bp)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (bq)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (br)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_FMS_TIME(_trans, _dev, tv_sec, tv_nsec, delay_ns){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "FMS_TIME", DL_FMS_TIME, 0+4+4+4) \
	  DownlinkPutUint32ByAddr(_trans, _dev, (tv_sec)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (tv_nsec)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (delay_ns)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_LOADCELL(_trans, _dev, load){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4)); \
	  DownlinkStartMessage(_trans, _dev, "LOADCELL", DL_LOADCELL, 0+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (load)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_FLA_DEBUG(_trans, _dev, past_input, imu_rate, desired_accel, motor_command){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "FLA_DEBUG", DL_FLA_DEBUG, 0+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (past_input)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (imu_rate)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (desired_accel)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (motor_command)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_BLMC_FAULT_STATUS(_trans, _dev, nb_raw_fault, raw_fault){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+nb_raw_fault*2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+nb_raw_fault*2)); \
	  DownlinkStartMessage(_trans, _dev, "BLMC_FAULT_STATUS", DL_BLMC_FAULT_STATUS, 0+1+nb_raw_fault*2) \
	  DownlinkPutUint16Array(_trans, _dev, nb_raw_fault, raw_fault); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_BLMC_SPEEDS(_trans, _dev, nb_speeds, speeds){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+nb_speeds*2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+nb_speeds*2)); \
	  DownlinkStartMessage(_trans, _dev, "BLMC_SPEEDS", DL_BLMC_SPEEDS, 0+1+nb_speeds*2) \
	  DownlinkPutInt16Array(_trans, _dev, nb_speeds, speeds); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_AHRS_DEBUG_QUAT(_trans, _dev, jqi, jqx, jqy, jqz, xqi, xqx, xqy, xqz, mqi, mqx, mqy, mqz){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "AHRS_DEBUG_QUAT", DL_AHRS_DEBUG_QUAT, 0+4+4+4+4+4+4+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (jqi)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (jqx)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (jqy)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (jqz)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (xqi)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (xqx)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (xqy)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (xqz)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (mqi)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (mqx)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (mqy)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (mqz)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_BLMC_BUSVOLTS(_trans, _dev, nb_busvolts, busvolts){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+nb_busvolts*2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+nb_busvolts*2)); \
	  DownlinkStartMessage(_trans, _dev, "BLMC_BUSVOLTS", DL_BLMC_BUSVOLTS, 0+1+nb_busvolts*2) \
	  DownlinkPutUint16Array(_trans, _dev, nb_busvolts, busvolts); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_SYSTEM_STATUS(_trans, _dev, csc1_loop_count, csc1_msg_count, csc2_loop_count, csc2_msg_count, can_rx_err, can_tx_err, rc_parser_err, system_fault){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+1)); \
	  DownlinkStartMessage(_trans, _dev, "SYSTEM_STATUS", DL_SYSTEM_STATUS, 0+4+4+4+4+4+4+4+1) \
	  DownlinkPutUint32ByAddr(_trans, _dev, (csc1_loop_count)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (csc1_msg_count)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (csc2_loop_count)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (csc2_msg_count)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (can_rx_err)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (can_tx_err)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (rc_parser_err)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (system_fault)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_DYNAMIXEL(_trans, _dev, left_wing, right_wing, left_wing_flag, right_wing_flag, invalid_position, timeout_events, checksum_errors, fuse_rotation_angle, fuse_rotation_rate){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+1+1+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+1+1+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "DYNAMIXEL", DL_DYNAMIXEL, 0+2+2+1+1+4+4+4+4+4) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (left_wing)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (right_wing)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (left_wing_flag)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (right_wing_flag)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (invalid_position)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (timeout_events)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (checksum_errors)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (fuse_rotation_angle)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (fuse_rotation_rate)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_RMAT_DEBUG(_trans, _dev, a, b, c, d, e, f, g, h, i){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "RMAT_DEBUG", DL_RMAT_DEBUG, 0+4+4+4+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (a)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (b)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (c)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (d)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (e)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (f)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (g)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (h)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (i)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_SIMPLE_COMMANDS(_trans, _dev, roll, pitch, yaw){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2)); \
	  DownlinkStartMessage(_trans, _dev, "SIMPLE_COMMANDS", DL_SIMPLE_COMMANDS, 0+2+2+2) \
	  DownlinkPutInt16ByAddr(_trans, _dev, (roll)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (pitch)); \
	  DownlinkPutInt16ByAddr(_trans, _dev, (yaw)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_VANE_SENSOR(_trans, _dev, alpha, alpha_filtered, alpha_target, alpha_vane_error, alpha2, beta, beta_filtered, beta_target, beta_vane_error, beta2){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "VANE_SENSOR", DL_VANE_SENSOR, 0+4+4+4+4+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (alpha)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (alpha_filtered)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (alpha_target)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (alpha_vane_error)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (alpha2)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (beta)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (beta_filtered)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (beta_target)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (beta_vane_error)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (beta2)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_CONTROLLER_GAINS(_trans, _dev, roll_gamma_p, roll_gamma_d, roll_gamma_i, pitch_gamma_p, pitch_gamma_d, pitch_gamma_i, yaw_gamma_p, yaw_gamma_d, yaw_gamma_i){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "CONTROLLER_GAINS", DL_CONTROLLER_GAINS, 0+4+4+4+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (roll_gamma_p)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (roll_gamma_d)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (roll_gamma_i)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (pitch_gamma_p)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (pitch_gamma_d)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (pitch_gamma_i)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (yaw_gamma_p)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (yaw_gamma_d)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (yaw_gamma_i)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_AHRS_LKF(_trans, _dev, phi, theta, psi, qi, qx, qy, qz, p, q, r, ax, ay, az, mx, my, mz){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "AHRS_LKF", DL_AHRS_LKF, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (phi)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (theta)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (psi)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (qi)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (qx)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (qy)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (qz)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (p)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (q)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (r)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ax)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ay)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (az)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (mx)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (my)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (mz)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_AHRS_LKF_DEBUG(_trans, _dev, phi_err, theta_err, psi_err, bp, bq, br, quat_norm, phi_accel, theta_accel, phi_cov, theta_cov, psi_cov, bp_cov, bq_cov, br_cov){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "AHRS_LKF_DEBUG", DL_AHRS_LKF_DEBUG, 0+4+4+4+4+4+4+4+4+4+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (phi_err)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (theta_err)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (psi_err)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (bp)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (bq)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (br)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (quat_norm)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (phi_accel)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (theta_accel)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (phi_cov)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (theta_cov)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (psi_cov)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (bp_cov)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (bq_cov)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (br_cov)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_AHRS_LKF_ACC_DBG(_trans, _dev, qi_err, qx_err, qy_err, qz_err, bp_err, bq_err, br_err){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "AHRS_LKF_ACC_DBG", DL_AHRS_LKF_ACC_DBG, 0+4+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (qi_err)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (qx_err)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (qy_err)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (qz_err)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (bp_err)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (bq_err)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (br_err)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_AHRS_LKF_MAG_DBG(_trans, _dev, qi_err, qx_err, qy_err, qz_err, bp_err, bq_err, br_err){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "AHRS_LKF_MAG_DBG", DL_AHRS_LKF_MAG_DBG, 0+4+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (qi_err)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (qx_err)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (qy_err)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (qz_err)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (bp_err)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (bq_err)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (br_err)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_NPS_SENSORS_SCALED(_trans, _dev, acc_x, acc_y, acc_z, mag_x, mag_y, mag_z){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "NPS_SENSORS_SCALED", DL_NPS_SENSORS_SCALED, 0+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (acc_x)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (acc_y)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (acc_z)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (mag_x)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (mag_y)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (mag_z)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_INS(_trans, _dev, ins_x, ins_y, ins_z, ins_xd, ins_yd, ins_zd, ins_xdd, ins_ydd, ins_zdd){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "INS", DL_INS, 0+4+4+4+4+4+4+4+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ins_x)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ins_y)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ins_z)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ins_xd)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ins_yd)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ins_zd)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ins_xdd)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ins_ydd)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ins_zdd)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_GPS_ERROR(_trans, _dev, x_position, y_position, z_position, x_velocity, y_velocity, z_velocity){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "GPS_ERROR", DL_GPS_ERROR, 0+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (x_position)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (y_position)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (z_position)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (x_velocity)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (y_velocity)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (z_velocity)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_IMU_GYRO(_trans, _dev, gp, gq, gr){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "IMU_GYRO", DL_IMU_GYRO, 0+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (gp)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (gq)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (gr)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_IMU_MAG(_trans, _dev, mx, my, mz){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "IMU_MAG", DL_IMU_MAG, 0+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (mx)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (my)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (mz)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_IMU_ACCEL(_trans, _dev, ax, ay, az){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "IMU_ACCEL", DL_IMU_ACCEL, 0+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (ax)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ay)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (az)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_IMU_GYRO_RAW(_trans, _dev, gp, gq, gr){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "IMU_GYRO_RAW", DL_IMU_GYRO_RAW, 0+4+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (gp)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (gq)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (gr)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_IMU_ACCEL_RAW(_trans, _dev, ax, ay, az){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "IMU_ACCEL_RAW", DL_IMU_ACCEL_RAW, 0+4+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ax)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (ay)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (az)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_IMU_MAG_RAW(_trans, _dev, mx, my, mz){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "IMU_MAG_RAW", DL_IMU_MAG_RAW, 0+4+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (mx)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (my)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (mz)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_IMU_MAG_SETTINGS(_trans, _dev, inclination, declination, hardiron_x, hardiron_y, hardiron_z){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "IMU_MAG_SETTINGS", DL_IMU_MAG_SETTINGS, 0+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (inclination)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (declination)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (hardiron_x)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (hardiron_y)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (hardiron_z)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_IMU_GYRO_LP(_trans, _dev, gp, gq, gr){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "IMU_GYRO_LP", DL_IMU_GYRO_LP, 0+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (gp)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (gq)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (gr)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_IMU_PRESSURE(_trans, _dev, p){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4)); \
	  DownlinkStartMessage(_trans, _dev, "IMU_PRESSURE", DL_IMU_PRESSURE, 0+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (p)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_IMU_HS_GYRO(_trans, _dev, axis, nb_samples, samples){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+nb_samples*4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1+nb_samples*4)); \
	  DownlinkStartMessage(_trans, _dev, "IMU_HS_GYRO", DL_IMU_HS_GYRO, 0+1+1+nb_samples*4) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (axis)); \
	  DownlinkPutUint32Array(_trans, _dev, nb_samples, samples); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_TEST_PASSTHROUGH_STATUS(_trans, _dev, io_proc_msg_cnt, io_proc_err_cnt, io_link_msg_cnt, io_link_err_cnt, rc_status){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+1)); \
	  DownlinkStartMessage(_trans, _dev, "TEST_PASSTHROUGH_STATUS", DL_TEST_PASSTHROUGH_STATUS, 0+4+4+4+4+1) \
	  DownlinkPutUint32ByAddr(_trans, _dev, (io_proc_msg_cnt)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (io_proc_err_cnt)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (io_link_msg_cnt)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (io_link_err_cnt)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (rc_status)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_WEATHER(_trans, _dev, p_amb, t_amb, windspeed, wind_from, humidity){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "WEATHER", DL_WEATHER, 0+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (p_amb)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (t_amb)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (windspeed)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (wind_from)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (humidity)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_IMU_TURNTABLE(_trans, _dev, omega){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4)); \
	  DownlinkStartMessage(_trans, _dev, "IMU_TURNTABLE", DL_IMU_TURNTABLE, 0+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (omega)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_BARO_RAW(_trans, _dev, abs, diff){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "BARO_RAW", DL_BARO_RAW, 0+4+4) \
	  DownlinkPutInt32ByAddr(_trans, _dev, (abs)); \
	  DownlinkPutInt32ByAddr(_trans, _dev, (diff)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_TIME(_trans, _dev, t){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4)); \
	  DownlinkStartMessage(_trans, _dev, "TIME", DL_TIME, 0+4) \
	  DownlinkPutUint32ByAddr(_trans, _dev, (t)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_ROTORCRAFT_STATUS(_trans, _dev, link_imu_nb_err, blmc_nb_err, rc_status, frame_rate, gps_status, ap_mode, ap_in_flight, ap_motors_on, ap_h_mode, ap_v_mode, vsupply, cpu_time){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+1+1+1+1+1+1+1+1+1+1+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+1+1+1+1+1+1+1+1+1+1+2)); \
	  DownlinkStartMessage(_trans, _dev, "ROTORCRAFT_STATUS", DL_ROTORCRAFT_STATUS, 0+4+1+1+1+1+1+1+1+1+1+1+2) \
	  DownlinkPutUint32ByAddr(_trans, _dev, (link_imu_nb_err)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (blmc_nb_err)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (rc_status)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (frame_rate)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (gps_status)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ap_mode)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ap_in_flight)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ap_motors_on)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ap_h_mode)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ap_v_mode)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (vsupply)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (cpu_time)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_STATE_FILTER_STATUS(_trans, _dev, state_filter_mode, value){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+2)); \
	  DownlinkStartMessage(_trans, _dev, "STATE_FILTER_STATUS", DL_STATE_FILTER_STATUS, 0+1+2) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (state_filter_mode)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (value)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_OPTICFLOW(_trans, _dev, flow, ref_alt){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+4)); \
	  DownlinkStartMessage(_trans, _dev, "OPTICFLOW", DL_OPTICFLOW, 0+2+4) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (flow)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ref_alt)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_VISUALTARGET(_trans, _dev, x, y){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2)); \
	  DownlinkStartMessage(_trans, _dev, "VISUALTARGET", DL_VISUALTARGET, 0+2+2) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (x)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (y)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_NPS_POS_LLH(_trans, _dev, pprz_lat, lat_geod, lat_geoc, pprz_lon, lon, pprz_alt, alt_geod, agl, asl){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "NPS_POS_LLH", DL_NPS_POS_LLH, 0+4+4+4+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (pprz_lat)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (lat_geod)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (lat_geoc)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (pprz_lon)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (lon)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (pprz_alt)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (alt_geod)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (agl)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (asl)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_NPS_RPMS(_trans, _dev, front, back, right, left){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "NPS_RPMS", DL_NPS_RPMS, 0+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (front)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (back)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (right)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (left)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_NPS_SPEED_POS(_trans, _dev, ltpp_xdd, ltpp_ydd, ltpp_zdd, ltpp_xd, ltpp_yd, ltpp_zd, ltpp_x, ltpp_y, ltpp_z){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "NPS_SPEED_POS", DL_NPS_SPEED_POS, 0+4+4+4+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (ltpp_xdd)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ltpp_ydd)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ltpp_zdd)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ltpp_xd)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ltpp_yd)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ltpp_zd)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ltpp_x)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ltpp_y)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ltpp_z)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_NPS_RATE_ATTITUDE(_trans, _dev, p, q, r, phi, theta, psi){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "NPS_RATE_ATTITUDE", DL_NPS_RATE_ATTITUDE, 0+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (p)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (q)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (r)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (phi)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (theta)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (psi)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_NPS_GYRO_BIAS(_trans, _dev, bp, bq, br){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "NPS_GYRO_BIAS", DL_NPS_GYRO_BIAS, 0+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (bp)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (bq)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (br)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_NPS_RANGE_METER(_trans, _dev, dist){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4)); \
	  DownlinkStartMessage(_trans, _dev, "NPS_RANGE_METER", DL_NPS_RANGE_METER, 0+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (dist)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_NPS_WIND(_trans, _dev, vx, vy, vz){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "NPS_WIND", DL_NPS_WIND, 0+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (vx)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (vy)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (vz)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_BOOZ_DEBUG_FOO(_trans, _dev, ami_stat){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1)); \
	  DownlinkStartMessage(_trans, _dev, "BOOZ_DEBUG_FOO", DL_BOOZ_DEBUG_FOO, 0+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (ami_stat)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_BOOZ_MAX1167_ERR(_trans, _dev, erno){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1)); \
	  DownlinkStartMessage(_trans, _dev, "BOOZ_MAX1167_ERR", DL_BOOZ_MAX1167_ERR, 0+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (erno)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_PPRZ_DEBUG(_trans, _dev, module, errno){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+1)); \
	  DownlinkStartMessage(_trans, _dev, "PPRZ_DEBUG", DL_PPRZ_DEBUG, 0+1+1) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (module)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (errno)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_NPS_ACCEL_LTP(_trans, _dev, xdd, ydd, zdd){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "NPS_ACCEL_LTP", DL_NPS_ACCEL_LTP, 0+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (xdd)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (ydd)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (zdd)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_LOOSE_INS_GPS(_trans, _dev, status, time_running, q0, q1, q2, q3, phi, theta, psi, north, east, down, v_north, v_east, v_down, est_p, est_q, est_r, gyroBias_x, gyroBias_y, gyroBias_z, imuCallbacks, gpsCallbacks, baroCallbacks){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+1+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "LOOSE_INS_GPS", DL_LOOSE_INS_GPS, 0+1+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+4+4+4) \
	  DownlinkPutUint8ByAddr(_trans, _dev, (status)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (time_running)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (q0)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (q1)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (q2)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (q3)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (phi)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (theta)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (psi)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (north)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (east)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (down)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (v_north)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (v_east)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (v_down)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (est_p)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (est_q)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (est_r)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (gyroBias_x)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (gyroBias_y)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (gyroBias_z)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (imuCallbacks)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (gpsCallbacks)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (baroCallbacks)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_AFL_COEFFS(_trans, _dev, roll_a, roll_b, roll_c, pitch_a, pitch_b, pitch_c, yaw_a, yaw_b, yaw_c){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "AFL_COEFFS", DL_AFL_COEFFS, 0+4+4+4+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (roll_a)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (roll_b)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (roll_c)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (pitch_a)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (pitch_b)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (pitch_c)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (yaw_a)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (yaw_b)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (yaw_c)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_BOOZ_ATT_REF_MODEL(_trans, _dev, omega_p, zeta_p, omega_q, zeta_q, omega_r, zeta_r){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "BOOZ_ATT_REF_MODEL", DL_BOOZ_ATT_REF_MODEL, 0+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (omega_p)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (zeta_p)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (omega_q)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (zeta_q)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (omega_r)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (zeta_r)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_BOOZ2_FF_ADAP(_trans, _dev, roll, pitch, yaw){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "BOOZ2_FF_ADAP", DL_BOOZ2_FF_ADAP, 0+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (roll)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (pitch)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (yaw)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_I2C_ERRORS(_trans, _dev, acknowledge_failure_cnt, misplaced_start_or_stop_cnt, arbitration_lost_cnt, overrun_or_underrun_cnt, pec_error_in_reception_cnt, timeout_or_tlow_error_cnt, smbus_alert_cnt, unexpected_event_cnt, last_unexpected_event, bus_number){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+2+2+2+2+2+4+1))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+2+2+2+2+2+2+2+2+4+1)); \
	  DownlinkStartMessage(_trans, _dev, "I2C_ERRORS", DL_I2C_ERRORS, 0+2+2+2+2+2+2+2+2+4+1) \
	  DownlinkPutUint16ByAddr(_trans, _dev, (acknowledge_failure_cnt)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (misplaced_start_or_stop_cnt)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (arbitration_lost_cnt)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (overrun_or_underrun_cnt)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (pec_error_in_reception_cnt)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (timeout_or_tlow_error_cnt)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (smbus_alert_cnt)); \
	  DownlinkPutUint16ByAddr(_trans, _dev, (unexpected_event_cnt)); \
	  DownlinkPutUint32ByAddr(_trans, _dev, (last_unexpected_event)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (bus_number)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_RDYB_TRAJECTORY(_trans, _dev, commanded_phi, commanded_theta, commanded_psi, setpoint_x, setpoint_y, setpoint_z){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+4+4+4+4+4)); \
	  DownlinkStartMessage(_trans, _dev, "RDYB_TRAJECTORY", DL_RDYB_TRAJECTORY, 0+4+4+4+4+4+4) \
	  DownlinkPutFloatByAddr(_trans, _dev, (commanded_phi)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (commanded_theta)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (commanded_psi)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (setpoint_x)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (setpoint_y)); \
	  DownlinkPutFloatByAddr(_trans, _dev, (setpoint_z)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#define DOWNLINK_SEND_HENRY_GNSS(_trans, _dev, last_imu_update, GPS_time, GPS_solution_valid, latitude, longitude, altitude, North, East, Down, SVs_Tracked, SVs_PVT, V_North, V_East, V_Down){ \
	if (DownlinkCheckFreeSpace(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+8+1+8+8+8+8+8+8+1+1+8+8+8))) {\
	  DownlinkCountBytes(_trans, _dev, DownlinkSizeOf(_trans, _dev, 0+4+8+1+8+8+8+8+8+8+1+1+8+8+8)); \
	  DownlinkStartMessage(_trans, _dev, "HENRY_GNSS", DL_HENRY_GNSS, 0+4+8+1+8+8+8+8+8+8+1+1+8+8+8) \
	  DownlinkPutUint32ByAddr(_trans, _dev, (last_imu_update)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (GPS_time)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (GPS_solution_valid)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (latitude)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (longitude)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (altitude)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (North)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (East)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (Down)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (SVs_Tracked)); \
	  DownlinkPutUint8ByAddr(_trans, _dev, (SVs_PVT)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (V_North)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (V_East)); \
	  DownlinkPutDoubleByAddr(_trans, _dev, (V_Down)); \
	  DownlinkEndMessage(_trans, _dev ) \
	} else \
	  DownlinkOverrun(_trans, _dev ); \
}

#else // DOWNLINK
#define DOWNLINK_SEND_BOOT(_trans, _dev, version) {}
#define DOWNLINK_SEND_ALIVE(_trans, _dev, nb_md5sum, md5sum) {}
#define DOWNLINK_SEND_PONG(_trans, _dev ) {}
#define DOWNLINK_SEND_TAKEOFF(_trans, _dev, cpu_time) {}
#define DOWNLINK_SEND_ATTITUDE(_trans, _dev, phi, psi, theta) {}
#define DOWNLINK_SEND_IR_SENSORS(_trans, _dev, ir1, ir2, longitudinal, lateral, vertical) {}
#define DOWNLINK_SEND_GPS(_trans, _dev, mode, utm_east, utm_north, course, alt, speed, climb, week, itow, utm_zone, gps_nb_err) {}
#define DOWNLINK_SEND_NAVIGATION_REF(_trans, _dev, utm_east, utm_north, utm_zone) {}
#define DOWNLINK_SEND_NAVIGATION(_trans, _dev, cur_block, cur_stage, pos_x, pos_y, dist2_wp, dist2_home, circle_count, oval_count) {}
#define DOWNLINK_SEND_PPRZ_MODE(_trans, _dev, ap_mode, ap_gaz, ap_lateral, ap_horizontal, if_calib_mode, mcu1_status) {}
#define DOWNLINK_SEND_BAT(_trans, _dev, throttle, voltage, amps, flight_time, kill_auto_throttle, block_time, stage_time, energy) {}
#define DOWNLINK_SEND_DEBUG_MCU_LINK(_trans, _dev, i2c_nb_err, i2c_mcu1_nb_err, ppm_rate) {}
#define DOWNLINK_SEND_CALIBRATION(_trans, _dev, climb_sum_err, climb_gaz_submode) {}
#define DOWNLINK_SEND_SETTINGS(_trans, _dev, slider_1_val, slider_2_val) {}
#define DOWNLINK_SEND_DESIRED(_trans, _dev, roll, pitch, course, x, y, altitude, climb) {}
#define DOWNLINK_SEND_GPS_SOL(_trans, _dev, Pacc, Sacc, PDOP, numSV) {}
#define DOWNLINK_SEND_ADC_GENERIC(_trans, _dev, val1, val2) {}
#define DOWNLINK_SEND_TEST_FORMAT(_trans, _dev, val1, val2) {}
#define DOWNLINK_SEND_CAM(_trans, _dev, phi, theta, target_x, target_y) {}
#define DOWNLINK_SEND_CIRCLE(_trans, _dev, center_east, center_north, radius) {}
#define DOWNLINK_SEND_SEGMENT(_trans, _dev, segment_east_1, segment_north_1, segment_east_2, segment_north_2) {}
#define DOWNLINK_SEND_DOWNLINK_STATUS(_trans, _dev, run_time, rx_bytes, rx_msgs, rx_err, rx_bytes_rate, rx_msgs_rate, ping_time) {}
#define DOWNLINK_SEND_MODEM_STATUS(_trans, _dev, detected, valim, cd, nb_byte, nb_msg, nb_err) {}
#define DOWNLINK_SEND_SVINFO(_trans, _dev, chn, SVID, Flags, QI, CNO, Elev, Azim) {}
#define DOWNLINK_SEND_DEBUG(_trans, _dev, nb_msg, msg) {}
#define DOWNLINK_SEND_SURVEY(_trans, _dev, east, north, west, south) {}
#define DOWNLINK_SEND_WC_RSSI(_trans, _dev, raw_level) {}
#define DOWNLINK_SEND_RANGEFINDER(_trans, _dev, range, z_dot, z_dot_sum_err, z_dot_setpoint, z_sum_err, z_setpoint, flying) {}
#define DOWNLINK_SEND_DOWNLINK(_trans, _dev, nb_ovrn, rate, nb_msgs) {}
#define DOWNLINK_SEND_DL_VALUE(_trans, _dev, index, value) {}
#define DOWNLINK_SEND_MARK(_trans, _dev, ac_id, lat, long) {}
#define DOWNLINK_SEND_SYS_MON(_trans, _dev, periodic_time, periodic_cycle, periodic_cycle_min, periodic_cycle_max, event_number, cpu_load) {}
#define DOWNLINK_SEND_MOTOR(_trans, _dev, rpm, current) {}
#define DOWNLINK_SEND_WP_MOVED(_trans, _dev, wp_id, utm_east, utm_north, alt, utm_zone) {}
#define DOWNLINK_SEND_ENERGY(_trans, _dev, bat, amp, energy, power) {}
#define DOWNLINK_SEND_BARO_BMP85_CALIB(_trans, _dev, a1, a2, a3, a4, a5, a6, b1, b2, mb, mc, md) {}
#define DOWNLINK_SEND_BARO_BMP85(_trans, _dev, UT, UP, P, T, MSL) {}
#define DOWNLINK_SEND_SPEED_LOOP(_trans, _dev, ve_set_point, ve, vn_set_point, vn, north_sp, east_sp) {}
#define DOWNLINK_SEND_ALT_KALMAN(_trans, _dev, p00, p01, p10, p11) {}
#define DOWNLINK_SEND_ESTIMATOR(_trans, _dev, z, z_dot) {}
#define DOWNLINK_SEND_TUNE_ROLL(_trans, _dev, p, phi, phi_sp) {}
#define DOWNLINK_SEND_BARO_MS5534A(_trans, _dev, pressure, temp, alt) {}
#define DOWNLINK_SEND_PRESSURE(_trans, _dev, airspeed_adc, airspeed, altitude_adc, altitude) {}
#define DOWNLINK_SEND_BARO_WORDS(_trans, _dev, w1, w2, w3, w4) {}
#define DOWNLINK_SEND_WP_MOVED_LLA(_trans, _dev, wp_id, lat, lon, alt) {}
#define DOWNLINK_SEND_CHRONO(_trans, _dev, tag, time) {}
#define DOWNLINK_SEND_WP_MOVED_ENU(_trans, _dev, wp_id, east, north, up) {}
#define DOWNLINK_SEND_WINDTURBINE_STATUS_(_trans, _dev, ac_id, tb_id, sync_itow, cycle_time) {}
#define DOWNLINK_SEND_RC_3CH_(_trans, _dev, throttle_mode, roll, pitch) {}
#define DOWNLINK_SEND_MPPT(_trans, _dev, nb_values, values) {}
#define DOWNLINK_SEND_DEBUG_IR_I2C(_trans, _dev, ir1, ir2, top) {}
#define DOWNLINK_SEND_AIRSPEED(_trans, _dev, airspeed, airspeed_sp, airspeed_cnt, groundspeed_sp) {}
#define DOWNLINK_SEND_XSENS(_trans, _dev, counter, p, q, r, phi, theta, psi, ax, ay, az, vx, vy, vz, lat, lon, alt, status, hour, min, sec, nanosec, year, month, day) {}
#define DOWNLINK_SEND_BARO_ETS(_trans, _dev, adc, offset, scaled) {}
#define DOWNLINK_SEND_AIRSPEED_ETS(_trans, _dev, adc, offset, scaled) {}
#define DOWNLINK_SEND_PBN(_trans, _dev, airspeed_adc, altitude_adc, airspeed, altitude, airspeed_offset, altitude_offset) {}
#define DOWNLINK_SEND_GPS_LLA(_trans, _dev, lat, lon, alt, course, speed, climb, week, itow, mode, gps_nb_err) {}
#define DOWNLINK_SEND_H_CTL_A(_trans, _dev, roll_sum_err, ref_roll_angle, pitch_sum_err, ref_pitch_angle) {}
#define DOWNLINK_SEND_TURB_PRESSURE_RAW(_trans, _dev, ch_0, ch_1, ch_2, ch_3, ch_4, ch_5, ch_6, ch_7, ch_8, ch_9, ch_10, ch_11, ch_12, ch_13, ch_14, ch_15) {}
#define DOWNLINK_SEND_TURB_PRESSURE_VOLTAGE(_trans, _dev, ch_1_p, ch_1_t, ch_2_p, ch_2_t, ch_3_p, ch_3_t, ch_4_p, ch_4_t, ch_5_p, ch_5_t, ch_6_p, ch_6_t, ch_7_p, ch_7_t, gnd1, gnd2) {}
#define DOWNLINK_SEND_CAM_POINT(_trans, _dev, cam_point_distance_from_home, cam_point_lat, cam_point_lon) {}
#define DOWNLINK_SEND_DC_INFO(_trans, _dev, mode, utm_east, utm_north, course, buffer, dist, next_dist, start_x, start_y, start_angle, angle, last_block, count, shutter) {}
#define DOWNLINK_SEND_AMSYS_BARO(_trans, _dev, pBaroRaw, pBaro, pHomePressure, AltOffset, aktuell, Over_Ground, tempBaro) {}
#define DOWNLINK_SEND_AMSYS_AIRSPEED(_trans, _dev, asRaw, asPresure, asAirspeed, asAirsFilt, asTemp) {}
#define DOWNLINK_SEND_FLIGHT_BENCHMARK(_trans, _dev, SE_As, SE_Alt, SE_Pos, Err_As, Err_Alt, Err_Pos) {}
#define DOWNLINK_SEND_AOA_adc(_trans, _dev, adcVal, AOA) {}
#define DOWNLINK_SEND_XTEND_RSSI(_trans, _dev, datalink_time, rssi_fade_margin, duty) {}
#define DOWNLINK_SEND_VF_UPDATE(_trans, _dev, baro, range_meter) {}
#define DOWNLINK_SEND_VF_PREDICT(_trans, _dev, accel) {}
#define DOWNLINK_SEND_CROSS_TRACK_ERROR(_trans, _dev, cross_track_error, cte_int) {}
#define DOWNLINK_SEND_GENERIC_COM(_trans, _dev, lat, lon, alt, gspeed, course, airspeed, vsupply, energy, throttle, ap_mode, nav_block, flight_time) {}
#define DOWNLINK_SEND_FORMATION_SLOT_TM(_trans, _dev, ac_id, mode, slot_east, slot_north, slot_alt) {}
#define DOWNLINK_SEND_FORMATION_STATUS_TM(_trans, _dev, ac_id, leader_id, status) {}
#define DOWNLINK_SEND_BMP_STATUS(_trans, _dev, UP, UT, press, temp) {}
#define DOWNLINK_SEND_MLX_STATUS(_trans, _dev, itemp_case, temp_case, itemp_obj, temp_obj) {}
#define DOWNLINK_SEND_TMP_STATUS(_trans, _dev, itemp, temp) {}
#define DOWNLINK_SEND_WIND_INFO_RET(_trans, _dev, east, north, airspeed) {}
#define DOWNLINK_SEND_SCP_STATUS(_trans, _dev, press, temp) {}
#define DOWNLINK_SEND_SHT_STATUS(_trans, _dev, ihumid, itemp, humid, temp) {}
#define DOWNLINK_SEND_ENOSE_STATUS(_trans, _dev, val1, val2, val3, PID, nb_heat, heat) {}
#define DOWNLINK_SEND_DPICCO_STATUS(_trans, _dev, humid, temp, fhumid, ftemp) {}
#define DOWNLINK_SEND_ANTENNA_DEBUG(_trans, _dev, mag_xraw, mag_yraw, mag_xcal, mag_ycal, mag_heading, mag_magnitude, mag_temp, mag_distor, mag_cal_status) {}
#define DOWNLINK_SEND_ANTENNA_STATUS(_trans, _dev, azim_sp, elev_sp, id_sp, mode) {}
#define DOWNLINK_SEND_MOTOR_BENCH_STATUS(_trans, _dev, time_ticks, throttle, rpm, current, thrust, torque, time_s, mode) {}
#define DOWNLINK_SEND_MOTOR_BENCH_STATIC(_trans, _dev, av_rpm, av_thrust, av_current, throttle) {}
#define DOWNLINK_SEND_HIH_STATUS(_trans, _dev, humid, fhumid, ftemp) {}
#define DOWNLINK_SEND_TEMT_STATUS(_trans, _dev, light, f_light) {}
#define DOWNLINK_SEND_GP2Y_STATUS(_trans, _dev, idensity, density) {}
#define DOWNLINK_SEND_SHT_I2C_SERIAL(_trans, _dev, serial0, serial1) {}
#define DOWNLINK_SEND_PPM(_trans, _dev, ppm_rate, nb_values, values) {}
#define DOWNLINK_SEND_RC(_trans, _dev, nb_values, values) {}
#define DOWNLINK_SEND_COMMANDS(_trans, _dev, nb_values, values) {}
#define DOWNLINK_SEND_FBW_STATUS(_trans, _dev, rc_status, frame_rate, mode, vsupply, current) {}
#define DOWNLINK_SEND_ADC(_trans, _dev, mcu, nb_values, values) {}
#define DOWNLINK_SEND_ACTUATORS(_trans, _dev, nb_values, values) {}
#define DOWNLINK_SEND_BETH(_trans, _dev, azimuth, elevation, tilt, counter, can_errs, spi_errs, thrust_out, pitch_out) {}
#define DOWNLINK_SEND_BETH_ESTIMATOR(_trans, _dev, tilt, tilt_dot, elevation, elevation_dot, azimuth, azimuth_dot) {}
#define DOWNLINK_SEND_BETH_CONTROLLER(_trans, _dev, pitch, thrust, pitch_ff, pitch_fb, thrust_ff, thrust_fb, tilt_sp, tilt_ref, tilt_dot_ref, elevation_sp , elevation_ref , elevation_dot_ref, azimuth_sp) {}
#define DOWNLINK_SEND_BETH_CONTROLLER_TWIST(_trans, _dev, S, S_dot, U_twt, error) {}
#define DOWNLINK_SEND_DC_SHOT(_trans, _dev, photo_nr, utm_east, utm_north, z, utm_zone, phi, theta, course, speed, itow) {}
#define DOWNLINK_SEND_TEST_BOARD_RESULTS(_trans, _dev, uart, ppm, nb_servo, servo) {}
#define DOWNLINK_SEND_BETH_CONTROLLER_SFB(_trans, _dev, one) {}
#define DOWNLINK_SEND_MLX_SERIAL(_trans, _dev, serial0, serial1) {}
#define DOWNLINK_SEND_PAYLOAD(_trans, _dev, nb_values, values) {}
#define DOWNLINK_SEND_HTM_STATUS(_trans, _dev, ihumid, itemp, humid, temp) {}
#define DOWNLINK_SEND_BARO_MS5611(_trans, _dev, d1, d2, pressure, temp) {}
#define DOWNLINK_SEND_MS5611_COEFF(_trans, _dev, c0, c1, c2, c3, c4, c5, c6, c7) {}
#define DOWNLINK_SEND_ATMOSPHERE_CHARGE(_trans, _dev, t0, t1, t2, t3, t4, t5, t6, t7, t8, t9) {}
#define DOWNLINK_SEND_SOLAR_RADIATION(_trans, _dev, up_t0, dn_t0, up_t1, dn_t1, up_t2, dn_t2, up_t3, dn_t3, up_t4, dn_t4, up_t5, dn_t5, up_t6, dn_t6, up_t7, dn_t7, up_t8, dn_t8, up_t9, dn_t9) {}
#define DOWNLINK_SEND_TCAS_TA(_trans, _dev, ac_id) {}
#define DOWNLINK_SEND_TCAS_RA(_trans, _dev, ac_id, resolve) {}
#define DOWNLINK_SEND_TCAS_RESOLVED(_trans, _dev, ac_id) {}
#define DOWNLINK_SEND_TCAS_DEBUG(_trans, _dev, ac_id, tau) {}
#define DOWNLINK_SEND_POTENTIAL(_trans, _dev, east, north, alt, speed, climb) {}
#define DOWNLINK_SEND_VERTICAL_ENERGY(_trans, _dev, Epot_err, Ekin_err, Etot_err, Edis_err, throttle, nav_pitch, speed_sp) {}
#define DOWNLINK_SEND_TEMP_TCOUPLE(_trans, _dev, fval0, fval1, fval2, fval3, fref0, fref1, fref2, fref3, val0, val1, val2, val3, ref0, ref1, ref2, ref3) {}
#define DOWNLINK_SEND_SHT_I2C_STATUS(_trans, _dev, ihumid, itemp, humid, temp) {}
#define DOWNLINK_SEND_CAMERA_SNAPSHOT(_trans, _dev, snapshot_image_number) {}
#define DOWNLINK_SEND_TIMESTAMP(_trans, _dev, timestamp) {}
#define DOWNLINK_SEND_STAB_ATTITUDE_FLOAT(_trans, _dev, est_p, est_q, est_r, est_phi, est_theta, est_psi, ref_phi, ref_theta, ref_psi, sum_err_phi, sum_err_theta, sum_err_psi, delta_a_fb, delta_e_fb, delta_r_fb, delta_a_ff, delta_e_ff, delta_r_ff, delta_a, delta_e, delta_r, est_p_d, est_q_d, est_r_d) {}
#define DOWNLINK_SEND_IMU_GYRO_SCALED(_trans, _dev, gp, gq, gr) {}
#define DOWNLINK_SEND_IMU_ACCEL_SCALED(_trans, _dev, ax, ay, az) {}
#define DOWNLINK_SEND_IMU_MAG_SCALED(_trans, _dev, mx, my, mz) {}
#define DOWNLINK_SEND_FILTER(_trans, _dev, phi, theta, psi, measure_phi, measure_theta, measure_psi, corrected_phi, corrected_theta, corrected_psi, correction_phi, correction_theta, correction_psi, bp, bq, br) {}
#define DOWNLINK_SEND_FILTER2(_trans, _dev, px, py, pz, gsx, gsy, gsz) {}
#define DOWNLINK_SEND_RATE_LOOP(_trans, _dev, sp_p, sp_q, sp_r, ref_p, ref_q, ref_r, refdot_p, refdot_q, refdot_r, sumerr_p, sumerr_q, sumerr_r, ff_p, ff_q, ff_r, fb_p, fb_q, fb_r, delta_t) {}
#define DOWNLINK_SEND_FILTER_ALIGNER(_trans, _dev, lp_gp, lp_gq, lp_gr, gp, gq, gr, noise, cnt, status) {}
#define DOWNLINK_SEND_FILTER_COR(_trans, _dev, mphi, mtheta, mpsi, qi, qx, qy, qz) {}
#define DOWNLINK_SEND_STAB_ATTITUDE_INT(_trans, _dev, est_p, est_q, est_r, est_phi, est_theta, est_psi, sp_phi, sp_theta, sp_psi, sum_err_phi, sum_err_theta, sum_err_psi, delta_a_fb, delta_e_fb, delta_r_fb, delta_a_ff, delta_e_ff, delta_r_ff, delta_a, delta_e, delta_r) {}
#define DOWNLINK_SEND_STAB_ATTITUDE_REF_INT(_trans, _dev, sp_phi, sp_theta, sp_psi, ref_phi, ref_theta, ref_psi, ref_p, ref_q, ref_r, ref_pd, ref_qd, ref_rd) {}
#define DOWNLINK_SEND_STAB_ATTITUDE_REF_FLOAT(_trans, _dev, sp_phi, sp_theta, sp_psi, ref_phi, ref_theta, ref_psi, ref_p, ref_q, ref_r, ref_pd, ref_qd, ref_rd) {}
#define DOWNLINK_SEND_ROTORCRAFT_CMD(_trans, _dev, cmd_roll, cmd_pitch, cmd_yaw, cmd_thrust) {}
#define DOWNLINK_SEND_GUIDANCE(_trans, _dev, pos_n, pos_e, sp_pos_n, sp_pos_e) {}
#define DOWNLINK_SEND_VERT_LOOP(_trans, _dev, z_sp, zd_sp, est_z, est_zd, est_zdd, ref_z, ref_zd, ref_zdd, adp_inv_m, adp_cov, adp_meas, sum_err, ff_cmd, fb_cmd, delta_t) {}
#define DOWNLINK_SEND_HOVER_LOOP(_trans, _dev, sp_x, sp_y, est_x, est_y, est_xd, est_yd, est_xdd, est_ydd, err_x, err_y, err_xd, err_yd, err_sum_x, err_sum_y, err_nav_x, err_nav_y, cmd_x, cmd_y, cmd_phi, cmd_theta, cmd_psi) {}
#define DOWNLINK_SEND_ROTORCRAFT_FP(_trans, _dev, east, north, up, veast, vnorth, vup, phi, theta, psi, carrot_east, carrot_north, carrot_up, carrot_psi, thrust, flight_time) {}
#define DOWNLINK_SEND_BOOZ2_FMS_INFO(_trans, _dev, tbd) {}
#define DOWNLINK_SEND_GUIDANCE_H_REF_INT(_trans, _dev, sp_x, ref_x, ref_xd, ref_xdd, sp_y, ref_y, ref_yd, ref_ydd) {}
#define DOWNLINK_SEND_ROTORCRAFT_TUNE_HOVER(_trans, _dev, rc_roll, rc_pitch, rc_yaw, cmd_roll, cmd_pitch, cmd_yaw, cmd_thrust, imu_phi, imu_theta, imu_psi, body_phi, body_theta, body_psi) {}
#define DOWNLINK_SEND_INS_Z(_trans, _dev, baro_alt, ins_z, ins_zd, ins_zdd) {}
#define DOWNLINK_SEND_PCAP01_STATUS(_trans, _dev, ihumid, itemp, humid, temp) {}
#define DOWNLINK_SEND_GEIGER_COUNTER(_trans, _dev, tube1, tube2, vsupply) {}
#define DOWNLINK_SEND_INS_REF(_trans, _dev, ecef_x0, ecef_y0, ecef_z0, lat0, lon0, alt0, hmsl0, baro_qfe) {}
#define DOWNLINK_SEND_GPS_INT(_trans, _dev, ecef_x, ecef_y, ecef_z, lat, lon, alt, hmsl, ecef_xd, ecef_yd, ecef_zd, pacc, sacc, tow, pdop, numsv, fix) {}
#define DOWNLINK_SEND_AHRS_EULER_INT(_trans, _dev, imu_phi, imu_theta, imu_psi, body_phi, body_theta, body_psi) {}
#define DOWNLINK_SEND_AHRS_QUAT_INT(_trans, _dev, imu_qi, imu_qx, imu_qy, imu_qz, body_qi, body_qx, body_qy, body_qz) {}
#define DOWNLINK_SEND_AHRS_RMAT_INT(_trans, _dev, imu_m00, imu_m01, imu_m02, imu_m10, imu_m11, imu_m12, imu_m20, imu_m21, imu_m22, body_m00, body_m01, body_m02, body_m10, body_m11, body_m12, body_m20, body_m21, body_m22) {}
#define DOWNLINK_SEND_ROTORCRAFT_NAV_STATUS(_trans, _dev, block_time, stage_time, cur_block, cur_stage, horizontal_mode) {}
#define DOWNLINK_SEND_ROTORCRAFT_RADIO_CONTROL(_trans, _dev, roll, pitch, yaw, throttle, mode, kill, status) {}
#define DOWNLINK_SEND_VFF(_trans, _dev, measure, z, zd, bias, Pzz, Pzdzd, Pbb) {}
#define DOWNLINK_SEND_BOOZ2_TUNE_FF(_trans, _dev, fb_rms, dg, g) {}
#define DOWNLINK_SEND_HFF(_trans, _dev, x, y, xd, yd, xdd, ydd) {}
#define DOWNLINK_SEND_HFF_DBG(_trans, _dev, x_measure, y_measure, yd_measure, xd_measure, Pxx, Pyy, Pxdxd, Pydyd) {}
#define DOWNLINK_SEND_HFF_GPS(_trans, _dev, lag_cnt, lag_cnt_err, save_cnt) {}
#define DOWNLINK_SEND_BOOZ2_SONAR(_trans, _dev, front, back, right, left) {}
#define DOWNLINK_SEND_BOOZ2_CAM(_trans, _dev, tilt, pan) {}
#define DOWNLINK_SEND_AHRS_REF_QUAT(_trans, _dev, ref_qi, ref_qx, ref_qy, ref_qz, body_qi, body_qx, body_qy, body_qz) {}
#define DOWNLINK_SEND_EKF7_XHAT(_trans, _dev, c, s1, s2, s3, p, q, r, bp, bq, br) {}
#define DOWNLINK_SEND_EKF7_Y(_trans, _dev, timecount, g1, g2, g3, m1, m2, m3, p, q, r) {}
#define DOWNLINK_SEND_EKF7_P_DIAG(_trans, _dev, c, s1, s2, s3, p, q, r, bp, bq, br) {}
#define DOWNLINK_SEND_AHRS_EULER(_trans, _dev, phi, theta, psi) {}
#define DOWNLINK_SEND_AHRS_MEASUREMENT_EULER(_trans, _dev, phi, theta, psi) {}
#define DOWNLINK_SEND_WT(_trans, _dev, rpm) {}
#define DOWNLINK_SEND_CSC_CAN_DEBUG(_trans, _dev, err_nb, err_code) {}
#define DOWNLINK_SEND_CSC_CAN_MSG(_trans, _dev, frame, id, data_a, data_b) {}
#define DOWNLINK_SEND_AHRS_GYRO_BIAS_INT(_trans, _dev, bp, bq, br) {}
#define DOWNLINK_SEND_FMS_TIME(_trans, _dev, tv_sec, tv_nsec, delay_ns) {}
#define DOWNLINK_SEND_LOADCELL(_trans, _dev, load) {}
#define DOWNLINK_SEND_FLA_DEBUG(_trans, _dev, past_input, imu_rate, desired_accel, motor_command) {}
#define DOWNLINK_SEND_BLMC_FAULT_STATUS(_trans, _dev, nb_raw_fault, raw_fault) {}
#define DOWNLINK_SEND_BLMC_SPEEDS(_trans, _dev, nb_speeds, speeds) {}
#define DOWNLINK_SEND_AHRS_DEBUG_QUAT(_trans, _dev, jqi, jqx, jqy, jqz, xqi, xqx, xqy, xqz, mqi, mqx, mqy, mqz) {}
#define DOWNLINK_SEND_BLMC_BUSVOLTS(_trans, _dev, nb_busvolts, busvolts) {}
#define DOWNLINK_SEND_SYSTEM_STATUS(_trans, _dev, csc1_loop_count, csc1_msg_count, csc2_loop_count, csc2_msg_count, can_rx_err, can_tx_err, rc_parser_err, system_fault) {}
#define DOWNLINK_SEND_DYNAMIXEL(_trans, _dev, left_wing, right_wing, left_wing_flag, right_wing_flag, invalid_position, timeout_events, checksum_errors, fuse_rotation_angle, fuse_rotation_rate) {}
#define DOWNLINK_SEND_RMAT_DEBUG(_trans, _dev, a, b, c, d, e, f, g, h, i) {}
#define DOWNLINK_SEND_SIMPLE_COMMANDS(_trans, _dev, roll, pitch, yaw) {}
#define DOWNLINK_SEND_VANE_SENSOR(_trans, _dev, alpha, alpha_filtered, alpha_target, alpha_vane_error, alpha2, beta, beta_filtered, beta_target, beta_vane_error, beta2) {}
#define DOWNLINK_SEND_CONTROLLER_GAINS(_trans, _dev, roll_gamma_p, roll_gamma_d, roll_gamma_i, pitch_gamma_p, pitch_gamma_d, pitch_gamma_i, yaw_gamma_p, yaw_gamma_d, yaw_gamma_i) {}
#define DOWNLINK_SEND_AHRS_LKF(_trans, _dev, phi, theta, psi, qi, qx, qy, qz, p, q, r, ax, ay, az, mx, my, mz) {}
#define DOWNLINK_SEND_AHRS_LKF_DEBUG(_trans, _dev, phi_err, theta_err, psi_err, bp, bq, br, quat_norm, phi_accel, theta_accel, phi_cov, theta_cov, psi_cov, bp_cov, bq_cov, br_cov) {}
#define DOWNLINK_SEND_AHRS_LKF_ACC_DBG(_trans, _dev, qi_err, qx_err, qy_err, qz_err, bp_err, bq_err, br_err) {}
#define DOWNLINK_SEND_AHRS_LKF_MAG_DBG(_trans, _dev, qi_err, qx_err, qy_err, qz_err, bp_err, bq_err, br_err) {}
#define DOWNLINK_SEND_NPS_SENSORS_SCALED(_trans, _dev, acc_x, acc_y, acc_z, mag_x, mag_y, mag_z) {}
#define DOWNLINK_SEND_INS(_trans, _dev, ins_x, ins_y, ins_z, ins_xd, ins_yd, ins_zd, ins_xdd, ins_ydd, ins_zdd) {}
#define DOWNLINK_SEND_GPS_ERROR(_trans, _dev, x_position, y_position, z_position, x_velocity, y_velocity, z_velocity) {}
#define DOWNLINK_SEND_IMU_GYRO(_trans, _dev, gp, gq, gr) {}
#define DOWNLINK_SEND_IMU_MAG(_trans, _dev, mx, my, mz) {}
#define DOWNLINK_SEND_IMU_ACCEL(_trans, _dev, ax, ay, az) {}
#define DOWNLINK_SEND_IMU_GYRO_RAW(_trans, _dev, gp, gq, gr) {}
#define DOWNLINK_SEND_IMU_ACCEL_RAW(_trans, _dev, ax, ay, az) {}
#define DOWNLINK_SEND_IMU_MAG_RAW(_trans, _dev, mx, my, mz) {}
#define DOWNLINK_SEND_IMU_MAG_SETTINGS(_trans, _dev, inclination, declination, hardiron_x, hardiron_y, hardiron_z) {}
#define DOWNLINK_SEND_IMU_GYRO_LP(_trans, _dev, gp, gq, gr) {}
#define DOWNLINK_SEND_IMU_PRESSURE(_trans, _dev, p) {}
#define DOWNLINK_SEND_IMU_HS_GYRO(_trans, _dev, axis, nb_samples, samples) {}
#define DOWNLINK_SEND_TEST_PASSTHROUGH_STATUS(_trans, _dev, io_proc_msg_cnt, io_proc_err_cnt, io_link_msg_cnt, io_link_err_cnt, rc_status) {}
#define DOWNLINK_SEND_WEATHER(_trans, _dev, p_amb, t_amb, windspeed, wind_from, humidity) {}
#define DOWNLINK_SEND_IMU_TURNTABLE(_trans, _dev, omega) {}
#define DOWNLINK_SEND_BARO_RAW(_trans, _dev, abs, diff) {}
#define DOWNLINK_SEND_TIME(_trans, _dev, t) {}
#define DOWNLINK_SEND_ROTORCRAFT_STATUS(_trans, _dev, link_imu_nb_err, blmc_nb_err, rc_status, frame_rate, gps_status, ap_mode, ap_in_flight, ap_motors_on, ap_h_mode, ap_v_mode, vsupply, cpu_time) {}
#define DOWNLINK_SEND_STATE_FILTER_STATUS(_trans, _dev, state_filter_mode, value) {}
#define DOWNLINK_SEND_OPTICFLOW(_trans, _dev, flow, ref_alt) {}
#define DOWNLINK_SEND_VISUALTARGET(_trans, _dev, x, y) {}
#define DOWNLINK_SEND_NPS_POS_LLH(_trans, _dev, pprz_lat, lat_geod, lat_geoc, pprz_lon, lon, pprz_alt, alt_geod, agl, asl) {}
#define DOWNLINK_SEND_NPS_RPMS(_trans, _dev, front, back, right, left) {}
#define DOWNLINK_SEND_NPS_SPEED_POS(_trans, _dev, ltpp_xdd, ltpp_ydd, ltpp_zdd, ltpp_xd, ltpp_yd, ltpp_zd, ltpp_x, ltpp_y, ltpp_z) {}
#define DOWNLINK_SEND_NPS_RATE_ATTITUDE(_trans, _dev, p, q, r, phi, theta, psi) {}
#define DOWNLINK_SEND_NPS_GYRO_BIAS(_trans, _dev, bp, bq, br) {}
#define DOWNLINK_SEND_NPS_RANGE_METER(_trans, _dev, dist) {}
#define DOWNLINK_SEND_NPS_WIND(_trans, _dev, vx, vy, vz) {}
#define DOWNLINK_SEND_BOOZ_DEBUG_FOO(_trans, _dev, ami_stat) {}
#define DOWNLINK_SEND_BOOZ_MAX1167_ERR(_trans, _dev, erno) {}
#define DOWNLINK_SEND_PPRZ_DEBUG(_trans, _dev, module, errno) {}
#define DOWNLINK_SEND_NPS_ACCEL_LTP(_trans, _dev, xdd, ydd, zdd) {}
#define DOWNLINK_SEND_LOOSE_INS_GPS(_trans, _dev, status, time_running, q0, q1, q2, q3, phi, theta, psi, north, east, down, v_north, v_east, v_down, est_p, est_q, est_r, gyroBias_x, gyroBias_y, gyroBias_z, imuCallbacks, gpsCallbacks, baroCallbacks) {}
#define DOWNLINK_SEND_AFL_COEFFS(_trans, _dev, roll_a, roll_b, roll_c, pitch_a, pitch_b, pitch_c, yaw_a, yaw_b, yaw_c) {}
#define DOWNLINK_SEND_BOOZ_ATT_REF_MODEL(_trans, _dev, omega_p, zeta_p, omega_q, zeta_q, omega_r, zeta_r) {}
#define DOWNLINK_SEND_BOOZ2_FF_ADAP(_trans, _dev, roll, pitch, yaw) {}
#define DOWNLINK_SEND_I2C_ERRORS(_trans, _dev, acknowledge_failure_cnt, misplaced_start_or_stop_cnt, arbitration_lost_cnt, overrun_or_underrun_cnt, pec_error_in_reception_cnt, timeout_or_tlow_error_cnt, smbus_alert_cnt, unexpected_event_cnt, last_unexpected_event, bus_number) {}
#define DOWNLINK_SEND_RDYB_TRAJECTORY(_trans, _dev, commanded_phi, commanded_theta, commanded_psi, setpoint_x, setpoint_y, setpoint_z) {}
#define DOWNLINK_SEND_HENRY_GNSS(_trans, _dev, last_imu_update, GPS_time, GPS_solution_valid, latitude, longitude, altitude, North, East, Down, SVs_Tracked, SVs_PVT, V_North, V_East, V_Down) {}
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
