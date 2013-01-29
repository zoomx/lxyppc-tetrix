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

#ifndef UART_H
#define UART_H
#include "stm32f10x.h"
#include "stdint.h"
///////////////////////////////////////////////////////////////////////////////

#define  PROTOCAL_SUPPORT       1


void uart1_init(uint32_t baudRate);
void uart2_init(uint32_t baudRate);
#if PROTOCAL_SUPPORT
#include "uart_data_process.h"
uint8_t uart1_send_data(const void* p, uint32_t len);

#else
///////////////////////////////////////////////////////////////////////////////

uint16_t uartAvailable(void);

///////////////////////////////////////////////////////////////////////////////

uint8_t uartTransmitEmpty(void);

///////////////////////////////////////////////////////////////////////////////

uint8_t uartRead(void);

///////////////////////////////////////////////////////////////////////////////

uint8_t uartReadPoll(void);

///////////////////////////////////////////////////////////////////////////////

void uartWrite(uint8_t ch);

///////////////////////////////////////////////////////////////////////////////

void uartPrint(char *str);
#endif
///////////////////////////////////////////////////////////////////////////////

#endif
