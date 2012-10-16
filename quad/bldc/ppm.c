#include "ppm.h"
#include "stm32f0xx.h"
#include "pwm.h"
#include "ring_buffer.h"

#define TIM2_DMAR_ADDRESS ( (uint32_t)(TIM2_BASE + 0x4C) ) /* TIM DMAR address */
typedef struct _PPM_Data
{
    uint32_t duty;
    uint32_t period;
}PPM_Data;
#define PPM_BUF_CNT 32
#define PPM_MASK  (PPM_BUF_CNT-1)

PPM_Data ppm_buffer[PPM_BUF_CNT] = {0};
uint32_t ppm_rd = 0;
uint32_t ppm_wr = 0;

// Initialize ppm, PPM use PWM input feature of the timer2
//  PB3 (TIM2 CH2) -> PPM input
#define USE_DMA         0
void init_ppm(void)
{
    GPIO_InitTypeDef        GPIO_InitStructure;
    TIM_ICInitTypeDef       TIM_ICInitStructure;
    NVIC_InitTypeDef        NVIC_InitStructure;
    DMA_InitTypeDef         DMA_InitStructure;
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource3, GPIO_AF_2);
 
    TIM_ICInitStructure.TIM_Channel = TIM_Channel_2;
    TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
    TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
    TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
    TIM_ICInitStructure.TIM_ICFilter = 0x0;

    TIM_PWMIConfig(TIM2, &TIM_ICInitStructure);
    
    TIM_SelectInputTrigger(TIM2, TIM_TS_TI2FP2);
    
    /* Select the slave Mode: Reset Mode */
    TIM_SelectSlaveMode(TIM2, TIM_SlaveMode_Reset);
    TIM_SelectMasterSlaveMode(TIM2,TIM_MasterSlaveMode_Enable);
    
    // Slave mode controller can generate a update event
    // We can use the DMA channel 2 for TIM2 up
    // Because in PWM input mode we use the TI2FP2 signal to
    // reset the timer, this is equal to TIM2 CC2 event
    //TIM_UpdateRequestConfig(TIM2, TIM_UpdateSource_Regular);
    
    // Transfer the CCR1 and CCR2 with DMA
#if USE_DMA
    TIM_DMAConfig(TIM2, TIM_DMABase_CCR1, TIM_DMABurstLength_2Transfers);
    DMA_DeInit(DMA1_Channel2);
    
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)TIM2_DMAR_ADDRESS;
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)ppm_buffer;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;  
    DMA_InitStructure.DMA_BufferSize = PPM_BUF_CNT*2;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_PeripheralDataSize_Word;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
    DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
    
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(DMA1_Channel2, &DMA_InitStructure);
    
    TIM_DMACmd(TIM2, TIM_DMA_Update, ENABLE);
    DMA_Cmd(DMA1_Channel2, ENABLE);
    (void)NVIC_InitStructure;
    // actual PPM value should solve in the systick
#else
    /* Enable the TIM2 global Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    /* Enable the CC2 Interrupt Request */
    TIM_ITConfig(TIM2, TIM_IT_CC2, ENABLE);
    
    (void)DMA_InitStructure;
#endif
    /* TIM enable counter */
    TIM_Cmd(TIM2, ENABLE);
}


#define  PPM_MAX_PERIOD_CNT         (SYSTEM_FREQ/ (1000000ul/PPM_MAX_PERIOD))
#define  PPM_IDLE_CNT                (SYSTEM_FREQ/ (1000000ul/PPM_IDLE))

uint32_t ppm_values[16];
uint32_t ppm_idx = 0xffff;
uint32_t ppm_cnt = 0;
uint32_t ppm_gaps[32];
uint32_t ppm_idx2 = 0;
// TIM2 IRQ handler, used to capture the PPM signal
void TIM2_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM2, TIM_IT_CC2) == SET) 
    {
        uint32_t period = TIM2->CCR2;
        uint32_t duty = TIM2->CCR1;
        TIM_ClearITPendingBit(TIM2, TIM_IT_CC2);
        if(duty > PPM_MAX_PERIOD_CNT){
            if(ppm_idx<16)ppm_cnt = ppm_idx;
            ppm_idx = 0;
        }else{
            if(ppm_idx<16){
                //ppm_gaps[ppm_idx2++ & 31] = (period-duty)/48;
                //duty = duty /48; // to us
                ppm_values[ppm_idx & 15] = duty;
                ppm_idx++;
            }
        }
        /* Clear TIM2 Capture compare interrupt pending bit */
      
        //ppm_buffer[ppm_wr & PPM_MASK].period = TIM2->CCR2;
        //ppm_buffer[ppm_wr & PPM_MASK].duty = TIM2->CCR1;
        //ppm_wr++;
    }
}

uint32_t get_ppm(void* buf, uint32_t cnt)
{
    if(cnt>ppm_cnt)cnt = ppm_cnt;
    if(cnt>16)cnt = 16;
    mymemcpy(buf,ppm_values,cnt*4);
    return cnt;
}
