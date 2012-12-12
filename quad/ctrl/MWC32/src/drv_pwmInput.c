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

#define PPM_TIM         TIM3
#define PPM_Channel     TIM_Channel_1
#define PPM_Polarity    TIM_ICPolarity_Rising
#define PPM_PORT        GPIOA
#define PPM_PIN         GPIO_Pin_6
#define PPM_IRQ         TIM3_IRQn
#define PPM_IT          TIM_IT_CC1

static struct TIM_Channel {
    TIM_TypeDef *tim;
    uint16_t channel;
    uint16_t cc;
} Channels[] = {
    { TIM2, TIM_Channel_1, TIM_IT_CC1 },
    { TIM2, TIM_Channel_2, TIM_IT_CC2 },
    { TIM2, TIM_Channel_3, TIM_IT_CC3 },
    { TIM2, TIM_Channel_4, TIM_IT_CC4 },
    { TIM3, TIM_Channel_1, TIM_IT_CC1 },
    { TIM3, TIM_Channel_2, TIM_IT_CC2 },
    { TIM3, TIM_Channel_3, TIM_IT_CC3 },
    { TIM3, TIM_Channel_4, TIM_IT_CC4 },
};

static struct PWM_State {
    uint8_t  state;
    uint16_t rise;
    uint16_t fall;
    uint16_t capture;
} Inputs[8] = { { 0, } };

static TIM_ICInitTypeDef  TIM_ICInitStructure = { 0, };

uint8_t rcActive = false;

///////////////////////////////////////////////////////////////////////////////

static void serialPWM_IRQHandler(TIM_TypeDef *tim)
{
    uint16_t diff;
    static uint16_t now;
    static uint16_t last = 0;
    static uint8_t  chan = 0;

    if (TIM_GetITStatus(tim, TIM_IT_CC1) == SET)
    {
        last = now;
        now = TIM_GetCapture1(tim);
        rcActive = true;
    }

    TIM_ClearITPendingBit(tim, TIM_IT_CC1);

    diff = now - last;

    if (diff > 2700 * 2)   // Per http://www.rcgroups.com/forums/showpost.php?p=21996147&postcount=3960
    {                      // "So, if you use 2.5ms or higher as being the reset for the PPM stream start,
        chan = 0;          // you will be fine. I use 2.7ms just to be safe."
    }
    else
    {
        if (diff > 750 * 2 && diff < 2250 * 2 && chan < 8)    // 750 to 2250 ms is our 'valid' channel range
        {
            Inputs[chan].capture = diff;
        }
        chan++;
    }
}

///////////////////////////////////////////////////////////////////////////////

static void parallelPWM_IRQHandler(TIM_TypeDef *tim)
{
    uint8_t i;
    uint16_t val = 0;

    for (i = 0; i < 8; i++)
    {
        struct TIM_Channel channel = Channels[i];
        struct PWM_State *state = &Inputs[i];

        if (channel.tim == tim && (TIM_GetITStatus(tim, channel.cc) == SET))
        {
            TIM_ClearITPendingBit(channel.tim, channel.cc);
            if ( i == 0 )
                rcActive = true;

            switch (channel.channel)
            {
                case TIM_Channel_1:
                    val = TIM_GetCapture1(channel.tim);
                    break;
                case TIM_Channel_2:
                    val = TIM_GetCapture2(channel.tim);
                    break;
                case TIM_Channel_3:
                    val = TIM_GetCapture3(channel.tim);
                    break;
                case TIM_Channel_4:
                    val = TIM_GetCapture4(channel.tim);
                    break;
            }

            if (state->state == 0)
                state->rise = val;
            else
                state->fall = val;

            if (state->state == 0)
            {
                // switch states
                state->state = 1;

                TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Falling;
                TIM_ICInitStructure.TIM_Channel = channel.channel;
                TIM_ICInit(channel.tim, &TIM_ICInitStructure);
            }
            else
            {
                // compute capture
                state->capture = state->fall - state->rise;

                // switch state
                state->state = 0;

                TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
                TIM_ICInitStructure.TIM_Channel = channel.channel;
                TIM_ICInit(channel.tim, &TIM_ICInitStructure);
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////

void TIM2_IRQHandler(void)
{
    if (systemConfig.useSerialPWMflag)
        serialPWM_IRQHandler(TIM2);
    else
        parallelPWM_IRQHandler(TIM2);
}

///////////////////////////////////////////////////////////////////////////////

void TIM3_IRQHandler(void)
{
    if (systemConfig.useSerialPWMflag)
        serialPWM_IRQHandler(TIM3);
    else
        parallelPWM_IRQHandler(TIM3);
}

///////////////////////////////////////////////////////////////////////////////

void pwmInputInit(void)
{
    // Inputs

    // RX1  TIM2_CH1 PA0
    // RX2  TIM2_CH2 PA1
    // RX3  TIM2_CH3 PA2
    // RX4  TIM2_CH4 PA3
    // RX5  TIM3_CH1 PA6
    // RX6  TIM3_CH2 PA7
    // RX7  TIM3_CH3 PB0
    // RX8  TIM3_CH4 PB1

    GPIO_InitTypeDef GPIO_InitStructure            = { 0, };
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure = { 0, };
    NVIC_InitTypeDef NVIC_InitStructure            = { 0, };
    uint8_t i;

    if (systemConfig.useSerialPWMflag)
    {
        // PPM input
        // Configure TIM2_CH1 for PPM input
        GPIO_InitStructure.GPIO_Pin   = PPM_PIN;
        GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IPD;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

        GPIO_Init(PPM_PORT, &GPIO_InitStructure);

        // Input timer on TIM2 only for PPM
        NVIC_InitStructure.NVIC_IRQChannel                   = PPM_IRQ;
        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
        NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 1;
        NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;

        NVIC_Init(&NVIC_InitStructure);

        // TIM2 timebase
        TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);

        TIM_TimeBaseStructure.TIM_Prescaler   = (36 - 1);
        TIM_TimeBaseStructure.TIM_Period      = 0xffff;
        TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

        TIM_TimeBaseInit(PPM_TIM, &TIM_TimeBaseStructure);

        // Input capture on TIM2_CH1 for PPM
        TIM_ICInitStructure.TIM_ICPolarity  = PPM_Polarity;
        TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
        TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
        TIM_ICInitStructure.TIM_ICFilter    = 0x0;
        TIM_ICInitStructure.TIM_Channel     = PPM_Channel;

        TIM_ICInit(PPM_TIM, &TIM_ICInitStructure);

        // TIM2_CH1 capture compare interrupt enable
        TIM_ITConfig(PPM_TIM, PPM_IT, ENABLE);
        TIM_Cmd(PPM_TIM, ENABLE);
    }
    else
    {
       // Configure TIM2, TIM3 all 4 channels
        GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_6 | GPIO_Pin_7;
        GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IPD;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

        GPIO_Init(GPIOA, &GPIO_InitStructure);

        GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_0 | GPIO_Pin_1;

        GPIO_Init(GPIOB, &GPIO_InitStructure);

        // Input timers on TIM2 and TIM3 for PWM
        NVIC_InitStructure.NVIC_IRQChannel                   = TIM2_IRQn;
        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
        NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 1;
        NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;

        NVIC_Init(&NVIC_InitStructure);

        NVIC_InitStructure.NVIC_IRQChannel                   = TIM3_IRQn;

        NVIC_Init(&NVIC_InitStructure);

        // TIM2 and TIM3 timebase
        TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);

        TIM_TimeBaseStructure.TIM_Prescaler   = (36 - 1);
        TIM_TimeBaseStructure.TIM_Period      = 0xffff;
        TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

        TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
        TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

        // PWM Input capture
        TIM_ICInitStructure.TIM_ICPolarity  = TIM_ICPolarity_Rising;
        TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
        TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
        TIM_ICInitStructure.TIM_ICFilter    = 0x0;

        for (i = 0; i < 8; i++)
        {
            TIM_ICInitStructure.TIM_Channel = Channels[i].channel;
            TIM_ICInit(Channels[i].tim, &TIM_ICInitStructure);
        }

        TIM_ITConfig(TIM2, TIM_IT_CC1 | TIM_IT_CC2 | TIM_IT_CC3 | TIM_IT_CC4, ENABLE);
        TIM_ITConfig(TIM3, TIM_IT_CC1 | TIM_IT_CC2 | TIM_IT_CC3 | TIM_IT_CC4, ENABLE);
        TIM_Cmd(TIM2, ENABLE);
        TIM_Cmd(TIM3, ENABLE);
    }
}

///////////////////////////////////////////////////////////////////////////////

uint16_t pwmRead(uint8_t channel)
{
    return Inputs[channel].capture;
}

///////////////////////////////////////////////////////////////////////////////
