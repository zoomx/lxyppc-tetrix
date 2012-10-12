#include "simple_io.h"
#include "stm32f0xx.h"

// Initial IO for address setting
// ADDR0 -> PF1  ADDR1 -> PF0  ADDR2->PB8, must config as input pull-up
void init_addr_config(void)
{
    GPIO_InitTypeDef        GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOF, &GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
}

// Initial IO for leds
// PB4(TIM3 CH1) -> LED1, PB5(TIM3 CH2) -> LED2
void init_led(void)
{
    GPIO_InitTypeDef        GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_OCInitTypeDef        TIM_OCInitStructure;
    
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_1);
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_1);
    
    TIM_TimeBaseStructure.TIM_Period = 99;          
    TIM_TimeBaseStructure.TIM_Prescaler = (uint16_t) (SystemCoreClock / 240000) - 1;       
    TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;    
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;   
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
    
    TIM_OCInitStructure.TIM_OCMode =  TIM_OCMode_PWM1;    
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;          
    TIM_OCInitStructure.TIM_Pulse = 1;//0xFFFF;  
    TIM_OC1Init(TIM3, &TIM_OCInitStructure);
    
    TIM_OCInitStructure.TIM_Pulse = 1;//0xFFFF;
    TIM_OC2Init(TIM3, &TIM_OCInitStructure); 

    /* TIM3 enable */
    TIM_Cmd(TIM3, ENABLE);
  
    /* TIM3 PWM Outputs Enable */
    TIM_CtrlPWMOutputs(TIM3, ENABLE);
}

uint8_t get_i2c_addr(void)
{
    // I2C addr can be config by the addr0,1,2 pin
    uint16_t add = GPIO_ReadInputData(GPIOF) & 0x03; // PF0->add1, PF1->add0
    add = ((add>>1) | (add<<1)) & 0x03;
    if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)){  // PB8, addr2
        add |= 0x04;
    }
    return add | 0x50;
}

void adj_led(uint8_t led1, uint8_t led2)
{
    if(led1<=100){
        TIM3->CCR1 = 100-led1;
    }
    if(led2<=100){
        TIM3->CCR2 = 100-led2;
    }
}

void init_tps(void)
{
    GPIO_InitTypeDef        GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}
