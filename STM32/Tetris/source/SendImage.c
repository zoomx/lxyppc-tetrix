/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_lib.h"
#include "usb_lib.h"
#include "usb_istr.h"
#include "usb_desc.h"
#include "hw_config.h"
#include "Task.h"

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
#define   PAYLOAD_SIZE      (PACKET_SIZE-2)
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
int    OutputHuffBlock(const unsigned int* codeTbl, const unsigned char* sizeTbl, int lastDC);


u32     bitTemp;
u8     bitRemain;
void    BitStreamOut(u32 code, u8 size);
u32   __CLZ(u32 val);

// Buffer used to store the bit streams
u16    StreamBuffer[64];
u8*   pStream;

const unsigned char* block;
void  SendImage2(void);
void  SendImage(void)
{
  PAYLOAD_HEAD = 0x0102;
  while(1){
    u16* payLoad = PAYLOAD0;
    const u16*  imageHeader = (const u16*)jpegHead;
    u16         iMcu;
    int         lastDCY,lastDCU,lastDCV;
    PAYLOAD_HEAD ^= 0x0100;
    do{
      *payLoad = *imageHeader++;
      payLoad+=2;
      if(payLoad == PAYLOAD_END){
        _ToggleDTOG_RX(ENDP1);
        SwitchToMain();
        payLoad = PAYLOAD0;
      }
    }while(imageHeader != IMAGE_END);
    
    iMcu = 0;
    lastDCY = lastDCU = lastDCV = 0;
    bitTemp = 0;
    bitRemain = 0;
    pStream = (u8*)StreamBuffer;
    do{
      block = scrBuf[iMcu]? BlockMCU[scrBuf[iMcu]] : BKMcu[iMcu];
      lastDCY = OutputHuffBlock(DCCodeTable0,DCSizeTable0,lastDCY);
      lastDCY = OutputHuffBlock(DCCodeTable0,DCSizeTable0,lastDCY);
      lastDCY = OutputHuffBlock(DCCodeTable0,DCSizeTable0,lastDCY);
      lastDCY = OutputHuffBlock(DCCodeTable0,DCSizeTable0,lastDCY);
      lastDCU = OutputHuffBlock(DCCodeTable1,DCSizeTable1,lastDCU);
      lastDCV = OutputHuffBlock(DCCodeTable1,DCSizeTable1,lastDCV);
      iMcu++;
      if(iMcu == MCU_CNT){
        BitStreamOut(0x7F,7);
        *pStream++ = 0xFF;
        *pStream++ = 0xD9;
      }
      
      {
        u8 length = pStream - ((u8*)StreamBuffer);
        u16* buf = (u16*)StreamBuffer;
        while(length&0xFE){
          *payLoad = *buf++;
          payLoad+=2;
          if(payLoad == PAYLOAD_END){
            _ToggleDTOG_RX(ENDP1);
            SwitchToMain();
            payLoad = PAYLOAD0;
          }
          length-=2;
        }
        if(length){
          StreamBuffer[0] = *pStream;
          pStream = ((u8*)StreamBuffer) + 1;
        }else{
          pStream = (u8*)StreamBuffer;
        }
      }
    }while(iMcu != MCU_CNT);
    if(payLoad != PAYLOAD0){
      _ToggleDTOG_RX(ENDP1);
      SwitchToMain();
    }
  }
}


void    BitStreamOut(u32 code, u8 size)
{
  /* This routine is heavily used, so it's worth coding tightly. */
  u32 put_buffer = code;
  u8 put_bits = bitRemain;

  put_buffer &= (((u32) 1)<<size) - 1; /* mask off any extra bits in code */
  
  put_bits += size;		/* new number of bits in buffer */
  
  put_buffer <<= 24 - put_bits; /* align incoming bits */

  put_buffer |= bitTemp; /* and merge with old buffer contents */
  
  while (put_bits & 0xF8) {
    u8 c = (u8) ((put_buffer >> 16) & 0xFF);
    
    *pStream++ = c;
    if (c == 0xFF) {		/* need to stuff a zero byte? */
      *pStream++ = 0;
    }
    put_buffer <<= 8;
    put_bits -= 8;
  }

  bitTemp = put_buffer; /* update state variables */
  bitRemain = put_bits;
}

int    OutputHuffBlock(const unsigned int* codeTbl, const unsigned char* sizeTbl, int lastDC)
{
  int temp1,temp2;
  dc_t curDC = (dc_t)(*block++);
  u32 bitCnt;
  temp1 = temp2 = curDC - lastDC;
  if(temp1<0){
    temp1 = -temp1;
    temp2--;
  }
  bitCnt = 32 - __CLZ(temp1);
  BitStreamOut(codeTbl[bitCnt],sizeTbl[bitCnt]);
  if(bitCnt){
    BitStreamOut(temp2,bitCnt);
  }
  bitCnt = *block++;
  while(bitCnt>=8){
    BitStreamOut(*block++,8);
    bitCnt-=8;
  }
  if(bitCnt){
    BitStreamOut(*block++,bitCnt);
  }
  return curDC;
}

void  SendImage2(void)
{
  while(1){
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
  SwitchToMain();
  }
}
