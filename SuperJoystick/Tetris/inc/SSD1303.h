#ifndef   SSD1303_H
#define   SSD1303_H
#include "DrawText.h"

void  SSD1303_Init(void);
void  StartPageTransfer(void);
extern  const DeviceProp  SSD1303_Prop;
unsigned long SSD1303_DrawBlock(Pos_t x, Pos_t y, Pos_t cx, Pos_t cy, const unsigned char* data);
unsigned long SSD1303_IsOn(void);
unsigned long SSD1303_TurnOff(void);
unsigned long SSD1303_TurnOn(void);
unsigned char SSD1303_SetContrast(unsigned char contrast);
unsigned char SSD1303_GetContrast();
void  SSD1303_FillScreen(Color_t color);
#endif
