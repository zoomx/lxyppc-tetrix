#ifndef DATA_PROCESS_H
#define DATA_PROCESS_H

#include "stdint.h"

#define DATA_MAX_LEN  64
#define NEED_TIMER 0

void process_data(uint8_t data);
void data_ready(const void* pData, uint32_t len) __attribute__((weak));

// return value: 0:     not timeout
//               non 0: timeout
int dp_is_timeout(void) __attribute__((weak));
void dp_start_timer(void) __attribute__((weak));
void dp_stop_timer(void) __attribute__((weak));

#endif
