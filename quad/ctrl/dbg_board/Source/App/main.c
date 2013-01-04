#include "stm32f10x.h"
#include "GLCD.h"
#include "I2C_EE.h"
#include  "usbd_hid_core.h"
#include  "usbd_usr.h"
#include  "usbd_desc.h"
#include "ring_buffer.h"
#include "nrf24l01.h"
#include "nrf24l01_config.h"
#include "math.h"

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

int I2C_recv_cmd_data(u8 addr, u8 cmd, u8 len, u8* data)
{
  uint32_t timeout;
  /* Send START condition */
  I2C_GenerateSTART(I2C1, ENABLE);
  
  /* Test on EV5 and clear it */
  timeout = 0xffff;
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT) && timeout){ timeout--; }
  if(timeout == 0) return 1;
  /* Send EEPROM address for write */
  I2C_Send7bitAddress(I2C1, addr, I2C_Direction_Transmitter);

  /* Test on EV6 and clear it */
  timeout = 0xffff;
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED) && timeout){ timeout--; }
  if(timeout == 0) return 2;

  /* Clear EV6 by setting again the PE bit */
  I2C_Cmd(I2C1, ENABLE);

  /* Send the EEPROM's internal address to write to */    
  I2C_SendData(I2C1, cmd);  

  /* Test on EV8 and clear it */
    timeout = 0xffff;
  while(! I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED) && timeout){ timeout--; }
    if(timeout == 0) return 3;

  /* While there is data to be written */
  /* Send the current byte */
  I2C_SendData(I2C1, len); 
  
  /* Test on EV8 and clear it */
  timeout = 0xffff;
  while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED) && timeout){ timeout--; }
  if(timeout == 0) return 4;
  
  /* Send START condition */
  I2C_GenerateSTART(I2C1, ENABLE);
  /* Test on EV5 and clear it */
  timeout = 0xffff;
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT) && timeout){ timeout--; }
  if(timeout == 0) return 5;
  
  /* Send EEPROM address for write */
  I2C_Send7bitAddress(I2C1, addr, I2C_Direction_Receiver);

  /* Test on EV6 and clear it */
  timeout = 0xffff;
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED) && timeout){ timeout--; }
  if(timeout == 0) return 6;
  
  /* While there is data to be read */
  timeout = 0xffff;
  while(len)  
  {
    if(len == 1)
    {
      /* Disable Acknowledgement */
      I2C_AcknowledgeConfig(I2C1, DISABLE);
      
      /* Send STOP Condition */
      I2C_GenerateSTOP(I2C1, ENABLE);
    }

    /* Test on EV7 and clear it */
    if(I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED))  
    {      
      timeout = 0xffff;
      /* Read a byte from the EEPROM */
      *data = I2C_ReceiveData(I2C1);

      /* Point to the next location where the byte read will be saved */
      data++; 
      
      /* Decrement the read bytes counter */
      len--;        
    }else{
        timeout--;
        if(timeout == 0){
            return 7;
        }
    }
  }
  
  /* Enable Acknowledgement to be ready for another reception */
  I2C_AcknowledgeConfig(I2C1, ENABLE);
  return 0;
}

int I2C_send_cmd_data(u8 addr, u8 cmd, u8 len, const u8* data)
{
  uint32_t timeout;
  /* Send START condition */
  I2C_GenerateSTART(I2C1, ENABLE);
  
  /* Test on EV5 and clear it */
  timeout = 0xffff;
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT) && timeout){ timeout--; }
  if(timeout == 0) return 1;
  /* Send EEPROM address for write */
  I2C_Send7bitAddress(I2C1, addr, I2C_Direction_Transmitter);

  /* Test on EV6 and clear it */
  timeout = 0xffff;
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED) && timeout){ timeout--; }
  if(timeout == 0) return 2;

  /* Send the EEPROM's internal address to write to */    
  I2C_SendData(I2C1, cmd);  

  /* Test on EV8 and clear it */
    timeout = 0xffff;
  while(! I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED) && timeout){ timeout--; }
    if(timeout == 0) return 3;

  /* While there is data to be written */
  /* Send the current byte */
  I2C_SendData(I2C1, len); 
  
  /* Test on EV8 and clear it */
  timeout = 0xffff;
  while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED) && timeout){ timeout--; }
  if(timeout == 0) return 4;
  
  while(len){
    I2C_SendData(I2C1, *data); 
    timeout = 0xffff;
    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED) && timeout){ timeout--; }
    if(timeout == 0) return 5;
    len--;
    data++;
  }
  
  /* Send STOP condition */
  I2C_GenerateSTOP(I2C1, ENABLE);
  return 0;
}

int I2C_send_data(u8 addr, u8 d1, u8 d2)
{
  uint32_t timeout = 0xff;
  //I2C_SoftwareResetCmd(I2C1, ENABLE);
  //while(timeout--);
  //I2C_SoftwareResetCmd(I2C1, DISABLE);
  /* Send START condition */
  I2C_GenerateSTART(I2C1, ENABLE);
  
  /* Test on EV5 and clear it */
  timeout = 0xffff;
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT) && timeout){ timeout--; }
  if(timeout == 0) return 1;
  /* Send EEPROM address for write */
  I2C_Send7bitAddress(I2C1, addr, I2C_Direction_Transmitter);

  /* Test on EV6 and clear it */
    timeout = 0xffff;
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED) && timeout){ timeout--; }
  if(timeout == 0) return 2;

  /* Send the EEPROM's internal address to write to */    
  I2C_SendData(I2C1, d1);  

  /* Test on EV8 and clear it */
    timeout = 0xffff;
  while(! I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED) && timeout){ timeout--; }
    if(timeout == 0) return 3;

  /* While there is data to be written */
    /* Send the current byte */
 I2C_SendData(I2C1, d2); 
  
  /* Test on EV8 and clear it */
  timeout = 0xffff;
  while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED) && timeout){ timeout--; }
  if(timeout == 0) return 4;
  
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
void I2C_Configuration(void);
const uint8_t addr[] = RX_ADDR0;
void nrf_test_reg(void);
uint8_t rx_buf[32] = {0};
const char* str_buf[] = {
    "get:  0","get:  1","get:  2","get:  3","get:  4","get:  5","get:  6","get:  7",
    "get:  8","get:  9","get: 10","get: 11","get: 12","get: 13","get: 14","get: 15",
    "get: 16","get: 17","get: 18","get: 19","get: 20","get: 21","get: 22","get: 23",
    "get: 24","get: 25","get: 26","get: 27","get: 28","get: 29","get: 30","get: 31",
    "get: 32","get: 33","get: 34","get: 35","get: 36","get: 37","get: 38","get: 39",
};

static uint8_t tx_done = 0;
void nrf_tx_done(uint8_t success)
{
    if(success == NRF_TX_FAIL){
        tx_done = 1;
    }else if(success == NRF_ACK_SUCCESS){
        tx_done = 3;
    }else{
        tx_done = 2;
    }
}

float attitude[4] = {3.14159, -1.111, -2.22222, 1000};// X,Y,Z,Thro
float motor[4] = {100, 200, 300, 400}; // 1,2,3,4
int32_t sensors_1[6] = {0};
int16_t sensors_2[3] = {0};
int16_t sensors[9] = {0};
#define  DT_ATT         1
#define  DT_SENSOR      2
#define  SET_ATT        1
#define  SET_MOTOR      2
#define  SET_MODE       3

static uint8_t rx_done = 0;
static uint8_t rx_len;
uint8_t rx_chn;
uint8_t rx_detail[256];
uint8_t idx = 0;
void nrf_on_rx_data(const void* p, uint32_t len, uint8_t channel)
{
    const uint8_t* data = (const uint8_t*)p;
    rx_done = 1;
    rx_len = len;
    rx_chn = channel;
    rx_detail[idx++] = len;
    if(data[0] == DT_ATT){
        int16_t motor_val[4];
        memcpy(attitude,data+1,sizeof(attitude));
        memcpy(motor_val,data+17,8);
        motor[0] = motor_val[0];
        motor[1] = motor_val[1];
        motor[2] = motor_val[2];
        motor[3] = motor_val[3];
    }else if(data[0] == DT_SENSOR){
        memcpy(sensors_1,data+1,24);
        memcpy(sensors_2,data+25,6);
        sensors[0] = sensors_1[0];
        sensors[1] = sensors_1[1];
        sensors[2] = sensors_1[2];
        sensors[3] = sensors_1[3];
        sensors[4] = sensors_1[4];
        sensors[5] = sensors_1[5];
        sensors[6] = sensors_2[0];
        sensors[7] = sensors_2[1];
        sensors[8] = sensors_2[2];
    }
}



static uint32_t report_mode = DT_ATT;

void process_quad_data(void)
{
    uint8_t buf[64];
    if(ring_buf_pop(usb_cmd,buf,64)){
        switch(buf[0]){
            case SET_ATT: // attitude data
                memcpy(attitude,buf+1,sizeof(attitude));
                break;
            case SET_MOTOR: // motor data
                memcpy(motor,buf+1,sizeof(motor));
                break;
            case SET_MODE:
                report_mode = buf[1];
                break;
        }
    }
}


static __IO uint32_t frame_1Hz = 0;
static __IO uint32_t frame_10Hz = 0;
static __IO uint32_t frame_50Hz = 0;
void SysTick_Handler(void)
{
    static uint32_t tick_1Hz = 0;
    static uint32_t tick_10Hz = 0;
    static uint32_t tick_50Hz = 0;
    tick_1Hz++;
    if(tick_1Hz == 1000){
        tick_1Hz = 0;
        frame_1Hz = 1;
    }
    tick_10Hz++;
    if(tick_10Hz == 100){
        tick_10Hz = 0;
        frame_10Hz = 1;
    }
    tick_50Hz++;
    if(tick_50Hz == 20){
        tick_50Hz = 0;
        frame_50Hz = 1;
    }
}

int main(void)
{  
    ring_buf_init(usb_cmd);
	Init_All_Periph();
    USBD_Init(&USB_OTG_dev, USB_OTG_FS_CORE_ID, &USR_desc, &USBD_HID_cb, &USR_cb);

    RCC_GetClocksFreq(&RCC_Clocks);
    nrf_init();
    nrf_detect();
    
    GLCD_displayStringLn(Line7, " Set RX mode");
    //nrf_rx_mode_no_aa(addr, 5, 16, 40);
    //nrf_tx_mode_no_aa(addr, 5, 40);
    //nrf_tx_mode(addr, 5, 40);
    nrf_tx_mode_dual(addr, 5, 40);
         
    {
        uint8_t status = nrf_read_reg(NRF_STATUS);
        nrf_write_reg(NRF_FLUSH_RX, 0xff);
        nrf_write_reg(NRF_FLUSH_TX, 0xff);
        nrf_write_reg(NRF_WRITE_REG|NRF_STATUS,status); // clear IRQ flags
    }
    //nrf_test_reg();
    while(1){
        if(frame_10Hz){
            uint8_t rx_av;
            static __IO uint32_t cnt = 0;
            cnt++;
            frame_10Hz = 0;
            //if(cnt&1)
            //    GLCD_displayStringLn(Line8, " 1");
            //else
            //    GLCD_displayStringLn(Line8, " 2");
            
            //nrf_tx_packet(addr, 16);
            rx_av = nrf_test_carrier();
            
            //rx_av = nrf_read_reg(NRF_STATUS);
            rx_buf[0] = SET_MODE;
            rx_buf[1] = report_mode;
            nrf_tx_packet_no_wait(rx_buf, 4);
            //if(nrf_rx_packet(rx_buf,16) == NRF_RX_OK)
            {
            //    GLCD_displayStringLn(Line5, (unsigned char*)str_buf[rx_buf[0]&15]);
            }
            {
                uint8_t buf[64];
                switch(report_mode){
                    case DT_ATT:
                        buf[0] = DT_ATT;
                        memcpy(buf+1,attitude,sizeof(attitude));
                        memcpy(buf+1+sizeof(attitude),motor,sizeof(motor));
                        break;
                    case DT_SENSOR:
                    {
                        /*
                        static float d = 0.0;
                        uint32_t i;
                        int16_t sensors[9] = {
                            -1,-2,-3,
                            100,200,300,
                            -250,-251,-252,
                        };
                        for(i=0;i<9;i++){
                            sensors[i] = sinf(d+i*0.3)*500;
                        }
                        d += 0.2;
                        */
                        buf[0] = DT_SENSOR;
                        memcpy(buf+1,sensors,sizeof(sensors));
                    }
                        break;
                }
                USBD_HID_SendReport(&USB_OTG_dev,buf,64);
            }
        }
        
        if(tx_done){
            if(tx_done == 1){
                GLCD_displayStringLn(Line8, " Tx Fail   ");
            }else if(tx_done == 2){
                GLCD_displayStringLn(Line8, " Tx Success");
            }else{
                GLCD_displayStringLn(Line8, " Ack Success");
            }
            tx_done = 0;
        }
        if(rx_done){
            rx_done = 0;
            GLCD_displayStringLn(Line5, (unsigned char*)str_buf[rx_chn&15]);
            GLCD_displayStringLn(Line6, (unsigned char*)str_buf[rx_len&31]);
        }
        
        process_quad_data();
        //rx_av = nrf_rx_available();
    }
    
    
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
                        ppm += 1000; // add 0.5 ms
                        if(ppm > 3000) ppm = 3000; // must less than 4ms
                        PPM_BUF[i] = ppm;
                    }
                    GLCD_displayStringLn(Line7, " PPM Data OK!");
                    break;
                }
                case 0x04: // send i2c data
                {
                    buf[63] = I2C_send_cmd_data(buf[1],buf[2],buf[3], buf+4);
                    break;
                }
                case 0x05: // read i2c data
                {
                    buf[63] = I2C_recv_cmd_data(buf[1],buf[2],buf[3], buf+4);
                    break;
                }
            }
            if(buf[63]){
                // Reset the I2c
                I2C_Configuration();
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

