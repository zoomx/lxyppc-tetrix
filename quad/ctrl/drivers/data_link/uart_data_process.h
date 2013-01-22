#ifndef UART_DATA_PROCESS_H
#define UART_DATA_PROCESS_H

#include "stdint.h"

#ifndef DATA_MAX_LEN
#define DATA_MAX_LEN  64
#endif
#ifndef NEED_TIMER
#define NEED_TIMER 0
#endif

typedef struct uart_process_t
{
    uint8_t* buffer;
    uint32_t buffer_size;
    uint32_t len;
    uint32_t bufIndex;
    uint32_t cal_cs;
    uint32_t cs;
    uint32_t end;
    void* context;
    uint8_t state;
    uint8_t txBusy;
}uart_process_t;

void uart_process_init(uart_process_t* process, uint8_t* buffer, uint32_t buffer_size, void* context);
void uart_process_data(uart_process_t* process, uint8_t data);
void uart_data_ready(const void* pData, uint32_t len, void* context);
uint32_t uart_pack_data(const void* pData, uint32_t len, void* packed, uint32_t pack_len);

// return value: 0:     not timeout
//               non 0: timeout
int dp_is_timeout(void) __attribute__((weak));
void dp_start_timer(void) __attribute__((weak));
void dp_stop_timer(void) __attribute__((weak));

#endif
