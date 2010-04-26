/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : TetrisProc.c
* Author             : lxyppc
* Version            : V1.0
* Date               : 04/03/2010
* Description        : Tetris process implement
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "Procs.h"

u8 bSwitchable = 0;
void  TetrisProcess(void)
{
  Msg msg = GetMessage();
  if(msg){
    static GameResult lastResult = GR_NoChange;
    GameResult result = TetrisPlay(msg);
    UpdateUI(result);
    if(lastResult != result || msg == MSG_DUMMY){
      TetrisUIInit();
    }
    lastResult = result;
    if(msg == MSG_SWITCH){
      if(bSwitchable){
        CurrentProcess = JoystickProcess;
        CurrentSystick = JoystickSystick;
        JoystickUIInit();
      }else{
        TextOut(&dev,10,45,curLang[STR_TETRIS_SWITCH],0xFF);
      }
    }
  }
}

void  TetrisUIInit(void)
{
  SSD1303_FillScreen(0x00);
  TextOut(&dev,0,0,curLang[STR_TETRIS],0xFF);
  if(gameState == GR_Pause){
    TextOut(&dev,10,16,curLang[STR_TETRIS_PAUSE],0xFF);
    bSwitchable = 1;
  }else if(gameState == GR_Over || gameState == GR_Init){
    TextOut(&dev,10,16,curLang[STR_TETRIS_OVER],0xFF);
    bSwitchable = 1;
  }else{
    bSwitchable = 0;
    TextOut(&dev,10,16,curLang[STR_TETRIS_PLAY],0xFF);
  }
  
  if(bCameraOn){
    TextOut(&dev,10,30,curLang[STR_CAMERA_ON],0xFF);
  }else{
    TextOut(&dev,10,30,curLang[STR_CAMERA_OFF],0xFF);
  }
  bNeedUpdateUI = 1;
}

u32 KeyLeft = 0;
u32 KeyRight = 0;
u32 KeyUp = 0;
u32 KeyDown = 0;
u32 KeyPause = 0;
u32 KeyDrop = 0;
#define   JugeKey(key)  \
  if(IsKey##key##()){\
    Key##key##++;\
    if(Key##key## >= 4){\
      PostMessage(KEY_##key##);\
      Key##key## = 2;\
      flag = 1;\
    }\
  }else{\
    Key##key## = 0;\
  }

#define   JugeKey2(key)  \
  if(IsKey##key##()){\
    Key##key##++;\
    if(Key##key## > 20){\
      Key##key## = 20;\
    }\
  }else{\
    if(Key##key## > 2){\
      PostMessage(KEY_##key##);\
      flag = 1;\
    }\
    Key##key## = 0;\
  }
extern unsigned    int  level;
u8  lastCamrea = 0;
void  TetrisSystick(void)
{
    u32     flag = 0;
    if(IsKeyLeft() || IsKeyL1()){
      KeyLeft++;
      if(KeyLeft >= 3){
        PostMessage(KEY_LEFT);
        KeyLeft = 1;
        flag = 1;
      }
    }else{
      KeyLeft = 0;
    }
    
    if(IsKeyRight() || IsKeyR1()){
      KeyRight++;
      if(KeyRight >= 3){
        PostMessage(KEY_RIGHT);
        KeyRight = 1;
        flag = 1;
      }
    }else{
      KeyRight = 0;
    }
    
    if(IsKeyDown() || IsKey3()){
      KeyDown++;
      if(KeyDown >= 3){
        PostMessage(KEY_DOWN);
        KeyDown = 1;
        flag = 1;
      }
    }else{
      KeyDown = 0;
    }
    
    if(IsKey3()){
      KeyDrop++;
      if(KeyDrop > 20){
        KeyDrop = 20;
      }
    }else{
      if(KeyDrop > 1){
        PostMessage(KEY_DROP);
        flag = 1;
      }
      KeyDrop = 0;
    }
    
    if(IsKeyUp() || IsKey2() || IsKey1()){
      KeyUp++;
      if(KeyUp > 20){
        KeyUp = 20;
      }
    }else{
      if(KeyUp > 1){
        PostMessage(KEY_UP);
        flag = 1;
      }
      KeyUp = 0;
    }
    
    JugeKey2(Pause);
    if(!flag){
      static  unsigned int timeCnt = 0;
      timeCnt++;
      if(level>14 || timeCnt >= 15 - level){
        timeCnt = 0;
        PostMessage(KEY_Down);
      }
    }
    if(lastCamrea != bCameraOn){
      PostMessage(MSG_DUMMY);
    }
  lastCamrea = bCameraOn;
}


