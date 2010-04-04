/*******************************************************************************
* File Name          : Setting.c
* Author             : lxyppc
* Version            : V1.0
* Date               : 04/03/2010
* Description        : Setting process implement
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "Procs.h"

u8  curSel = 0;


void  UpdateText(void)
{
  if(curSel == 0){
    TextOut_HighLight(&dev,10,16,curLang[STR_LANG_CHS],0xFF);
    TextOut(&dev,10,32,curLang[STR_LANG_ENG],0xFF);
    TextOut(&dev,10,48,curLang[STR_ABOUT],0xFF);
  }else if(curSel == 1){
    TextOut(&dev,10,16,curLang[STR_LANG_CHS],0xFF);
    TextOut_HighLight(&dev,10,32,curLang[STR_LANG_ENG],0xFF);
    TextOut(&dev,10,48,curLang[STR_ABOUT],0xFF);
  }else{
    TextOut(&dev,10,16,curLang[STR_LANG_CHS],0xFF);
    TextOut(&dev,10,32,curLang[STR_LANG_ENG],0xFF);
    TextOut_HighLight(&dev,10,48,curLang[STR_ABOUT],0xFF);
  }
  bNeedUpdateUI = 1;
}

void  SettingUIInit(void)
{
  SSD1303_FillScreen(0x00);
  TextOut(&dev,0,0,curLang[STR_SETTING],0xFF);
  UpdateText();
  bNeedUpdateUI = 1;
}

void  AboutUIInit(void)
{
  SSD1303_FillScreen(0x00);
  TextOut(&dev,0,0,curLang[STR_ABOUT],0xFF);
  
  TextOut(&dev,0,16,curLang[STR_ABOUT_0],0xFF);
  TextOut(&dev,0,30,curLang[STR_ABOUT_1],0xFF);
  TextOut(&dev,0,45,curLang[STR_ABOUT_2],0xFF);
  bNeedUpdateUI = 1;
}

void  AboutProcess(void)
{
  Msg msg = GetMessage();
  if(msg == KEY_3){
    CurrentProcess = SettingProcess;
    SettingUIInit();
  }
}

void  SettingProcess(void)
{
  Msg msg = GetMessage();
  if(msg == MSG_SWITCH){
    CurrentProcess = TetrisProcess;
    CurrentSystick = TetrisSystick;
    TetrisUIInit();
  }else if(msg == KEY_3){
    if(curSel == 0){
      curLang = StringTable_CHS;
      SettingUIInit();
    }else if(curSel == 1){
      curLang = StringTable_ENG;
      SettingUIInit();
    }else{
      CurrentProcess = AboutProcess;
      AboutUIInit();
    }
  }else if(msg == KEY_UP){
    if(curSel){
      curSel--;
    }else{
      curSel = 2;
    }
    UpdateText();
  }else if(msg == KEY_DOWN){
    if(curSel<2){
      curSel++;
    }else{
      curSel = 0;
    }
    UpdateText();
  }
}

static u32 Key3 = 0;
static u32 KeyUp = 0;
static u32 KeyDown = 0;

#define   JugeKey(key)  \
  if(IsKey##key##()){\
    Key##key##++;\
    if(Key##key## >= 3){\
      PostMessage(KEY_##key##);\
      Key##key## = 1;\
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
    if(Key##key## > 1){\
      PostMessage(KEY_##key##);\
    }\
    Key##key## = 0;\
  }

void  SettingSystick(void)
{
  JugeKey(Up);
  JugeKey(Down);
  JugeKey2(3);
}
