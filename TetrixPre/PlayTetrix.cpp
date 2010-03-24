#include "StdAfx.h"
#include "TetrixPre.h"
#include "TetrixPreDlg.h"
#include "Stream.h"

extern  unsigned char scrBuf[437];
#include "..\Tetris\Tetris.c"
DWORD WINAPI Playtetris(LPVOID pVoid)
{
    CTetrixPreDlg* pThis = (CTetrixPreDlg*)pVoid;
    TetrisPlay(pThis->m_keyCode);
    unsigned char iMat = firstLine;
    for(int row=0;row<20;row++){
        for(int col=0;col<10;col++){
            unsigned char val = 0;
            if( (row >= curBlock.y&& row<curBlock.y+4) && (col >= curBlock.x && col < curBlock.x +4)){
                val = curBlock.BlockData[ (row - curBlock.y)*4 + col - curBlock.x ];
            }
            if(!val){
                val = matrix[iMat].Data[col];
            }
            scrBuf[(row+1)*19+col+1] = val;//i+j+1;//TetrisMap[i*18 + j + 4];
                //matrix[(i+matrixStart) & MATRIX_MASK].Data[j];
        }
        iMat = matrix[iMat].nextLine;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            scrBuf[(i+4)*19+j+13] = //i+j+1;
                nextBlock.BlockData[i*4+j];
        }
    }
    static  int isd = 0;
    isd++;
    if(isd&1){
    // Game over
        //for(int i=154;i<=161;i++){
        //    scrBuf[i] = i;
        //}
        //for(int i=173;i<=180;i++){
        //    scrBuf[i] = i;
        //}
        //for(int i=231;i<=236;i++){
        //    scrBuf[i] = i;
        //}
        //for(int i=250;i<=255;i++){
        //    scrBuf[i] = i;
        //}
    }
    DisplayGameOver();
    DisplayGamePause();
    CDC* pDC = pThis->m_picDbg.GetDC();
    LONG cx = 8;
    LONG cy = 8;
    CBrush btrue(RGB(0,0,0));
    CBrush bfalse(RGB(255,50,255));
    CBrush* pold = pDC->SelectObject(&btrue);
    iMat = matrix[firstLine].preLine;
    for(int row=-1;row<MAT_ROW_CNT+1;row++){
        int col = 0;
        unsigned int tmp;
        for(tmp=0x8000;tmp;tmp>>=1){
            pDC->SelectObject(tmp&matrix[iMat].BitMap?
                &btrue:&bfalse);
            pDC->Rectangle(col*cx,row*cy + cy,col*cx+cx,row*cy+cy + cy);
            col++;
        }
        iMat = matrix[iMat].nextLine;
    }
    CString res;
    res.Format(_T("Score %3d"),score);
    pDC->TextOut(0,200,res);
    res.Format(_T("Level %02d"),level);
    pDC->TextOut(0,230,res);
    pDC->SelectObject(pold);
    pThis->m_picDbg.ReleaseDC(pDC);

    return 0;
}
