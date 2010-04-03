/*****************************************************************************
 *  Module for Microchip Graphics Library
 *  Display driver selection
 *****************************************************************************
 * FileName:        DisplayDriver.c
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

#include "Graphics\Graphics.h"

#if (DISPLAY_CONTROLLER == CUSTOM_CONTROLLER)

#include "Drivers\CustomDisplayDriver.c"

#elif (DISPLAY_CONTROLLER == SSD1906)

#include "Drivers\SSD1906.c"

#elif  (DISPLAY_CONTROLLER == SSD1926)

#include "Drivers\SSD1926.c"

#elif  (DISPLAY_CONTROLLER == S6D0129)

#include "Drivers\drvTFT001.c"

#elif  (DISPLAY_CONTROLLER == S6D0139)

#include "Drivers\drvTFT001.c"

#elif  (DISPLAY_CONTROLLER == LGDP4531)

#include "Drivers\drvTFT001.c"

#elif  (DISPLAY_CONTROLLER == R61505)

#include "Drivers\drvTFT001.c"

#elif  (DISPLAY_CONTROLLER == SPFD5408)

#include "Drivers\drvTFT001.c"

#elif  (DISPLAY_CONTROLLER == SSD1339)

#include "Drivers\SSD1339.c"

#elif  (DISPLAY_CONTROLLER == ST7529)

#include "Drivers\ST7529.c"

#elif  (DISPLAY_CONTROLLER == SH1101A)

#include "Drivers\SH1101A_SSD1303.c"

#elif  (DISPLAY_CONTROLLER == SSD1303)

#include "Drivers\SH1101A_SSD1303.c"

#elif  (DISPLAY_CONTROLLER == HIT1270)

#include "Drivers\HIT1270.c"

#elif  (DISPLAY_CONTROLLER == UC1610)

#include "Drivers\UC1610.c"

#elif  (DISPLAY_CONTROLLER == ILI9320)

#include "Drivers\drvTFT001.c"

#elif  (DISPLAY_CONTROLLER == SSD1289)

#include "Drivers\SSD1289.c"

#elif  (DISPLAY_CONTROLLER == HX8347)

#include "Drivers\HX8347.c"

#elif  (DISPLAY_CONTROLLER == R61580)

#include "Drivers\drvTFT001.c"

#else

#error	GRAPHICS CONTROLLER IS NOT SUPPORTED

#endif
