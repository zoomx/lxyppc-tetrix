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
  
  ad = (2048-ADCResult.ADY)/16;
  JoyMouseBuffer[IDX_RX] = ad;
  
  ad = (2048-ADCResult.ADX)/16;
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

#define   ADC_RESOLUTION     4096
#define   ADC_THRESHOLD      256
#define   UI_RANGE           48
#define   BALL_RANGE         40
#define   BALL_RADIUS        4
#define   UI_START           16

#define   THRESHOLD_WIDTH     (BALL_RANGE*ADC_THRESHOLD*2/ADC_RESOLUTION)

u16 adX = ADC_RESOLUTION/2;
u16 adY = ADC_RESOLUTION/2;
void  UpdateBall(void)
{
  Pos_t x;
  { // Draw the outline box horizontal line
    u8 buf[6] = {0x01,0,0,0,0,0x80};
    for(x=1;x<UI_RANGE-1;x++){
      SSD1303_DrawBlock(x,UI_START,1,UI_RANGE,buf);
    }
  }
  { // Draw the outline box vertical line
    u8 buf[6] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
    SSD1303_DrawBlock(0,UI_START,1,UI_RANGE,buf);
    SSD1303_DrawBlock(UI_RANGE-1,UI_START,1,UI_RANGE,buf);
  }
  {
    u16 buf = (1<<(THRESHOLD_WIDTH-1)) + 1;
    for(x=1+UI_RANGE/2-THRESHOLD_WIDTH/2;x<UI_RANGE/2+THRESHOLD_WIDTH/2-1;x++){
      SSD1303_DrawBlock(
        x,
        UI_START+UI_RANGE/2-THRESHOLD_WIDTH/2,
        1,THRESHOLD_WIDTH,(u8*)&buf);
    }
  }
  {
    u16 buf = (1<<(THRESHOLD_WIDTH)) - 1;
    SSD1303_DrawBlock(
      UI_RANGE/2-THRESHOLD_WIDTH/2,
      UI_START+UI_RANGE/2-THRESHOLD_WIDTH/2,
      1,THRESHOLD_WIDTH,(u8*)&buf);
    SSD1303_DrawBlock(
      UI_RANGE/2+THRESHOLD_WIDTH/2-1,
      UI_START+UI_RANGE/2-THRESHOLD_WIDTH/2,
      1,THRESHOLD_WIDTH,(u8*)&buf);
  }
  {
    //Pos_t x = adX*40 / 4096;
    //Pos_t y = adY*40 / 4096;
    Pos_t x = BALL_RANGE - adY*BALL_RANGE / ADC_RESOLUTION;
    Pos_t y = BALL_RANGE - adX*BALL_RANGE / ADC_RESOLUTION;
    u8 buf[4] = {6,15,15,6};  // ball
    SSD1303_DrawBlock(
      x-BALL_RADIUS/2+(UI_RANGE-BALL_RANGE)/2,
      y-BALL_RADIUS/2+UI_START+(UI_RANGE-BALL_RANGE)/2,
      BALL_RADIUS,
      BALL_RADIUS,buf);
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
  if(x ==0 && y==0 /*&& bMode*/){
    if(IsKey1()){
      // Air mouse mode,
      if(adX > ADC_RESOLUTION/2 + ADC_THRESHOLD){
        y-= delta;
      }else if(adX<ADC_RESOLUTION/2 - ADC_THRESHOLD){
        y+= delta;
      }
      if(adY > ADC_RESOLUTION/2 + ADC_THRESHOLD){
        x-= delta;
      }else if(adY<ADC_RESOLUTION/2 - ADC_THRESHOLD){
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
  
  TextOut(&dev,48,16,curLang[STR_AIR_MOUSE_0],0xFF);
  TextOut(&dev,48,28,curLang[STR_AIR_MOUSE_1],0xFF);
  TextOut(&dev,48,40,curLang[STR_AIR_MOUSE_2],0xFF);
  TextOut(&dev,48,52,curLang[STR_AIR_MOUSE_3],0xFF);
  bNeedUpdateUI = 1;
}
