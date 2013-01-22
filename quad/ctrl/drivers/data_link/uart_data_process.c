#include "uart_data_process.h"

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

void uart_process_init(uart_process_t* process, uint8_t* buffer, uint32_t buffer_size, void* context)
{
    process->state = IDLE;
    process->buffer = buffer;
    process->buffer_size = buffer_size;
    process->len = 0;
    process->bufIndex = 0;
    process->cal_cs = 0;
#if (CSEnd > CS1)
    process->cs = 0;
#endif
#if End > END1
    process->end = 0;
#endif
    process->context = context;
}

void uart_process_data(uart_process_t* process, uint8_t data)
{
    //static uint8_t state = IDLE;
    //static uint8_t buffer[DATA_MAX_LEN];
    //static uint32_t len = 0;
    //static uint32_t bufIndex = 0;
    //static uint32_t cal_cs = 0;
#if (CSEnd > CS1)
    //static uint32_t cs = 0;
#endif
#if End > END1
    //static uint32_t end = 0;
#endif
#if NEED_TIMER
    if(is_timeout()) process->state = IDLE;
#endif
    process->cal_cs += data;
    switch(process->state){
        case IDLE:  // IDLE
            process->len = 0;
            process->bufIndex = 0;
            if(data == head1) {
                process->cal_cs = data;
                process->state = HEAD1;
#if NEED_TIMER
                start_timer();
#endif
            }
            break;
#if HEADEnd > HEAD1
        case HEAD1: // HEAD1
            if(data == head2) {process->state = HEAD2;}
            else {process->state = IDLE;}
            break;
#if HEADEnd > HEAD2
        case HEAD2: // HEAD2
            if(data == head3) {process->state = HEAD3;}
            else {process->state = IDLE;}
            break;       
#if HEADEnd > HEAD3
        case HEAD3: // HEAD3
            if(data == head4) {process->state = HEAD4;}
            else {process->state = IDLE;}
            break;
#if HEADEnd > HEAD4
        case HEAD4: // HEAD4
#error wrong head count
#endif // HEADEnd > HEAD4
#endif // HEADEnd > HEAD3
#endif // HEADEnd > HEAD2
#endif // HEADEnd > HEAD1
        
        case HEADEnd: // HEADEnd
            process->len = data;
            process->state = LEN1;
            break;
#if LENEnd > LEN1
        case LEN1:  // LEN1
#if MSB_LEN
            process->len = (process->len<<8) + data;
#else
            process->len = process->len + (data<<8);
#endif
            process->state = LEN2;
            break;
#if LENEnd > LEN2
        case LEN2:  // LEN2
#if MSB_LEN
            process->len = (process->len<<8) + data;
#else
            process->len = process->len + (process->data<<16);
#endif
            process->state = LEN3;
            break;
#if LENEnd > LEN3
        case LEN3:  // LEN3
#if MSB_LEN
            process->len = (process->len<<8) + data;
#else
            process->len = process->len + (data<<24);
#endif
            process->state = LEN4;
            break;
#if LENEnd > LEN4
        case LEN4:  // LEN4
#error wrong data length count
#endif
#endif
#endif
#endif
        case LENEnd: // LENEnd
            process->state = DATA;
            process->bufIndex = 0;
            process->buffer[process->bufIndex++] = data;
            break;
        case DATA:  // DATA
            if(process->bufIndex<process->len){
                process->buffer[process->bufIndex++] = data;
                break;
            }
            process->state = CS1;
            process->cal_cs -= data;
            process->cs = data;
            break;
#if CSEnd > CS1
         case CS1: // CS1
            process->state = CS2;
            process->cal_cs -= data;
            process->cs = (process->cs << 8) + data;
            break;
#if CSEnd > CS2
         case CS2: // CS2
            process->state = CS3;
            process->cal_cs -= data;
            process->cs = (process->cs<<8) + data;
            break;
#if CSEnd > CS3
         case CS3: // CS3
            process->state = CS4;
            process->cal_cs -= data;
            process->cs = (process->cs<<8) + data;
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
            process->state = END1;
            process->end = data;
            process->cal_cs -= data;
            break;
#endif
#if End > END1
         case END1: // END1
            process->end = (process->end<<8) + data;
            process->state = END2;
            process->cal_cs -= data;
            break;
#if End > END2
         case END2: // END2
            process->end = (process->end<<8) + data;
            process->state = END3;
            process->cal_cs -= data;
            break;
#if End > END3
         case END3: // END3
            process->end = (process->end<<8) + data;
            process->state = END4;
            process->cal_cs -= data;
            break;
#if End > END4
         case END4: // END4
#error wrong end count
#endif
#endif
#endif
#endif
    }
    if(LENEnd == process->state && process->len > process->buffer_size){
        process->state = IDLE;
    }
    if(End == process->state){
#define CS_MASK   ((1 << ((CSEnd - CS1 + 1)*8)) - 1)

#if 0
        uint32_t i;
        process->cal_cs = 0
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
        + ( (process->len>>0) & 0xff )
#if LENEnd > LEN1
        + ( (process->len>>8) & 0xff )
#if LENEnd > LEN2
        + ( (process->len>>16) & 0xff )
#if LENEnd > LEN3
        + ( (process->len>>24) & 0xff )
#endif
#endif
#endif
#endif
        ;
        for(i=0;i<process->len;i++){
            process->cal_cs += process->buffer[i];
        }
#endif // if 0
        process->state = IDLE;
        // check the data
#if NEED_TIMER
        stop_timer();
#endif
        if( (process->cal_cs & CS_MASK)  == process->cs)
            uart_data_ready(process->buffer,process->len,process->context);
    }
}
