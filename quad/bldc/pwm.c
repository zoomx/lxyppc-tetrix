#include "pwm.h"
#include "stm32f0xx.h"


// Initialize the PWM, PWM will also used to sync the ADC
// TIM1 is used to output PWM, TIM1 CC4 used to sync ADC
#define GET_DUTY(percent)   \
      (uint16_t)((((uint32_t)percent) * ((SYSTEM_FREQ/PWM_FREQ) - 1) ) / 100)

void init_pwm(void)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;
    NVIC_InitTypeDef    NVIC_InitStructure;
    
    TIM_TimeBaseStructure.TIM_Prescaler = 0;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseStructure.TIM_Period = (SYSTEM_FREQ/PWM_FREQ) - 1;
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
    
    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
    
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
    // We may disable these output after initialize
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
    
    TIM_OCInitStructure.TIM_Pulse = GET_DUTY(50); // 5%
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
    TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
    TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
    TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCIdleState_Reset;
    
    TIM_OC1Init(TIM1, &TIM_OCInitStructure);
		TIM_OCInitStructure.TIM_Pulse = GET_DUTY(30); // 5%
    TIM_OC2Init(TIM1, &TIM_OCInitStructure);
		TIM_OCInitStructure.TIM_Pulse = GET_DUTY(10); // 5%
    TIM_OC3Init(TIM1, &TIM_OCInitStructure);
    // TIM4 CH4 is used to triggrt the ADC
		TIM_OCInitStructure.TIM_Pulse = GET_DUTY(80); // 5%
    TIM_OC4Init(TIM1, &TIM_OCInitStructure);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_2);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_2);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_2);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource11, GPIO_AF_2);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_2);
    
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource0, GPIO_AF_2);
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource1, GPIO_AF_2);
    
    // We need update the timer settings by COM event
    // In this case, TIM15 and TIM17 can be used as COM trigger
    TIM_CCPreloadControl(TIM1, ENABLE);
    // Select TIM15 as the trigger
    TIM_SelectInputTrigger(TIM1, TIM_TS_ITR0);
    
    NVIC_InitStructure.NVIC_IRQChannel = TIM1_BRK_UP_TRG_COM_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    TIM_ITConfig(TIM1, TIM_IT_COM, ENABLE);
    
    TIM_Cmd(TIM1, ENABLE);
    /* TIM1 Main Output Enable */
    TIM_CtrlPWMOutputs(TIM1, ENABLE);
    
    //init_tim15();
}

#define  AP      (1ul<<0)
#define  AN      (1ul<<2)
#define  BP      (1ul<<4)
#define  BN      (1ul<<6)
#define  CP      (1ul<<8)
#define  CN      (1ul<<10)
#define  ALL_OFF        (~ (AP|AN|BP|BN|CP|CN))
#define  CLOSE_ALL()    TIM1->CCER &= ALL_OFF
#define  ENABLE_TIM(mask)   \
        do{\
            TIM1->CCER &= ALL_OFF;\
            TIM1->CCER |= mask;\
        }while(0)

#define  A_B    ENABLE_TIM(AP|BN)    
#define  C_B    ENABLE_TIM(CP|BN)
#define  C_A    ENABLE_TIM(CP|AN)
#define  B_A    ENABLE_TIM(BP|AN)
#define  B_C    ENABLE_TIM(BP|CN)
#define  A_C    ENABLE_TIM(AP|CN)

int32_t dir = 1;
int32_t step = 1;
void TIM1_BRK_UP_TRG_COM_IRQHandler(void)
{
    TIM_ClearITPendingBit(TIM1, TIM_IT_COM);
    // Here to prepare data for next step
    if(dir>0) dir = 1;
    if(dir<0) dir = -1;
    switch(step){
        case 1:
            A_B;
            step += dir;
            break;
        case 2:
            C_B;
            step += dir;
            break;
        case 3:
            C_A;
            step += dir;
            break;
        case 4:
            B_A;
            step += dir;
            break;
        case 5:
            B_C;
            step += dir;
            break;
        case 6:
            A_C;
            step += dir;
            break;
    }
    if(step>6){
        step = 1;
    }else if(step < 1){
        step = 6;
    }
}

// Here I use the tim15 as the COM trigger for tim1
// TIM15 can use DMA channel 5 to update it's pre-load values
void init_tim15(void)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    NVIC_InitTypeDef         NVIC_InitStructure;
    
    TIM_TimeBaseStructure.TIM_Period = 0xFFFF;          
    TIM_TimeBaseStructure.TIM_Prescaler = (uint16_t) (SystemCoreClock / 24000000) - 1;
    TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;    
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;   
    TIM_TimeBaseInit(TIM15, &TIM_TimeBaseStructure);
    
    /* Select the Master Slave Mode */
    TIM_SelectMasterSlaveMode(TIM15, TIM_MasterSlaveMode_Enable);

    /* Master Mode selection */
    TIM_SelectOutputTrigger(TIM15, TIM_TRGOSource_Update);
    
    NVIC_InitStructure.NVIC_IRQChannel = TIM15_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    TIM_ITConfig(TIM15, TIM_IT_Update, ENABLE);
    
    // enable tim15
    TIM_Cmd(TIM15, ENABLE);
}

// to make sure tim15 is running
void TIM15_IRQHandler(void)
{
    TIM_ClearITPendingBit(TIM15, TIM_IT_Update);
    // TIM15 is running
}

#define PWM_MASK  (~0xFFF)
void pwm_force_output(uint8_t a, uint8_t b, uint8_t c)
{
    uint16_t ccer = (a & 0xf ? 0 : AP) | (a & 0xf0 ? 0 : AN)
                  | (b & 0xf ? 0 : BP) | (b & 0xf0 ? 0 : BN)
                  | (c & 0xf ? 0 : CP) | (c & 0xf0 ? 0 : CN)
                  |  ((a & 0xf) == 1 ? 0 : (AP<<1)) |  ((a & 0xf) == 0x10 ? (AN<<1) : 0)
                  |  ((b & 0xf) == 1 ? 0 : (BP<<1)) |  ((b & 0xf) == 0x10 ? (BN<<1) : 0)
                  |  ((c & 0xf) == 1 ? 0 : (CP<<1)) |  ((c & 0xf) == 0x10 ? (CN<<1) : 0)
    ;
    
    TIM1->CCER &= PWM_MASK;//ALL_OFF;
    TIM1->CCER |= ccer;
    TIM_GenerateEvent(TIM1, TIM_EventSource_COM);
}

void set_duty(uint16_t duty)
{
    TIM1->CCR1 = duty;
    TIM1->CCR2 = duty;
    TIM1->CCR3 = duty;
}


