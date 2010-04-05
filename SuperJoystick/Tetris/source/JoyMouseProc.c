/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : TetrisProc.c
* Author             : lxyppc
* Version            : V1.0
* Date               : 04/03/2010
* Description        : Tetris process implement
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "Procs.h"

#define IDX_ID    0
#define IDX_X     1
#define IDX_Y     2
#define IDX_RX    3
#define IDX_RY    4
#define IDX_RZ    5
#define IDX_BTN   6

#define IDX_MOUSE_BTN     1
#define IDX_MOUSE_X       2
#define IDX_MOUSE_Y       3
#define IDX_MOUSE_WHEEL   4

void  JoystickUIInit(void)
{
  SSD1303_FillScreen(0x00);
  TextOut(&dev,0,0,curLang[STR_JOYSTICK],0xFF);
  
  TextOut(&dev,0,16,curLang[STR_ABOUT_0],0xFF);
  TextOut(&dev,0,30,curLang[STR_ABOUT_1],0xFF);
  TextOut(&dev,0,45,curLang[STR_ABOUT_2],0xFF);
  bNeedUpdateUI = 1;
}

u8    JoyMouseBuffer[16];
static  u8  bMode = 0;    //  0 for normaol, 1 for air mouse
void  JoystickProcess(void)
{
  Msg msg = GetMessage();
  if(msg == MSG_SWITCH){
    CurrentProcess = MouseProcess;
    CurrentSystick = MouseSystick;
    MouseUIInit();
    for(u32 i=0;i<sizeof(JoyMouseBuffer);i++){
      JoyMouseBuffer[i] = 0;
    }
    JoyMouseBuffer[IDX_ID] = JOYSTICK_REPORT_ID;
    UserToPMABufferCopy(JoyMouseBuffer, GetEPTxAddr(ENDP2), 8);
    /* enable endpoint for transmission */
    SetEPTxCount(ENDP2, 8);
    SetEPTxValid(ENDP2);
  }else if(msg){
    JoyMouseBuffer[IDX_ID] = JOYSTICK_REPORT_ID;
    UserToPMABufferCopy(JoyMouseBuffer, GetEPTxAddr(ENDP2), 8);
    /* enable endpoint for transmission */
    SetEPTxCount(ENDP2, 8);
    SetEPTxValid(ENDP2);
  }
}
void  JoystickSystick(void)
{
  s8  pos = 0;
  s8 ad;
  if(IsKeyLeft()){ pos-=127;}
  if(IsKeyRight()){ pos+=127; }
  JoyMouseBuffer[IDX_X] = pos;
  pos = 0;
  if(IsKeyUp()){ pos-=127;}
  if(IsKeyDown()){ pos+=127;}
  JoyMouseBuffer[IDX_Y] = pos;
  
  ad = (ADCResult.ADX - 2048)/16;
  JoyMouseBuffer[IDX_RX] = ad;
  
  ad = (ADCResult.ADY - 2048)/16;
  JoyMouseBuffer[IDX_RY] = ad;
  
  ad = (ADCResult.ADZ - 2048)/16;
  JoyMouseBuffer[IDX_RZ] = ad;
  
  pos = 0;
  if(IsKey1()){ pos |= 1;}
  if(IsKey2()){ pos |= 2;}
  if(IsKey3()){ pos |= 4;}
  if(IsKey4()){ pos |= 8;}
  if(IsKeyL1()){pos |= 16;}
  if(IsKeyR1()){pos |= 32;}
  if(IsKeyL2()){pos |= 64;}
  if(IsKeyR2()){pos |= 128;}
  JoyMouseBuffer[IDX_BTN] = pos;
  pos = 0;
  if(IsKeySelect()){ pos|=1; }
  if(IsKeyPause()){ pos|=2; }
  JoyMouseBuffer[IDX_BTN+1] = pos;
  PostMessage(MSG_DUMMY);
}

void  MouseUIInit(void)
{
  SSD1303_FillScreen(0x00);
  TextOut(&dev,0,0,curLang[STR_MOUSE],0xFF);
  
  TextOut(&dev,0,16,curLang[STR_MOUSE_0],0xFF);
  TextOut(&dev,0,28,curLang[STR_MOUSE_1],0xFF);
  TextOut(&dev,0,40,curLang[STR_MOUSE_2],0xFF);
  TextOut(&dev,0,52,curLang[STR_MOUSE_3],0xFF);
  bNeedUpdateUI = 1;
  bMode = 0;
}

u16 adX = 2048;
u16 adY = 2048;
const char hex[]="0123456789ABCDEF";
void  UpdateBall(void)
{
  Pos_t x;
  {
    u8 buf[6] = {0x01,0,0,0,0,0x80};
    for(x=1;x<47;x++){
      SSD1303_DrawBlock(x,16,1,48,buf);
    }
  }
  {
    u8 buf[6] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
    SSD1303_DrawBlock(0,16,1,48,buf);
    SSD1303_DrawBlock(47,16,1,48,buf);
  }
  {
    //Pos_t x = adX*40 / 4096;
    //Pos_t y = adY*40 / 4096;
    Pos_t x = 40 - adY*40 / 4096;
    Pos_t y = 40 - adX*40 / 4096;
    u8 buf[4] = {6,15,15,6};
    SSD1303_DrawBlock(x-2+4,y-2+16+4,4,4,buf);
    bNeedUpdateUI = 1;
  }
}

void  MouseProcess(void)
{
  Msg msg = GetMessage();
  if(msg == MSG_SWITCH){
    CurrentProcess = KeyboardProcess;
    CurrentSystick = KeyboardSystick;
    KeyboardUIInit();
    for(u32 i=0;i<sizeof(JoyMouseBuffer);i++){
      JoyMouseBuffer[i] = 0;
    }
    JoyMouseBuffer[IDX_ID] = MOUSE_REPORT_ID;
    UserToPMABufferCopy(JoyMouseBuffer, GetEPTxAddr(ENDP2), 5);
    /* enable endpoint for transmission */
    SetEPTxCount(ENDP2, 5);
    SetEPTxValid(ENDP2);
  }else if(KEY_PAUSE == msg){
    bMode = !bMode;
    if(bMode){
      AirMouseUIInit();
    }else{
      MouseUIInit();
    }
  }else if(msg){
    JoyMouseBuffer[IDX_ID] = MOUSE_REPORT_ID;
    UserToPMABufferCopy(JoyMouseBuffer, GetEPTxAddr(ENDP2), 5);
    /* enable endpoint for transmission */
    SetEPTxCount(ENDP2, 5);
    SetEPTxValid(ENDP2);
    
    if(bMode){
      UpdateBall();
    }
  }
}

u8  mux = 1;
#define   MUX_MAX     20
static  u32 KeyPause = 0;
void  MouseSystick(void)
{
  s8  pos = 0;
  s8  x = 0;
  s8  y = 0;
  s8  delta = mux;
  if(IsKey4()){ pos |= 1;}
  if(IsKey2()){ pos |= 2;}
  if(IsKey3()){ pos |= 4;}
  JoyMouseBuffer[IDX_MOUSE_BTN] = pos;  
  
  if(IsKeyL1()){
    delta = MUX_MAX;
  }
  if(IsKeyL2()){
    delta = 1;
  }
  
  if(IsKeyLeft()){ x-=delta; }
  if(IsKeyRight()){ x+=delta; }
  if(IsKeyUp()){ y-=delta;}
  if(IsKeyDown()){ y+=delta;}
  adX = ADCResult.ADX;
  adY = ADCResult.ADY;
  if(x ==0 && y==0 && bMode){
    if(IsKey1()){
      // Air mouse mode,
      if(adX > 2048 + 512){
        y-= delta;
      }else if(adX<2048-512){
        y+= delta;
      }
      if(adY > 2048 + 512){
        x-= delta;
      }else if(adY<2048-512){
        x+= delta;
      }
    }
  }
  if(x || y){
    mux++;
    if(mux >MUX_MAX)mux = MUX_MAX;
  }else{
    mux = 1;
  }
  JoyMouseBuffer[IDX_MOUSE_X] = x;
  JoyMouseBuffer[IDX_MOUSE_Y] = y;
  
  pos = 0;
  if(IsKeyR1()){ pos+=1; }
  if(IsKeyR2()){ pos-=1; }
  JoyMouseBuffer[IDX_MOUSE_WHEEL] = pos;
  
  if(IsKeyPause()){
    KeyPause++;
  }else{
    if(KeyPause > 1){
      PostMessage(KEY_PAUSE);
    }
    KeyPause = 0;
  }
  PostMessage(MSG_DUMMY);
}

void  AirMouseUIInit(void)
{
  SSD1303_FillScreen(0x00);
  TextOut(&dev,0,0,curLang[STR_AIR_MOUSE],0xFF);
  bNeedUpdateUI = 1;
}
