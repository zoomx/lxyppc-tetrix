/**
  ******************************************************************************
  * @file    Project/STM32F0xx_StdPeriph_Templates/main.h 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    18-May-2012
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx.h"
#include "stm32f0xx_i2c_cpal.h"
#include <stdio.h>

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */
void TimingDelay_Decrement(void);
void Delay(__IO uint32_t nTime);
uint8_t get_i2c_addr(void);

#define  MIN_BAT                4000  /* 4000mV */

// command definition
#define  CMD_LED        0x11    // cmd, led1, led2.     ret: cnd,led1,led2
#define  CMD_I2C_ADD    0x12    // cmd                  ret: cmd,i2c addr
#define  CMD_ADC_ALL    0x13    // cmd                  ret: cmd,adc cnt, 16bits adc ...
#define  CMD_ADC_SINGLE 0x14    // cmd, ch              ret: cmd,adc cnt, 16bits adc
// get ADC calibration value
#define  CMD_GET_CAL    0x15    // cmd                  ret: cmd,0, ref(2bytes), temp 30(2bytes), temp 110(2bytes)
#define  CMD_SET_PWM    0x16    // cmd,a,b,c,duty(2)    ret: cmd,a,b,c
#define  CMD_START_BLDC 0x17    // cmd,enable,freq(2),duty(2) ret: cmd,enable,freq(2),duty(2)
#define  CMD_GET_PPM    0x18    // cmd           ret: cmd, ppm cnt, ppm1(2), ppm2(2) ... ppmN(2)
// Enable the TX pin of USART2, this will disable the SWD clk pin
#define  CMD_ENABLE_TX  0x19    // cmd           ret: cmd
#define  CMD_DISABLE_TX 0x1A    // cmd           ret: cmd
#define  CMD_GET_ERROR  0x1B    // cmd           ret: cmd, error code
#define  CMD_GET_TEST_DATA  0x1C // cmd,idx,len  ret: cmd, data len


// Error reason definition
#define  ERR_NONE       0
#define  ERR_A          1
#define  ERR_B          2
#define  ERR_C          3
#define  ERR_AB         4
#define  ERR_AC         5
#define  ERR_BC         6
#define  ERR_BAT        7

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
