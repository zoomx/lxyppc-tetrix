#ifndef   DRAWTEXT_H
#define   DRAWTEXT_H

typedef unsigned long Pos_t;
typedef unsigned long Size_t;
typedef unsigned long Color_t;


typedef   unsigned long  (*pfnDrawBlock_t)(
  Pos_t x,
  Pos_t y,
  Pos_t cx,
  Pos_t cy,
  const unsigned char* data);
typedef   unsigned long  (*pfnDrawPoint_t)(Pos_t x, Pos_t y, Color_t color);

#include "font.h"
typedef  struct _DeviceProp
{
  pfnDrawBlock_t    pfnDrawBlok;
  pfnDrawPoint_t    pfnDrawPoint;
  Size_t            xPixel;
  Size_t            yPixel;
}DeviceProp;

typedef  struct  _Device
{
  const DeviceProp*   pDevProp;
  pfnFontDrawChar     pfnFont;
  Pos_t               curX;
  Pos_t               curY;
}Device;




void  InitialDevice(Device* pDev, const DeviceProp* pDevProp, pfnFontDrawChar pfnFont);

unsigned long  TextOut_HighLight(
  Device* pDev,
  Pos_t x,
  Pos_t y,
  const char* text,
  Size_t len);

unsigned long SpecTextOut_HighLight(
  Device* pDev,
  Pos_t x,
  Pos_t y,
  pfnFontDrawChar pfnFont,
  Size_t len);

unsigned long HightLightArea(
  Pos_t x,
  Pos_t y,
  Pos_t cx,
  Pos_t cy);

unsigned long  TextOut(
  Device* pDev,
  Pos_t x,
  Pos_t y,
  const char* text,
  Size_t len);

unsigned long SpecTextOut(
  Device* pDev,
  Pos_t x,
  Pos_t y,
  pfnFontDrawChar pfnFont,
  Size_t len);

unsigned long SetPoint(
  Device* pDev,
  Pos_t x,
  Pos_t y);

unsigned long ClearPoint(
  Device* pDev,
  Pos_t x,
  Pos_t y);

#endif
