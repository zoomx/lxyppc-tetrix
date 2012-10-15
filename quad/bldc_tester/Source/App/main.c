#include "stm32f10x.h"
#include "GLCD.h"
#include "I2C_EE.h"
#include  "usbd_hid_core.h"
#include  "usbd_usr.h"
#include  "usbd_desc.h"
#include "ring_buffer.h"

typedef enum {FAILED = 0, PASSED = !FAILED} TestStatus;

/* Private define ------------------------------------------------------------*/
#define EEPROM_WriteAddress1    0x05
#define EEPROM_ReadAddress1     0x05
#define BufferSize1             (countof(Tx1_Buffer)-1)
#define BufferSize2             (countof(Tx2_Buffer)-1)
#define EEPROM_WriteAddress2    (EEPROM_WriteAddress1 + BufferSize1)
#define EEPROM_ReadAddress2     (EEPROM_ReadAddress1 + BufferSize1)

/* Private macro -------------------------------------------------------------*/
#define countof(a) (sizeof(a) / sizeof(*(a)))

/* Private variables ---------------------------------------------------------*/
u8 Tx1_Buffer[] = "/* I2C Firmware ";
u8 Tx2_Buffer[] = "Library Example */";
u8 Rx1_Buffer[BufferSize1], Rx2_Buffer[BufferSize2];
volatile TestStatus TransferStatus1 = FAILED, TransferStatus2 = FAILED;
ErrorStatus HSEStartUpStatus;
TestStatus Buffercmp(u8* pBuffer1, u8* pBuffer2, u16 BufferLength);


void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/* Configure IO connected to LD1, LD2, LD3 and LD4 leds *********************/	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_7;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  	GPIO_Init(GPIOD, &GPIO_InitStructure);

   	/* Configure USART1 Tx (PA.09) as alternate function push-pull */
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  	GPIO_Init(GPIOA, &GPIO_InitStructure);
    
  	/* Configure USART1 Rx (PA.10) as input floating */
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

//系统中断管理
void NVIC_Configuration(void)
{ 
  	/* Configure the NVIC Preemption Priority Bits */  
  	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);

	#ifdef  VECT_TAB_RAM  
	  /* Set the Vector Table base location at 0x20000000 */ 
	  NVIC_SetVectorTable(NVIC_VectTab_RAM, 0x0); 
	#else  /* VECT_TAB_FLASH  */
	  /* Set the Vector Table base location at 0x08000000 */ 
	  NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);   
	#endif
}

//配置系统时钟,使能各外设时钟
void RCC_Configuration(void)
{
	SystemInit();	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA 
                           |RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC
                           |RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE
						   |RCC_APB2Periph_ADC1  | RCC_APB2Periph_AFIO 
                           |RCC_APB2Periph_SPI1, ENABLE );
  // RCC_APB2PeriphClockCmd(RCC_APB2Periph_ALL ,ENABLE );
     RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4 | RCC_APB1Periph_TIM3 | RCC_APB1Periph_TIM5
                           |RCC_APB1Periph_USART3|RCC_APB1Periph_TIM2	                           
                           , ENABLE );
	 RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	 /* I2C1 Periph clock enable */
  	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
}

void InitDis(void) 
{
   /* LCD Module init */
   GLCD_init();
   GLCD_clear(White);
   GLCD_setTextColor(Blue);
   GLCD_displayStringLn(Line1, "     GoldBull");
   GLCD_displayStringLn(Line2, "   EEPROM example");
   GLCD_setTextColor(Red);
}

int I2C_send_data(u8 addr, u8 d1, u8 d2)
{
  uint32_t timeout;
  /* Send START condition */
  I2C_GenerateSTART(I2C1, ENABLE);
  
  /* Test on EV5 and clear it */
  timeout = 0xffff;
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT) && timeout){ timeout--; }
  if(timeout == 0) return -1;
  /* Send EEPROM address for write */
  I2C_Send7bitAddress(I2C1, addr, I2C_Direction_Transmitter);

  /* Test on EV6 and clear it */
    timeout = 0xffff;
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED) && timeout){ timeout--; }
  if(timeout == 0) return -1;

  /* Send the EEPROM's internal address to write to */    
  I2C_SendData(I2C1, d1);  

  /* Test on EV8 and clear it */
    timeout = 0xffff;
  while(! I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED) && timeout){ timeout--; }
    if(timeout == 0) return -1;

  /* While there is data to be written */
    /* Send the current byte */
 I2C_SendData(I2C1, d2); 
  
  /* Test on EV8 and clear it */
  timeout = 0xffff;
  while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED) && timeout){ timeout--; }
  if(timeout == 0) return -1;
  
  /* Send STOP condition */
  I2C_GenerateSTOP(I2C1, ENABLE);
  return 0;
}


void init_ppm_output(void)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;
    NVIC_InitTypeDef  NVIC_InitStructure;
    
    uint16_t PrescalerValue = (uint16_t) (72000000 / 1000000) - 1;
    /* Time base configuration */
    TIM_TimeBaseStructure.TIM_Period = 20000-1;
    TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
    
    // init tim5 to 50Hz
    TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);
    
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = 500-1; // 1ms
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OC3Init(TIM3, &TIM_OCInitStructure);
    TIM_OC4Init(TIM3, &TIM_OCInitStructure);
    
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
    NVIC_Init(&NVIC_InitStructure);
    
    NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;
    NVIC_Init(&NVIC_InitStructure);
    
    TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
    TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE);
    
    TIM_Cmd(TIM5, ENABLE);
}

uint16_t   ppm_value[] = { 100, 500, 2000, 2500, 3000, 3500, 500 , 0, 0, 0};
#define PPM_BUF     (ppm_value+2)
uint32_t   ppm_idx = 0;
uint32_t   ppm_cnt = 9;
__IO uint8_t repeat_send = 0;
struct {
    uint8_t addr;
    uint8_t d1;
    uint8_t d2;
} I2C_Data [8];

void TIM3_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM3,TIM_IT_Update)){
        TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
        TIM3->ARR = ppm_value[ppm_idx];
        ppm_idx++;
        if(ppm_idx == (ppm_cnt-1)){
            TIM3->CCMR2 &= ~0x10;
        }
        if(ppm_idx == ppm_cnt){
            //uint8_t b = 0xaa;
            ppm_idx = 0;
            TIM_Cmd(TIM3, DISABLE);
            GPIOD->BRR = GPIO_Pin_2;
            if(repeat_send){
                int i;
                for(i=0;i<4;i++){
                    int r = I2C_send_data(I2C_Data[i].addr,I2C_Data[i].d1,I2C_Data[i].d2);
                    if(r) break;
                }
            }
            //I2C_send_data(&b,0x0c);
        }
    }
}

uint32_t x = 0;
void TIM5_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM5,TIM_IT_Update)){
        TIM_ClearITPendingBit(TIM5,TIM_IT_Update);
        GPIOD->BSRR = GPIO_Pin_2;
        x++;
        ppm_idx = 0;
        TIM3->CCMR2 |= 0x10;
        TIM_ARRPreloadConfig(TIM3, DISABLE);
        TIM3->ARR = ppm_value[ppm_idx];
        TIM_ARRPreloadConfig(TIM3, ENABLE);
        ppm_idx++;
        TIM3->ARR = ppm_value[ppm_idx];
        ppm_idx++;
        
        TIM_Cmd(TIM3, ENABLE);
        
    }
}

//配置所有外设
void Init_All_Periph(void)
{
	RCC_Configuration();	
	InitDis();
//	GLCD_Test();
	GPIO_Configuration();
	NVIC_Configuration();
	I2C_EE_Init();
    //init_ppm_output();
}

RCC_ClocksTypeDef RCC_Clocks;
USB_OTG_CORE_HANDLE  USB_OTG_dev;
DECLRAE_RING_BUFFER(usb_cmd);

int main(void)
{  
    ring_buf_init(usb_cmd);
	Init_All_Periph();
    USBD_Init(&USB_OTG_dev, USB_OTG_FS_CORE_ID, &USR_desc, &USBD_HID_cb, &USR_cb);

    RCC_GetClocksFreq(&RCC_Clocks);
  /* First write in the memory followed by a read of the written data --------*/
  /* Write on I2C EEPROM from EEPROM_WriteAddress1 */
  I2C_EE_BufferWrite(Tx1_Buffer, EEPROM_WriteAddress1, BufferSize1); 

  /* Read from I2C EEPROM from EEPROM_ReadAddress1 */
  I2C_EE_BufferRead(Rx1_Buffer, EEPROM_ReadAddress1, BufferSize1); 

  /* Check if the data written to the memory is read correctly */
  TransferStatus1 = Buffercmp(Tx1_Buffer, Rx1_Buffer, BufferSize1);
  /* TransferStatus1 = PASSED, if the transmitted and received data 
     to/from the EEPROM are the same */
  /* TransferStatus1 = FAILED, if the transmitted and received data 
     to/from the EEPROM are different */

  if(TransferStatus1==PASSED)
  {
  	GPIO_SetBits(GPIOD,GPIO_Pin_2);	  //写进去的数据和读出来的数据完全一样
    GLCD_displayStringLn(Line4, Rx1_Buffer);
  }
  else
  {
  	GPIO_SetBits(GPIOD,GPIO_Pin_4);	  //写进去的数据和读出来的数据不相同
	while(1);
  }
  /* Wait for EEPROM standby state */
  I2C_EE_WaitEepromStandbyState();

  /* Second write in the memory followed by a read of the written data -------*/
  /* Write on I2C EEPROM from EEPROM_WriteAddress2 */
  I2C_EE_BufferWrite(Tx2_Buffer, EEPROM_WriteAddress2, BufferSize2); 

  /* Read from I2C EEPROM from EEPROM_ReadAddress2 */
  I2C_EE_BufferRead(Rx2_Buffer, EEPROM_ReadAddress2, BufferSize2);

  /* Check if the data written to the memory is read correctly */
  TransferStatus2 = Buffercmp(Tx2_Buffer, Rx2_Buffer, BufferSize2);
  /* TransferStatus2 = PASSED, if the transmitted and received data 
     to/from the EEPROM are the same */
  /* TransferStatus2 = FAILED, if the transmitted and received data 
     to/from the EEPROM are different */
  if(TransferStatus2==PASSED)
  {
  	GPIO_SetBits(GPIOD,GPIO_Pin_3);	   //写进去的数据和读出来的数据完全一样
    GLCD_displayStringLn(Line5, Rx2_Buffer); 
  }
  else
  {
  	GPIO_SetBits(GPIOD,GPIO_Pin_7);	   //写进去的数据和读出来的数据不相同
	while(1);
  }
  GLCD_displayStringLn(Line7, " I2C TEST OK!");
  init_ppm_output();
 	while(1)
  	{
        uint8_t buf[64];
        if(ring_buf_pop(usb_cmd,buf,64)){
            // get command from usb
            switch(buf[0]){
                case 0x01: // single i2c data
                {
                    buf[63] = I2C_send_data(buf[2],buf[3],buf[4]);
                    I2C_Data[ buf[1] ].addr = buf[2];
                    I2C_Data[ buf[1] ].d1 = buf[3];
                    I2C_Data[ buf[1] ].d2 = buf[4];
                    if(buf[1]){
                        GLCD_displayStringLn(Line7, " I2C Single Data Fail!");
                    }else{
                        GLCD_displayStringLn(Line7, " I2C Single Data OK!");
                    }
                    break;
                }
                case 0x02: // all i2c data
                {
                    uint8_t i;
                    int r;
                    for(i=0;i<buf[1];i++){
                        r = I2C_send_data(buf[2+i*3],buf[3+i*3],buf[4+i*3]);
                        if(r) break;
                    }
                    for(i=0;i<buf[1];i++){
                        I2C_Data[i].addr = buf[2+i*3];
                        I2C_Data[i].d1 = buf[3+i*3];
                        I2C_Data[i].d2 = buf[4+i*3];
                    }
                    repeat_send = buf[ 2+buf[1]*3 ];
                    buf[63] = r;
                    if(buf[63]){
                        GLCD_displayStringLn(Line7, " I2C All Data Fail!");
                    }else{
                        GLCD_displayStringLn(Line7, " I2C All Data OK!");
                    }
                    break;
                }
                case 0x03: // ppm data
                {
                    uint8_t i;
                    for(i=0;i<buf[1];i++){
                        uint16_t ppm = *(uint16_t*)(buf+2*i+2);
                        ppm += 500; // add 0.5 ms
                        if(ppm > 4500) ppm = 4500; // must less than 4ms
                        PPM_BUF[i] = *(uint16_t*)(buf+2*i+2);
                    }
                    GLCD_displayStringLn(Line7, " PPM Data OK!");
                    break;
                }
            }
            USBD_HID_SendReport(&USB_OTG_dev,buf,64);
        }
  	}
}

/*******************************************************************************
* Function Name  : Buffercmp
* Description    : Compares two buffers.
* Input          : - pBuffer1, pBuffer2: buffers to be compared.
*                : - BufferLength: buffer's length
* Output         : None
* Return         : PASSED: pBuffer1 identical to pBuffer2
*                  FAILED: pBuffer1 differs from pBuffer2
*******************************************************************************/
TestStatus Buffercmp(u8* pBuffer1, u8* pBuffer2, u16 BufferLength)
{
  while(BufferLength--)
  {
    if(*pBuffer1 != *pBuffer2)
    {
      return FAILED;
    }
    
    pBuffer1++;
    pBuffer2++;
  }

  return PASSED;  
}

