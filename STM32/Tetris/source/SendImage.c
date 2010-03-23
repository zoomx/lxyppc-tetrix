/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_lib.h"
#include "usb_lib.h"
#include "usb_istr.h"
#include "usb_desc.h"
#include "hw_config.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Extern variables ----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Extern function prototypes ------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
#include "..\..\..\TetrixPre\DataBK2.c"
#include "..\..\..\TetrixPre\DataBlock.c"
#define     X_BLOCK_CNT     19
#define     Y_BLOCK_CNT     23
#if X_BLOCK_CNT*Y_BLOCK_CNT != MCU_CNT
#error  Size mismatch
#endif
unsigned char scrBuf[X_BLOCK_CNT*Y_BLOCK_CNT] = {0};

#define   PAYLOAD_HEAD      (*(u16 *)(ENDP1_BUF0Addr * 2 + PMAAddr))
#define   PAYLOAD0          ((u16 *)(ENDP1_BUF0Addr * 2 + PMAAddr+4))
#define   PAYLOAD_END       ((u16 *)(ENDP1_BUF0Addr * 2 + PMAAddr+4*PACKET_SIZE))

#define   IMAGE_END         ((const u16*)(jpegHead+sizeof(jpegHead)))

typedef enum{
  TS_Init,
  TS_Head,
  TS_Huff,
  TS_None,
}TransferState;

static  TransferState state = TS_Init;
const u16*    imageHeader = (const u16*)jpegHead;
static  u8 frameCnt = 0;
static  u8    huffIndex = 0;

ac_t    lastAD_Y;
ac_t    lastAD_U;
ac_t    lastAD_V;
unsigned short  BlockIndex = 0;
u32      mainStackPosition;
u32      procStackPosition;
u32*     currentTaskStack;
u32*     nextTaskStack;
void  EP1_IN_Callback(void)
{
  u16* payLoad = PAYLOAD0;
  //TurnOnLED1();
  GPIOF->BRR = GPIO_Pin_7;
  
  switch(state){
  case TS_Init:
    PAYLOAD_HEAD = frameCnt & 1  ? 0x0102 : 0x0002;
    frameCnt++;
    imageHeader = (const u16*)jpegHead;
    state = TS_Head;
  case TS_Head:
    while(imageHeader != IMAGE_END){
      *payLoad = *imageHeader++;
      payLoad+=2;
      if(payLoad == PAYLOAD_END)goto LoopEnd;
    }
    huffIndex = 0;
    lastAD_Y = lastAD_U = lastAD_V = 0;
    BlockIndex = 0;
    state = TS_Huff;
  case TS_Huff:
    switch(huffIndex){
    case 0:
    case 1:
    case 2:
    case 3:
      huffIndex++;
      break;
    case 4:
      huffIndex++;
      break;
    case 5:
    default:
      huffIndex = 0;
      break;
    }
  case TS_None:
  default:
    break;
  }
  
LoopEnd:
  //TurnOffLED1();
  GPIOF->BSRR = GPIO_Pin_7;
  _ToggleDTOG_RX(ENDP1);
  
  currentTaskStack = &mainStackPosition;
  nextTaskStack = &procStackPosition;
  NVIC_SetSystemHandlerPendingBit(SystemHandler_PSV);
}
