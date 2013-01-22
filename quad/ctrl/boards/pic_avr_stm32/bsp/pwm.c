#include "pwm.h"
#include "stm32f10x.h"

void pwm_input_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
    TIM_ICInitTypeDef  TIM_ICInitStructure;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    
    /* TIM2 clock enable */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    /* GPIOB clock enable */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
      
    /* TIM2 chennel2 configuration : PA.01 */
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    /* Connect TIM pin to AF1 */
    //GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_1);

    /* Enable the TIM2 global Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    // TIM2 timebase
    TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
        
    TIM_ICInitStructure.TIM_Channel = TIM_Channel_2;
    TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
    TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
    TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
    TIM_ICInitStructure.TIM_ICFilter = 0x0;
    TIM_ICInit(TIM2, &TIM_ICInitStructure);
    
    // tim2 in STM32F3 is a 32 bit timer
    TIM_ITConfig(TIM2, TIM_IT_CC2, ENABLE);
    //TIM_PWMIConfig
    TIM_Cmd(TIM2,ENABLE);
}


void pwm_output_init(void)
{
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
void TIM2_IRQHandler(void)
{
    // TIM2 in STM32F3 is a 32 bit timer, to use 16 bit timer, we should change the data type to uint16_t
    timer_val_t diff;
    static timer_val_t now;
    static timer_val_t last = 0;
    static uint32_t  chan = 0;
    if (TIM_GetITStatus(TIM2, TIM_IT_CC2) == SET){
        TIM_ClearITPendingBit(TIM2, TIM_IT_CC2);
        last = now;
        now = TIM_GetCapture2(TIM2);
        diff = now - last;  // auto overflow
        if(diff > MAX_PULSE*72 ){
            chn_count = chan;
            chan = 0;
        }else{
            pwm_intputs[chan % MAX_CHN_CNT] = (uint16_t)(diff/72);
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



