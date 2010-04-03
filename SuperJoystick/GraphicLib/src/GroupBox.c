/*****************************************************************************
 *  Module for Microchip Graphics Library
 *  GOL Layer 
 *  Group Box
 *****************************************************************************
 * FileName:        GroupBox.c
 * Dependencies:    
 * Processor:       PIC24F, PIC24H, dsPIC, PIC32
 * Compiler:       	MPLAB C30 V3.00, MPLAB C32
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
 * Paolo A. Tamayo		11/12/07	Version 1.0 release
 *****************************************************************************/

#include "Graphics\Graphics.h"

#ifdef USE_GROUPBOX

/*********************************************************************
* Function: GROUPBOX *GbCreate(WORD ID, SHORT left, SHORT top, SHORT right, 
*							   SHORT bottom, WORD state, XCHAR *pText, 
*							   GOL_SCHEME *pScheme)
*
* Notes: Creates a GROUPBOX object and adds it to the current active list.
*        If the creation is successful, the pointer to the created Object 
*        is returned. If not successful, NULL is returned.
*
********************************************************************/
GROUPBOX *GbCreate(WORD ID, SHORT left, SHORT top, SHORT right, SHORT bottom, 
				   WORD state, XCHAR *pText, GOL_SCHEME *pScheme)
{
	GROUPBOX *pGb = NULL;
	
	pGb = (GROUPBOX*)malloc(sizeof(GROUPBOX));
	if (pGb == NULL)
		return pGb;
	
	pGb->hdr.ID     	= ID;					// unique id assigned for referencing
	pGb->hdr.pNxtObj   	= NULL;
	pGb->hdr.type      	= OBJ_GROUPBOX;         // set object type
	pGb->hdr.left      	= left; 
	pGb->hdr.top       	= top;	
	pGb->hdr.right     	= right;   		    		 
	pGb->hdr.bottom   	= bottom;               	 
	pGb->hdr.state   	= state; 	
	pGb->pText      = pText;

	// Set the color scheme and font to be used
	if (pScheme == NULL)
		pGb->hdr.pGolScheme = _pDefaultGolScheme; 
	else 	
		pGb->hdr.pGolScheme = (GOL_SCHEME *)pScheme; 	

	pGb->textWidth  = 0;  
	pGb->textHeight = 0;
 	if(pText != NULL){
		// Set the text width & height  
		pGb->textWidth  = GetTextWidth(pText, pGb->hdr.pGolScheme->pFont);  
		pGb->textHeight = GetTextHeight(pGb->hdr.pGolScheme->pFont);
    }
	GOLAddObject((OBJ_HEADER*) pGb);	
	return pGb;
}

/*********************************************************************
* Function: WORD GbTranslateMsg(GROUPBOX *pGb, GOL_MSG *pMsg)
*
* Notes: Evaluates the message if the object will be affected by the 
*		 message or not.
*
********************************************************************/
WORD GbTranslateMsg(GROUPBOX *pGb, GOL_MSG *pMsg)
{
	// Evaluate if the message is for the button
    // Check if disabled first
	if (!GetState(pGb, GB_DISABLED)) {

#ifdef USE_TOUCHSCREEN
	    if(pMsg->type == TYPE_TOUCHSCREEN) {
			// Check if it falls to the left or right of the center of the thumb's face
			if( (pGb->hdr.left     < pMsg->param1) &&
		  	    (pGb->hdr.right    > pMsg->param1) &&
		   	    (pGb->hdr.top      < pMsg->param2) &&
		   	    (pGb->hdr.bottom   > pMsg->param2) ) {
			       	
			    	if((pMsg->uiEvent == EVENT_PRESS) || (pMsg->uiEvent == EVENT_RELEASE)) 
			    		return GB_MSG_SELECTED;
			 }
		}	 
#endif

	}	


	return OBJ_MSG_INVALID;	
}

/*********************************************************************
* Function: WORD GbDraw(GROUPBOX *pGb);
*
* Notes: This is the state machine to draw the button.
*
********************************************************************/
#if (COLOR_DEPTH == 1)
	#define THREE_D_EFFECT   0
#else	
	#define THREE_D_EFFECT   1
#endif	
WORD GbDraw(GROUPBOX *pGb)
{
typedef enum {
	GB_STATE_IDLE,
	GB_STATE_HIDETEXT,
	GB_STATE_SETDIMENSION,
	GB_STATE_DRAWTEXT,
	GB_STATE_DRAWTOPRIGHT,
    GB_STATE_DRAWTOPLEFT,
	GB_STATE_DRAWSIDELEFT, 
	GB_STATE_DRAWSIDERIGHT,
	GB_STATE_DRAWBOTTOM,
#if (COLOR_DEPTH != 1)
	GB_STATE_2DRAWTOPRIGHT,
    GB_STATE_2DRAWTOPLEFT,
	GB_STATE_2DRAWSIDELEFT, 
	GB_STATE_2DRAWSIDERIGHT,
	GB_STATE_2DRAWBOTTOM,
#endif	
} GB_DRAW_STATES;	
	
static GB_DRAW_STATES state = GB_STATE_IDLE;
static SHORT textLeft, textRight, top;						// used to draw lines that start/stops at text.

    if(IsDeviceBusy())
        return 0;

    switch(state){
	    
        case GB_STATE_IDLE:

            if(IsDeviceBusy())
                return 0;  

	        if (GetState(pGb,GB_HIDE)) {					// Hide the Group Box (remove from screen)
       	        SetColor(pGb->hdr.pGolScheme->CommonBkColor);
       	        Bar(pGb->hdr.left, pGb->hdr.top, pGb->hdr.right, pGb->hdr.bottom);
       	        return 1;
		    }
  	        state = GB_STATE_HIDETEXT;

        case GB_STATE_HIDETEXT:								// hide the text first
            if (pGb->pText != NULL) {  						// needed when dynamically changing 
            	SetColor(pGb->hdr.pGolScheme->CommonBkColor);	// the alignement of text
            	Bar(pGb->hdr.left,  pGb->hdr.top,				\
            	    pGb->hdr.right, pGb->hdr.top+pGb->textHeight);
            }	
  	        state = GB_STATE_SETDIMENSION;

        case GB_STATE_SETDIMENSION:

 			if(IsDeviceBusy())
                return 0;    		    
                
	        if (GetState(pGb,GB_DISABLED)) {				// set color to inactive color
	            SetColor(pGb->hdr.pGolScheme->TextColorDisabled);    
			}	
			else {
				SetColor(pGb->hdr.pGolScheme->TextColor0);		// active color
			}	

            if (pGb->pText == NULL) {  						// there is no text, use full dimensions
	            top       = pGb->hdr.top;
   				textLeft  = pGb->hdr.left + 1;
   				textRight = textLeft;
			   	state = GB_STATE_DRAWTOPRIGHT;				// go to drawing of right top line
			   	goto gb_state_draw_lines;
		   	}
		   	else {											// text is present, set up dimensions with text
	            SetFont(pGb->hdr.pGolScheme->pFont);
	            top = pGb->hdr.top+(pGb->textHeight>>1);		// adjust lines on top

		        if (pGb->hdr.state&GB_RIGHT_ALIGN) {
		           	// do right aligned
	   				textLeft  = pGb->hdr.right-pGb->textWidth-2;
	   				textRight = pGb->hdr.right-2;
	        	}    
	           	else if (pGb->hdr.state&GB_CENTER_ALIGN) {
			       	// do center aligned
	   				textLeft  = (pGb->hdr.left+ pGb->hdr.right-pGb->textWidth)>>1;
	   				textRight = textLeft + pGb->textWidth;
		       	}   
		       	else {
		            // do left aligned
	   				textLeft  = pGb->hdr.left+2;
	   				textRight = pGb->hdr.left+2 + pGb->textWidth;
			   	} 
			   	MoveTo(textLeft, pGb->hdr.top);					// move cursor to start of text
  			   	state = GB_STATE_DRAWTEXT;
		   	}
		   	
        case GB_STATE_DRAWTEXT:

 			if(!OutText(pGb->pText))
                return 0;
   			#if (COLOR_DEPTH == 1)
	   	        SetColor(WHITE);
			#else
	   	        SetColor(pGb->hdr.pGolScheme->EmbossDkColor);
	   	    #endif    
            state = GB_STATE_DRAWTOPRIGHT;
            
gb_state_draw_lines:

        case GB_STATE_DRAWTOPRIGHT:
        
            if(IsDeviceBusy())
                return 0;    
			Line(textRight, top + THREE_D_EFFECT, pGb->hdr.right, top + THREE_D_EFFECT);	// top line at right
			state = GB_STATE_DRAWTOPLEFT;
			
        case GB_STATE_DRAWTOPLEFT:
        
            if(IsDeviceBusy())
                return 0;    
			Line(pGb->hdr.left+THREE_D_EFFECT, top + THREE_D_EFFECT, textLeft, top + THREE_D_EFFECT);	// top line at left
			state = GB_STATE_DRAWSIDELEFT;

        case GB_STATE_DRAWSIDELEFT:
        
            if(IsDeviceBusy())
                return 0;    
			Line(pGb->hdr.left+THREE_D_EFFECT, top + THREE_D_EFFECT, 					\
			     pGb->hdr.left+THREE_D_EFFECT, pGb->hdr.bottom); 				// side line at left
			state = GB_STATE_DRAWSIDERIGHT;
			
        case GB_STATE_DRAWSIDERIGHT:
        
            if(IsDeviceBusy())
                return 0;    
			Line(pGb->hdr.right, top + THREE_D_EFFECT, 					\
			     pGb->hdr.right, pGb->hdr.bottom);   				// side line at right
			state = GB_STATE_DRAWBOTTOM;

        case GB_STATE_DRAWBOTTOM:
        
            if(IsDeviceBusy())
                return 0;    
			Line(pGb->hdr.left+THREE_D_EFFECT, pGb->hdr.bottom, 				\
			     pGb->hdr.right, pGb->hdr.bottom);   				// bottom line
			#if (COLOR_DEPTH == 1)
            	state = GB_STATE_IDLE;
			#else
				state = GB_STATE_2DRAWTOPLEFT;
            #endif
	        
#if (COLOR_DEPTH != 1)
        case GB_STATE_2DRAWTOPLEFT:
        
            if(IsDeviceBusy())
                return 0;    
			SetColor(pGb->hdr.pGolScheme->EmbossLtColor);		// 2nd line top line at left
			Line(pGb->hdr.left, top, textLeft,  top);
           	state = GB_STATE_2DRAWTOPRIGHT;
            
        case GB_STATE_2DRAWTOPRIGHT:
        
            if(IsDeviceBusy())
                return 0;    
			Line(textRight, top, pGb->hdr.right, top);			// 2nd line top line at right
            state = GB_STATE_2DRAWSIDELEFT;

	    case GB_STATE_2DRAWSIDELEFT:

            if(IsDeviceBusy())
   	            return 0;    
			Line(pGb->hdr.left, top, pGb->hdr.left, pGb->hdr.bottom-1);	// 2nd line left
            state =  GB_STATE_2DRAWSIDERIGHT;

	    case  GB_STATE_2DRAWSIDERIGHT:

            if(IsDeviceBusy())
   	            return 0;    
			Line(pGb->hdr.right-1, top+2, 					\
			     pGb->hdr.right-1, pGb->hdr.bottom-1);				// 2nd line right
            state = GB_STATE_2DRAWBOTTOM;

	    case GB_STATE_2DRAWBOTTOM:

            if(IsDeviceBusy())
   	            return 0;    
			Line(pGb->hdr.left+2, pGb->hdr.bottom-1, 			\
			     pGb->hdr.right-1, pGb->hdr.bottom-1);				// 2nd line bottom
   	        state = GB_STATE_IDLE;
#endif 

	}    	
	return 1;
}

#endif // USE_GROUPBOX


