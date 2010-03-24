/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : usb_endp.c
* Author             : MCD Application Team
* Version            : V2.2.0
* Date               : 06/13/2008
* Description        : Endpoint routines
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_lib.h"
#include "usb_lib.h"
#include "usb_istr.h"
#include "usb_desc.h"
#include "Task.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Extern variables ----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Extern function prototypes ------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
* Function Name  : EP1_OUT_Callback
* Description    : Endpoint 1 out callback routine.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void EP1_OUT_Callback_noUse(void);
void EP1_OUT_Callback_noUse(void)
{
//  u16 Data_Len;       /* data length*/
//  if (GetENDPOINT(ENDP1) & EP_DTOG_TX)
//  {
//    /*read from ENDP1_BUF0Addr buffer*/
//    Data_Len = GetEPDblBuf0Count(ENDP1);
//    PMAToUserBufferCopy(Stream_Buff, ENDP1_BUF0Addr, Data_Len);
//  }
//  else
//  {
//    /*read from ENDP1_BUF1Addr buffer*/
//    Data_Len = GetEPDblBuf1Count(ENDP1);
//    PMAToUserBufferCopy(Stream_Buff, ENDP1_BUF1Addr, Data_Len);
//  }
//  FreeUserBuffer(ENDP1, EP_DBUF_OUT);
//  In_Data_Offset += Data_Len;
}

/**
    RGB to YUV Conversion
    Y  =      (0.257 * R) + (0.504 * G) + (0.098 * B) + 16
    Cr = V =  (0.439 * R) - (0.368 * G) - (0.071 * B) + 128
    Cb = U = -(0.148 * R) - (0.291 * G) + (0.439 * B) + 128
    
    YUV to RGB Conversion
    B = 1.164(Y - 16)                   + 2.018(U - 128)
    G = 1.164(Y - 16) - 0.813(V - 128) - 0.391(U - 128)
    R = 1.164(Y - 16) + 1.596(V - 128)
 */


u32 IsOn1(void);
void TurnOffLED1(void);
void TurnOnLED1(void);

#define   HEAD_SIZE                 (2)
#define   VALID_DATA_PER_PACKET     (PACKET_SIZE-HEAD_SIZE)
#define   DATA_PER_FRAME            (WIDTH*HEIGHT*2)

#define   PIXEL_PATTEN        0x80,0x40,0x80,0x40,

u8 vBufA[PACKET_SIZE] = {
  //0x0C,0x8C,0x00,0x00, 0x00,0x00,0x00,0x00,
  0x02,0x00,0x00,0x00, 0x00,0x00,0x00,0x00,
    PIXEL_PATTEN   PIXEL_PATTEN
    PIXEL_PATTEN   PIXEL_PATTEN
    PIXEL_PATTEN   PIXEL_PATTEN
      
    PIXEL_PATTEN   PIXEL_PATTEN
    PIXEL_PATTEN   PIXEL_PATTEN
    PIXEL_PATTEN   PIXEL_PATTEN
    PIXEL_PATTEN   PIXEL_PATTEN
//    0x0F,0xF0,0x0F,0xF0, 0x0F,0xF0,0x0F,0xF0,
//    0x0F,0xF0,0x0F,0xF0, 0x0F,0xF0,0x0F,0xF0,
//    0x0F,0xF0,0x0F,0xF0, 0x0F,0xF0,0x0F,0xF0,
//    
//    0x0F,0xF0,0x0F,0xF0, 0x0F,0xF0,0x0F,0xF0,
//    0x0F,0xF0,0x0F,0xF0, 0x0F,0xF0,0x0F,0xF0,
//    0x0F,0xF0,0x0F,0xF0, 0x0F,0xF0,0x0F,0xF0,
//    0x0F,0xF0,0x0F,0xF0, 0x0F,0xF0,0x0F,0xF0,
};
u8 vBufB[PACKET_SIZE] = { 
  //0x0C,0x8D,0x00,0x00, 0x00,0x00,0x00,0x00,
  0x02,0x01,0x00,0x00, 0x00,0x00,0x00,0x00,
//  0xF0,0x00,0xF0,0x00, 0xF0,0x00,0xF0,0x00,
//  0xF0,0x00,0xF0,0x00, 0xF0,0x00,0xF0,0x00,
//  0xF0,0x00,0xF0,0x00, 0xF0,0x00,0xF0,0x00,
//  
//  0xF0,0x00,0xF0,0x00, 0xF0,0x00,0xF0,0x00,
//  0xF0,0x00,0xF0,0x00, 0xF0,0x00,0xF0,0x00,
//  0xF0,0x00,0xF0,0x00, 0xF0,0x00,0xF0,0x00,
//  0xF0,0x00,0xF0,0x00, 0xF0,0x00,0xF0,0x00,
//    0xFF,0xFF,0xFF,0xFF, 0xFF,0xFF,0xFF,0xFF,
//    0xFF,0xFF,0xFF,0xFF, 0xFF,0xFF,0xFF,0xFF,
//    0xFF,0xFF,0xFF,0xFF, 0xFF,0xFF,0xFF,0xFF,
//    
//    0xFF,0xFF,0xFF,0xFF, 0xFF,0xFF,0xFF,0xFF,
//    0xFF,0xFF,0xFF,0xFF, 0xFF,0xFF,0xFF,0xFF,
//    0xFF,0xFF,0xFF,0xFF, 0xFF,0xFF,0xFF,0xFF,
//    0xFF,0xFF,0xFF,0xFF, 0xFF,0xFF,0xFF,0xFF,
};

const u8 ClockFaceData[8][128] = {
  {0,0,0,0,0,0,0,0,0,0,0,0,0,64,0,16,96,128,4,0,0,2,0,0,1,0,0,1,0,0,15,15,15,0,1,0,0,1,0,0,2,0,0,4,128,96,16,0,0,64,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
  {0,0,0,0,0,0,32,0,4,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,4,0,32,0,0,0,0,0,0,0,},
  {0,64,8,0,1,1,2,2,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,2,2,1,1,0,8,64,0,0,},
  {210,192,192,192,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,192,224,224,224,192,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,192,192,192,210,0,},
  {73,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,3,3,3,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,73,0,},
  {0,2,16,0,128,64,32,32,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,32,64,128,128,0,16,2,0,0,},
  {0,0,0,0,0,0,4,0,32,0,128,0,0,0,0,0,0,0,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,0,0,0,0,0,0,0,0,128,0,32,0,4,0,0,0,0,0,0,0,},
  {0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,8,6,1,32,0,0,64,0,0,128,0,0,128,0,0,240,240,240,0,128,0,0,128,0,0,64,0,0,32,1,6,8,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
};

#define   PAYLOAD_HEAD      (*(u16 *)(ENDP1_BUF0Addr * 2 + PMAAddr))
#define   PAYLOAD0          ((u16 *)(ENDP1_BUF0Addr * 2 + PMAAddr+4))

void  EP1_IN_Callbacksss(void);
void  EP1_IN_Callback(void)
{
  SwitchToProc();
}

void  EP1_IN_Callbacksss(void)
{
  static u32 cnt = 0;
  u8 index = (cnt&63)>>3;
  u8 x = 1<<(cnt&7);
  u16 i = 0;
  u16* payLoad = PAYLOAD0;
  TurnOnLED1();
  for(;i<128;i++){
    *payLoad = ClockFaceData[index][i]&x?0x80FF:0x8000;
    payLoad+=2;
  }
  cnt++;
  if(cnt & 64){
    PAYLOAD_HEAD = 0x0002;
  }else{
    PAYLOAD_HEAD = 0x0102;
  }
  TurnOffLED1();
  _ToggleDTOG_RX(ENDP1);
}

void  EP1_IN_Callbackxx(void);
void  EP1_IN_Callbackxx(void)
{
  static u8* curBuf = vBufA;
  static u32 sendCount = 0;
  static u32 endcount = 0;
  u16 Data_Len;
  TurnOnLED1();
  if(sendCount + VALID_DATA_PER_PACKET>= DATA_PER_FRAME){
    Data_Len = DATA_PER_FRAME - sendCount + HEAD_SIZE;
    sendCount = DATA_PER_FRAME;
    //curBuf[1] |= 0x02;
    endcount = 4;
  }else{
    sendCount += VALID_DATA_PER_PACKET;
    Data_Len = PACKET_SIZE;
  }
  //curBuf[63] = checkSum++;
  if(_GetENDPOINT(ENDP1) & EP_DTOG_RX){
    // User use buffer0
    //curBuf[62] = 0xAA;
    UserToPMABufferCopy(curBuf, ENDP1_BUF0Addr, PACKET_SIZE);
    _SetEPDblBuf0Count(ENDP1,EP_DBUF_IN,Data_Len);
  }else{
    // User use buffer1
    //curBuf[62] = 0xBB;
    UserToPMABufferCopy(curBuf, ENDP1_BUF1Addr, PACKET_SIZE);
    _SetEPDblBuf1Count(ENDP1,EP_DBUF_IN,Data_Len);
  }
  TurnOffLED1();
  _ToggleDTOG_RX(ENDP1);
  //FreeUserBuffer(ENDP1, EP_DBUF_IN);
  if(sendCount == DATA_PER_FRAME){
    if(1 || endcount == 0){
      sendCount = 0;
      curBuf = (curBuf == vBufA ? vBufB : vBufA);
      //curBuf[1] &= (~0x02);
      // Generate dwPresentationTime
//      curBuf[2] = (u8)(SystickCount);
//      curBuf[3] = (u8)(SystickCount>>8);
//      curBuf[4] = (u8)(SystickCount>>16);
//      curBuf[5] = (u8)(SystickCount>>24);
    }else{
      endcount--;
    }
  }
}

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/

