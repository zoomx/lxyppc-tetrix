/*****************************************************************************
 *  Module for Microchip Graphics Library
 *  Main header file for the display driver
 *****************************************************************************
 * FileName:        DisplayDriver.h
 * Dependencies:    p24Fxxxx.h or plib.h
 * Processor:       PIC24F, PIC24H, dsPIC, PIC32
 * Compiler:       	MPLAB C30, MPLAB C32
 * Linker:          MPLAB LINK30, MPLAB LINK32
 * Company:         Microchip Technology Incorporated
 *
 * Software License Agreement
 *
 * Copyright © 2008 Microchip Technology Inc.  All rights reserved.
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
 * Anton Alkhimenok     09/04/08
 *****************************************************************************/

#ifndef _DISPLAYDRIVER_H
#define _DISPLAYDRIVER_H

#if (DISPLAY_CONTROLLER == CUSTOM_CONTROLLER)

#include "Graphics\CustomDisplayDriver.h"

#elif (DISPLAY_CONTROLLER == SSD1906)

#include "Graphics\SSD1906.h"

#elif  (DISPLAY_CONTROLLER == SSD1926)

#include "Graphics\SSD1926.h"

#elif  (DISPLAY_CONTROLLER == S6D0129)

#include "Graphics\drvTFT001.h"

#elif  (DISPLAY_CONTROLLER == S6D0139)

#include "Graphics\drvTFT001.h"

#elif  (DISPLAY_CONTROLLER == LGDP4531)

#include "Graphics\drvTFT001.h"

#elif  (DISPLAY_CONTROLLER == R61505)

#include "Graphics\drvTFT001.h"

#elif  (DISPLAY_CONTROLLER == SPFD5408)

#include "Graphics\drvTFT001.h"

#elif  (DISPLAY_CONTROLLER == SSD1339)

#include "Graphics\SSD1339.h"

#elif  (DISPLAY_CONTROLLER == ST7529)

#include "Graphics\ST7529.h"

#elif  (DISPLAY_CONTROLLER == SH1101A)

#include "Graphics\SH1101A_SSD1303.h"

#elif  (DISPLAY_CONTROLLER == SSD1303)

#include "Graphics\SH1101A_SSD1303.h"

#elif  (DISPLAY_CONTROLLER == HIT1270)

#include "Graphics\HIT1270.h"

#elif  (DISPLAY_CONTROLLER == UC1610)

#include "Graphics\UC1610.h"

#elif  (DISPLAY_CONTROLLER == ILI9320)

#include "Graphics\drvTFT001.h"

#elif  (DISPLAY_CONTROLLER == HX8347)

#include "Graphics\HX8347.h"

#elif  (DISPLAY_CONTROLLER == SSD1289)

#include "Graphics\SSD1289.h"

#elif  (DISPLAY_CONTROLLER == NO_CONTROLLER_DEFINED)

#elif  (DISPLAY_CONTROLLER == R61580)

#include "Graphics\drvTFT001.h"

#else

#error	GRAPHICS CONTROLLER IS NOT SUPPORTED

#endif

#endif
