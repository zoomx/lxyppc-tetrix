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

// for roundf()
#define __USE_C99_MATH

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

#include "stm32f10x_conf.h"
#include "core_cm3.h"

#define digitalHi(p, i)     { p->BSRR = i; }
#define digitalLo(p, i)     { p->BRR = i; }
#define digitalToggle(p, i) { p->ODR ^= i; }

// Hardware definitions and GPIO

#define LED0_GPIO   GPIOA
#define LED0_PIN    GPIO_Pin_15
#define LED1_GPIO   GPIOB
#define LED1_PIN    GPIO_Pin_3

#define LED0_TOGGLE digitalToggle(LED0_GPIO, LED0_PIN);
#define LED0_OFF    digitalHi(LED0_GPIO, LED0_PIN);
#define LED0_ON     digitalLo(LED0_GPIO, LED0_PIN);

#define LED1_TOGGLE digitalToggle(LED1_GPIO, LED1_PIN);
#define LED1_OFF    digitalHi(LED1_GPIO, LED1_PIN);
#define LED1_ON     digitalLo(LED1_GPIO, LED1_PIN);

#define  SENSOR_I2C     I2C1

#include "pid.h"

#include "baseFlightPlus.h"

#include "drv_pwmInput.h"
#include "drv_pwmOutput.h"
#include "drv_i2c.h"
#include "drv_system.h"
#include "drv_uart.h"

#include "adxl345.h"
#include "bmp085.h"
#include "hmc5883.h"
#include "mpu3050.h"
#include "mpu6050.h"

#include "accelCalibration.h"
#include "ahrsCalibration.h"
#include "chr6dmMatrix3x3.h"
#include "chr6dmAHRS.h"
#include "computeAxisCommands.h"
#include "config.h"
#include "flightCommand.h"
#include "gyroTempCalibration.h"
#include "lowPassFilter.h"
#include "MadgwickAHRS.h"
#include "magCalibration.h"
#include "MargAHRS.h"
#include "mixer.h"
#include "serial.h"
#include "utilities.h"

///////////////////////////////////////////////////////////////////////////////
