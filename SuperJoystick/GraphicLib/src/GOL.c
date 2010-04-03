/*****************************************************************************
 *  Module for Microchip Graphics Library 
 *  GOL Layer 
 *****************************************************************************
 * FileName:        GOL.c
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
 * Anton Alkhimenok and
 * Paolo A. Tamayo
 *                      11/12/07    Version 1.0 release
 * PAT					06/29/09	Added multi-line support for Buttons.
 *****************************************************************************/
#include "Graphics\Graphics.h"

#ifdef USE_GOL

// Pointer to the current linked list of objects displayed and receiving messages
OBJ_HEADER  *_pGolObjects        = NULL;

// Pointer to the default GOL scheme (created in GOLInit())
GOL_SCHEME  *_pDefaultGolScheme  = NULL;

// Pointer to the object receiving keyboard input
OBJ_HEADER  *_pObjectFocused     = NULL;

#ifdef USE_FOCUS

/*********************************************************************
* Function: OBJ_HEADER *GOLGetFocusPrev()
*
* Overview: This function returns the pointer to the previous object
*		 	in the active linked list which is able to receive 
*		 	keyboard input.
*
* PreCondition: none
*
* Input: none
*
* Output: This returns the pointer of the previous object in the 
*		  active list capable of receiving keyboard input. If 
*		  there is no object capable of receiving keyboard 
*		  inputs (i.e. none can be focused) NULL is returned.
*
* Side Effects: none
*
********************************************************************/
OBJ_HEADER *GOLGetFocusPrev(void){
OBJ_HEADER *pPrevObj;
OBJ_HEADER *pCurObj;
OBJ_HEADER *pFocusedObj;

    if(_pGolObjects == NULL)
        return NULL;

    if(_pObjectFocused == NULL){
        pFocusedObj = _pGolObjects;
    }else{
        pFocusedObj = _pObjectFocused;
    }
  
    pPrevObj = NULL;
    pCurObj = pFocusedObj; 

    while(1){
        if(GOLCanBeFocused(pCurObj))
            pPrevObj = pCurObj;

        if(pCurObj->pNxtObj == NULL)
        if(_pGolObjects == pFocusedObj)
            return pPrevObj;    

        if(pCurObj->pNxtObj == pFocusedObj)
            return pPrevObj;

        pCurObj = (OBJ_HEADER*)pCurObj->pNxtObj;

        if(pCurObj == NULL)
            pCurObj = _pGolObjects;
        
    }
}
/*********************************************************************
* Function: OBJ_HEADER *GOLGetFocusNext()
*
* Overview: This function returns the pointer to the next object
*		 	in the active linked list which is able to receive 
*		 	keyboard input.
*
* PreCondition: none
*
* Input: none
*
* Output: This returns the pointer of the next object in the 
*		  active list capable of receiving keyboard input. If 
*		  there is no object capable of receiving keyboard 
*		  inputs (i.e. none can be focused) NULL is returned.
*
* Side Effects: none
*
********************************************************************/
OBJ_HEADER *GOLGetFocusNext(void){
OBJ_HEADER *pNextObj;

    if(_pObjectFocused == NULL){
        pNextObj = _pGolObjects;
    }else{
        pNextObj = _pObjectFocused;
    }

    do{
        pNextObj = (OBJ_HEADER*)pNextObj->pNxtObj;

        if(pNextObj == NULL)
            pNextObj = _pGolObjects;

        if(GOLCanBeFocused(pNextObj))
            break;

    }while(pNextObj != _pObjectFocused);
         
    
    return pNextObj;
}

/*********************************************************************
* Function: void GOLSetFocus(OBJ_HEADER* object)
*
* PreCondition: none
*
* Input: pointer to the object to be focused
*
* Output: 
*
* Side Effects: none
*
* Overview: moves keyboard focus to the object
*
* Note: none
*
********************************************************************/
void GOLSetFocus(OBJ_HEADER* object){

	if(!GOLCanBeFocused(object)) 
		return;
		
    if(_pObjectFocused != NULL){
        ClrState(_pObjectFocused, FOCUSED);
        SetState(_pObjectFocused, DRAW_FOCUS);
    }

     SetState(object, DRAW_FOCUS|FOCUSED);

    _pObjectFocused = object;
}

/*********************************************************************
* Function: WORD GOLCanBeFocused(OBJ_HEADER* object)
*
* PreCondition: none
*
* Input: pointer to the object 
*
* Output: non-zero if the object supports keyboard focus, zero if not
*
* Side Effects: none
*
* Overview: checks if object support keyboard focus
*
* Note: none
*
********************************************************************/
WORD GOLCanBeFocused(OBJ_HEADER* object){

    if((object->type == OBJ_BUTTON) || (object->type == OBJ_CHECKBOX) ||
        (object->type == OBJ_RADIOBUTTON) || (object->type == OBJ_LISTBOX) ||
        (object->type == OBJ_SLIDER)) 
    {

        if(!GetState(object,DISABLED))            
            return 1;
    }
    return 0;
}

#endif

/*********************************************************************
* Function: GOL_SCHEME *GOLCreateScheme(void)
*
* PreCondition: none
*
* Input: none
*
* Output: pointer to scheme object
*
* Side Effects: none
*
* Overview: creates a color scheme object and assign default colors
*
* Note: none
*
********************************************************************/
GOL_SCHEME *GOLCreateScheme(void)
{
	GOL_SCHEME *pTemp;
	pTemp = (GOL_SCHEME*) malloc(sizeof(GOL_SCHEME));
	if (pTemp != NULL)
	{
		pTemp->EmbossDkColor 		= EMBOSSDKCOLORDEFAULT;
		pTemp->EmbossLtColor   		= EMBOSSLTCOLORDEFAULT;
		pTemp->TextColor0			= TEXTCOLOR0DEFAULT;
		pTemp->TextColor1	  		= TEXTCOLOR1DEFAULT;
		pTemp->TextColorDisabled	= TEXTCOLORDISABLEDDEFAULT;
		pTemp->Color0				= COLOR0DEFAULT; 
		pTemp->Color1				= COLOR1DEFAULT; 
        pTemp->ColorDisabled		= COLORDISABLEDDEFAULT; 
		pTemp->CommonBkColor 		= COMMONBACKGROUNDCOLORDEFAULT;
		pTemp->pFont				= (void*)&FONTDEFAULT;		
	}
	return pTemp;
}	

/*********************************************************************
* Function: void GOLInit()
*
* PreCondition: none
*
* Input: none
*
* Output: none
*
* Side Effects: none
*
* Overview: initializes GOL
*
* Note: none
*
********************************************************************/
void  GOLInit(){
	// Initialize display
    InitGraph();
	// Initialize the default GOL scheme
	_pDefaultGolScheme  = GOLCreateScheme();
}

/*********************************************************************
* Function: void GOLFree()
*
* PreCondition: none
*
* Input: none
*
* Output: none
*
* Side Effects: none
*
* Overview: frees memory of all objects in the current linked list
*           and starts a new linked list. This function must be 
*           called only inside the GOLDrawCallback()function when 
*           using GOLDraw() and GOLMsg() to manage rendering and 
*           message processing.
*
* Note: drawing and messaging must be suspended
*
********************************************************************/
void GOLFree(){
OBJ_HEADER * pNextObj;
OBJ_HEADER * pCurrentObj;


    pCurrentObj = _pGolObjects;
    while(pCurrentObj != NULL){
        pNextObj = (OBJ_HEADER*)pCurrentObj->pNxtObj;

#ifdef USE_LISTBOX
        if(pCurrentObj->type == OBJ_LISTBOX)
            LbDelItemsList((LISTBOX*)pCurrentObj);
#endif

#ifdef USE_GRID
        if(pCurrentObj->type == OBJ_GRID)
            GridFreeItems((GRID*)pCurrentObj);
#endif

#ifdef USE_CHART
        if(pCurrentObj->type == OBJ_CHART)
            ChRemoveDataSeries((CHART*)pCurrentObj, 0);
#endif

#ifdef USE_TEXTENTRY
        if(pCurrentObj->type == OBJ_TEXTENTRY)
            TeDelKeyMembers((TEXTENTRY*)pCurrentObj);
#endif

        free(pCurrentObj);
        pCurrentObj = pNextObj;
    }

    GOLNewList();
}
/*********************************************************************
* Function: BOOL GOLDeleteObject(OBJ_HEADER * object)
*
* PreCondition: none
*
* Input: pointer to the object
*
* Output: none
*
* Side Effects: none
*
* Overview: deletes an object to the linked list objects for the current screen.
*
* Note: none
*
********************************************************************/
BOOL  GOLDeleteObject(OBJ_HEADER * object)
{
    if(!_pGolObjects)
        return FALSE;

    if(object == _pGolObjects)
    {
        _pGolObjects = (OBJ_HEADER*)object->pNxtObj;        
    }else
    {
        OBJ_HEADER  *curr;
        OBJ_HEADER  *prev;

        curr = (OBJ_HEADER*)_pGolObjects->pNxtObj;
        prev = (OBJ_HEADER*)_pGolObjects;

        while(curr)
        {
            if(curr == object)
                break;

            prev = (OBJ_HEADER*)curr;
            curr = (OBJ_HEADER*)curr->pNxtObj;
        }

        if(!curr)
            return FALSE;

        prev->pNxtObj = curr->pNxtObj;
    }

#ifdef USE_LISTBOX
    if(object->type == OBJ_LISTBOX)
        LbDelItemsList((LISTBOX*)object);
#endif

#ifdef USE_GRID
    if(object->type == OBJ_GRID)
        GridFreeItems((GRID*)object);
#endif

    free(object);

    return TRUE;
}
/*********************************************************************
* Function: BOOL GOLDeleteObject(OBJ_HEADER * object)
*
* PreCondition: none
*
* Input: pointer to the object
*
* Output: none
*
* Side Effects: none
*
* Overview: deletes an object to the linked list objects for the current screen.
*
* Note: none
*
********************************************************************/
BOOL  GOLDeleteObjectByID(WORD ID)
{
    OBJ_HEADER * object;

    object = GOLFindObject(ID);

    if(!object)
        return FALSE;

    return GOLDeleteObject(object);

}
/*********************************************************************
* Function: OBJ_HEADER* GOLFindObject(WORD ID)
*
* PreCondition: none
*
* Input: object ID
*
* Output: pointer to the object
*
* Side Effects: none
*
* Overview: searches for the object by its ID in the current objects linked list,
*           returns NULL if the object is not found
*
* Note: none
*
********************************************************************/
OBJ_HEADER* GOLFindObject(WORD ID){
OBJ_HEADER * pNextObj;

    pNextObj = _pGolObjects;
    while(pNextObj != NULL){
        if(pNextObj->ID == ID){
            return pNextObj;
        }
        pNextObj = (OBJ_HEADER*)pNextObj->pNxtObj;            
    }
    return NULL;
}

/*********************************************************************
* Function: void GOLAddObject(OBJ_HEADER * object)
*
* PreCondition: none
*
* Input: pointer to the object
*
* Output: none
*
* Side Effects: none
*
* Overview: adds an object to the linked list objects for the current screen.
*           Object will be drawn and will receive messages.
*
* Note: none
*
********************************************************************/
void  GOLAddObject(OBJ_HEADER * object){
OBJ_HEADER * pNextObj;

    if(_pGolObjects ==  NULL){
        _pGolObjects = object;
    }else{
        pNextObj = _pGolObjects;
        while(pNextObj->pNxtObj != NULL){
            pNextObj = (OBJ_HEADER*)pNextObj->pNxtObj;            
        }
        pNextObj->pNxtObj = (void*)object;
    }
    object->pNxtObj = NULL;
}
/*********************************************************************
* Function: WORD GOLDraw()
*
* PreCondition: none
*
* Input: none
*
* Output: non-zero if drawing is complete
*
* Side Effects: none
*
* Overview: redraws objects in the current linked list
*
* Note: none
*
********************************************************************/
WORD GOLDraw(){
static OBJ_HEADER *pCurrentObj = NULL;
SHORT done;

    if(pCurrentObj == NULL){
        if(GOLDrawCallback()){
            // It's last object jump to head
            pCurrentObj = _pGolObjects;
        }else{
            return 0;  // drawing is not done
        }
    }

    done = 0;
    while(pCurrentObj != NULL){
        
        if(IsObjUpdated(pCurrentObj)){

            switch(pCurrentObj->type){
				#if defined (USE_BUTTON) || defined (USE_BUTTON_MULTI_LINE)                
	            case OBJ_BUTTON:
                    done = BtnDraw((BUTTON*)pCurrentObj);
                    break;
                #endif
                #ifdef USE_WINDOW
	            case OBJ_WINDOW:
                    done = WndDraw((WINDOW*)pCurrentObj);
                    break;
                #endif
                #ifdef USE_CHECKBOX
	            case OBJ_CHECKBOX:
                    done = CbDraw((CHECKBOX*)pCurrentObj);
                    break;
                #endif
                #ifdef USE_RADIOBUTTON
	            case OBJ_RADIOBUTTON:
                    done = RbDraw((RADIOBUTTON*)pCurrentObj);
                    break;
                #endif
                #ifdef USE_EDITBOX
	            case OBJ_EDITBOX:
                    done = EbDraw((EDITBOX*)pCurrentObj);
                    break;
                #endif
                #ifdef USE_LISTBOX
	            case OBJ_LISTBOX:
                    done = LbDraw((LISTBOX*)pCurrentObj);
                    break;
                #endif
                #ifdef USE_SLIDER
	            case OBJ_SLIDER:
                    done = SldDraw((SLIDER*)pCurrentObj);
                    break;
                #endif
                #ifdef USE_PROGRESSBAR
	            case OBJ_PROGRESSBAR:
                    done = PbDraw((PROGRESSBAR*)pCurrentObj);
                    break;
                #endif
                #ifdef USE_STATICTEXT
	            case OBJ_STATICTEXT:
                    done = StDraw((STATICTEXT*)pCurrentObj);
                    break;
                #endif
                #ifdef USE_DIGITALMETER
	            case OBJ_DIGITALMETER:
                    done = DmDraw((DIGITALMETER*)pCurrentObj);
                    break;
                #endif
                #ifdef USE_PICTURE
	            case OBJ_PICTURE:
                    done = PictDraw((PICTURE*)pCurrentObj);
                    break;
                #endif
                #ifdef USE_GROUPBOX
	            case OBJ_GROUPBOX:
                    done = GbDraw((GROUPBOX*)pCurrentObj);
                    break;
                #endif
                #ifdef USE_ROUNDDIAL
	            case OBJ_ROUNDDIAL:
                    done = RdiaDraw((ROUNDDIAL*)pCurrentObj);
                    break;
                #endif
                #ifdef USE_METER
	            case OBJ_METER:
                    done = MtrDraw((METER*)pCurrentObj);
                    break;
                #endif
                #ifdef USE_CUSTOM
	            case OBJ_CUSTOM:
                    done = CcDraw((CUSTOM*)pCurrentObj);
                    break;
                #endif
                #ifdef USE_GRID
                case OBJ_GRID:
                    done = GridDraw( (GRID *)pCurrentObj );
                    break;
                #endif
                #ifdef USE_CHART
                case OBJ_CHART:
                    done = ChDraw( (CHART *)pCurrentObj );
                    break;
                #endif
 				#ifdef USE_TEXTENTRY
                case OBJ_TEXTENTRY:
                    done = TeDraw( (TEXTENTRY *)pCurrentObj );
                    break;
                #endif
                
                default:
                    break;
            }
            if(done){
                GOLDrawComplete(pCurrentObj);
            }else{
                return 0; // drawing is not done
            }
        }
        pCurrentObj = (OBJ_HEADER*)pCurrentObj->pNxtObj;
    }
    return 1;   // drawing is completed
}

/*********************************************************************
* Function: void GOLRedrawRec(SHORT left, SHORT top, SHORT right, SHORT bottom)
*
* PreCondition: none
*
* Input: left,top,right,bottom - rectangle borders
*
* Output: none
*
* Side Effects: none
*
* Overview: marks objects with parts in the rectangle to be redrawn
*
* Note: none
*
********************************************************************/
void  GOLRedrawRec(SHORT left, SHORT top, SHORT right, SHORT bottom){
OBJ_HEADER *pCurrentObj;

    pCurrentObj = _pGolObjects;

    while(pCurrentObj != NULL){
        
        if( !( (pCurrentObj->left > right) ||
             (pCurrentObj->right < left) ||       
             (pCurrentObj->top > bottom) ||
             (pCurrentObj->bottom < top) ) )

		if( ( (pCurrentObj->left >= left)&&
              (pCurrentObj->left <= right) ) ||

            ( (pCurrentObj->right >= left)&&
              (pCurrentObj->right <= right) ) ||

            ( (pCurrentObj->top >= top)&&
              (pCurrentObj->top <= bottom) )||

            ( (pCurrentObj->bottom >= top)&&
              (pCurrentObj->bottom <= bottom) ) ){

                GOLRedraw(pCurrentObj);

        }

        pCurrentObj = (OBJ_HEADER*)pCurrentObj->pNxtObj;            

    }//end of while
}

/*********************************************************************
* Function: void GOLMsg(GOL_MSG *pMsg)
*
* PreCondition: none
*
* Input: pointer to the message
*
* Output: none
*
* Side Effects: none
*
* Overview: processes message for all objects in the liked list
*
* Note: none
*
********************************************************************/
void  GOLMsg(GOL_MSG *pMsg){
OBJ_HEADER *pCurrentObj;
WORD   translatedMsg;

    if(pMsg->uiEvent == EVENT_INVALID)
        return;

    pCurrentObj = _pGolObjects;

    while(pCurrentObj != NULL){
        switch(pCurrentObj->type){
			#if defined (USE_BUTTON) || defined (USE_BUTTON_MULTI_LINE)            
	        case OBJ_BUTTON:
                translatedMsg = BtnTranslateMsg((BUTTON*)pCurrentObj, pMsg);
                if(translatedMsg == OBJ_MSG_INVALID)
                    break;
                if(GOLMsgCallback(translatedMsg,pCurrentObj,pMsg))
                    BtnMsgDefault(translatedMsg,(BUTTON*)pCurrentObj, pMsg);
                break;
            #endif
            #ifdef USE_WINDOW
	        case OBJ_WINDOW:
                translatedMsg = WndTranslateMsg((WINDOW*)pCurrentObj, pMsg);
                if(translatedMsg == OBJ_MSG_INVALID)
                    break;
                GOLMsgCallback(translatedMsg,pCurrentObj,pMsg);
                break;
            #endif
            #ifdef USE_CHECKBOX
	        case OBJ_CHECKBOX:
                translatedMsg = CbTranslateMsg((CHECKBOX*)pCurrentObj, pMsg);
                if(translatedMsg == OBJ_MSG_INVALID)
                    break;
                if(GOLMsgCallback(translatedMsg,pCurrentObj,pMsg))
                    CbMsgDefault(translatedMsg,(CHECKBOX*)pCurrentObj, pMsg);
                break;
            #endif
            #ifdef USE_RADIOBUTTON
	        case OBJ_RADIOBUTTON:
                translatedMsg = RbTranslateMsg((RADIOBUTTON*)pCurrentObj, pMsg);
                if(translatedMsg == OBJ_MSG_INVALID)
                    break;
                if(GOLMsgCallback(translatedMsg,pCurrentObj,pMsg))
                    RbMsgDefault(translatedMsg,(RADIOBUTTON*)pCurrentObj, pMsg);
                break;
            #endif
            #ifdef USE_EDITBOX
	        case OBJ_EDITBOX:
                translatedMsg = EbTranslateMsg((EDITBOX*)pCurrentObj, pMsg);
                if(translatedMsg == OBJ_MSG_INVALID)
                    break;
                if(GOLMsgCallback(translatedMsg,pCurrentObj,pMsg))
                    EbMsgDefault(translatedMsg,(EDITBOX*)pCurrentObj, pMsg);
                break;
            #endif
            #ifdef USE_LISTBOX
	        case OBJ_LISTBOX:
                translatedMsg = LbTranslateMsg((LISTBOX*)pCurrentObj, pMsg);
                if(translatedMsg == OBJ_MSG_INVALID)
                    break;
                if(GOLMsgCallback(translatedMsg,pCurrentObj,pMsg))
                    LbMsgDefault(translatedMsg,(LISTBOX*)pCurrentObj, pMsg);
                break;
            #endif
            #ifdef USE_SLIDER
	        case OBJ_SLIDER:
                translatedMsg = SldTranslateMsg((SLIDER*)pCurrentObj, pMsg);
                if(translatedMsg == OBJ_MSG_INVALID)
                    break;
                if(GOLMsgCallback(translatedMsg,pCurrentObj,pMsg))
                    SldMsgDefault(translatedMsg,(SLIDER*)pCurrentObj, pMsg);
                break;
            #endif
            #ifdef USE_GROUPBOX
	        case OBJ_GROUPBOX:
                translatedMsg = GbTranslateMsg((GROUPBOX*)pCurrentObj, pMsg);
                if(translatedMsg == OBJ_MSG_INVALID)
                    break;
                GOLMsgCallback(translatedMsg,pCurrentObj,pMsg);
                break;
            #endif
            #ifdef USE_PROGRESSBAR
	        case OBJ_PROGRESSBAR:
                break;
            #endif
            #ifdef USE_STATICTEXT
	        case OBJ_STATICTEXT:
                translatedMsg = StTranslateMsg((STATICTEXT*)pCurrentObj, pMsg);
                if(translatedMsg == OBJ_MSG_INVALID)
                    break;
                GOLMsgCallback(translatedMsg,pCurrentObj,pMsg);
                break;
            #endif
            #ifdef USE_DIGITALMETER
	        case OBJ_DIGITALMETER:
                translatedMsg = DmTranslateMsg((DIGITALMETER*)pCurrentObj, pMsg);
                if(translatedMsg == OBJ_MSG_INVALID)
                    break;
                GOLMsgCallback(translatedMsg,pCurrentObj,pMsg);
                break;
            #endif
            #ifdef USE_PICTURE
	        case OBJ_PICTURE:
                translatedMsg = PictTranslateMsg((PICTURE*)pCurrentObj, pMsg);
                if(translatedMsg == OBJ_MSG_INVALID)
                    break;
                GOLMsgCallback(translatedMsg,pCurrentObj,pMsg);
                break;
            #endif
           
            #ifdef USE_ROUNDDIAL
            case OBJ_ROUNDDIAL:
                translatedMsg = RdiaTranslateMsg((ROUNDDIAL*)pCurrentObj, pMsg);
                if(translatedMsg == OBJ_MSG_INVALID)
                    break;
                if(GOLMsgCallback(translatedMsg,pCurrentObj,pMsg))
                    RdiaMsgDefault(translatedMsg,(ROUNDDIAL*)pCurrentObj, pMsg);
                break;
            #endif            
            
            #ifdef USE_METER
            case OBJ_METER:
                translatedMsg = MtrTranslateMsg((METER*)pCurrentObj, pMsg);
                if(translatedMsg == OBJ_MSG_INVALID)
                    break;
                if(GOLMsgCallback(translatedMsg,pCurrentObj,pMsg))
                    MtrMsgDefault(translatedMsg,(METER*)pCurrentObj, pMsg);
                break;
            #endif            

            #ifdef USE_CUSTOM
	        case OBJ_CUSTOM:
                translatedMsg = CcTranslateMsg((CUSTOM*)pCurrentObj, pMsg);
                if(translatedMsg == OBJ_MSG_INVALID)
                    break;
                if(GOLMsgCallback(translatedMsg,pCurrentObj,pMsg))
                    CcMsgDefault((CUSTOM*)pCurrentObj,pMsg);
                break;
            #endif

            #ifdef USE_GRID
	        case OBJ_GRID:
                translatedMsg = GridTranslateMsg((GRID*)pCurrentObj, pMsg);
                if(translatedMsg == OBJ_MSG_INVALID)
                    break;
                if(GOLMsgCallback(translatedMsg,pCurrentObj,pMsg))
                    GridMsgDefault( translatedMsg, (GRID*)pCurrentObj, pMsg );
                break;
            #endif

            #ifdef USE_CHART
	        case OBJ_CHART:
                translatedMsg = ChTranslateMsg((CHART*)pCurrentObj, pMsg);
                if(translatedMsg == OBJ_MSG_INVALID)
                    break;
                GOLMsgCallback(translatedMsg,pCurrentObj,pMsg);
                break;
            #endif

            #ifdef USE_TEXTENTRY
	        case OBJ_TEXTENTRY:
                translatedMsg = TeTranslateMsg((TEXTENTRY*)pCurrentObj, pMsg);
                if(translatedMsg == OBJ_MSG_INVALID)
                    break;
                if(GOLMsgCallback(translatedMsg,pCurrentObj,pMsg))
                    TeMsgDefault(translatedMsg,(TEXTENTRY*)pCurrentObj, pMsg);
                break;
            #endif
            
            default:
                break;
        }
        pCurrentObj = (OBJ_HEADER*)pCurrentObj->pNxtObj;
    }
}

/*********************************************************************
* Variables for rounded panel drawing. Used by GOLRndPanelDraw and GOLRndPanelDrawTsk
********************************************************************/
SHORT _rpnlX1,				// Center x position of upper left corner
      _rpnlY1,				// Center y position of upper left corner
      _rpnlX2,				// Center x position of lower right corner
      _rpnlY2,				// Center y position of lower right corner
      _rpnlR;				// radius
WORD  _rpnlFaceColor,		// face color
      _rpnlEmbossLtColor,	// emboss light color
      _rpnlEmbossDkColor,	// emboss dark color
	  _rpnlEmbossSize;      // emboss size 
	  
void* _pRpnlBitmap = NULL;      

/*********************************************************************
* Function: WORD GOLPanelDrawTsk(void) 
*
* PreCondition: parameters must be set with
*               GOLRndPanelDraw(x,y,radius,width,height,faceClr,embossLtClr,
*								embossDkClr,pBitmap,embossSize)
*
* Input: None
*
* Output: Output: non-zero if drawing is completed
*
* Overview: draws a rounded panel on screen. Must be called repeatedly. Drawing is done
*           when it returns non-zero. 
*
* Note: none
*
********************************************************************/
WORD GOLPanelDrawTsk(void) {

//#define SIN45 46341

#ifndef USE_NONBLOCKING_CONFIG

	WORD counter;

	if (_rpnlR) {
		// draw upper left portion of the embossed area
		SetColor(_rpnlEmbossLtColor);
		Arc(_rpnlX1, _rpnlY1, _rpnlX2, _rpnlY2, _rpnlR-_rpnlEmbossSize, _rpnlR, 0xE1);	
		// draw lower right portion of the embossed area
		SetColor(_rpnlEmbossDkColor);
		Arc(_rpnlX1, _rpnlY1, _rpnlX2, _rpnlY2, _rpnlR-_rpnlEmbossSize, _rpnlR, 0x1E);	
	}
	else {
		// object is rectangular panel draw the embossed areas
		counter = 1;
	    SetColor(_rpnlEmbossLtColor);
    	while(counter < _rpnlEmbossSize){
   			Bar( _rpnlX1+counter, _rpnlY1+counter, _rpnlX2-counter, _rpnlY1+counter); 	// draw top
        	Bar( _rpnlX1+counter, _rpnlY1+counter, _rpnlX1+counter, _rpnlY2-counter);	// draw left
           	counter++;
       	}
       	counter = 1;
	    SetColor(_rpnlEmbossDkColor);
    	while(counter < _rpnlEmbossSize){
        	Bar( _rpnlX1+counter, _rpnlY2-counter, _rpnlX2-counter, _rpnlY2-counter);	// draw bottom
        	Bar( _rpnlX2-counter, _rpnlY1+counter, _rpnlX2-counter, _rpnlY2-counter);	// draw right	
           	counter++;
       	}
	}

    // draw the face color
    SetColor(_rpnlFaceColor);
	if (_rpnlR) 
	    FillBevel(_rpnlX1, _rpnlY1, _rpnlX2, _rpnlY2, _rpnlR-_rpnlEmbossSize);
	else    
	    Bar(_rpnlX1+_rpnlEmbossSize, _rpnlY1+_rpnlEmbossSize, _rpnlX2-_rpnlEmbossSize, _rpnlY2-_rpnlEmbossSize);	     

#if (COLOR_DEPTH == 1)

	if (_rpnlFaceColor == BLACK) {
		SetColor(WHITE);
		if (_rpnlR) 
   			Bevel(_rpnlX1, _rpnlY1, _rpnlX2, _rpnlY2, _rpnlR-(_rpnlEmbossSize-1));	
   		else	
   			Bevel(_rpnlX1+(_rpnlEmbossSize-1), _rpnlY1+(_rpnlEmbossSize-1), 
   				  _rpnlX2-(_rpnlEmbossSize-1), _rpnlY2-(_rpnlEmbossSize-1), 0);	
	}
#endif

	// draw bitmap
	if(_pRpnlBitmap != NULL) {
		
		PutImage(((_rpnlX2+_rpnlX1)-(GetImageWidth((void*)_pRpnlBitmap))>>1)+1, 
				 ((_rpnlY2+_rpnlY1)-(GetImageHeight((void*)_pRpnlBitmap))>>1)+1,
				 _pRpnlBitmap, IMAGE_NORMAL);

    }    
	// check if we need to draw the frame
	if ((_pRpnlBitmap == NULL) || (((_rpnlX2-_rpnlX1+_rpnlR)>=GetImageWidth((void*)_pRpnlBitmap)) &&
								   ((_rpnlY2-_rpnlY1+_rpnlR)>=GetImageHeight((void*)_pRpnlBitmap)))) {
		// draw the outline 
    	SetColor(_rpnlEmbossDkColor);
    	Bevel(_rpnlX1, _rpnlY1, _rpnlX2, _rpnlY2, _rpnlR);
	}			 
    return 1;

#else

typedef enum {
BEGIN,
ARC1,
DRAW_EMBOSS1,
DRAW_EMBOSS2,
DRAW_EMBOSS3,
DRAW_EMBOSS4,
DRAW_FACECOLOR,
#if (COLOR_DEPTH == 1)
DRAW_INNERFRAME,
#endif
DRAW_FRAME,
DRAW_IMAGE,
} ROUND_PANEL_DRAW_STATES;

static ROUND_PANEL_DRAW_STATES state = BEGIN;
static WORD counter;

while(1){
    if(IsDeviceBusy())
        return 0;
    switch(state){
        case BEGIN:      
			if (_rpnlR) {
				// draw upper left portion of the embossed area
				SetColor(_rpnlEmbossLtColor);
				if (!Arc(_rpnlX1, _rpnlY1, _rpnlX2, _rpnlY2, _rpnlR-_rpnlEmbossSize, _rpnlR, 0xE1))	
					return 0;
				state = ARC1;
	        } 
	        else {
        		state = DRAW_EMBOSS1;
        		counter = 1;
        		goto rnd_panel_draw_emboss;
        	}

        case ARC1:      
			// draw upper left portion of the embossed area
			SetColor(_rpnlEmbossDkColor);
			if (!Arc(_rpnlX1, _rpnlY1, _rpnlX2, _rpnlY2, _rpnlR-_rpnlEmbossSize, _rpnlR, 0x1E))
				return 0;	
        	state = DRAW_FACECOLOR;
        	goto rnd_panel_draw_facecolor;

		// now draw the upper portion of the embossed area
        case DRAW_EMBOSS1:
rnd_panel_draw_emboss:        
	    	SetColor(_rpnlEmbossLtColor);
            while(counter < _rpnlEmbossSize){
	       	    // draw top        
				if(!Bar( _rpnlX1+counter, _rpnlY1+counter,  \
				     _rpnlX2-counter, _rpnlY1+counter))
                {
				    return 0;
				}

              	counter++;
           	}
            counter = 1;
           	state = DRAW_EMBOSS2;
           	break;

		case DRAW_EMBOSS2:
           	while(counter < _rpnlEmbossSize){
                // draw left   	
	        	if(!Bar( _rpnlX1+counter, _rpnlY1+counter,  \
	        	     _rpnlX1+counter, _rpnlY2-counter))	
                {
				    return 0;
				}
				counter++;
           	}
           	counter = 1;
           	state = DRAW_EMBOSS3;
           	break;

		// now draw the lower portion of the embossed area
		case DRAW_EMBOSS3:
		    SetColor(_rpnlEmbossDkColor);
	        while(counter < _rpnlEmbossSize){
       	        // draw bottom    
		       	if(!Bar( _rpnlX1+counter, _rpnlY2-counter,   \
		       	     _rpnlX2-counter, _rpnlY2-counter))
                {
				    return 0;
				}
				counter++;
           	}
           	counter = 1;
           	state = DRAW_EMBOSS4;
           	break;

		case DRAW_EMBOSS4:
			while(counter < _rpnlEmbossSize){
                // draw right	   	
	        	if(!Bar( _rpnlX2-counter, _rpnlY1+counter,  \
	        		 _rpnlX2-counter, _rpnlY2-counter))
                {
				    return 0;
				}
				counter++;
			}
            state = DRAW_FACECOLOR;
            break;

		// draw the face color 
		case DRAW_FACECOLOR:
rnd_panel_draw_facecolor:		

		    SetColor(_rpnlFaceColor);
			if (_rpnlR) {
			    if (!FillBevel(_rpnlX1, _rpnlY1, _rpnlX2, _rpnlY2, _rpnlR-_rpnlEmbossSize))
			    	return 0;
			}
			else  {  
			    if(!Bar(_rpnlX1+_rpnlEmbossSize, _rpnlY1+_rpnlEmbossSize,    \
			    	_rpnlX2-_rpnlEmbossSize, _rpnlY2-_rpnlEmbossSize))
                {
				    return 0;
				}			}
            state = DRAW_IMAGE;
            break;
            
		case DRAW_IMAGE:            
			if(_pRpnlBitmap != NULL) {
				
				if(!PutImage(((_rpnlX2+_rpnlX1- GetImageWidth((void*)_pRpnlBitmap))>>1)+1, 
						 ((_rpnlY2+_rpnlY1-GetImageHeight((void*)_pRpnlBitmap))>>1)+1,
						 _pRpnlBitmap, IMAGE_NORMAL))
                {
				    return 0;
				}
		    }
			#if (COLOR_DEPTH == 1)
       	    	state = DRAW_INNERFRAME;
           		break;
           	#else	
			    state = DRAW_FRAME;
       	    #endif
		    break;
		    
		#if (COLOR_DEPTH == 1)
		case DRAW_INNERFRAME:
   			if (_rpnlFaceColor == BLACK) {
   				SetColor(WHITE);
				if (_rpnlR) 
	    			if(!Bevel(_rpnlX1, _rpnlY1, _rpnlX2, _rpnlY2, _rpnlR-(_rpnlEmbossSize-1)))
                    {
				        return 0;
				    }
				else if(!Bevel(_rpnlX1+(_rpnlEmbossSize-1), _rpnlY1+(_rpnlEmbossSize-1),
    					  _rpnlX2-(_rpnlEmbossSize-1), _rpnlY2-(_rpnlEmbossSize-1), 0))	
                    {
				        return 0;
				    }
	    			
    		}
            state = DRAW_FRAME;
            break;
		#endif

		case DRAW_FRAME:
			// check if we need to draw the frame
			if ((_pRpnlBitmap == NULL) || (((_rpnlX2-_rpnlX1+_rpnlR)>=GetImageWidth((void*)_pRpnlBitmap)) &&
										   ((_rpnlY2-_rpnlY1+_rpnlR)>=GetImageHeight((void*)_pRpnlBitmap)))) {
				// draw the outline frame
				#if (COLOR_DEPTH == 1)
			    	SetColor(WHITE);
			    #else	
			    	SetColor(_rpnlEmbossDkColor);
			    #endif
			    if(!Bevel(_rpnlX1, _rpnlY1, _rpnlX2, _rpnlY2, _rpnlR))
			    {
			        return 0;
			    }
			}			 
            state = BEGIN;
            return 1;
            
    }// end of switch
}// end of while
#endif //#ifndef USE_NONBLOCKING_CONFIG   
}

#endif // USE_GOL
