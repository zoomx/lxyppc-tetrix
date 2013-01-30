#include "bsp.h"

static __IO uint32_t delay_ms_count = 0;
static uint32_t tick_per_us = 72;

void delay_ms(uint32_t ms)
{
    delay_ms_count = ms;
    while(delay_ms_count);
}

void delay_us(uint32_t usec)
{
  uint32_t count = 0;
  const uint32_t utime = (120 * usec / 7);
  do
  {
    if ( ++count > utime )
    {
      return ;
    }
  }
  while (1);
}

void enable_tick_count(void)
{
    RCC_ClocksTypeDef RCC_Clocks;
    RCC_GetClocksFreq(&RCC_Clocks);
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
    tick_per_us = RCC_Clocks.SYSCLK_Frequency/1000000;
}

uint32_t get_tick_count(void)
{
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
    return DWT->CYCCNT;
}

uint32_t current_us(void)
{
    return get_tick_count()/tick_per_us;
}

// setup systick to 1000 HZ
void setup_systick(void)
{
    RCC_ClocksTypeDef RCC_Clocks;
    RCC_GetClocksFreq(&RCC_Clocks);
    SysTick_Config(RCC_Clocks.HCLK_Frequency / 1000);
    //SysTick_Config(72000000 / 1000);
}

extern __IO uint32_t USBConnectTimeOut;

static uint32_t frame_counter;
uint8_t frame_20Hz = 0;
uint8_t frame_50Hz = 0;
uint8_t frame_100Hz = 0;
uint8_t frame_200Hz = 0;
uint8_t frame_1Hz = 0;
void SysTick_Handler(void)
{
    frame_counter++;
    if(frame_counter > 1000)
    {  
        frame_1Hz = 1;
        frame_counter = 1;
    }
    
    if(frame_counter % 5 == 0){
        // 200 Hz
        frame_200Hz = 1;
    }
    
    if(frame_counter % 10 == 0){
        // 100 Hz
        frame_100Hz = 1;
    }
    
    if(frame_counter % 20 == 0){
        // 50 Hz
        frame_50Hz = 1;
    }
    
    if(frame_counter % 50 == 0){
        // 20 Hz
        frame_20Hz = 1;
    }
    
    if(delay_ms_count){
        delay_ms_count--;
    }
    
    if(USBConnectTimeOut){
        USBConnectTimeOut--;
    }
    
}


