/*****************************************************************************
 *  Module for Microchip Graphics Library
 *  Himax. HX8257 TCON  driver
 *****************************************************************************
 * FileName:        TCON_HX8257.c
 * Dependencies:    Graphics.h
 * Processor:       PIC24, PIC32
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
 * Anton Alkhimenok     01/12/09
 *****************************************************************************/

#include "Graphics\Graphics.h"

#define CS      0x01
#define SCL     0x02
#define SDO     0x04

BYTE            value; 

void TCON_Delay()
{
WORD timeOut;
        timeOut = 200;
        while(timeOut--);
}

void TCON_CTRL(BYTE mask, BYTE level)
{
    if(level == 0){
        value &= ~mask;
    }else{
        value |= mask;
    }
    SetReg(0xAC, value);
}

void TCONWriteByte(BYTE value)
{
BYTE mask;

	mask = 0x80;
	while(mask)
	{
		TCON_CTRL(SCL,0);
        TCON_Delay();
		if(mask&value){
			TCON_CTRL(SDO,1);
		}else{
			TCON_CTRL(SDO,0);
		}
		TCON_CTRL(SCL,1);
		mask >>= 1;
	}
}

void GPIO_TCON(WORD index, WORD value)
{
	TCON_CTRL(CS,0);
    // Index
	TCONWriteByte(0x70);
	TCONWriteByte(((WORD_VAL)index).v[1]);
	TCONWriteByte(((WORD_VAL)index).v[0]);

	TCON_CTRL(CS,1);
    TCON_Delay();
	TCON_CTRL(CS,0);

    // Data
	TCONWriteByte(0x72);
	TCONWriteByte(((WORD_VAL)value).v[1]);
	TCONWriteByte(((WORD_VAL)value).v[0]);
	TCON_CTRL(CS,1);
    TCON_Delay();
}

void TCON_Init(void)
{
    SetReg(0xA8, CS|SDO|SCL);
    TCON_CTRL(CS,1);
	TCON_CTRL(SDO,1);
	TCON_CTRL(SCL,1);

    DelayMs(20);
	GPIO_TCON(0x0006, 0x2020);
    DelayMs(20);
}
