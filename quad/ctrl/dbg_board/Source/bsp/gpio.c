#include "gpio.h"
#include "stm32f10x.h"
void setup_io(void)
{
    EXTI_InitTypeDef   EXTI_InitStructure;
    GPIO_InitTypeDef   GPIO_InitStructure;
    NVIC_InitTypeDef   NVIC_InitStructure;
	
    /* Enable AFIO clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC, ENABLE);
	/* Configure IO for NRF2401 CE, SPI CS *********************/	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  	GPIO_Init(GPIOA, &GPIO_InitStructure);
    
  	/* Configure IO for NRF2401 IRQ output */
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  	GPIO_Init(GPIOC, &GPIO_InitStructure);
    
    /* Configure EXTI4 Line to PA.4 pin*/
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource4);
    
    EXTI_InitStructure.EXTI_Line = EXTI_Line4;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);
    
    NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}


void EXTI4_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_Line4) != RESET)
    {
        /* Clear the  EXTI line 4 pending bit */
        EXTI_ClearITPendingBit(EXTI_Line4);
        // IRQ ready
    }
}


void nrf_ce_set(void){  GPIOA->BSRR = (1<<3); }
void nrf_ce_reset(void){  GPIOA->BRR = (1<<3); }
void nrf_cs_set(void){  GPIOA->BSRR = (1<<4); }
void nrf_cs_reset(void){  GPIOA->BRR = (1<<4); }
uint32_t nrf_irq(void) { return (GPIOC->IDR & (1<<4)) >> 4; }


void nrf_ce_reset(void);
void nrf_cs_set(void);
void nrf_cs_reset(void);
