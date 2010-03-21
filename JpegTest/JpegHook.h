#pragma once

typedef   struct JpegHookStruct* PJpegHookStruct;
extern    PJpegHookStruct  pJH;

void    JH_InitialMemory(PJpegHookStruct pjh);
void    JH_Global_GetOneByte(PJpegHookStruct pjh, unsigned char val);
void    JH_Block_OnDC(PJpegHookStruct pjh, int val, unsigned char size, unsigned char tableIndex, unsigned char ci);
void    JH_Block_OnAC(PJpegHookStruct pjh, int val, unsigned char size);
void    JH_Block_OnDCStream(PJpegHookStruct pjh, unsigned int val, unsigned char size);
void    JH_Block_OnACStream(PJpegHookStruct pjh, unsigned int val, unsigned char size);
void    JH_Block_Start(PJpegHookStruct pjh);
void    JH_Block_End(PJpegHookStruct pjh);
void    JH_MCU_Start(PJpegHookStruct pjh);
void    JH_MCU_End(PJpegHookStruct pjh);
void    JH_OnCreate_Table(PJpegHookStruct pjh, int isDC, int index, unsigned int* code, unsigned char* size, int len);
void    JH_OnScanStart(PJpegHookStruct pjh);