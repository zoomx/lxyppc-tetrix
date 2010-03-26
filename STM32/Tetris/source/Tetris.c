//#include "stm32f10x_lib.h"
#include "..\inc\Tetris.h"

#define     MATRIX_SIZE     21
#define     MAT_ROW_CNT     20
#define     MAT_COL_CNT     10
#define     MATRIX_START    0
#define     MATRIX_END      (MATRIX_START+MAT_ROW_CNT)
#define     MATRIX_LAST     20
#define     MATRIX_FIRST    0
#define     MATRIX_BEFORE_1ST  MATRIX_LAST

#if MATRIX_SIZE < (MATRIX_END + 1)
#error  Buffer too small
#endif

#define     MAP_MASK        0xFFFF
#define     MAP_OFFSET      3
#define     MAT_ROW_MASK     ((1<<MAT_COL_CNT) - 1)

#define     PATTEN_CNT       (7+1)  // plus one to make power of 2
#define     COLOR_CNT        8

typedef enum
{
    TA_Left,
    TA_Right,
    TA_Rotate,
    TA_Down,
    TA_None,
}TetrisAction;

#define     _ExtendBit(x)        ( ((x&1)<<24) | ((x&2)<<15) | ((x&4)<<6) | ((x&8)>>3))
const   unsigned long   BitExtend[16] =
{
    _ExtendBit(0x0),_ExtendBit(0x1),_ExtendBit(0x2),_ExtendBit(0x3),
    _ExtendBit(0x4),_ExtendBit(0x5),_ExtendBit(0x6),_ExtendBit(0x7),
    _ExtendBit(0x8),_ExtendBit(0x9),_ExtendBit(0xA),_ExtendBit(0xB),
    _ExtendBit(0xC),_ExtendBit(0xD),_ExtendBit(0xE),_ExtendBit(0xF),
};

typedef    unsigned char    PattenMap[4];

typedef union   MatrixLine
{
    unsigned long   raw32[4];
    unsigned short  raw16[8];
    unsigned char   raw8[16];
    struct  {
        unsigned char  Data[12];        //12
        unsigned short BitMap;          //2
        unsigned char  preLine;         //1
        unsigned char  nextLine;        //1  = total 16
    };
}MatrixLine;

typedef union  BlockDesc
{
    unsigned long   raw32;
    struct{
        signed char     x;
        //signed char     y;
        unsigned char   line;           // Line index in the matrix
        unsigned char   rotatePatten;   // low 2 bit is rotate state
        unsigned char   color1;
    };
}BlockDesc;

const PattenMap pattens[PATTEN_CNT*4] = 
{
    // Box
    {0x00,0x06,0x06,0x00},{0x00,0x06,0x06,0x00},
    {0x00,0x06,0x06,0x00},{0x00,0x06,0x06,0x00},
    // L
    {0x04,0x04,0x06,0x00},{0x00,0x07,0x04,0x00},
    {0x06,0x02,0x02,0x00},{0x00,0x02,0x0E,0x00},
    // J
    {0x02,0x02,0x06,0x00},{0x00,0x04,0x07,0x00},
    {0x06,0x04,0x04,0x00},{0x00,0x0E,0x02,0x00},
    // Z
    {0x00,0x06,0x03,0x00},{0x02,0x06,0x04,0x00},
    {0x00,0x06,0x03,0x00},{0x02,0x06,0x04,0x00},
    // S
    {0x00,0x03,0x06,0x00},{0x04,0x06,0x02,0x00},
    {0x00,0x03,0x06,0x00},{0x04,0x06,0x02,0x00},
    // T
    {0x00,0x07,0x02,0x00},{0x02,0x06,0x02,0x00},
    {0x00,0x02,0x07,0x00},{0x02,0x03,0x02,0x00},
    // line
    {0x04,0x04,0x04,0x04},{0x00,0x0F,0x00,0x00},
    {0x04,0x04,0x04,0x04},{0x00,0x0F,0x00,0x00},
    /// Duplicate the L patten, so the random value only need to and 31
    // L
    {0x04,0x04,0x06,0x00},{0x00,0x07,0x04,0x00},
    {0x06,0x02,0x02,0x00},{0x00,0x02,0x0E,0x00},
};

MatrixLine      matrix[MATRIX_SIZE];

BlockDesc       curBlock = {0};
BlockDesc       nextBlock = {0};
unsigned    int  score = 0;
unsigned    int  level = 0;
void            ScoreUp(int line);

void    InitialMatrix();
void    CreateBlock(BlockDesc* block);
int     CheckBlock(BlockDesc* block, TetrisAction action);
int     MoveBlock(BlockDesc* block, TetrisAction action);
//void    CopyBlock(BlockDesc* des, const BlockDesc* src);
#define    CopyBlock(des, src)  ((des)->raw32 = (src)->raw32)

int     DropBlock(BlockDesc* block);
unsigned char   firstLine = 0;

volatile unsigned char   bCameraOn = 0;

GameResult     TetrisPlay(int param)
{
    static  GameResult  gameState = GR_Init;
    static  unsigned char timeCnt = 0;
    switch(gameState){
    case GR_Init:
        level = 0;
    case GR_Over:
      if(param == KEY_UP || param == KEY_PAUSE){
        InitialMatrix();
        CreateBlock(&curBlock);
        
        // Create next block
        CreateBlock(&nextBlock);
        score = 0;
        DisplayScoreLevel();
        gameState = GR_Update;
      }else{
          if(param == KEY_LEFT){
              if(level < 20){
                level++;
              }
              DisplayScoreLevel();
              gameState = GR_Init;
          }else if(param == KEY_RIGHT){
              if(level > 0){
                level--;
              }
              DisplayScoreLevel();
              gameState = GR_Init;
          }
          if(gameState == GR_Init){
              gameState = GR_Over;
              DisplayGameOver();
              return GR_NoChange;
          }else{
              return GR_NoChange;
          }
      }
      return gameState;
    case GR_Pause:
      if(param == KEY_PAUSE || param == KEY_UP){
        gameState = GR_Normal;
        return gameState;
      }
      return GR_NoChange;
    default:
      if(param == KEY_PAUSE){
        DisplayGamePause();
        gameState = GR_Pause;
        return GR_NoChange;
      }
      break;
    }
    if(!bCameraOn){
      gameState = GR_Pause;
      DisplayGamePause();
      return GR_NoChange;
    }
    //while(1)
    {
        int key;
        TetrisAction action;
        //DebugDump();

        // Check valid
        if(!CheckBlock(&curBlock,TA_None)){
            // Game over
          level = 0;
          gameState = GR_Over;
          DisplayGameOver();
          return GR_NoChange;
        }

        key = GetKey();
        switch(key){
            case KEY_LEFT:
                action = TA_Left;
                break;
            case KEY_RIGHT:
                action = TA_Right;
                break;
            case KEY_UP:
                action = TA_Rotate;
                break;
            case KEY_DOWN:
                action = TA_Down;
                break;
            case KEY_PAUSE:
                break;
            case TIME_50MS:
                timeCnt++;
                if(level>14 || timeCnt >= 15 - level){
                    timeCnt = 0;
                    action = TA_Down;
                }else{
                    return GR_NoChange;
                }
                break;
            default:
                return GR_NoChange;
        }
        if(CheckBlock(&curBlock,action)){
            MoveBlock(&curBlock,action);
            return GR_Move;
        }else if(action == TA_Down){
            ScoreUp(DropBlock(&curBlock));
            CopyBlock(&curBlock,&nextBlock);
            CreateBlock(&nextBlock);
        }
    }
    return GR_Update;
}


void    InitialMatrix()
{
    unsigned int i;
    for(i=0;i<MATRIX_SIZE;i++){
        matrix[i].raw32[0] = 0;
        matrix[i].raw32[1] = 0;
        matrix[i].raw32[2] = 0;
        matrix[i].raw32[3] = 0;
        matrix[i].nextLine = i + 1;
        matrix[i].preLine = i - 1;
        //             _3_ __10bits__ _3_
        //             012 1234567890 012  // Ten bits
        //             012 3456789ABC DEF
        // Bit patten  111 0000000000 111
        matrix[i].BitMap = MAP_MASK - (MAT_ROW_MASK<<MAP_OFFSET);
    }
    matrix[MATRIX_FIRST].preLine = MATRIX_LAST;
    matrix[MATRIX_LAST].nextLine = 0;
    matrix[MATRIX_LAST].BitMap = MAP_MASK;
    firstLine = MATRIX_START;
}

void    CreateBlock(BlockDesc* block)
{
    block->color1 = (Rand32()&15) + 1;
    block->rotatePatten =  Rand32()&31;
    block->x = 3;
    if(pattens[block->rotatePatten][0]){
        block->line = firstLine;
    }else{
        block->line = MATRIX_LAST;
    }
    //for(i=0;i<4;i++){
    //    unsigned char pat = pattens[block->rotatePatten][i];//block->patten[block->rotate][i];
    //    //block->raw32[i] = BitExtend[pat]*(color+1);
    //    if(pat && rnd){
    //        if(i){
    //            block->line = matrix[firstLine].preLine;
    //        }
    //        //block->y -= i;
    //        rnd = 0;
    //    }
    //}
}

//void    CopyBlock(BlockDesc* des, const BlockDesc* src)
//{
//    int i;
//    for(i=0;i<sizeof(BlockDesc)/4;i++){
//        des->raw32[i] = src->raw32[i];
//    }
//}

int     CheckBlock(BlockDesc* block, TetrisAction action)
{
    int bx = block->x;
    unsigned int br = block->rotatePatten;
    int i;
    unsigned char line = block->line;
    switch(action){
        case TA_Left:
            bx--;
            break;
        case TA_Right:
            bx++;
            break;
        case TA_Rotate:
            br = ((br&3) == 3) ? br-3 : br+1;
            break;
        case TA_Down:
            line = matrix[line].nextLine;
            break;
        default:
            break;
    }
    
    for(i=0;i<4;i++){
        unsigned long blockMap = pattens[br][i];
        blockMap<<=(MAP_OFFSET+MAT_COL_CNT-bx-4);
        if(matrix[line].BitMap & blockMap){
            return 0;
        }
        line = matrix[line].nextLine;
    }
    return 1;
}

int     MoveBlock(BlockDesc* block, TetrisAction action)
{
    //int i;
    switch(action){
        case TA_Left:
            block->x--;
            break;
        case TA_Right:
            block->x++;
            break;
        case TA_Rotate:
            {
                unsigned char rp = block->rotatePatten;
            block->rotatePatten = 
                ((rp&3) == 3 ) ? rp-3 : rp+1;
            }
            break;
        case TA_Down:
            block->line =
            matrix[block->line].nextLine;
            break;
    }
    //for(i=0;i<4;i++){
    //    unsigned char pat = block->patten[block->rotate][i];
    //    block->raw32[i] = BitExtend[pat]*(block->color+1);
    //}
    return 1;
}

int     DropBlock(BlockDesc* block)
{
    int bx = block->x;
    int i;
    int full = 0;
    unsigned char iMat = block->line;
    unsigned char iNext;
    for(i=0;i<4;i++){
        unsigned long blockMap = pattens[block->rotatePatten][i];
        if(iMat==MATRIX_END)break;
        blockMap<<=(MAP_OFFSET+MAT_COL_CNT-bx-4);
        matrix[iMat].BitMap |= blockMap;
        if(matrix[iMat].BitMap == MAP_MASK && blockMap){
            full++;
            // Clear this line
            matrix[iMat].raw32[0] = 0;
            matrix[iMat].raw32[1] = 0;
            matrix[iMat].raw32[2] = 0;
            matrix[iMat].BitMap = MAP_MASK - (MAT_ROW_MASK<<MAP_OFFSET);

            // Remember next line
            iNext = matrix[iMat].nextLine;
            // Connect to next line
            matrix[matrix[iMat].preLine].nextLine = matrix[iMat].nextLine;
            matrix[iNext].preLine = matrix[iMat].preLine;

            // Move it to the first place
            matrix[iMat].preLine = MATRIX_LAST;//matrix[firstLine].preLine;
            matrix[iMat].nextLine = matrix[MATRIX_LAST].nextLine;//firstLine;
            matrix[MATRIX_LAST].nextLine = iMat;
            //matrix[matrix[firstLine].preLine].nextLine = iMat;
            matrix[firstLine].preLine = iMat;
            firstLine = iMat;
            iMat = iNext;
        }else{
            unsigned long *p = (unsigned long *)(matrix[iMat].raw8 + bx);
            unsigned char pat = pattens[block->rotatePatten][i];
            *p |= BitExtend[pat]*(block->color1);
            iMat = matrix[iMat].nextLine;
        }
    }
    //MATRIX_START = (MATRIX_START - full)&MATRIX_MASK;
    //MATRIX_END = (MATRIX_END - full)&MATRIX_MASK;
    return full;
}
#if 0
void    DebugDump()
{
    int row;
    unsigned char iMat = matrix[firstLine].preLine;
    printf("***************Dump Start****************\n");
    for(row=-1;row<MAT_ROW_CNT+1;row++){
        int col;
        unsigned int tmp;
        for(col=0;col<MAT_COL_CNT;col++){
            unsigned char val = 0;
            if( (row >= curBlock.y&& row<curBlock.y+4) && (col >= curBlock.x && col < curBlock.x +4)){
                val = curBlock.BlockData[ (row - curBlock.y)*4 + col - curBlock.x ];
            }
            if(!val){
                val = matrix[iMat].Data[col];
            }
            if(row == -1 || row == MAT_ROW_CNT){
                if(!val){
                    printf("X");
                }else{
                    printf("%d",val);
                }
            }else{
                printf("%d",val);
            }
        }
        printf("   ");
        for(tmp=0x8000;tmp;tmp>>=1){
            printf(tmp&matrix[iMat].BitMap?"1":"0");
        }
        iMat = matrix[iMat].nextLine;
        printf("\n");
    }
    printf("\n");
}
#endif
void ScoreUp(int line)
{
    // 1 1
    // 2 3
    // 3 6
    // 4 12
    if(line){
        unsigned int lastScore = score/100;
        score += line*line - line/2;
        if(lastScore != score/100)
        level++;
        if(level>20){
            level = 20;
        }
        if(score > 99999){
            score = 99999;
        }
        DisplayScoreLevel();
    }
}

extern  unsigned char scrBuf[19*23];
void  UpdateUI(GameResult result)
{
  unsigned char iMat = firstLine;
  unsigned char cnt = 4;
  unsigned char blockLine = curBlock.line;
  unsigned char row;
  if(blockLine == MATRIX_LAST){
      cnt--;
      blockLine = matrix[MATRIX_LAST].nextLine;
  }
  if(result == GR_NoChange)return;
  for(row=0;row<MATRIX_LAST;row++)
  {
    *(unsigned long*)&scrBuf[(row+1)*19 + 1] = matrix[iMat].raw32[0];
    *(unsigned long*)&scrBuf[(row+1)*19 + 5] = matrix[iMat].raw32[1];
    *(unsigned short*)&scrBuf[(row+1)*19 + 9] = matrix[iMat].raw16[4];
    //*(unsigned short*)&scrBuf[(row+1)*19 + 9] = matrix[iMat].raw16[4];
    if(iMat == blockLine && cnt){
        *(unsigned long*)&scrBuf[(row+1)*19 + curBlock.x + 1] |=
            BitExtend[pattens[curBlock.rotatePatten][4-cnt]] * (curBlock.color1);
        iMat = blockLine = matrix[iMat].nextLine;
        cnt--;
    }else{
        iMat = matrix[iMat].nextLine;
    }
  }//while(iMat != MATRIX_LAST);

  for(int i=0;i<4;i++){
    *(unsigned long*)&scrBuf[(i+4)*19 + 13] =
        BitExtend[pattens[nextBlock.rotatePatten][i]] * (nextBlock.color1);
  }
  
  //if(result == GR_Over){
  //  DisplayGameOver();
  //}else if(result == GR_Pause){
  //  DisplayGamePause();
  //}
}


#define     NUM_0_BLOCK_A       20
#define     NUM_0_BLOCK_B       30
#define     GAME_OVER_BLOCK_A   40
#define     GAME_OVER_BLOCK_B   48
#define     PAUSE_BLOCK_A       56
#define     PAUSE_BLOCK_B       62

#define     GAME_OVER_LEN       8
#define     GAME_OVER_A         154
#define     GAME_OVER_B         173

#define     PAUSE_LEN           6
#define     PAUSE_A             231
#define     PAUSE_B             250

#define     LEVEL_10_A      337
#define     LEVEL_10_B      356 
#define     LEVEL_1_A       338
#define     LEVEL_1_B       357

#define     SCORE_10000_A   240
#define     SCORE_10000_B   259

void    DisplayScoreLevel(void)
{
    int num = level/10;
    unsigned char* scoreA = &scrBuf[SCORE_10000_A];
    unsigned char* scoreB = &scrBuf[SCORE_10000_B];
    unsigned int tpScore = score;
    scrBuf[LEVEL_10_A] = NUM_0_BLOCK_A + num;
    scrBuf[LEVEL_10_B] = NUM_0_BLOCK_B + num;
    num = level - num*10;
    scrBuf[LEVEL_1_A] = NUM_0_BLOCK_A + num;
    scrBuf[LEVEL_1_B] = NUM_0_BLOCK_B + num;

    if(score >9999){
        num = tpScore/10000;
        *scoreA++ = num + NUM_0_BLOCK_A;
        *scoreB++ = num + NUM_0_BLOCK_B;

        tpScore = tpScore - num*10000;
        num = tpScore/1000;
        *scoreA++ = num + NUM_0_BLOCK_A;
        *scoreB++ = num + NUM_0_BLOCK_B;
        
        tpScore = tpScore - num*1000;
        num = tpScore/100;
        *scoreA++ = num + NUM_0_BLOCK_A;
        *scoreB++ = num + NUM_0_BLOCK_B;

        tpScore = tpScore - num*100;
        num = tpScore/10;
        *scoreA++ = num + NUM_0_BLOCK_A;
        *scoreB++ = num + NUM_0_BLOCK_B;

        tpScore = tpScore - num*10;
        num = tpScore/1;
        *scoreA++ = num + NUM_0_BLOCK_A;
        *scoreB++ = num + NUM_0_BLOCK_B;
    }else if(score>999){
        *scoreA++ = 0;
        *scoreB++ = 0;

        num = tpScore/1000;
        *scoreA++ = num + NUM_0_BLOCK_A;
        *scoreB++ = num + NUM_0_BLOCK_B;
        
        tpScore = tpScore - num*1000;
        num = tpScore/100;
        *scoreA++ = num + NUM_0_BLOCK_A;
        *scoreB++ = num + NUM_0_BLOCK_B;

        tpScore = tpScore - num*100;
        num = tpScore/10;
        *scoreA++ = num + NUM_0_BLOCK_A;
        *scoreB++ = num + NUM_0_BLOCK_B;

        tpScore = tpScore - num*10;
        num = tpScore/1;
        *scoreA++ = num + NUM_0_BLOCK_A;
        *scoreB++ = num + NUM_0_BLOCK_B;
    }else if(score>99){
        *scoreA++ = 0;
        *scoreB++ = 0;
        *scoreA++ = 0;
        *scoreB++ = 0;

        num = tpScore/100;
        *scoreA++ = num + NUM_0_BLOCK_A;
        *scoreB++ = num + NUM_0_BLOCK_B;

        tpScore = tpScore - num*100;
        num = tpScore/10;
        *scoreA++ = num + NUM_0_BLOCK_A;
        *scoreB++ = num + NUM_0_BLOCK_B;

        tpScore = tpScore - num*10;
        num = tpScore/1;
        *scoreA++ = num + NUM_0_BLOCK_A;
        *scoreB++ = num + NUM_0_BLOCK_B;
    }else{  // less than 99
        *scoreA++ = 0;
        *scoreB++ = 0;
        *scoreA++ = 0;
        *scoreB++ = 0;

        num = tpScore/10;
        if(num){
            *scoreA++ = num + NUM_0_BLOCK_A;
            *scoreB++ = num + NUM_0_BLOCK_B;
        }else{
            *scoreA++ = 0;
            *scoreB++ = 0;

        }

        tpScore = tpScore - num*10;
        num = tpScore/1;
        *scoreA++ = num + NUM_0_BLOCK_A;
        *scoreB++ = num + NUM_0_BLOCK_B;

        *scoreA++ = 0;
        *scoreB++ = 0;
    }
}

void    DisplayGameOver()
{
    int i;
    for(i=0;i<GAME_OVER_LEN;i++){
        scrBuf[GAME_OVER_A+i] = GAME_OVER_BLOCK_A + i;
        scrBuf[GAME_OVER_B+i] = GAME_OVER_BLOCK_B + i;
    }
}

void    DisplayGamePause()
{
    int i;
    for(i=0;i<PAUSE_LEN;i++){
        scrBuf[PAUSE_A+i] = PAUSE_BLOCK_A + i;
        scrBuf[PAUSE_B+i] = PAUSE_BLOCK_B + i;
    }
}


