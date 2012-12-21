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

#define FLASH_PAGE_COUNT 64

#define FLASH_PAGE_SIZE                 ((uint16_t)0x400)

// use the last KB for sensor config storage
#define FLASH_WRITE_SENSOR_CONFIG_ADDR  (0x08000000 + (uint32_t)FLASH_PAGE_SIZE * (FLASH_PAGE_COUNT - 1))

// use the 2nd to last KB for system config storage
#define FLASH_WRITE_SYSTEM_CONFIG_ADDR  (0x08000000 + (uint32_t)FLASH_PAGE_SIZE * (FLASH_PAGE_COUNT - 2))

const char rcChannelLetters[] = "AERT1234";

static uint8_t checkNewSensorConf = 1;
static uint8_t checkNewSystemConf = 1;

///////////////////////////////////////////////////////////////////////////////

void parseRcChannels(const char *input)
{
    const char *c, *s;

    for (c = input; *c; c++)
    {
        s = strchr(rcChannelLetters, *c);
        if (s)
            systemConfig.rcMap[s - rcChannelLetters] = c - input;
    }
}

///////////////////////////////////////////////////////////////////////////////

void readEEPROM(void)
{
    // Read flash

	memcpy(&sensorConfig, (char *)FLASH_WRITE_SENSOR_CONFIG_ADDR, sizeof(sensorConfig_t));

    memcpy(&systemConfig, (char *)FLASH_WRITE_SYSTEM_CONFIG_ADDR, sizeof(systemConfig_t));

    systemConfig.yawDirection = constrain( systemConfig.yawDirection, -1.0f, 1.0f );
}

///////////////////////////////////////////////////////////////////////////////

void writeSensorParams(void)
{
    FLASH_Status status;
    uint32_t i;

    FLASH_Unlock();

    FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);

    if (FLASH_ErasePage(FLASH_WRITE_SENSOR_CONFIG_ADDR) == FLASH_COMPLETE)
    {
        for (i = 0; i < sizeof(sensorConfig_t); i += 4)
        {
            status = FLASH_ProgramWord(FLASH_WRITE_SENSOR_CONFIG_ADDR + i, *(uint32_t *)((char *)&sensorConfig + i));
            if (status != FLASH_COMPLETE)
                break; // TODO: fail
        }
    }

    FLASH_Lock();

    readEEPROM();
}

///////////////////////////////////////////////////////////////////////////////

void writeSystemParams(void)
{
    FLASH_Status status;
    uint32_t i;

    FLASH_Unlock();

    FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);

    if (FLASH_ErasePage(FLASH_WRITE_SYSTEM_CONFIG_ADDR) == FLASH_COMPLETE)
    {
        for (i = 0; i < sizeof(systemConfig_t); i += 4)
        {
            status = FLASH_ProgramWord(FLASH_WRITE_SYSTEM_CONFIG_ADDR + i, *(uint32_t *)((char *)&systemConfig + i));
            if (status != FLASH_COMPLETE)
                break; // TODO: fail
        }
    }

    FLASH_Lock();

    readEEPROM();
}

///////////////////////////////////////////////////////////////////////////////

void checkFirstTime(bool sensorReset, bool systemReset)
{
    uint8_t test_val;

    test_val = *(uint8_t *)FLASH_WRITE_SENSOR_CONFIG_ADDR;

    if (sensorReset || test_val != checkNewSensorConf)
    {
		// Default settings
        sensorConfig.version = checkNewSensorConf;

	    ///////////////////////////////

        sensorConfig.accelBias[XAXIS] = 0.0f;
        sensorConfig.accelBias[YAXIS] = 0.0f;
        sensorConfig.accelBias[ZAXIS] = 0.0f;

        ///////////////////////////////

        sensorConfig.accelScaleFactor[XAXIS] = 9.8065f / 2048.0f;
        sensorConfig.accelScaleFactor[YAXIS] = 9.8065f / 2048.0f;
        sensorConfig.accelScaleFactor[ZAXIS] = 9.8065f / 2048.0f;

        ///////////////////////////////

        sensorConfig.gyroTCBiasSlope[ROLL ] = 0.0f;
        sensorConfig.gyroTCBiasSlope[PITCH] = 0.0f;
        sensorConfig.gyroTCBiasSlope[YAW  ] = 0.0f;

	    ///////////////////////////////

	    sensorConfig.gyroTCBiasIntercept[ROLL ] = 0.0f;
	    sensorConfig.gyroTCBiasIntercept[PITCH] = 0.0f;
	    sensorConfig.gyroTCBiasIntercept[YAW  ] = 0.0f;

	    ///////////////////////////////

	    sensorConfig.magBias[XAXIS] = 0.0f;
	    sensorConfig.magBias[YAXIS] = 0.0f;
	    sensorConfig.magBias[ZAXIS] = 0.0f;

		///////////////////////////////

		sensorConfig.accelCutoff = 1.0f;

		///////////////////////////////

		sensorConfig.beta = 0.1f;

	    ///////////////////////////////

	    sensorConfig.KpAcc = 2.0f;    // proportional gain governs rate of convergence to accelerometer
	    sensorConfig.KiAcc = 0.005f;  // integral gain governs rate of convergence of gyroscope biases
	    sensorConfig.KpMag = 2.0f;    // proportional gain governs rate of convergence to magnetometer
	    sensorConfig.KiMag = 0.005f;  // integral gain governs rate of convergence of gyroscope biases

	    ///////////////////////////////

	    sensorConfig.accelVariance = 2.0f;

	    sensorConfig.magVariance = 2.0f;

	    sensorConfig.processVariance = 0.1f;

	    sensorConfig.accelRefVector[XAXIS] =  0.0f;
	    sensorConfig.accelRefVector[YAXIS] =  0.0f;
	    sensorConfig.accelRefVector[ZAXIS] = -9.8065f;

	    sensorConfig.magRefVector[XAXIS] = 255.0f;
	    sensorConfig.magRefVector[YAXIS] = 0.0f;
	    sensorConfig.magRefVector[ZAXIS] = 666.0f;

	    ///////////////////////////////

	    writeSensorParams();
	}

    ///////////////////////////////////

    if (systemReset || test_val != checkNewSystemConf)
    {
		// Default settings
        systemConfig.version = checkNewSystemConf;

        systemConfig.useSerialPWMflag = true; // use the serial PWM for PPM singal

        parseRcChannels("TAER1234");

        systemConfig.escPwmRate   = 400;
        systemConfig.servoPwmRate = 50;

        systemConfig.mixerConfiguration = MULTITYPE_QUADX;
        systemConfig.yawDirection = 1.0f;

        systemConfig.midCommand   = 3000.0f;
        systemConfig.minCheck     = (float)(MINCOMMAND + 200);
        systemConfig.maxCheck     = (float)(MAXCOMMAND - 200);
        systemConfig.minThrottle  = (float)(MINCOMMAND + 200);
        systemConfig.maxThrottle  = (float)(MAXCOMMAND);

        systemConfig.PID[ROLL_RATE_PID].P            = 200.0f;
        systemConfig.PID[ROLL_RATE_PID].I            =   0.0f;
        systemConfig.PID[ROLL_RATE_PID].D            =   0.0f;
        systemConfig.PID[ROLL_RATE_PID].iTerm        =   0.0f;
        systemConfig.PID[ROLL_RATE_PID].windupGuard  = 200.0f;  // PWMs
        systemConfig.PID[ROLL_RATE_PID].lastError    =   0.0f;
        systemConfig.PID[ROLL_RATE_PID].dTerm1       =   0.0f;
        systemConfig.PID[ROLL_RATE_PID].dTerm2       =   0.0f;
        systemConfig.PID[ROLL_RATE_PID].type         =   0;

        systemConfig.PID[PITCH_RATE_PID].P           = 200.0f;
        systemConfig.PID[PITCH_RATE_PID].I           =   0.0f;
        systemConfig.PID[PITCH_RATE_PID].D           =   0.0f;
        systemConfig.PID[PITCH_RATE_PID].iTerm       =   0.0f;
        systemConfig.PID[PITCH_RATE_PID].windupGuard = 200.0f;  // PWMs
        systemConfig.PID[PITCH_RATE_PID].lastError   =   0.0f;
        systemConfig.PID[PITCH_RATE_PID].dTerm1      =   0.0f;
        systemConfig.PID[PITCH_RATE_PID].dTerm2      =   0.0f;
        systemConfig.PID[PITCH_RATE_PID].type        =   0;

        systemConfig.PID[YAW_RATE_PID].P             = 400.0f;
        systemConfig.PID[YAW_RATE_PID].I             =   0.0f;
        systemConfig.PID[YAW_RATE_PID].D             =   0.0f;
        systemConfig.PID[YAW_RATE_PID].iTerm         =   0.0f;
        systemConfig.PID[YAW_RATE_PID].windupGuard   = 200.0f;  // PWMs
        systemConfig.PID[YAW_RATE_PID].lastError     =   0.0f;
        systemConfig.PID[YAW_RATE_PID].dTerm1        =   0.0f;
        systemConfig.PID[YAW_RATE_PID].dTerm2        =   0.0f;
        systemConfig.PID[YAW_RATE_PID].type          =   0;

        systemConfig.PID[ROLL_ATT_PID].P             =   4.0f;
        systemConfig.PID[ROLL_ATT_PID].I             =   0.0f;
        systemConfig.PID[ROLL_ATT_PID].D             =   0.0f;
        systemConfig.PID[ROLL_ATT_PID].iTerm         =   0.0f;
        systemConfig.PID[ROLL_ATT_PID].windupGuard   =   0.5f;  // radians/sec
        systemConfig.PID[ROLL_ATT_PID].lastError     =   0.0f;
        systemConfig.PID[ROLL_ATT_PID].dTerm1        =   0.0f;
        systemConfig.PID[ROLL_ATT_PID].dTerm2        =   0.0f;
        systemConfig.PID[ROLL_ATT_PID].type          =   1;

        systemConfig.PID[PITCH_ATT_PID].P            =   4.0f;
        systemConfig.PID[PITCH_ATT_PID].I            =   0.0f;
        systemConfig.PID[PITCH_ATT_PID].D            =   0.0f;
        systemConfig.PID[PITCH_ATT_PID].iTerm        =   0.0f;
        systemConfig.PID[PITCH_ATT_PID].windupGuard  =   0.5f;  // radians/sec
        systemConfig.PID[PITCH_ATT_PID].lastError    =   0.0f;
        systemConfig.PID[PITCH_ATT_PID].dTerm1       =   0.0f;
        systemConfig.PID[PITCH_ATT_PID].dTerm2       =   0.0f;
        systemConfig.PID[PITCH_ATT_PID].type         =   1;

        systemConfig.PID[HEADING_PID].P              =   3.0f;
        systemConfig.PID[HEADING_PID].I              =   0.0f;
        systemConfig.PID[HEADING_PID].D              =   0.0f;
        systemConfig.PID[HEADING_PID].iTerm          =   0.0f;
        systemConfig.PID[HEADING_PID].windupGuard    =   0.5f;  // radians/sec
        systemConfig.PID[HEADING_PID].lastError      =   0.0f;
        systemConfig.PID[HEADING_PID].dTerm1         =   0.0f;
        systemConfig.PID[HEADING_PID].dTerm2         =   0.0f;
        systemConfig.PID[HEADING_PID].type           =   1;

        systemConfig.biLeftServoMin  = 2000.0f;
        systemConfig.biLeftServoMid  = 3000.0f;
        systemConfig.biLeftServoMax  = 4000.0f;

        systemConfig.biRightServoMin = 2000.0f;
        systemConfig.biRightServoMid = 3000.0f;
        systemConfig.biRightServoMax = 4000.0f;

        systemConfig.triYawServoMin       = 2000.0f;
        systemConfig.triYawServoMid       = 3000.0f;
        systemConfig.triYawServoMax       = 4000.0f;

        systemConfig.gimbalRollServoMin   = 2000.0f;
		systemConfig.gimbalRollServoMid   = 3000.0f;
		systemConfig.gimbalRollServoMax   = 4000.0f;
		systemConfig.gimbalRollServoGain  = 1.0f;

		systemConfig.gimbalPitchServoMin  = 2000.0f;
		systemConfig.gimbalPitchServoMid  = 3000.0f;
		systemConfig.gimbalPitchServoMax  = 4000.0f;
		systemConfig.gimbalPitchServoGain = 1.0f;

        // Free Mix Defaults to Quad X
		systemConfig.freeMixMotors = 4;

		systemConfig.freeMix[0][ROLL]  =  1.0f;
        systemConfig.freeMix[0][PITCH] = -1.0f;
        systemConfig.freeMix[0][YAW]   = -1.0f;

        systemConfig.freeMix[1][ROLL]  = -1.0f;
        systemConfig.freeMix[1][PITCH] = -1.0f;
        systemConfig.freeMix[1][YAW]   =  1.0f;

        systemConfig.freeMix[2][ROLL]  = -1.0f;
        systemConfig.freeMix[2][PITCH] =  1.0f;
        systemConfig.freeMix[2][YAW]   = -1.0f;

        systemConfig.freeMix[3][ROLL]  =  1.0f;
        systemConfig.freeMix[3][PITCH] =  1.0f;
        systemConfig.freeMix[3][YAW]   =  1.0f;

        systemConfig.freeMix[4][ROLL]  =  0.0f;
        systemConfig.freeMix[4][PITCH] =  0.0f;
        systemConfig.freeMix[4][YAW]   =  0.0f;

        systemConfig.freeMix[5][ROLL]  =  0.0f;
        systemConfig.freeMix[5][PITCH] =  0.0f;
        systemConfig.freeMix[5][YAW]   =  0.0f;

        systemConfig.rollDirectionLeft   = -1.0f;
        systemConfig.rollDirectionRight  =  1.0f;
        systemConfig.pitchDirectionLeft  = -1.0f;
        systemConfig.pitchDirectionRight =  1.0f;
        systemConfig.wingLeftMinimum     =  2000.0f;
        systemConfig.wingLeftMaximum     =  4000.0f;
        systemConfig.wingRightMinimum    =  2000.0f;
        systemConfig.wingRightMaximum    =  4000.0f;

        writeSystemParams();
	}
}

///////////////////////////////////////////////////////////////////////////////
