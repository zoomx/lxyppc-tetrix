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

#include "usb_lib.h"
#include "usb_pwr.h"
#include "board.h"
#include "drv_nrf24l01.h"
#include "drv_nrf24l01_config.h"
///////////////////////////////////////////////////////////////////////////////

sensors_t      sensors;
sensorConfig_t sensorConfig;
systemConfig_t systemConfig;

#if defined(USE_MADGWICK_AHRS) | defined(USE_MARG_AHRS)
static    float q0q0, q1q1, q2q2, q3q3;
#endif

///////////////////////////////////////////////////////////////////////////////

RCC_ClocksTypeDef clocks;

void cycleCounterInit(void);
void testInit(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    uint8_t i;

    struct __gpio_config_t {
    GPIO_TypeDef *gpio;
    uint16_t pin;
    GPIOMode_TypeDef mode;
    }
    gpio_cfg[] = {
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
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
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
    
    checkFirstTime(true,true);
    initMixer();
    
    pwmOutputConfig.motorPwmRate = 10*1000;
    pwmOutputConfig.noEsc = true;
    pwmOutputInit(&pwmOutputConfig);
    
    
    i2cInit(SENSOR_I2C);
    initGyro();
    initAccel();
    initMag();
    nrf_init();
    nrf_detect();
}
void usb_send_data(const void* buffer, uint32_t len);
int16_t magSumed[3] = {0,0,0};
const uint8_t addr[] = TX_ADDR;

void usb_get_data(const void* p, uint32_t len)
{
    LED0_TOGGLE;
    memcpy(rxCommand, p , sizeof(rxCommand));
}

int main(void)
{
	uint32_t currentTime;

    // High Speed Telemetry Test Code Begin
    char numberString[12];
    // High Speed Telemetry Test Code End
    RCC_GetClocksFreq(&clocks);
    USB_Interrupts_Config();
    Set_USBClock();
    USB_Init();
    
    // Wait until device configured
    //while(bDeviceState != CONFIGURED);

    testInit();
    
    LED0_ON;
    systemReady = true;
    
    nrf_tx_mode_no_aa(addr,5,40);
    
    while (1)
    {
        uint8_t buf[64];
        if (frame_50Hz)
        {
        	frame_50Hz = false;
        	currentTime      = micros();
			deltaTime50Hz    = currentTime - previous50HzTime;
			previous50HzTime = currentTime;
            memcpy(buf, accelSummedSamples100Hz, 12);
            memcpy(buf+12, gyroSummedSamples100Hz, 12);
            memcpy(buf+24, magSumed, 6);
            
            memcpy(buf, &sensors.attitude200Hz[0], 12);
            memcpy(buf + 12, &executionTime200Hz, 4);
            memcpy(buf + 16, motor, 16);
            usb_send_data(buf , 64);
			executionTime50Hz = micros() - currentTime;
            nrf_tx_packet(buf,16);
        }
        
        if(frame_10Hz)
        {
            frame_10Hz = false;
            magSumed[XAXIS] = magSum[XAXIS];
            magSumed[YAXIS] = magSum[YAXIS];
            magSumed[ZAXIS] = magSum[ZAXIS];
            magSum[XAXIS] = 0;
			magSum[YAXIS] = 0;
			magSum[ZAXIS] = 0;
            newMagData = true;
        }
        
        if (frame_100Hz)
        {
            frame_100Hz = false;
            computeAxisCommands(dt100Hz);
            mixTable();
            writeServos();
            writeMotors();
        }
        
        if (frame_200Hz)
        {
        	frame_200Hz = false;

       	    currentTime       = micros();
       	    deltaTime200Hz    = currentTime - previous200HzTime;
       	    previous200HzTime = currentTime;

       	    dt200Hz = (float)deltaTime200Hz * 0.000001f;  // For integrations in 200 Hz loop

            #if defined(USE_MADGWICK_AHRS) | defined(USE_MARG_AHRS)
                sensors.accel200Hz[XAXIS] = -((float)accelSummedSamples200Hz[XAXIS] / 5.0f - accelRTBias[XAXIS] - sensorConfig.accelBias[XAXIS]) * sensorConfig.accelScaleFactor[XAXIS];
			    sensors.accel200Hz[YAXIS] = -((float)accelSummedSamples200Hz[YAXIS] / 5.0f - accelRTBias[YAXIS] - sensorConfig.accelBias[YAXIS]) * sensorConfig.accelScaleFactor[YAXIS];
			    sensors.accel200Hz[ZAXIS] = -((float)accelSummedSamples200Hz[ZAXIS] / 5.0f - accelRTBias[ZAXIS] - sensorConfig.accelBias[ZAXIS]) * sensorConfig.accelScaleFactor[ZAXIS];

                sensors.accel200Hz[XAXIS] = computeFourthOrder200Hz(sensors.accel200Hz[XAXIS], &fourthOrder200Hz[AX_FILTER]);
                sensors.accel200Hz[YAXIS] = computeFourthOrder200Hz(sensors.accel200Hz[YAXIS], &fourthOrder200Hz[AY_FILTER]);
                sensors.accel200Hz[ZAXIS] = computeFourthOrder200Hz(sensors.accel200Hz[ZAXIS], &fourthOrder200Hz[AZ_FILTER]);

                computeGyroTCBias();
                sensors.gyro200Hz[ROLL ] =  ((float)gyroSummedSamples200Hz[ROLL]  / 5.0f - gyroRTBias[ROLL ] - gyroTCBias[ROLL ]) * GYRO_SCALE_FACTOR;
			    sensors.gyro200Hz[PITCH] = -((float)gyroSummedSamples200Hz[PITCH] / 5.0f - gyroRTBias[PITCH] - gyroTCBias[PITCH]) * GYRO_SCALE_FACTOR;
                sensors.gyro200Hz[YAW  ] = -((float)gyroSummedSamples200Hz[YAW]   / 5.0f - gyroRTBias[YAW  ] - gyroTCBias[YAW  ]) * GYRO_SCALE_FACTOR;
            #endif

            #if defined(USE_MADGWICK_AHRS)
                MadgwickAHRSupdate( sensors.gyro200Hz[ROLL],   sensors.gyro200Hz[PITCH],  sensors.gyro200Hz[YAW],
                                    sensors.accel200Hz[XAXIS], sensors.accel200Hz[YAXIS], sensors.accel200Hz[ZAXIS],
                                    sensors.mag10Hz[XAXIS],    sensors.mag10Hz[YAXIS],    sensors.mag10Hz[ZAXIS],
                                    sensorConfig.accelCutoff,
                                    newMagData,
                                    dt200Hz );

                newMagData = false;

		        q0q0 = q0 * q0;
		        q1q1 = q1 * q1;
		        q2q2 = q2 * q2;
		        q3q3 = q3 * q3;

    	        sensors.attitude200Hz[ROLL ] = atan2f( 2.0f * (q0 * q1 + q2 * q3), q0q0 - q1q1 - q2q2 + q3q3 );
    	        sensors.attitude200Hz[PITCH] = -asinf( 2.0f * (q1 * q3 - q0 * q2) );
    	        sensors.attitude200Hz[YAW  ] = atan2f( 2.0f * (q1 * q2 + q0 * q3), q0q0 + q1q1 - q2q2 - q3q3 );
            #endif

            #if defined(USE_MARG_AHRS)
                MargAHRSupdate( sensors.gyro200Hz[ROLL],   sensors.gyro200Hz[PITCH],  sensors.gyro200Hz[YAW],
                                sensors.accel200Hz[XAXIS], sensors.accel200Hz[YAXIS], sensors.accel200Hz[ZAXIS],
                                sensors.mag10Hz[XAXIS],    sensors.mag10Hz[YAXIS],    sensors.mag10Hz[ZAXIS],
                                sensorConfig.accelCutoff,
                                newMagData,
                                dt200Hz );

                newMagData = false;

		        q0q0 = q0 * q0;
		        q1q1 = q1 * q1;
		        q2q2 = q2 * q2;
		        q3q3 = q3 * q3;

    	        sensors.attitude200Hz[ROLL ] = atan2f( 2.0f * (q0 * q1 + q2 * q3), q0q0 - q1q1 - q2q2 + q3q3 );
    	        sensors.attitude200Hz[PITCH] = -asinf( 2.0f * (q1 * q3 - q0 * q2) );
    	        sensors.attitude200Hz[YAW  ] = atan2f( 2.0f * (q1 * q2 + q0 * q3), q0q0 + q1q1 - q2q2 - q3q3 );
            #endif

            executionTime200Hz = micros() - currentTime;
        }
    }
    systemInit();
    systemReady = true;
    while (1)
    {
    	///////////////////////////////

        if (frame_50Hz)
        {
        	frame_50Hz = false;

        	currentTime      = micros();
			deltaTime50Hz    = currentTime - previous50HzTime;
			previous50HzTime = currentTime;

			processFlightCommands();

			executionTime50Hz = micros() - currentTime;
        }

        ///////////////////////////////

        if (frame_10Hz)
        {
            LED0_TOGGLE;
        	frame_10Hz = false;

        	currentTime      = micros();
			deltaTime10Hz    = currentTime - previous10HzTime;
			previous10HzTime = currentTime;

			sensors.mag10Hz[XAXIS] = -((float)magSum[XAXIS] / 5.0f * magScaleFactor[XAXIS] - sensorConfig.magBias[XAXIS]);
			sensors.mag10Hz[YAXIS] =   (float)magSum[YAXIS] / 5.0f * magScaleFactor[YAXIS] - sensorConfig.magBias[YAXIS];
			sensors.mag10Hz[ZAXIS] = -((float)magSum[ZAXIS] / 5.0f * magScaleFactor[ZAXIS] - sensorConfig.magBias[ZAXIS]);

			magSum[XAXIS] = 0;
			magSum[YAXIS] = 0;
			magSum[ZAXIS] = 0;

			newMagData = true;

        	pressureAverage = pressureSum / 10;
        	pressureSum = 0;
        	calculateTemperature();
        	calculatePressureAltitude();
        	sensors.pressureAltitude10Hz = pressureAlt;

        	serialCom();

        	if ( EKF_Initialized == false ) EKF_Init( sensors.accel100Hz[XAXIS], sensors.accel100Hz[YAXIS], sensors.accel100Hz[ZAXIS],
                                                      sensors.mag10Hz[XAXIS],    sensors.mag10Hz[YAXIS],    sensors.mag10Hz[ZAXIS] );

            executionTime10Hz = micros() - currentTime;
        }

        ///////////////////////////////

        if (frame_500Hz)
        {
			frame_500Hz = false;

       	    currentTime       = micros();
       	    deltaTime500Hz    = currentTime - previous500HzTime;
       	    previous500HzTime = currentTime;

       	    dt500Hz = (float)deltaTime500Hz * 0.000001f;  // For integrations in 500 Hz loop

            computeGyroTCBias();
            sensors.gyro500Hz[ROLL ] =  ((float)gyroSummedSamples500Hz[ROLL]  / 2.0f - gyroRTBias[ROLL ] - gyroTCBias[ROLL ]) * GYRO_SCALE_FACTOR;
			sensors.gyro500Hz[PITCH] = -((float)gyroSummedSamples500Hz[PITCH] / 2.0f - gyroRTBias[PITCH] - gyroTCBias[PITCH]) * GYRO_SCALE_FACTOR;
            sensors.gyro500Hz[YAW  ] = -((float)gyroSummedSamples500Hz[YAW]   / 2.0f - gyroRTBias[YAW  ] - gyroTCBias[YAW  ]) * GYRO_SCALE_FACTOR;

            #if defined(USE_CHR6DM_AHRS)
                if ( EKF_Initialized == true ) EKF_Predict( sensors.gyro500Hz[ROLL], sensors.gyro500Hz[PITCH], sensors.gyro500Hz[YAW],
                                                            dt500Hz );

                sensors.attitude200Hz[ROLL ] = gEstimatedStates.phi;
                sensors.attitude200Hz[PITCH] = gEstimatedStates.theta;
                sensors.attitude200Hz[YAW  ] = gEstimatedStates.psi;
            #endif

       	    executionTime500Hz = micros() - currentTime;
		}

        ///////////////////////////////

        if (frame_200Hz)
        {
        	frame_200Hz = false;

       	    currentTime       = micros();
       	    deltaTime200Hz    = currentTime - previous200HzTime;
       	    previous200HzTime = currentTime;

       	    dt200Hz = (float)deltaTime200Hz * 0.000001f;  // For integrations in 200 Hz loop

            #if defined(USE_MADGWICK_AHRS) | defined(USE_MARG_AHRS)
                sensors.accel200Hz[XAXIS] = -((float)accelSummedSamples200Hz[XAXIS] / 5.0f - accelRTBias[XAXIS] - sensorConfig.accelBias[XAXIS]) * sensorConfig.accelScaleFactor[XAXIS];
			    sensors.accel200Hz[YAXIS] = -((float)accelSummedSamples200Hz[YAXIS] / 5.0f - accelRTBias[YAXIS] - sensorConfig.accelBias[YAXIS]) * sensorConfig.accelScaleFactor[YAXIS];
			    sensors.accel200Hz[ZAXIS] = -((float)accelSummedSamples200Hz[ZAXIS] / 5.0f - accelRTBias[ZAXIS] - sensorConfig.accelBias[ZAXIS]) * sensorConfig.accelScaleFactor[ZAXIS];

                sensors.accel200Hz[XAXIS] = computeFourthOrder200Hz(sensors.accel200Hz[XAXIS], &fourthOrder200Hz[AX_FILTER]);
                sensors.accel200Hz[YAXIS] = computeFourthOrder200Hz(sensors.accel200Hz[YAXIS], &fourthOrder200Hz[AY_FILTER]);
                sensors.accel200Hz[ZAXIS] = computeFourthOrder200Hz(sensors.accel200Hz[ZAXIS], &fourthOrder200Hz[AZ_FILTER]);

                computeGyroTCBias();
                sensors.gyro200Hz[ROLL ] =  ((float)gyroSummedSamples200Hz[ROLL]  / 5.0f - gyroRTBias[ROLL ] - gyroTCBias[ROLL ]) * GYRO_SCALE_FACTOR;
			    sensors.gyro200Hz[PITCH] = -((float)gyroSummedSamples200Hz[PITCH] / 5.0f - gyroRTBias[PITCH] - gyroTCBias[PITCH]) * GYRO_SCALE_FACTOR;
                sensors.gyro200Hz[YAW  ] = -((float)gyroSummedSamples200Hz[YAW]   / 5.0f - gyroRTBias[YAW  ] - gyroTCBias[YAW  ]) * GYRO_SCALE_FACTOR;
            #endif

            #if defined(USE_MADGWICK_AHRS)
                MadgwickAHRSupdate( sensors.gyro200Hz[ROLL],   sensors.gyro200Hz[PITCH],  sensors.gyro200Hz[YAW],
                                    sensors.accel200Hz[XAXIS], sensors.accel200Hz[YAXIS], sensors.accel200Hz[ZAXIS],
                                    sensors.mag10Hz[XAXIS],    sensors.mag10Hz[YAXIS],    sensors.mag10Hz[ZAXIS],
                                    sensorConfig.accelCutoff,
                                    newMagData,
                                    dt200Hz );

                newMagData = false;

		        q0q0 = q0 * q0;
		        q1q1 = q1 * q1;
		        q2q2 = q2 * q2;
		        q3q3 = q3 * q3;

    	        sensors.attitude200Hz[ROLL ] = atan2f( 2.0f * (q0 * q1 + q2 * q3), q0q0 - q1q1 - q2q2 + q3q3 );
    	        sensors.attitude200Hz[PITCH] = -asinf( 2.0f * (q1 * q3 - q0 * q2) );
    	        sensors.attitude200Hz[YAW  ] = atan2f( 2.0f * (q1 * q2 + q0 * q3), q0q0 + q1q1 - q2q2 - q3q3 );
            #endif

            #if defined(USE_MARG_AHRS)
                MargAHRSupdate( sensors.gyro200Hz[ROLL],   sensors.gyro200Hz[PITCH],  sensors.gyro200Hz[YAW],
                                sensors.accel200Hz[XAXIS], sensors.accel200Hz[YAXIS], sensors.accel200Hz[ZAXIS],
                                sensors.mag10Hz[XAXIS],    sensors.mag10Hz[YAXIS],    sensors.mag10Hz[ZAXIS],
                                sensorConfig.accelCutoff,
                                newMagData,
                                dt200Hz );

                newMagData = false;

		        q0q0 = q0 * q0;
		        q1q1 = q1 * q1;
		        q2q2 = q2 * q2;
		        q3q3 = q3 * q3;

    	        sensors.attitude200Hz[ROLL ] = atan2f( 2.0f * (q0 * q1 + q2 * q3), q0q0 - q1q1 - q2q2 + q3q3 );
    	        sensors.attitude200Hz[PITCH] = -asinf( 2.0f * (q1 * q3 - q0 * q2) );
    	        sensors.attitude200Hz[YAW  ] = atan2f( 2.0f * (q1 * q2 + q0 * q3), q0q0 + q1q1 - q2q2 - q3q3 );
            #endif

            executionTime200Hz = micros() - currentTime;
        }

        ///////////////////////////////

        if (frame_100Hz)
        {
        	frame_100Hz = false;

        	currentTime       = micros();
			deltaTime100Hz    = currentTime - previous100HzTime;
			previous100HzTime = currentTime;

			dt100Hz = (float)deltaTime100Hz * 0.000001f;  // For integrations in 100 Hz loop

            sensors.accel100Hz[XAXIS] = -((float)accelSummedSamples100Hz[XAXIS] / 10.0f - accelRTBias[XAXIS] - sensorConfig.accelBias[XAXIS]) * sensorConfig.accelScaleFactor[XAXIS];
			sensors.accel100Hz[YAXIS] = -((float)accelSummedSamples100Hz[YAXIS] / 10.0f - accelRTBias[YAXIS] - sensorConfig.accelBias[YAXIS]) * sensorConfig.accelScaleFactor[YAXIS];
			sensors.accel100Hz[ZAXIS] = -((float)accelSummedSamples100Hz[ZAXIS] / 10.0f - accelRTBias[ZAXIS] - sensorConfig.accelBias[ZAXIS]) * sensorConfig.accelScaleFactor[ZAXIS];

        	sensors.accel100Hz[XAXIS] = computeFourthOrder100Hz(sensors.accel100Hz[XAXIS], &fourthOrder100Hz[AX_FILTER]);
            sensors.accel100Hz[YAXIS] = computeFourthOrder100Hz(sensors.accel100Hz[YAXIS], &fourthOrder100Hz[AY_FILTER]);
            sensors.accel100Hz[ZAXIS] = computeFourthOrder100Hz(sensors.accel100Hz[ZAXIS], &fourthOrder100Hz[AZ_FILTER]);

            computeGyroTCBias();
            sensors.gyro100Hz[ROLL ] =  ((float)gyroSummedSamples100Hz[ROLL]  / 10.0f - gyroRTBias[ROLL ] - gyroTCBias[ROLL ]) * GYRO_SCALE_FACTOR;
			sensors.gyro100Hz[PITCH] = -((float)gyroSummedSamples100Hz[PITCH] / 10.0f - gyroRTBias[PITCH] - gyroTCBias[PITCH]) * GYRO_SCALE_FACTOR;
            sensors.gyro100Hz[YAW  ] = -((float)gyroSummedSamples100Hz[YAW]   / 10.0f - gyroRTBias[YAW  ] - gyroTCBias[YAW  ]) * GYRO_SCALE_FACTOR;

            #if defined(USE_CHR6DM_AHRS)
                if ( EKF_Initialized == true ) EKF_Update( sensors.accel100Hz[XAXIS], sensors.accel100Hz[YAXIS], sensors.accel100Hz[ZAXIS],
					                                       sensors.mag10Hz[XAXIS],    sensors.mag10Hz[YAXIS],    sensors.mag10Hz[ZAXIS],
					                                       sensorConfig.accelCutoff,
                                                           newMagData );
                newMagData = false;

		        sensors.attitude200Hz[ROLL ] = gEstimatedStates.phi;
    	        sensors.attitude200Hz[PITCH] = gEstimatedStates.theta;
    	        sensors.attitude200Hz[YAW  ] = gEstimatedStates.psi;
            #endif

            computeAxisCommands(dt100Hz);
            mixTable();
            writeServos();
            writeMotors();

            // High Speed Telemetry Test Code Begin
            if ( highSpeedAccelTelemEnabled == true )
            {
            	// 100 Hz Accels
            	ftoa(sensors.accel100Hz[XAXIS], numberString); uartPrint(numberString); uartPrint(",");
            	ftoa(sensors.accel100Hz[YAXIS], numberString); uartPrint(numberString); uartPrint(",");
            	ftoa(sensors.accel100Hz[ZAXIS], numberString); uartPrint(numberString); uartPrint("\n");
            }

            if ( highSpeedGyroTelemEnabled == true )
            {
            	// 100 Hz Gyros
            	ftoa(sensors.gyro100Hz[ROLL ], numberString); uartPrint(numberString); uartPrint(",");
            	ftoa(sensors.gyro100Hz[PITCH], numberString); uartPrint(numberString); uartPrint(",");
            	ftoa(sensors.gyro100Hz[YAW  ], numberString); uartPrint(numberString); uartPrint("\n");
            }

            if ( highSpeedRollRateTelemEnabled == true )
            {
            	// Roll Rate, Roll Rate Command
            	ftoa(sensors.gyro100Hz[ROLL], numberString); uartPrint(numberString); uartPrint(",");
            	ftoa(rxCommand[ROLL],         numberString); uartPrint(numberString); uartPrint("\n");
            }

            if ( highSpeedPitchRateTelemEnabled == true )
            {
            	// Pitch Rate, Pitch Rate Command
            	ftoa(sensors.gyro100Hz[PITCH], numberString); uartPrint(numberString); uartPrint(",");
            	ftoa(rxCommand[PITCH],         numberString); uartPrint(numberString); uartPrint("\n");
            }

            if ( highSpeedYawRateTelemEnabled == true )
            {
            	// Yaw Rate, Yaw Rate Command
            	ftoa(sensors.gyro100Hz[YAW], numberString); uartPrint(numberString); uartPrint(",");
            	ftoa(rxCommand[YAW],         numberString); uartPrint(numberString); uartPrint("\n");
            }

            if ( highSpeedAttitudeTelemEnabled == true )
            {
            	// 200 Hz Attitudes
            	ftoa(sensors.attitude200Hz[ROLL ], numberString); uartPrint(numberString); uartPrint(",");
            	ftoa(sensors.attitude200Hz[PITCH], numberString); uartPrint(numberString); uartPrint(",");
            	ftoa(sensors.attitude200Hz[YAW  ], numberString); uartPrint(numberString); uartPrint("\n");
            }
            // High Speed Telemetry Test Code End
            executionTime100Hz = micros() - currentTime;
        }

        ///////////////////////////////

        if (frame_5Hz)
        {
        	frame_5Hz = false;

        	currentTime     = micros();
			deltaTime5Hz    = currentTime - previous5HzTime;
			previous5HzTime = currentTime;

        	executionTime5Hz = micros() - currentTime;
        }

        ///////////////////////////////

        if (frame_1Hz)
        {
        	frame_1Hz = false;

        	currentTime     = micros();
			deltaTime1Hz    = currentTime - previous1HzTime;
			previous1HzTime = currentTime;

        	executionTime1Hz = micros() - currentTime;
        }

        ////////////////////////////////
    }
}

///////////////////////////////////////////////////////////////////////////////
