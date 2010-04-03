/*****************************************************************************
 *  Module for Microchip Graphics Library
 *  Sino Wealth Microelectronic SH1101A OLED controller driver  
 *  Solomon Systech SSD1303 LCD controller driver
  *****************************************************************************
 * FileName:        SH1101A_SSD1303.c
 * Dependencies:    Graphics.h
 * Processor:       PIC24
 * Compiler:       	MPLAB C30
 * Linker:          MPLAB LINK30
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
 * Rodger Richey		03/10/07	Original
 * Paolo Tamayo			12/20/07	Ported to PIC24 Kit
 *****************************************************************************/
#include "Graphics\Graphics.h"

// Color
BYTE    _color;
// Clipping region control
SHORT _clipRgn;
// Clipping region borders
SHORT _clipLeft;
SHORT _clipTop;
SHORT _clipRight;
SHORT _clipBottom;

/*********************************************************************
* Function:  void  DelayMs(WORD time)
*
* PreCondition: none
*
* Input: time - delay in ms
*
* Output: none
*
* Side Effects: none
*
* Overview: delays execution on time specified in ms
*
* Note: delay is defined for 16MIPS
*
********************************************************************/
#if defined(__dsPIC33F__) || defined(__PIC24H__)
#define DELAY_1MS 40000/5  // for 40MIPS
void  DelayMs(WORD time){
unsigned delay;
	while(time--)
		for(delay=0; delay<DELAY_1MS; delay++);	
}
#elif defined(__PIC32MX__)
void  DelayMs(WORD time)
{
    while(time--)
    {
        unsigned int int_status;

        int_status = INTDisableInterrupts();
        OpenCoreTimer(GetSystemClock() / 2000);     // core timer is at 1/2 system clock
        INTRestoreInterrupts(int_status);

        mCTClearIntFlag();

        while(!mCTGetIntFlag());

    }

    mCTClearIntFlag();
}
#else
#define DELAY_1MS 16000/5  // for 16MIPS
void  DelayMs(WORD time){
unsigned delay;
	while(time--)
		for(delay=0; delay<DELAY_1MS; delay++);	
}
#endif

/*********************************************************************
* Function:  void ResetDevice()
*
* PreCondition: none
*
* Input: none
*
* Output: none
*
* Side Effects: none
*
* Overview: resets LCD, initializes PMP
*
* Note: none
*
********************************************************************/
void ResetDevice(void){

	// Set reset pin as output
    RST_TRIS_BIT = 0;
    // Hold in reset
    RST_LAT_BIT = 0;

	// Set up chip select signal to be IO controlled
	CS_TRIS_BIT = 0;
	CS_LAT_BIT = 1;       
 
#if defined(__dsPIC33F__) || defined(__PIC24H__) 
    // PMP setup 
    PMMODEbits.MODE  = 0b10;	// Master 2, controller pins should be set BS0=0,BS1=1,BS2=1 on board
    PMMODEbits.WAITB = 0b01;	// 1 tcy data set up
    PMMODEbits.WAITM = 0b0011;	// 3 tcy additional wait 
    PMMODEbits.WAITE = 0b00;	// 0 tcy data hold 
#else
    // PMP setup 
    PMMODEbits.MODE  = 0b10;	// Master 2, controller pins should be set BS0=0,BS1=1,BS2=1 on board
    PMMODEbits.WAITB = 0b01;	// 1 tcy data set up
    PMMODEbits.WAITM = 0b0010;	// 2 tcy additional wait 
    PMMODEbits.WAITE = 0b00;	// 0 tcy data hold 
#endif

    PMAENbits.PTEN0  = 1;		// Address line 0 is enabled
    PMAENbits.PTEN14 = 0;		// Address line 14 is used as an IO port

    PMCONbits.PTRDEN = 1;		// enable read strobe
    PMCONbits.PTWREN = 1;		// enable write strobe
    PMCONbits.PMPEN  = 1;		// enable PMP module

    // Reset controller
    RST_LAT_BIT = 1;
    DelayMs(20);
    RST_LAT_BIT = 0;
    DelayMs(20);
    RST_LAT_BIT = 1;
    DelayMs(20);

CS_LAT_BIT=0;

#if (DISPLAY_CONTROLLER == SH1101A)
	// Setup Display
	WriteCommand(0xAE);			// turn off the display (AF=ON, AE=OFF)
	WriteCommand(0xDB);			// set  VCOMH
	WriteCommand(0x23);			 
	WriteCommand(0xD9);			// set  VP
	WriteCommand(0x22);			 
	// Re-map
	WriteCommand(0xA1);			// [A0]:column address 0 is map to SEG0
								// [A1]:column address 131 is map to SEG0
	// COM Output Scan Direction
	WriteCommand(0xC8);			// C0 is COM0 to COMn, C8 is COMn to COM0
	// COM Pins Hardware Configuration
	WriteCommand(0xDA);			// set pins hardware configuration
	WriteCommand(0x12);
	// Multiplex Ratio
	WriteCommand(0xA8);			// set multiplex ratio
	WriteCommand(0x3F);			// set to 64 mux
	// Display Clock Divide
	WriteCommand(0xD5);			// set display clock divide
	WriteCommand(0xA0);			// set to 100Hz
	// Contrast Control Register
	WriteCommand(0x81);			// Set contrast control
	WriteCommand(0x60);			// display 0 ~ 127; 2C
	// Display Offset
	WriteCommand(0xD3);			// set display offset
	WriteCommand(0x00);			// no offset
	//Normal or Inverse Display
	WriteCommand(0xA6);			// Normal display
	WriteCommand(0xAD);			// Set DC-DC
	WriteCommand(0x8B);			// 8B=ON, 8A=OFF 
	// Display ON/OFF
	WriteCommand(0xAF);			// AF=ON, AE=OFF
	DelayMs(150);
	// Entire Display ON/OFF
	WriteCommand(0xA4);			// A4=ON
	// Display Start Line
	WriteCommand(0x40);			// Set display start line
	// Lower Column Address
	WriteCommand(0x00+OFFSET);	// Set lower column address
	// Higher Column Address
	WriteCommand(0x10);			// Set higher column address
    DelayMs(1);
#elif (DISPLAY_CONTROLLER == SSD1303)
	// Setup Display
	WriteCommand(0xAE);			// turn off the display (AF=ON, AE=OFF)
	WriteCommand(0xDB);			// set  VCOMH
	WriteCommand(0x23);			 
	WriteCommand(0xD9);			// set  VP
	WriteCommand(0x22);			 
	WriteCommand(0xAD);			// Set DC-DC
	WriteCommand(0x8B);			// 8B=ON, 8A=OFF 
	DelayMs(1);
	// Display ON/OFF
	WriteCommand(0xAF);			// AF=ON, AE=OFF
	// Init OLED display using SSD1303 driver
	// Display Clock Divide
	WriteCommand(0xD5);			// set display clock divide
	WriteCommand(0xA0);			// set to 100Hz
	// Display Offset
	WriteCommand(0xD3);			// set display offset
	WriteCommand(0x00);			// no offset
	// Multiplex Ratio
	WriteCommand(0xA8);			// set multiplex ratio
	WriteCommand(0x3F);			// set to 64 mux
	// Display Start Line
	WriteCommand(0x40);			// Set display start line
	// Re-map
	WriteCommand(0xA0);			// [A0]:column address 0 is map to SEG0
								// [A1]:column address 131 is map to SEG0
	// COM Output Scan Direction
	WriteCommand(0xC8);			// C0 is COM0 to COMn, C8 is COMn to COM0
	// COM Pins Hardware Configuration
	WriteCommand(0xDA);			// set pins hardware configuration
	WriteCommand(0x12);
	// Contrast Control Register
	WriteCommand(0x81);			// Set contrast control
	WriteCommand(0x60);			// display 0 ~ 127; 2C
	// Entire Display ON/OFF
	WriteCommand(0xA4);			// A4=ON
	//Normal or Inverse Display
	WriteCommand(0xA6);			// Normal display
	// Lower Column Address
	WriteCommand(0x00+OFFSET);	// Set lower column address
	// Higher Column Address
	WriteCommand(0x10);			// Set higher column address
    DelayMs(1);
#else
#error The controller is not supported.
#endif

CS_LAT_BIT=1;    
}


/*********************************************************************
* Function: void PutPixel(SHORT x, SHORT y)
*
* PreCondition: none
*
* Input: x,y - pixel coordinates
*
* Output: none
*
* Side Effects: none
*
* Overview: puts pixel
*
* Note: none
*
********************************************************************/
void PutPixel(SHORT x, SHORT y) {
BYTE page, add, lAddr, hAddr;
BYTE mask, display;

	// check if point is in clipping region
    if(_clipRgn){
        if(x<_clipLeft)
            return;
        if(x>_clipRight)
            return;
        if(y<_clipTop)
            return;
        if(y>_clipBottom)
            return;
    }

	// Assign a page address
    	 if(y < 8)  page = 0xB0;
	else if(y < 16) page = 0xB1;
	else if(y < 24) page = 0xB2;
	else if(y < 32) page = 0xB3;
	else if(y < 40) page = 0xB4;
	else if(y < 48) page = 0xB5;
	else if(y < 56) page = 0xB6;
	else            page = 0xB7;

	add = x+OFFSET;
	lAddr = 0x0F & add;				// Low address
	hAddr = 0x10 | (add >> 4);		// High address

	// Calculate mask from rows basically do a y%8 and remainder is bit position
	add = y>>3;						// Divide by 8
	add <<= 3;						// Multiply by 8
	add = y - add;					// Calculate bit position
	mask = 1 << add;				// Left shift 1 by bit position

	CS_LAT_BIT=0;

	SetAddress(page, lAddr, hAddr);	// Set the address (sets the page, 
									// lower and higher column address pointers)

	ReadData(display);				// Read to initiate Read transaction on PMP and dummy read
									// (requirement for data synchronization in the controller)
	ReadData(display);				// Read actual data from from display buffer

	ReadData(display);				// Read data from PMP register


	if(_color > 0)					// If non-zero for pixel on
		display |= mask;			// or in mask
	else							// If 0 for pixel off
		display &= ~mask;			// and with inverted mask
	SetAddress(page, lAddr, hAddr);	// Set the address (sets the page, 
									// lower and higher column address pointers)
	WriteData(display);				// restore the byte with manipulated bit
	
	CS_LAT_BIT = 1;
}

/*********************************************************************
* Function: BYTE GetPixel(SHORT x, SHORT y)
*
* PreCondition: none
*
* Input: x,y - pixel coordinates 
*
* Output: pixel color
*
* Side Effects: none
*
* Overview: return pixel color at x,y position
*
* Note: none
*
********************************************************************/
BYTE GetPixel(SHORT x, SHORT y){
BYTE page, add, lAddr, hAddr;
BYTE mask, temp, display;

	// check if point is in clipping region
    if(_clipRgn){
        if(x<_clipLeft)
            return 0;
        if(x>_clipRight)
            return 0;
        if(y<_clipTop)
            return 0;
        if(y>_clipBottom)
            return 0;
    }

	// Assign a page address
    	 if(y < 8)  page = 0xB0;
	else if(y < 16) page = 0xB1;
	else if(y < 24) page = 0xB2;
	else if(y < 32) page = 0xB3;
	else if(y < 40) page = 0xB4;
	else if(y < 48) page = 0xB5;
	else if(y < 56) page = 0xB6;
	else            page = 0xB7;

	add = x+OFFSET;
	lAddr = 0x0F & add;				// Low address
	hAddr = 0x10 | (add >> 4);		// High address

	// Calculate mask from rows basically do a y%8 and remainder is bit position
	temp = y>>3;					// Divide by 8
	temp <<= 3;						// Multiply by 8
	temp = y - temp;				// Calculate bit position
	mask = 1 << temp;				// Left shift 1 by bit position

	CS_LAT_BIT=0;

	SetAddress(page, lAddr, hAddr);	// Set the address (sets the page, 
									// lower and higher column address pointers)
	ReadData(display);				// Read to initiate Read transaction on PMP
	ReadData(display);				// Dummy Read (requirement for data synchronization in the controller)

	ReadData(display);				// Read data from display buffer


	CS_LAT_BIT=1;

	return (display & mask);		// mask all other bits and return the result	
}

/*********************************************************************
* Function: void ClearDevice(void)
*
* PreCondition: none
*
* Input: none
*
* Output: none
*
* Side Effects: none
*
* Overview: clears screen with current color 
*
* Note: none
*
********************************************************************/
void ClearDevice(void){
	BYTE i,j;
	CS_LAT_BIT = 0;
	for(i=0xB0;i<0xB8;i++) {			// Go through all 8 pages
		SetAddress(i,0x00,0x10);
		for(j=0;j<132;j++) {			// Write to all 132 bytes
			WriteData(_color);			
		}
	}
	CS_LAT_BIT = 1;
}
