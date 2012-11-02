#include "pwm.h"
#include "stm32f0xx.h"
#include "simple_io.h"

// Initialize the PWM, PWM will also used to sync the ADC
// TIM1 is used to output PWM, TIM1 CC4 used to sync ADC
#define GET_DUTY(percent)   \
      (uint16_t)((((uint32_t)percent) * ((SYSTEM_FREQ/PWM_FREQ) - 1) ) / 100)
#define PWM_PERIOD        (SYSTEM_FREQ/PWM_FREQ)
      
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
    
    TIM_OCInitStructure.TIM_OCMode = TIM_ForcedAction_InActive;
    // We may disable these output after initialize
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Disable;
    TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
    
    TIM_OCInitStructure.TIM_Pulse = GET_DUTY(0); // 5%
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_Low;
    TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
    TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Set;
    
    TIM_OC1Init(TIM1, &TIM_OCInitStructure);
		//TIM_OCInitStructure.TIM_Pulse = GET_DUTY(30); // 5%
    TIM_OC2Init(TIM1, &TIM_OCInitStructure);
		//TIM_OCInitStructure.TIM_Pulse = GET_DUTY(10); // 5%
    TIM_OC3Init(TIM1, &TIM_OCInitStructure);
    // TIM4 CH4 is used to triggrt the ADC
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = GET_DUTY(1); // 5%
    TIM_OC4Init(TIM1, &TIM_OCInitStructure);
    
    //TIM_ForcedOC1Config(TIM1, TIM_ForcedAction_InActive);
    //TIM_ForcedOC2Config(TIM1, TIM_ForcedAction_InActive);
    //TIM_ForcedOC3Config(TIM1, TIM_ForcedAction_InActive);
    
    TIM1->BDTR |= (TIM_OSSRState_Enable | TIM_OSSIState_Enable);
    
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_2);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_2);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_2);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource11, GPIO_AF_2);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_2);
    
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource0, GPIO_AF_2);
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource1, GPIO_AF_2);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    // We need update the timer settings by COM event
    // In this case, TIM15 and TIM17 can be used as COM trigger
    TIM_CCPreloadControl(TIM1, ENABLE);
    // Select TIM15 as the trigger
    TIM_SelectInputTrigger(TIM1, TIM_TS_ITR0);
    TIM_SelectMasterSlaveMode(TIM1, TIM_MasterSlaveMode_Enable);
    TIM_SelectCOM(TIM1, ENABLE);
    // Sometimes I will use the update event to trigger the ADC
    TIM_SelectOutputTrigger(TIM1, TIM_TRGOSource_Update);
    
    NVIC_InitStructure.NVIC_IRQChannel = TIM1_BRK_UP_TRG_COM_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    NVIC_InitStructure.NVIC_IRQChannel = TIM1_CC_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    TIM_ITConfig(TIM1, TIM_IT_COM, ENABLE);
    //TIM_ITConfig(TIM1, TIM_IT_CC4, ENABLE);
    
    TIM_Cmd(TIM1, ENABLE);
    /* TIM1 Main Output Enable */
    TIM_CtrlPWMOutputs(TIM1, ENABLE);
    
    //set_duty(1199);
    // close all channel
    //pwm_force_output(2,2,2);
    init_tim15();
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
/*
#define  A_B    ENABLE_TIM(AP|BN)    
#define  C_B    ENABLE_TIM(CP|BN)
#define  C_A    ENABLE_TIM(CP|AN)
#define  B_A    ENABLE_TIM(BP|AN)
#define  B_C    ENABLE_TIM(BP|CN)
#define  A_C    ENABLE_TIM(AP|CN)
*/


int32_t dir = 1;
int32_t step = 1;
uint16_t update_rate = 0;
isr_callback_t  on_phase_update_done = 0;
isr_callback_t  on_tim1_cc4 = 0;
#define SET_PIN(port,pin)   GPIO##port->BSRR = GPIO_Pin_##pin
#define RESET_PIN(port,pin)   GPIO##port->BRR = GPIO_Pin_##pin


void TIM1_BRK_UP_TRG_COM_IRQHandler(void)
{
    TIM_ClearITPendingBit(TIM1, TIM_IT_COM);
    if(on_phase_update_done){
        on_phase_update_done();
    }
}

void TIM1_CC_IRQHandler(void)
{
    // here I use CC4 to gather the ADC data
    TIM_ClearITPendingBit(TIM1, TIM_IT_CC4);
    if(on_tim1_cc4){
        on_tim1_cc4();
    }
}

void switch_phase_6_step(void)
{
    if(update_rate){
        TIM15->ARR = update_rate;
        update_rate = 0;
    }
    TP3_TOGGLE;
    // Here to prepare data for next step
    if(dir>0) dir = 1;
    if(dir<0) dir = -1;
    switch(step){
        case 1:
            SET_PIN(A,15);
            update_pwm(A_B);
            step += dir;
            break;
        case 2:
            RESET_PIN(A,15);
            update_pwm(C_B);
            step += dir;
            break;
        case 3:
            update_pwm(C_A);
            step += dir;
            break;
        case 4:
            update_pwm(B_A);
            step += dir;
            break;
        case 5:
            update_pwm(B_C);
            step += dir;
            break;
        case 6:
            update_pwm(A_C);
            step += dir;
            break;
    }
    if(step>6){
        step = 1;
    }else if(step < 1){
        step = 6;
    }
}


void set_update_rate(uint16_t rate)
{
    update_rate = rate;
}

// Here I use the tim15 as the COM trigger for tim1
// TIM15 can use DMA channel 5 to update it's pre-load values
void init_tim15(void)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    //NVIC_InitTypeDef         NVIC_InitStructure;
    
    TIM_TimeBaseStructure.TIM_Period = 200-1;// 50Hz 0xFFFF;
    TIM_TimeBaseStructure.TIM_Prescaler = 1000; //Down to 48K//(uint16_t) (SystemCoreClock / 24000000) - 1;
    TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;    
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;   
    TIM_TimeBaseInit(TIM15, &TIM_TimeBaseStructure);
    
    /* Select the Master Slave Mode */
    TIM_SelectMasterSlaveMode(TIM15, TIM_MasterSlaveMode_Enable);

    /* Master Mode selection */
    TIM_SelectOutputTrigger(TIM15, TIM_TRGOSource_Update);
    
    //NVIC_InitStructure.NVIC_IRQChannel = TIM15_IRQn;
    //NVIC_InitStructure.NVIC_IRQChannelPriority = 1;
    //NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    //NVIC_Init(&NVIC_InitStructure);
    //TIM_ITConfig(TIM15, TIM_IT_Update, ENABLE);
    
    // enable tim15
    //TIM_Cmd(TIM15, ENABLE);
}

// setup the phase update freq, when phase update success
// it will invoke the 
void set_phase_update_freq(uint32_t freq, isr_callback_t callback)
{
    // TIM15 is used to update the phase
    uint32_t arr;
    uint32_t psc = 1;
    on_phase_update_done = callback;
    TIM_Cmd(TIM15, DISABLE);
    if(freq == 0) return;
    arr = SYSTEM_FREQ/freq;
    while(arr> 0xffff){
        arr>>=1;
        psc<<=1;
    }
    
    TIM15->ARR = arr-1;
    TIM15->PSC = psc-1;
    TIM_Cmd(TIM15, ENABLE);
}

// to make sure tim15 is running
void TIM15_IRQHandler(void)
{
    TIM_ClearITPendingBit(TIM15, TIM_IT_Update);
    // TIM15 is running
}

const uint16_t enTable_high_pwm[] = {
    AP, AP|AN, AN, AN,
    BP, BP|BN, BN, BN,
    CP, CP|CN, CN, CN,
};

const uint16_t enTable_low_pwm[] = {
    AN, AP|AN, AN, AN,
    BN, BP|BN, BN, BN,
    CN, CP|CN, CN, CN,
};

const uint16_t modeTable_high_pwm[] = {
    TIM_OCMode_PWM1, TIM_ForcedAction_InActive, TIM_ForcedAction_InActive , TIM_ForcedAction_InActive,
    TIM_OCMode_PWM1<<8, TIM_ForcedAction_InActive<<8, TIM_ForcedAction_InActive<<8, TIM_ForcedAction_InActive<<8,
};
const uint16_t modeTable_low_pwm[] = {
    TIM_OCMode_PWM1, TIM_ForcedAction_Active, TIM_ForcedAction_InActive , TIM_ForcedAction_InActive,
    TIM_OCMode_PWM1<<8, TIM_ForcedAction_Active<<8, TIM_ForcedAction_InActive<<8, TIM_ForcedAction_InActive<<8,
};

#if PWM_MODE
#define  enTable     enTable_high_pwm
#define modeTable   modeTable_high_pwm
#else
#define modeTable   modeTable_low_pwm
#define modeTable   modeTable_low_pwm
#endif

#define enTableA    (enTable)
#define enTableB    (enTable+4)
#define enTableC    (enTable+8)
#define PWM_MASK     (~0xFFF)
#define modeTableA   (modeTable)
#define modeTableB   (modeTable+4)

static __IO uint16_t tr;

void update_pwm(uint8_t a, uint8_t b, uint8_t c)
{
    uint16_t ccer = 0;
    TIM1->CCER &= ALL_OFF;
    ccer = enTableA[a&3] | enTableB[b&3] | enTableC[c&3];
    TIM1->CCER |= ccer;
    
    TIM1->CCMR1 &= ~0x7070;
    TIM1->CCMR1 |= modeTableA[a&3] | modeTableB[b&3];
    TIM1->CCMR2 &= ~0x70;
    TIM1->CCMR2 |= modeTableA[c&3];
}

void pwm_force_output(uint8_t a, uint8_t b, uint8_t c)
{
    update_pwm(a,b,c);
    TIM_GenerateEvent(TIM1, TIM_EventSource_COM);
}

void pwm_force_output_unused(uint8_t a, uint8_t b, uint8_t c)
{
    uint16_t ccer = 0;
    /*
    uint16_t ccer = (a & 0xf ? 0 : AP) | (a & 0xf0 ? 0 : AN)
                  | (b & 0xf ? 0 : BP) | (b & 0xf0 ? 0 : BN)
                  | (c & 0xf ? 0 : CP) | (c & 0xf0 ? 0 : CN);
    ;
    
    TIM1->CCER &= ALL_OFF;
    TIM1->CCER |= ccer;
    */
    TIM1->CCER &= ALL_OFF;
    TIM1->CCMR1 &= ~0x7070;
    TIM1->CCMR2 &= ~0x70;
    ccer = enTableA[a&3] | enTableB[b&3] | enTableC[c&3];
    TIM1->CCER |= ccer;
    TIM1->CCMR1 |= modeTableA[a&3] | modeTableB[b&3];
    TIM1->CCMR2 |= modeTableA[c&3];
    /*
    switch(a){
        case 0:
            // +PWM -OFF
            ccer |= AP;
            TIM1->CCMR1 |= TIM_OCMode_PWM1;
            break;
        case 1:
            // +OFF -ON
            ccer |= (AP | AN);
            break;
        default:
            // +OFF -OFF
            ccer |= AN;
            break;
    }
    switch(b){
        case 0:
            // +PWM  -OFF
            ccer |= BP;
            TIM1->CCMR1 |= (TIM_OCMode_PWM1<<8);
            break;
        case 1:
            // +OFF  -ON
            ccer |= (BP | BN);
            break;
        default:
            // +OFF -OFF
            ccer |= BN;
            break;
    }
    
    

    switch(c){
        case 0:
            // +PWM  -OFF
            ccer |= CP;
            TIM1->CCMR2 |= (TIM_OCMode_PWM1);
            break;
        case 1:
            // +OFF  -ON
            ccer |= (CP | CN);
            break;
        default:
            // +OFF -OFF
            ccer |= CN;
            break;
    }
    */
    
    
    /*
    if(a & 0xf){
        TIM_CCxCmd(TIM1, TIM_Channel_1, TIM_CCx_Disable);
    }else{
        TIM_CCxCmd(TIM1, TIM_Channel_1, TIM_CCx_Enable);
    }
    if(a & 0xf0){
        TIM_CCxNCmd(TIM1, TIM_Channel_1, TIM_CCxN_Disable);
    }else{
        TIM_CCxNCmd(TIM1, TIM_Channel_1, TIM_CCxN_Enable);
    }
    
    if(b & 0xf){
        TIM_CCxCmd(TIM1, TIM_Channel_2, TIM_CCx_Disable);
    }else{
        TIM_CCxCmd(TIM1, TIM_Channel_2, TIM_CCx_Enable);
    }
    if(b & 0xf0){
        TIM_CCxNCmd(TIM1, TIM_Channel_2, TIM_CCxN_Disable);
    }else{
        TIM_CCxNCmd(TIM1, TIM_Channel_2, TIM_CCxN_Enable);
    }
    
    if(c & 0xf){
        TIM_CCxCmd(TIM1, TIM_Channel_3, TIM_CCx_Disable);
    }else{
        TIM_CCxCmd(TIM1, TIM_Channel_3, TIM_CCx_Enable);
    }
    if(c & 0xf0){
        TIM_CCxNCmd(TIM1, TIM_Channel_3, TIM_CCxN_Disable);
    }else{
        TIM_CCxNCmd(TIM1, TIM_Channel_3, TIM_CCxN_Enable);
    }
    */
    /*
    tr = TIM1->CCER;
    TIM1->CCER = tr;
    
    tr = TIM1->CR2;
    TIM1->CR2 = tr;
    
    tr = TIM1->CCMR1;
    TIM1->CCMR1 = tr;
    
    tr = TIM1->CCMR2;
    TIM1->CCMR2 = tr;
    */
    
}

void set_duty(uint16_t duty, uint16_t cc4_duty)
{
    TIM1->CCR1 = duty;
    TIM1->CCR2 = duty;
    TIM1->CCR3 = duty;
    TIM1->CCR4 = cc4_duty; // also set the ADC trigger time
    //if(duty > PWM_PERIOD/2){
    //    TIM1->CCR4 = 100; // wait 2us 100*48MHz = 2us
    //}else{
    //    TIM1->CCR4 = PWM_PERIOD/2+100; // wait half + 2us
    //}
    //TIM1->CCR4 = 48;//600;//96; // wait 1us
}


