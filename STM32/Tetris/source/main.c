/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : main.c
* Author             : MCD Application Team
* Version            : V2.2.0
* Date               : 06/13/2008
* Description        : Audio Speaker Demo main file
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_lib.h"
#include "usb_lib.h"
#include "usb_desc.h"
#include "hw_config.h"
#include "usb_prop.h"
#include "stm32f10x_it.h"
#include "Task.h"
#include "Tetris.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Extern variables ----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void WaitConfig(void);
void InitialIO(void);

/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
* Function Name  : main.
* Description    : Main routine.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/

int main(void)
{
#ifdef DEBUG
  debug();
#endif

  Set_System();
  Set_USBClock();
  USB_Config();
  USB_Init();
  InitialIO();
  
  InitialProcTask();
  
  WaitConfig();
  
  SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);
  SysTick_SetReload(72000000/20);
  SysTick_CounterCmd(SysTick_Counter_Enable);
  SysTick_ITConfig(ENABLE);

  //Speaker_Config();
  while (1)
  {
    Msg msg = GetMessage();
    if(msg){
      UpdateUI(TetrisPlay(msg));
    }
  }
}

/*******************************************************************************
* Function Name  : SysTickHandler
* Description    : This function handles SysTick Handler.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
u32 KeyLeft = 0;
u32 KeyRight = 0;
u32 KeyUp = 0;
u32 KeyDown = 0;
u32 KeyPause = 0;
#define   JugeKey(key)  \
  if(IsKey##key##()){\
    Key##key##++;\
    if(Key##key## == 2){\
      PostMessage(KEY_##key##);\
      Key##key## = 0;\
    }\
  }else{\
    Key##key## = 0;\
  }

#define   JugeKey2(key)  \
  if(IsKey##key##()){\
    Key##key##++;\
    if(Key##key## > 20){\
      Key##key## = 20;\
    }\
  }else{\
    if(Key##key## > 2){\
      PostMessage(KEY_##key##);\
    }\
    Key##key## = 0;\
  }

void SysTickHandler(void)   // Every 50ms
{
  static  u32 cnt = 0;
  cnt++;
  if(cnt == 10){
    cnt = 0;
    PostMessage(KEY_DOWN);
  }
  JugeKey(Left);
  JugeKey(Right);
  JugeKey(Down);
  
  JugeKey2(Up);
  JugeKey2(Pause);
  //SwitchToProc();
}

volatile unsigned char wrMsgIndex = 0;
unsigned char rdMsgIndex = 0;
Msg     msgStack[MSG_STACK_SIZE];

void InitialIO(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
#ifdef    USE_STM3210E_EVAL
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE);
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE);
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOD, ENABLE);
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
  GPIO_Init(GPIOD, &GPIO_InitStructure);

#elif defined  (USE_STM3210B_EVAL)
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOD, ENABLE);
  
  GPIO_InitStructure.GPIO_Pin = 
  GPIO_Pin_3 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
#endif
  
}

//void PendSVC2(void);
//void PendSVC(void)
//{
//  PendSVC2();
//}

#ifdef  DEBUG
/*******************************************************************************
* Function Name  : assert_failed
* Description    : Reports the name of the source file and the source line number
*                  where the assert_param error has occurred.
* Input          : - file: pointer to the source file name
*                  - line: assert_param error line source number
* Output         : None
* Return         : None
*******************************************************************************/
void assert_failed(u8* file, u32 line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {}
}
#endif

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/
