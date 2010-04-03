#ifndef BSP_H
#define BSP_H


#define   SSD_Clk         GPIOB,GPIO_Pin_13
#define   SSD_Data        GPIOB,GPIO_Pin_15
#define   SSD_Reset       GPIOD,GPIO_Pin_12
#define   SSD_A0          GPIOD,GPIO_Pin_14
#define   SSD_CS          //GPIOG,GPIO_Pin_2

#define   SSD_Clk_Low()     GPIOB->BRR = GPIO_Pin_13
#define   SSD_Clk_High()    GPIOB->BSRR = GPIO_Pin_13
#define   SSD_Data_Low()    GPIOB->BRR = GPIO_Pin_15
#define   SSD_Data_High()   GPIOB->BSRR = GPIO_Pin_15
#define   SSD_Reset_Low()   GPIOB->BRR = GPIO_Pin_12
#define   SSD_Reset_High()  GPIOB->BSRR = GPIO_Pin_12
#define   SSD_A0_Low()      GPIOB->BRR = GPIO_Pin_14
#define   SSD_A0_High()     GPIOB->BSRR = GPIO_Pin_14
#define   SSD_CS_Low()      //GPIOG->BRR = GPIO_Pin_2
#define   SSD_CS_High()     //GPIOG->BSRR = GPIO_Pin_2

#define   SPI_SendByte(data)  SPI2->DR = (data)
#define   SPI_Wait()           while(!(SPI2->SR&SPI_I2S_FLAG_TXE));while(SPI2->SR&SPI_I2S_FLAG_BSY);

#define   GSel1_High()    GPIOB->BSRR = GPIO_Pin_9
#define   GSel1_Low()     GPIOB->BRR = GPIO_Pin_9
#define   GSel2_High()    GPIOB->BSRR = GPIO_Pin_8
#define   GSel2_Low()     GPIOB->BRR = GPIO_Pin_8

#define   MMA_SLEEP()     GPIOB->BRR = GPIO_Pin_11
#define   MMA_WAKEUP()    GPIOB->BSRR = GPIO_Pin_11
#define   Is_MMA_WAKEUP() (GPIOB->ODR & GPIO_Pin_11)

#define   IsLedOn()       (!(GPIOA->ODR & GPIO_Pin_8))
#define   LED_ON()        GPIOA->BRR = GPIO_Pin_8
#define   LED_OFF()       GPIOA->BSRR = GPIO_Pin_8
#define   ToggleLED()     if(GPIOA->ODR & GPIO_Pin_8){GPIOA->BRR = GPIO_Pin_8;}\
                          else{GPIOA->BSRR = GPIO_Pin_8;}


#define   AD_CH_BAT       ADC_Channel_4
#define   AD_CH_X         ADC_Channel_1
#define   AD_CH_Y         ADC_Channel_2
#define   AD_CH_Z         ADC_Channel_3
#define   AD_CH_CHG       ADC_Channel_9
#define   AD_CH_REF       ADC_Channel_17

#define   DMA_SSD_1303    DMA1_Channel5
#define   DMA_Handler_SSD_1303    DMA1_Channel5_IRQHandler
#define   DMA_ADC         DMA1_Channel1

typedef   struct  _ADResult_t
{
  u16   ADRef;    // ADC1 
  u16   ADX;      // ADC1
  u16   ADY;      // ADC2
  u16   ADZ;      // ADC1
}ADResult_t;

extern  ADResult_t  ADCResult;

#endif
