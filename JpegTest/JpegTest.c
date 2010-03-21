// JpegTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "JpegLib.h"
#include "stdlib.h"
#include "time.h"
//#include "image.h"
//#include "imagebk.h"
#include "wall.h"
#include "Data.c"
GLOBAL(void)
    write_JPEG_file (char * filename, int quality);

#ifndef WIDTH
#define WIDTH       320
#endif

#ifndef HEIGHT
#define HEIGHT       400
#endif

unsigned char buf[HEIGHT*WIDTH*3] = {RGB_DATA};
JSAMPLE * image_buffer = buf;	/* Points to large array of R,G,B-order data */
int image_height = HEIGHT;	/* Number of rows in image */
int image_width = WIDTH;		/* Number of columns in image */

PJpegHookStruct   AllocateJH();
PJpegHookStruct  pJH = NULL;
void    DumpJpegData(PJpegHookStruct  pjh, const char* fileName);
void    DumpStreamData(PJpegHookStruct  pjh, const char* fileName);
void    GenerateJpeg(const char* fileName);

char UserComment[] = "lxyppc's project";
typedef unsigned long COLORREF,DWORD;
typedef unsigned char BYTE;
typedef unsigned short WORD;
#define GetRValue(rgb)      ((BYTE)(rgb))
#define GetGValue(rgb)      ((BYTE)(((WORD)(rgb)) >> 8))
#define GetBValue(rgb)      ((BYTE)((rgb)>>16))
#define RGB(r,g,b)          ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
int _tmain(int argc, _TCHAR* argv[])
{
    int i;
    time_t t;
    COLORREF start = RGB(255,255,255);
    COLORREF end  = RGB(0,0,0);
    int div = image_height/16;
    float rstep = (float)(GetRValue(end) - GetRValue(start)) / div;
    float gstep = (float)(GetGValue(end) - GetGValue(start)) / div;
    float bstep = (float)(GetBValue(end) - GetBValue(start)) / div;
    int rstart = GetRValue(start);
    int gstart = GetGValue(start);
    int bstart = GetBValue(start);
    pJH = AllocateJH();
    JH_InitialMemory(pJH);
    srand((unsigned int)time(&t));
    for(i=0; i<image_height*image_width;i++){
        int row = i/image_width;
        int col = i%image_width;
        row /= 16;
        col /= 16;
        buf[i*3 + 0] = (row&3) * 63;
        buf[i*3 + 1] = (col&3) * 63;
        buf[i*3 + 2] = (col&3) * 63;
        //buf[i*3 + 0] = (BYTE)(row*rstep + rstart); // r
        //buf[i*3 + 1] = (BYTE)(row*gstep + gstart); // g
        //buf[i*3 + 2] = (BYTE)(row*bstep + bstart); // b
    }
    //memset(buf,0xff,320*240*3/2);
    write_JPEG_file ("123.jpg", 50);
    DumpJpegData(pJH, "myTest.jpg");
    DumpStreamData(pJH,"Data.c");
    GenerateJpeg("test.jpg");
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
    int   codeTable[256];
    unsigned int   sizeTable[256];
}DerivedTable;

typedef   struct  MCUBlock
{
    unsigned int    blockCnt;
    HuffBlock       huffBlocks[16];
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
    int             maxDC;       // DC max value
    int             minDC;       // DC min value
    unsigned int    maxDCBit;    // DC max bit number
    unsigned int    maxACStream; // AC max stream size
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

void    StreamOut(FILE* fp,const unsigned char* streamBuffer, unsigned int streamSize)
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
    unsigned int bitCnt;
    unsigned char stream[16] = {0};
    int streamSize = 0;
    int streamIndex = 0;
    unsigned int code,c1,c2;
    int size,s1,s2;
    if(pHuff->DCOrgVal > pjh->maxDC)pjh->maxDC = pHuff->DCOrgVal;
    if(pHuff->DCOrgVal < pjh->minDC)pjh->minDC = pHuff->DCOrgVal;
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
    if(bitCnt > pjh->maxDCBit) pjh->maxDCBit = bitCnt;
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
    unsigned int iMCU,iBlock;
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
            if(pHuff->ACEncodeStreamSize > pjh->maxACStream ){
                pjh->maxACStream = pHuff->ACEncodeStreamSize;
            }
        }
    }
    StreamOut(fp,0,0);
    fwrite(&endImage,1,2,fp);
    fclose(fp);
Error:
    if(fp)fclose(fp);
}

void   DumpStreamData(PJpegHookStruct  pjh, const char* fileName)
{
    FILE* fp = fopen(fileName,"w+");
    unsigned int i = 0;
    int DCSize;
    int ACSize;
    if(!fp)goto Error;
    if(!pjh->header)goto Error;
    if(!pjh->MCUCount)goto Error;
    /* Dump the head data */
    fprintf(fp,"#define MAX_DC          (%d)\n",pjh->maxDC);
    fprintf(fp,"#define MIN_DC          (%d)\n",pjh->minDC);
    fprintf(fp,"#define MAX_DC_BIT      (%d)\n",pjh->maxDCBit);
    fprintf(fp,"#define MAX_AC_BIT      (%d)\n",pjh->maxACStream);
    fprintf(fp,"#define MCU_CNT         (%d)\n",pjh->MCUCount);
    if(pjh->maxDC > 127 || pjh->minDC < -128){
        DCSize = 2;
        fprintf(fp,"#define DC_SIZE         (%d)\n",DCSize);
        fprintf(fp,"typedef signed short dc_t;\n");
    }else{
        DCSize = 1;
        fprintf(fp,"#define DC_SIZE         (%d)\n",DCSize);
        fprintf(fp,"typedef signed char dc_t;\n");
    }
    if(pjh->maxACStream > 255){
        ACSize = 2;
        fprintf(fp,"#define AC_SIZE         (%d)\n",ACSize);
        fprintf(fp,"typedef unsigned short ac_t;\n");
    }else{
        ACSize = 1;
        fprintf(fp,"#define AC_SIZE         (%d)\n",ACSize);
        fprintf(fp,"typedef unsigned char ac_t;\n");
    }
    fprintf(fp,"const unsigned char jpegHead[%d] = {\n",pjh->headerSize);
    for(i=0;i<pjh->headerSize;i++){
        fprintf(fp," 0x%02X,",pjh->header[i]);
        if( (i&15) == 15){
            fprintf(fp,"\n");
        }
    }
    fprintf(fp,"\n};\n");

    /* Dump the DC table 0*/
    fprintf(fp,"const unsigned int DCCodeTable0[] = {\n");
    for(i=0;i<256;i++){
        fprintf(fp," %d,",pjh->dcTable[0].codeTable[i]);
        if( (i&15) == 15){
            fprintf(fp,"\n");
        }
    }
    fprintf(fp,"\n};\n");
    fprintf(fp,"const unsigned char DCSizeTable0[] = {\n");
    for(i=0;i<256;i++){
        fprintf(fp," %d,",pjh->dcTable[0].sizeTable[i]);
        if( (i&15) == 15){
            fprintf(fp,"\n");
        }
    }
    fprintf(fp,"\n};\n");

    /* Dump the DC table 1 */
    fprintf(fp,"const unsigned int DCCodeTable1[] = {\n");
    for(i=0;i<256;i++){
        fprintf(fp," %d,",pjh->dcTable[1].codeTable[i]);
        if( (i&15) == 15){
            fprintf(fp,"\n");
        }
    }
    fprintf(fp,"\n};\n");
    fprintf(fp,"const unsigned char DCSizeTable1[] = {\n");
    for(i=0;i<256;i++){
        fprintf(fp," %d,",pjh->dcTable[1].sizeTable[i]);
        if( (i&15) == 15){
            fprintf(fp,"\n");
        }
    }
    fprintf(fp,"\n};\n");

#if 0   // The AD value is output in the stream, so there is no need to dump the AC table
    /* Dump the AC table 0 */
    fprintf(fp,"const unsigned int ACCodeTable0[] = {\n");
    for(i=0;i<256;i++){
        fprintf(fp," %d,",pjh->acTable[0].codeTable[i]);
        if( (i&15) == 15){
            fprintf(fp,"\n");
        }
    }
    fprintf(fp,"\n};\n");
    fprintf(fp,"const unsigned char ACSizeTable0[] = {\n");
    for(i=0;i<256;i++){
        fprintf(fp," %d,",pjh->acTable[0].sizeTable[i]);
        if( (i&15) == 15){
            fprintf(fp,"\n");
        }
    }
    fprintf(fp,"\n};\n");

    /* Dump the AC table 1 */
    fprintf(fp,"const unsigned int ACCodeTable1[] = {\n");
    for(i=0;i<256;i++){
        fprintf(fp," %d,",pjh->acTable[1].codeTable[i]);
        if( (i&15) == 15){
            fprintf(fp,"\n");
        }
    }
    fprintf(fp,"\n};\n");
    fprintf(fp,"const unsigned char ACSizeTable1[] = {\n");
    for(i=0;i<256;i++){
        fprintf(fp," %d,",pjh->acTable[1].sizeTable[i]);
        if( (i&15) == 15){
            fprintf(fp,"\n");
        }
    }
    fprintf(fp,"\n};\n");
#endif
    /* Dump the MCU data */
    for(i=0;i<pjh->MCUCount;i++){
        MCUBlock *pMCU = &pjh->MCUBlocks[i];
        unsigned int val;
        unsigned int iHuf = 0;
        fprintf(fp,"static const unsigned char MCU%d[] = {\n",i);
        for(iHuf = 0; iHuf<pMCU->blockCnt;iHuf++){
        {
            int iDC,shadow;
            shadow = val = pMCU->huffBlocks[iHuf].DCOrgVal;
            if(shadow<0)shadow = -shadow;
            fprintf(fp,"/* DC%d: */",iHuf);
            for(iDC = 0;iDC<DCSize; iDC++){
                fprintf(fp," 0x%02X,",val&0xFF);
                val>>=8;
                shadow>>=8;
            }
            if(shadow){
                *(char*)0 = 0;
            }
            fprintf(fp,"\n");
            //fprintf(fp,"/* DC%d: */ 0x%02X, 0x%02X, 0x%02X, 0x%02X,\n",iHuf,
            //    val & 0xFF , (val>>8)&0xFF, (val>>16)&0xFF, (val>>24)& 0xFF);
        }
        //for(iHuf = 0; iHuf<pMCU->blockCnt;iHuf++)
        {
            int iAC,shadow;
            shadow = val = pMCU->huffBlocks[iHuf].ACEncodeStreamSize;
            if(shadow<0)shadow = -shadow;
            fprintf(fp,"/* AC%d Size: */",iHuf);// 0x%02X, 0x%02X, 0x%02X, 0x%02X,\n",iHuf,
                //val & 0xFF , (val>>8)&0xFF, (val>>16)&0xFF, (val>>24)& 0xFF);
            for(iAC = 0;iAC<ACSize; iAC++){
                fprintf(fp," 0x%02X,",val&0xFF);
                val>>=8;
                shadow>>=8;
            }
            if(shadow){
                *(char*)0 = 0;
            }
            fprintf(fp,"\n");
        }

        //for(iHuf = 0; iHuf<pMCU->blockCnt;iHuf++)
        {
            unsigned int iData;
            val = pMCU->huffBlocks[iHuf].ACEncodeStreamSize;
            fprintf(fp,"/* AC%d Stream */\n",iHuf);
            val = (val+7)/8;
            for(iData =0;iData<val;iData++){
                fprintf(fp," 0x%02X,",pMCU->huffBlocks[iHuf].ACEncodeStream[iData]);
                if( (iData&15) == 15){
                    fprintf(fp,"\n");
                }
            }
            fprintf(fp,"\n");
        }
        }
        fprintf(fp,"\n};\n");
    }

    fprintf(fp,"typedef  const unsigned char* LPCSTR;\n");
    fprintf(fp,"const LPCSTR BKMcu[MCU_CNT] = {\n");
    for(i=0;i<pjh->MCUCount;i++){
        fprintf(fp," MCU%d,",i);
        if( (i&15) == 15){
            fprintf(fp,"\n");
        }
    }
    fprintf(fp,"\n};\n");
Error:
    if(fp)fclose(fp);
}

FILE* gfp = NULL;
const char* pBlock = NULL;
#define INIT_STREAM()       {if(!gfp)gfp = fopen(fileName,"wb+");}
#define CLOSE_STREAM()      {if(gfp)fclose(gfp);}
#define OUTPUT_BYTE(x)      {char buf[] = {(x)}; if(gfp)fwrite(buf,1,1,gfp);}

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
        pBlock = BKMcu[i];
        lastDCY = OutputHuffBlock(DCCodeTable0,DCSizeTable0,lastDCY);
        lastDCY = OutputHuffBlock(DCCodeTable0,DCSizeTable0,lastDCY);
        lastDCY = OutputHuffBlock(DCCodeTable0,DCSizeTable0,lastDCY);
        lastDCY = OutputHuffBlock(DCCodeTable0,DCSizeTable0,lastDCY);
        lastDCU = OutputHuffBlock(DCCodeTable1,DCSizeTable1,lastDCU);
        lastDCV = OutputHuffBlock(DCCodeTable1,DCSizeTable1,lastDCV);
    }
    StreamOut(gfp,0,0);
    OUTPUT_BYTE(0xFF);
    OUTPUT_BYTE(0xD9);
    CLOSE_STREAM();
}

#define     GET_VAL(type)       *((type*)pBlock)
#define     MOVE_PTR(type)      pBlock += sizeof(type)
#define     MOVE_PTR_STREAM(size)   pBlock += ((size)+7)/8
#define     GET_PTR()               pBlock

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
    if(0){
        static cnt = 0;
        static FILE* fold = NULL;
        static FILE* fnew = NULL;
        int iMCU = cnt/6;
        int iHuf = cnt%6;
        int iLog = 0;
        int logS;
        const unsigned char* strm;
        FILE* tfp;
        if(!fold)fold = fopen("old.log","w+");
        if(!fnew)fnew = fopen("new.log","w+");
        tfp = fold;
        logS = pJH->MCUBlocks[iMCU].huffBlocks[iHuf].DCEncodeStreamSize;
        strm = pJH->MCUBlocks[iMCU].huffBlocks[iHuf].DCEncodeStream;
        fprintf(tfp,"%d.%d DC size%d\n",iMCU,iHuf,logS);
        for(iLog = 0; iLog<(logS+7)/8;iLog++){
            fprintf(tfp," 0x%02X,",strm[iLog]);
        }
        fprintf(tfp,"\n");
        logS = pJH->MCUBlocks[iMCU].huffBlocks[iHuf].ACEncodeStreamSize;
        strm = pJH->MCUBlocks[iMCU].huffBlocks[iHuf].ACEncodeStream;
        fprintf(tfp,"%d.%d AC size%d\n",iMCU,iHuf,logS);
        for(iLog = 0; iLog<(logS+7)/8;iLog++){
            fprintf(tfp," 0x%02X,",strm[iLog]);
        }
        fprintf(tfp,"\n");

        tfp = fnew;
        logS = streamSize;
        strm = stream;
        fprintf(tfp,"%d.%d DC size%d\n",iMCU,iHuf,logS);
        for(iLog = 0; iLog<(logS+7)/8;iLog++){
            fprintf(tfp," 0x%02X,",strm[iLog]);
        }
        fprintf(tfp,"\n");
        logS = acSize;
        strm = ACStream;
        fprintf(tfp,"%d.%d AC size%d\n",iMCU,iHuf,logS);
        for(iLog = 0; iLog<(logS+7)/8;iLog++){
            fprintf(tfp," 0x%02X,",strm[iLog]);
        }
        fprintf(tfp,"\n");
        cnt++;
    }
    StreamOut(gfp,stream,streamSize);
    StreamOut(gfp,ACStream,acSize);
    return lastDC;
}