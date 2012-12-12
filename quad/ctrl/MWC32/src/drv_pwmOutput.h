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

typedef struct drv_pwm_output_config_t {
    uint8_t useServos;
    uint8_t noEsc;
    uint16_t escPwmRate;
    uint16_t servoPwmRate;
    uint16_t motorPwmRate;
} drv_pwm_output_config_t;

extern drv_pwm_output_config_t pwmOutputConfig;

///////////////////////////////////////////////////////////////////////////////

void pwmWrite(uint8_t channel, uint16_t value);

///////////////////////////////////////////////////////////////////////////////

void pwmOutputInit(drv_pwm_output_config_t * init);

///////////////////////////////////////////////////////////////////////////////
