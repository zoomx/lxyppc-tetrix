#include "data_process.h"

#define head1   0
#define head2   0
#define head3   0
#define head4   0
#define end1    0
#define end2    0
#define end3    0
#define end4    0

#define    IDLE     0
#define    HEAD1    1
#define    HEAD2    2
#define    HEAD3    3
#define    HEAD4    4
#define    LEN1     5
#define    LEN2     6
#define    LEN3     7
#define    LEN4     8
#define    DATA     9
#define    CS1      10
#define    CS2      11
#define    CS3      12
#define    CS4      13
#define    END1     14
#define    END2     15
#define    END3     16
#define    END4     17

//-----------------------  data  format  -----------------------
//     h1   h2   l1    l2   d   d   d  ...  d   d   cs1   cs2
//   |0x55|0xAA| L1  | L0 | ..| ..| ..| ..| ..| ..| cs1 | cs2|
//   |  header | data len |data:len=(L1<<8) + L0  | check sum|
//   Max data length is 64 bytes
//--------------------------------------------------------------
#define HEADEnd     HEAD2
#define LENEnd      LEN2
#define CSEnd       CS2
#define End         CSEnd
#undef head1
#define head1       0x55
#undef head2
#define head2       0xAA
#define MSB_LEN     1

void process_data(uint8_t data)
{
    static uint8_t state = IDLE;
    static uint8_t buffer[DATA_MAX_LEN];
    static uint32_t len = 0;
    static uint32_t bufIndex = 0;
    static uint32_t cal_cs = 0;
#if (CSEnd > CS1)
    static uint32_t cs = 0;
#endif
#if End > END1
    static uint32_t end = 0;
#endif
#if NEED_TIMER
    if(is_timeout()) state = IDLE;
#endif
    cal_cs += data;
    switch(state){
        case IDLE:  // IDLE
            len = 0;
            bufIndex = 0;
            if(data == head1) {
                cal_cs = data;
                state = HEAD1;
#if NEED_TIMER
                start_timer();
#endif
            }
            break;
#if HEADEnd > HEAD1
        case HEAD1: // HEAD1
            if(data == head2) {state = HEAD2;}
            else {state = IDLE;}
            break;
#if HEADEnd > HEAD2
        case HEAD2: // HEAD2
            if(data == head3) {state = HEAD3;}
            else {state = IDLE;}
            break;       
#if HEADEnd > HEAD3
        case HEAD3: // HEAD3
            if(data == head4) {state = HEAD4;}
            else {state = IDLE;}
            break;
#if HEADEnd > HEAD4
        case HEAD4: // HEAD4
#error wrong head count
#endif // HEADEnd > HEAD4
#endif // HEADEnd > HEAD3
#endif // HEADEnd > HEAD2
#endif // HEADEnd > HEAD1
        
        case HEADEnd: // HEADEnd
            len = data;
            state = LEN1;
            break;
#if LENEnd > LEN1
        case LEN1:  // LEN1
#if MSB_LEN
            len = (len<<8) + data;
#else
            len = len + (data<<8);
#endif
            state = LEN2;
            break;
#if LENEnd > LEN2
        case LEN2:  // LEN2
#if MSB_LEN
            len = (len<<8) + data;
#else
            len = len + (data<<16);
#endif
            state = LEN3;
            break;
#if LENEnd > LEN3
        case LEN3:  // LEN3
#if MSB_LEN
            len = (len<<8) + data;
#else
            len = len + (data<<24);
#endif
            state = LEN4;
            break;
#if LENEnd > LEN4
        case LEN4:  // LEN4
#error wrong data length count
#endif
#endif
#endif
#endif
        case LENEnd: // LENEnd
            state = DATA;
            bufIndex = 0;
            buffer[bufIndex++] = data;
            break;
        case DATA:  // DATA
            if(bufIndex<len){
                buffer[bufIndex++] = data;
                break;
            }
            state = CS1;
            cal_cs -= data;
            cs = data;
            break;
#if CSEnd > CS1
         case CS1: // CS1
            state = CS2;
            cal_cs -= data;
            cs = (cs << 8) + data;
            break;
#if CSEnd > CS2
         case CS2: // CS2
            state = CS3;
            cal_cs -= data;
            cs = (cs<<8) + data;
            break;
#if CSEnd > CS3
         case CS3: // CS3
            state = CS4;
            cal_cs -= data;
            cs = (cs<<8) + data;
            break;
#if CSEnd > CS4
         case CS4: // CS4
#wrong cs count
#endif
#endif
#endif
#endif
#if End > CSEnd
         case CSEnd: // CSEnd
            state = END1;
            end = data;
            cal_cs -= data;
            break;
#endif
#if End > END1
         case END1: // END1
            end = (end<<8) + data;
            state = END2;
            cal_cs -= data;
            break;
#if End > END2
         case END2: // END2
            end = (end<<8) + data;
            state = END3;
            cal_cs -= data;
            break;
#if End > END3
         case END3: // END3
            end = (end<<8) + data;
            state = END4;
            cal_cs -= data;
            break;
#if End > END4
         case END4: // END4
#error wrong end count
#endif
#endif
#endif
#endif
    }
    if(LENEnd == state && len > DATA_MAX_LEN){
        state = IDLE;
    }
    if(End == state){
#define CS_MASK   ((1 << ((CSEnd - CS1 + 1)*8)) - 1)

#if 0
        uint32_t i;
        cal_cs = 0
#if HEADEnd > (HEAD1-1)
        + head1
#if HEADEnd > HEAD1
        + head2
#if HEADEnd > HEAD2
        + head3
#if HEADEnd > HEAD3
        + head4
#endif
#endif
#endif
#endif
#if LENEnd > (LEN1-1)
        + ( (len>>0) & 0xff )
#if LENEnd > LEN1
        + ( (len>>8) & 0xff )
#if LENEnd > LEN2
        + ( (len>>16) & 0xff )
#if LENEnd > LEN3
        + ( (len>>24) & 0xff )
#endif
#endif
#endif
#endif
        ;
        for(i=0;i<len;i++){
            cal_cs += buffer[i];
        }
#endif // if 0
        state = IDLE;
        // check the data
#if NEED_TIMER
        stop_timer();
#endif
        if( (cal_cs & CS_MASK)  == cs)
            data_ready(buffer,len);
    }
}
