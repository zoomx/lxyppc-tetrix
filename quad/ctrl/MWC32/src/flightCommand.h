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
// Process Pilot Commands Defines and Variables
///////////////////////////////////////////////////////////////////////////////

#define DEADBAND       24
#define DEADBAND_SLOPE 1000/(1000-DEADBAND)

extern float rxCommand[8];

extern uint8_t commandInDetent[3];
extern uint8_t previousCommandInDetent[3];

extern uint8_t channelOrder[8];

///////////////////////////////////////////////////////////////////////////////
// Flight Mode Defines and Variables
///////////////////////////////////////////////////////////////////////////////

#define RATE     0
#define ATTITUDE 1

extern uint8_t flightMode;

///////////////////////////////////////////////////////////////////////////////
// Arm State Variables
///////////////////////////////////////////////////////////////////////////////

extern uint8_t armed;
extern uint8_t armingTimer;

///////////////////////////////////////////////////////////////////////////////
// Process Flight Commands
///////////////////////////////////////////////////////////////////////////////

void processFlightCommands(void);

///////////////////////////////////////////////////////////////////////////////
