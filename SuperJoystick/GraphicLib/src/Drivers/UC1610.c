/*****************************************************************************
 *  Module for Microchip Graphics Library
 *  UltraChip UC1610 controller driver
 *****************************************************************************
 * FileName:        UC1610.c
 * Dependencies:    Graphics.h
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

/////////////////////// LOCAL FUNCTIONS PROTOTYPES ////////////////////////////
void PutImage1BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch);
void PutImage4BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch);
void PutImage1BPPExt(SHORT left, SHORT top, void* bitmap, BYTE stretch);
void PutImage4BPPExt(SHORT left, SHORT top, void* bitmap, BYTE stretch);

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
* Note: none
*
********************************************************************/
#define DELAY_1MS 16000/5  // for 16MIPS
void  DelayMs(WORD time){
unsigned delay;
	while(time--)
		for(delay=0; delay<DELAY_1MS; delay++);	
}

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
    // Disable LCD 
    CS_LAT_BIT = 1;
	CS_TRIS_BIT = 0;

    // Enable register select line
    DC_LAT_BIT = 1;
    DC_TRIS_BIT = 0;
       
    // Hold in reset
    RST_LAT_BIT = 0;
    RST_TRIS_BIT = 0;
    
    // PMP setup 
    PMMODE=0; PMCON=0; PMAEN=0;
    PMMODEbits.MODE  = 2;  // Master 2
    PMMODEbits.WAITB = 0;
	PMMODEbits.WAITM = 3;
    PMMODEbits.WAITE = 0;
    PMCONbits.CSF    = 0;
    PMCONbits.PTRDEN = 1;    
    PMCONbits.PTWREN = 1;
    PMCONbits.PMPEN  = 1; 

    // Release from reset
    RST_LAT_BIT = 1;

    DelayMs(20);
    CS_LAT_BIT = 0;

    // set Vbias
    WriteCmd(CMD_BIAS_RATIO_12);
    WriteCmd(CMD_CONTRAST);
    WriteCmd(82);

    // set panel loading
    WriteCmd(CMD_PANEL_LOADING_38NF);

    // set connected COM electrodes 
    WriteCmd(CMD_DISPLAY_START);
    WriteCmd(4*(DISP_START_PAGE+1)-1);
    WriteCmd(CMD_DISPLAY_END);
    WriteCmd(4*(DISP_END_PAGE+1)-1);
    WriteCmd(CMD_COM_END);
    WriteCmd(4*(DISP_END_PAGE+1)-1);

    // set line rate
    WriteCmd(CMD_LINE_RATE_12KLPS);
  
    WriteCmd(CMD_MAPPING_MY);

    // inverse color
    WriteCmd(CMD_INVERSE_ON);

    // set programm window
    WriteCmd(CMD_WND_PRG_DISABLE);
    WriteCmd(CMD_START_COLUMN);
    WriteCmd(DISP_START_COLUMN);    
    WriteCmd(CMD_END_COLUMN);
    WriteCmd(DISP_END_COLUMN);
    WriteCmd(CMD_START_PAGE);
    WriteCmd(DISP_START_PAGE);
    WriteCmd(CMD_END_PAGE);
    WriteCmd(DISP_END_PAGE);
    WriteCmd(CMD_WND_PRG_ENABLE);

    // set autoincrement
    WriteCmd(CMD_RAM_ADDR_INCR_ON);

    WriteCmd(CMD_DISPLAY_ON);

    CS_LAT_BIT = 1;
    DelayMs(10);
}

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
void ContrastSet(BYTE contrast){
    CS_LAT_BIT = 0;
    WriteCmd(CMD_CONTRAST);
    WriteCmd(contrast);
    CS_LAT_BIT = 1;
}

/*********************************************************************
* Function: void PutPixel(SHORT x, SHORT y)
*
* PreCondition: none
*
* Input: pixel position
*
* Output: none
*
* Side Effects: none
*
* Overview: puts pixel with current color at given position
*
* Note: none
*
********************************************************************/
void PutPixel(SHORT x, SHORT y){
BYTE value;

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

    x += DISP_START_COLUMN;

    CS_LAT_BIT = 0;

    // set address
    WriteCmd(CMD_COLUMN_ADDR_LSB|(x&0x0f));
    WriteCmd(CMD_COLUMN_ADDR_MSB|((x>>4)&0x0f));
    WriteCmd(CMD_PAGE_ADDR|(DISP_START_PAGE+(y>>2)));

    // read 4 pixels
    value = ReadData();    
    value = ReadData();    
    PMCONbits.PMPEN  = 0;  // suspend PMP
    value = PMDIN1;        // read value
    PMCONbits.PMPEN  = 1;  // resume PMP
    
    // set pixel
    switch(y&0x03){
        case 0:
            value &= 0b11111100;
            value |= _color;
            break;
        case 1:
            value &= 0b11110011;
            value |= _color<<2;
            break;
        case 2:
            value &= 0b11001111;
            value |= _color<<4;
            break;
        case 3:
            value &= 0b00111111;
            value |= _color<<6;
            break;
    }

    // set address
    WriteCmd(CMD_COLUMN_ADDR_LSB|(x&0x0f));
    WriteCmd(CMD_COLUMN_ADDR_MSB|((x>>4)&0x0f));
    WriteCmd(CMD_PAGE_ADDR|(DISP_START_PAGE+(y>>2)));
    // write 4 pixels back
    WriteData(value);

    CS_LAT_BIT = 1;
}

/*********************************************************************
* Function: WORD GetPixel(SHORT x, SHORT y)
*
* PreCondition: none
*
* Input: pixel position
*
* Output: pixel color
*
* Side Effects: none
*
* Overview: returns pixel at given position
*
* Note: none
*
********************************************************************/
WORD GetPixel(SHORT x, SHORT y){
BYTE value;

    x += DISP_START_COLUMN;

    CS_LAT_BIT = 0;

    // set address
    WriteCmd(CMD_COLUMN_ADDR_LSB|(x&0x0f));
    WriteCmd(CMD_COLUMN_ADDR_MSB|((x>>4)&0x0f));
    WriteCmd(CMD_PAGE_ADDR|(DISP_START_PAGE+(y>>2)));

    // read 4 pixels
    value = ReadData();    
    value = ReadData();    

    CS_LAT_BIT = 1;

    PMCONbits.PMPEN  = 0;  // suspend PMP
    value = PMDIN1;        // read value
    PMCONbits.PMPEN  = 1;  // resume PMP
    
    // get pixel
    switch(y&0x03){
        case 0:
			break;
        case 1:
            value >>= 2;
			break;
        case 2:
            value >>= 4;
			break;
        case 3:
            value >>= 6;
			break;
    }

    value &= 0x03;
    return value;
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
WORD     counter;
BYTE     pattern;

    pattern = _color;
    pattern |= pattern<<2;
    pattern |= pattern<<4;

    CS_LAT_BIT = 0;
    WriteCmd(CMD_COLUMN_ADDR_LSB|(DISP_START_COLUMN&0x0f));
    WriteCmd(CMD_COLUMN_ADDR_MSB|((DISP_START_COLUMN>>4)&0x0f));
    WriteCmd(CMD_PAGE_ADDR|DISP_START_PAGE);

    for(counter=0; counter<(DWORD)(GetMaxX()+1)*(GetMaxY()+1)/4; counter++){
        WriteData(pattern);
    }

    CS_LAT_BIT = 1;
}

/*********************************************************************
* Function: WORD PutImage(SHORT left, SHORT top, void* bitmap, BYTE stretch)
*
* PreCondition: none
*
* Input: left,top - left top image corner,
*        bitmap - image pointer,
*        stretch - image stretch factor
*
* Output: For NON-Blocking configuration:
*         - Returns 0 when device is busy and the image is not yet completely drawn.
*         - Returns 1 when the image is completely drawn.
*         For Blocking configuration:
*         - Always return 1.
*
* Side Effects: none
*
* Overview: outputs image starting from left,top coordinates
*
* Note: image must be located in flash
*
********************************************************************/
WORD PutImage(SHORT left, SHORT top, void* bitmap, BYTE stretch){
FLASH_BYTE* flashAddress;
BYTE colorDepth;
BYTE colorTemp;

    #ifndef USE_NONBLOCKING_CONFIG
        while(IsDeviceBusy() != 0); /* Ready */
    #else
        if(IsDeviceBusy() != 0) return 0;
    #endif

    // Save current color
    colorTemp = _color;

    switch(*((SHORT*)bitmap))
    {
#ifdef USE_BITMAP_FLASH
        case FLASH:
            // Image address
            flashAddress = ((BITMAP_FLASH*)bitmap)->address;
            // Read color depth
            colorDepth = *(flashAddress+1);
            // Draw picture
            switch(colorDepth){
                case 1:
                    PutImage1BPP(left, top, flashAddress, stretch);
                    break;
                case 4:
                    PutImage4BPP(left, top, flashAddress, stretch);
                    break;
                default:
                    break;
            }
            break;
#endif
#ifdef USE_BITMAP_EXTERNAL
        case EXTERNAL:
            // Get color depth
            ExternalMemoryCallback(bitmap, 1, 1, &colorDepth);
            // Draw picture
            switch(colorDepth){
                case 1:
                    PutImage1BPPExt(left, top, bitmap, stretch);
                    break;
                case 4:
                    PutImage4BPPExt(left, top, bitmap, stretch);
                    break;
                default:
                    break;
            }
            break;
#endif
        default:
            break;
    }

    // Restore current color
    _color = colorTemp;
    return 1;
}

#ifdef USE_BITMAP_FLASH
/*********************************************************************
* Function: void PutImage1BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch)
*
* PreCondition: none
*
* Input: left,top - left top image corner,
*        bitmap - image pointer,
*        stretch - image stretch factor
*
* Output: none
*
* Side Effects: none
*
* Overview: outputs monochrome image starting from left,top coordinates
*
* Note: image must be located in flash
*
********************************************************************/
void PutImage1BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch){
register FLASH_BYTE* flashAddress;
register FLASH_BYTE* tempFlashAddress;
BYTE temp;
WORD sizeX, sizeY;
WORD x,y;
WORD cx,cy;
BYTE stretchX,stretchY;
BYTE palette[2];
BYTE mask;

    // Move pointer to size information
    flashAddress = bitmap + 2;

    // Read image size
    sizeY = *((FLASH_WORD*)flashAddress);
    flashAddress += 2;
    sizeX = *((FLASH_WORD*)flashAddress);
    flashAddress += 2;
    palette[0] = (BYTE)*(flashAddress+1);
    palette[0] >>= 3;
    palette[0] &= 0x03;
    flashAddress += 2;
    palette[1] = (BYTE)*(flashAddress+1);
    palette[1] >>= 3;
    palette[1] &= 0x03;
    flashAddress += 2;

    CS_LAT_BIT = 0;
    cy = top;
    for(y=0; y<sizeY; y++){
        tempFlashAddress = flashAddress;
        for(stretchY = 0; stretchY<stretch; stretchY++){
            flashAddress = tempFlashAddress;
            cx = left;
            mask = 0;
            for(x=0; x<sizeX; x++){

                // Read 8 pixels from flash
                if(mask == 0){
                    temp = *flashAddress;
                    flashAddress++;
                    mask = 0x80;
                }
                
                // Set color
                if(mask&temp){
                    SetColor(palette[1]);
                }else{
                    SetColor(palette[0]);
                }

                // Write pixel to screen
                for(stretchX=0; stretchX<stretch; stretchX++){
                    PutPixel(cx++,cy);
                }

                // Shift to the next pixel
                mask >>= 1;
           }
           cy++;
        }
    }
    CS_LAT_BIT = 1;
}

/*********************************************************************
* Function: void PutImage4BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch)
*
* PreCondition: none
*
* Input: left,top - left top image corner, bitmap - image pointer,
*        stretch - image stretch factor
*
* Output: none
*
* Side Effects: none
*
* Overview: outputs 16 color image starting from left,top coordinates
*
* Note: image must be located in flash
*
********************************************************************/
void PutImage4BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch){
register FLASH_BYTE* flashAddress;
register FLASH_BYTE* tempFlashAddress;
WORD sizeX, sizeY;
WORD x,y;
WORD cx, cy;
BYTE temp;
register BYTE stretchX,stretchY;
BYTE palette[16];
WORD counter;

    // Move pointer to size information
    flashAddress = bitmap + 2;

    // Read image size
    sizeY = *((FLASH_WORD*)flashAddress);
    flashAddress += 2;
    sizeX = *((FLASH_WORD*)flashAddress);
    flashAddress += 2;

    // Read pallete
    for(counter=0;counter<16;counter++){
        palette[counter] = (BYTE)*(flashAddress+1);
        palette[counter] >>= 3;
        palette[counter] &= 0x03;
        flashAddress += 2;
    }

    CS_LAT_BIT = 0;     
    cy = top;
    for(y=0; y<sizeY; y++){
        tempFlashAddress = flashAddress;
        for(stretchY = 0; stretchY<stretch; stretchY++){
            flashAddress = tempFlashAddress;
            cx = left;
            for(x=0; x<sizeX; x++){
                // Read 2 pixels from flash
                if(x&0x0001){
                    // second pixel in byte
                    SetColor(palette[temp>>4]);
                }else{
                    temp = *flashAddress;
                    flashAddress++;
                    // first pixel in byte
                    SetColor(palette[temp&0x0f]);
                }

                // Write pixel to screen       
                for(stretchX=0; stretchX<stretch; stretchX++){
                    PutPixel(cx++,cy);
                }

            }
            cy++;
        }
    }
    CS_LAT_BIT = 1;
}
#endif
#ifdef USE_BITMAP_EXTERNAL
/*********************************************************************
* Function: void PutImage1BPPExt(SHORT left, SHORT top, void* bitmap, BYTE stretch)
*
* PreCondition: none
*
* Input: left,top - left top image corner, bitmap - image pointer,
*        stretch - image stretch factor
*
* Output: none
*
* Side Effects: none
*
* Overview: outputs monochrome image starting from left,top coordinates
*
* Note: image must be located in external memory
*
********************************************************************/
void PutImage1BPPExt(SHORT left, SHORT top, void* bitmap, BYTE stretch){
register DWORD      memOffset;
BITMAP_HEADER       bmp;
WORD                pallete[2];
BYTE                lineBuffer[((GetMaxX()+1)/8)+1];
BYTE*               pData; 
SHORT               byteWidth;

BYTE                temp;
BYTE                mask;
WORD                sizeX, sizeY;
WORD                x,y;
WORD                cx,cy;
BYTE                stretchX, stretchY;

    // Get bitmap header
    ExternalMemoryCallback(bitmap, 0, sizeof(BITMAP_HEADER), &bmp);

    // Get pallete (2 entries)
    ExternalMemoryCallback(bitmap, sizeof(BITMAP_HEADER), 2*sizeof(WORD), palette);

    palette[0] >>= 3;
    palette[0] &= 0x03;
    palette[1] >>= 3;
    palette[1] &= 0x03;

    // Set offset to the image data
    memOffset = sizeof(BITMAP_HEADER) + 2*sizeof(WORD);

    // Line width in bytes
    byteWidth = bmp.width>>3;
    if(bmp.width&0x0007)
        byteWidth++;

    // Get size
    sizeX = bmp.width;
    sizeY = bmp.height;

    cy = top;
    for(y=0; y<sizeY; y++){

        // Get line
        ExternalMemoryCallback(bitmap, memOffset, byteWidth, lineBuffer);
        memOffset += byteWidth;
        CS_LAT_BIT = 0;
        for(stretchY = 0; stretchY<stretch; stretchY++){
            pData = lineBuffer;
            cx = left;
            mask = 0;
            for(x=0; x<sizeX; x++){

                // Read 8 pixels from flash
                if(mask == 0){
                    temp = *pData++;
                    mask = 0x80;
                }
                
                // Set color
                if(mask&temp){
                    SetColor(palette[1]);
                }else{
                    SetColor(palette[0]);
                }

                // Write pixel to screen
                for(stretchX=0; stretchX<stretch; stretchX++){
                    PutPixel(cx++,cy);
                }

                // Shift to the next pixel
                mask >>= 1;
           }
           cy++;
        }
        CS_LAT_BIT = 1;
    }
}

/*********************************************************************
* Function: void PutImage4BPPExt(SHORT left, SHORT top, void* bitmap, BYTE stretch)
*
* PreCondition: none
*
* Input: left,top - left top image corner, bitmap - image pointer,
*        stretch - image stretch factor
*
* Output: none
*
* Side Effects: none
*
* Overview: outputs monochrome image starting from left,top coordinates
*
* Note: image must be located in external memory
*
********************************************************************/
void PutImage4BPPExt(SHORT left, SHORT top, void* bitmap, BYTE stretch){
register DWORD      memOffset;
BITMAP_HEADER       bmp;
WORD                palette[16];
BYTE                lineBuffer[((GetMaxX()+1)/2)+1];
BYTE*               pData; 
SHORT               byteWidth;

BYTE                temp;
WORD                sizeX, sizeY;
WORD                x,y;
WORD                cx,cy;
BYTE                stretchX, stretchY;

    // Get bitmap header
    ExternalMemoryCallback(bitmap, 0, sizeof(BITMAP_HEADER), &bmp);

    // Get pallete (16 entries)
    ExternalMemoryCallback(bitmap, sizeof(BITMAP_HEADER), 16*sizeof(WORD), palette);

    for(temp=0; temp<16; temp++){
        palette[temp] >>= 3;
        palette[temp] &= 0x03;
    }

    // Set offset to the image data
    memOffset = sizeof(BITMAP_HEADER) + 16*sizeof(WORD);

    // Line width in bytes
    byteWidth = bmp.width>>1;
    if(bmp.width&0x0001)
        byteWidth++;

    // Get size
    sizeX = bmp.width;
    sizeY = bmp.height;

    cy = top;
    for(y=0; y<sizeY; y++){

        // Get line
        ExternalMemoryCallback(bitmap, memOffset, byteWidth, lineBuffer);
        memOffset += byteWidth;
        CS_LAT_BIT = 0;
        for(stretchY = 0; stretchY<stretch; stretchY++){

            pData = lineBuffer;
            cx = left;

            for(x=0; x<sizeX; x++){

                // Read 2 pixels from flash
                if(x&0x0001){
                    // second pixel in byte
                    SetColor(palette[temp>>4]);
                }else{
                    temp = *pData++;
                    // first pixel in byte
                    SetColor(palette[temp&0x0f]);
                }

                // Write pixel to screen       
                for(stretchX=0; stretchX<stretch; stretchX++){
                    PutPixel(cx++,cy);
                }
           }
           cy++;
        }
        CS_LAT_BIT = 1;
    }
}
#endif
