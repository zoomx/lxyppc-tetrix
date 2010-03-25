#include "StdAfx.h"
#include "TetrixPre.h"
#include "TetrixPreDlg.h"
#include "Stream.h"

extern  unsigned char scrBuf[437];
#include "..\STM32\Tetris\source\Tetris.c"
DWORD WINAPI Playtetris(LPVOID pVoid)
{
    CTetrixPreDlg* pThis = (CTetrixPreDlg*)pVoid;
    bCameraOn = 1;  // Camera always on
    GameResult gr = TetrisPlay(pThis->m_keyCode);
    UpdateUI(gr);


    CDC* pDC = pThis->m_picDbg.GetDC();
    LONG cx = 8;
    LONG cy = 8;
    CBrush btrue(RGB(0,0,0));
    CBrush bfalse(RGB(255,50,255));
    CBrush* pold = pDC->SelectObject(&btrue);
    unsigned char iMat = matrix[firstLine].preLine;
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

    return gr == GR_NoChange ? 0 : 1;
}
