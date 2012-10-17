#ifndef ADC_H
#define ADC_H
#include "stdint.h"
#include "stm32f0xx_adc.h"
void init_adc(void);

void start_adc(uint32_t channel, uint32_t sample_time);

int is_adc_done(void);
int get_adc_value(uint16_t* buf, uint32_t len);
uint16_t get_refint_cal(void);
uint16_t get_temp_30_cal(void);
uint16_t get_temp_110_cal(void);

#define  CH_BAT     ADC_Channel_0
#define  CH_IREF    ADC_Channel_1
#define  CH_A       ADC_Channel_2
#define  CH_N       ADC_Channel_3
#define  CH_B       ADC_Channel_4
#define  CH_C       ADC_Channel_5
#define  CH_TEMP    ADC_Channel_6

#define ALL_ADC_CH      \
    (CH_BAT | CH_IREF | CH_A | CH_B \
    | CH_C | CH_N | CH_TEMP | ADC_Channel_TempSensor | ADC_Channel_Vrefint)

#endif
