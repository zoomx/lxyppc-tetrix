#ifndef __USART_H
#define __USART_H

extern void USART1_SendByte(u16 dat);
extern void USART1Write(u8* data,u16 len);

void USART1_Configuration(void);

#define DIR485_H  GPIOC->BSRR=1<<1
#define DIR485_L  GPIOC->BRR=1<<1 


#endif
