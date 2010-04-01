#ifndef     TETRIS_H
#define     TETRIS_H


#define     KEY_LEFT            1
#define     KEY_Left            1
#define     KEY_RIGHT           2
#define     KEY_Right           2
#define     KEY_UP              3
#define     KEY_Up              3
#define     KEY_DOWN            4
#define     KEY_Down            4
#define     KEY_PAUSE           5
#define     KEY_Pause           5
#define     TIME_50MS           6


#ifdef      WIN32

#define      GetKey()               param //4 //(getchar(),4)

// Get a random value less than 16
#define     Rand32()          (rand()%32)

#else
#ifdef    USE_STM3210E_EVAL

#define     IsKeyLeft()         (!(GPIOA->IDR & GPIO_Pin_0))
#define     IsKeyUp()           (!(GPIOD->IDR & GPIO_Pin_3))
#define     IsKeyRight()        (!(GPIOA->IDR & GPIO_Pin_8))
#define     IsKeyDown()         (!(GPIOC->IDR & GPIO_Pin_13))
#define     IsKeyPause()        (0)     // No pause
#define     IsKeySelect()       (0)     // No select

#define     Led1On()            GPIOF->BRR = GPIO_Pin_6
#define     Led1Off()           GPIOF->BSRR = GPIO_Pin_6
#define     Led2On()            GPIOF->BRR = GPIO_Pin_7
#define     Led2Off()           GPIOF->BSRR = GPIO_Pin_7
#define     Led3On()            GPIOF->BRR = GPIO_Pin_8
#define     Led3Off()           GPIOF->BSRR = GPIO_Pin_8
#define     Led4On()            GPIOF->BRR = GPIO_Pin_9
#define     Led4Off()           GPIOF->BSRR = GPIO_Pin_9
#define     Led5On()            GPIOF->BRR = GPIO_Pin_10
#define     Led5Off()           GPIOF->BSRR = GPIO_Pin_10


#elif defined  (USE_STM3210B_EVAL)

#define     IsKeyLeft()         (!(GPIOD->IDR & GPIO_Pin_13))
#define     IsKeyUp()           (!(GPIOD->IDR & GPIO_Pin_14))
#define     IsKeyRight()        (!(GPIOD->IDR & GPIO_Pin_12))
#define     IsKeyDown()         (!(GPIOD->IDR & GPIO_Pin_15))
#define     IsKeyPause()        (!(GPIOD->IDR & GPIO_Pin_3))
#define     IsKeySelect()       (!(GPIOD->IDR & GPIO_Pin_4))

#define     Led1On()            GPIOC->BSRR = GPIO_Pin_7
#define     Led1Off()           GPIOC->BRR = GPIO_Pin_7
#define     Led2On()            GPIOC->BSRR = GPIO_Pin_6
#define     Led2Off()           GPIOC->BRR = GPIO_Pin_6

#else
#error    Unkonw define
#endif


#define      GetKey()               param //4 //(getchar(),4)

#include "stm32f10x_lib.h"
// Get a random value less than 16
#define     Rand32()          (SysTick->VAL &0x1F) //rand()%32

#endif

void    DebugDump();

typedef   enum
{
  GR_Update,
  GR_Score,
  GR_Over,
  GR_Move,
  GR_Pause,
  GR_Normal,
  GR_NoChange,
  GR_Init,
}GameResult;

typedef enum
{
  GS_Over,
  GS_Pause,
  GS_Normal,
}GameState;

GameResult     TetrisPlay(int param);

void  UpdateUI(GameResult result);

void    DisplayScoreLevel(void);
void    DisplayGameOver();
void    DisplayGamePause();

#endif
