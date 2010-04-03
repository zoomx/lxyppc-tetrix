/*****************************************************************************
 *  Module for Microchip Graphics Library
 *  Himax HX8238 TCON driver
 *****************************************************************************
 * FileName:        TCON_HX8238.c
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
 * Anton Alkhimenok     11/17/08
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

    GPIO_TCON(0x0001,0x6300);//Driver Output Control
    GPIO_TCON(0x0002,0x0200);//LCD-Driving-Waveform Control:N-line inversion,N=0
    GPIO_TCON(0x0003,0x7184);//Power control 1:Set the step-up cycle of the step-up circuit for 262k-color mode
    DelayMs(100);
    GPIO_TCON(0x0004,0x0447);//Input Data and Color Filter Control
    GPIO_TCON(0x0005,0xb854);//Function Control

    GPIO_TCON(0X000a,0x4008);//Contrast/Brightness Control
//    GPIO_TCON(0X000a,0xff18);//Contrast/Brightness Control
    DelayMs( 40 );
    GPIO_TCON(0x000b,0xd400);//Frame Cycle Control
    GPIO_TCON(0x000d,0x123a);//Power Control 2
    DelayMs(200);
    GPIO_TCON(0x000e,0x3000);//Power Control 3
    DelayMs(200);
    GPIO_TCON(0x000f,0x0000);//Gate Scan Position
    GPIO_TCON(0x0016,0x9f80);//Horizontal Porch
    GPIO_TCON(0x0017,0x2212);//Vertical Porch
    DelayMs(200);
    GPIO_TCON(0x001e,0x00ef);//Set the VCOMH voltage
    DelayMs(200);

    GPIO_TCON(0x0030,0x0507);//Gamma Control
    GPIO_TCON(0x0031,0x0004);//Gamma Control
    GPIO_TCON(0x0032,0x0707);//Gamma Control
    GPIO_TCON(0x0033,0x0000);//Gamma Control
    GPIO_TCON(0x0034,0x0000);//Gamma Control
    GPIO_TCON(0x0035,0x0307);//Gamma Control
    GPIO_TCON(0x0036,0x0700);//Gamma Control
    GPIO_TCON(0x0037,0x0000);//Gamma Control
    GPIO_TCON(0x003a,0x140b);//Gamma Control
    GPIO_TCON(0x003b,0x140b);//Gamma Control
}
