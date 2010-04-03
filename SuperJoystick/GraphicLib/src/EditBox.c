/*****************************************************************************
 *  Module for Microchip Graphics Library 
 *  GOL Layer 
 *  Edit Box
 *****************************************************************************
 * FileName:        EditBox.c
 * Dependencies:    None 
 * Processor:       PIC24F, PIC24H, dsPIC, PIC32
 * Compiler:       	MPLAB C30 V3.00, C32
 * Linker:          MPLAB LINK30, LINK32
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
 * Anton Alkhimenok     11/12/07	Version 1.0 release
*****************************************************************************/
#include "Graphics\Graphics.h"

#ifdef USE_EDITBOX

/*********************************************************************
* Function: EDITBOX  *EbCreate(WORD ID, SHORT left, SHORT top, SHORT right, SHORT bottom, 
*							   WORD state , XCHAR *pText, WORD charMax, GOL_SCHEME *pScheme)
*
* Notes: Create the EDITBOX Object.
*
********************************************************************/
EDITBOX  *EbCreate(WORD ID, SHORT left, SHORT top, SHORT right, SHORT bottom, 
				   WORD state , XCHAR *pText, WORD charMax, GOL_SCHEME *pScheme){

	EDITBOX *pEb = NULL;

  	pEb = (EDITBOX*)malloc(sizeof(EDITBOX)+ (charMax + 1)*sizeof(XCHAR)); // ending zero is not included into charMax
	if (pEb == NULL)
		return pEb;

    pEb->pBuffer  = (XCHAR*)((BYTE*)pEb+sizeof(EDITBOX));
    *pEb->pBuffer = 0;
    pEb->length   = 0;
    pEb->charMax  = charMax;

    if(pText != NULL)
        EbSetText(pEb, pText);
	
	pEb->hdr.ID      	= ID;					
	pEb->hdr.pNxtObj 	= NULL;					
	pEb->hdr.type    	= OBJ_EDITBOX;		    
	pEb->hdr.left    	= left;       	    	
	pEb->hdr.top     	= top;
	pEb->hdr.right   	= right;     	    	
	pEb->hdr.bottom  	= bottom;
	pEb->hdr.state   	= state; 	

	// Set the style scheme to be used
	if (pScheme == NULL)
		pEb->hdr.pGolScheme = _pDefaultGolScheme; 
	else 	
		pEb->hdr.pGolScheme = (GOL_SCHEME *)pScheme; 	

    pEb->textHeight = GetTextHeight(pEb->hdr.pGolScheme->pFont);
  
    GOLAddObject((OBJ_HEADER*) pEb);
	return pEb;
}

/*********************************************************************
* Function: EbSetText(EDITBOX *pEb, XCHAR *pText)
*
* Notes: Sets a new text.
*
********************************************************************/
void EbSetText(EDITBOX *pEb, XCHAR *pText){
WORD  ch;
WORD  length;
XCHAR* pointerFrom;
XCHAR* pointerTo;
  
    // Copy and count length
    pointerFrom = pText;
    pointerTo = pEb->pBuffer;
    length = 0;

    do{
        ch = *pointerFrom++;
        *pointerTo++ = ch;
        length++;
        if(length >= pEb->charMax){
            *pointerTo = 0;
            break;
        }
    }while(ch);


    pEb->length = length-1;
}

/*********************************************************************
* Function: void  EbAddChar(EDITBOX* pEb, XCHAR ch)
*
* Notes: Adds character at the end.
*
********************************************************************/
void EbAddChar(EDITBOX* pEb, XCHAR ch){

    if(pEb->length >= pEb->charMax)
        return;

    // Add character
    pEb->pBuffer[pEb->length] = ch;
    pEb->length++;
    pEb->pBuffer[pEb->length] = 0;
}

/*********************************************************************
* Function: void  EbDeleteChar(EDITBOX* pEb)
*
* Notes: Deletes character at the end.
*
********************************************************************/
void EbDeleteChar(EDITBOX* pEb){

    if(pEb->length == 0)
        return;

    // Delete charachter
    pEb->length--;
    pEb->pBuffer[pEb->length] = 0;

}

/*********************************************************************
* Function: WORD StTranslateMsg(EDITBOX *pEb, GOL_MSG *pMsg)
*
* Notes: Translates GOL message for the edit box
*
********************************************************************/
WORD EbTranslateMsg(EDITBOX *pEb, GOL_MSG *pMsg)
{
    // Evaluate if the message is for the edit box
    // Check if disabled first
	if (GetState(pEb, EB_DISABLED))
      return OBJ_MSG_INVALID;

#ifdef  USE_FOCUS
#ifdef  USE_TOUCHSCREEN
    if(pMsg->type == TYPE_TOUCHSCREEN) {
		// Check if it falls in edit box borders
		if( (pEb->hdr.left     < pMsg->param1) &&
	  	    (pEb->hdr.right    > pMsg->param1) &&
	   	    (pEb->hdr.top      < pMsg->param2) &&
	   	    (pEb->hdr.bottom   > pMsg->param2) ) 
            return EB_MSG_TOUCHSCREEN;
           
        return OBJ_MSG_INVALID;
	}
#endif	
#endif

#ifdef  USE_KEYBOARD
    if(pMsg->type == TYPE_KEYBOARD) {

        if(pMsg->uiEvent == EVENT_CHARCODE)
            return EB_MSG_CHAR;  

        if(pMsg->uiEvent == EVENT_KEYSCAN)
            if(pMsg->param2 == SCAN_BS_PRESSED)
                return EB_MSG_DEL;
        
	    return OBJ_MSG_INVALID;
	}
#endif	


	return OBJ_MSG_INVALID;
}

/*********************************************************************
* Function: void EbMsgDefault(WORD translatedMsg, EDITBOX *pEb, GOL_MSG *pMsg)
*
* Notes: Changes the state of the edit box by default.
*
********************************************************************/
void EbMsgDefault(WORD translatedMsg, EDITBOX *pEb, GOL_MSG *pMsg){

#ifdef  USE_FOCUS
#ifdef  USE_TOUCHSCREEN
    if(pMsg->type == TYPE_TOUCHSCREEN){
        if(!GetState(pEb,BTN_FOCUSED)){
                GOLSetFocus((OBJ_HEADER*)pEb);
        }
    }
#endif
#endif

    switch(translatedMsg){

        case EB_MSG_CHAR:
            EbAddChar(pEb,(XCHAR)pMsg->param2);
            SetState(pEb, EB_DRAW);
            break;

        case EB_MSG_DEL:
            EbDeleteChar(pEb);
            SetState(pEb, EB_DRAW);
            break;

    }
}

/*********************************************************************
* Function: WORD EbDraw(EDITBOX *pEb)
*
* Notes: This is the state machine to draw the button.
*
********************************************************************/
WORD EbDraw(EDITBOX *pEb)
{
typedef enum {
	EB_STATE_START,
	EB_STATE_PANEL,
	EB_STATE_TEXT,
    EB_STATE_CARET,
} EB_DRAW_STATES;

static EB_DRAW_STATES state = EB_STATE_START;
SHORT temp;
SHORT width;

    if(IsDeviceBusy())
        return 0;
        
    switch(state){

        case EB_STATE_START:

          	if(GetState(pEb, EB_HIDE)){
   	   	        SetColor(pEb->hdr.pGolScheme->CommonBkColor);
    	        if(!Bar(pEb->hdr.left,pEb->hdr.top,pEb->hdr.right,pEb->hdr.bottom)) return 0;
    	        return 1;
    	    }    

            if(GetState(pEb,EB_DISABLED)){
                temp = pEb->hdr.pGolScheme->ColorDisabled;
                ClrState(pEb,EB_CARET);
	        }else{
                temp = pEb->hdr.pGolScheme->Color0;
                if(GetState(pEb,EB_DRAW)){
                    if(GetState(pEb,EB_FOCUSED)){
                        SetState(pEb,EB_CARET);
                    }else{
                        ClrState(pEb,EB_CARET);
                    }
                }
            }

    if(GetState(pEb,EB_DRAW)){

            GOLPanelDraw(pEb->hdr.left,pEb->hdr.top,pEb->hdr.right,pEb->hdr.bottom,0,
                temp,
                pEb->hdr.pGolScheme->EmbossDkColor,
                pEb->hdr.pGolScheme->EmbossLtColor,
                NULL,
                GOL_EMBOSS_SIZE);

            state = EB_STATE_PANEL;

        case EB_STATE_PANEL:

            if(!GOLPanelDrawTsk())
                return 0;

    }

            SetClip(CLIP_ENABLE);

            SetClipRgn(pEb->hdr.left+GOL_EMBOSS_SIZE+EB_INDENT,
                       pEb->hdr.top+GOL_EMBOSS_SIZE+EB_INDENT,
                       pEb->hdr.right-GOL_EMBOSS_SIZE-EB_INDENT,
                       pEb->hdr.bottom-GOL_EMBOSS_SIZE-EB_INDENT);

	        SetFont(pEb->hdr.pGolScheme->pFont);

            if(GetState(pEb,EB_DISABLED)){
                SetColor(pEb->hdr.pGolScheme->TextColorDisabled);
            }else{
                SetColor(pEb->hdr.pGolScheme->TextColor0);
            }  

            MoveTo(GetX(),(pEb->hdr.top+pEb->hdr.bottom-pEb->textHeight)>>1);


            width = GetTextWidth(pEb->pBuffer,pEb->hdr.pGolScheme->pFont);

            if (!GetState(pEb, EB_CENTER_ALIGN|EB_RIGHT_ALIGN)) {
                MoveTo(pEb->hdr.left+GOL_EMBOSS_SIZE+EB_INDENT, GetY());
            }else{
                if (GetState(pEb, EB_RIGHT_ALIGN)) {
			        MoveTo(pEb->hdr.right-width-EB_INDENT-GOL_EMBOSS_SIZE, GetY());
                }else{
                    MoveTo((pEb->hdr.left+pEb->hdr.right-width)>>1,GetY());
                }
            }

    if(GetState(pEb,EB_DRAW)){

		    state = EB_STATE_TEXT;
			
        case EB_STATE_TEXT:
            if(!OutText(pEb->pBuffer))
                return 0;
    }else{

        MoveRel(width, 0);

    }

			state = EB_STATE_CARET;

        case EB_STATE_CARET:
            if(!GetState(pEb,EB_DISABLED)){
                if(GetState(pEb,EB_CARET)){
                    SetColor(pEb->hdr.pGolScheme->TextColor0);
                }else{
                    SetColor(pEb->hdr.pGolScheme->Color0);
                }
                if(!Bar(GetX(),GetY(),GetX()+EB_CARET_WIDTH,GetY()+pEb->textHeight)) return 0;
            }
            SetClip(CLIP_DISABLE);
			state = EB_STATE_START;
			return 1;
    }
    return 1;
}

#endif // USE_EDITBOX
