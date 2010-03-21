// JpegTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "JpegLib.h"
#include "stdlib.h"
#include "time.h"
GLOBAL(void)
    write_JPEG_file (char * filename, int quality);

unsigned char buf[320*240*3] = {0};
JSAMPLE * image_buffer = buf;	/* Points to large array of R,G,B-order data */
int image_height = 320;	/* Number of rows in image */
int image_width = 240;		/* Number of columns in image */

PJpegHookStruct   AllocateJH();
PJpegHookStruct  pJH = NULL;
void    DumpJpegData(PJpegHookStruct  pjh, const char* fileName);

char UserComment[] = "lxyppc's project";
int _tmain(int argc, _TCHAR* argv[])
{
    int i;
    time_t t;
    pJH = AllocateJH();
    JH_InitialMemory(pJH);
    srand(time(&t));
    for(i=0; i<320*240;i++){
        int row = (i/240) / 16;
        int col = (i%240) / 16;

        buf[i*3 + 0] = row*15 ; // r
        buf[i*3 + 1] = col*15 ; // g
        buf[i*3 + 2] = (row+col)*2; // b
    }
    //memset(buf,0xff,320*240*3/2);
    write_JPEG_file ("123.jpg", 100);
    DumpJpegData(pJH, "myTest.jpg");
	return 0;
}


typedef   struct  HuffBlock
{
    int           DCOrgVal;
    unsigned int  DCOrgSize;
    unsigned char DCEncodeStream[16];
    unsigned int  DCEncodeStreamIndex;
    unsigned int  DCEncodeStreamSize;
    unsigned int  DCBuffer;
    unsigned int  DCRemainSize;

    int           ACOrgVal[63];
    unsigned int  ACOrgSize;
    unsigned char ACEncodeStream[256];
    unsigned int  ACEncodeStreamIndex;
    unsigned int  ACEncodeStreamSize;
    unsigned int  ACBuffer;
    unsigned int  ACRemainSize;

    unsigned int  DCTableindex;
    unsigned char ci;
}HuffBlock;

typedef struct  DerivedTable
{
    unsigned int   codeTable[256];
    unsigned int   sizeTable[256];
}DerivedTable;

typedef   struct  MCUBlock
{
    int         blockCnt;
    HuffBlock   huffBlocks[16];
}MCUBlock;

typedef   struct JpegHookStruct
{
    unsigned char*  mem;
    unsigned char*  header;
    unsigned int    headerSize;
    unsigned int    curIndex;
    MCUBlock        MCUBlocks[4096];    // Max pixel 1024*1024
    unsigned int    MCUCount;
    DerivedTable    dcTable[4];
    DerivedTable    acTable[4];
}JpegHookStruct,*PJpegHookStruct;

PJpegHookStruct   AllocateJH()
{
    PJpegHookStruct p = (PJpegHookStruct)malloc(sizeof(JpegHookStruct));
    memset(p,0,sizeof(JpegHookStruct));
    return p;
}

void    JH_InitialMemory(PJpegHookStruct pjh)
{
    pjh->mem = malloc(1024*64);
    memset(pjh->mem,0,1024*64);
    pjh->curIndex = 0;
    pjh->MCUCount = 0;
}

void    JH_Global_GetOneByte(PJpegHookStruct pjh, unsigned char val)
{
    pjh->mem[pjh->curIndex++] = val;
}

/* Encode block related functions */
void    JH_Block_Start(PJpegHookStruct pjh)
{
}

void    JH_Block_OnDC(PJpegHookStruct pjh, int val, unsigned char size, unsigned char tableIndex, unsigned char ci)
{
    MCUBlock *pMCU = &pjh->MCUBlocks[pjh->MCUCount];
    pMCU->huffBlocks[pMCU->blockCnt].DCOrgVal = val;
    pMCU->huffBlocks[pMCU->blockCnt].DCOrgSize = size;
    pMCU->huffBlocks[pMCU->blockCnt].DCTableindex = tableIndex;
    pMCU->huffBlocks[pMCU->blockCnt].ci = ci;
}

void    JH_Block_OnAC(PJpegHookStruct pjh, int val, unsigned char size)
{
    // asert(size == 8)
    MCUBlock *pMCU = &pjh->MCUBlocks[pjh->MCUCount];
    HuffBlock *pHuff = &pMCU->huffBlocks[pMCU->blockCnt];
    pHuff->ACOrgVal[pHuff->ACOrgSize++] = val;
}

void    JH_Block_OnDCStream(PJpegHookStruct pjh, unsigned int val, unsigned char size)
{
    MCUBlock *pMCU = &pjh->MCUBlocks[pjh->MCUCount];
    HuffBlock *pHuff = &pMCU->huffBlocks[pMCU->blockCnt];
    unsigned int temp = val & ((1<<size)-1);
    unsigned int curLen = pHuff->DCRemainSize + size;
    temp = (temp<<(24-curLen) | pHuff->DCBuffer);
    while(curLen>=8){
        pHuff->DCEncodeStream[pHuff->DCEncodeStreamIndex++] = (temp>>16) & 0xFF;
        curLen-=8;
        temp<<=8;
    }
    pHuff->DCBuffer = temp & 0xFFFF0000;
    pHuff->DCRemainSize = curLen;
    pHuff->DCEncodeStreamSize+=size;
}

void    JH_Block_OnACStream(PJpegHookStruct pjh, unsigned int val, unsigned char size)
{
    MCUBlock *pMCU = &pjh->MCUBlocks[pjh->MCUCount];
    HuffBlock *pHuff = &pMCU->huffBlocks[pMCU->blockCnt];
    unsigned int temp = val & ((1<<size)-1);
    unsigned int curLen = pHuff->ACRemainSize + size;
    temp = (temp<<(24-curLen) | pHuff->ACBuffer);
    while(curLen>=8){
        pHuff->ACEncodeStream[pHuff->ACEncodeStreamIndex++] = (temp>>16) & 0xFF;
        curLen-=8;
        temp<<=8;
    }
    pHuff->ACBuffer = temp & 0xFFFF0000;
    pHuff->ACRemainSize = curLen;
    pHuff->ACEncodeStreamSize+=size;
}

void    JH_Block_End(PJpegHookStruct pjh)
{
    MCUBlock *pMCU = &pjh->MCUBlocks[pjh->MCUCount];
    HuffBlock *pHuff = &pMCU->huffBlocks[pMCU->blockCnt];
    if(pHuff->DCRemainSize){
        unsigned int tmp = pHuff->DCBuffer>>16;
        tmp = tmp>>(8-pHuff->DCRemainSize);
        tmp = tmp<<(8-pHuff->DCRemainSize);
        pHuff->DCEncodeStream[pHuff->DCEncodeStreamIndex++] = tmp;
    }
    if(pHuff->ACRemainSize){
        unsigned int tmp = pHuff->ACBuffer>>16;
        tmp = tmp>>(8-pHuff->ACRemainSize);
        tmp = tmp<<(8-pHuff->ACRemainSize);
        pHuff->ACEncodeStream[pHuff->ACEncodeStreamIndex++] = tmp;
    }
    pMCU->blockCnt++;
}

void    JH_MCU_Start(PJpegHookStruct pjh)
{
}

void    JH_MCU_End(PJpegHookStruct pjh)
{
    pjh->MCUCount++;
}

void    JH_OnCreate_Table(PJpegHookStruct pjh, int isDC, int index, unsigned int* code, unsigned char* size, int len)
{
    int i = 0;
    DerivedTable *dt = 0;
    if(isDC){
        dt = &pjh->dcTable[index];
    }else{
        dt = &pjh->acTable[index];
    }
    if(!dt)return;
    for(i=0;i<len;i++){
        dt->codeTable[i] = code[i];
        dt->sizeTable[i] = size[i];
    }
}

void    JH_OnScanStart(PJpegHookStruct pjh)
{
    FILE* fp = fopen("HookHead.bin","wb+");
    fwrite(pjh->mem,1,pjh->curIndex,fp);
    fflush(fp);
    fclose(fp);
    pjh->header = malloc(pjh->curIndex);
    pjh->headerSize = pjh->curIndex;
    memcpy(pjh->header,pjh->mem,pjh->headerSize);
}

void CheckByte(unsigned char val)
{
    static int state = 0;
    switch(state){
        case 0:
            if(val == 0x84){
                state++;
            }else{
                state = 0;
            }
            break;
        case 1:
            if(val == 0x7c){
                state++;
            }else{
                state = 0;
            }
            break;
        case 2:
            if(val == 0x15){
                state++;
            }else{
                state = 0;
            }
            break;
        default:
            break;
    }
}

void    StreamOut(FILE* fp, unsigned char* streamBuffer, unsigned int streamSize)
{
    static unsigned int buffer = 0;
    static unsigned int remain = 0;
    unsigned int cnt = remain + streamSize;
    unsigned int offset1 = 24 - remain;
    unsigned int offset2 = 16 - remain;
    if(streamBuffer){
        buffer |= (*streamBuffer++)<<offset1;
        buffer |= (*streamBuffer++)<<offset2;
        while(cnt>=16){
            unsigned char tmp;
            tmp = buffer>>24;
            fwrite(&tmp,1,1,fp);
            CheckByte(tmp);
            if(tmp == 0xFF){
                tmp = 0;
                fwrite(&tmp,1,1,fp);
            }
            tmp = buffer>>16;
            CheckByte(tmp);
            fwrite(&tmp,1,1,fp);
            if(tmp == 0xFF){
                tmp = 0;
                fwrite(&tmp,1,1,fp);
            }
            cnt-=16;
            buffer<<=16;
            buffer |= (*streamBuffer++)<<offset1;
            buffer |= (*streamBuffer++)<<offset2;
        }
        remain = cnt;
    }else{
        if(remain >= 8){
            unsigned char data = buffer>>24;
            fwrite(&data,1,1,fp);
            remain -= 8;
            buffer<<=8;
        }
        if(remain){
            unsigned char data;
            remain = 8 - remain;
            buffer >>= 24;
            buffer |= ((1<<remain) - 1);
            data = buffer;
            fwrite(&data,1,1,fp);
            if(data == 0xFF){
                data = 0;
                fwrite(&data,1,1,fp);
            }
        }
        remain = 0;
        buffer = 0;
    }
}

void    DCStreamOut(FILE* fp, HuffBlock *pHuff, PJpegHookStruct  pjh)
{
    static int lastDC[4] = {0};
    int temp,temp2;
    int bitCnt;
    unsigned char stream[16] = {0};
    int streamSize = 0;
    int streamIndex = 0;
    unsigned int code,c1,c2;
    int size,s1,s2;
    temp = temp2 = pHuff->DCOrgVal - lastDC[pHuff->ci];
    lastDC[pHuff->ci] = pHuff->DCOrgVal;
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
    c1 = code = pjh->dcTable[pHuff->DCTableindex].codeTable[bitCnt];
    s1 = size = pjh->dcTable[pHuff->DCTableindex].sizeTable[bitCnt];
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


    for(size = 0;size<streamSize;size+=8){
        if(stream[size/8] != pHuff->DCEncodeStream[size/8]){
            //printf("Error!\n");
        }
    }
    StreamOut(fp,stream,streamSize);
}

void    StreamOut2(FILE* fp, unsigned char* streamBuffer, unsigned int streamSize)
{
    static unsigned int buffer = 0;
    static unsigned int remain = 0;
    int curCnt = 0;
    unsigned char tmp = *streamBuffer++;
    while(streamSize--){
        curCnt++;
        buffer<<=1;
        buffer|= (tmp>>7);
        remain++;
        tmp<<=1;
        if(remain == 8){
            remain -= 8;
            fwrite(&buffer,1,1,fp);
            if((buffer & 0xFF) == 0xFF){
                buffer = 0;
                fwrite(&buffer,1,1,fp);
            }
        }
        if(curCnt == 8){
            curCnt = 0;
            tmp = *streamBuffer++;
        }
    }
}

void    DumpJpegData(PJpegHookStruct  pjh, const char* fileName)
{
    FILE* fp = fopen(fileName,"wb+");
    int iMCU,iBlock;
    unsigned int endImage = 0xD9FF;
    if(!fp)goto Error;
    if(!pjh->header)goto Error;
    fwrite(pjh->header,1,pjh->headerSize,fp);
    for(iMCU = 0; iMCU<pjh->MCUCount; iMCU++){
        int ic = iMCU;//rand()%pjh->MCUCount;
        for(iBlock = 0; iBlock<pjh->MCUBlocks[ic].blockCnt; iBlock++){
            HuffBlock *pHuff = &pjh->MCUBlocks[ic].huffBlocks[iBlock];
            //StreamOut(fp,pHuff->DCEncodeStream,pHuff->DCEncodeStreamSize);
            DCStreamOut(fp,pHuff,pjh);
            StreamOut(fp,pHuff->ACEncodeStream,pHuff->ACEncodeStreamSize);
        }
    }
    StreamOut(fp,0,0);
    fwrite(&endImage,1,2,fp);
    fclose(fp);
Error:
    if(fp)fclose(fp);
}

