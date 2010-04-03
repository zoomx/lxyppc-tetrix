/*****************************************************************************
 *  Module for Microchip Graphics Library
 *  UltraChip UC1610 LCD controllers driver
 *****************************************************************************
 * FileName:        UC1610.h
 * Dependencies:    p24Fxxxx.h
 * Processor:       PIC24
 * Compiler:       	MPLAB C30
 * Linker:          MPLAB LINK30
 * Company:         Microchip Technology Incorporated
 *
 * Software License Agreement
 *
 * Copyright © 2009 Microchip Technology Inc.  All rights reserved.
 * Microchip licenses to you the right to use, modify, copy and distribute
 * Software only when embedded on a Microchip microcontroller or digital
 * signal controller, which is integrated into your product or third party
 * product (pursuant to the sublicense terms in the accompanying license
 * agreement).  
 *
 * You should refer to the license agreement accompanying this Software
 * for additional information regarding your rights and obligations.
 *
 * SOFTWARE AND DOCUMENTATION ARE PROVIDED “AS IS” WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY
 * OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR
 * PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR
 * OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,
 * BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT
 * DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL,
 * INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA,
 * COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY
 * CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF),
 * OR OTHER SIMILAR COSTS.
 *
 * Author               Date        Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Anton Alkhimenok     02/25/09
 *****************************************************************************/
#ifndef _UC1610_H
#define _UC1610_H

#include <p24Fxxxx.h>

#include "GraphicsConfig.h"
#include "GenericTypeDefs.h"

/*********************************************************************
* Overview: Additional hardware-accelerated functions can be implemented
*           in the driver. These definitions exclude the PutPixel()-based
*           functions in the primitives layer (Primitive.c file) from compilation.
*********************************************************************/

// Define this to implement Font related functions in the driver.
//#define USE_DRV_FONT

// Define this to implement Line function in the driver.
//#define USE_DRV_LINE

// Define this to implement Circle function in the driver.
//#define USE_DRV_CIRCLE

// Define this to implement FillCircle function in the driver.
//#define USE_DRV_FILLCIRCLE

// Define this to implement Bar function in the driver.
//#define USE_DRV_BAR

// Define this to implement ClearDevice function in the driver.
#define USE_DRV_CLEARDEVICE

// Define this to implement PutImage function in the driver.
#define USE_DRV_PUTIMAGE

#ifdef USE_16BIT_PMP
#error  This driver doesn't support 16-bit PMP (remove USE_16BIT_PMP option from GraphicsConfig.h)
#endif

#ifndef DISP_HOR_RESOLUTION
#error  DISP_HOR_RESOLUTION must be defined in GraphicsConfig.h
#endif

#ifndef DISP_VER_RESOLUTION
#error  DISP_VER_RESOLUTION must be defined in GraphicsConfig.h
#endif

#ifndef COLOR_DEPTH
#error  COLOR_DEPTH must be defined in GraphicsConfig.h
#endif

#ifndef DISP_ORIENTATION
#error  DISP_ORIENTATION must be defined in GraphicsConfig.h
#endif

/*********************************************************************
* Overview: Horizontal and vertical screen size.
*********************************************************************/
#if (DISP_HOR_RESOLUTION != 160)
#error This driver doesn't supports this resolution. Horizontal resolution must be 160 pixels.
#endif
#if (DISP_VER_RESOLUTION != 100)
#error This driver doesn't supports this resolution. Vertical resolution must be 100 pixels.
#endif

/*********************************************************************
* Overview: Display orientation.
*********************************************************************/
#if (DISP_ORIENTATION != 0)
#error This driver doesn't support this orientation. It must be 0.
#endif

/*********************************************************************
* Overview: Color depth.
*********************************************************************/
#if (COLOR_DEPTH != 2)
#error This driver doesn't support this color depth. It should be 2.
#endif

#define CMD_DISPLAY_ON              0b10101111
#define CMD_DISPLAY_OFF             0b10101110

#define CMD_INVERSE_ON              0b10100111
#define CMD_INVERSE_OFF             0b10100110

#define CMD_PANEL_LOADING_16NF      0b00101000
#define CMD_PANEL_LOADING_21NF      0b00101001
#define CMD_PANEL_LOADING_28NF      0b00101010
#define CMD_PANEL_LOADING_38NF      0b00101011

#define CMD_LINE_RATE_12KLPS        0b10100000
#define CMD_LINE_RATE_13KLPS        0b10100001
#define CMD_LINE_RATE_14KLPS        0b10100010
#define CMD_LINE_RATE_16KLPS        0b10100011

#define CMD_DISPLAY_START           0b11110010
#define CMD_DISPLAY_END             0b11110011
#define CMD_COM_END                 0b11110001

#define CMD_BIAS_RATIO_5 		    0b11101000
#define CMD_BIAS_RATIO_10 		    0b11101001
#define CMD_BIAS_RATIO_11 		    0b11101010
#define CMD_BIAS_RATIO_12		    0b11101011

#define CMD_CONTRAST				0b10000001

#define CMD_RAM_ADDR_INCR_OFF       0b10001000
#define CMD_RAM_ADDR_INCR_ON        0b10001101

#define CMD_MAPPING_CTRL            0b11000000
#define CMD_MAPPING_MY              0b11000100
#define CMD_MAPPING_MX              0b11000010

#define CMD_WND_PRG_DISABLE			0b11111000
#define CMD_WND_PRG_ENABLE			0b11111001
#define CMD_START_COLUMN			0b11110100
#define CMD_START_PAGE			    0b11110101
#define CMD_END_COLUMN			    0b11110110
#define CMD_END_PAGE				0b11110111

#define CMD_COLUMN_ADDR_LSB		    0b00000000
#define CMD_COLUMN_ADDR_MSB		    0b00010000
#define CMD_PAGE_ADDR   			0b01100000

#define DISP_START_COLUMN			0
#define DISP_START_PAGE			    7
#define DISP_END_COLUMN			    159
#define DISP_END_PAGE				31


/*********************************************************************
* Overview: Clipping region control codes to be used with SetClip(...)
*           function. 
*********************************************************************/
#define CLIP_DISABLE       0 	// Disables clipping.
#define CLIP_ENABLE        1	// Enables clipping.

/*********************************************************************
* Overview: Some basic colors definitions.
*********************************************************************/

#define BLACK                0
#define GRAY1         	     1
#define GRAY0                2
#define WHITE                3

// Color
extern BYTE _color;

/*********************************************************************
* Overview: Clipping region control and border settings.
*
*********************************************************************/
// Clipping region enable control
extern SHORT _clipRgn;

// Left clipping region border
extern SHORT _clipLeft;
// Top clipping region border
extern SHORT _clipTop;
// Right clipping region border
extern SHORT _clipRight;
// Bottom clipping region border
extern SHORT _clipBottom;

/*********************************************************************
* Macros:  PMPWaitBusy()
*
* Overview: Delays execution for PMP cycle time.
*
* PreCondition: none
*
* Input: none
*
* Output: none
*
* Side Effects: none
*
********************************************************************/
#define PMPWaitBusy()  while(PMMODEbits.BUSY);


/*********************************************************************
* Macros:  WriteCmd(command)
*
* Overview: Writes a command.
*
* PreCondition: none
*
* Input: command
*
* Output: none
*
* Side Effects: none
*
********************************************************************/
#define WriteCmd(command)  DC_LAT_BIT=0;PMDIN1=command;PMPWaitBusy();DC_LAT_BIT=1;

/*********************************************************************
* Macros:  WriteData(data)
*
* Overview: Writes data.
*
* PreCondition: none
*
* Input: data
*
* Output: none
*
* Side Effects: none
*
********************************************************************/
#define WriteData(data)   PMDIN1=data;PMPWaitBusy();

/*********************************************************************
* Macros:  ReadData()
*
* Overview: Reads data.
*
* PreCondition: none
*
* Input: none
*
* Output: data
*
* Side Effects: none
*
********************************************************************/
#define ReadData()   PMDIN1;PMPWaitBusy();

/*********************************************************************
* Function:  void ResetDevice()
*
* Overview: Initializes LCD module.
*
* PreCondition: none
*
* Input: none
*
* Output: none
*
* Side Effects: none
*
********************************************************************/
void ResetDevice(void);

/*********************************************************************
* Macros:  GetMaxX()
*
* Overview: Returns maximum horizontal coordinate.
*
* PreCondition: none
*
* Input: none
*
* Output: Maximum horizontal coordinate.
*
* Side Effects: none
*
********************************************************************/
#define GetMaxX() (DISP_HOR_RESOLUTION-1)

/*********************************************************************
* Macros:  GetMaxY()
*
* Overview: Returns maximum vertical coordinate.
*
* PreCondition: none
*
* Input: none
*
* Output: Maximum vertical coordinate.
*
* Side Effects: none
*
********************************************************************/
#define GetMaxY() (DISP_VER_RESOLUTION-1)

/*********************************************************************
* Macros:  SetColor(color)
*
* Overview: Sets current drawing color.
*
* PreCondition: none
*
* Input: color - Color coded in 5:6:5 RGB format.
*
* Output: none
*
* Side Effects: none
*
********************************************************************/
#define SetColor(color) _color = (BYTE)(color&0x03);

/*********************************************************************
* Macros:  GetColor()
*
* Overview: Returns current drawing color.
*
* PreCondition: none
*
* Input: none
*
* Output: Color coded in 5:6:5 RGB format.
*
* Side Effects: none
*
********************************************************************/
#define GetColor() _color

/*********************************************************************
* Macros:  SetActivePage(page)
*
* Overview: Sets active graphic page.
*
* PreCondition: none
*
* Input: page - Graphic page number.
*
* Output: none
*
* Side Effects: none
*
********************************************************************/
#define SetActivePage(page)

/*********************************************************************
* Macros: SetVisualPage(page)
*
* Overview: Sets graphic page to display.
*
* PreCondition: none
*
* Input: page - Graphic page number
*
* Output: none
*
* Side Effects: none
*
********************************************************************/
#define SetVisualPage(page)

/*********************************************************************
* Function: void PutPixel(SHORT x, SHORT y)
*
* Overview: Puts pixel with the given x,y coordinate position.
*
* PreCondition: none
*
* Input: x - x position of the pixel.
*		 y - y position of the pixel.
*
* Output: none
*
* Side Effects: none
*
********************************************************************/
void PutPixel(SHORT x, SHORT y);

/*********************************************************************
* Function: WORD GetPixel(SHORT x, SHORT y)
*
* Overview: Returns pixel color at the given x,y coordinate position.
*
* PreCondition: none
*
* Input: x - x position of the pixel.
*		 y - y position of the pixel.
*
* Output: pixel color
*
* Side Effects: none
*
********************************************************************/
WORD GetPixel(SHORT x, SHORT y);

/*********************************************************************
* Macros: SetClipRgn(left, top, right, bottom)
*
* Overview: Sets clipping region.
*
* PreCondition: none
*
* Input: left - Defines the left clipping region border.
*		 top - Defines the top clipping region border.
*		 right - Defines the right clipping region border.
*	     bottom - Defines the bottom clipping region border.
*
* Output: none
*
* Side Effects: none
*
********************************************************************/
#define SetClipRgn(left,top,right,bottom) _clipLeft=left; _clipTop=top; _clipRight=right; _clipBottom=bottom;

/*********************************************************************
* Macros: GetClipLeft()
*
* Overview: Returns left clipping border.
*
* PreCondition: none
*
* Input: none
*
* Output: Left clipping border.
*
* Side Effects: none
*
********************************************************************/
#define GetClipLeft() _clipLeft

/*********************************************************************
* Macros: GetClipRight()
*
* Overview: Returns right clipping border.
*
* PreCondition: none
*
* Input: none
*
* Output: Right clipping border.
*
* Side Effects: none
*
********************************************************************/
#define GetClipRight() _clipRight

/*********************************************************************
* Macros: GetClipTop()
*
* Overview: Returns top clipping border.
*
* PreCondition: none
*
* Input: none
*
* Output: Top clipping border.
*
* Side Effects: none
*
********************************************************************/
#define GetClipTop() _clipTop

/*********************************************************************
* Macros: GetClipBottom()
*
* Overview: Returns bottom clipping border.
*
* PreCondition: none
*
* Input: none
*
* Output: Bottom clipping border.
*
* Side Effects: none
*
********************************************************************/
#define GetClipBottom() _clipBottom

/*********************************************************************
* Macros: SetClip(control)
*
* Overview: Enables/disables clipping.
*
* PreCondition: none
*
* Input: control - Enables or disables the clipping.
*			- 0: Disable clipping
*			- 1: Enable clipping
*
* Output: none
*
* Side Effects: none
*
********************************************************************/
#define SetClip(control) _clipRgn=control;

/*********************************************************************
* Macros: IsDeviceBusy()
*
* Overview: Returns non-zero if LCD controller is busy 
*           (previous drawing operation is not completed).
*
* PreCondition: none
*
* Input: none
*
* Output: Busy status.
*
* Side Effects: none
*
********************************************************************/
#define IsDeviceBusy()  0

/*********************************************************************
* Macros: SetPalette(colorNum, color)
*
* Overview:  Sets palette register.
*
* PreCondition: none
*
* Input: colorNum - Register number.
*        color - Color.
*
* Output: none
*
* Side Effects: none
*
********************************************************************/
#define SetPalette(colorNum, color)

/*********************************************************************
* Function:  void  DelayMs(WORD time)
*
* Overview: Delays execution on time specified in milliseconds.
*           The delay is correct only for 16MIPS.
*
* PreCondition: none
*
* Input: time - Delay in milliseconds.
*
* Output: none
*
* Side Effects: none
*
********************************************************************/
void DelayMs(WORD time);

/*********************************************************************
* Function: void ContrastSet(BYTE contrast)
*
* PreCondition: none
*
* Input: contrast value
*
* Output: none
*
* Side Effects: none
*
* Overview: sets contrast
*
* Note: none
*
********************************************************************/
void ContrastSet(BYTE contrast);

#endif // _UC1610_H
