#include "gpio.h"

void setup_io_l3gd20(void)
{
    EXTI_InitTypeDef   EXTI_InitStructure;
    GPIO_InitTypeDef   GPIO_InitStructure;
    NVIC_InitTypeDef   NVIC_InitStructure;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	
	/* Configure IO for NRF2401 CE, SPI CS *********************/	
	//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
  	//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  	//GPIO_Init(GPIOA, &GPIO_InitStructure);
    //GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    //GPIO_Init(GPIOB, &GPIO_InitStructure);
    
  	/* Configure IO for NRF2401 IRQ output */
  	//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    //GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  	//GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    /* Configure EXTI4 Line to PA.4 pin*/
    //GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource8);
    
    /* configure IO for l3gd20 CS, INT1, INT2*/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOE, &GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOE, &GPIO_InitStructure);
    
    
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource0);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource1);
  
    EXTI_InitStructure.EXTI_Line = EXTI_Line0;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);
    
    EXTI_InitStructure.EXTI_Line = EXTI_Line1;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);
    
    NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

void setup_io_lsm303dlhc(void)
{
    EXTI_InitTypeDef   EXTI_InitStructure;
    GPIO_InitTypeDef   GPIO_InitStructure;
    NVIC_InitTypeDef   NVIC_InitStructure;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
    /* configure IO for lsm303dlhc INT1, INT2, DRDY*/
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOE, &GPIO_InitStructure);
    
    
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource2);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource4);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource5);
  
    EXTI_InitStructure.EXTI_Line = EXTI_Line2;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);
    
    EXTI_InitStructure.EXTI_Line = EXTI_Line4;
    EXTI_Init(&EXTI_InitStructure);
    EXTI_InitStructure.EXTI_Line = EXTI_Line5;
    EXTI_Init(&EXTI_InitStructure);
    
    
    NVIC_InitStructure.NVIC_IRQChannel = EXTI2_TS_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

void setup_io_nrf24l01(void)
{
    //EXTI_InitTypeDef   EXTI_InitStructure;
    //GPIO_InitTypeDef   GPIO_InitStructure;
    //NVIC_InitTypeDef   NVIC_InitStructure;
    
    //RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	
	/* Configure IO for NRF2401 CE, SPI CS *********************/	
	//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
  	//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  	//GPIO_Init(GPIOA, &GPIO_InitStructure);
    //GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    //GPIO_Init(GPIOB, &GPIO_InitStructure);
    
  	/* Configure IO for NRF2401 IRQ output */
  	//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    //GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  	//GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    /* Configure EXTI4 Line to PA.4 pin*/
    //SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource3);
  
    //EXTI_InitStructure.EXTI_Line = EXTI_Line3;
    //EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    //EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
    //EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    //EXTI_Init(&EXTI_InitStructure);
    
    //NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;
    //NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
    //NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
    //NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    //NVIC_Init(&NVIC_InitStructure);
}


void setup_io_leds(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
  
  /* Enable the GPIO_LED Clock */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);

  /* Configure the GPIO_LED pin */
  GPIO_InitStructure.GPIO_Pin = 
    GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | 
    GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
}

// IO IRQ handlers
void EXTI0_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_Line0) != RESET){
        EXTI_ClearITPendingBit(EXTI_Line0);
        // l3gd20_int1_irq_handler();
    }
}

__IO uint32_t d_tick;
void EXTI1_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_Line1) != RESET){
        EXTI_ClearITPendingBit(EXTI_Line1);
        // l3gd20_int2_irq_handler();
        {
            static uint32_t last_tick = 0;
            uint32_t cur_tick = get_tick_count();
            d_tick = cur_tick - last_tick;
            last_tick = cur_tick;
        }
    }
}

void EXTI2_TS_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_Line2) != RESET){
        EXTI_ClearITPendingBit(EXTI_Line2);
        // lsm303dlhc_drdy_irq_handler();
    }
}

void EXTI4_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_Line4) != RESET){
        EXTI_ClearITPendingBit(EXTI_Line4);
        // lsm303dlhc_int1_irq_handler();
    }
}

void EXTI9_5_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_Line5) != RESET)
    {
        /* Clear the  EXTI line 8 pending bit */
        EXTI_ClearITPendingBit(EXTI_Line5);
        // lsm303dlhc_int2_irq_handler();
        // IRQ ready
        //nrf_irq_handler();
    }
}



