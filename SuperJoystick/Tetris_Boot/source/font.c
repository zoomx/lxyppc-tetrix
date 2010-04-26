/*******************************************************************************
* File Name          : font.c
* Author             : lxyppc
* Version            : V1.0
* Date               : 10-01-21
* Description        : Font data file
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "DrawText.h"
#include "font.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/* Install font data for "ËÎÌå¡¡Ð¡Îå"*/
#include ".\Font\SongSmall5.c"

unsigned long SongSmall5_DrawChar(pfnDrawBlock_t DrawBlock,Pos_t x, Pos_t y,unsigned int ch)
{
  if(DrawBlock == 0){
    if(ch>0x7f){
      if(x) return SongSmall5_Chinese_Width(ch);
      else  return SongSmall5_Chinese_Height(ch);
    }else{
      if(x) return SongSmall5_English_Width(ch);
      else  return SongSmall5_English_Height(ch);
    }
  }
  if(ch>0x7F){
    DrawBlock(x,y,12,12,SongSmall5_Chinese[ch-0x80].data);
    return SongSmall5_Chinese_Width(ch);
  }else if(ch>0x1F){
    DrawBlock(x,y,6,12,SongSmall5_English[ch-0x20].data);
  }else{
    DrawBlock(x,y,6,12,SongSmall5_English[0x7F-0x20].data);
  }
  return SongSmall5_English_Width(ch);
}
