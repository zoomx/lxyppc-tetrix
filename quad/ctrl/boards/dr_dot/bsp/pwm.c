#include "pwm.h"
#include "stm32f10x.h"

#define  PRESCALER      36
#define  SYSFREQ_MHz    72

void pwm_input_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
    TIM_ICInitTypeDef  TIM_ICInitStructure;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    
    /* TIM2 clock enable */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

    /* GPIOB clock enable */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
      
    /* TIM2 chennel2 configuration : PA.07 */
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    /* Connect TIM pin to AF1 */
    //GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_1);

    /* Enable the TIM2 global Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    // TIM3 timebase
    TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
    TIM_TimeBaseStructure.TIM_Prescaler = (PRESCALER-1);
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
        
    TIM_ICInitStructure.TIM_Channel = TIM_Channel_2;
    TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
    TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
    TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
    TIM_ICInitStructure.TIM_ICFilter = 0x0;
    TIM_ICInit(TIM3, &TIM_ICInitStructure);
    
    // tim2 in STM32F3 is a 32 bit timer
    TIM_ITConfig(TIM3, TIM_IT_CC2, ENABLE);
    //TIM_PWMIConfig
    TIM_Cmd(TIM3,ENABLE);
}


static uint32_t period = 0;
#define DUTY(duty)  (((uint32_t)(duty)) * ((uint32_t)period) / 100)
void pwm_output_init(uint32_t pwm_rate)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;
    uint32_t pre = 1;
    
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(GPIOA, &GPIO_InitStructure);

    period = (72000000/pre)/pwm_rate;
    while(period > 65535){
        pre *= 2;
        period = (72000000/pre)/pwm_rate;
    }
    
    
    TIM_TimeBaseStructure.TIM_Prescaler = pre - 1;
    TIM_TimeBaseStructure.TIM_Period = period - 1;
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
    
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
    TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
    
    TIM_OCInitStructure.TIM_Pulse = DUTY(5);
    TIM_OC1Init(TIM2, &TIM_OCInitStructure);
    
    TIM_OCInitStructure.TIM_Pulse = DUTY(5);
    TIM_OC2Init(TIM2, &TIM_OCInitStructure);
    
    TIM_OCInitStructure.TIM_Pulse = DUTY(5);
    TIM_OC3Init(TIM2, &TIM_OCInitStructure);
    
    TIM_OCInitStructure.TIM_Pulse = DUTY(5);
    TIM_OC4Init(TIM2, &TIM_OCInitStructure);
    
    TIM_Cmd(TIM2, ENABLE);
    TIM_CtrlPWMOutputs(TIM2, ENABLE);
}

void set_motor_speed(int32_t* value)
{
    TIM2->CCR1 = (uint16_t)value[0];
    TIM2->CCR2 = (uint16_t)value[1];
    TIM2->CCR3 = (uint16_t)value[2];
    TIM2->CCR4 = (uint16_t)value[3];
}

#define MAX_CHN_CNT   16
#define MAX_PULSE     3000 /* 3000us*/
#if INPUT_TIMER_BIT == 32
typedef  uint32_t timer_val_t;
#elif INPUT_TIMER_BIT == 16
typedef  uint16_t timer_val_t;
#else
#error wrong timer bit
#endif
static uint16_t pwm_intputs[MAX_CHN_CNT];
static uint32_t chn_count = 0;

// PWM input handler
void TIM3_IRQHandler(void)
{
    // TIM2 in STM32F3 is a 32 bit timer, to use 16 bit timer, we should change the data type to uint16_t
    timer_val_t diff;
    static timer_val_t now;
    static timer_val_t last = 0;
    static uint32_t  chan = 0;
    if (TIM_GetITStatus(TIM3, TIM_IT_CC2) == SET){
        TIM_ClearITPendingBit(TIM3, TIM_IT_CC2);
        last = now;
        now = TIM_GetCapture2(TIM2);
        diff = now - last;  // auto overflow
        if(diff > MAX_PULSE*PRESCALER/SYSFREQ_MHz ){
            chn_count = chan;
            chan = 0;
        }else{
            pwm_intputs[chan % MAX_CHN_CNT] = (uint16_t)(diff*PRESCALER/SYSFREQ_MHz);
            if(chan < MAX_CHN_CNT)
                chan++;
        }
    }
}

uint32_t get_pwm_values(uint16_t* values, uint32_t count)
{
    uint16_t* p = pwm_intputs;
    if(count > chn_count) count = chn_count;
    while(count){
        *values++ = *p++;
        count--;
    }
    return chn_count;
}



