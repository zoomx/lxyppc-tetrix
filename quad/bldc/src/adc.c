#include "adc.h"
#include "stm32f0xx.h"
#include "ring_buffer.h"

#define ADC1_DR_Address    ((uint32_t)(ADC1_BASE + 0x40))//0x40012440
#define ADC_BUF_LEN 32
#define ADC_BUF_MASK (ADC_BUF_LEN - 1)

static uint32_t adc_index = 0;
static uint32_t adc_length = 0;
static uint16_t adc_buffer[ADC_BUF_LEN];

static __IO uint8_t ad_done = 0;


// initialize the ADC
void init_adc(void)
{
    ADC_InitTypeDef     ADC_InitStructure;
    GPIO_InitTypeDef    GPIO_InitStructure;
    DMA_InitTypeDef     DMA_InitStructure;
    NVIC_InitTypeDef    NVIC_InitStructure;
    
    /* Configure ADC Channel11 as analog input */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | 
            GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    ADC_StructInit(&ADC_InitStructure);
    /* Configure the ADC1 in continous mode withe a resolutuion equal to 12 bits  */
    ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
    ADC_InitStructure.ADC_ContinuousConvMode = DISABLE; 
    ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC4;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_ScanDirection = ADC_ScanDirection_Backward;
    ADC_Init(ADC1, &ADC_InitStructure);
    
    DMA_DeInit(DMA1_Channel1);

    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)ADC1_DR_Address;
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)adc_buffer;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
    DMA_InitStructure.DMA_BufferSize = ADC_BUF_LEN;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(DMA1_Channel1, &DMA_InitStructure);
    
    DMA_Cmd(DMA1_Channel1, ENABLE);
    
    ADC_ChannelConfig(ADC1, ALL_ADC_CH , ADC_SampleTime_55_5Cycles);
    //ADC_ChannelConfig(ADC1, CH_A , ADC_SampleTime_55_5Cycles);
    
    ADC_VrefintCmd(ENABLE);
    ADC_TempSensorCmd(ENABLE);
    
    ADC_DMARequestModeConfig(ADC1, ADC_DMAMode_Circular);
    
    ADC_GetCalibrationFactor(ADC1);
    
    ADC_DMACmd(ADC1, ENABLE);
    
    NVIC_InitStructure.NVIC_IRQChannel = ADC1_COMP_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    ADC_ITConfig(ADC1, ADC_IT_EOSEQ, ENABLE);
    
    ADC_Cmd(ADC1, ENABLE);
    
    while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_ADEN)); 
    
    // start the ADC, because external trigger is set
    // ADC will not start right now
    //ADC_StartOfConversion(ADC1);
}
void on_bldc(void);
void ADC1_COMP_IRQHandler(void)
{
    if(ADC_GetITStatus(ADC1,ADC_IT_EOSEQ) == SET){
        ADC_ClearITPendingBit(ADC1,ADC_IT_EOSEQ);
        // process the ADC data
        ad_done = 1;
        on_bldc();
    }
}

#define MAX_AD_CH  18
static uint32_t get_channel_count(uint32_t ch)
{
    uint32_t cnt = 0;
    for(;ch;ch>>=1){
        cnt += ch & 1;
    }
    return cnt;
}

void start_adc(uint32_t channel, uint32_t sample_time)
{
    //while(ADC_GetFlagStatus(ADC1,ADC_FLAG_ADSTART));
    ad_done = 0;
    adc_length = get_channel_count(channel);
    //ADC_ChannelConfig(ADC1, channel , sample_time);
    ADC1->CHSELR = channel;
    ADC1->SMPR = sample_time ;
    ADC_StartOfConversion(ADC1);
}

int is_adc_done(void)
{
    return ad_done;
}

int get_adc_value(uint16_t* buf, uint32_t len)
{
    uint32_t value_cnt = 0;
    for(;len && adc_length;len--){
        buf[value_cnt] = adc_buffer[adc_index & ADC_BUF_MASK];
        adc_buffer[adc_index & ADC_BUF_MASK] = 0xffff;
        adc_index++;
        value_cnt++;
        adc_length--;
    }
    while(adc_length){
        adc_length--;
        adc_index++;
    }
    return value_cnt;
}

uint16_t get_refint_cal(void)
{
    // refer to STM32F051 datasheet 3.10.2
    return *((__IO uint16_t*) 0x1ffff7ba);
}

uint16_t get_temp_30_cal(void)
{
    // refer to STM32F051 datasheet 3.10.1
    return *((__IO uint16_t*) 0x1ffff7b8);
}

uint16_t get_temp_110_cal(void)
{
    // refer to STM32F051 datasheet 3.10.1
    return *((__IO uint16_t*) 0x1ffff7C2);
}
