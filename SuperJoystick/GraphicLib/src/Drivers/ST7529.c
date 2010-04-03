/*****************************************************************************
 *  Module for Microchip Graphics Library
 *  Sitronix ST7529 controller driver
 *****************************************************************************
 * FileName:        ST7529.c
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
 * Anton Alkhimenok     03/20/08	
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
void PutImage8BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch);
void PutImage1BPPExt(SHORT left, SHORT top, void* bitmap, BYTE stretch);
void PutImage4BPPExt(SHORT left, SHORT top, void* bitmap, BYTE stretch);
void PutImage8BPPExt(SHORT left, SHORT top, void* bitmap, BYTE stretch);

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
#ifdef __PIC32MX
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

    // Disable LCD 
    CS_LAT_BIT = 1;
	CS_TRIS_BIT = 0;

    // Enable register select line
    RS_LAT_BIT = 1;
    RS_TRIS_BIT = 0;
       
    // Hold in reset
    RST_LAT_BIT = 0;
    RST_TRIS_BIT = 0;
    
    // PMP setup 
    PMMODE=0; PMCON=0; PMAEN=0;
    PMMODEbits.MODE  = 2;  // Master 2
    PMMODEbits.WAITB = 0;
#ifdef __PIC32MX
    PMMODEbits.WAITM = 13;
#else
	PMMODEbits.WAITM = 2;
#endif
    PMMODEbits.WAITE = 0;
    PMCONbits.CSF    = 0;
    PMCONbits.PTRDEN = 1;    
    PMCONbits.PTWREN = 1;
    PMCONbits.PMPEN  = 1; 

    // Relese from reset
    RST_LAT_BIT = 1;

    DelayMs(20);
    CS_LAT_BIT = 0;
    WriteCmd( EXTIN   ); //Ext = 0
    WriteCmd( SLPOUT  ); //Sleep Out
    WriteCmd( OSCON   ); //OSC On
    WriteCmd( PWRCTRL ); //Power Control Set
    WriteData( 0x08 ); //Booster Must Be On First
    DelayMs(2);
    WriteCmd( 0x20 ); //Power Control Set
    WriteData( 0x0B ); //Booster, Regulator, Follower ON
    WriteCmd( VOLCTRL ); //Electronic Control
    WriteData( 0x3f ); //Vop=18.0V
    WriteData( 0x04 );
    WriteCmd( DISCTRL ); //Display Control
    WriteData( 0x00 ); //CL=X1
    WriteData( 0x27 ); //Duty=160
    WriteData( 0x00 ); //FR Inverse-Set Value
    WriteCmd( DISNOR   ); // Normal Display
    WriteCmd( COMSCN   ); //COM Scan Direction
    WriteData( 0x01 ); // 0->79 159->80
    WriteCmd( DATSDR   ); //Data Scan Direction
#if (DISP_ORIENTATION == 180)
    WriteData( 0x01 ); //Row Reverse 
    WriteData( 0x00 ); //Derect 3 Pixels Arrangement
#else
    WriteData( 0x02 ); //Column Reverse
    WriteData( 0x01 ); //Inverse 3 Pixels Arrangement
#endif
    WriteData( 0x02 ); //3Byte 3Pixel mode
    WriteCmd( LASET     ); //Line Address Set(lines from 16 to 144 are used)
    WriteData( 0x10 ); //Start Line=16
    WriteData( 0x8f ); //End Line =144-1
    WriteCmd( CASET     ); //Column Address Set
    WriteData( 0x00 ); //Start Column=0
    WriteData( 0x54 ); //End Column =84 ((84+1)*3 == 255)
    WriteCmd( EXTOUT    ); //Ext = 1
    WriteCmd( ANASET    ); //Analog Circuit Set
    WriteData( 0x00 ); //OSC Frequency =000 (Default)
    WriteData( 0x01 ); //Booster Efficiency=01(Default)
    WriteData( 0x00 ); //Bias=1/14
    WriteCmd( SWINT     ); //Software Initial
    WriteCmd( EXTIN     ); //Ext = 0
    WriteCmd( DISON     ); //Display On
    CS_LAT_BIT = 1;
    DelayMs(100);
}

/*********************************************************************
* Function: void ContrastSet(WORD contrast)
*
* PreCondition: none
*
* Input: contrast value (LSB 10-0 are valid, MSB 15-11 are not used)
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
void ContrastSet(WORD contrast){
    CS_LAT_BIT = 0;
    WriteCmd( VOLCTRL ); //Electronic Control
    WriteData( (((WORD_VAL)contrast).v[0]) ); //Vop=18.0V
    WriteData( (((WORD_VAL)contrast).v[1]) ); //Vop=18.0V
    CS_LAT_BIT = 1;
}

/*********************************************************************
* Function: void ContrastUp(void)
*
* PreCondition: none
*
* Input: none
*
* Output: none
*
* Side Effects: none
*
* Overview: increases contrast
*
* Note: none
*
********************************************************************/
void ContrastUp(void){
    CS_LAT_BIT = 0;
    WriteCmd( VOLUP );
    CS_LAT_BIT = 1;
}

/*********************************************************************
* Function: void ContrastDown(void)
*
* PreCondition: none
*
* Input: none
*
* Output: none
*
* Side Effects: none
*
* Overview: decreases contrast
*
* Note: none
*
********************************************************************/
void ContrastDown(void){
    CS_LAT_BIT = 0;
    WriteCmd( VOLDOWN ); //Electronic Control
    CS_LAT_BIT = 1;
}

/*********************************************************************
* Function: void DisplayOn(void)
*
* PreCondition: none
*
* Input: none
*
* Output: none
*
* Side Effects: none
*
* Overview: turns on display
*
* Note: none
*
********************************************************************/
void DisplayOn(void){
    CS_LAT_BIT = 0;
    WriteCmd( DISON );
    CS_LAT_BIT = 1;
}

/*********************************************************************
* Function: void DisplayOn(void)
*
* PreCondition: none
*
* Input: none
*
* Output: none
*
* Side Effects: none
*
* Overview: turns off display
*
* Note: none
*
********************************************************************/
void DisplayOff(void){
    CS_LAT_BIT = 0;
    WriteCmd( DISOFF );
    CS_LAT_BIT = 1;
}

/*********************************************************************
* Function: void SleepIn(void)
*
* PreCondition: none
*
* Input: none
*
* Output: none
*
* Side Effects: none
*
* Overview: enters sleep mode
*
* Note: none
*
********************************************************************/
void SleepIn(void){
    CS_LAT_BIT = 0;
    WriteCmd( SLPIN );
    CS_LAT_BIT = 1;
}

/*********************************************************************
* Function: void WakeUp(void)
*
* PreCondition: none
*
* Input: none
*
* Output: none
*
* Side Effects: none
*
* Overview: wakes up from sleep
*
* Note: none
*
********************************************************************/
void WakeUp(void){
    CS_LAT_BIT = 0;
    WriteCmd( SLPOUT );
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
BYTE columnPixel[3]; // 3 Pixels in each column

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

    CS_LAT_BIT = 0;

    // Set Row and Column Address
    WriteCmd(LASET);
    WriteData(y+16);
    WriteData(0x8f);
    WriteCmd(CASET);
    WriteData(x/3);
    WriteData(0x54);

    // Read Column
    WriteCmd( RMWIN);
    columnPixel[0] = ReadData(); // Dummy reading
	PMPWaitBusy();
    columnPixel[0] = ReadData(); // Start reading cycle for pixel 0
    columnPixel[0] = ReadData(); // Start reading cycle for pixel 1
    columnPixel[1] = ReadData(); // Start reading cycle for pixel 2
    PMCONbits.PMPEN  = 0;   // Suspend PMP
    columnPixel[2] = ReadData(); // Read last value
    PMCONbits.PMPEN  = 1;   // Resume PMP
    
    // Modify pixel
    columnPixel[x%3] = _color;

    // Write Column
    WriteData(columnPixel[0]);
    WriteData(columnPixel[1]);
    WriteData(columnPixel[2]);

    WriteCmd( RMWOUT);
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
BYTE columnPixel[3]; // 3 Pixels in each column

    CS_LAT_BIT = 0;

    // Set Row and Column Address
    WriteCmd(LASET);
    WriteData(y+16);
    WriteData(0x8f);
    WriteCmd(CASET);
    WriteData(x/3);
    WriteData(0x54);

    // Read Column
    WriteCmd( RMWIN);
    columnPixel[0] = ReadData(); // Start reading cycle for pixel 0
    columnPixel[0] = ReadData(); // Start reading cycle for pixel 0
    columnPixel[0] = ReadData(); // Start reading cycle for pixel 1
    columnPixel[1] = ReadData(); // Start reading cycle for pixel 2
    PMCONbits.PMPEN  = 0;   // Suspend PMP
    columnPixel[2] = ReadData(); // Read last value
    PMCONbits.PMPEN  = 1;   // Resume PMP
   
    WriteCmd( RMWOUT);
    CS_LAT_BIT = 1;

    return columnPixel[x%3];
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

    CS_LAT_BIT = 0;

    // Whole screen
    WriteCmd( LASET     ); //Line Address Set(lines from 16 to 144 are used)
    WriteData( 0x10 ); //Start Line=16
    WriteData( 0x8f ); //End Line =144-1
    WriteCmd( CASET     ); //Column Address Set
    WriteData( 0x00 ); //Start Column=0
    WriteData( 0x54 ); //End Column =84 ((84+1)*3 == 255)

    WriteCmd( RAMWR );
    for(counter=0; counter<(WORD)(GetMaxX()+1)*(GetMaxY()+1); counter++){
        WriteData(_color);
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
                case 8:
                    PutImage8BPP(left, top, flashAddress, stretch);
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
                case 8:
                    PutImage8BPPExt(left, top, bitmap, stretch);
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
    flashAddress += 2;
    palette[1] = (BYTE)*(flashAddress+1);
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

/*********************************************************************
* Function: void PutImage8BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch)
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
* Overview: outputs 256 color image starting from left,top coordinates
*
* Note: image must be located in flash
*
********************************************************************/
void PutImage8BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch){
register FLASH_BYTE* flashAddress;
register FLASH_BYTE* tempFlashAddress;
WORD sizeX, sizeY;
WORD x,y;
WORD cx, cy;
BYTE temp;
BYTE stretchX, stretchY;
BYTE palette[256];
WORD counter;

    // Move pointer to size information
    flashAddress = bitmap + 2;

    // Read image size
    sizeY = *((FLASH_WORD*)flashAddress);
    flashAddress += 2;
    sizeX = *((FLASH_WORD*)flashAddress);
    flashAddress += 2;

    // Read pallete
    for(counter=0;counter<256;counter++){
        palette[counter] = (BYTE)*(flashAddress+1);
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
                // Read pixels from flash
                temp = *flashAddress;
                flashAddress++;

                // Set color
                SetColor(palette[temp]);

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

    palette[0] <<= 3;
    palette[1] <<= 3;

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
        palette[temp] <<= 3;
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

/*********************************************************************
* Function: void PutImage8BPPExt(SHORT left, SHORT top, void* bitmap, BYTE stretch)
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
void PutImage8BPPExt(SHORT left, SHORT top, void* bitmap, BYTE stretch){
register DWORD      memOffset;
BITMAP_HEADER       bmp;
WORD                palette[256];
BYTE                lineBuffer[(GetMaxX()+1)];
BYTE*               pData; 

BYTE                temp;
WORD                sizeX, sizeY;
WORD                x,y;
WORD                cx,cy;
BYTE                stretchX, stretchY;

    // Get bitmap header
    ExternalMemoryCallback(bitmap, 0, sizeof(BITMAP_HEADER), &bmp);

    // Get pallete (256 entries)
    ExternalMemoryCallback(bitmap, sizeof(BITMAP_HEADER), 256*sizeof(WORD), palette);

    for(temp=0; temp<32; temp++){
        palette[temp] <<= 3;
    }

    // Set offset to the image data
    memOffset = sizeof(BITMAP_HEADER) + 256*sizeof(WORD);

    // Get size
    sizeX = bmp.width;
    sizeY = bmp.height;

    cy = top;
    for(y=0; y<sizeY; y++){

        // Get line
        ExternalMemoryCallback(bitmap, memOffset, sizeX, lineBuffer);
        memOffset += sizeX;
        CS_LAT_BIT = 0;
        for(stretchY = 0; stretchY<stretch; stretchY++){

            pData = lineBuffer;
            cx = left;

            for(x=0; x<sizeX; x++){

                temp = *pData++;
                SetColor(palette[temp]);                    

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
