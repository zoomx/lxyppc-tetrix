/**
  ******************************************************************************
  * @file    Project/STM32F0xx_StdPeriph_Templates/main.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    18-May-2012
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "data_process.h"
#include "string.h"
#include "ring_buffer.h"
#include "usart.h"
#include "simple_io.h"
#include "adc.h"
#include "pwm.h"

/** @addtogroup Template_Project
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
typedef enum {FAILED = 0, PASSED = !FAILED} TestStatus;

/* Private define ------------------------------------------------------------*/
#if defined (USE_STM320518_EVAL)
  #define MESSAGE1   " STM32F05x CortexM0 " 
  #define MESSAGE2   " Device running on  " 
  #define MESSAGE3   "   STM320518-EVAL   " 
#endif

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
//USART_InitTypeDef USART_InitStructure;
static __IO uint32_t TimingDelay;
RCC_ClocksTypeDef RCC_Clocks;
CPAL_TransferTypeDef  sRxStructure, sTxStructure;
/* Buffers tables declarations */
const uint8_t tStateSignal[]  = "STM32 CPAL 2xBoards Example: Signal State  ";
const uint8_t tSignal1[]      = "STM32 CPAL 2xBoards Example: Signal Signal1";
const uint8_t tSignal2[]      = "STM32 CPAL 2xBoards Example: Signal Signal2";

uint8_t tRxBuffer[MAX_BUFF_SIZE];
uint32_t BufferSize = BUFFER_SIZE;
uint8_t Color = 0;
__IO uint32_t ActionState = ACTION_NONE;
__IO uint32_t RecieverMode = 0;
__IO uint32_t TransmitMode = 0;

DECLRAE_RING_BUFFER(cmd_buffer)

/* Private function prototypes -----------------------------------------------*/
#ifdef __GNUC__
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

/* Private functions ---------------------------------------------------------*/
void init_clocks(void);
void init_addr_config(void);
void init_led(void);
void init_ppm(void);
void init_i2c(void);
//void init_usart_dbg(void);
//void init_usart(void);
void init_adc(void);
void init_pwm(void);
void init_tim15(void);
void io_test(void);

//void send_data(USART_TypeDef* USARTx, const void* p, uint32_t len);

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f0xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f0xx.c file
     */ 
  /* SysTick end of count event each 10ms */
    uint8_t buf[32];
    RCC_GetClocksFreq(&RCC_Clocks); // Check the clock freqs
    ring_buf_init(cmd_buffer);
    init_clocks();
    SysTick_Config(RCC_Clocks.HCLK_Frequency / 100);
    init_addr_config();
    init_led();
    //init_ppm();
    //init_i2c();
    //init_usart();
    init_usart_dbg();
    init_adc();
    init_pwm();
    //io_test();
	while(1){
        if(ring_buf_pop(cmd_buffer,buf,8)){
            uint32_t len = 8;
            //USART_SendData(USART1, buf[0]);
            //*((__IO uint16_t*)USART1_TDR_ADDRESS) = buf[0];
            switch(buf[0]){
                case 0xaa:
                    adj_led(buf[1],buf[2]);
                    break;
                case 0xbb:
                    buf[1] = get_i2c_addr();
                    break;
                case 0xcc:
                    start_adc(ALL_ADC_CH, ADC_SampleTime_55_5Cycles);
                    //ADC_StartOfConversion(ADC1);
                    while(!is_adc_done());
                    buf[1] = get_adc_value((uint16_t*)(buf+2), 10);
                    len = buf[1]*2 + 2;
                    break;
                case 0xdd:
                    *((uint16_t*)(buf+2)) = get_refint_cal();
                    *((uint16_t*)(buf+4)) = get_temp_30_cal();
                    *((uint16_t*)(buf+6)) = get_temp_110_cal();
                    break;
                case 0xee:
                    pwm_force_output(buf[1],buf[2],buf[3]);
                    set_duty(*((uint16_t*) (buf+4)));
                    break;
            }
            send_data(USART1,buf,len);
        }
        //GPIO_SetBits(GPIOB, GPIO_Pin_8);
        //GPIO_ResetBits(GPIOB, GPIO_Pin_8);
        
        //GPIO_SetBits(GPIOF, GPIO_Pin_1 | GPIO_Pin_0);
        //GPIO_ResetBits(GPIOF, GPIO_Pin_1 | GPIO_Pin_0);
        //GPIO_SetBits(GPIOB, GPIO_Pin_0|GPIO_Pin_1);
        //GPIO_ResetBits(GPIOA, GPIO_Pin_7);
        //GPIO_ResetBits(GPIOB, GPIO_Pin_0|GPIO_Pin_1);
    }
}

void init_clocks(void)
{
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOF, ENABLE);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
    
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM15, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1 , ENABLE);
    
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1 , ENABLE);
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
    
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
}

void io_test(void)
{
    GPIO_InitTypeDef        GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    //GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
    //GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    //GPIO_SetBits(GPIOA, GPIO_Pin_7);
    //GPIO_SetBits(GPIOB, GPIO_Pin_0|GPIO_Pin_1);
}

/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART */
  //USART_SendData(EVAL_COM1, (uint8_t) ch);

  /* Loop until the end of transmission */
  //while (USART_GetFlagStatus(EVAL_COM1, USART_FLAG_TC) == RESET)
  //{}

  return ch;
}


#define TIM2_DMAR_ADDRESS ( (uint32_t)(TIM2_BASE + 0x4C) ) /* TIM DMAR address */
typedef struct _PPM_Data
{
    uint32_t duty;
    uint32_t period;
}PPM_Data;
#define PPM_BUF_CNT 32
PPM_Data ppm_buffer[PPM_BUF_CNT] = {0};
// Initialize ppm, PPM use PWM input feature of the timer2
//  PB3 (TIM2 CH2) -> PPM input
#define USE_DMA         1
void init_ppm(void)
{
    GPIO_InitTypeDef        GPIO_InitStructure;
    TIM_ICInitTypeDef       TIM_ICInitStructure;
    NVIC_InitTypeDef        NVIC_InitStructure;
    DMA_InitTypeDef         DMA_InitStructure;
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource3, GPIO_AF_2);
 
    TIM_ICInitStructure.TIM_Channel = TIM_Channel_2;
    TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
    TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
    TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
    TIM_ICInitStructure.TIM_ICFilter = 0x0;

    TIM_PWMIConfig(TIM2, &TIM_ICInitStructure);
    
    TIM_SelectInputTrigger(TIM2, TIM_TS_TI2FP2);
    
    /* Select the slave Mode: Reset Mode */
    TIM_SelectSlaveMode(TIM2, TIM_SlaveMode_Reset);
    TIM_SelectMasterSlaveMode(TIM2,TIM_MasterSlaveMode_Enable);
    
    // Slave mode controller can generate a update event
    // We can use the DMA channel 2 for TIM2 up
    // Because in PWM input mode we use the TI2FP2 signal to
    // reset the timer, this is equal to TIM2 CC2 event
    TIM_UpdateRequestConfig(TIM2, TIM_UpdateSource_Regular);
    
    // Transfer the CCR1 and CCR2 with DMA
#if USE_DMA
    TIM_DMAConfig(TIM2, TIM_DMABase_CCR1, TIM_DMABurstLength_2Transfers);
    DMA_DeInit(DMA1_Channel2);
    
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)TIM2_DMAR_ADDRESS;
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)ppm_buffer;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;  
    DMA_InitStructure.DMA_BufferSize = PPM_BUF_CNT*2;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_PeripheralDataSize_Word;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
    DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
    
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(DMA1_Channel2, &DMA_InitStructure);
    
    TIM_DMACmd(TIM2, TIM_DMA_Update, ENABLE);
    DMA_Cmd(DMA1_Channel2, ENABLE);
    (void)NVIC_InitStructure;
    // actual PPM value should solve in the systick
#else
    /* Enable the TIM2 global Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    /* Enable the CC2 Interrupt Request */
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
    (void)DMA_InitStructure;
#endif
    /* TIM enable counter */
    TIM_Cmd(TIM2, ENABLE);
}

// TIM2 IRQ handler, used to capture the PPM signal
__IO uint16_t IC2Value = 0;
__IO uint16_t DutyCycle = 0;
__IO uint32_t Frequency = 0;
void TIM2_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM2, TIM_IT_Update) == SET) 
    {
      /* Clear TIM2 Capture compare interrupt pending bit */
      TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

      /* Get the Input Capture value */
      IC2Value = TIM_GetCapture2(TIM2);

      if (IC2Value != 0)
      {
        /* Duty cycle computation */
        DutyCycle = (TIM_GetCapture1(TIM2) * 100) / IC2Value;

        /* Frequency computation 
           TIM2 counter clock = (RCC_Clocks.HCLK_Frequency)/2 */

        Frequency = RCC_Clocks.HCLK_Frequency / IC2Value;
      }
      else
      {
        DutyCycle = 0;
        Frequency = 0;
      }
    }
}

#define I2C_BUF_LEN 32
uint8_t i2c_buffer[I2C_BUF_LEN];
#define I2C1_RXDR_Address     ((uint32_t)(I2C1_BASE + 0x24))
// Initialize the I2C
void init_i2c(void)
{
    // Think we can keep things simple, just use the std library
    I2C_InitTypeDef     I2C_InitStructure;
    GPIO_InitTypeDef    GPIO_InitStructure;
    NVIC_InitTypeDef    NVIC_InitStructure;
    DMA_InitTypeDef     DMA_InitStructure;

    /*!< Configure I2C1 pins: SCL */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    /*!< Configure I2C1 pins: SDA */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    /* Connect PB6 to I2C_SCL*/
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_1);
    /* Connect PB7 to I2C_SDA*/
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_1);
  
    I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
    I2C_InitStructure.I2C_AnalogFilter = I2C_AnalogFilter_Enable;
    I2C_InitStructure.I2C_DigitalFilter = 0x00;
    I2C_InitStructure.I2C_OwnAddress1 = OWN_ADDRESS;
    I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
    I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
    I2C_InitStructure.I2C_Timing = I2C_TIMING;
    I2C_Init(I2C1, &I2C_InitStructure);
    
    DMA_DeInit(DMA1_Channel3);

    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)I2C1_RXDR_Address;
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)i2c_buffer;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
    DMA_InitStructure.DMA_BufferSize = I2C_BUF_LEN;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(DMA1_Channel3, &DMA_InitStructure);
    
    DMA_Cmd(DMA1_Channel3, ENABLE);
    I2C_DMACmd(I2C1, I2C_DMAReq_Rx, ENABLE);
    
    NVIC_InitStructure.NVIC_IRQChannel = I2C1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    I2C_ITConfig(I2C1, I2C_IT_ADDRI, ENABLE);
    
    I2C_Cmd(I2C1, ENABLE);
    
    
#ifdef  USE_CPAL
    // I2C need CPAL library 
    sRxStructure.wNumData = BufferSize;       /* Maximum Number of data to be received */
    sRxStructure.pbBuffer = tRxBuffer;        /* Common Rx buffer for all received data */
    sRxStructure.wAddr1 = OWN_ADDRESS;        /* Not needed */
    sRxStructure.wAddr2 = 0;                  /* Not needed */
  
    /* Initialize local Transmission structures */
    sTxStructure.wNumData = BufferSize;       /* Maximum Number of data to be received */
    sTxStructure.pbBuffer = (uint8_t*)tStateSignal;     /* Common Rx buffer for all received data */
    sTxStructure.wAddr1 = OWN_ADDRESS;        /* The own board address */
    sTxStructure.wAddr2 = 0;                  /* Not needed */
    
    RCC_I2CCLKConfig(RCC_I2C1CLK_SYSCLK);
    CPAL_I2C_StructInit(&I2C_DevStructure);
    I2C_DevStructure.CPAL_Mode = CPAL_MODE_SLAVE;
    I2C_DevStructure.CPAL_Direction = CPAL_DIRECTION_RX;
#ifdef CPAL_I2C_DMA_PROGMODEL
    I2C_DevStructure.wCPAL_Options =  CPAL_OPT_NO_MEM_ADDR | CPAL_OPT_DMARX_TCIT;
    I2C_DevStructure.CPAL_ProgModel = CPAL_PROGMODEL_DMA;
#elif defined (CPAL_I2C_IT_PROGMODEL)
    I2C_DevStructure.wCPAL_Options =  CPAL_OPT_NO_MEM_ADDR;
    I2C_DevStructure.CPAL_ProgModel = CPAL_PROGMODEL_INTERRUPT;
#else
 #error "Please select one of the programming model (in stm32f0xx_i2c_cpal_conf.h)"
#endif
    I2C_DevStructure.pCPAL_I2C_Struct->I2C_Timing = I2C_TIMING;
    I2C_DevStructure.pCPAL_I2C_Struct->I2C_OwnAddress1 = OWN_ADDRESS;
    I2C_DevStructure.pCPAL_TransferRx = &sRxStructure;
    I2C_DevStructure.pCPAL_TransferTx = &sTxStructure;
  
    CPAL_I2C_Init(&I2C_DevStructure);
#endif
}


uint32_t I2C1_IRQHandler(void)
{
    if(I2C_GetITStatus(I2C1, I2C_IT_ADDR)){
        // setup DMA address here
        I2C_ClearITPendingBit(I2C1, I2C_IT_ADDR);
    }
		return 0;
}

/**
  * @brief  Inserts a delay time.
  * @param  nTime: specifies the delay time length, in 10 ms.
  * @retval None
  */
void Delay(__IO uint32_t nTime)
{
  TimingDelay = nTime;

  while(TimingDelay != 0);
}

void SysTick_Handler_i2c(void);

/**
  * @brief  Decrements the TimingDelay variable.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
#ifdef USE_CPAL
    SysTick_Handler_i2c();
#endif
    if (TimingDelay != 0x00)
    { 
        TimingDelay--;
    }
    if(0){
        static uint8_t led1 = 0;
        static uint8_t led2 = 0;    
        adj_led(led1,led2);
        led1++;
        led2++;
        if(led1 == 101) led1 = 0;
        if(led2 == 101) led2 = 0;
    }
}
TestStatus Buffer_Compare(uint8_t* pBuffer1, uint8_t* pBuffer2, uint16_t BufferLength)
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

uint8_t Buffer_Check(uint8_t* pBuffer, uint8_t* pBuffer1, uint8_t* pBuffer2,  uint8_t* pBuffer3, uint16_t BufferLength)
{ 
  if (Buffer_Compare(pBuffer, pBuffer1, BufferLength) == PASSED)
  {
    return 0;
  }
  else if (Buffer_Compare(pBuffer, pBuffer2, BufferLength) == PASSED)
  {
    return 1;
  }
  else if (Buffer_Compare(pBuffer, pBuffer3, BufferLength) == PASSED)
  {
    return 2;
  }  
  else
  {
    return 0xFF; /* Non identified buffer */
  }
}



#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
