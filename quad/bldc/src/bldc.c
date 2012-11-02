#include "bldc.h"
#include "pwm.h"
#include "stm32f0xx.h"
#include "adc.h"
#include "simple_io.h"

#define  C5_Tone     523         // C5 tone freq
#define  Cs5_Tone     554         // Cs5 tone freq
#define  D5_Tone     587         // D5 tone freq
#define  Ds5_Tone     622         // Ds5 tone freq
#define  E5_Tone     659         // E5 tone freq
#define  F5_Tone     698         // F5 tone freq
#define  Fs5_Tone     740         // Fs5 tone freq
#define  G5_Tone     784         // G5 tone freq
#define  Gs5_Tone     831         // Gs5 tone freq
#define  A5_Tone     880         // A5 tone freq
#define  As5_Tone     932         // As5 tone freq
#define  B5_Tone     988         // B5 tone freq
#define  C6_Tone     1047         // C6 tone freq
#define  Cs6_Tone     1109         // Cs6 tone freq
#define  D6_Tone     1175         // D6 tone freq
#define  Ds6_Tone     1245         // Ds6 tone freq
#define  E6_Tone     1319         // E6 tone freq
#define  F6_Tone     1397         // F6 tone freq
#define  Fs6_Tone     1480         // Fs6 tone freq
#define  G6_Tone     1568         // G6 tone freq
#define  Gs6_Tone     1661         // Gs6 tone freq
#define  A6_Tone     1760         // A6 tone freq
#define  As6_Tone     1865         // As6 tone freq
#define  B6_Tone     1976         // B6 tone freq
#define  C7_Tone     2093         // C7 tone freq

uint8_t mosfet_test_step = 1;

// 10K Hz PWM, can smaple 100 time in one period @ 1MHz
uint16_t adc_buffer_for_mosfet_test[128];
#define ADC1_DR_Address    ((uint32_t)(ADC1_BASE + 0x40))//0x40012440

void gather_adc_values(void)
{
    static uint8_t last_step = 0;
    // TIM1 CC4 occuer
    adc_buffer_for_mosfet_test[126] = DMA1_Channel1->CNDTR;
    TP3_SET;
    ADC_StopOfConversion(ADC1);
    ADC_DMACmd(ADC1, DISABLE);
    // reset the DMA
    DMA_Cmd(DMA1_Channel1, DISABLE);
    //DMA_DeInit(DMA1_Channel1);
    
    DMA_ClearFlag(DMA1_FLAG_GL1);

//     DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)ADC1_DR_Address;
//     DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)adc_buffer_for_mosfet_test;
//     DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
//     DMA_InitStructure.DMA_BufferSize = 25;
//     DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
//     DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
//     DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
//     DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
//     DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
//     DMA_InitStructure.DMA_Priority = DMA_Priority_High;
//     DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    //DMA_Init(DMA1_Channel1, &DMA_InitStructure);
    DMA1_Channel1->CNDTR = 50;
    
    adc_buffer_for_mosfet_test[127] = ADC1->DR;
    DMA_Cmd(DMA1_Channel1, ENABLE);
    ADC_DMACmd(ADC1, ENABLE);
    
    ADC_StartOfConversion(ADC1);
    adc_buffer_for_mosfet_test[127] = DMA1_Channel1->CNDTR;
    
    if(last_step == mosfet_test_step){
        if(mosfet_test_step == 1){
            adc_buffer_for_mosfet_test[50] = adc_buffer_for_mosfet_test[0];
            adc_buffer_for_mosfet_test[51] = adc_buffer_for_mosfet_test[1];
            adc_buffer_for_mosfet_test[52] = adc_buffer_for_mosfet_test[2];
        }else{
            adc_buffer_for_mosfet_test[100] = adc_buffer_for_mosfet_test[0];
            adc_buffer_for_mosfet_test[101] = adc_buffer_for_mosfet_test[1];
            adc_buffer_for_mosfet_test[102] = adc_buffer_for_mosfet_test[2];
        }
    }
    last_step = mosfet_test_step;
    TP3_RESET;
}

void mosfet_test_update_phase(void)
{
    switch(mosfet_test_step){
        case 1:
            update_pwm(A_B);
            mosfet_test_step = 2;
            break;
        case 2:
            update_pwm(OFF,OFF,OFF);
            mosfet_test_step = 1;
            break;
        case 3:
            update_pwm(B_C);
            mosfet_test_step = 4;
            break;
        case 4:
            update_pwm(OFF,OFF,OFF);
            mosfet_test_step = 3;
            break;
        case 5:
            update_pwm(C_A);
            mosfet_test_step = 6;
            break;
        case 6:
            update_pwm(OFF,OFF,OFF);
            mosfet_test_step = 5;
            break;
    }
}


void initial_adc_dma_for_mosfet_test(void)
{
    DMA_InitTypeDef     DMA_InitStructure;
    
    // Set the TIM1 Trgo as the ADC trigger
    ADC1->CFGR1 |= ADC_ExternalTrigConvEdge_Rising;
    ADC1->CFGR1 &= ~ADC_ExternalTrigConv_T1_CC4;
    ADC1->CFGR1 |= ADC_ExternalTrigConv_T1_TRGO;
    
    ADC_ITConfig(ADC1, ADC_IT_EOSEQ, DISABLE);
    // Continuous mode
    // When tim1 update trigger the convert
    ADC_ContinuousModeCmd(ADC1, ENABLE);
    // Reconfig ADC DMA buffer
    DMA_DeInit(DMA1_Channel1);
    
    ADC_DMARequestModeConfig(ADC1, ADC_DMAMode_OneShot);

    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)ADC1_DR_Address;
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)adc_buffer_for_mosfet_test;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
    DMA_InitStructure.DMA_BufferSize = 50;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(DMA1_Channel1, &DMA_InitStructure);
    
    DMA_Cmd(DMA1_Channel1, ENABLE);
}

// Test the mosfet
void mosfet_start_up_test(void)
{
    on_tim1_cc4 = gather_adc_values;
    TIM_ITConfig(TIM1, TIM_IT_CC4, ENABLE);
    mosfet_test_step = 1;
    // apply the step
    mosfet_test_update_phase();
    // trggier a COM event
    TIM_GenerateEvent(TIM1, TIM_EventSource_COM);
    set_duty(DUTY(10), DUTY(50));   // PWM 10% duty, CC4 20%
    set_phase_update_freq(G5_Tone*2, mosfet_test_update_phase);
    
    initial_adc_dma_for_mosfet_test();
    start_adc(CH_A, ADC_SampleTime_1_5Cycles);
    
    while(1);
}

