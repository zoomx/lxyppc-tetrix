/**
  ******************************************************************************
  * @file    Project/STM32F0xx_StdPeriph_Templates/main.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    18-May-2012
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "data_process.h"
#include "string.h"
#include "ring_buffer.h"
#include "usart.h"
#include "simple_io.h"
#include "adc.h"
#include "pwm.h"
#include "ppm.h"
#include "i2c.h"
#include "stdlib.h"
#include "string.h"
#include "bldc.h"

/** @addtogroup Template_Project
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
//USART_InitTypeDef USART_InitStructure;
static __IO uint32_t TimingDelay;
RCC_ClocksTypeDef RCC_Clocks;

DECLRAE_RING_BUFFER(cmd_buffer,8,16)

uint8_t errorCode = ERR_NONE;
/* Private functions ---------------------------------------------------------*/
void init_clocks(void);
void io_test(void);
int startup_test(void);
void display_volt(uint32_t v3v3, uint32_t vbat);
void output_string(const char* str);
void start_bldc(uint16_t duty, uint16_t cc4_duty);
void stop_bldc(void);
int is_bldc_running(void);
uint8_t get_test_data(uint8_t idx, uint8_t len, uint8_t* buf);
uint8_t test_data_phase = 3;
uint8_t test_data_ready = 0;

//void send_data(USART_TypeDef* USARTx, const void* p, uint32_t len);

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
  
static USART_TypeDef* USARTx = USART1;
int main(void)
{
  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f0xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f0xx.c file
     */ 
    uint8_t buf[32];
    RCC_GetClocksFreq(&RCC_Clocks); // Check the clock freqs
    ring_buf_init(cmd_buffer);
    init_clocks();
    /* SysTick end of count event each 10ms */
    SysTick_Config(RCC_Clocks.HCLK_Frequency / 100);
    init_addr_config();
    init_led();
    init_ppm();
    init_i2c();
    //init_usart();
    init_usart_dbg();
    init_adc();
    init_pwm();
    io_test();
    init_tps();
    adj_led(0, 0);
    mosfet_start_up_test();
    
    errorCode = ERR_NONE;
    //startup_test();
    
    while(errorCode){
        uint32_t x;
        adj_led(0xff, 7);
        for(x=0xfffff;x--;);
        adj_led(0xff, 0);
        for(x=0xfffff;x--;);
    }
    adj_led(99, 0);
    
	while(1){
        uint8_t need_test_data = 0;
        if(ring_buf_pop(cmd_buffer,buf,ring_buffer_size(cmd_buffer))){
            // command from I2C and USART will push into the cmd_buffer
            uint32_t len = 8;
            //USART_SendData(USART1, buf[0]);
            //*((__IO uint16_t*)USART1_TDR_ADDRESS) = buf[0];
            switch(buf[0]){
                case CMD_LED:
                    adj_led(buf[1],buf[2]);
                    break;
                case CMD_I2C_ADD:
                    buf[1] = get_i2c_addr();
                    break;
                case CMD_ADC_ALL:
                    if(is_bldc_running()){
                        buf[1] = 0;
                        break;
                    }
                    start_adc(ALL_ADC_CH, ADC_SampleTime_55_5Cycles);
                    //ADC_StartOfConversion(ADC1);
                    while(!is_adc_done());
                    buf[1] = get_adc_value((uint16_t*)(buf+2), 10);
                    len = buf[1]*2 + 2;
                    break;
                case CMD_ADC_SINGLE:
                    if(is_bldc_running()){
                        buf[1] = 0;
                        break;
                    }
                    start_adc(1<<buf[1], ADC_SampleTime_55_5Cycles);
                    //ADC_StartOfConversion(ADC1);
                    while(!is_adc_done());
                    buf[1] = get_adc_value((uint16_t*)(buf+2), 10);
                    len = buf[1]*2 + 2;
                    break;
                case CMD_GET_CAL:
                    *((uint16_t*)(buf+2)) = get_refint_cal();
                    *((uint16_t*)(buf+4)) = get_temp_30_cal();
                    *((uint16_t*)(buf+6)) = get_temp_110_cal();
                    break;
                case CMD_SET_PWM:
                    pwm_force_output(buf[1],buf[2],buf[3]);
                    set_duty(*((uint16_t*) (buf+4)), *((uint16_t*) (buf+6)));
                    break;
                case CMD_START_BLDC:
                    // Start open loop PWM output
                    if(buf[1]){
                        if(is_bldc_running()){
                            set_update_rate(*((uint16_t*)(buf+2)));
                            set_duty(*((uint16_t*) (buf+4)), *((uint16_t*) (buf+6)));
                        }else{
                            // setup callback, disable timer 15
                            set_phase_update_freq(0, switch_phase_6_step);
                            TIM15->ARR = *((uint16_t*)(buf+2));
                            //set_duty(*((uint16_t*) (buf+4)));
                            //TIM_Cmd(TIM15, ENABLE);
                            start_bldc(*((uint16_t*) (buf+4)),*((uint16_t*) (buf+6)));
                        }
                    }else{
                        stop_bldc();
                        //TIM_Cmd(TIM15, DISABLE);
                        //pwm_force_output(OFF,OFF,OFF);
                    }
                    break;
                case CMD_GET_PPM:
                    // get PPM values
                    buf[1] = get_ppm(buf+2,buf[1]);
                    len = buf[1]*4+2;
                    break;
                case CMD_ENABLE_TX:
                    enable_tx_PA14();
                    USARTx = USART2;
                    break;
                case CMD_DISABLE_TX:
                    disable_tx_PA14();
                    USARTx = USART1;
                    break;
                case CMD_GET_ERROR:
                    buf[1] = errorCode;
                    break;
                case CMD_GET_TEST_DATA:
                    need_test_data = 1;
                    get_test_data(buf[1],buf[2],0);
                    test_data_phase = buf[3];
                    break;
            }
            send_data(USARTx,buf,len);
        }
        if(need_test_data && test_data_ready){
            need_test_data = 0;
            test_data_ready = 0;
            buf[1] = get_test_data(buf[1],buf[2],buf+2);
        }
        //GPIO_SetBits(GPIOB, GPIO_Pin_8);
        //GPIO_ResetBits(GPIOB, GPIO_Pin_8);
        
        //GPIO_SetBits(GPIOF, GPIO_Pin_1 | GPIO_Pin_0);
        //GPIO_ResetBits(GPIOF, GPIO_Pin_1 | GPIO_Pin_0);
        //GPIO_SetBits(GPIOB, GPIO_Pin_0|GPIO_Pin_1);
        //GPIO_ResetBits(GPIOA, GPIO_Pin_7);
        //GPIO_ResetBits(GPIOB, GPIO_Pin_0|GPIO_Pin_1);
    }
}

void init_clocks(void)
{
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOF, ENABLE);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
    
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM15, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1 , ENABLE);
    
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1 , ENABLE);
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
    
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
}

// io test after solder
void io_test(void)
{
    GPIO_InitTypeDef        GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
    
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    //GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
    //GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    //GPIO_SetBits(GPIOA, GPIO_Pin_7);
    //GPIO_SetBits(GPIOB, GPIO_Pin_0|GPIO_Pin_1);
}

#define CHECK_ADC_OFF(v)   (v<0x0f)
#define CHECK_ADC_ON(v)    (v>0x100)

__IO struct {
    uint32_t V3v3;
    uint32_t Vbat;
    uint32_t Va;
    uint32_t Vb;
    uint32_t Vc;
}Voltages;

struct {
    uint16_t ref;
    uint16_t ITemp;
    uint16_t OTemp;
    uint16_t C;
    uint16_t B;
    uint16_t N;
    uint16_t A;
    uint16_t IRef;
    uint16_t bat;
}ADCs;

#define  IS_ON(x)    \
    (ADCs.x > ADCs.bat*2)

#define  IS_OFF(x)   \
    (ADCs.x < 0xf0)

int startup_test(void)
{
    uint16_t batAD,refAD;
    // close PWMs
    pwm_force_output(OFF,OFF,OFF);
    set_duty(0,0);
    // Get internal refer voltage ADC
    //start_adc(ADC_Channel_Vrefint, ADC_SampleTime_55_5Cycles);
    start_adc(ALL_ADC_CH, ADC_SampleTime_55_5Cycles);
    while(!is_adc_done());
    get_adc_value(&ADCs.ref, 9);
    //return;
    refAD = ADCs.ref;
    
    // Calculate STM32 power voltage
    Voltages.V3v3 = get_refint_cal()*3300/refAD; // STM32 power voltage in mV
    
    // Get battery voltage ADC value
    start_adc(ALL_ADC_CH, ADC_SampleTime_55_5Cycles);
    while(!is_adc_done());
    get_adc_value(&ADCs.ref, 9);
    batAD = ADCs.bat;
    
    // Calculate Battery voltage
    Voltages.Vbat = Voltages.V3v3 * batAD / 4095; // Unit is mV
    Voltages.Vbat = Voltages.Vbat * (10000 + 680 ) / 680; // Unit is mV
    
    display_volt(Voltages.V3v3, Voltages.Vbat);
    
    if(Voltages.Vbat < MIN_BAT){
        output_string("Battery too low fail");
        errorCode = ERR_BAT;
        goto end;
    }
    
    set_duty(FULL_DUTY,0); // set PWM to 100%
    
    pwm_force_output(PWM,OFF,OFF); // open A+
    // sample the ADC value of A,b,C channel
    start_adc(ALL_ADC_CH, ADC_SampleTime_55_5Cycles);
    while(!is_adc_done());
    get_adc_value(&ADCs.ref, 9);
    if( IS_ON(A) ){
    }else{
        output_string("Phase A test fail");
        errorCode = ERR_A;
        goto end;
    }
    if( IS_ON(B) ){
    }else{
        output_string("Motor AB break");
        errorCode = ERR_AB;
        goto end;
    }
    if( IS_ON(C) ){
    }else{
        output_string("Motor AC break");
        errorCode = ERR_AC;
        goto end;
    }
    
    
    pwm_force_output(OFF,PWM,OFF); // open B+
    // sample the ADC value of A,b,C channel
    start_adc(ALL_ADC_CH, ADC_SampleTime_55_5Cycles);
    while(!is_adc_done());
    get_adc_value(&ADCs.ref, 9);
    if(IS_ON(B)){
    }else{
        output_string("Phase B test fail");
        errorCode = ERR_B;
        goto end;
    }
    if( IS_ON(A) ){
    }else{
        output_string("Motor AB break");
        errorCode = ERR_AB;
        goto end;
    }
    if( IS_ON(C) ){
    }else{
        output_string("Motor BC break");
        errorCode = ERR_BC;
        goto end;
    }
    
    
    pwm_force_output(OFF,OFF,PWM); // open C+
    // sample the ADC value of A,b,C channel
    start_adc(ALL_ADC_CH, ADC_SampleTime_55_5Cycles);
    while(!is_adc_done());
    get_adc_value(&ADCs.ref, 9);
    if(IS_ON(C) ){
    }else{
        output_string("Phase C test fail");
        errorCode = ERR_C;
        goto end;
    }
    if( IS_ON(A) ){
    }else{
        output_string("Motor AC break");
        errorCode = ERR_AC;
        goto end;
    }
    if( IS_ON(B) ){
    }else{
        output_string("Motor BC break");
        errorCode = ERR_BC;
        goto end;
    }
    
end:
    if(errorCode){
        adj_led(0xff,10);
    }
    pwm_force_output(OFF,OFF,OFF);
    set_duty(0,0);
    return errorCode;
}

void display_volt(uint32_t v3v3, uint32_t vbat)
{
    char buf[64] = "";
    sprintf(buf,"V3v3 %d.%dV, Vbat %d.%dV", Voltages.V3v3/1000,Voltages.V3v3%1000
        ,Voltages.Vbat/1000,Voltages.Vbat%1000);
    
    send_data(USARTx,buf,strlen(buf));
}

void output_string(const char* str)
{
    send_data(USARTx,str,strlen(str));
}


static int g_bldc_running = 0;
uint16_t bldc_dma_buf[4];
#define ADC1_DR_Address    ((uint32_t)(ADC1_BASE + 0x40))//0x40012440


void start_bldc(uint16_t duty, uint16_t cc4_duty)
{
    DMA_InitTypeDef     DMA_InitStructure;
    // Set the PWM duty
    set_duty(duty, cc4_duty);
    
    // Set the TIM1 CC4 as the ADC trigger
    ADC1->CFGR1 |= ADC_ExternalTrigConvEdge_Rising;
    // Reconfig ADC DMA buffer
    DMA_DeInit(DMA1_Channel1);

    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)ADC1_DR_Address;
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)bldc_dma_buf;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
    DMA_InitStructure.DMA_BufferSize = 4;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(DMA1_Channel1, &DMA_InitStructure);
    
    DMA_Cmd(DMA1_Channel1, ENABLE);
    
    // Start ADC
    start_adc(CH_A|CH_B|CH_C|CH_N, ADC_SampleTime_1_5Cycles);
    // enable the tim15
    TIM_Cmd(TIM15, ENABLE);
    g_bldc_running = 1;
}

extern int32_t step;

static struct  test_t{
    uint16_t A;
    uint16_t N;
    uint16_t B;
    uint16_t C;
}phase_test1[128] = {0};
static struct test_t  phase_test2[128] = {0};

struct test_t * phase_test = phase_test1;

uint32_t pidx = 0;
uint32_t max_pidx = 0;
static uint32_t rdCnt = 0;
void on_bldc(void)
{
    if(!g_bldc_running){
        return;
    }
    //if(step == test_data_phase){
        phase_test[pidx & 127].C = bldc_dma_buf[0];
        phase_test[pidx & 127].B = bldc_dma_buf[1];
        phase_test[pidx & 127].N = bldc_dma_buf[2];
        phase_test[pidx & 127].A = bldc_dma_buf[3];
        pidx++;
        max_pidx = pidx;
        rdCnt++;
        if(rdCnt == 128){
            test_data_ready = 1;
            phase_test = phase_test1;
        }
    //}else{
        //pidx = 0;
    //}
}

uint8_t get_test_data(uint8_t idx, uint8_t len, uint8_t* buf)
{
    if(buf){
        send_data(USARTx,&phase_test2[idx].A,len*8);
        return len;
    }else{
        phase_test = phase_test2;
        rdCnt = 0;
    }
    return 0;
}

void stop_bldc(void)
{
    TIM_Cmd(TIM15, DISABLE);
    pwm_force_output(OFF,OFF,OFF);
    ADC1->CFGR1 &= ~ADC_ExternalTrigConvEdge_Rising;
    g_bldc_running = 0;
}


int is_bldc_running(void)
{
    return g_bldc_running;
}

/**
  * @brief  Inserts a delay time.
  * @param  nTime: specifies the delay time length, in 10 ms.
  * @retval None
  */
void Delay(__IO uint32_t nTime)
{
  TimingDelay = nTime;

  while(TimingDelay != 0);
}

/**
  * @brief  Decrements the TimingDelay variable.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
#ifdef USE_CPAL
    SysTick_Handler_i2c();
#endif
    if (TimingDelay != 0x00)
    { 
        TimingDelay--;
    }
    if(0){
        static uint8_t led1 = 0;
        static uint8_t led2 = 0;    
        adj_led(led1,led2);
        led1++;
        led2++;
        if(led1 == 101) led1 = 0;
        if(led2 == 101) led2 = 0;
    }
}


#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
