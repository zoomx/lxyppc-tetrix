#ifndef     TETRIS_H
#define     TETRIS_H


#define     KEY_LEFT            1
#define     KEY_RIGHT           2
#define     KEY_UP              3
#define     KEY_DOWN            4
#define     KEY_PAUSE           5

int     TetrisPlay(int param);

#define      GetKey()               param //4 //(getchar(),4)

// Get a random value less than 16
#define     Rand32()          rand()%32

void    DebugDump();
void    DisplayScoreLevel(void);
void    DisplayGameOver();
void    DisplayGamePause();

#endif
