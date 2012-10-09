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


/* Private function prototypes -----------------------------------------------*/
#ifdef __GNUC__
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

/* Private functions ---------------------------------------------------------*/
void init_addr_config(void);
void init_led(void);
void init_ppm(void);
void init_i2c(void);
void init_usart_dbg(void);
void init_usart(void);
void init_adc(void);
void init_pwm(void);
void init_tim15(void);
void io_test(void);


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
    RCC_GetClocksFreq(&RCC_Clocks);
    SysTick_Config(RCC_Clocks.HCLK_Frequency / 100);
    init_addr_config();
    init_led();
    init_ppm();
    //init_i2c();
    //init_usart();
    init_usart_dbg();
    init_adc();
    init_pwm();
    //io_test();
	while(1){
        //GPIO_SetBits(GPIOB, GPIO_Pin_3| GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8);
        //GPIO_ResetBits(GPIOB, GPIO_Pin_3| GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8);
        
        //GPIO_SetBits(GPIOF, GPIO_Pin_1 | GPIO_Pin_0);
        //GPIO_ResetBits(GPIOF, GPIO_Pin_1 | GPIO_Pin_0);
        //GPIO_SetBits(GPIOB, GPIO_Pin_0|GPIO_Pin_1);
        //GPIO_ResetBits(GPIOA, GPIO_Pin_7);
        //GPIO_ResetBits(GPIOB, GPIO_Pin_0|GPIO_Pin_1);
    }
}

void io_test(void)
{
    GPIO_InitTypeDef        GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOF, &GPIO_InitStructure);
    
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

// Initial IO for address setting
// ADDR0 -> PF1  ADDR1 -> PF0  ADDR2->PB8, must config as input pull-up
void init_addr_config(void)
{
    GPIO_InitTypeDef        GPIO_InitStructure;
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOF, ENABLE);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);
	  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
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
    
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_1);
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_1);
    
    TIM_TimeBaseStructure.TIM_Period = 0xFFFF;          
    TIM_TimeBaseStructure.TIM_Prescaler = (uint16_t) (SystemCoreClock / 24000000) - 1;       
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
    
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
    
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

#define USART2_TDR_ADDRESS  ((uint32_t)(USART2_BASE + 0x28))
uint8_t txBuffer[64];

// init usart 
// usart will use PA14 and PA15, PA14 also used as SWD interface
// PA14 is the TX pin for USART, so I will not config the PA14 as
// USART Tx, until it receive a valid command from Rx PIN
// When boot from the system memory, the PA14 is used as Tx.
// This will also diable the SWD function
// To prevent disable the SWD in both system memory and user app
// I will leave the PA14 as SWD pin, until receive a valid command
void init_usart(void)
{
    USART_InitTypeDef   USART_InitStructure;
    GPIO_InitTypeDef    GPIO_InitStructure;
    NVIC_InitTypeDef    NVIC_InitStructure;
    DMA_InitTypeDef         DMA_InitStructure;
    
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
    
    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_Init(USART2, &USART_InitStructure);
    
    /* Configure USART Tx and Rx as alternate function push-pull */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Level_3;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    /* Connect PA14 to USART2_Tx */
    // Tx is used as SWD clk pin, this will disable the SWD
    // So I will enable the TX after receive a valid command from Rx
    //GPIO_PinAFConfig(GPIOA, GPIO_PinSource14, GPIO_AF_1);
    
    /* Connect PA15 to USART2_Rx */
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource15, GPIO_AF_1);
    
    /* Enable the UASRT2 global Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    // Use DMA to send data
    //USART_DMACmd(USART2, USART_DMAReq_Tx, ENABLE);
    DMA_DeInit(DMA1_Channel4);
    
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)USART2_TDR_ADDRESS;
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)txBuffer;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
    DMA_InitStructure.DMA_BufferSize = 64;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
    DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
    
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(DMA1_Channel4, &DMA_InitStructure);
    
    //DMA_Cmd(DMA1_Channel4, ENABLE);
    
    NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel4_5_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    
    DMA_ITConfig(DMA1_Channel4, DMA_IT_TC | DMA_IT_TE, ENABLE);
    
    
    USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
    
    USART_Cmd(USART2, ENABLE);
}
void send_data(USART_TypeDef* USARTx, const void* p, uint32_t len)
{
    memcpy(txBuffer,p,len);
    DMA_Cmd(DMA1_Channel4, DISABLE);
    USART_DMACmd(USARTx, USART_DMAReq_Tx, DISABLE);
    
    DMA1_Channel4->CNDTR = len;
    DMA1_Channel4->CPAR = (uint32_t)txBuffer;
    
    DMA_ClearFlag(DMA1_FLAG_GL4);
    
    USART_DMACmd(USARTx, USART_DMAReq_Tx, ENABLE);
    USART_ClearFlag(USART2, USART_FLAG_TC);
    DMA_Cmd(DMA1_Channel4, ENABLE);
}
// USART2 IRQ handler
void USART2_IRQHandler(void)
{
    /* USART in mode Receiver --------------------------------------------------*/
    if (USART_GetITStatus(USART2, USART_IT_RXNE) == SET)
    {
        uint16_t data = (uint8_t)USART_ReceiveData(USART2);
        // use systick for time out
        process_data((uint8_t)data);
        // when valid data received, we should set the tx pin to AF_1
        // this will disable SWD
        USART_SendData(USART2, data);
    }
}

#define USART1_TDR_ADDRESS  ((uint32_t)(USART1_BASE + 0x28))
// When debug, use usart1 on the i2c port
// 
void init_usart_dbg(void)
{
    USART_InitTypeDef   USART_InitStructure;
    GPIO_InitTypeDef    GPIO_InitStructure;
    NVIC_InitTypeDef    NVIC_InitStructure;
    DMA_InitTypeDef         DMA_InitStructure;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
    
    USART_InitStructure.USART_BaudRate = 38400;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_Init(USART1, &USART_InitStructure);
    
    /* Configure USART Tx and Rx as alternate function push-pull */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Level_3;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    /* Connect PB6 to USART1_Tx */
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_0);
    
    /* Connect PB7 to USART1_Rx */
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_0);
    
    /* Enable the UASRT1 global Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    // Remap the USART tx1 dma to channel 4
    SYSCFG_DMAChannelRemapConfig(SYSCFG_DMARemap_USART1Tx, ENABLE);
    
    // Use DMA to send data
    //USART_DMACmd(USART2, USART_DMAReq_Tx, ENABLE);
    DMA_DeInit(DMA1_Channel4);
    
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)USART1_TDR_ADDRESS;
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)txBuffer;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
    DMA_InitStructure.DMA_BufferSize = 64;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
    DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
    
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(DMA1_Channel4, &DMA_InitStructure);
    
    //DMA_Cmd(DMA1_Channel4, ENABLE);
    
    NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel4_5_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    
    DMA_ITConfig(DMA1_Channel4, DMA_IT_TC | DMA_IT_TE, ENABLE);
    
    
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
    
    USART_Cmd(USART1, ENABLE);
}

// USART2 IRQ handler
void USART1_IRQHandler(void)
{
    /* USART in mode Receiver --------------------------------------------------*/
    if (USART_GetITStatus(USART1, USART_IT_RXNE) == SET)
    {
        uint16_t data = (uint8_t)USART_ReceiveData(USART1);
        // use systick for time out
        process_data((uint8_t)data);
        // when valid data received, we should set the tx pin to AF_1
        // this will disable SWD
        USART_SendData(USART1, data);
    }
}

void DMA1_Channel4_5_IRQHandler(void)
{
    if(DMA_GetITStatus(DMA1_IT_TC4) == SET){
        DMA_ClearITPendingBit(DMA1_IT_TC4);
        // Tx data success
    }
    if(DMA_GetITStatus(DMA1_IT_TE4) == SET){
        DMA_ClearITPendingBit(DMA1_IT_TE4);
        // Tx data fail
    }
}

void data_ready(const void* p, uint32_t len)
{
    // valid data received, setup the Tx pin
    static uint32_t txReady = 0;
    if(txReady == 0){
        GPIO_PinAFConfig(GPIOA, GPIO_PinSource14, GPIO_AF_1);
        txReady = 1;
    }
}

#define ADC1_DR_Address    ((uint32_t)(ADC1_BASE + 0x40))//0x40012440
#define ADC_BUF_LEN 32
uint16_t adc_buffer[ADC_BUF_LEN];
#define ALL_ADC_CH      \
    (ADC_Channel_0 | ADC_Channel_1 | ADC_Channel_2 | ADC_Channel_3 | ADC_Channel_4 | ADC_Channel_5)

// initialize the ADC
void init_adc(void)
{
    ADC_InitTypeDef     ADC_InitStructure;
    GPIO_InitTypeDef    GPIO_InitStructure;
    DMA_InitTypeDef     DMA_InitStructure;
    NVIC_InitTypeDef    NVIC_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
    
    /* Configure ADC Channel11 as analog input */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | 
            GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    ADC_StructInit(&ADC_InitStructure);
    /* Configure the ADC1 in continous mode withe a resolutuion equal to 12 bits  */
    ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
    ADC_InitStructure.ADC_ContinuousConvMode = DISABLE; 
    ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC4;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_ScanDirection = ADC_ScanDirection_Backward;
    ADC_Init(ADC1, &ADC_InitStructure);
    
    DMA_DeInit(DMA1_Channel1);

    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)ADC1_DR_Address;
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)adc_buffer;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
    DMA_InitStructure.DMA_BufferSize = ADC_BUF_LEN;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(DMA1_Channel1, &DMA_InitStructure);
    
    DMA_Cmd(DMA1_Channel1, ENABLE);
    
    ADC_ChannelConfig(ADC1, ALL_ADC_CH , ADC_SampleTime_1_5Cycles);
    
    ADC_DMARequestModeConfig(ADC1, ADC_DMAMode_Circular);
    
    ADC_GetCalibrationFactor(ADC1);
    
    ADC_DMACmd(ADC1, ENABLE);
    
    NVIC_InitStructure.NVIC_IRQChannel = ADC1_COMP_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    ADC_ITConfig(ADC1, ADC_IT_EOSEQ, ENABLE);
    
    ADC_Cmd(ADC1, ENABLE);
    
    while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_ADEN)); 
    
    // start the ADC, because external trigger is set
    // ADC will not start right now
    ADC_StartOfConversion(ADC1);
}

void ADC1_COMP_IRQHandler(void)
{
    if(ADC_GetITStatus(ADC1,ADC_IT_EOSEQ) == SET){
        ADC_ClearITPendingBit(ADC1,ADC_IT_EOSEQ);
        // process the ADC data
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
    
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1 , ENABLE);

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

// Initialize the PWM, PWM will also used to sync the ADC
// TIM1 is used to output PWM, TIM1 CC4 used to sync ADC
#define GET_DUTY(percent)   \
      (uint16_t)((((uint32_t)percent) * ((SYSTEM_FREQ/PWM_FREQ) - 1) ) / 100)

void init_pwm(void)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;
    NVIC_InitTypeDef    NVIC_InitStructure;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1 , ENABLE);
    
    TIM_TimeBaseStructure.TIM_Prescaler = 0;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseStructure.TIM_Period = (SYSTEM_FREQ/PWM_FREQ) - 1;
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
    
    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
    
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
    // We may disable these output after initialize
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
    
    TIM_OCInitStructure.TIM_Pulse = GET_DUTY(50); // 5%
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
    TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
    TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
    TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCIdleState_Reset;
    
    TIM_OC1Init(TIM1, &TIM_OCInitStructure);
		TIM_OCInitStructure.TIM_Pulse = GET_DUTY(30); // 5%
    TIM_OC2Init(TIM1, &TIM_OCInitStructure);
		TIM_OCInitStructure.TIM_Pulse = GET_DUTY(10); // 5%
    TIM_OC3Init(TIM1, &TIM_OCInitStructure);
    // TIM4 CH4 is used to triggrt the ADC
		TIM_OCInitStructure.TIM_Pulse = GET_DUTY(80); // 5%
    TIM_OC4Init(TIM1, &TIM_OCInitStructure);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_2);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_2);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_2);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource11, GPIO_AF_2);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_2);
    
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource0, GPIO_AF_2);
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource1, GPIO_AF_2);
    
    // We need update the timer settings by COM event
    // In this case, TIM15 and TIM17 can be used as COM trigger
    TIM_CCPreloadControl(TIM1, ENABLE);
    // Select TIM15 as the trigger
    TIM_SelectInputTrigger(TIM1, TIM_TS_ITR0);
    
    NVIC_InitStructure.NVIC_IRQChannel = TIM1_BRK_UP_TRG_COM_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    TIM_ITConfig(TIM1, TIM_IT_COM, ENABLE);
    
    TIM_Cmd(TIM1, ENABLE);
    /* TIM1 Main Output Enable */
    TIM_CtrlPWMOutputs(TIM1, ENABLE);
    
    //init_tim15();
}

#define  AP      (1ul<<0)
#define  AN      (1ul<<2)
#define  BP      (1ul<<4)
#define  BN      (1ul<<6)
#define  CP      (1ul<<8)
#define  CN      (1ul<<10)
#define  ALL_OFF        (~ (AP|AN|BP|BN|CP|CN))
#define  CLOSE_ALL()    TIM1->CCER &= ALLOFF
#define  ENABLE_TIM(mask)   \
        do{\
            TIM1->CCER &= ALL_OFF;\
            TIM1->CCER |= mask;\
        }while(0)

#define  A_B    ENABLE_TIM(AP|BN)    
#define  C_B    ENABLE_TIM(CP|BN)
#define  C_A    ENABLE_TIM(CP|AN)
#define  B_A    ENABLE_TIM(BP|AN)
#define  B_C    ENABLE_TIM(BP|CN)
#define  A_C    ENABLE_TIM(AP|CN)

int32_t dir = 1;
int32_t step = 1;
void TIM1_BRK_UP_TRG_COM_IRQHandler(void)
{
    TIM_ClearITPendingBit(TIM1, TIM_IT_COM);
    // Here to prepare data for next step
    if(dir>0) dir = 1;
    if(dir<0) dir = -1;
    switch(step){
        case 1:
            A_B;
            step += dir;
            break;
        case 2:
            C_B;
            step += dir;
            break;
        case 3:
            C_A;
            step += dir;
            break;
        case 4:
            B_A;
            step += dir;
            break;
        case 5:
            B_C;
            step += dir;
            break;
        case 6:
            A_C;
            step += dir;
            break;
    }
    if(step>6){
        step = 1;
    }else if(step < 1){
        step = 6;
    }
}

// Here I use the tim15 as the COM trigger for tim1
// TIM15 can use DMA channel 5 to update it's pre-load values
void init_tim15(void)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    NVIC_InitTypeDef         NVIC_InitStructure;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM15, ENABLE);
    
    TIM_TimeBaseStructure.TIM_Period = 0xFFFF;          
    TIM_TimeBaseStructure.TIM_Prescaler = (uint16_t) (SystemCoreClock / 24000000) - 1;
    TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;    
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;   
    TIM_TimeBaseInit(TIM15, &TIM_TimeBaseStructure);
    
    /* Select the Master Slave Mode */
    TIM_SelectMasterSlaveMode(TIM15, TIM_MasterSlaveMode_Enable);

    /* Master Mode selection */
    TIM_SelectOutputTrigger(TIM15, TIM_TRGOSource_Update);
    
    NVIC_InitStructure.NVIC_IRQChannel = TIM15_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    TIM_ITConfig(TIM15, TIM_IT_Update, ENABLE);
    
    // enable tim15
    TIM_Cmd(TIM15, ENABLE);
}

// to make sure tim15 is running
void TIM15_IRQHandler(void)
{
    TIM_ClearITPendingBit(TIM15, TIM_IT_Update);
    // TIM15 is running
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
void TimingDelay_Decrement(void)
{
#ifdef USE_CPAL
    SysTick_Handler_i2c();
#endif
    if (TimingDelay != 0x00)
    { 
        TimingDelay--;
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

uint8_t get_i2c_addr(void)
{
    // I2C addr can be config by the addr0,1,2 pin
    uint16_t add = GPIO_ReadInputData(GPIOF) & 0x03; // PF0->add1, PF1->add0
    add = ((add>>1) | (add<<1)) & 0x03;
    if(GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_8)){  // PB8, addr2
        add |= 0x04;
    }
    return add | 0x50;
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
