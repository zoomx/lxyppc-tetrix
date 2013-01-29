
#include "sensors.h"
#include "alg_types.h"

// convert sensor data to flight
// unit : rad/s
// gyro[0] roll
// gyro[1] PITCH
// gyro[2] yaw
void board_2_flight_gyro(float* gyro, int32_t *raw)
{
}

// unit: g, don't care
// acc[0] x-axis
// acc[1] y-axis
// acc[2] z-axis
void board_2_flight_acc(float* acc, int32_t *raw)
{
}

// unit: gauss, don't care
// mag[0] x-axis
// mag[1] y-axis
// mag[2] z-axis
void board_2_flight_mag(float* mag, int32_t *raw)
{
}

