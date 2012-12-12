/*
  June 2012

  BaseFligh tPlus Rev -

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

static volatile uint8_t queryType;

uint8_t highSpeedAccelTelemEnabled     = false;
uint8_t highSpeedGyroTelemEnabled      = false;
uint8_t highSpeedRollRateTelemEnabled  = false;
uint8_t highSpeedPitchRateTelemEnabled = false;
uint8_t highSpeedYawRateTelemEnabled   = false;
uint8_t highSpeedAttitudeTelemEnabled  = false;

///////////////////////////////////////////////////////////////////////////////
// Read Character String from Serial Comm
///////////////////////////////////////////////////////////////////////////////

char *readStringSerial(char *data, uint8_t length)
{
    uint8_t index    = 0;
    uint8_t timeout  = 0;

    do
    {
        if (uartAvailable() == false)
        {
            delay(10);
            timeout++;
        }
        else
        {
            data[index] = uartRead();
            timeout = 0;
            index++;
        }
    }
    while ((index == 0 || data[index-1] != ';') && (timeout < 5) && (index < length));

    data[index] = '\0';

    return data;
}

///////////////////////////////////////////////////////////////////////////////
// Read Float from Serial Comm
///////////////////////////////////////////////////////////////////////////////

float readFloatSerial(void)
{
    uint8_t index    = 0;
    uint8_t timeout  = 0;
    char    data[13] = "";

    do
    {
        if (uartAvailable() == false)
        {
            delay(10);
            timeout++;
        }
        else
        {
            data[index] = uartRead();
            timeout = 0;
            index++;
        }
    }
    while ((index == 0 || data[index-1] != ';') && (timeout < 5) && (index < sizeof(data)-1));

    data[index] = '\0';

    return stringToFloat(data);
}

///////////////////////////////////////////////////////////////////////////////
// Read Int from Serial Comm
///////////////////////////////////////////////////////////////////////////////

int16_t readInt16Serial(void)
{
    uint8_t index    = 0;
    uint8_t timeout  = 0;
    char    data[13] = "";

    do
    {
        if (uartAvailable() == false)
        {
            delay(10);
            timeout++;
        }
        else
        {
            data[index] = uartRead();
            timeout = 0;
            index++;
        }
    }
    while ((index == 0 || data[index-1] != ';') && (timeout < 5) && (index < sizeof(data)-1));

    data[index] = '\0';

    return atoi(data);
}

///////////////////////////////////////////////////////////////////////////////
// Read PID Values from Serial Comm
///////////////////////////////////////////////////////////////////////////////

void readSerialPID(unsigned char PIDid)
{
  struct PIDdata* pid = &systemConfig.PID[PIDid];

  pid->P           = readFloatSerial();
  pid->I           = readFloatSerial();
  pid->D           = readFloatSerial();
  pid->windupGuard = readFloatSerial();
  pid->iTerm       = 0.0f;
  pid->lastError   = 0.0f;
  pid->dTerm1      = 0.0f;
  pid->dTerm2      = 0.0f;
}

///////////////////////////////////////////////////////////////////////////////
// Serial Communication
///////////////////////////////////////////////////////////////////////////////

void serialCom(void)
{
    char  numberString[12];
    char  rcOrderString[9];
    float hdg;
    uint8_t index;
    uint8_t rows, columns;

    if ( uartAvailable() ) queryType = uartRead();

    switch (queryType)
    {
        ///////////////////////////////

        case 'a': // Loop Delta Times
        	itoa( deltaTime1000Hz, numberString, 10 ); uartPrint(numberString); uartPrint(", ");
        	itoa( deltaTime500Hz,  numberString, 10 ); uartPrint(numberString); uartPrint(", ");
        	itoa( deltaTime200Hz,  numberString, 10 ); uartPrint(numberString); uartPrint(", ");
        	itoa( deltaTime100Hz,  numberString, 10 ); uartPrint(numberString); uartPrint(", ");
        	itoa( deltaTime50Hz,   numberString, 10 ); uartPrint(numberString); uartPrint(", ");
        	itoa( deltaTime10Hz,   numberString, 10 ); uartPrint(numberString); uartPrint(", ");
        	itoa( deltaTime5Hz,    numberString, 10 ); uartPrint(numberString); uartPrint(", ");
        	itoa( deltaTime1Hz,    numberString, 10 ); uartPrint(numberString); uartPrint("\n");
        	break;

        ///////////////////////////////

        case 'b': // Loop Execution Times
        	itoa( executionTime500Hz,  numberString, 10 ); uartPrint(numberString); uartPrint(", ");
        	itoa( executionTime200Hz,  numberString, 10 ); uartPrint(numberString); uartPrint(", ");
        	itoa( executionTime100Hz,  numberString, 10 ); uartPrint(numberString); uartPrint(", ");
        	itoa( executionTime50Hz,   numberString, 10 ); uartPrint(numberString); uartPrint(", ");
        	itoa( executionTime10Hz,   numberString, 10 ); uartPrint(numberString); uartPrint(", ");
        	itoa( executionTime5Hz,    numberString, 10 ); uartPrint(numberString); uartPrint(", ");
        	itoa( executionTime1Hz,    numberString, 10 ); uartPrint(numberString); uartPrint("\n");
        	break;

        ///////////////////////////////

        case 'c': // Execute Accel Calibration
            accelCalibration();

            queryType = 'x';
            break;

        ///////////////////////////////

        case 'd': // Execute Gyro Temp Calibration
            gyroTempCalibration();

            queryType = 'x';
            break;

        ///////////////////////////////

        case 'e': // 200 Hz Accel Data
        	ftoa( sensors.accel200Hz[ROLL ], numberString ); uartPrint(numberString); uartPrint(", ");
        	ftoa( sensors.accel200Hz[PITCH], numberString ); uartPrint(numberString); uartPrint(", ");
        	ftoa( sensors.accel200Hz[YAW  ], numberString ); uartPrint(numberString); uartPrint("\n");
        	break;

        ///////////////////////////////

        case 'f': // 100 Hz Accel Data
        	ftoa( sensors.accel100Hz[ROLL ], numberString ); uartPrint(numberString); uartPrint(", ");
        	ftoa( sensors.accel100Hz[PITCH], numberString ); uartPrint(numberString); uartPrint(", ");
        	ftoa( sensors.accel100Hz[YAW  ], numberString ); uartPrint(numberString); uartPrint("\n");
        	break;

        ///////////////////////////////

        case 'g': // 200 Hz Gyro Data
        	ftoa( sensors.gyro200Hz[ROLL ], numberString ); uartPrint(numberString); uartPrint(", ");
        	ftoa( sensors.gyro200Hz[PITCH], numberString ); uartPrint(numberString); uartPrint(", ");
        	ftoa( sensors.gyro200Hz[YAW  ], numberString ); uartPrint(numberString); uartPrint(", ");
        	ftoa( gyroTemperature,          numberString ); uartPrint(numberString); uartPrint("\n");
        	break;

        ///////////////////////////////

        case 'h': // 100 Hz Gyro Data
        	ftoa( sensors.gyro100Hz[ROLL ], numberString ); uartPrint(numberString); uartPrint(", ");
        	ftoa( sensors.gyro100Hz[PITCH], numberString ); uartPrint(numberString); uartPrint(", ");
        	ftoa( sensors.gyro100Hz[YAW  ], numberString ); uartPrint(numberString); uartPrint(", ");
        	ftoa( gyroTemperature,          numberString ); uartPrint(numberString); uartPrint("\n");
        	break;

        ///////////////////////////////

        case 'i': // Execute Mag Calibration
            magCalibration();

            queryType = 'x';
            break;

        ///////////////////////////////

        case 'j': // 10 Hz Mag Data
        	ftoa( sensors.mag10Hz[XAXIS], numberString ); uartPrint(numberString); uartPrint(", ");
        	ftoa( sensors.mag10Hz[YAXIS], numberString ); uartPrint(numberString); uartPrint(", ");
        	ftoa( sensors.mag10Hz[ZAXIS], numberString ); uartPrint(numberString); uartPrint("\n");
        	break;

        ///////////////////////////////

        case 'k': // Heading (Only good at Roll = 0, Pitch = 0)
            hdg = atan2( -sensors.mag10Hz[YAXIS], sensors.mag10Hz[XAXIS] ) * 57.3f;
            ftoa( hdg, numberString );
            uartPrint( numberString ); uartPrint( "\n" );
            break;

        ///////////////////////////////

        case 'l': // 10Hz Pressure Altitude
            ftoa( sensors.pressureAltitude10Hz, numberString ); uartPrint( numberString ); uartPrint("\n");
            break;

        ///////////////////////////////

        case 'm': // Tilts (from 100 Hz Accel Data)
        	ftoa( atan2( -sensors.accel100Hz[YAXIS], -sensors.accel100Hz[ZAXIS] ) * 57.3f, numberString ); uartPrint(numberString); uartPrint(", ");
        	ftoa( atan2(  sensors.accel100Hz[XAXIS], -sensors.accel100Hz[ZAXIS] ) * 57.3f, numberString ); uartPrint(numberString); uartPrint("\n");
        	break;

        ///////////////////////////////

        case 'n': // 200 Hz Attitude Data
        	ftoa( sensors.attitude200Hz[ROLL ] * 57.3f, numberString ); uartPrint(numberString); uartPrint(", ");
        	ftoa( sensors.attitude200Hz[PITCH] * 57.3f, numberString ); uartPrint(numberString); uartPrint(", ");
        	ftoa( sensors.attitude200Hz[YAW  ] * 57.3f, numberString ); uartPrint(numberString); uartPrint("\n");
        	break;

        ///////////////////////////////

        case 'o': // Receiver Commands
            for (index = 0; index < 7; index++)
            {
    			ftoa( rxCommand[index], numberString );
    			uartPrint( numberString ); uartPrint( ", " );
    		}

            ftoa( rxCommand[7], numberString );
            uartPrint( numberString ); uartPrint( "\n" );
            break;

        ///////////////////////////////

        case 'p': // Command in Detent Discretes
            if ( commandInDetent[ROLL] == true )
                uartPrint( "true" );
            else
                uartPrint( "false" );
            uartPrint(", ");

            if ( commandInDetent[PITCH] == true )
                uartPrint( "true" );
            else
                uartPrint( "false" );
            uartPrint(", ");

            if ( commandInDetent[YAW] == true )
                uartPrint( "true" );
            else
                uartPrint( "false" );
            uartPrint("\n");
            break;

        ///////////////////////////////

        case 'q': // PWM Outputs
            itoa(TIM1->CCR1, numberString, 10); uartPrint(numberString); uartPrint(", ");
            itoa(TIM1->CCR4, numberString, 10); uartPrint(numberString); uartPrint(", ");
            itoa(TIM4->CCR1, numberString, 10); uartPrint(numberString); uartPrint(", ");
            itoa(TIM4->CCR2, numberString, 10); uartPrint(numberString); uartPrint(", ");
            itoa(TIM4->CCR3, numberString, 10); uartPrint(numberString); uartPrint(", ");
            itoa(TIM4->CCR4, numberString, 10); uartPrint(numberString); uartPrint("\n");
            break;

        ///////////////////////////////

        case 'r': // Rate PIDs
            uartPrint("\n");

            uartPrint("Roll Rate PID:  ");
            ftoa(systemConfig.PID[ROLL_RATE_PID].P,            numberString); uartPrint(numberString); uartPrint(", ");
            ftoa(systemConfig.PID[ROLL_RATE_PID].I,            numberString); uartPrint(numberString); uartPrint(", ");
            ftoa(systemConfig.PID[ROLL_RATE_PID].D,            numberString); uartPrint(numberString); uartPrint(", ");
            ftoa(systemConfig.PID[ROLL_RATE_PID].windupGuard,  numberString); uartPrint(numberString); uartPrint(", ");
            itoa(systemConfig.PID[ROLL_RATE_PID].type,     numberString, 10); uartPrint(numberString); uartPrint("\n");

            uartPrint("Pitch Rate PID: ");
            ftoa(systemConfig.PID[PITCH_RATE_PID].P,           numberString); uartPrint(numberString); uartPrint(", ");
            ftoa(systemConfig.PID[PITCH_RATE_PID].I,           numberString); uartPrint(numberString); uartPrint(", ");
            ftoa(systemConfig.PID[PITCH_RATE_PID].D,           numberString); uartPrint(numberString); uartPrint(", ");
            ftoa(systemConfig.PID[PITCH_RATE_PID].windupGuard, numberString); uartPrint(numberString); uartPrint(", ");
            itoa(systemConfig.PID[PITCH_RATE_PID].type,    numberString, 10); uartPrint(numberString); uartPrint("\n");

            uartPrint("Yaw Rate PID:   ");
            ftoa(systemConfig.PID[YAW_RATE_PID].P,             numberString); uartPrint(numberString); uartPrint(", ");
            ftoa(systemConfig.PID[YAW_RATE_PID].I,             numberString); uartPrint(numberString); uartPrint(", ");
            ftoa(systemConfig.PID[YAW_RATE_PID].D,             numberString); uartPrint(numberString); uartPrint(", ");
            ftoa(systemConfig.PID[YAW_RATE_PID].windupGuard,   numberString); uartPrint(numberString); uartPrint(", ");
            itoa(systemConfig.PID[YAW_RATE_PID].type,      numberString, 10); uartPrint(numberString); uartPrint("\n");

            queryType = 'x';
            break;

        ///////////////////////////////

        case 's': // Attitude PIDs
            uartPrint("\n");

            uartPrint("Roll Attitude PID:  ");
            ftoa(systemConfig.PID[ROLL_ATT_PID].P,            numberString); uartPrint(numberString); uartPrint(", ");
            ftoa(systemConfig.PID[ROLL_ATT_PID].I,            numberString); uartPrint(numberString); uartPrint(", ");
            ftoa(systemConfig.PID[ROLL_ATT_PID].D,            numberString); uartPrint(numberString); uartPrint(", ");
            ftoa(systemConfig.PID[ROLL_ATT_PID].windupGuard,  numberString); uartPrint(numberString); uartPrint(", ");
            itoa(systemConfig.PID[ROLL_ATT_PID].type,     numberString, 10); uartPrint(numberString); uartPrint("\n");

            uartPrint("Pitch Attitude PID: ");
            ftoa(systemConfig.PID[PITCH_ATT_PID].P,           numberString); uartPrint(numberString); uartPrint(", ");
            ftoa(systemConfig.PID[PITCH_ATT_PID].I,           numberString); uartPrint(numberString); uartPrint(", ");
            ftoa(systemConfig.PID[PITCH_ATT_PID].D,           numberString); uartPrint(numberString); uartPrint(", ");
            ftoa(systemConfig.PID[PITCH_ATT_PID].windupGuard, numberString); uartPrint(numberString); uartPrint(", ");
            itoa(systemConfig.PID[PITCH_ATT_PID].type,    numberString, 10); uartPrint(numberString); uartPrint("\n");

            uartPrint("Heading PID:        ");
            ftoa(systemConfig.PID[HEADING_PID].P,             numberString); uartPrint(numberString); uartPrint(", ");
            ftoa(systemConfig.PID[HEADING_PID].I,             numberString); uartPrint(numberString); uartPrint(", ");
            ftoa(systemConfig.PID[HEADING_PID].D,             numberString); uartPrint(numberString); uartPrint(", ");
            ftoa(systemConfig.PID[HEADING_PID].windupGuard,   numberString); uartPrint(numberString); uartPrint(", ");
            itoa(systemConfig.PID[HEADING_PID].type,      numberString, 10); uartPrint(numberString); uartPrint("\n");

            queryType = 'x';
            break;

        ///////////////////////////////

        case 't': // Sensor Calibration Data
            uartPrint("\n");

            uartPrint("Accel Scale Factor:        ");
            ftoa(sensorConfig.accelScaleFactor[XAXIS],    numberString); uartPrint(numberString); uartPrint(", ");
            ftoa(sensorConfig.accelScaleFactor[YAXIS],    numberString); uartPrint(numberString); uartPrint(", ");
            ftoa(sensorConfig.accelScaleFactor[ZAXIS],    numberString); uartPrint(numberString); uartPrint("\n");

            uartPrint("Accel Bias:                ");
            ftoa(sensorConfig.accelBias[XAXIS],           numberString); uartPrint(numberString); uartPrint(", ");
            ftoa(sensorConfig.accelBias[YAXIS],           numberString); uartPrint(numberString); uartPrint(", ");
            ftoa(sensorConfig.accelBias[ZAXIS],           numberString); uartPrint(numberString); uartPrint("\n");

            uartPrint("Gyro Temp Comp Slope:      ");
            ftoa(sensorConfig.gyroTCBiasSlope[ROLL ],     numberString); uartPrint(numberString); uartPrint(", ");
            ftoa(sensorConfig.gyroTCBiasSlope[PITCH],     numberString); uartPrint(numberString); uartPrint(", ");
            ftoa(sensorConfig.gyroTCBiasSlope[YAW  ],     numberString); uartPrint(numberString); uartPrint("\n");

            uartPrint("Gyro Temp Comp Intercept:  ");
            ftoa(sensorConfig.gyroTCBiasIntercept[ROLL ], numberString); uartPrint(numberString); uartPrint(", ");
            ftoa(sensorConfig.gyroTCBiasIntercept[PITCH], numberString); uartPrint(numberString); uartPrint(", ");
            ftoa(sensorConfig.gyroTCBiasIntercept[YAW  ], numberString); uartPrint(numberString); uartPrint("\n");

            uartPrint("Mag Bias:                  ");
            ftoa(sensorConfig.magBias[XAXIS],             numberString); uartPrint(numberString); uartPrint(", ");
            ftoa(sensorConfig.magBias[YAXIS],             numberString); uartPrint(numberString); uartPrint(", ");
            ftoa(sensorConfig.magBias[ZAXIS],             numberString); uartPrint(numberString); uartPrint("\n");

            uartPrint("Accel Cutoff:              ");
            ftoa(sensorConfig.accelCutoff,                numberString); uartPrint(numberString); uartPrint("\n");

            #if defined(USE_MADGWICK_AHRS)
                uartPrint("Beta:                      ");
                ftoa(sensorConfig.beta,                       numberString); uartPrint(numberString); uartPrint("\n");
            #endif

            #if defined(USE_MARG_AHRS)
                uartPrint("KpAcc:                     ");
                ftoa(sensorConfig.KpAcc,                      numberString); uartPrint(numberString); uartPrint("\n");

                uartPrint("KiAcc:                     ");
                ftoa(sensorConfig.KiAcc,                      numberString); uartPrint(numberString); uartPrint("\n");

                uartPrint("KpMag:                     ");
                ftoa(sensorConfig.KpMag,                      numberString); uartPrint(numberString); uartPrint("\n");

                uartPrint("KiMag:                     ");
                ftoa(sensorConfig.KiMag,                      numberString); uartPrint(numberString); uartPrint("\n");
            #endif

            #if defined(USE_CHR6DM_AHRS)
                uartPrint("Accel Variance:            ");
                ftoa(sensorConfig.accelVariance,              numberString); uartPrint(numberString); uartPrint("\n");

                uartPrint("Mag Variance:              ");
                ftoa(sensorConfig.magVariance,                numberString); uartPrint(numberString); uartPrint("\n");

                uartPrint("Process Variance:          ");
                ftoa(sensorConfig.processVariance,            numberString); uartPrint(numberString); uartPrint("\n");

                uartPrint("Accel Ref Vector:          ");
                ftoa(sensorConfig.accelRefVector[XAXIS],      numberString); uartPrint(numberString); uartPrint(", ");
                ftoa(sensorConfig.accelRefVector[YAXIS],      numberString); uartPrint(numberString); uartPrint(", ");
                ftoa(sensorConfig.accelRefVector[ZAXIS],      numberString); uartPrint(numberString); uartPrint("\n");

                uartPrint("Mag Ref Vector:            ");
                ftoa(sensorConfig.magRefVector[XAXIS],        numberString); uartPrint(numberString); uartPrint(", ");
                ftoa(sensorConfig.magRefVector[YAXIS],        numberString); uartPrint(numberString); uartPrint(", ");
                ftoa(sensorConfig.magRefVector[ZAXIS],        numberString); uartPrint(numberString); uartPrint("\n");
            #endif

            queryType = 'x';
            break;

        ///////////////////////////////

        case 'u': // System Configuration Data
            uartPrint("\nReceiver PWM Input Type:        ");
            if (systemConfig.useSerialPWMflag)
                uartPrint("Serial\n");
            else
                uartPrint("Parallel\n");

            uartPrint("Current RC Channel Assignment:  ");
            for (index = 0; index < 8; index++)
                rcOrderString[systemConfig.rcMap[index]] = rcChannelLetters[index];

            rcOrderString[index] = '\0';

            uartPrint(rcOrderString);
            uartPrint("\n");

            uartPrint("Mixer Configuration:            ");
            switch (systemConfig.mixerConfiguration)
            {
                case MULTITYPE_TRI:
                    uartPrint("MULTITYPE TRICOPTER\n");
                    break;

                case MULTITYPE_QUADP:
                    uartPrint("MULTITYPE QUAD PLUS\n");
                    break;

                case MULTITYPE_QUADX:
                    uartPrint("MULTITYPE QUAD X\n");
                    break;

                case MULTITYPE_BI:
                    uartPrint("MULTITYPE BICOPTER\n");
                    break;

                case MULTITYPE_GIMBAL:
                	uartPrint("MULTITYPE GIMBAL\n");
                	break;

                case MULTITYPE_Y6:
                    uartPrint("MULTITYPE Y6\n");
                    break;

                case MULTITYPE_HEX6P:
                    uartPrint("MULTITYPE HEX PLUS\n");
                    break;

                case MULTITYPE_Y4:
                	uartPrint("MULTITYPE Y4\n");
                	break;

                case MULTITYPE_HEX6X:
                    uartPrint("MULTITYPE HEX X\n");
                    break;

                case MULTITYPE_VTAIL4:
                	uartPrint("MULTITYPE QUAD VTAIL\n");
                	break;

                case MULTITYPE_FREEMIX:
                	uartPrint("MULTITYPE FREE MIX\n");
                	break;

                case MULTITYPE_FLYING_WING:
                	uartPrint("MULTITYPE FLYING WING\n");
                	break;
            }

            uartPrint("Number of Motors:               ");
            itoa(numberMotor,                         numberString, 10); uartPrint(numberString); uartPrint("\n");

            uartPrint("ESC PWM Rate:                   ");
            itoa((uint16_t)systemConfig.escPwmRate,   numberString, 10); uartPrint(numberString); uartPrint("\n");

            uartPrint("Servo PWM Rate:                 ");
            itoa((uint16_t)systemConfig.servoPwmRate, numberString, 10); uartPrint(numberString); uartPrint("\n");

            uartPrint("Mid Command:                    ");
            itoa((uint16_t)systemConfig.midCommand,   numberString, 10); uartPrint(numberString); uartPrint("\n");

            uartPrint("Min Check:                      ");
            itoa((uint16_t)systemConfig.minCheck,     numberString, 10); uartPrint(numberString); uartPrint("\n");

            uartPrint("Max Check:                      ");
            itoa((uint16_t)systemConfig.maxCheck,     numberString, 10); uartPrint(numberString); uartPrint("\n");

            uartPrint("Min Throttle:                   ");
            itoa((uint16_t)systemConfig.minThrottle,  numberString, 10); uartPrint(numberString); uartPrint("\n");

            uartPrint("Max Thottle:                    ");
            itoa((uint16_t)systemConfig.maxThrottle,  numberString, 10); uartPrint(numberString); uartPrint("\n");

            if ( systemConfig.mixerConfiguration == MULTITYPE_GIMBAL )
            {
                uartPrint("Gimbal Roll Servo Min:          ");
                itoa((uint16_t)systemConfig.gimbalRollServoMin,  numberString, 10); uartPrint(numberString); uartPrint("\n");
                uartPrint("Gimbal Roll Servo Mid:          ");
                itoa((uint16_t)systemConfig.gimbalRollServoMid,  numberString, 10); uartPrint(numberString); uartPrint("\n");
                uartPrint("Gimbal Roll Servo Max:          ");
                itoa((uint16_t)systemConfig.gimbalRollServoMax,  numberString, 10); uartPrint(numberString); uartPrint("\n");
                uartPrint("Gimbal Roll Servo Gain:         ");
                ftoa(systemConfig.gimbalRollServoGain, numberString);               uartPrint(numberString); uartPrint("\n");
                uartPrint("Gimbal Pitch Servo Min:         ");
                itoa((uint16_t)systemConfig.gimbalPitchServoMin, numberString, 10); uartPrint(numberString); uartPrint("\n");
                uartPrint("Gimbal Pitch Servo Mid:         ");
                itoa((uint16_t)systemConfig.gimbalPitchServoMid, numberString, 10); uartPrint(numberString); uartPrint("\n");
                uartPrint("Gimbal Pitch Servo Max:         ");
                itoa((uint16_t)systemConfig.gimbalPitchServoMax, numberString, 10); uartPrint(numberString); uartPrint("\n");
                uartPrint("Gimbal Pitch Servo Gain:        ");
                ftoa(systemConfig.gimbalPitchServoGain, numberString);              uartPrint(numberString); uartPrint("\n");
            }

            if ( systemConfig.mixerConfiguration == MULTITYPE_BI )
            {
                uartPrint("BiCopter Left Servo Min:        ");
                itoa((uint16_t)systemConfig.biLeftServoMin,  numberString, 10); uartPrint(numberString); uartPrint("\n");
                uartPrint("BiCopter Left Servo Mid:        ");
                itoa((uint16_t)systemConfig.biLeftServoMid,  numberString, 10); uartPrint(numberString); uartPrint("\n");
                uartPrint("BiCopter Left Servo Max:        ");
                itoa((uint16_t)systemConfig.biLeftServoMax,  numberString, 10); uartPrint(numberString); uartPrint("\n");
                uartPrint("BiCopter Right Servo Min:       ");
                itoa((uint16_t)systemConfig.biRightServoMin, numberString, 10); uartPrint(numberString); uartPrint("\n");
                uartPrint("BiCopter Right Servo Mid:       ");
                itoa((uint16_t)systemConfig.biRightServoMid, numberString, 10); uartPrint(numberString); uartPrint("\n");
                uartPrint("BiCopter Right Servo Max:       ");
                itoa((uint16_t)systemConfig.biRightServoMax, numberString, 10); uartPrint(numberString); uartPrint("\n");
             }

            if ( systemConfig.mixerConfiguration == MULTITYPE_TRI )
            {
                uartPrint("TriCopter Yaw Servo Min:        ");
                itoa((uint16_t)systemConfig.triYawServoMin, numberString, 10); uartPrint(numberString); uartPrint("\n");
                uartPrint("TriCopter Yaw Servo Mid:        ");
                itoa((uint16_t)systemConfig.triYawServoMid, numberString, 10); uartPrint(numberString); uartPrint("\n");
                uartPrint("TriCopter Yaw Servo Max:        ");
                itoa((uint16_t)systemConfig.triYawServoMax, numberString, 10); uartPrint(numberString); uartPrint("\n");
             }

            if ( systemConfig.mixerConfiguration == MULTITYPE_FLYING_WING )
            {
                uartPrint("Roll Direction Left:            ");
                itoa((uint16_t)systemConfig.rollDirectionLeft,   numberString, 10); uartPrint(numberString); uartPrint("\n");
                uartPrint("Roll Direction Right:           ");
                itoa((uint16_t)systemConfig.rollDirectionRight,  numberString, 10); uartPrint(numberString); uartPrint("\n");
                uartPrint("Pitch Direction Left:           ");
                itoa((uint16_t)systemConfig.pitchDirectionLeft,  numberString, 10); uartPrint(numberString); uartPrint("\n");
                uartPrint("Pitch Direction Right:          ");
                itoa((uint16_t)systemConfig.pitchDirectionRight, numberString, 10); uartPrint(numberString); uartPrint("\n");
                uartPrint("Wing Left Minimum:              ");
                itoa((uint16_t)systemConfig.wingLeftMinimum,     numberString, 10); uartPrint(numberString); uartPrint("\n");
                uartPrint("Wing Left Maximum:              ");
                itoa((uint16_t)systemConfig.wingLeftMaximum,     numberString, 10); uartPrint(numberString); uartPrint("\n");
                uartPrint("Wing Right Minimum:             ");
                itoa((uint16_t)systemConfig.wingRightMinimum,    numberString, 10); uartPrint(numberString); uartPrint("\n");
                uartPrint("Wing Right Maximum:             ");
                itoa((uint16_t)systemConfig.wingRightMaximum,    numberString, 10); uartPrint(numberString); uartPrint("\n");
             }

            queryType = 'x';
            break;

        ///////////////////////////////

        #if defined(USE_CHR6DM_AHRS)
            case 'v':
                ahrsCalibration();

                queryType = 'x';
                break;
        #endif

        ///////////////////////////////

        case 'w':
        	uartPrint("\nNumber of Free Mixer Motors:  ");
        	itoa( systemConfig.freeMixMotors, numberString, 10 ); uartPrint( numberString ); uartPrint("\n\n");
            uartPrint("         Roll    Pitch   Yaw\n");

        	for ( index = 0; index < systemConfig.freeMixMotors; index++ )
        	{
        		uartPrint("Motor"); itoa( index, numberString, 10 );     uartPrint( numberString ); uartPrint("  ");
        		ftoa( systemConfig.freeMix[index][ROLL ], numberString); uartPrint( numberString ); uartPrint("  ");
        		ftoa( systemConfig.freeMix[index][PITCH], numberString); uartPrint( numberString ); uartPrint("  ");
        		ftoa( systemConfig.freeMix[index][YAW  ], numberString); uartPrint( numberString ); uartPrint("\n");
        	}
        	queryType = 'x';
        	break;

        ///////////////////////////////

        case 'x':
            break;

        ///////////////////////////////

        case '1': // Toggle high speed accel telemetry on/off
        	if ( highSpeedAccelTelemEnabled == false )
                highSpeedAccelTelemEnabled = true;
           	else
           		highSpeedAccelTelemEnabled = false;

        	queryType = 'x';
            break;

        ///////////////////////////////

        case '2': // Toggle high speed gyro telemetry on/off
           	if ( highSpeedGyroTelemEnabled == false )
                highSpeedGyroTelemEnabled = true;
           	else
           		highSpeedGyroTelemEnabled = false;

           	queryType = 'x';
           	break;

        ///////////////////////////////

        case '3': // Toggle high speed roll rate telemetry on/off
           	if ( highSpeedRollRateTelemEnabled == false )
                highSpeedRollRateTelemEnabled = true;
           	else
           		highSpeedRollRateTelemEnabled = false;

           	queryType = 'x';
            break;

        ///////////////////////////////

        case '4': // Toggle high speed pitch rate telemetry on/off
          	if ( highSpeedPitchRateTelemEnabled == false )
                highSpeedPitchRateTelemEnabled = true;
           	else
          		highSpeedPitchRateTelemEnabled = false;

           	queryType = 'x';
           	break;

        ///////////////////////////////

        case '5': // Toggle high speed yaw rate telemetry on/off
           	if ( highSpeedYawRateTelemEnabled == false )
                highSpeedYawRateTelemEnabled = true;
           	else
           		highSpeedYawRateTelemEnabled = false;

           	queryType = 'x';
           	break;

        ///////////////////////////////

        case '6': // Toggle high speed attitude telemetry on/off
          	if ( highSpeedAttitudeTelemEnabled == false )
                highSpeedAttitudeTelemEnabled = true;
           	else
           		highSpeedAttitudeTelemEnabled = false;

           	queryType = 'x';
           	break;

        ///////////////////////////////

        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////

        ///////////////////////////////

        case 'A': // Read Roll Rate PID Values
            readSerialPID(ROLL_RATE_PID);
            uartPrint( "\nRoll Rate PID Received....\n" );

        	queryType = 'r';
        	break;

        ///////////////////////////////

        case 'B': // Read Pitch Rate PID Values
            readSerialPID(PITCH_RATE_PID);
            uartPrint( "\nPitch Rate PID Received....\n" );

        	queryType = 'r';
        	break;

        ///////////////////////////////

        case 'C': // Read Yaw Rate PID Values
            readSerialPID(YAW_RATE_PID);
            uartPrint( "\nYaw Rate PID Received....\n" );

        	queryType = 'r';
        	break;

        ///////////////////////////////

        case 'D': // Read Roll Attitude PID Values
            readSerialPID(ROLL_ATT_PID);
            uartPrint( "\nRoll Attitude PID Received....\n" );

        	queryType = 's';
        	break;

        ///////////////////////////////

        case 'E': // Read Pitch Attitude PID Values
            readSerialPID(PITCH_ATT_PID);
            uartPrint( "\nPitch Attitude PID Received....\n" );

        	queryType = 's';
        	break;

        ///////////////////////////////

        case 'F': // Read Heading PID Values
            readSerialPID(HEADING_PID);
            uartPrint( "\nHeading PID Received....\n" );

        	queryType = 's';
        	break;

        ///////////////////////////////

        case 'G': // Read RC Control Points
            systemConfig.midCommand   = readFloatSerial();
			systemConfig.minCheck     = readFloatSerial();
			systemConfig.maxCheck     = readFloatSerial();
			systemConfig.minThrottle  = readFloatSerial();
			systemConfig.maxThrottle  = readFloatSerial();
            uartPrint( "\nRC Control Points Received....\n" );

        	queryType = 'u';
        	break;

        ///////////////////////////////

        case 'H': // Read Mixer Configuration
            systemConfig.mixerConfiguration = (uint8_t)readFloatSerial();
            uartPrint( "\nMixer Configuration Received....\n" );
        	initMixer();
        	pwmOutputInit(&pwmOutputConfig);

        	queryType = 'u';
        	break;

        ///////////////////////////////

        case 'I': // Read RC Control Order
            readStringSerial( rcOrderString, 8 );
            uartPrint( "\nRC Channel Order Received...." );
            uartPrint( rcOrderString );
            uartPrint("\n");
            parseRcChannels( rcOrderString );

        	queryType = 'u';
        	break;

        ///////////////////////////////

        case 'J': // Read Accel Cutoff
            sensorConfig.accelCutoff = readFloatSerial();
            uartPrint( "\nAccel Cutoff Received....\n" );

            queryType = 't';
        	break;

        ///////////////////////////////

        case 'K': // Read Beta or Read KpAcc, KiAcc, KpMag, KiMag
            #if defined(USE_MADGWICK_AHRS)
                sensorConfig.beta = readFloatSerial();
                uartPrint( "\nBeta Received....\n" );
            #endif

            #if defined(USE_MARG_AHRS)
                sensorConfig.KpAcc = readFloatSerial();
                sensorConfig.KiAcc = readFloatSerial();
                sensorConfig.KpMag = readFloatSerial();
                sensorConfig.KiMag = readFloatSerial();
                uartPrint( "\nKp's and Ki's Received....\n" );
            #endif

            #if defined(USE_CHR6DM_AHRS)
                sensorConfig.accelVariance   = readFloatSerial();
                sensorConfig.magVariance     = readFloatSerial();
                sensorConfig.processVariance = readFloatSerial();
                uartPrint( "\nVariance's  Received....\n" );
            #endif

            queryType = 't';
        	break;

        ///////////////////////////////

        case 'L': // Read BiCopter Left Servo Parameters
        	if ( systemConfig.mixerConfiguration == MULTITYPE_BI )
        	{
        		systemConfig.biLeftServoMin = readFloatSerial();
        		systemConfig.biLeftServoMid = readFloatSerial();
        		systemConfig.biLeftServoMax = readFloatSerial();
        		uartPrint( "\nBiCopter Left Servo Parameters Received....\n");

        		queryType = 'u';
        	}
        	break;

        ///////////////////////////////

        case 'M': // Read BiCopter Right Servo Parameters
        	if ( systemConfig.mixerConfiguration == MULTITYPE_BI )
        	{
        		systemConfig.biRightServoMin = readFloatSerial();
        		systemConfig.biRightServoMid = readFloatSerial();
        		systemConfig.biRightServoMax = readFloatSerial();
        		uartPrint( "\nBiCopter Right Servo Parameters Received....\n");

        		queryType = 'u';
        	}
        	break;

        ///////////////////////////////

        case 'N': // Read TriCopter YawServo Parameters
        	if ( systemConfig.mixerConfiguration == MULTITYPE_TRI )
        	{
        		systemConfig.triYawServoMin = readFloatSerial();
        		systemConfig.triYawServoMid = readFloatSerial();
        		systemConfig.triYawServoMax = readFloatSerial();
        		uartPrint( "\nTriCopter Yaw Servo Parameters Received....\n");

        		queryType = 'u';
        	}
        	break;

        ///////////////////////////////

        case 'O': // Read Gimbal Roll Servo Parameters
        	if ( systemConfig.mixerConfiguration == MULTITYPE_GIMBAL )
        	{
        		systemConfig.gimbalRollServoMin  = readFloatSerial();
        		systemConfig.gimbalRollServoMid  = readFloatSerial();
        		systemConfig.gimbalRollServoMax  = readFloatSerial();
        		systemConfig.gimbalRollServoGain = readFloatSerial();
        		uartPrint( "\nGimbal Roll Servo Parameters Received....\n");

        		queryType = 'u';
        	}
        	break;

        ///////////////////////////////

        case 'P': // Read Gimbal Pitch Servo Parameters
        	if ( systemConfig.mixerConfiguration == MULTITYPE_GIMBAL )
        	{
        		systemConfig.gimbalPitchServoMin  = readFloatSerial();
        		systemConfig.gimbalPitchServoMid  = readFloatSerial();
        		systemConfig.gimbalPitchServoMax  = readFloatSerial();
        		systemConfig.gimbalPitchServoGain = readFloatSerial();
        		uartPrint( "\nGimbal Pitch Servo Parameters Received....\n");

        		queryType = 'u';
        	}
        	break;

        ///////////////////////////////

        case 'Q': // Read ESC and Servo PWM Update Rates
            systemConfig.escPwmRate = (uint16_t)readFloatSerial();
            systemConfig.servoPwmRate = (uint16_t)readFloatSerial();
            uartPrint( "\nPWM Update Rates Received....\n");
            pwmOutputConfig.escPwmRate   = systemConfig.escPwmRate;
            pwmOutputConfig.servoPwmRate = systemConfig.servoPwmRate;
            pwmOutputInit(&pwmOutputConfig);

            queryType = 'u';
            break;

        ///////////////////////////////

        case 'R': // Reset to Bootloader
        	systemReset(true);
        	break;

        ///////////////////////////////

        case 'S': // Read Flying Wing Servo Directions
            systemConfig.rollDirectionLeft   = readFloatSerial();
            systemConfig.rollDirectionRight  = readFloatSerial();
            systemConfig.pitchDirectionLeft  = readFloatSerial();
            systemConfig.pitchDirectionRight = readFloatSerial();
        	uartPrint( "\nFlying Wing Servo Directions Received....\n");

        	queryType = 'u';
        	break;

        ///////////////////////////////

        case 'T': // Read Flying Wing Servo Limits
        	systemConfig.wingLeftMinimum  = readFloatSerial();
        	systemConfig.wingLeftMaximum  = readFloatSerial();
        	systemConfig.wingRightMinimum = readFloatSerial();
        	systemConfig.wingRightMaximum = readFloatSerial();
        	uartPrint( "\nFlying Wing Servo Limits Received....\n");

        	queryType = 'u';
        	break;

        ///////////////////////////////

        case 'U': // Reset Sensor Configuration
            uartPrint( "\nSensor Configuration Reset....\n" );
            checkFirstTime(true, false);
            systemReset(false);
            break;

        ///////////////////////////////

        case 'V': // Reset System Configuration
            uartPrint( "\nSystem Configuration Reset....\n" );
            checkFirstTime(false, true);
            systemReset(false);
            break;

        ///////////////////////////////

        case 'W': // Write EEPROM Sensor Parameters
            uartPrint( "\nWriting EEPROM Sensor Parameters....\n" );
            writeSensorParams();
            systemReset(false);
            break;

        ///////////////////////////////

        case 'X': // Read Free Mix Motor Number
        	systemConfig.freeMixMotors = (uint8_t)readFloatSerial();
        	uartPrint( "\nFree Mix Motor Number Received....\n");
        	initMixer();

           	queryType = 'w';
           	break;

        ///////////////////////////////

        case 'Y': // Read Free Mix Motor Number
            rows    = (uint8_t)readFloatSerial();
            columns = (uint8_t)readFloatSerial();
            systemConfig.freeMix[rows][columns] = readFloatSerial();
            uartPrint( "\nFree Mix Value Received....\n");

            queryType = 'w';
            break;

        ///////////////////////////////

        case 'Z': // Reset System
        	uartPrint("\nSystem Reseting....\n");
        	delay(100);
        	systemReset(false);
        	break;

        ///////////////////////////////

        case '!': // Read RX Input Type
            systemConfig.useSerialPWMflag = (uint8_t)readFloatSerial();
            uartPrint( "\nReceiver PWM Input Type Received....\n");

            queryType = 'u';
            break;

        ///////////////////////////////

        case '@': // Write EEPROM System Parameters
            uartPrint( "\nWriting EEPROM System Parameters....\n" );
            writeSystemParams();
            systemReset(false);
            break;

        ///////////////////////////////

    }
}

///////////////////////////////////////////////////////////////////////////////
