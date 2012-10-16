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
#include "ppm.h"
#include "i2c.h"

/** @addtogroup Template_Project
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
//USART_InitTypeDef USART_InitStructure;
static __IO uint32_t TimingDelay;
RCC_ClocksTypeDef RCC_Clocks;

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
    init_ppm();
    init_i2c();
    init_usart();
    //init_usart_dbg();
    init_adc();
    init_pwm();
    //io_test();
    init_tps();
    adj_led(0, 0);
	while(1){
        if(ring_buf_pop(cmd_buffer,buf,8)){
            uint32_t len = 8;
            USART_TypeDef* USARTx = USART1;
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
                case 0x1A:
                    // Start open loop PWM output
                    if(buf[1]){
                        TIM15->ARR = *((uint16_t*)(buf+2));
                        set_duty(*((uint16_t*) (buf+4)));
                        TIM_Cmd(TIM15, ENABLE);
                    }else{
                        pwm_force_output(OFF,OFF,OFF);
                        TIM_Cmd(TIM15, DISABLE);
                    }
                    break;
                case 0x2A:
                    // get PPM values
                    buf[1] = get_ppm(buf+2,buf[1]);
                    len = buf[1]*4+2;
                    break;
                case 0x3A:
                    enable_tx_PA14();
                    USARTx = USART2;
                    break;
                    
            }
            send_data(USARTx,buf,len);
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
