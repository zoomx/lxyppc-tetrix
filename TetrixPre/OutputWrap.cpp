#include "StdAfx.h"
#include "TetrixPre.h"
#include "TetrixPreDlg.h"
#include "Stream.h"
#include "DataBK.c"
#include "DataBlock.c"

#define     X_BLOCK_CNT     20
#define     Y_BLOCK_CNT     25
#if X_BLOCK_CNT*Y_BLOCK_CNT != MCU_CNT
#error  Size mismatch
#endif
unsigned char scrBuf[X_BLOCK_CNT*Y_BLOCK_CNT] = {0,3};
extern   CStream   scrStream;

FILE* gfp = NULL;
const unsigned char* pBlock = NULL;
//#define INIT_STREAM()       {if(!gfp)gfp = fopen(fileName,"wb+");}
//#define CLOSE_STREAM()      {if(gfp)fclose(gfp);}
//#define OUTPUT_BYTE(x)      {char buf[] = {(x)}; if(gfp)fwrite(buf,1,1,gfp);}

#define INIT_STREAM()       {scrStream.SeekToBegin(); }
#define CLOSE_STREAM()      {}
#define OUTPUT_BYTE(x)      scrStream.Write((BYTE)(x))
        

void    JpegStreamOut(const unsigned char* streamBuffer, unsigned int streamSize);
int    OutputHuffBlock(const unsigned int* codeTbl, const unsigned char* sizeTbl, int lastDC);
void    GenerateJpeg(const char* fileName)
{
    int i;
    int lastDCY,lastDCU,lastDCV;
    lastDCY = lastDCU = lastDCV = 0;
    INIT_STREAM();
    for(i=0; i<sizeof(jpegHead); i++){
        OUTPUT_BYTE(jpegHead[i]);
    }
    for(i=0;i<MCU_CNT;i++){
        // Output the MCU block
        if(scrBuf[i]){
            pBlock = BlockMCU[scrBuf[i]];
        }else{
            pBlock = BKMcu[i];
        }
        lastDCY = OutputHuffBlock(DCCodeTable0,DCSizeTable0,lastDCY);
        lastDCY = OutputHuffBlock(DCCodeTable0,DCSizeTable0,lastDCY);
        lastDCY = OutputHuffBlock(DCCodeTable0,DCSizeTable0,lastDCY);
        lastDCY = OutputHuffBlock(DCCodeTable0,DCSizeTable0,lastDCY);
        lastDCU = OutputHuffBlock(DCCodeTable1,DCSizeTable1,lastDCU);
        lastDCV = OutputHuffBlock(DCCodeTable1,DCSizeTable1,lastDCV);
    }
    JpegStreamOut(0,0);
    OUTPUT_BYTE(0xFF);
    OUTPUT_BYTE(0xD9);
    CLOSE_STREAM();
}

#define     GET_VAL(type)       *((type*)pBlock)
#define     MOVE_PTR(type)      pBlock += sizeof(type)
#define     MOVE_PTR_STREAM(size)   pBlock += ((size)+7)/8
#define     GET_PTR()               pBlock


void    JpegStreamOut(const unsigned char* streamBuffer, unsigned int streamSize)
{
    static unsigned int buffer = 0;
    static unsigned int remain = 0;
    unsigned int cnt = remain + streamSize;
    unsigned int offset1 = 24 - remain;
    unsigned int offset2 = 16 - remain;
    unsigned int streamRemain = (streamSize+7)/8;
    if(streamSize == 0){
        printf("Error!");
    }
    if(streamBuffer){
        if(streamRemain){
            buffer |= (*streamBuffer++)<<offset1;
            streamRemain--;
        }
        if(streamRemain){
            buffer |= (*streamBuffer++)<<offset2;
            streamRemain--;
        }
        while(cnt>=16){
            unsigned char tmp;
            tmp = buffer>>24;
            OUTPUT_BYTE(tmp);
            if(tmp == 0xFF){
                OUTPUT_BYTE(0);
            }
            tmp = buffer>>16;
            OUTPUT_BYTE(tmp);
            if(tmp == 0xFF){
                OUTPUT_BYTE(0);
            }
            cnt-=16;
            buffer<<=16;
            if(streamRemain){
                buffer |= (*streamBuffer++)<<offset1;
                streamRemain--;
            }
            if(streamRemain){
                buffer |= (*streamBuffer++)<<offset2;
                streamRemain--;
            }
        }
        remain = cnt;
    }else{
        if(remain >= 8){
            unsigned char data = buffer>>24;
            OUTPUT_BYTE(data);
            if(data == 0xFF){
                OUTPUT_BYTE(0);
            }
            remain -= 8;
            buffer<<=8;
        }
        if(remain){
            unsigned char data;
            remain = 8 - remain;
            buffer >>= 24;
            buffer |= ((1<<remain) - 1);
            data = buffer;
            OUTPUT_BYTE(data);
            if(data == 0xFF){
                OUTPUT_BYTE(0);
            }
        }
        remain = 0;
        buffer = 0;
    }
}

int    OutputHuffBlock(const unsigned int* codeTbl, const unsigned char* sizeTbl, int lastDC)
{
    int temp,temp2;
    int bitCnt;
    unsigned char stream[16] = {0};
    int streamSize = 0;
    int streamIndex = 0;
    unsigned int code,c1,c2;
    int size,s1,s2;
    const unsigned char* ACStream;
    dc_t dc;
    ac_t acSize;
    dc = GET_VAL(dc_t);
    MOVE_PTR(dc_t);
    acSize = GET_VAL(ac_t);
    MOVE_PTR(ac_t);
    ACStream = GET_PTR();
    MOVE_PTR_STREAM(acSize);
    temp = temp2 = (int)dc - lastDC;
    lastDC = (int)dc;
    if(temp<0){
        temp = -temp;
        temp2--;
    }
    bitCnt = 0;
    while (temp){
        bitCnt++;
        temp >>= 1;
    }
    size = 0;
    c1 = code = codeTbl[bitCnt];
    s1 = size = sizeTbl[bitCnt];
    if(bitCnt){
        c2 = temp2 & ((1<<bitCnt) - 1);
        code = (c1<<bitCnt) | c2;
    }else{
        code = c1;
    }
    s2 = bitCnt;
    streamSize = size + bitCnt;
    size = streamSize;
    while(size>0){
        if(size>=8){
            stream[streamIndex++] = code >> (size-8);
        }else{
            stream[streamIndex++] = code << (8-size);
        }
        size-=8;
    }

    JpegStreamOut(stream,streamSize);
    JpegStreamOut(ACStream,acSize);
    return lastDC;
}