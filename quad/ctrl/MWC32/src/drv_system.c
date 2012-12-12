/*
  June 2012

  BaseFlightPlus Rev -

  An Open Source STM32 Based Multicopter

  Includes code and/or ideas from:

  1)AeroQuad
  2)BaseFlight
  3)CH Robotics
  4)MultiWii
  5)S.O.H. Madgwick

  Designed to run on Naze32 Flight Control Board

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "board.h"

///////////////////////////////////////////////////////////////////////////////

// Cycle counter stuff - these should be defined by CMSIS, but they aren't
#define DWT_CTRL    (*(volatile uint32_t *)0xE0001000)
#define DWT_CYCCNT  ((volatile uint32_t *)0xE0001004)
#define CYCCNTENA   (1 << 0)

///////////////////////////////////////////////////////////////////////////////

typedef struct gpio_config_t {
    GPIO_TypeDef *gpio;
    uint16_t pin;
    GPIOMode_TypeDef mode;
} gpio_config_t;

///////////////////////////////////////////////////////////////////////////////

// Cycles per microsecond
static volatile uint32_t usTicks = 0;

///////////////////////////////////////////////////////////////////////////////

// Current uptime for 1kHz systick timer. will rollover after 49 days.
// Hopefully we won't care.
static volatile uint32_t sysTickUptime = 0;
static volatile uint32_t sysTickCycleCounter = 0;

///////////////////////////////////////////////////////////////////////////////
// Cycle Counter
///////////////////////////////////////////////////////////////////////////////

static void cycleCounterInit(void)
{
    RCC_ClocksTypeDef clocks;
    RCC_GetClocksFreq(&clocks);
    usTicks = clocks.SYSCLK_Frequency / 1000000;

    // enable DWT access
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
    // enable the CPU cycle counter
    DWT_CTRL |= CYCCNTENA;
}

///////////////////////////////////////
// Frame Timing Variables
///////////////////////////////////////

uint16_t frameCounter = 0;

uint8_t frame_500Hz = false;
uint8_t frame_200Hz = false;
uint8_t frame_100Hz = false;
uint8_t frame_50Hz = false;
uint8_t frame_10Hz = false;
uint8_t frame_5Hz = false;
uint8_t frame_1Hz = false;

uint32_t deltaTime1000Hz, executionTime1000Hz, previous1000HzTime;
uint32_t deltaTime500Hz, executionTime500Hz, previous500HzTime;
uint32_t deltaTime200Hz, executionTime200Hz, previous200HzTime;
uint32_t deltaTime100Hz, executionTime100Hz, previous100HzTime;
uint32_t deltaTime50Hz, executionTime50Hz, previous50HzTime;
uint32_t deltaTime10Hz, executionTime10Hz, previous10HzTime;
uint32_t deltaTime5Hz, executionTime5Hz, previous5HzTime;
uint32_t deltaTime1Hz, executionTime1Hz, previous1HzTime;

float dt500Hz, dt200Hz, dt100Hz;

uint8_t systemReady = false;

///////////////////////////////////////////////////////////////////////////////
// SysTick
///////////////////////////////////////////////////////////////////////////////

void SysTick_Handler(void)
{
    uint8_t index;
    uint32_t currentTime;

    sysTickCycleCounter = *DWT_CYCCNT;
    sysTickUptime++;

#if defined(USE_MADGWICK_AHRS) | defined(USE_MARG_AHRS)
    if ((systemReady == true) &&
    	(accelCalibrating == false) &&
    	(gyroCalibrating == false) &&
    	(magCalibrating == false))
#endif

#if defined(USE_CHR6DM_AHRS)
    if ((systemReady == true) &&
      	(accelCalibrating == false) &&
       	(gyroCalibrating == false) &&
       	(magCalibrating == false) &&
       	(ahrsCalibrating == false))
#endif

        {
            frameCounter++;
            if (frameCounter > FRAME_COUNT)
                frameCounter = 1;

            ///////////////////////////////

            currentTime = micros();
            deltaTime1000Hz = currentTime - previous1000HzTime;
            previous1000HzTime = currentTime;

            readAccel();

#if defined(USE_MADGWICK_AHRS) | defined(USE_MARG_AHRS)
            accelSum200Hz[XAXIS] += rawAccel[XAXIS].value;
            accelSum200Hz[YAXIS] += rawAccel[YAXIS].value;
            accelSum200Hz[ZAXIS] += rawAccel[ZAXIS].value;
#endif

            accelSum100Hz[XAXIS] += rawAccel[XAXIS].value;
            accelSum100Hz[YAXIS] += rawAccel[YAXIS].value;
            accelSum100Hz[ZAXIS] += rawAccel[ZAXIS].value;

            readGyro();

            gyroSum200Hz[ROLL] += rawGyro[ROLL].value;
            gyroSum200Hz[PITCH] += rawGyro[PITCH].value;
            gyroSum200Hz[YAW] += rawGyro[YAW].value;

            gyroSum100Hz[ROLL] += rawGyro[ROLL].value;
            gyroSum100Hz[PITCH] += rawGyro[PITCH].value;
            gyroSum100Hz[YAW] += rawGyro[YAW].value;

            ///////////////////////////////

            if ((frameCounter % COUNT_500HZ) == 0) {
                frame_500Hz = true;

                for (index = 0; index < 3; index++) {
                    gyroSummedSamples500Hz[index] = gyroSum500Hz[index];
                    gyroSum500Hz[index] = 0.0f;
                }
            }
            ///////////////////////////////

            if ((frameCounter % COUNT_200HZ) == 0) {
                frame_200Hz = true;

                for (index = 0; index < 3; index++) {
#if defined(USE_MADGWICK_AHRS) | defined(USE_MARG_AHRS)
                    accelSummedSamples200Hz[index] = accelSum200Hz[index];
                    accelSum200Hz[index] = 0.0f;
#endif

                    gyroSummedSamples200Hz[index] = gyroSum200Hz[index];
                    gyroSum200Hz[index] = 0.0f;
                }
            }
            ///////////////////////////////

            if ((frameCounter % COUNT_100HZ) == 0) {
                frame_100Hz = true;

                for (index = 0; index < 3; index++) {
                    accelSummedSamples100Hz[index] = accelSum100Hz[index];
                    accelSum100Hz[index] = 0.0f;

                    gyroSummedSamples100Hz[index] = gyroSum100Hz[index];
                    gyroSum100Hz[index] = 0.0f;
                }

                if (frameCounter == COUNT_100HZ) {
                    readTemperatureRequestPressure();
                } else if (frameCounter == FRAME_COUNT) {
                    readPressureRequestTemperature();
                } else {
                    readPressureRequestPressure();
                }

                pressureSum += uncompensatedPressure.value;
            }
            ///////////////////////////////

            if (((frameCounter + 1) % COUNT_50HZ) == 0) {
                readMag();
                magSum[XAXIS] += rawMag[XAXIS].value;
                magSum[YAXIS] += rawMag[YAXIS].value;
                magSum[ZAXIS] += rawMag[ZAXIS].value;
            }

            if ((frameCounter % COUNT_50HZ) == 0) {
                frame_50Hz = true;
            }
            ///////////////////////////////

            if ((frameCounter % COUNT_10HZ) == 0)
                frame_10Hz = true;

            ///////////////////////////////

            if ((frameCounter % COUNT_5HZ) == 0)
                frame_5Hz = true;

            ///////////////////////////////

            if ((frameCounter % COUNT_1HZ) == 0)
                frame_1Hz = true;

            ///////////////////////////////////

            executionTime1000Hz = micros() - currentTime;

            ///////////////////////////////
        }
}

///////////////////////////////////////////////////////////////////////////////
// System Time in Microseconds
///////////////////////////////////////////////////////////////////////////////

uint32_t micros(void)
{
    register uint32_t oldCycle, cycle, timeMs;
    __disable_irq();
    cycle = *DWT_CYCCNT;
    oldCycle = sysTickCycleCounter;
    timeMs = sysTickUptime;
    __enable_irq();
    return (timeMs * 1000) + (cycle - oldCycle) / usTicks;
}

///////////////////////////////////////////////////////////////////////////////
// System Time in Milliseconds
///////////////////////////////////////////////////////////////////////////////

uint32_t millis(void)
{
    return sysTickUptime;
}

///////////////////////////////////////////////////////////////////////////////
// System Initialization
///////////////////////////////////////////////////////////////////////////////

void systemInit(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    uint8_t i;

    gpio_config_t gpio_cfg[] = {
        {LED0_GPIO, LED0_PIN, GPIO_Mode_Out_PP},        // PB3 (LED)
        {LED1_GPIO, LED1_PIN, GPIO_Mode_Out_PP},        // PB4 (LED)
    };

    uint8_t gpio_count = sizeof(gpio_cfg) / sizeof(gpio_cfg[0]);

    // Turn on clocks for stuff we use
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C2, ENABLE);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA2, ENABLE);
    RCC_ClearFlag();

    // Make all GPIO in by default to save power and reduce noise
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    // Turn off JTAG port 'cause we're using the GPIO for leds
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);

    // Configure gpio
    for (i = 0; i < gpio_count; i++) {
        GPIO_InitStructure.GPIO_Pin = gpio_cfg[i].pin;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_Mode = gpio_cfg[i].mode;

        GPIO_Init(gpio_cfg[i].gpio, &GPIO_InitStructure);
    }

    // Init cycle counter
    cycleCounterInit();

    // SysTick
    SysTick_Config(SystemCoreClock / 1000);

    LED0_OFF;
    LED1_OFF;

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);     // 2 bits for pre-emption priority, 2 bits for subpriority

    checkFirstTime(false, false);
    readEEPROM();

    initMixer();

    pwmOutputConfig.escPwmRate = systemConfig.escPwmRate;
    pwmOutputConfig.servoPwmRate = systemConfig.servoPwmRate;

    i2cInit(I2C2);
    pwmInputInit();
    pwmOutputInit(&pwmOutputConfig);
    uartInit(115200);

    delay(10000);               // 10 sec delay for sensor stabilization - probably not long enough.....

    initAccel();
    initGyro();
    initMag();
    initPressure();

    initPID();
}

///////////////////////////////////////////////////////////////////////////////
// Delay Microseconds
///////////////////////////////////////////////////////////////////////////////

void delayMicroseconds(uint32_t us)
{
    uint32_t elapsed = 0;
    uint32_t lastCount = *DWT_CYCCNT;

    for (;;) {
        register uint32_t current_count = *DWT_CYCCNT;
        uint32_t elapsed_us;

        // measure the time elapsed since the last time we checked
        elapsed += current_count - lastCount;
        lastCount = current_count;

        // convert to microseconds
        elapsed_us = elapsed / usTicks;
        if (elapsed_us >= us)
            break;

        // reduce the delay by the elapsed time
        us -= elapsed_us;

        // keep fractional microseconds for the next iteration
        elapsed %= usTicks;
    }
}

///////////////////////////////////////////////////////////////////////////////
// Delay Milliseconds
///////////////////////////////////////////////////////////////////////////////

void delay(uint32_t ms)
{
    while (ms--)
        delayMicroseconds(1000);
}

///////////////////////////////////////////////////////////////////////////////
// System Reset
///////////////////////////////////////////////////////////////////////////////

#define AIRCR_VECTKEY_MASK    ((uint32_t)0x05FA0000)

void systemReset(bool toBootloader)
{
    if (toBootloader) {
        // 1FFFF000 -> 20000200 -> SP
        // 1FFFF004 -> 1FFFF021 -> PC
        *((uint32_t *) 0x20004FF0) = 0xDEADBEEF;        // 20KB STM32F103
    }
    // Generate system reset
    SCB->AIRCR = AIRCR_VECTKEY_MASK | (uint32_t) 0x04;
}

///////////////////////////////////////////////////////////////////////////////
