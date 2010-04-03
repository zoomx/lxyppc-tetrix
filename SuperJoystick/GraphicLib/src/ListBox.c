/*****************************************************************************
 *  Module for Microchip Graphics Library 
 *  GOL Layer 
 *  List Box
 *****************************************************************************
 * FileName:        ListBox.c
 * Dependencies:    None 
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
 * Anton Alkhimenok     11/12/07	Version 1.0 release
*****************************************************************************/
#include "Graphics\Graphics.h"

#ifdef USE_LISTBOX

/*********************************************************************
* Function: LISTBOX  *LbCreate(WORD ID, SHORT left, SHORT top, SHORT right, SHORT bottom, 
*				               WORD state, XCHAR* pText, GOL_SCHEME *pScheme)
*
* Overview: creates the list box
*
********************************************************************/
LISTBOX *LbCreate(WORD ID, SHORT left, SHORT top, SHORT right, SHORT bottom, 
		   	      WORD state , XCHAR* pText, GOL_SCHEME *pScheme)

{
	LISTBOX *pLb = NULL;
    XCHAR* pointer;
    WORD  counter;    

  	pLb = (LISTBOX*)malloc(sizeof(LISTBOX));

	if(pLb == NULL)
	    return pLb;

	pLb->hdr.ID      	= ID;
	pLb->hdr.pNxtObj 	= NULL;
	pLb->hdr.type    	= OBJ_LISTBOX;
	pLb->hdr.left    	= left;
	pLb->hdr.top     	= top;
	pLb->hdr.right   	= right;
	pLb->hdr.bottom  	= bottom;
	pLb->hdr.state   	= state; 
    pLb->pItemList  = NULL;	
    pLb->scrollY    = 0;
    pLb->itemsNumber = 0;

	// Set the style scheme to be used
	if (pScheme == NULL)
		pLb->hdr.pGolScheme = _pDefaultGolScheme; 
	else 	
		pLb->hdr.pGolScheme = (GOL_SCHEME *)pScheme; 	

    pLb->textHeight = GetTextHeight(pLb->hdr.pGolScheme->pFont);
	
    GOLAddObject((OBJ_HEADER*) pLb);

    // Add items if there's an initialization text (each line will become one item,
    // lines must be separated by '\n' character)
    if(pText != NULL){
        pointer = pText;
        counter = 0;
        while(*pointer){
            if(NULL == LbAddItem(pLb, NULL, pointer, NULL, 0, counter))
                break;
            while((unsigned XCHAR)*pointer++ > (unsigned XCHAR)31);
            if(*(pointer-1) == 0)
                break;
            counter++;
        }
    }
    
    pLb->pFocusItem = pLb->pItemList;

    // Set focus for the object if FOCUSED state is set
#ifdef  USE_FOCUS
    if(GetState(pLb,LB_FOCUSED))
        GOLSetFocus((OBJ_HEADER*)pLb);
#endif

	return pLb;
}

/*********************************************************************
* Function: LISTITEM* LbAddItem(LISTBOX *pLb, LISTITEM *pPrevItem, XCHAR *pText, void* pBitmap, WORD status, WORD data)
*
* Input: pLb - the pointer to the list box,
*        pPrevItem - pointer to the item after which a new item must be inserted,
*                    if this pointer is NULL, the item will be appended at the end of the items list,
*        pText -  pointer to the text,
*        pBitmap - pointer to the bitmap,
*        status - status after creation,
*        data -  some data associated with the item
*
* Output: pointer to the item created, NULL if the operation was not successful
*
* Overview: allocates memory for a new item and adds it to the list box
*
********************************************************************/
LISTITEM* LbAddItem(LISTBOX *pLb, LISTITEM *pPrevItem, XCHAR *pText, void* pBitmap, WORD status, WORD data){
LISTITEM* pItem;
LISTITEM* pCurItem; 

    pItem = (LISTITEM*) malloc(sizeof(LISTITEM));

    if(pItem == NULL){
        return NULL;
    }

    pLb->itemsNumber++;

    if(pLb->pItemList == NULL){

        pLb->pItemList = pItem;
        pItem->pNextItem = NULL;
        pItem->pPrevItem = NULL;

    }else{

        if(pPrevItem == NULL){
            // Find last item
            pCurItem = (LISTITEM*)pLb->pItemList;
            while(pCurItem->pNextItem != NULL)
                pCurItem = (LISTITEM*)pCurItem->pNextItem;
        }else{
            pCurItem = (LISTITEM*)pPrevItem;
        }

        // Insert a new item
        pItem->pNextItem = pCurItem->pNextItem;
        pItem->pPrevItem = pCurItem;
        pCurItem->pNextItem = pItem;
    }
    
    pItem->pText = pText;
    pItem->pBitmap = pBitmap;
    pItem->status = status;
    pItem->data = data;

    return pItem;
}

/*********************************************************************
* Function: void LbDelItem(LISTBOX *pLb, LISTITEM *pItem)
*
* Input: pLb - the pointer to the object,
*        pItem - the pointer to the item must be deleted
*
* Output: none
*
* Overview: removes an item from the list box and frees memory
*
********************************************************************/
void LbDelItem(LISTBOX *pLb, LISTITEM *pItem){

    if(pItem->pNextItem != NULL){
        ((LISTITEM*)pItem->pNextItem)->pPrevItem = pItem->pPrevItem;
        if(pItem->pPrevItem == NULL)
            pLb->pItemList = (LISTITEM*)pItem->pNextItem;
    }

    if(pItem->pPrevItem != NULL)
        ((LISTITEM*)pItem->pPrevItem)->pNextItem = pItem->pNextItem;

    free(pItem);

    pLb->itemsNumber--;

	if(pLb->itemsNumber == 0)
		pLb->pItemList = NULL;
}

/*********************************************************************
* Function: void LbDelItemsList(LISTBOX *pLb)
*
* Input: pLb - the pointer to the object
*
* Output: none
*
* Overview: removes all items from list box and frees memory
*
********************************************************************/
void LbDelItemsList(LISTBOX *pLb){
LISTITEM* pCurItem;
LISTITEM* pItem;

    pCurItem = pLb->pItemList;

    while(pCurItem != NULL){
        pItem = pCurItem;
        pCurItem = (LISTITEM*)pCurItem->pNextItem;
        free(pItem);
    }
	pLb->pItemList = NULL;
}

/*********************************************************************
* Function: LISTITEM* LbGetSel(LISTBOX *pLb, LISTITEM *pFromItem)
*
* Input: pLb - the pointer to the object,
*        pFromItem - pointer to the item the seach must start from,
*                    if the pointer is NULL the search begins from the start of the items list
*
* Output: pointer to the selected item, NULL if there are no items selected
*
* Overview: seaches for selected items
*
********************************************************************/
LISTITEM* LbGetSel(LISTBOX *pLb, LISTITEM *pFromItem){
    if(pFromItem == NULL){
        pFromItem = pLb->pItemList;
    }
    while(pFromItem != NULL){
        if(pFromItem->status&LB_STS_SELECTED)
            break;
        pFromItem = (LISTITEM*)pFromItem->pNextItem;
    }
    return pFromItem;
}

/*********************************************************************
* Function: void LbChangeSel(LISTBOX *pLb, LISTITEM *pItem)
*
* Input: pLb - the pointer to the object,
*        pItem - pointer to the item the selection status will be changed
*
* Output: none
*
* Overview: changes selection status of an item
*
********************************************************************/
void LbChangeSel(LISTBOX *pLb, LISTITEM *pItem){
LISTITEM* pCurItem;

    if( GetState(pLb, LB_SINGLE_SEL)){
        // Remove selection from all items
        pCurItem = pLb->pItemList;
        while(pCurItem != NULL){
            if(pCurItem->status&LB_STS_SELECTED){
                pCurItem->status &= ~LB_STS_SELECTED;
                pCurItem->status |= LB_STS_REDRAW;
            }
            pCurItem = (LISTITEM*)pCurItem->pNextItem;
        }
    }
    pItem->status ^= LB_STS_SELECTED;
    pItem->status |= LB_STS_REDRAW;
}

/*********************************************************************
* Function: void LbSetFocusedItem(LISTBOX* pLb, SHORT index)
*
* Input: pLb - the pointer to the object
*        index - item number from the list beginning
*
* Output: none
*
* Overview: sets focus for the item with index defined
*
********************************************************************/
void LbSetFocusedItem(LISTBOX* pLb, SHORT index){
LISTITEM* pCurItem;

    // Look for item to be focused
    pCurItem = pLb->pItemList;
    while(pCurItem->pNextItem != NULL){
        if(index <= 0)
            break;
        index--;
        pCurItem = (LISTITEM*)pCurItem->pNextItem;    
    }

    if(pCurItem != NULL){
        if(pLb->pFocusItem != NULL){
            pLb->pFocusItem->status |= LB_STS_REDRAW;
        }
        pLb->pFocusItem = pCurItem;
        pCurItem->status |= LB_STS_REDRAW;
    }
}

/*********************************************************************
* Function: SHORT LbGetFocusedItem(LISTBOX* pLb)
*
* Input: pLb - the pointer to the list box
*
* Output: index of the focused item, -1 if there's no item in focus
*
* Overview: returns focused item number from the list beginning
*
********************************************************************/
SHORT LbGetFocusedItem(LISTBOX* pLb){
LISTITEM* pCurItem;
SHORT     index;

    if(pLb->pFocusItem == NULL)
        return -1;

    // Look for the focused item index
    index = 0;
    pCurItem = pLb->pItemList;
    while(pCurItem->pNextItem != NULL){
        if(pCurItem == pLb->pFocusItem)
            break;
        index++;
        pCurItem = (LISTITEM*)pCurItem->pNextItem;    
    }

    return index;
}

/*********************************************************************
* Function: WORD LbTranslateMsg(LISTBOX *pLb, GOL_MSG *pMsg)
*
* Overview: translates the GOL message for the list box
*
********************************************************************/
WORD LbTranslateMsg(LISTBOX *pLb, GOL_MSG *pMsg)
{
    // Evaluate if the message is for the list box
    // Check if disabled first
	if(GetState(pLb, LB_DISABLED))
      return OBJ_MSG_INVALID;

#ifdef  USE_TOUCHSCREEN
    if(pMsg->type == TYPE_TOUCHSCREEN) {
		// Check if it falls in list box borders
		if( (pLb->hdr.left     < pMsg->param1) &&
	  	    (pLb->hdr.right    > pMsg->param1) &&
	   	    (pLb->hdr.top      < pMsg->param2) &&
	   	    (pLb->hdr.bottom   > pMsg->param2) )
                 return LB_MSG_TOUCHSCREEN;
         
        return OBJ_MSG_INVALID;
	}
#endif	

#ifdef  USE_KEYBOARD
    if(pMsg->type == TYPE_KEYBOARD)
    if(pMsg->param1 == pLb->hdr.ID) {
        if(pMsg->uiEvent == EVENT_KEYSCAN){
            if( (pMsg->param2 == SCAN_UP_PRESSED)||
                (pMsg->param2 == SCAN_DOWN_PRESSED) )
                return LB_MSG_MOVE;

            if( (pMsg->param2 == SCAN_SPACE_PRESSED)||
                (pMsg->param2 == SCAN_CR_PRESSED) )
                return LB_MSG_SEL;

        }   
	    return OBJ_MSG_INVALID;
	}
#endif	


	return OBJ_MSG_INVALID;
}

/*********************************************************************
* Function: void LbMsgDefault(WORD translatedMsg, LISTBOX *pLb, GOL_MSG *pMsg)
*
* Overview: changes the state of the list box by default
*
********************************************************************/
void LbMsgDefault(WORD translatedMsg, LISTBOX *pLb, GOL_MSG *pMsg){

#ifdef  USE_TOUCHSCREEN

SHORT     pos;
LISTITEM* pItem;

    if(pMsg->type == TYPE_TOUCHSCREEN) {

#ifdef  USE_FOCUS
        if(pMsg->type == TYPE_TOUCHSCREEN){
            if(!GetState(pLb,LB_FOCUSED)){
                GOLSetFocus((OBJ_HEADER*)pLb);
            }
        }
#endif

        if(pMsg->uiEvent == EVENT_PRESS){

            pos = (pMsg->param2-pLb->scrollY-pLb->hdr.top-LB_INDENT-GOL_EMBOSS_SIZE)/pLb->textHeight;
            pItem = (LISTITEM*)pLb->pItemList;
            while(pos){
                if(pItem == NULL)
                    break;
                if(pItem->pNextItem == NULL)
                    break;
                pItem = (LISTITEM*)pItem->pNextItem;
                pos--;
            }

            if(pLb->pFocusItem != pItem){
                pItem->status |= LB_STS_REDRAW;
                pLb->pFocusItem->status |= LB_STS_REDRAW;
                pLb->pFocusItem = pItem;
                SetState(pLb, LB_DRAW_ITEMS);
            }

        
            LbChangeSel(pLb, pItem);
            SetState(pLb, LB_DRAW_ITEMS);

        }

	}
#endif	

#ifdef  USE_KEYBOARD
    if(pMsg->type == TYPE_KEYBOARD){

        switch(translatedMsg){
            case LB_MSG_SEL:
                if(pLb->pFocusItem != NULL)
                    LbChangeSel(pLb, pLb->pFocusItem);
                    SetState(pLb, LB_DRAW_ITEMS);
                break;

            case LB_MSG_MOVE:
                switch(pMsg->param2){
                    case SCAN_UP_PRESSED:
                        LbSetFocusedItem(pLb,LbGetFocusedItem(pLb)-1);
                        SetState(pLb, LB_DRAW_ITEMS);
                        break;
                    case SCAN_DOWN_PRESSED:
                        LbSetFocusedItem(pLb,LbGetFocusedItem(pLb)+1);
                        SetState(pLb, LB_DRAW_ITEMS);
                        break;
                }
                break;
        }
    }// end of if
#endif	

}

/*********************************************************************
* Function: WORD LbDraw(LISTBOX *pLb)
*
* Output: returns the status of the drawing
*		  0 - not completed
*         1 - done
*
* Overview: draws edit box
*
********************************************************************/
WORD LbDraw(LISTBOX *pLb)
{
typedef enum {
	LB_STATE_START,
	LB_STATE_PANEL,
	LB_STATE_ERASEITEM,
    LB_STATE_ITEMFOCUS,
    LB_STATE_BITMAP,
	LB_STATE_TEXT
} LB_DRAW_STATES;

static LB_DRAW_STATES state = LB_STATE_START;
static LISTITEM* pCurItem;
static SHORT  temp;
        
    switch(state){

/////////////////////////////////////////////////////////////////////
// REMOVE FROM SCREEN
/////////////////////////////////////////////////////////////////////
        case LB_STATE_START:

          	if (GetState(pLb, LB_HIDE)) {
   	   	        SetColor(pLb->hdr.pGolScheme->CommonBkColor);
    	        if(!Bar(pLb->hdr.left,pLb->hdr.top,pLb->hdr.right,pLb->hdr.bottom)) return 0;
    	        return 1;
    	    }    


            if( GetState(pLb,LB_DRAW_FOCUS) ){
                if(pLb->pFocusItem != NULL)
                    ((LISTITEM*)pLb->pFocusItem)->status |= LB_STS_REDRAW;
                SetState(pLb,LB_DRAW_ITEMS);
            }
/////////////////////////////////////////////////////////////////////
// DRAW PANEL
/////////////////////////////////////////////////////////////////////
if(GetState(pLb, LB_DRAW)){
 
            if(GetState(pLb,LB_DISABLED)){
                temp = pLb->hdr.pGolScheme->ColorDisabled;
	        }else{
                temp = pLb->hdr.pGolScheme->Color0;
            }

            GOLPanelDraw(pLb->hdr.left,pLb->hdr.top,pLb->hdr.right,pLb->hdr.bottom,0,
                         temp,
                         pLb->hdr.pGolScheme->EmbossDkColor,
                         pLb->hdr.pGolScheme->EmbossLtColor,
                         NULL,
                         GOL_EMBOSS_SIZE);

            state = LB_STATE_PANEL;

        case LB_STATE_PANEL:

            if(!GOLPanelDrawTsk())
                return 0;

}
/////////////////////////////////////////////////////////////////////
// DRAW ITEMS
/////////////////////////////////////////////////////////////////////
L_LB_DRAW:
            SetClip(CLIP_ENABLE);

            SetClipRgn(pLb->hdr.left+GOL_EMBOSS_SIZE+LB_INDENT,
                       pLb->hdr.top+GOL_EMBOSS_SIZE+LB_INDENT,
                       pLb->hdr.right-GOL_EMBOSS_SIZE-LB_INDENT,
                       pLb->hdr.bottom-GOL_EMBOSS_SIZE-LB_INDENT);

	        SetFont(pLb->hdr.pGolScheme->pFont);

            // Set graphics cursor
            MoveTo(pLb->hdr.left+GOL_EMBOSS_SIZE+LB_INDENT,
                   pLb->hdr.top+GOL_EMBOSS_SIZE+LB_INDENT+pLb->scrollY);

            pCurItem = pLb->pItemList;

/////////////////////////////////////////////////////////////////////
// DRAW CURRENT ITEM
/////////////////////////////////////////////////////////////////////
L_LB_DRAWITEM:
            if( pCurItem == NULL ) {
                state = LB_STATE_START;
                SetClip(CLIP_DISABLE);
                return 1;
            }

/////////////////////////////////////////////////////////////////////
if( GetY() < pLb->hdr.bottom-GOL_EMBOSS_SIZE-LB_INDENT )
if((GetY()+ pLb->textHeight) >= (pLb->hdr.top+GOL_EMBOSS_SIZE+LB_INDENT)){

            if(! GetState(pLb, LB_DRAW))
            if(!(pCurItem->status&LB_STS_REDRAW))
                goto L_LB_NEXTITEM;

            pCurItem->status &= ~LB_STS_REDRAW;

            state = LB_STATE_ERASEITEM;

        case LB_STATE_ERASEITEM:

            if(IsDeviceBusy())
                return 0;

            if( GetState(pLb, LB_DISABLED)){
                SetColor(pLb->hdr.pGolScheme->ColorDisabled);
            }else{
                SetColor(pLb->hdr.pGolScheme->Color0);
                if(pCurItem != NULL)
                if(pCurItem->status&LB_STS_SELECTED){
                    SetColor(pLb->hdr.pGolScheme->Color1);
                }
            }

            if(!Bar(pLb->hdr.left+GOL_EMBOSS_SIZE+LB_INDENT,
                GetY(),
                pLb->hdr.right-GOL_EMBOSS_SIZE-LB_INDENT,
                GetY()+ pLb->textHeight))
                return 0;


            if (!GetState(pLb, LB_CENTER_ALIGN|LB_RIGHT_ALIGN)) {
                MoveTo(pLb->hdr.left+GOL_EMBOSS_SIZE+LB_INDENT, GetY());
            }else{
                temp = GetTextWidth(pCurItem->pText, pLb->hdr.pGolScheme->pFont);
                if(pCurItem->pBitmap != NULL)
                {
                    temp += GetImageWidth(pCurItem->pBitmap)+LB_INDENT;
                }
                if (GetState(pLb, LB_RIGHT_ALIGN)) {
			        MoveTo(pLb->hdr.right-temp-LB_INDENT-GOL_EMBOSS_SIZE, GetY());
                }else{
                    MoveTo((pLb->hdr.left+pLb->hdr.right-temp)>>1, GetY());
                }
            }

            if( GetState(pLb, LB_DISABLED)){
                SetColor(pLb->hdr.pGolScheme->TextColorDisabled);
            }else{
                if(pCurItem->status&LB_STS_SELECTED){
                    SetColor(pLb->hdr.pGolScheme->TextColor1);
                }else{
                    SetColor(pLb->hdr.pGolScheme->TextColor0);
                }
            }

            state = LB_STATE_BITMAP;

        case LB_STATE_BITMAP:
            if(pCurItem->pBitmap != NULL)
            {

                if(!PutImage(GetX(),
                         GetY()+((pLb->textHeight-GetImageHeight(pCurItem->pBitmap))>>1),
                         pCurItem->pBitmap,
                         1))
                         return 0;

                MoveRel(GetImageWidth(pCurItem->pBitmap)+LB_INDENT,0);
            }
            state = LB_STATE_TEXT;

        case LB_STATE_TEXT:
            if(!OutText(pCurItem->pText))
                return 0;
}
/////////////////////////////////////////////////////////////////////

L_LB_NEXTITEM:
            state = LB_STATE_ITEMFOCUS;

        case LB_STATE_ITEMFOCUS:

            if(pLb->pFocusItem == pCurItem){
                if(IsDeviceBusy())
                    return 0;

                if( GetState(pLb,LB_FOCUSED) ){
                    SetColor(pLb->hdr.pGolScheme->TextColor1);
                }else{
                    SetColor(pLb->hdr.pGolScheme->TextColor0);
                }
          
                SetLineType(FOCUS_LINE);
                temp = GetY();
                if(!Rectangle(pLb->hdr.left+GOL_EMBOSS_SIZE+LB_INDENT,
                          GetY(),
                          pLb->hdr.right-GOL_EMBOSS_SIZE-LB_INDENT,
                          GetY()+pLb->textHeight-1))
                          return 0;
                MoveTo(0,temp);
                SetLineType(SOLID_LINE);

                // Scroll if needed
                if(GetY() < (pLb->hdr.top+GOL_EMBOSS_SIZE+LB_INDENT)){
                    pLb->scrollY += (pLb->hdr.top+GOL_EMBOSS_SIZE+LB_INDENT)-GetY();
                    SetState(pLb, LB_DRAW);
                    goto L_LB_DRAW;
                }
                if((GetY()+pLb->textHeight) > (pLb->hdr.bottom-GOL_EMBOSS_SIZE-LB_INDENT)){
                    pLb->scrollY += pLb->hdr.bottom-GetY()-pLb->textHeight-GOL_EMBOSS_SIZE-LB_INDENT;                 
                    SetState(pLb, LB_DRAW);
                    goto L_LB_DRAW;
                }
            }

            pCurItem = (LISTITEM*)pCurItem->pNextItem;
            MoveRel(0,pLb->textHeight);

            goto L_LB_DRAWITEM;

    } // end of switch
    return 1;

}

#endif // USE_LISTBOX
