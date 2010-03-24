#ifndef     TETRIS_H
#define     TETRIS_H


#define     KEY_LEFT            1
#define     KEY_RIGHT           2
#define     KEY_UP              3
#define     KEY_DOWN            4
#define     KEY_PAUSE           5

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
}GameResult;

GameResult     TetrisPlay(int param);

void  UpdateUI();

#endif
