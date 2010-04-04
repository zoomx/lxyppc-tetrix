/*******************************************************************************
* File Name          : Keyboard.c
* Author             : lxyppc
* Version            : V1.0
* Date               : 04/03/2010
* Description        : Tetris process implement
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "Procs.h"

#define   KEY_CTRL      0x01
#define   KEY_SHIFT     0x02
#define   KEY_ALT       0x04
#define   KEY_GUI       0x08

static  vu8  modifyKey = 0;

extern  u8  keyboardLED;
extern  u8  keyboardLedChange;

#define   KEY_WIDTH     9
#define   CAPS_X        104

u8    curRow = 0;
u8    curCol = 0;

void (*pfnShowKey)(void);

const struct  KeyLayout
{
  const char* bufA;
  const char* bufB;
  Pos_t   x;
  u8      c;
  u8      s;
}keyLayout[] = {
  {
    "`1234567890-=\\",
    "~!@#$%^&*()_+|",
    0,0,14,
  },
  {
    "qwertyuiop[]",
    "QWERTYUIOP{}",
    9,10,2,
  },
  {
    "asdfghjkl;'",
    "ASDFGHJKL:\"",
    13,9,2,
  },
  {
    "zxcvbnm,./",
    "ZXCVBNM<>?",
    13,7,3,
  },
  {
    0,
    0,
    CAPS_X,1,0,
  },
};

const u8 IconLeftArr[24] = {
  0,32,112,248,172,34,32,32,32,32,32,0,
  0,0,0,0,1,2,0,0,0,0,0,0
};
const u8 IconRightArr[24] = {
  0,32,32,32,32,32,34,172,248,112,32,0,
  0,0,0,0,0,0,2,1,0,0,0,0
};
const u8 IconUpArr[24] = {
  0,32,16,24,12,254,12,24,16,32,0,0,
  0,0,0,0,0,7,0,0,0,0,0,0
};
const u8 IconDownArr[24] = {
  0,64,128,128,0,254,0,128,128,64,0,0,
  0,0,0,1,3,7,3,1,0,0,0,0
};

const u8 IconPowerOff[24] = {
  112,140,2,2,1,241,1,2,2,140,112,0,
  0,1,2,2,4,4,4,2,2,1,0,0
};

const u8 IconPowerSleep[24] = {
  112,140,0,0,0,31,0,0,0,140,112,0,
  0,1,2,2,4,4,4,2,2,1,0,0
};

const u8 IconPowerWakeup[24] = {
  112,140,2,114,129,97,129,114,2,140,112,0,
  0,1,2,2,4,4,4,2,2,1,0,0
};

const struct  FuncKey
{
  const u8* desc;
  u8          type;   // 0 for string, 1 for bitmap
  u8          width;  //
  u8          x;
  u8          y;
  u8          code;
  u8          l;
  u8          r;
  u8          u;
  u8          d;
}funcKey[] = 
{
  {"1",0,6,0,16,0x3A,27,1,18,12},    //0
  {"2",0,6,9,16,0x3B,0,2,18,12},    //1
  {"3",0,6,18,16,0x3C,1,3,19,13},    //2
  {"4",0,6,27,16,0x3D,2,4,19,13},    //3
  {"5",0,6,36,16,0x3E,3,5,20,14},    //4
  {"6",0,6,45,16,0x3F,4,6,20,14},    //5
  {"7",0,6,54,16,0x40,5,7,25,21},    //6
  {"8",0,6,63,16,0x41,6,8,25,21},    //7
  {"9",0,6,72,16,0x42,7,9,26,22},    //8
  {"10",0,12,81,16,0x43,8,10,26,22},    //9
  {"11",0,12,96,16,0x44,9,11,27,23},    //10
  {"12",0,12,111,16,0x45,10,12,27,23},    //11
/** Function Map
    0  1  2  3  4  5  6  7  8  9 10 11
     12    13    14    21   22    23
     15    16    17         24
     18    19    20    25   26    27
 */
  {"PSr",0,18,0,28,0x46,11,13,0,15},    //12
  {"Scr",0,18,24,28,0x47,12,14,2,16},    //13
  {"Brk",0,18,48,28,0x48,13,21,4,17},    //14
  
  {"Ins",0,18,0,40,0x49,23,16,12,18},    //15
  {"Hom",0,18,24,40,0x4A,15,17,13,19},    //16
  {"PUp",0,18,48,40,0x4B,16,24,14,20},    //17
  
  {"Del",0,18,0,52,0x4C,24,19,15,0},    //18
  {"End",0,18,24,52,0x4D,18,20,16,2},    //19
  {"PDn",0,18,48,52,0x4E,19,25,17,4},    //20
  
  {IconPowerOff,1,12,72,28,0x66,14,22,6,25},  //21
  {IconPowerSleep,1,12,90,28,0x66,21,23,8,24},  //22
  {IconPowerWakeup,1,12,108,28,0x66,22,15,10,27},  //23
  
  {IconUpArr,1,12,90,40,0x52,17,18,22,26},  //24
  
  {IconLeftArr,1,12,72,52,0x50,20,26,21,6},  //25
  {IconDownArr,1,12,90,52,0x51,25,27,24,8},  //26
  {IconRightArr,1,12,108,52,0x4F,26,0,23,10},  //27
  
};

void  HighLightFuncKey(void)
{
  HightLightArea(funcKey[curCol].x,funcKey[curCol].y,funcKey[curCol].width,12);
}

void  ShowFuncKey(void)
{
  for(u32 i=0;i<sizeof(funcKey)/sizeof(funcKey[0]);i++){
    if(funcKey[i].type){
      SSD1303_DrawBlock(funcKey[i].x,funcKey[i].y,funcKey[i].width,12,funcKey[i].desc);
    }else{
      TextOut(&dev,funcKey[i].x,funcKey[i].y,(const char*)funcKey[i].desc,0xFF);
    }
  }
  HighLightFuncKey();
}


void  HighLightMajorKey(void)
{
  Pos_t x = keyLayout[curRow].x + curCol*KEY_WIDTH;
  Pos_t y = curRow*12+16;
  if(curRow == 4){
    HightLightArea(keyLayout[curRow].x,52,6*4,12);
  }else{
    HightLightArea(x,y,6,12);
  }
}

void  ShowMajorKey(void)
{
  Pos_t x = 0;
  Pos_t y = 16;
  for(u32 row = 0;row<4;row++,y+=12){
    const char* buf;
    x = keyLayout[row].x;
    if(modifyKey & KEY_SHIFT){
      if(keyboardLED & CAPS_LOCK){
        buf = keyLayout[row].bufA;
      }else{
        buf = keyLayout[row].bufB;
      }
    }else{
      if(keyboardLED & CAPS_LOCK){
        buf = keyLayout[row].bufB;
      }else{
        buf = keyLayout[row].bufA;
      }
    }
    for(u32 i=0;i<keyLayout[row].c;i++){
      DrawChar(&dev,x,y,buf[i]);
      x+=KEY_WIDTH;
    }
    if(modifyKey & KEY_SHIFT){
      buf = keyLayout[row].bufB + keyLayout[row].c;
    }else{
      buf = keyLayout[row].bufA + keyLayout[row].c;
    }
    for(u32 i=0;i<keyLayout[row].s;i++){
      DrawChar(&dev,x,y,buf[i]);
      x+=KEY_WIDTH;
    }
  }
  if(keyboardLED & CAPS_LOCK){
    TextOut(&dev,CAPS_X,52,"CAPS",0xFF);
  }else{
    TextOut(&dev,CAPS_X,52,"caps",0xFF);
  }
  HighLightMajorKey();
}

void  MoveHighLight(u8 dir)
{
  if(pfnShowKey == ShowFuncKey){
    switch(dir){
    case KEY_Left:
      curCol = funcKey[curCol].l;
      return;
    case KEY_Up:
      curCol = funcKey[curCol].u;
      return;
    case KEY_Right:
      curCol = funcKey[curCol].r;
      return;
    case KEY_Down:
      curCol = funcKey[curCol].d;
      return;
    default:
      return;
    }
  }
  switch(dir){
  case KEY_Left:
    if(curCol){
      curCol--;
      break;
    }else{
      curCol--;
    }
  case KEY_Up:
    if(curRow){curRow--;}
    else{curRow = 4;}
    if(curCol >= keyLayout[curRow].c+keyLayout[curRow].s){
      curCol = keyLayout[curRow].c+keyLayout[curRow].s - 1;
    }
    break;
  case KEY_Right:
    if(curCol<keyLayout[curRow].c+keyLayout[curRow].s-1){
      curCol++;
      break;
    }else{
      curCol = 0;
    }
  case KEY_Down:
    if(curRow<4){curRow++;}
    else{curRow = 0;}
    if(curCol >= keyLayout[curRow].c+keyLayout[curRow].s){
      curCol = keyLayout[curRow].c+keyLayout[curRow].s - 1;
    }
    break;
  default:
    break;
  }
}

void  UpdateLEDStatus(void)
{
  char status[] = "ncs";
  if(keyboardLED & NUM_LOCK){ status[0] = 'N'; }
  if(keyboardLED & CAPS_LOCK){ status[1] = 'C'; }
  if(keyboardLED & SCROLL_LOCK){ status[2] = 'S'; }
  DrawChar(&dev,100,0,status[0]);
  DrawChar(&dev,110,0,status[1]);
  DrawChar(&dev,120,0,status[2]);
}

void  KeyboardUIInit(void)
{
  SSD1303_FillScreen(0x00);
  TextOut(&dev,0,0,curLang[STR_KEYBOARD],0xFF);
  UpdateLEDStatus();
  curRow = 0;
  curCol = 0;
  pfnShowKey = ShowMajorKey;
  pfnShowKey();
  bNeedUpdateUI = 1;
}

u8  GetKeyCode(void)
{
  if(pfnShowKey == ShowFuncKey){
      return funcKey[curCol].code;
  }
  if(curRow<4 && curRow>0){
    u8 ch = keyLayout[curRow].bufA[curCol];
    if(curCol<keyLayout[curRow].c){
      return ch - 'a' + 0x04;
    }else{
      switch(curRow){
      case 1:
        return 0x2F + curCol - keyLayout[curRow].c;
      case 2:
        return 0x33 + curCol - keyLayout[curRow].c;
      case 3:
        return 0x36 + curCol - keyLayout[curRow].c;
      default:
        return 0;
      }
    }
  }else if(curRow == 0){
    if(curCol == 0){
      return 0x32;
    }else if(curCol>12){
      return 0x31;
    }else if(curCol > 10){
      return 0x2D - 11 + curCol;
    }else{
      return 0x1e - 1 + curCol;
    }
  }else{
    return 0x39;
  }
}

static u8    KeyboardBuffer[8];
void  KeyboardProcess(void)
{
  static  u8  lastModify = 0;
  u8  updateKey = 0;
  u8  sendKey = 0;
  u8 keyCode = 0;
  Msg msg = GetMessage();
  if(msg == MSG_SWITCH){
    CurrentProcess = SettingProcess;
    CurrentSystick = SettingSystick;
    SettingUIInit();
    for(u32 i=0;i<sizeof(KeyboardBuffer);i++){
      KeyboardBuffer[i] = 0;
    }
    UserToPMABufferCopy(KeyboardBuffer, GetEPTxAddr(ENDP3), 8);
    /* enable endpoint for transmission */
    SetEPTxCount(ENDP3, 8);
    SetEPTxValid(ENDP3);
  }else if(msg){
    switch(msg){
    case KEY_UP:
    case KEY_DOWN:
    case KEY_LEFT:
    case KEY_RIGHT:
      if(modifyKey & KEY_CTRL){
        static const char arrCode[] = {0x50,0x4f,0x52,0x51};
        static char lastCode = 0;
        keyCode = arrCode[msg-1];
        if(keyCode != lastCode){
          sendKey = 1;
          modifyKey &= ~KEY_CTRL;
          lastModify |= 0x80;
        }else{
          keyCode = 0;
        }
        lastCode = keyCode;
      }else{
        MoveHighLight(msg);
        updateKey = 1;
      }
      break;
    case KEY_1_DOWN:
      sendKey = 1;
      keyCode = 0x29; // Escape
      break;
    case KEY_2_DOWN:
      sendKey = 1;
      keyCode = 0x28; // Enter
      break;
    case KEY_3_DOWN:
      sendKey = 1;
      keyCode = GetKeyCode();
      break;
    case KEY_4_DOWN:
      sendKey = 1;
      keyCode = 0x2A; // Backspace
      break;
    case KEY_SELECT_DOWN:
      sendKey = 1;
      keyCode = 0x2B; // Tab
      break;
    case KEY_1_UP:
    case KEY_2_UP:
    case KEY_3_UP:
    case KEY_4_UP:
    case KEY_SELECT_UP:
      sendKey = 1;
      keyCode = 0;
      break;
    case KEY_PAUSE_DOWN:
      if(modifyKey & KEY_CTRL){
      }else{
        sendKey = 1;
        keyCode = 0x2C;
      }
      break;
    case KEY_PAUSE_UP:
      if(modifyKey & KEY_CTRL){
        curRow = 0;
        curCol = 0;
        SSD1303_FillScreen(0x00);
        TextOut(&dev,0,0,curLang[STR_KEYBOARD],0xFF);
        UpdateLEDStatus();
        if(pfnShowKey == ShowMajorKey){
          pfnShowKey = ShowFuncKey;
          DrawChar(&dev,60,0,'F');
        }else{
          pfnShowKey = ShowMajorKey;
        }
        updateKey = 1;
      }else{
        sendKey = 1;
        keyCode = 0;
      }
      break;
    default:
      break;
    }
  }
  
  if(keyboardLedChange){
    keyboardLedChange = 0;
    UpdateLEDStatus();
    updateKey = 1;
    bNeedUpdateUI = 1;
  }
  if( ((lastModify ^ modifyKey) & KEY_SHIFT) || updateKey ){
    pfnShowKey();
    bNeedUpdateUI = 1;
  }
  if(lastModify ^ modifyKey){
    sendKey = 1;
  }
  
  if(sendKey){
    KeyboardBuffer[0] = modifyKey;
    KeyboardBuffer[1] = 0;
    KeyboardBuffer[2] = keyCode;
    UserToPMABufferCopy(KeyboardBuffer, GetEPTxAddr(ENDP3), 8);
    /* enable endpoint for transmission */
    SetEPTxCount(ENDP3, 8);
    SetEPTxValid(ENDP3);
  }
  lastModify = modifyKey;
}

static u32 KeyLeft = 0;
static u32 KeyRight = 0;
static u32 KeyUp = 0;
static u32 KeyDown = 0;
static u32 Key1 = 0;
static u32 Key2 = 0;
static u32 Key3 = 0;
static u32 Key4 = 0;
static u32 KeyPause = 0;
static u32 KeySelect = 0;


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

#define   JudgeKey3(key)  \
  if(IsKey##key##()){\
    Key##key##++;\
    if(Key##key##>1){\
      PostMessage(KEY_##key##_DOWN);\
    }\
  }else{\
    if(Key##key##>1){\
      PostMessage(KEY_##key##_UP);\
    }\
    Key##key## = 0;\
  }  

void  KeyboardSystick(void)
{
  if(IsKeyL2()){ modifyKey |= KEY_CTRL; }
  else         { modifyKey &= ~KEY_CTRL; }
  
  if(IsKeyL1()){ modifyKey |= KEY_SHIFT; }
  else         { modifyKey &= ~KEY_SHIFT; }
  
  if(IsKeyR2()){ modifyKey |= KEY_ALT; }
  else         { modifyKey &= ~KEY_ALT; }
  
  if(IsKeyR1()){ modifyKey |= KEY_GUI; }
  else         { modifyKey &= ~KEY_GUI; }
  
  JudgeKey3(1);
  JudgeKey3(2);
  JudgeKey3(3);
  JudgeKey3(4);
  JugeKey(Up);
  JugeKey(Down);
  JugeKey(Left);
  JugeKey(Right);
  if(IsKeyPause()){
    KeyPause++;
    if(KeyPause == 2){
      PostMessage(KEY_PAUSE_DOWN);
    }
  }else{
    if(KeyPause > 1){
      PostMessage(KEY_PAUSE_UP);
    }
    KeyPause = 0;
  }
  
  if(IsKeySelect() && (!IsKeyL2())){
    KeySelect++;
    if(KeySelect == 2){
      PostMessage(KEY_SELECT_DOWN);
    }
  }else{
    if(KeySelect > 1){
      PostMessage(KEY_SELECT_UP);
    }
    KeySelect = 0;
  }
}

