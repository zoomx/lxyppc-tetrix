/*****************************************************************************
 *  Module for Microchip Graphics Library 
 *  GOL Layer 
 *  Window
 *****************************************************************************
 * FileName:        Window.c
 * Dependencies:    Graphics.h 
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
 * Anton Alkhimenok 	11/12/07	Version 1.0 release
 *****************************************************************************/
#include "Graphics\Graphics.h"

#ifdef USE_WINDOW

/*********************************************************************
* Function: WINDOW  *WndCreate(WORD ID, SHORT left, SHORT top, SHORT right, 
*                              SHORT bottom, WORD state, XCHAR *pText, void* pBitmap,
*                              GOL_SCHEME *pScheme)
*
* Overview: creates the window
*
********************************************************************/
WINDOW *WndCreate(WORD ID, SHORT left, SHORT top, SHORT right, SHORT bottom,
			      WORD state, void *pBitmap, XCHAR *pText, GOL_SCHEME *pScheme)
{
	WINDOW *pW;
	
	pW = (WINDOW*)malloc(sizeof(WINDOW));
	if (pW == NULL)
		return pW;

	pW->hdr.ID      	= ID;
	pW->hdr.pNxtObj 	= NULL;
	pW->hdr.type    	= OBJ_WINDOW;
	pW->hdr.left    	= left;
	pW->hdr.top     	= top;
	pW->hdr.right   	= right;
	pW->hdr.bottom  	= bottom;
	pW->pBitmap  		= pBitmap;
	pW->pText   		= pText;
	pW->hdr.state       = state;

	// Set the style scheme to be used
	if (pScheme == NULL)
		pW->hdr.pGolScheme = _pDefaultGolScheme; 
    else
		pW->hdr.pGolScheme = pScheme;
    

    pW->textHeight  = 0;
    if(pText != NULL){
        pW->textHeight = GetTextHeight(pW->hdr.pGolScheme->pFont);
    }

    GOLAddObject((OBJ_HEADER*) pW);
	
	return pW;
}

/*********************************************************************
* Function: WndSetText(WINDOW *pW, XCHAR *pText)
*
* Overview: sets text
*
********************************************************************/
void WndSetText(WINDOW *pW, XCHAR *pText)
{
	pW->pText = pText;
	pW->textHeight = GetTextHeight(pW->hdr.pGolScheme->pFont);
}

/*********************************************************************
* Function: WORD WndTranslateMsg(WINDOW *pW, GOL_MSG *pMsg)
*
* Overview: translates the GOL message for the window
*
********************************************************************/
WORD WndTranslateMsg(WINDOW *pW, GOL_MSG *pMsg)
{
	// Evaluate if the message is for the window
    // Check if disabled first
	if ( GetState(pW,WND_DISABLED) )
		return OBJ_MSG_INVALID;

#ifdef USE_TOUCHSCREEN
    if( pMsg->type == TYPE_TOUCHSCREEN ){

    	// Check if it falls in the title bar area
	    if( (pW->hdr.left   < pMsg->param1) &&
   	        (pW->hdr.right  > pMsg->param1) &&
            (pW->hdr.top    < pMsg->param2) &&
            (pW->hdr.top+WND_TITLE_HEIGHT+GOL_EMBOSS_SIZE > pMsg->param2) ){

            return WND_MSG_TITLE;

        }

        // Check if it falls in the client area
   	    if( (pW->hdr.left+GOL_EMBOSS_SIZE < pMsg->param1) &&
            (pW->hdr.right-GOL_EMBOSS_SIZE > pMsg->param1) &&
            (pW->hdr.top+WND_TITLE_HEIGHT+GOL_EMBOSS_SIZE < pMsg->param2) &&
            (pW->hdr.bottom-GOL_EMBOSS_SIZE > pMsg->param2) ){

            return WND_MSG_CLIENT;    

        }
    }
#endif

	return OBJ_MSG_INVALID;	
}

/*********************************************************************
* Function: WORD WndDraw(WINDOW *pW)
*
* Overview: draws window
*
********************************************************************/
WORD WndDraw(WINDOW *pW){

typedef enum {
    WND_REMOVE,
	WND_TITLE_BAR_DRAW,
	WND_TITLE_BAR_BITMAP,
	WND_TITLE_BAR_TEXT,
	WND_TITLE_BAR_TEXT_DRAW,
    WND_CLIENT,
    WND_CLIENT_DRAW
} WND_DRAW_STATES;

SHORT temp;
static WND_DRAW_STATES state = WND_REMOVE;

    while(1){

        if(IsDeviceBusy())
            return 0;

        switch(state){

            case WND_REMOVE:
                if(GetState(pW,WND_HIDE)){
                    SetColor(pW->hdr.pGolScheme->CommonBkColor);
                    if(!Bar(pW->hdr.left,pW->hdr.top,pW->hdr.right,pW->hdr.bottom))
                    {
                        return 0;
                    }
                    return 1;                  
                }
                
if(GetState(pW,WND_DRAW_CLIENT)){

                state = WND_CLIENT;
                break;

            case WND_CLIENT:
	   			SetLineThickness(NORMAL_LINE);
				SetLineType(SOLID_LINE);			
		        GOLPanelDraw(pW->hdr.left,pW->hdr.top,pW->hdr.right,pW->hdr.bottom, 0,
                         pW->hdr.pGolScheme->CommonBkColor,
                         pW->hdr.pGolScheme->EmbossLtColor,
                         pW->hdr.pGolScheme->EmbossDkColor,
                         NULL,
                         GOL_EMBOSS_SIZE);

                state = WND_CLIENT_DRAW;

            case WND_CLIENT_DRAW:

                if(!GOLPanelDrawTsk())
                    return 0;

}
                state = WND_TITLE_BAR_DRAW;
                break;

            case WND_TITLE_BAR_DRAW:

                if(!GetState(pW,WND_DISABLED)){
    	            if(GetState(pW,WND_FOCUSED)){
                        SetColor(pW->hdr.pGolScheme->Color1);
	                }else{

                        SetColor(pW->hdr.pGolScheme->Color0);
                    }
                }else{
                        SetColor(pW->hdr.pGolScheme->ColorDisabled);
                }

                if(!Bar(pW->hdr.left+GOL_EMBOSS_SIZE, pW->hdr.top+GOL_EMBOSS_SIZE,
                    pW->hdr.right-GOL_EMBOSS_SIZE, pW->hdr.top+GOL_EMBOSS_SIZE+WND_TITLE_HEIGHT))
                {
                    return 0;
                }

                state = WND_TITLE_BAR_BITMAP;
                
                break;
              
            case WND_TITLE_BAR_BITMAP:

        	    if (pW->pBitmap != NULL){
                    if(!PutImage(pW->hdr.left+GOL_EMBOSS_SIZE,
                             pW->hdr.top+GOL_EMBOSS_SIZE+((WND_TITLE_HEIGHT-GetImageHeight(pW->pBitmap))>>1),
                             pW->pBitmap,IMAGE_NORMAL))
                             {
                                 return 0;
                             }
                }

if (pW->pText != NULL){

                state = WND_TITLE_BAR_TEXT;
                break;

            case WND_TITLE_BAR_TEXT:

                SetFont(pW->hdr.pGolScheme->pFont);

                if(!GetState(pW,WND_DISABLED)){

        	        if (GetState(pW,WND_FOCUSED)){
	        	        SetColor(pW->hdr.pGolScheme->TextColor1);
	                }else{
		                SetColor(pW->hdr.pGolScheme->TextColor0);
                    }

                }else{
		            SetColor(pW->hdr.pGolScheme->TextColorDisabled);
                }
                    
                temp = pW->hdr.left+GOL_EMBOSS_SIZE+WND_INDENT;

                if(pW->pBitmap != NULL){
                    temp += GetImageWidth(pW->pBitmap);
                }

				if (GetState(pW, WND_TITLECENTER)) {
					temp = (temp + (pW->hdr.right-GetTextWidth(pW->pText, pW->hdr.pGolScheme->pFont)))>>1;  
				}	
                MoveTo(temp, pW->hdr.top+GOL_EMBOSS_SIZE+((WND_TITLE_HEIGHT-pW->textHeight)>>1));

                state = WND_TITLE_BAR_TEXT_DRAW;

            case WND_TITLE_BAR_TEXT_DRAW:
                if(!OutText(pW->pText))
                    return 0;	
}
                state = WND_REMOVE;
                return 1;

        }//end of switch

    }//end of while
}

#endif // USE_WINDOW

