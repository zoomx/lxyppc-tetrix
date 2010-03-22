#include "Tetris.h"

#define     MATRIX_SIZE     32
#define     MATRIX_MASK     31
#define     MAT_ROW_CNT     20
#define     MAT_COL_CNT     10

#define     MAP_MASK        0xFFFF
#define     MAP_OFFSET      3
#define     MAT_ROW_MASK     ((1<<MAT_COL_CNT) - 1)

#define     PATTEN_CNT       7
#define     COLOR_CNT        8

#define     ExtendBit(x)        ( ((x&1)<<24) | ((x&2)<<15) | ((x&4)<<6) | ((x&8)>>3))
const   unsigned long   BitExtend[16] =
{
    ExtendBit(0x0),ExtendBit(0x1),ExtendBit(0x2),ExtendBit(0x3),
    ExtendBit(0x4),ExtendBit(0x5),ExtendBit(0x6),ExtendBit(0x7),
    ExtendBit(0x8),ExtendBit(0x9),ExtendBit(0xA),ExtendBit(0xB),
    ExtendBit(0xC),ExtendBit(0xD),ExtendBit(0xE),ExtendBit(0xF),
};

typedef    unsigned char    PattenMap[4];

typedef union   MatrixLine
{
    unsigned char   rowData8[16];
    unsigned short  rowData16[8];
    unsigned long   rowData32[4];
    struct  {
        unsigned char  Data[10];
        unsigned char  Dummy0[6];
    };
    struct  {
        unsigned char  Dummy1[12];
        unsigned short BitMap;
        unsigned char  preLine;
        unsigned char  nextLine;
    };
    struct  {
        unsigned char  Dummy3[16];
    };
}MatrixLine;

typedef union  BlockDesc
{
    unsigned long   row32[8];           //32
    unsigned short  row16[16];
    unsigned char   row8[32];
    struct{
        unsigned char   BlockData[16];  //16
        unsigned short  BlockBits[4];   //8
        const PattenMap*  patten;       //4
        signed   char  x;               //1
        signed   char  y;               //1
        unsigned char  rotate;          //1
        signed   char  color;           //1
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
    {0x06,0x03,0x00,0x00},{0x02,0x06,0x04,0x00},
    {0x06,0x03,0x00,0x00},{0x02,0x06,0x04,0x00},
    // S
    {0x00,0x03,0x06,0x00},{0x04,0x06,0x02,0x00},
    {0x00,0x03,0x06,0x00},{0x04,0x06,0x02,0x00},
    // T
    {0x00,0x07,0x02,0x00},{0x02,0x06,0x02,0x00},
    {0x00,0x02,0x07,0x00},{0x02,0x03,0x02,0x00},
    // line
    {0x04,0x04,0x04,0x04},{0x00,0x0F,0x00,0x00},
    {0x04,0x04,0x04,0x04},{0x00,0x0F,0x00,0x00},
};

MatrixLine      matrix[MATRIX_SIZE];
unsigned    int   matrixStart;
unsigned    int   matrixEnd;
BlockDesc       curBlock;
BlockDesc       nextBlock;
unsigned    int  score = 0;
void            ScoreUp(int line);

void    InitialMatrix();
void    CreateBlock(BlockDesc* block);
int     CheckBlock(BlockDesc* block, signed char x, signed char y, unsigned char rotate);
int     MoveBlock(BlockDesc* block, signed char x, signed char y, unsigned char rotate);
void    CopyBlock(BlockDesc* des, const BlockDesc* src);

int     DropBlock(BlockDesc* block);
unsigned char   firstLine = 0;
unsigned char   curLine = 0;
void    GetCurrentLine(signed char pos);

int     TetrisPlay(int param)
{
    static int flag = 0;
    if(!flag){
        flag = 1;
        InitialMatrix();
        CreateBlock(&curBlock);

        // Create next block
        CreateBlock(&nextBlock);
        GetCurrentLine(curBlock.y);
    }

    //while(1)
    {
        int key;
        signed char dx = 0;
        signed char dy = 0;
        unsigned char rotate = 0; 
        DebugDump();

        // Check valid
        if(!CheckBlock(&curBlock,0,0,0)){
            // Game over
            printf("Game over!\n");
        }

        key = GetKey();
        switch(key){
            case KEY_LEFT:
                dx = -1;
                break;
            case KEY_RIGHT:
                dx = 1;
                break;
            case KEY_UP:
                rotate = 1;
                break;
            case KEY_DOWN:
                dy = 1;
                break;
            case KEY_PAUSE:
                break;
            default:
                dy = 1;
                break;
        }
        if(CheckBlock(&curBlock,dx,dy,rotate)){
            MoveBlock(&curBlock,dx,dy,rotate);
        }else if(dy){
            ScoreUp(DropBlock(&curBlock));
            CopyBlock(&curBlock,&nextBlock);
            CreateBlock(&nextBlock);
            GetCurrentLine(curBlock.y);
        }
    }
    return 0;
}

void  GetCurrentLine(signed char pos)
{
    curLine = firstLine;
    while(pos<0){
        pos++;
        curLine = matrix[curLine].preLine;
    }
}

void    InitialMatrix()
{
    unsigned int i;
    matrixStart = 4;
    matrixEnd = (matrixStart + MAT_ROW_CNT)&MATRIX_MASK;
    for(i=0;i<MATRIX_SIZE;i++){
        matrix[i].rowData32[0] = 0;
        matrix[i].rowData32[1] = 0;
        matrix[i].rowData32[2] = 0;
        matrix[i].rowData32[3] = 0;
        matrix[i].nextLine = i + 1;
        matrix[i].preLine = i - 1;
        //             ___11bits__ __10bits__ ___11bits__
        //             0123456789A 1234567890 0123456789A  // Ten bits
        //             0123456789A BCDEF01234 56789ABCDEF
        // Bit patten  11111111111 0000000000 11111111111
        if(i>=matrixStart && i<matrixEnd){
            matrix[i].BitMap = MAP_MASK - (MAT_ROW_MASK<<MAP_OFFSET);
        }else{
            matrix[i].BitMap = MAP_MASK;
        }
    }
    firstLine = matrixStart;
}

void    CreateBlock(BlockDesc* block)
{
    int rnd = Rand16();
    int color = Rand16()&7;
    int i;
    rnd &= 7;
    if(rnd>=PATTEN_CNT){
        rnd = Rand16()&3;
    }
    block->patten = pattens + rnd*4;
    block->rotate = Rand16()&3;
    block->x = 3;
    block->y = 0;
    block->color = color;
    rnd = 1;
    for(i=0;i<4;i++){
        unsigned char pat = block->patten[block->rotate][i];
        block->row32[i] = ExtendBit(pat)*(color+1);
        if(pat && rnd){
            block->y -= i;
            rnd = 0;
        }
    }
    if(rnd){
        printf("Error!");
    }
}

void    CopyBlock(BlockDesc* des, const BlockDesc* src)
{
    int i;
    for(i=0;i<sizeof(BlockDesc)/4;i++){
        des->row32[i] = src->row32[i];
    }
}

int     CheckBlock(BlockDesc* block, signed char x, signed char y, unsigned char rotate)
{
    int bx = x + block->x;
    unsigned int br = (block->rotate + rotate) & 3;
    int i;
    unsigned char line = curLine;
    while(y){
        y--;
        line = matrix[line].nextLine;
    }
    for(i=0;i<4;i++){
        unsigned long blockMap = block->patten[br][i];
        blockMap<<=(MAP_OFFSET+MAT_COL_CNT-bx-4);
        if(matrix[line].BitMap & blockMap){
            return 0;
        }
        line = matrix[line].nextLine;
    }
    return 1;
}

int     MoveBlock(BlockDesc* block, signed char dx, signed char dy, unsigned char rotate)
{
    int i;
    block->x+=dx;
    block->y+=dy;
    block->rotate=(block->rotate+rotate)&3;
    for(i=0;i<4;i++){
        unsigned char pat = block->patten[block->rotate][i];
        block->row32[i] = ExtendBit(pat)*(block->color+1);
    }
    while(dy){
        dy--;
        curLine = matrix[curLine].nextLine;
    }
    return 1;
}

int     DropBlock(BlockDesc* block)
{
    int bx = block->x;
    int by = block->y + matrixStart;
    unsigned int br = block->rotate;
    int i;
    int full = 0;
    unsigned char iMat = curLine;
    unsigned char iNext;
    for(i=0;i<4;i++){
        unsigned long blockMap = block->patten[br][i];
        if(iMat==matrixEnd)break;
        blockMap<<=(MAP_OFFSET+MAT_COL_CNT-bx-4);
        matrix[iMat].BitMap |= blockMap;
        if(matrix[iMat].BitMap == MAP_MASK){
            full++;
            // Clear this line
            matrix[iMat].rowData32[0] = 0;
            matrix[iMat].rowData32[1] = 0;
            matrix[iMat].rowData32[2] = 0;
            matrix[iMat].BitMap = MAP_MASK - (MAT_ROW_MASK<<MAP_OFFSET);

            // Remember next line
            iNext = matrix[iMat].nextLine;
            // Connect to next line
            matrix[matrix[iMat].preLine].nextLine = matrix[iMat].nextLine;
            matrix[iNext].preLine = matrix[iMat].preLine;

            // Move it to the first place
            matrix[iMat].preLine = matrix[firstLine].preLine;
            matrix[iMat].nextLine = firstLine;
            matrix[matrix[firstLine].preLine].nextLine = iMat;
            matrix[firstLine].preLine = iMat;
            firstLine = iMat;
            iMat = iNext;
        }else{
            unsigned long *p = (unsigned long *)(matrix[iMat].rowData8 + bx);
            unsigned char pat = block->patten[block->rotate][i];
            *p |= ExtendBit(pat)*(block->color+1);
            iMat = matrix[iMat].nextLine;
        }
    }
    //matrixStart = (matrixStart - full)&MATRIX_MASK;
    //matrixEnd = (matrixEnd - full)&MATRIX_MASK;
    return full;
}

void    DebugDump()
{
    int row;
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
                val = matrix[(row+matrixStart)&MATRIX_MASK].Data[col];
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
            printf(tmp&matrix[(row+matrixStart)&MATRIX_MASK].BitMap?"1":"0");
        }
        printf("\n");
    }
    printf("\n");
}

void            ScoreUp(int line)
{
    // 1 1
    // 2 3
    // 3 6
    // 4 12
    score += line*line - line/2;
}
