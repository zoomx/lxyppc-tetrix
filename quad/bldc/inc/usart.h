#ifndef USART_H
#define USART_H

#include "stm32f0xx.h"
void init_usart_dbg(void);
void init_usart(void);

// Enable the USART2 Tx pin on PA14, this will diable the SWD CLK pin of the chip
void enable_tx_PA14(void);

void disable_tx_PA14(void);

// Send data through the DMA
void send_data(USART_TypeDef* USARTx, const void* p, uint32_t len);

#endif
