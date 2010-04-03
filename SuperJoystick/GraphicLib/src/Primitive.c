/*****************************************************************************
 *  Module for Microchip Graphics Library
 *  Graphic Primitives Layer
 *****************************************************************************
 * FileName:        Primitive.c
 * Dependencies:    Graphics.h
 * Processor:       PIC24F, PIC24H, dsPIC, PIC32
 * Compiler:       	MPLAB C30 V3.00, MPLAB C32
 * Linker:          MPLAB LINK30, MPLAB LINK32
 * Company:         Microchip Technology Incorporated
 *
 * Software License Agreement
 *
 * Copyright ?2008 Microchip Technology Inc.  All rights reserved.
 * Microchip licenses to you the right to use, modify, copy and distribute
 * Software only when embedded on a Microchip microcontroller or digital
 * signal controller, which is integrated into your product or third party
 * product (pursuant to the sublicense terms in the accompanying license
 * agreement).  
 *
 * You should refer to the license agreement accompanying this Software
 * for additional information regarding your rights and obligations.
 *
 * SOFTWARE AND DOCUMENTATION ARE PROVIDED “AS IS?WITHOUT WARRANTY OF ANY
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
 * Anton Alkhimenok and
 * Paolo A. Tomayo      11/12/07    Version 1.0 release
 *****************************************************************************/
#include "Graphics\Graphics.h"

#define USE_PRIMITIVE_BEVEL

/////////////////////// LOCAL FUNCTIONS PROTOTYPES ////////////////////////////
void PutImage1BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch);
void PutImage4BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch);
void PutImage8BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch);
void PutImage16BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch);

void PutImage1BPPExt(SHORT left, SHORT top, void* bitmap, BYTE stretch);
void PutImage4BPPExt(SHORT left, SHORT top, void* bitmap, BYTE stretch);
void PutImage8BPPExt(SHORT left, SHORT top, void* bitmap, BYTE stretch);
void PutImage16BPPExt(SHORT left, SHORT top, void* bitmap, BYTE stretch);

// Current line type
SHORT _lineType;

// Current line thickness
BYTE _lineThickness;

// Font orientation
BYTE _fontOrientation;

// Current cursor x-coordinates
SHORT _cursorX;
// Current cursor y-coordinates
SHORT _cursorY;

// Pointer to the current font
void *_font;

#ifdef USE_PALETTE
 void *_palette;
#endif

// First and last characters in the font
WORD   _fontFirstChar;					// First character in the font table.
WORD   _fontLastChar;					// Last character in the font table.
// Installed font height
SHORT  _fontHeight;

/*********************************************************************
* Function:  void InitGraph(void)
*
* PreCondition: none
*
* Input: none
*
* Output: none
*
* Side Effects: none
*
* Overview: initializes LCD controller,
*           sets cursor position to upper left corner,
*           sets active and visual pages to page 0,
*           clears active page with BLACK,
*           sets color to WHITE,
*           disables clipping
*
* Note: none
*
********************************************************************/
void InitGraph(void){

    // Current line type
    SetLineType(SOLID_LINE);
    // Current line thickness
    SetLineThickness(NORMAL_LINE);
    // Current cursor coordinates to 0,0
    MoveTo(0,0);
    // Reset device
    ResetDevice();
    // Set active and visual pages
    SetActivePage(0);
    SetVisualPage(0);
    // Set color to BLACK
    SetColor(BLACK);
    // Clear screen
    ClearDevice();
    // Set color to WHITE
    SetColor(WHITE);
    // Disable clipping 
    SetClip(CLIP_DISABLE);
    // Set font orientation
    SetFontOrientation(ORIENT_HOR);
}

/*********************************************************************
* Function: WORD Arc(SHORT xL, SHORT yT, SHORT xR, SHORT yB, SHORT r1, SHORT r2, BYTE octant);
*
* PreCondition: none
*
* Input: xL, yT - location of the upper left center in the x,y coordinate
*		 xR, yB - location of the lower right left center in the x,y coordinate
*		 r1, r2 - the two concentric circle radii, r1 as the radius 
*				  of the smaller circle and and r2 as the radius of the 
*				  larger circle.
*		 octant - bitmask of the octant that will be drawn.
*				  Moving in a clockwise direction from x = 0, y = +radius
*                 bit0 : first octant 	bit4 : fifth octant
*                 bit1 : second octant  bit5 : sixth octant
*                 bit2 : third octant   bit6 : seventh octant
*                 bit3 : fourth octant  bit7 : eigth octant
*
* Output: For NON-Blocking configuration:
*         - Returns 0 when device is busy and the shape is not yet completely drawn.
*         - Returns 1 when the shape is completely drawn.
*         For Blocking configuration:
*         - Always return 1.
*
* Side Effects: none
*
* Overview: Draws the octant arc of a beveled figure with given centers, radii
*			and octant mask. When r1 is zero and r2 has some value, a filled 
*			circle is drawn; when the radii have values, an arc of
*			thickness (r2-r1) is drawn; when octant = 0xFF, a full ring 
*			is drawn. When r1 and r2 are zero, a rectangular object is drawn, where
*			xL, yT specifies the left top corner; xR, yB specifies the right bottom
*			corner.
*
* Note: none
*
********************************************************************/
WORD Arc(SHORT xL, SHORT yT, SHORT xR, SHORT yB, SHORT r1, SHORT r2, BYTE octant)
{
// this is using a variant of the Midpoint (Bresenham's) Algorithm

#ifndef USE_NONBLOCKING_CONFIG

	SHORT y1Limit, y2Limit;
	SHORT x1, x2, y1, y2;
	SHORT err1, err2;
	SHORT x1Cur, y1Cur, y1New;
	SHORT x2Cur, y2Cur, y2New;
	DWORD_VAL  temp;	

	temp.Val = SIN45*r1;
	y1Limit  = temp.w[1];
	temp.Val = SIN45*r2;
	y2Limit  = temp.w[1];

	temp.Val = (DWORD)(ONEP25 -((LONG)r1<<16));
	err1  = (SHORT)(temp.w[1]); 

	temp.Val = (DWORD)(ONEP25 -((LONG)r2<<16));
	err2  = (SHORT)(temp.w[1]); 

	x1 = r1; x2 = r2; y1 = 0; y2 = 0;

	x1Cur = x1; y1Cur = y1; y1New = y1;
	x2Cur = x2; y2Cur = y2; y2New = y2;

	while(y2<=y2Limit) {			// just watch for y2 limit since outer circle
									// will have greater value.
		// Drawing of the rounded panel is done only when there is a change in the
		// x direction. Bars are drawn to be efficient.
			
		// detect changes in the x position. Every change will mean a bar will be drawn 
		// to cover the previous area. y1New records the last position of y before the 
		// change in x position.


		// y1New & y2New records the last y positions, must remember this to
		// draw the correct bars (non-overlapping).
		y1New = y1;	y2New = y2;		

		if (y1 <= y1Limit) {
	 		if(err1 > 0) {
    			x1--;
    			err1 += 5;
    			err1 += (y1-x1)<<1;
   			} else {
    			err1 += 3;
    			err1 += y1<<1;
    		}
    		y1++;
		} else {
			y1++;
			if (x1 < y1)	
				x1 = y1;
		}
	
	 	if(err2 > 0) {
    		x2--;
    		err2 += 5;
    		err2 += (y2-x2)<<1;
   		} else {
    		err2 += 3;
    		err2 += y2<<1;
    	}
		y2++;	


		if ((x1Cur != x1) || (x2Cur != x2)) {
			if (octant&0x01) {
				Bar(xR+y2Cur, yT-x2Cur, xR+y1New, yT-x1Cur);	// 1st octant
			}
			if (octant&0x02) {
				Bar(xR+x1Cur, yT-y1New, xR+x2Cur, yT-y2Cur); 	// 2nd octant
			}
			if (octant&0x04) {
				Bar(xR+x1Cur, yB+y1Cur, xR+x2Cur, yB+y2New); 	// 3rd octant
			}
			if (octant&0x08) {
				Bar(xR+y1Cur, yB+x1Cur, xR+y2New, yB+x2Cur);	// 4th octant
			}
			if (octant&0x10) {
				Bar(xL-y1New, yB+x1Cur, xL-y2Cur, yB+x2Cur);	// 5th octant
			}
			if (octant&0x20) {
				Bar(xL-x2Cur, yB+y2Cur, xL-x1Cur, yB+y1New);	// 6th octant
			}
			if (octant&0x40) {
				Bar(xL-x2Cur, yT-y2New, xL-x1Cur, yT-y1Cur); 	// 7th octant
			}
			if (octant&0x80) {
				Bar(xL-y2New, yT-x2Cur, xL-y1Cur, yT-x1Cur);  	// 8th octant
	   		}
			// update current values
			x1Cur = x1;	y1Cur = y1; x2Cur = x2;	y2Cur = y2;

		} 
					
    } // end of while loop

	// draw the width and height     
   	if ((xR-xL) || (yB-yT)) {
		// draw right
		if (octant&0x02) {
			Bar(xR+r1,yT,xR+r2,(yB+yT)>>1); 
		}
		if (octant&0x04) {
			Bar(xR+r1,((yB+yT)>>1), xR+r2, yB); 
		}
		// draw bottom
		if (octant&0x10) {
			Bar(xL, yB+r1, ((xR+xL)>>1),yB+r2);
		}
		if (octant&0x08) {
			Bar(((xR+xL)>>1),yB+r1,xR,yB+r2);
		}
	
		if(xR-xL) {
   			// draw top
			if (octant&0x80) {
				Bar(xL, yT-r2, ((xR+xL)>>1),yT-r1);
			}
			if (octant&0x01) {
				Bar(((xR+xL)>>1),yT-r2,xR,yT-r1);
			}
   		}
	   	if (yT-yB) {
	   		// draw left
			if (octant&0x40) {
				Bar(xL-r2,yT,xL-r1,((yB+yT)>>1)); 			
			}
			if (octant&0x20) {
				Bar(xL-r2,((yB+yT)>>1),xL-r1,yB); 			
			}
	   	}
	} 
    
    return 1;
#else

typedef enum {
BEGIN,
QUAD11, BARRIGHT1,
QUAD12, BARRIGHT2,
QUAD21, BARLEFT1,
QUAD22, BARLEFT2,
QUAD31, BARTOP1,
QUAD32, BARTOP2,
QUAD41, BARBOTTOM1,
QUAD42, BARBOTTOM2,
CHECK,  
} OCTANTARC_STATES;

	DWORD_VAL  temp;	
//	LONG temp1;
	static SHORT y1Limit, y2Limit;
	static SHORT x1, x2, y1, y2;
	static SHORT err1, err2;
	static SHORT x1Cur, y1Cur, y1New;
	static SHORT x2Cur, y2Cur, y2New;
	static OCTANTARC_STATES state = BEGIN;

	while(1){
	    if(IsDeviceBusy())
	        return 0;
	    switch(state){
	        case BEGIN:     
	        

				temp.Val = SIN45*r1;
				y1Limit  = temp.w[1];
				temp.Val = SIN45*r2;
				y2Limit  = temp.w[1];

				temp.Val = (DWORD)(ONEP25 -((LONG)r1<<16));
				err1  = (SHORT)(temp.w[1]); 

				temp.Val = (DWORD)(ONEP25 -((LONG)r2<<16));
				err2  = (SHORT)(temp.w[1]); 

				x1 = r1; x2 = r2; y1 = 0; y2 = 0;

				x1Cur = x1; y1Cur = y1; y1New = y1;
				x2Cur = x2; y2Cur = y2; y2New = y2;
	            state = CHECK;

	        case CHECK:
arc_check_state:	        
				if (y2 > y2Limit) {
	                state = BARRIGHT1;
	                goto arc_draw_width_height_state;
	            }
				// y1New & y2New records the last y positions
				y1New = y1;	y2New = y2;		

				if (y1 <= y1Limit) {
			 		if(err1 > 0) {
		    			x1--;
		    			err1 += 5;
		    			err1 += (y1-x1)<<1;
		   			} else {
		    			err1 += 3;
		    			err1 += y1<<1;
		    		}
		    		y1++;
				} else {
					y1++;
					if (x1 < y1)	
						x1 = y1;
				}

			 	if(err2 > 0) {
		    		x2--;
		    		err2 += 5;
		    		err2 += (y2-x2)<<1;
		   		} else {
		    		err2 += 3;
		    		err2 += y2<<1;
		    	}
				y2++;	

				state = QUAD11;
				break;

	        case QUAD11:
				if ((x1Cur != x1) || (x2Cur != x2)) {
					// 1st octant
					if (octant&0x01) {
						if(Bar(xR+y2Cur, yT-x2Cur, xR+y1New, yT-x1Cur) == 0) return 0;
					}
				}
				else {
					state = CHECK;
		            goto arc_check_state;
		        }
				state = QUAD12;
	            break;

	        case QUAD12:
				// 2nd octant
				if (octant&0x02) {
					if(Bar(xR+x1Cur, yT-y1New, xR+x2Cur, yT-y2Cur) == 0) return 0;
				}
				state = QUAD21;
	            break;

	        case QUAD21:
				// 3rd octant
				if (octant&0x04) {
					if(Bar(xR+x1Cur, yB+y1Cur, xR+x2Cur, yB+y2New) == 0) return 0;
				}
				state = QUAD22;
	            break;

	        case QUAD22:
				// 4th octant
				if (octant&0x08) {
					if(Bar(xR+y1Cur, yB+x1Cur, xR+y2New, yB+x2Cur) == 0) return 0;
				}
				state = QUAD31;
	            break;

	        case QUAD31:
				// 5th octant
				if (octant&0x10) {
					if(Bar(xL-y1New, yB+x1Cur, xL-y2Cur, yB+x2Cur) == 0) return 0;
				}
				state = QUAD32;
	            break;

	        case QUAD32:
				// 6th octant
				if (octant&0x20) {
					if(Bar(xL-x2Cur, yB+y2Cur, xL-x1Cur, yB+y1New) == 0) return 0;
				}
				state = QUAD41;
	            break;

	        case QUAD41:
				// 7th octant
				if (octant&0x40) {
					if(Bar(xL-x2Cur, yT-y2New, xL-x1Cur, yT-y1Cur) == 0) return 0;
				}
				state = QUAD42;
	            break;

	        case QUAD42:
				// 8th octant
				if (octant&0x80) {
					if(Bar(xL-y2New, yT-x2Cur, xL-y1Cur, yT-x1Cur) == 0) return 0;
				}

				// update current values
				x1Cur = x1;	y1Cur = y1; x2Cur = x2;	y2Cur = y2;
				state = CHECK;
	            break;

	        case BARRIGHT1:   			// draw upper right
arc_draw_width_height_state:
			   	if ((xR-xL) || (yB-yT)) {
					// draw right
					if (octant&0x02) {
						if(Bar(xR+r1,yT,xR+r2,(yB+yT)>>1) == 0) return 0; 
					}
				}
				else {
					state = BEGIN;
					return 1;		
				}
				state = BARRIGHT2;
				break;

	        case BARRIGHT2:   			// draw lower right
				if (octant&0x04) {
					if(Bar(xR+r1,((yB+yT)>>1), xR+r2, yB) == 0) return 0; 
				}
				state = BARBOTTOM1;
				break;

	        case BARBOTTOM1:   			// draw left bottom
				// draw bottom
				if (octant&0x10) {
					if(Bar(xL, yB+r1, ((xR+xL)>>1),yB+r2) == 0) return 0;
				}
				state = BARBOTTOM2;
				break;

	        case BARBOTTOM2:   			// draw right bottom
				if (octant&0x08) {
					if(Bar(((xR+xL)>>1),yB+r1,xR,yB+r2) == 0) return 0;
				}
				state = BARTOP1;
				break;

	        case BARTOP1:   			// draw left top
				if(xR-xL) {
		   			// draw top
					if (octant&0x80) {
						if(Bar(xL, yT-r2, ((xR+xL)>>1),yT-r1) == 0) return 0;
					}
					state = BARTOP2;
				} else
					state = BARLEFT1;	// no width go directly to height bar
				break;

	        case BARTOP2:   			// draw right top
				if (octant&0x01) {
					if(Bar(((xR+xL)>>1),yT-r2,xR,yT-r1) == 0) return 0;
				}
				state = BARLEFT1;
				break;

	        case BARLEFT1:   			// draw upper left
			   	if (yT-yB) {
			   		// draw left
					if (octant&0x40) {
						if(Bar(xL-r2,yT,xL-r1,((yB+yT)>>1)) == 0) return 0; 			
					}
					state = BARLEFT2;
				} else {
					state = BEGIN;		// no height go back to BEGIN
					return 1;
				}
				break;

	        case BARLEFT2:   			// draw lower left
				if (octant&0x20) {
					if(Bar(xL-r2,((yB+yT)>>1),xL-r1,yB) == 0) return 0; 			
				}
				state = BEGIN;
				return 1;
	    }// end of switch
	}// end of while
#endif // USE_NONBLOCKING_CONFIG    
}

/*********************************************************************
* Function: WORD Line(SHORT x1, SHORT y1, SHORT x2, SHORT y2)
*
* PreCondition: none
*
* Input: x1,y1 - starting coordinates, x2,y2 - ending coordinates
*
* Output: For NON-Blocking configuration:
*         - Returns 0 when device is busy and the shape is not yet completely drawn.
*         - Returns 1 when the shape is completely drawn.
*         For Blocking configuration:
*         - Always return 1.
*
* Side Effects: none
*
* Overview: draws line
*
* Note: none
*
********************************************************************/
#ifndef USE_DRV_LINE
WORD Line(SHORT x1, SHORT y1, SHORT x2, SHORT y2){
    SHORT deltaX, deltaY;
    SHORT error, stepErrorLT, stepErrorGE;
    SHORT stepX, stepY;
    SHORT steep;
    SHORT temp;
    SHORT style, type;

    #ifndef USE_NONBLOCKING_CONFIG
        while(IsDeviceBusy() != 0); /* Ready */
    #else
        if(IsDeviceBusy() != 0) return 0;
    #endif

     // Move cursor   
     MoveTo(x2,y2);

     if(x1==x2){
        if(y1>y2){
            temp = y1; y1 = y2; y2 = temp;
        }
        style = 0; type =1;
        for(temp=y1; temp<y2+1; temp++){
            if((++style)==_lineType){
                type ^=1;
                style = 0;
            }
            if(type){
                PutPixel(x1,temp);
                if(_lineThickness){
                    PutPixel (x1+1,temp);
                    PutPixel (x1-1,temp);
                }
            }
       }
       return 1;
    }

    if(y1==y2){
        if(x1>x2){
            temp = x1; x1 = x2; x2 = temp;
        }
        style = 0; type =1;
        for(temp=x1; temp<x2+1; temp++){
            if((++style)==_lineType){
                type ^=1;
                style = 0;
            }
            if(type){
                PutPixel(temp,y1);
                if(_lineThickness){
                    PutPixel (temp,y1+1);
                    PutPixel (temp,y1-1);
                }
            }
        }
        return 1;
    }

    stepX= 0;
    deltaX = x2-x1;
    if(deltaX < 0){
        deltaX= -deltaX;
        --stepX;
    }else{
        ++stepX;
    }

    stepY= 0;
    deltaY = y2-y1;
    if(deltaY < 0){
        deltaY= -deltaY;
        --stepY;
    }else{
        ++stepY;
    }

    steep= 0;
    if(deltaX < deltaY){
        ++steep;
        temp = deltaX;  deltaX = deltaY;  deltaY = temp;
        temp = x1;  x1 = y1;  y1 = temp;
        temp = stepX;  stepX = stepY;  stepY = temp;
        PutPixel(y1,x1);
    }else{
        PutPixel(x1,y1);
    }

    // If the current error greater or equal zero
    stepErrorGE= deltaX<<1;
    // If the current error less than zero
    stepErrorLT= deltaY<<1;
    // Error for the first pixel
    error= stepErrorLT-deltaX;

    style = 0; type =1;

    while(--deltaX >= 0){
        if(error >= 0){
            y1+= stepY;
            error-= stepErrorGE;
        }
        x1+= stepX;
        error+= stepErrorLT;

        if((++style)==_lineType){
            type ^=1;
            style = 0;
        }
        if(type){
            if(steep){
                PutPixel (y1,x1);
                if(_lineThickness){
                    PutPixel (y1+1,x1);
                    PutPixel (y1-1,x1);
                }
            }else{
                PutPixel (x1,y1);
                if(_lineThickness){
                    PutPixel (x1,y1+1);
                    PutPixel (x1,y1-1);
                }
            }
        }
   }// end of while

   return 1;
}
#endif

/*********************************************************************
* Function: WORD Bevel(SHORT x1, SHORT y1, SHORT x2, SHORT y2, SHORT rad)
*
* PreCondition: None
*
* Input: x1, y1 - coordinate position of the upper left center of the 
* 				  circle that draws the rounded corners,
*		 x2, y2 - coordinate position of the lower right center of the 
* 				  circle that draws the rounded corners,
*        rad - defines the redius of the circle,
*
* Output: For NON-Blocking configuration:
*         - Returns 0 when device is busy and the shape is not yet completely drawn.
*         - Returns 1 when the shape is completely drawn.
*         For Blocking configuration:
*         - Always return 1.
*
* Overview: Draws a beveled figure on the screen. 
*           For a pure circular object x1 = x2 and y1 = y2. 
*           For a rectangular object radius = 0.
*
* Note: none
*
********************************************************************/
WORD Bevel(SHORT x1, SHORT y1, SHORT x2, SHORT y2, SHORT rad)
{
	SHORT  style, type, xLimit, xPos, yPos, error;
	DWORD_VAL  temp;	

    #ifndef USE_NONBLOCKING_CONFIG
        while(IsDeviceBusy() != 0); /* Ready */
    #else
        if(IsDeviceBusy() != 0) return 0;
    #endif

	temp.Val = SIN45*rad;
	xLimit   = temp.w[1]+1;
	temp.Val = (DWORD)(ONEP25 -((LONG)rad<<16));
	error    = (SHORT)(temp.w[1]); 
	yPos     = rad;

    style = 0; type =1;

	if (rad) {
	  	for (xPos=0; xPos <=xLimit; xPos++) {
		  	
		  	if((++style)==_lineType){
	            type ^=1;
	            style = 0;
	        }
		  	
		  	if(type){
		   		PutPixel(x2+xPos, y1-yPos);		// 1st quadrant
		   		PutPixel(x2+yPos, y1-xPos);
		   		PutPixel(x2+xPos, y2+yPos);		// 2nd quadrant
		  		PutPixel(x2+yPos, y2+xPos);				
		   		PutPixel(x1-xPos, y2+yPos);		// 3rd quadrant
		   		PutPixel(x1-yPos, y2+xPos);
		   		PutPixel(x1-yPos, y1-xPos);		// 4th quadrant
		   		PutPixel(x1-xPos, y1-yPos);

	            if(_lineThickness){
			   		PutPixel(x2+xPos,   y1-yPos-1);		// 1st quadrant
			   		PutPixel(x2+xPos,   y1-yPos+1);		
			   		PutPixel(x2+yPos+1, y1-xPos);
			   		PutPixel(x2+yPos-1, y1-xPos);
			   		PutPixel(x2+xPos,   y2+yPos-1);		// 2nd quadrant
			   		PutPixel(x2+xPos,   y2+yPos+1);		
		  			PutPixel(x2+yPos+1, y2+xPos);				
		  			PutPixel(x2+yPos-1, y2+xPos);				
		   			PutPixel(x1-xPos,   y2+yPos-1);		// 3rd quadrant
		   			PutPixel(x1-xPos,   y2+yPos+1);		
			   		PutPixel(x1-yPos+1, y2+xPos);
			   		PutPixel(x1-yPos-1, y2+xPos);
			   		PutPixel(x1-yPos+1, y1-xPos);		// 4th quadrant
			   		PutPixel(x1-yPos-1, y1-xPos);		
			   		PutPixel(x1-xPos,   y1-yPos+1);
			   		PutPixel(x1-xPos,   y1-yPos-1);
                }
		   	}
		 	if(error > 0) {
	    		yPos--;
	    		error += 5+((xPos-yPos)<<1);
	   		}
	   		else
	    		error += 3+(xPos<<1);
	    }
	} 

   	// Must use lines here since this can also be used to draw focus of round buttons
   	if (x2-x1) {
   		while(!Line(x1,y1-rad,x2,y1-rad));				// draw top
   	}
   	if (y2-y1) {
   		while(!Line(x1-rad,y1,x1-rad,y2)); 				// draw left
   	}
   	if ((x2-x1) || (y2-y1)) {
		while(!Line(x2+rad,y1,x2+rad,y2)); 				// draw right
		while(!Line(x1,y2+rad,x2,y2+rad));				// draw bottom
	}

	return 1;
}

/*********************************************************************
* Function: WORD FillBevel(SHORT x1, SHORT y1, SHORT x2, SHORT y2, SHORT rad)
*
* PreCondition: None
*
* Input: x1, y1 - coordinate position of the upper left center of the 
* 				  circle that draws the rounded corners,
*		 x2, y2 - coordinate position of the lower right center of the 
* 				  circle that draws the rounded corners,
*        rad - defines the redius of the circle,
*
* Output: For NON-Blocking configuration:
*         - Returns 0 when device is busy and the shape is not yet completely drawn.
*         - Returns 1 when the shape is completely drawn.
*         For Blocking configuration:
*         - Always return 1.
*
* Overview: Draws a filled beveled figure on the screen. 
*           For a filled circular object x1 = x2 and y1 = y2. 
*           For a filled rectangular object radius = 0.
*
* Note: none
*
********************************************************************/
WORD FillBevel(SHORT x1, SHORT y1, SHORT x2, SHORT y2, SHORT rad)
{

#ifndef USE_NONBLOCKING_CONFIG

	SHORT yLimit, xPos, yPos, err;
	SHORT xCur, yCur, yNew;
	DWORD_VAL  temp;	

	// note that octants here is defined as:
	// from yPos=-radius, xPos=0 in the clockwise direction octant 1 to 8 are labeled
	// assumes an origin at 0,0. Quadrants are defined in the same manner

	if (rad) {
		temp.Val = SIN45*rad;
		yLimit   = temp.w[1];
		temp.Val = (DWORD)(ONEP25 -((LONG)rad<<16));
		err      = (SHORT)(temp.w[1]); 
		xPos     = rad;
		yPos     = 0;

		xCur = xPos; yCur = yPos; yNew = yPos;

		
		while(yPos<=yLimit) {
	
			// Drawing of the rounded panel is done only when there is a change in the
			// x direction. Bars are drawn to be efficient.
			
			// detect changes in the x position. Every change will mean a bar will be drawn 
			// to cover the previous area. y1New records the last position of y before the 
			// change in x position.

			// y1New records the last y position
			yNew = yPos;			

		 	if(err > 0) {
	    		xPos--;
	    		err += 5+((yPos-xPos)<<1);
	   		} else
	    		err += 3+(yPos<<1);
			yPos++;	

			if (xCur != xPos) {
				// 6th octant to 3rd octant
	   			Bar(x1-xCur, y2+yCur, x2+xCur, y2+yNew);
				// 5th octant to 4th octant
	   			Bar(x1-yNew, y2+xPos, x2+yNew, y2+xCur);
				// 8th octant to 1st octant
	   			Bar(x1-yNew, y1-xCur, x2+yNew, y1-xPos);
				// 7th octant to 2nd octant
	   			Bar(x1-xCur, y1-yNew, x2+xCur, y1-yCur);

				// update current values
				xCur = xPos; yCur = yPos;
			} 

	    }
	}
	// this covers both filled rounded object and filled rectangle.
    if ((x2-x1) || (y2-y1))
    	Bar(x1-rad, y1, x2+rad, y2);
	return 1; 
#else

typedef enum {
BEGIN,
CHECK,
Q8TOQ1,
Q7TOQ2,
Q6TOQ3,
Q5TOQ4,
WAITFORDONE,
FACE
} FILLCIRCLE_STATES;


	DWORD_VAL  temp;	
	static LONG err;
	static SHORT yLimit, xPos, yPos;
	static SHORT xCur, yCur, yNew;

	static FILLCIRCLE_STATES state = BEGIN;

while(1){
    if(IsDeviceBusy())
        return 0;
    switch(state){
        case BEGIN:  
        	if (!rad) {									// no radius object is a filled rectangle
	        	state = FACE;
	        	break;
	        }
	        // compute variables
			temp.Val = SIN45*rad;
			yLimit   = temp.w[1];
			temp.Val = (DWORD)(ONEP25 -((LONG)rad<<16));
			err      = (SHORT)(temp.w[1]); 
			xPos 	 = rad; yPos = 0;
			xCur     = xPos; yCur = yPos; yNew = yPos;
            state    = CHECK;

        case CHECK:
bevel_fill_check:
            if (yPos>yLimit) {
                state = FACE;
                break;
            }
			// y1New records the last y position
			yNew = yPos;			

			// calculate the next value of x and y
		 	if(err > 0) {
	    		xPos--;
	    		err += 5+((yPos-xPos)<<1);
	   		} else
	    		err += 3+(yPos<<1);
			yPos++;	
			state = Q6TOQ3;

        case Q6TOQ3:
			if (xCur != xPos) {
				// 6th octant to 3rd octant
	   			if(Bar(x1-xCur, y2+yCur, x2+xCur, y2+yNew) == 0) return 0;
	   			state = Q5TOQ4;
	   			break;
	   		}
	   		state = CHECK;
	   		goto bevel_fill_check;

        case Q5TOQ4:
			// 5th octant to 4th octant
   			if(Bar(x1-yNew, y2+xPos, x2+yNew, y2+xCur) == 0) return 0;
            state = Q8TOQ1;
            break;

        case Q8TOQ1:
			// 8th octant to 1st octant
   			if(Bar(x1-yNew, y1-xCur, x2+yNew, y1-xPos) == 0) return 0;				
            state = Q7TOQ2;
            break;

        case Q7TOQ2:
			// 7th octant to 2nd octant
   			if(Bar(x1-xCur, y1-yNew, x2+xCur, y1-yCur) == 0) return 0;				
			// update current values
			xCur = xPos;
			yCur = yPos;
            state = CHECK;
            break;
		case FACE:
			if ((x2-x1)||(y2-y1)) {
		    	if(Bar(x1-rad, y1, x2+rad, y2) == 0) return 0;
		    	state = WAITFORDONE;
		    }
		    else {
			    state = BEGIN;
		    	return 1;
		    }
		case WAITFORDONE:
			if (IsDeviceBusy())
				return 0;
		    state = BEGIN;
		    return 1;	
    }// end of switch
}// end of while

#endif // end of USE_NONBLOCKING_CONFIG
}

/*********************************************************************
* Function: WORD DrawPoly(SHORT numPoints, SHORT* polyPoints)
*
* PreCondition: none
*
* Input: numPoints - points number, polyPoints - pointer to points array
*
* Output: For NON-Blocking configuration:
*         - Returns 0 when device is busy and the shape is not yet completely drawn.
*         - Returns 1 when the shape is completely drawn.
*         For Blocking configuration:
*         - Always return 1.
*
* Side Effects: none
*
* Overview: draws line polygon
*
* Note: none
*
********************************************************************/
WORD DrawPoly(SHORT numPoints, SHORT* polyPoints){

#ifndef USE_NONBLOCKING_CONFIG

    SHORT counter;
    SHORT sx,sy,ex,ey;

    #ifndef USE_NONBLOCKING_CONFIG
        while(IsDeviceBusy() != 0); /* Ready */
    #else
        if(IsDeviceBusy() != 0) return 0;
    #endif

    sx = *polyPoints++; sy = *polyPoints++;
    for(counter = 0; counter < numPoints - 1; counter++){
        ex = *polyPoints++; ey = *polyPoints++;
        while(Line(sx,sy,ex,ey) == 0);
        sx = ex; sy = ey;
    }
    return 1;
#else
    typedef enum {
    POLY_BEGIN,
    POLY_DRAWING,
    } DRAWPOLY_STATES;

    static DRAWPOLY_STATES state = POLY_BEGIN;
    static SHORT counter;
    SHORT sx,sy,ex,ey;
    while(1){
        if(IsDeviceBusy())
            return 0;
        switch(state)   {
            case POLY_BEGIN:    counter = 1;
                                state = POLY_DRAWING;

            case POLY_DRAWING:  if(counter == 0 || counter >= numPoints)
                                {
                                    state = POLY_BEGIN;
                                    break;
                                }
                                while(counter < numPoints)
                                {
                                    sx = polyPoints[(counter - 1) * 2];
                                    sy = polyPoints[(counter * 2) - 1];
                                    ex = polyPoints[counter * 2];
                                    ey = polyPoints[counter * 2 + 1];
                                    if(Line(sx,sy,ex,ey) == 0)
                                    {
                                        return 0;
                                    }
                                    counter++;
                                }
                                state = POLY_BEGIN;
                                return 1;
        }
    }

#endif
}

/*********************************************************************
* Function: WORD Bar(SHORT left, SHORT top, SHORT right, SHORT bottom)
*
* PreCondition: none
*
* Input: left,top - top left corner coordinates,
*        right,bottom - bottom right corner coordinates
*
* Output: For NON-Blocking configuration:
*         - Returns 0 when device is busy and the shape is not yet completely drawn.
*         - Returns 1 when the shape is completely drawn.
*         For Blocking configuration:
*         - Always return 1.
*
* Side Effects: none
*
* Overview: draws rectangle filled with current color
*
* Note: none
*
********************************************************************/
#ifndef USE_DRV_BAR
WORD Bar(SHORT left, SHORT top, SHORT right, SHORT bottom){
    SHORT x,y;

    #ifndef USE_NONBLOCKING_CONFIG
        while(IsDeviceBusy() != 0); /* Ready */
    #else
        if(IsDeviceBusy() != 0) return 0;
    #endif

    for(y = top; y < bottom + 1; y++)
        for(x = left; x < right + 1; x++)
            PutPixel(x,y);

    return 1;
}
#endif

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
* Overview: clears screen with current color and sets cursor to 0,0
*
* Note: none
*
********************************************************************/
#ifndef USE_DRV_CLEARDEVICE
void ClearDevice(void){
    while(Bar(0,0,GetMaxX(),GetMaxY()) == 0);
    MoveTo(0,0);
}
#endif

/*********************************************************************
* Function: void SetFont(void* font)
*
* PreCondition: none
*
* Input: pointer to the font image
*
* Output: none
*
* Side Effects: none
*
* Overview: defines current font
*
* Note: none
*
********************************************************************/
#ifndef USE_DRV_FONT
void SetFont(void* font){
FONT_HEADER* pHeader;

#ifdef USE_FONT_EXTERNAL
FONT_HEADER  header;
#endif

    _font = font;
    switch(*((SHORT*)font)){
#ifdef USE_FONT_FLASH
        case FLASH:
            pHeader = (FONT_HEADER*)((FONT_FLASH*)font)->address;
            break;
#endif
#ifdef USE_FONT_EXTERNAL
        case EXTERNAL:
            pHeader = &header;
            ExternalMemoryCallback(font,0,sizeof(FONT_HEADER),pHeader);
            break;
#endif
        default:
            return;
    }
    _fontFirstChar = pHeader->firstChar;
    _fontLastChar =  pHeader->lastChar;
    _fontHeight =    pHeader->height;
}
#endif

/*********************************************************************
* Function: WORD OutText(XCHAR* textString)
*
* PreCondition: none
*
* Input: textString - pointer to text string
*
* Output: non-zero if drawing done (used for NON-BLOCKING configuration)
*
* Side Effects: none
*
* Overview: outputs text from current position
*
* Note: none
*
********************************************************************/
WORD OutText(XCHAR* textString){
#ifndef USE_NONBLOCKING_CONFIG

XCHAR ch;
    while((unsigned XCHAR)15 < (unsigned XCHAR)(ch = *textString++))
        while(OutChar(ch) == 0);
    return 1;

#else

XCHAR ch;
static WORD counter = 0;
    
    while((unsigned XCHAR)(ch = *(textString+counter)) > (unsigned XCHAR)15){
        if(OutChar(ch) == 0)
            return 0;
        counter++;
    }
    counter = 0;
    return 1;

#endif
}

/*********************************************************************
* Function: WORD OutTextXY(SHORT x, SHORT y, XCHAR* textString)
*
* PreCondition: none
*
* Input: x,y - starting coordinates, textString - pointer to text string
*
* Output: non-zero if drawing done (used for NON-BLOCKING configuration)
*
* Side Effects: none
*
* Overview: outputs text from x,y position
*
* Note: none
*
********************************************************************/
WORD OutTextXY(SHORT x, SHORT y, XCHAR* textString){

#ifndef USE_NONBLOCKING_CONFIG

    MoveTo(x,y);
    OutText(textString);
    return 1;

#else

static BYTE start = 1;

    if(start){
        MoveTo(x,y);
        start = 0;
    }

    if(OutText(textString) == 0){
        return 0;
    }else{
        start = 1;
        return 1;
    }
#endif
}

/*********************************************************************
* Function: WORD OutChar(XCHAR ch)
*
* PreCondition: none
*
* Input: character code
*
* Output: For NON-Blocking configuration:
*         - Returns 0 when device is busy and the character is not yet completely drawn.
*         - Returns 1 when the character is completely drawn.
*         For Blocking configuration:
*         - Always return 1.
*
* Side Effects: none
*
* Overview: outputs a character
*
* Note: none
*
********************************************************************/
#ifndef USE_DRV_FONT
WORD OutChar(XCHAR ch){

    GLYPH_ENTRY* pChTable;
    BYTE*        pChImage;
    
    #ifdef USE_FONT_EXTERNAL
    GLYPH_ENTRY  chTable;
    BYTE         chImage[EXTERNAL_FONT_BUFFER_SIZE];
    WORD         imageSize;
    DWORD_VAL    glyphOffset;
    #endif
    
    SHORT        chWidth;
    SHORT        xCnt, yCnt, x, y;
    BYTE         temp, mask;

    #ifndef USE_NONBLOCKING_CONFIG
        while(IsDeviceBusy() != 0); /* Ready */
    #else
        if(IsDeviceBusy() != 0) return 0;
    #endif

    if((unsigned XCHAR)ch<(unsigned XCHAR)_fontFirstChar)
        return (WORD)-1;
    if((unsigned XCHAR)ch>(unsigned XCHAR)_fontLastChar)
        return (WORD)-1;

    switch(*((SHORT*)_font)){
#ifdef USE_FONT_FLASH
        case FLASH:

            pChTable = (GLYPH_ENTRY*)( ((FONT_FLASH*)_font)->address+sizeof(FONT_HEADER) ) + ((unsigned XCHAR)ch-(unsigned XCHAR)_fontFirstChar);

            pChImage = (BYTE*)( ((FONT_FLASH*)_font)->address + pChTable->offsetLSB );

            chWidth = pChTable->width;

            break;
#endif
#ifdef USE_FONT_EXTERNAL
        case EXTERNAL:          
            // get glyph entry
            ExternalMemoryCallback(_font,
                                   sizeof(FONT_HEADER)+((unsigned XCHAR)ch-(unsigned XCHAR)_fontFirstChar)*sizeof(GLYPH_ENTRY),
                                   sizeof(GLYPH_ENTRY),
                                   &chTable);

            chWidth = chTable.width;

            // width of glyph in bytes
            imageSize = 0;
            if(chWidth&0x0007)
                imageSize = 1;
            imageSize += (chWidth>>3);

            // glyph image size
            imageSize *= _fontHeight;    

            // get glyph image
			glyphOffset.w[1] = chTable.offsetMSB;
			glyphOffset.w[0] = chTable.offsetLSB;

            ExternalMemoryCallback(_font,
                                   glyphOffset.Val,
                                   imageSize,
                                   &chImage);
            pChImage = (BYTE*)&chImage;

            break;
#endif
        default:
            break;
    }
    if(_fontOrientation == ORIENT_HOR){
        y = GetY(); 
        for(yCnt=0; yCnt<_fontHeight; yCnt++){        
            x = GetX(); 
            mask = 0;
            for(xCnt=0; xCnt<chWidth; xCnt++){
                if(mask == 0){
                    temp = *pChImage++;
                    mask = 0x80;
                }
                if(temp&mask){
                    PutPixel(x,y);
                }
                x++;
                mask >>= 1;
            }
            y++;
        }
        // move cursor
        _cursorX = x;
    }else{
        y = GetX(); 
        for(yCnt=0; yCnt<_fontHeight; yCnt++){        
            x = GetY(); 
            mask = 0;
            for(xCnt=0; xCnt<chWidth; xCnt++){
                if(mask == 0){
                    temp = *pChImage++;
                    mask = 0x80;
                }
                if(temp&mask){
                    PutPixel(y,x);
                }
                x--;
                mask >>= 1;
            }
            y++;
        }
        // move cursor
        _cursorY = x;
    }
    return 1;
}
#endif

/*********************************************************************
* Function: SHORT GetTextWidth(XCHAR* textString, void* font)
*
* PreCondition: none
*
* Input: textString - pointer to the text string,
*        font - pointer to the font
*
* Output: text width in pixels
*
* Side Effects: none
*
* Overview: returns text width for the font
*
* Note: none
*
********************************************************************/
#ifndef USE_DRV_FONT
SHORT GetTextWidth(XCHAR* textString, void* font){
GLYPH_ENTRY* pChTable;
FONT_HEADER* pHeader;
#ifdef USE_FONT_EXTERNAL
GLYPH_ENTRY  chTable;
FONT_HEADER  header;
#endif
SHORT        textWidth;
//SHORT        temp;
XCHAR        ch;
XCHAR        fontFirstChar;
XCHAR        fontLastChar;

    switch(*((SHORT*)font)){
#ifdef USE_FONT_FLASH
        case FLASH:
            pHeader = (FONT_HEADER*)((FONT_FLASH*)font)->address;
            fontFirstChar = pHeader->firstChar;
            fontLastChar  = pHeader->lastChar;
            pChTable = (GLYPH_ENTRY*)(pHeader + 1);
            textWidth = 0;
            while((unsigned XCHAR)15<(unsigned XCHAR)(ch = *textString++)){
                if((unsigned XCHAR)ch<(unsigned XCHAR)fontFirstChar)
                    continue;
                if((unsigned XCHAR)ch>(unsigned XCHAR)fontLastChar)
                    continue;
                textWidth += (pChTable+((unsigned XCHAR)ch-(unsigned XCHAR)fontFirstChar))->width;
            }
            return textWidth;
#endif
#ifdef USE_FONT_EXTERNAL
        case EXTERNAL:
            ExternalMemoryCallback(font,0,sizeof(FONT_HEADER),&header);
            fontFirstChar = header.firstChar;
            fontLastChar =  header.lastChar;
            textWidth = 0;
            while((unsigned XCHAR)15<(unsigned XCHAR)(ch = *textString++)){
                if((unsigned XCHAR)ch<(unsigned XCHAR)fontFirstChar)
                    continue;
                if((unsigned XCHAR)ch>(unsigned XCHAR)fontLastChar)
                    continue;
                ExternalMemoryCallback(font,
                                       sizeof(FONT_HEADER)+sizeof(GLYPH_ENTRY)*((unsigned XCHAR)ch-(unsigned XCHAR)fontFirstChar),
                                       sizeof(GLYPH_ENTRY),
                                       &chTable);
                textWidth += chTable.width;
            }
            return textWidth;
#endif
        default:
            return 0;
    }
}
#endif

/*********************************************************************
* Function: SHORT GetTextHeight(void* font)
*
* PreCondition: none
*
* Input: pointer to the font
*
* Output: character height in pixels
*
* Side Effects: none
*
* Overview: returns characters height for the font
*
* Note: none
*
********************************************************************/
#ifndef USE_DRV_FONT
SHORT   GetTextHeight(void* font){
#ifdef USE_FONT_EXTERNAL
char height;
#endif

    switch(*((SHORT*)font)){
#ifdef USE_FONT_FLASH
        case FLASH:
            return ((FONT_HEADER*)((FONT_FLASH*)font)->address)->height;
#endif
#ifdef USE_FONT_EXTERNAL
        case EXTERNAL:
            ExternalMemoryCallback(font,sizeof(FONT_HEADER)-1,1,&height);
            return height;
#endif
        default:
            return 0;

    }
}
#endif

/*********************************************************************
* Function: SHORT GetImageWidth(void* bitmap)
*
* PreCondition: none
*
* Input: bitmap - image pointer
*
* Output: none
*
* Side Effects: none
*
* Overview: returns image width
*
* Note: none
*
********************************************************************/
SHORT GetImageWidth(void* bitmap){
#ifdef USE_BITMAP_EXTERNAL
SHORT width;
#endif

    switch(*((SHORT*)bitmap))
    {
#ifdef USE_BITMAP_FLASH
        case FLASH:
            return *( (FLASH_WORD*)((BITMAP_FLASH*)bitmap)->address+2 );
#endif
#ifdef USE_BITMAP_EXTERNAL
        case EXTERNAL:
            ExternalMemoryCallback(bitmap, 4, 2, &width);
            return width;
#endif
        default:
            return 0;
    }
}

/*********************************************************************
* Function: SHORT GetImageHeight(void* bitmap)
*
* PreCondition: none
*
* Input: bitmap - image pointer
*
* Output: none
*
* Side Effects: none
*
* Overview: returns image height
*
* Note: none
*
********************************************************************/
SHORT GetImageHeight(void* bitmap){
#ifdef USE_BITMAP_EXTERNAL
SHORT height;
#endif

    switch(*((SHORT*)bitmap))
    {
#ifdef USE_BITMAP_FLASH
        case FLASH:
            return *( (FLASH_WORD*)((BITMAP_FLASH*)bitmap)->address+1 );
#endif
#ifdef USE_BITMAP_EXTERNAL
        case EXTERNAL:
            ExternalMemoryCallback(bitmap, 2, 2, &height);
            return height;
#endif
        default:
            return 0;
    }
}

#ifndef USE_DRV_PUTIMAGE
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
    WORD colorTemp;

    #ifndef USE_NONBLOCKING_CONFIG
        while(IsDeviceBusy() != 0); /* Ready */
    #else
        if(IsDeviceBusy() != 0) return 0;
    #endif

    // Save current color
    colorTemp = GetColor();

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
#if	(COLOR_DEPTH >= 4)
                case 4:
                    PutImage4BPP(left, top, flashAddress, stretch);
                    break;
#endif
#if	(COLOR_DEPTH >= 8)
                case 8:
                    PutImage8BPP(left, top, flashAddress, stretch);
                    break;
#endif
#if	(COLOR_DEPTH == 16)
                case 16:
                    PutImage16BPP(left, top, flashAddress, stretch);
                    break;
#endif			
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
#ifdef	(COLOR_DEPTH >= 4)
                case 4:
                    PutImage4BPPExt(left, top, bitmap, stretch);
                    break;
#endif
#ifdef	(COLOR_DEPTH >= 8)
                case 8:
                    PutImage8BPPExt(left, top, bitmap, stretch);
                    break;
#endif
#ifdef	(COLOR_DEPTH == 16)
                case 16:
                    PutImage16BPPExt(left, top, bitmap, stretch);
                    break;
#endif
                default:
                    break;
            }
            break;
#endif
        default:
            break;
    }

    // Restore current color
    SetColor(colorTemp);
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
WORD xc,yc;
BYTE stretchX,stretchY;
WORD pallete[2];
BYTE mask;

    // Move pointer to size information
    flashAddress = bitmap + 2;

    // Read image size
    sizeY = *((FLASH_WORD*)flashAddress);
    flashAddress += 2;
    sizeX = *((FLASH_WORD*)flashAddress);
    flashAddress += 2;
    pallete[0] = *((FLASH_WORD*)flashAddress);
    flashAddress += 2;
    pallete[1] = *((FLASH_WORD*)flashAddress);
    flashAddress += 2;

    yc = top;
    for(y=0; y<sizeY; y++){
        tempFlashAddress = flashAddress;
        for(stretchY = 0; stretchY<stretch; stretchY++){
            flashAddress = tempFlashAddress;
            mask = 0;
            xc = left;
            for(x=0; x<sizeX; x++){

                // Read 8 pixels from flash
                if(mask == 0){
                    temp = *flashAddress;
                    flashAddress++;
                    mask = 0x80;
                }
                
                // Set color
                if(mask&temp){
                    SetColor(pallete[1]);
                }else{
                    SetColor(pallete[0]);
                }

                // Write pixel to screen
                for(stretchX=0; stretchX<stretch; stretchX++){
                    PutPixel(xc++, yc);
                }
                // Shift to the next pixel
                mask >>= 1;
           }
           yc++;
        }
    }
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
#if	(COLOR_DEPTH >= 4)

void PutImage4BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch){
register FLASH_BYTE* flashAddress;
register FLASH_BYTE* tempFlashAddress;
WORD sizeX, sizeY;
register WORD x,y;
WORD xc,yc;
BYTE temp;
register BYTE stretchX,stretchY;
WORD pallete[16];
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
        pallete[counter] = *((FLASH_WORD*)flashAddress);
        flashAddress += 2;
    }

    yc = top;
    for(y=0; y<sizeY; y++){
        tempFlashAddress = flashAddress;
        for(stretchY = 0; stretchY<stretch; stretchY++){
            flashAddress = tempFlashAddress;
            xc = left;
            for(x=0; x<sizeX; x++){
                // Read 2 pixels from flash
                if(x&0x0001){
                    // second pixel in byte
                    SetColor(pallete[temp>>4]);
                }else{
                    temp = *flashAddress;
                    flashAddress++;
                    // first pixel in byte
                    SetColor(pallete[temp&0x0f]);
                }

                // Write pixel to screen       
                for(stretchX=0; stretchX<stretch; stretchX++){
					PutPixel(xc++, yc);
                }
            }
            yc++;
        }
    }
}

#endif

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
#if	(COLOR_DEPTH >= 8)
void PutImage8BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch){
register DWORD_VAL address;
register FLASH_BYTE* flashAddress;
register FLASH_BYTE* tempFlashAddress;
WORD sizeX, sizeY;
WORD x,y;
WORD xc,yc;
BYTE temp;
BYTE stretchX, stretchY;
WORD pallete[256];
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
        pallete[counter] = *((FLASH_WORD*)flashAddress);
        flashAddress += 2;
    }

    yc = top;
    for(y=0; y<sizeY; y++){
        tempFlashAddress = flashAddress;
        for(stretchY = 0; stretchY<stretch; stretchY++){
            flashAddress = tempFlashAddress;
            xc = left;
            for(x=0; x<sizeX; x++){
                // Read pixels from flash
                temp = *flashAddress;
                flashAddress++;

                // Set color
                SetColor(pallete[temp]);

                // Write pixel to screen       
                for(stretchX=0; stretchX<stretch; stretchX++){
					PutPixel(xc++, yc);
                }
            }
            yc++;
        }
    }
}

#endif
/*********************************************************************
* Function: void PutImage16BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch)
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
* Overview: outputs hicolor image starting from left,top coordinates
*
* Note: image must be located in flash
*
********************************************************************/
#if	(COLOR_DEPTH == 16)
void PutImage16BPP(SHORT left, SHORT top, FLASH_BYTE* bitmap, BYTE stretch){
register FLASH_WORD* flashAddress;
register FLASH_WORD* tempFlashAddress;
WORD sizeX, sizeY;
register WORD x,y;
WORD xc,yc;
WORD temp;
register BYTE stretchX,stretchY;

    // Move pointer to size information
    flashAddress = (FLASH_WORD*)bitmap + 1;

    // Read image size
    sizeY = *flashAddress;
    flashAddress++;
    sizeX = *flashAddress;
    flashAddress++;

    yc = top;
    for(y=0; y<sizeY; y++){
        tempFlashAddress = flashAddress;
        for(stretchY = 0; stretchY<stretch; stretchY++){
            flashAddress = tempFlashAddress;
            xc = left;
            for(x=0; x<sizeX; x++){
                // Read pixels from flash
                temp = *flashAddress;
                flashAddress++;

                // Set color
                SetColor(temp);

                // Write pixel to screen       
                for(stretchX=0; stretchX<stretch; stretchX++){
					PutPixel(xc++, yc);
                }
            }
            yc++;
        }
    }
}

#endif

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
WORD xc,yc;
BYTE                stretchX, stretchY;

    // Get bitmap header
    ExternalMemoryCallback(bitmap, 0, sizeof(BITMAP_HEADER), &bmp);

    // Get pallete (2 entries)
    ExternalMemoryCallback(bitmap, sizeof(BITMAP_HEADER), 2*sizeof(WORD), pallete);

    // Set offset to the image data
    memOffset = sizeof(BITMAP_HEADER) + 2*sizeof(WORD);

    // Line width in bytes
    byteWidth = bmp.width>>3;
    if(bmp.width&0x0007)
        byteWidth++;

    // Get size
    sizeX = bmp.width;
    sizeY = bmp.height;

    yc = top;
    for(y=0; y<sizeY; y++){

        // Get line
        ExternalMemoryCallback(bitmap, memOffset, byteWidth, lineBuffer);
        memOffset += byteWidth;
        for(stretchY = 0; stretchY<stretch; stretchY++){
            pData = lineBuffer;
            mask = 0;
            xc = left;
            for(x=0; x<sizeX; x++){

                // Read 8 pixels from flash
                if(mask == 0){
                    temp = *pData++;
                    mask = 0x80;
                }
                
                // Set color
                if(mask&temp){
                    SetColor(pallete[1]);
                }else{
                    SetColor(pallete[0]);
                }

                // Write pixel to screen
                for(stretchX=0; stretchX<stretch; stretchX++){
					PutPixel(xc++, yc);
                }

                // Shift to the next pixel
                mask >>= 1;
           }
           yc++;
        }
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
#ifdef	(COLOR_DEPTH >= 4)
void PutImage4BPPExt(SHORT left, SHORT top, void* bitmap, BYTE stretch){
register DWORD      memOffset;
BITMAP_HEADER       bmp;
WORD                pallete[16];
BYTE                lineBuffer[((GetMaxX()+1)/2)+1];
BYTE*               pData; 
SHORT               byteWidth;

BYTE                temp;
WORD                sizeX, sizeY;
WORD                x,y;
WORD xc,yc;
BYTE                stretchX, stretchY;

    // Get bitmap header
    ExternalMemoryCallback(bitmap, 0, sizeof(BITMAP_HEADER), &bmp);

    // Get pallete (16 entries)
    ExternalMemoryCallback(bitmap, sizeof(BITMAP_HEADER), 16*sizeof(WORD), pallete);

    // Set offset to the image data
    memOffset = sizeof(BITMAP_HEADER) + 16*sizeof(WORD);

    // Line width in bytes
    byteWidth = bmp.width>>1;
    if(bmp.width&0x0001)
        byteWidth++;

    // Get size
    sizeX = bmp.width;
    sizeY = bmp.height;

    yc = top;
    for(y=0; y<sizeY; y++){

        // Get line
        ExternalMemoryCallback(bitmap, memOffset, byteWidth, lineBuffer);
        memOffset += byteWidth;
        for(stretchY = 0; stretchY<stretch; stretchY++){

            pData = lineBuffer;
            xc = left;
            for(x=0; x<sizeX; x++){

                // Read 2 pixels from flash
                if(x&0x0001){
                    // second pixel in byte
                    SetColor(pallete[temp>>4]);
                }else{
                    temp = *pData++;
                    // first pixel in byte
                    SetColor(pallete[temp&0x0f]);
                }

                // Write pixel to screen       
                for(stretchX=0; stretchX<stretch; stretchX++){
					PutPixel(xc++, yc);
				}
           }
           yc++;
        }
    }
}
#endif
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
#ifdef	(COLOR_DEPTH >= 8)
void PutImage8BPPExt(SHORT left, SHORT top, void* bitmap, BYTE stretch){
register DWORD      memOffset;
BITMAP_HEADER       bmp;
WORD                pallete[256];
BYTE                lineBuffer[(GetMaxX()+1)];
BYTE*               pData; 

BYTE                temp;
WORD                sizeX, sizeY;
WORD                x,y;
WORD xc,yc;
BYTE                stretchX, stretchY;

    // Get bitmap header
    ExternalMemoryCallback(bitmap, 0, sizeof(BITMAP_HEADER), &bmp);

    // Get pallete (256 entries)
    ExternalMemoryCallback(bitmap, sizeof(BITMAP_HEADER), 256*sizeof(WORD), pallete);

    // Set offset to the image data
    memOffset = sizeof(BITMAP_HEADER) + 256*sizeof(WORD);

    // Get size
    sizeX = bmp.width;
    sizeY = bmp.height;

    yc = top;
    for(y=0; y<sizeY; y++){

        // Get line
        ExternalMemoryCallback(bitmap, memOffset, sizeX, lineBuffer);
        memOffset += sizeX;
        for(stretchY = 0; stretchY<stretch; stretchY++){

            pData = lineBuffer;
            xc = left;
            for(x=0; x<sizeX; x++){

                temp = *pData++;
                SetColor(pallete[temp]);                    

                // Write pixel to screen       
                for(stretchX=0; stretchX<stretch; stretchX++){
					PutPixel(xc++, yc);
				}
           }
           yc++;
        }
    }
}
#endif
/*********************************************************************
* Function: void PutImage16BPPExt(SHORT left, SHORT top, void* bitmap, BYTE stretch)
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
#ifdef	(COLOR_DEPTH == 16)
void PutImage16BPPExt(SHORT left, SHORT top, void* bitmap, BYTE stretch){
register DWORD      memOffset;
BITMAP_HEADER       bmp;
WORD                lineBuffer[(GetMaxX()+1)];
WORD*               pData; 
WORD                byteWidth;

WORD                temp;
WORD                sizeX, sizeY;
WORD                x,y;
WORD xc,yc;
BYTE                stretchX, stretchY;

    // Get bitmap header
    ExternalMemoryCallback(bitmap, 0, sizeof(BITMAP_HEADER), &bmp);

    // Set offset to the image data
    memOffset = sizeof(BITMAP_HEADER);

    // Get size
    sizeX = bmp.width;
    sizeY = bmp.height;

    byteWidth = sizeX<<1;

    yc = top; 
    for(y=0; y<sizeY; y++){

        // Get line
        ExternalMemoryCallback(bitmap, memOffset, byteWidth, lineBuffer);
        memOffset += byteWidth;
        for(stretchY = 0; stretchY<stretch; stretchY++){

            pData = lineBuffer;

            xc = left;
            for(x=0; x<sizeX; x++){

                temp = *pData++;
                SetColor(temp);                    

                // Write pixel to screen       
                for(stretchX=0; stretchX<stretch; stretchX++){
					PutPixel(xc++, yc);
				}
           }
           yc++;
        }
    }
}
#endif

#endif

#endif // USE_DRV_PUTIMAGE
