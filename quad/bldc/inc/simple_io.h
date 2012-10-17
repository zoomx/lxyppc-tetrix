#ifndef SIMPLE_IO_H
#define SIMPLE_IO_H
#include "stdint.h"

// init i2c address config
void init_addr_config(void);
// init led 
void init_led(void);

// get current i2c address
uint8_t get_addr_value(void);

// set led bright, valid value [0~100]
void adj_led(uint8_t led1, uint8_t led2);

// TP2 is used by TIM1 CH4 to trigger the ADC
void init_tps(void);

#define TP1_SET         do{GPIOB->BSRR |= GPIO_Pin_2;}while(0)
#define TP1_RESET       do{GPIOB->BRR |= GPIO_Pin_2;}while(0)
#define TP1_TOGGLE      do{if(GPIOB->ODR & GPIO_Pin_2)TP1_SET;else TP1_RESET; }while(0)

#define TP2_SET         do{GPIOA->BSRR |= GPIO_Pin_11;}while(0)
#define TP2_RESET       do{GPIOA->BRR |= GPIO_Pin_11;}while(0)
#define TP2_TOGGLE      do{if(GPIOA->ODR & GPIO_Pin_11)TP2_SET;else TP2_RESET; }while(0)

#define TP3_SET         do{GPIOA->BSRR |= GPIO_Pin_12;}while(0)
#define TP3_RESET       do{GPIOA->BRR |= GPIO_Pin_12;}while(0)
#define TP3_TOGGLE      do{static uint8_t x=0;if(x++&1)TP3_SET;else TP3_RESET; }while(0)

#endif
