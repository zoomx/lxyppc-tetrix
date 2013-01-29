
#ifndef ADC_H
#define ADC_H
#include "stm32f10x.h"
#include "stdint.h"
///////////////////////////////////////////////////////////////////////////////

void adc_init(void);
uint16_t adc_get_value(uint32_t channel);
uint32_t get_battery(void);

#endif
