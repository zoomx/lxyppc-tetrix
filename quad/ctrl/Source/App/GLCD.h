/*----------------------------------------------------------------------------
 * Name:    GLCD.h
 * Purpose: MCB1700 low level Graphic LCD (320x240 pixels) prototypes
 * Version: V1.00
 * Note(s):
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2009 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------
 * History:
 *          V1.00 Initial Version
 *----------------------------------------------------------------------------*/

#ifndef _GLCD_H
#define _GLCD_H

/*------------------------------------------------------------------------------
  color coding.
  GLCD is coded:   15..11 red, 10..5 green, 4..0 blue  (unsigned short)  GLCD_R5, GLCD_G6, GLCD_B5   
  original coding: 17..12 red, 11..6 green, 5..0 blue                    ORG_R6,  ORG_G6,  ORG_B6

  ORG_R1..5 = GLCD_R0..4,  ORG_R0 = GLCD_R4
  ORG_G0..5 = GLCD_G0..5,
  ORG_B1..5 = GLCD_B0..4,  ORG_B0 = GLCD_B4
 *------------------------------------------------------------------------------*/
/*硬件相关的宏定义*/
/********************************************************************************/
#define Set_Cs  GPIOC->BSRR  = 0x00000040;
#define Clr_Cs  GPIOC->BRR   = 0x00000040;

#define Set_Rs  GPIOD->BSRR  = 0x00002000;
#define Clr_Rs  GPIOD->BRR   = 0x00002000;

#define Set_nWr GPIOD->BSRR  = 0x00004000;
#define Clr_nWr GPIOD->BRR   = 0x00004000;

#define Set_nRd GPIOD->BSRR  = 0x00008000;
#define Clr_nRd GPIOD->BRR   = 0x00008000;
/********************************************************************************/
                             
/* GLCD RGB color definitions */
#define Black           0x0000		/*   0,   0,   0 */
#define Navy            0x000F      /*   0,   0, 128 */
#define DarkGreen       0x03E0      /*   0, 128,   0 */
#define DarkCyan        0x03EF      /*   0, 128, 128 */
#define Maroon          0x7800      /* 128,   0,   0 */
#define Purple          0x780F      /* 128,   0, 128 */
#define Olive           0x7BE0      /* 128, 128,   0 */
#define LightGrey       0xC618      /* 192, 192, 192 */
#define DarkGrey        0x7BEF      /* 128, 128, 128 */
#define Blue            0x001F      /*   0,   0, 255 */
#define Green           0x07E0      /*   0, 255,   0 */
#define Cyan            0x07FF      /*   0, 255, 255 */
#define Red             0xF800      /* 255,   0,   0 */
#define Magenta         0xF81F      /* 255,   0, 255 */
#define Yellow          0xFFE0      /* 255, 255, 0   */
#define White           0xFFFF      /* 255, 255, 255 */

#define Line0                0
#define Line1               24
#define Line2               48
#define Line3               72
#define Line4               96
#define Line5              120
#define Line6              144
#define Line7              168
#define Line8              192
#define Line9              216


extern void GLCD_init           (void);
extern void GLCD_clear          (unsigned short color);
extern void GLCD_setTextColor   (unsigned short color);
extern void GLCD_setBackColor   (unsigned short color);
extern void GLCD_displayChar    (unsigned int ln, unsigned int col, unsigned char  c);
extern void GLCD_displayStringLn(unsigned int ln, unsigned char *s);
extern void GLCD_bitmap         (unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned char *bitmap);
extern void GLCD_clearLn        (unsigned int ln);
extern void GLCD_putPixel       (unsigned int x, unsigned int y);
extern void GLCD_Test           (void);

#endif /* _GLCD_H */
