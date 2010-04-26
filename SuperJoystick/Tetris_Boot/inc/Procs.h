#ifndef   PROCS_H
#define   PROCS_H

#include "stm32f10x_lib.h"
#include "usb_lib.h"
#include "usb_desc.h"
#include "hw_config.h"
#include "usb_prop.h"
#include "stm32f10x_it.h"
#include "Task.h"
#include "Tetris.h"
#include "HidDevice.h"
#include "bsp.h"
#include "SSD1303.h"
#include "DrawText.h"
#include "StringResource.h"
#include "TetrisProc.h"
#include "JoyMouseProc.h"
#include "KeyboardProc.h"
#include "SettingProc.h"


extern  Device dev;
extern  const LPCSTR* curLang;
extern  u8 bNeedUpdateUI;
extern  GameResult  gameState;
extern void  (*CurrentProcess)(void);
extern void  (*CurrentSystick)(void);
extern  volatile unsigned char   bCameraOn;

#endif

