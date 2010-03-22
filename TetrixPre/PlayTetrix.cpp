#include "StdAfx.h"
#include "TetrixPre.h"
#include "TetrixPreDlg.h"
#include "Stream.h"

#include "..\Tetris\Tetris.c"
extern  unsigned char scrBuf[437];
DWORD WINAPI Playtetris(LPVOID pVoid)
{
    CTetrixPreDlg* pThis = (CTetrixPreDlg*)pVoid;
    TetrisPlay(pThis->m_keyCode);
    for(int row=0;row<20;row++){
        for(int col=0;col<10;col++){
            unsigned char val = 0;
            if( (row >= curBlock.y&& row<curBlock.y+4) && (col >= curBlock.x && col < curBlock.x +4)){
                val = curBlock.BlockData[ (row - curBlock.y)*4 + col - curBlock.x ];
            }
            if(!val){
                val = matrix[(row+matrixStart)&MATRIX_MASK].Data[col];
            }
            scrBuf[(row+1)*19+col+1] = val;//i+j+1;//TetrisMap[i*18 + j + 4];
                //matrix[(i+matrixStart) & MATRIX_MASK].Data[j];
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            scrBuf[(i+4)*19+j+13] = //i+j+1;
                nextBlock.BlockData[i*4+j];
        }
    }

    CDC* pDC = pThis->m_picDbg.GetDC();
    LONG cx = 8;
    LONG cy = 8;
    CBrush btrue(RGB(0,0,0));
    CBrush bfalse(RGB(255,50,255));
    CBrush* pold = pDC->SelectObject(&btrue);
    for(int row=-1;row<MAT_ROW_CNT+1;row++){
        int col = 0;
        unsigned int tmp;
        for(tmp=0x8000;tmp;tmp>>=1){
            pDC->SelectObject(tmp&matrix[(row+matrixStart)&MATRIX_MASK].BitMap?
                &btrue:&bfalse);
            pDC->Rectangle(col*cx,row*cy,col*cx+cx,row*cy+cy);
            col++;
        }
    }
    pDC->SelectObject(pold);
    pThis->m_picDbg.ReleaseDC(pDC);

    return 0;
}