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


#define     IsKeyLeft()         (!(GPIOA->IDR & GPIO_Pin_0))
#define     IsKeyUp()           (!(GPIOD->IDR & GPIO_Pin_3))
#define     IsKeyRight()        (!(GPIOA->IDR & GPIO_Pin_8))
#define     IsKeyDown()         (!(GPIOC->IDR & GPIO_Pin_13))

#define     IsKeyPause()        (0)

#define     KEY_LEFT_PORT       GPIOA
#define     KEY_LEFT_PIN        GPIO_Pin_0

#define     KEY_RIGHT_PORT      GPIOC
#define     KEY_RIGHT_PIN       GPIO_Pin_13

#define     KEY_UP_PORT         GPIOA
#define     KEY_UP_PIN          GPIO_Pin_8

#define     KEY_DOWN_PORT       GPIOD
#define     KEY_DOWN_PIN        GPIO_Pin_3


#define      GetKey()               param //4 //(getchar(),4)

// Get a random value less than 16
#define     Rand16()          (SysTick->VAL &0x0F) //rand()%16

void    DebugDump();

typedef   enum
{
  GR_Update,
  GR_Score,
  GR_Over,
  GR_Move,
  GR_Pause,
  GR_Normal,
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
