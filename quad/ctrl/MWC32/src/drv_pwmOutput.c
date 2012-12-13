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

#include "board.h"

///////////////////////////////////////////////////////////////////////////////

#define PULSE_1MS   2000
#define PULSE_1p5MS 3000
#define PULSE_2MS   4000
#define DUTY(duty)  (((uint32_t)(duty)) * ((uint32_t)pwm_period) / 100)

drv_pwm_output_config_t pwmOutputConfig;

///////////////////////////////////////////////////////////////////////////////

static uint16_t pwm_period;

static volatile uint16_t *OutputChannels[] = {
    &(TIM2->CCR1),
    &(TIM2->CCR2),
    &(TIM2->CCR3),
    &(TIM2->CCR4),
    &(TIM4->CCR3),
    &(TIM4->CCR4),
};

///////////////////////////////////////////////////////////////////////////////

void pwmWrite(uint8_t channel, uint16_t value)
{
    if (channel < 8)
        *OutputChannels[channel] = value;
}

///////////////////////////////////////////////////////////////////////////////

void pwmOutputInit(drv_pwm_output_config_t * init)
{
    GPIO_InitTypeDef GPIO_InitStructure = { 0, };
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure = { 0, };
    TIM_OCInitTypeDef TIM_OCInitStructure = { 0, };

    // Outputs
    // PWM1 TIM1_CH1 PA8
    // PWM2 TIM1_CH4 PA11
    // PWM3 TIM4_CH1 PB6
    // PWM4 TIM4_CH2 PB7
    // PWM5 TIM4_CH3 PB8
    // PWM6 TIM4_CH4 PB9

    // Output pins
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(GPIOA, &GPIO_InitStructure);

    //GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;

    //GPIO_Init(GPIOB, &GPIO_InitStructure);

    // Output timers
    TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);

    TIM_TimeBaseStructure.TIM_Prescaler = (36 - 1);

    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
    TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
    
    
    if (init->noEsc) {
        TIM_TimeBaseStructure.TIM_Period = (2000000 / init->motorPwmRate) - 1;
        TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
        pwm_period = 2000000 / init->motorPwmRate;
        TIM_OCInitStructure.TIM_Pulse = DUTY(10);
        TIM_OC1Init(TIM2, &TIM_OCInitStructure);
        TIM_OCInitStructure.TIM_Pulse = DUTY(20);
        TIM_OC2Init(TIM2, &TIM_OCInitStructure);
        TIM_OCInitStructure.TIM_Pulse = DUTY(30);
        TIM_OC3Init(TIM2, &TIM_OCInitStructure);
        TIM_OCInitStructure.TIM_Pulse = DUTY(40);
        TIM_OC4Init(TIM2, &TIM_OCInitStructure);
    }else if (init->useServos == true) {
        // ch1, 2 for servo
        TIM_TimeBaseStructure.TIM_Period = (2000000 / init->servoPwmRate) - 1;
        TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);

        TIM_OCInitStructure.TIM_Pulse = PULSE_1p5MS;
        TIM_OC1Init(TIM1, &TIM_OCInitStructure);
        TIM_OC4Init(TIM1, &TIM_OCInitStructure);

        TIM_TimeBaseStructure.TIM_Period = (2000000 / init->escPwmRate) - 1;
        TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

        TIM_OCInitStructure.TIM_Pulse = PULSE_1MS;
        TIM_OC1Init(TIM4, &TIM_OCInitStructure);
        TIM_OC2Init(TIM4, &TIM_OCInitStructure);
        TIM_OC3Init(TIM4, &TIM_OCInitStructure);
        TIM_OC4Init(TIM4, &TIM_OCInitStructure);
    } else {
        TIM_TimeBaseStructure.TIM_Period = (2000000 / init->escPwmRate) - 1;
        TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
        TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

        TIM_OCInitStructure.TIM_Pulse = PULSE_1MS;
        TIM_OC1Init(TIM1, &TIM_OCInitStructure);
        TIM_OC4Init(TIM1, &TIM_OCInitStructure);
        TIM_OC1Init(TIM4, &TIM_OCInitStructure);
        TIM_OC2Init(TIM4, &TIM_OCInitStructure);
        TIM_OC3Init(TIM4, &TIM_OCInitStructure);
        TIM_OC4Init(TIM4, &TIM_OCInitStructure);
    }

    TIM_Cmd(TIM2, ENABLE);
    //TIM_Cmd(TIM4, ENABLE);
    TIM_CtrlPWMOutputs(TIM2, ENABLE);
    //TIM_CtrlPWMOutputs(TIM4, ENABLE);
}

///////////////////////////////////////////////////////////////////////////////
