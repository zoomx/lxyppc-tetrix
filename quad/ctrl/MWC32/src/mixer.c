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

uint8_t numberMotor;

float motor[6] = { 2000.0f, 2000.0f, 2000.0f, 2000.0f, 2000.0f, 2000.0f };

float servo[2] = { 3000.0f, 3000.0f };

///////////////////////////////////////////////////////////////////////////////
// Initialize Mixer
///////////////////////////////////////////////////////////////////////////////

void initMixer(void)
{
    // enable servos for mixes that require them. note, this shifts motor counts.
    if ( systemConfig.mixerConfiguration == MULTITYPE_GIMBAL    ||
         systemConfig.mixerConfiguration == MULTITYPE_BI        ||
         systemConfig.mixerConfiguration == MULTITYPE_TRI       ||
         systemConfig.mixerConfiguration == MULTITYPE_QUADP     ||
         systemConfig.mixerConfiguration == MULTITYPE_QUADX     ||
         systemConfig.mixerConfiguration == MULTITYPE_Y4        ||
         systemConfig.mixerConfiguration == MULTITYPE_VTAIL4    ||
        (systemConfig.mixerConfiguration == MULTITYPE_FREEMIX   &&
         systemConfig.freeMixMotors < 5)                        ||
         systemConfig.mixerConfiguration == MULTITYPE_FLYING_WING )   pwmOutputConfig.useServos = true;

    else  pwmOutputConfig.useServos = false;
    
    pwmOutputConfig.useServos = false;
    pwmOutputConfig.noEsc = 1;
    pwmOutputConfig.motorPwmRate = 10*1000; // Use 10K pwm rate for motor

    switch (systemConfig.mixerConfiguration)
    {
        case MULTITYPE_GIMBAL:
            numberMotor = 0;
            break;

        case MULTITYPE_BI:
            numberMotor = 2;
            break;

        case MULTITYPE_TRI:
            numberMotor = 3;
            break;

        case MULTITYPE_QUADP:
        case MULTITYPE_QUADX:
        case MULTITYPE_Y4:
        case MULTITYPE_VTAIL4:
            numberMotor = 4;
            break;

        case MULTITYPE_Y6:
        case MULTITYPE_HEX6P:
        case MULTITYPE_HEX6X:
            numberMotor = 6;
            break;

        case MULTITYPE_FREEMIX:
        	numberMotor = systemConfig.freeMixMotors;
        	break;

        case MULTITYPE_FLYING_WING:
           numberMotor = 1;
           break;
    }
}

///////////////////////////////////////////////////////////////////////////////
// Write to Servos
///////////////////////////////////////////////////////////////////////////////

void writeServos(void)
{
    if (!pwmOutputConfig.useServos)
        return;

    pwmWrite(0, (uint16_t)servo[0]);
    pwmWrite(1, (uint16_t)servo[1]);
}

///////////////////////////////////////////////////////////////////////////////
// Write to Motors
///////////////////////////////////////////////////////////////////////////////

void writeMotors(void)
{
    uint8_t i;
    uint8_t offset = 0;

    // when servos are enabled, pwm outputs 1 and 2 are for servos only
    if (pwmOutputConfig.useServos)
        offset = 2;

    for (i = 0; i < numberMotor; i++)
        pwmWrite(i + offset, (uint16_t)motor[i]);
}

///////////////////////////////////////////////////////////////////////////////
// Write to All Motors
///////////////////////////////////////////////////////////////////////////////

void writeAllMotors(float mc)
{
    uint8_t i;

    // Sends commands to all motors
    for (i = 0; i < numberMotor; i++)
        motor[i] = mc;
    writeMotors();
}

///////////////////////////////////////////////////////////////////////////////
// Pulse Motors
///////////////////////////////////////////////////////////////////////////////

void pulseMotors(uint8_t quantity)
{
    uint8_t i;

    for ( i = 0; i < quantity; i++ )
    {
        writeAllMotors( systemConfig.minThrottle );
        delay(250);
        writeAllMotors( (float)MINCOMMAND );
        delay(250);
    }
}

///////////////////////////////////////////////////////////////////////////////
// Mixer
///////////////////////////////////////////////////////////////////////////////

#define PIDMIX(X,Y,Z) rxCommand[THROTTLE] + axisPID[ROLL] * X + axisPID[PITCH] * Y + systemConfig.yawDirection * axisPID[YAW] * Z

void mixTable(void)
{
    int16_t maxMotor;
    uint8_t i;

    ///////////////////////////////////
    /*
    if ( numberMotor > 3 )
    {
        //prevent "yaw jump" during yaw correction
        axisPID[YAW] = constrain(axisPID[YAW], -100 - fabs(rcCommand[YAW]), +100 + fabs(rcCommand[YAW]));
    }
    */
    ///////////////////////////////////

    switch ( systemConfig.mixerConfiguration )
    {
        case MULTITYPE_BI:
            motor[0] = PIDMIX(  1.0f, 0.0f, 0.0f );        // Left Motor
            motor[1] = PIDMIX( -1.0f, 0.0f, 0.0f );        // Right Motor

            servo[0] = constrain( systemConfig.biLeftServoMid + (systemConfig.yawDirection * axisPID[YAW]) + axisPID[PITCH],
                                  systemConfig.biLeftServoMin, systemConfig.biLeftServoMax );   // Left Servo
            servo[1] = constrain( systemConfig.biRightServoMid + (systemConfig.yawDirection * axisPID[YAW]) - axisPID[PITCH],
                                  systemConfig.biRightServoMin, systemConfig.biRightServoMax );   // Right Servo
            break;

        case MULTITYPE_TRI:
            motor[0] = PIDMIX(  1.0f, -0.666667f, 0.0f );  // Left  CW
            motor[1] = PIDMIX( -1.0f, -0.666667f, 0.0f );  // Right CCW
            motor[2] = PIDMIX(  0.0f,  1.333333f, 0.0f );  // Rear  CW or CCW

            servo[0] = constrain( systemConfig.triYawServoMid + systemConfig.yawDirection * axisPID[YAW],
                                  systemConfig.triYawServoMin, systemConfig.triYawServoMax ); // Tail Servo
            break;

        case MULTITYPE_QUADP:
            motor[0] = PIDMIX(  0.0f, -1.0f, -1.0f );      // Front CW
            motor[1] = PIDMIX( -1.0f,  0.0f,  1.0f );      // Right CCW
            motor[2] = PIDMIX(  0.0f,  1.0f, -1.0f );      // Rear  CW
            motor[3] = PIDMIX(  1.0f,  0.0f,  1.0f );      // Left  CCW
            break;

        case MULTITYPE_QUADX:
            motor[0] = PIDMIX(  1.0f, -1.0f, -1.0f );      // Front Left  CW
            motor[1] = PIDMIX( -1.0f, -1.0f,  1.0f );      // Front Right CCW
            motor[2] = PIDMIX( -1.0f,  1.0f, -1.0f );      // Rear Right  CW
            motor[3] = PIDMIX(  1.0f,  1.0f,  1.0f );      // Rear Left   CCW
            break;

        case MULTITYPE_Y4:
            motor[0] = PIDMIX(  1.0f, -1.0f,  0.0f );      // Front Left  CW
            motor[1] = PIDMIX( -1.0f, -1.0f,  0.0f );      // Front Right CCW
            motor[2] = PIDMIX(  0.0f,  1.0f, -1.0f );      // Top Rear    CW
            motor[3] = PIDMIX(  0.0f,  1.0f,  1.0f );      // Bottom Rear CCW
            break;

        case MULTITYPE_Y6:
            motor[0] = PIDMIX(  1.0f, -0.666667, -1.0f );  // Top Left     CW
            motor[1] = PIDMIX( -1.0f, -0.666667, -1.0f );  // Top Right    CW
            motor[2] = PIDMIX(  0.0f,  1.333333,  1.0f );  // Top Rear     CCW
            motor[3] = PIDMIX(  1.0f, -0.666667,  1.0f );  // Bottom Left  CCW
            motor[4] = PIDMIX( -1.0f, -0.666667,  1.0f );  // Bottom Right CCW
            motor[5] = PIDMIX(  0.0f,  1.333333, -1.0f );  // Bottom Rear  CW
            break;

        case MULTITYPE_HEX6P:
            motor[0] = PIDMIX(  0.0f, -0.866025f, -1.0f ); // Front       CW
            motor[1] = PIDMIX( -1.0f, -0.866025f,  1.0f ); // Front Right CCW
            motor[2] = PIDMIX( -1.0f,  0.866025f, -1.0f ); // Rear Right  CW
            motor[3] = PIDMIX(  0.0f,  0.866025f,  1.0f ); // Rear        CCW
            motor[4] = PIDMIX(  1.0f,  0.866025f, -1.0f ); // Rear Left   CW
            motor[5] = PIDMIX(  1.0f, -0.866025f,  1.0f ); // Front Left  CCW
            break;

        case MULTITYPE_HEX6X:
            motor[0] = PIDMIX(  0.866025f, -1.0f, -1.0f ); // Front Left  CW
            motor[1] = PIDMIX( -0.866025f, -1.0f,  1.0f ); // Front Right CCW
            motor[2] = PIDMIX( -0.866025f,  0.0f, -1.0f ); // Right       CW
            motor[3] = PIDMIX( -0.866025f,  1.0f,  1.0f ); // Rear Right  CCW
            motor[4] = PIDMIX(  0.866025f,  1.0f, -1.0f ); // Rear Left   CW
            motor[5] = PIDMIX(  0.866025f,  0.0f,  1.0f ); // Left        CCW
            break;

        case MULTITYPE_VTAIL4:
            motor[0] = PIDMIX(  1.0f, -1.0f,  0.6428f );   // Front Left  CCW - NOTE rotation difference from all other configurations
            motor[1] = PIDMIX( -1.0f, -1.0f, -0.6428f );   // Front Right CW  - NOTE rotation difference from all other configurations
            motor[2] = PIDMIX(  0.0f,  1.0f,  1.0f    );   // Rear Right  CCW - NOTE rotation difference from all other configurations
            motor[3] = PIDMIX(  0.0f,  1.0f, -1.0f    );   // Rear Left   CW  - NOTE rotation difference from all other configurations
            break;

        case MULTITYPE_FREEMIX:
        	for ( i = 0; i < numberMotor; i++ )
        	{
        		motor[i] = PIDMIX ( systemConfig.freeMix[i][ROLL],
        				            systemConfig.freeMix[i][PITCH],
        				            systemConfig.freeMix[i][YAW] );
        	}
        	break;

        case MULTITYPE_GIMBAL:
            servo[0] = constrain( systemConfig.gimbalRollServoMid + systemConfig.gimbalRollServoGain * sensors.attitude200Hz[ROLL] + rxCommand[ROLL],
                                  systemConfig.gimbalRollServoMin, systemConfig.gimbalRollServoMax );

            servo[1] = constrain( systemConfig.gimbalPitchServoMid + systemConfig.gimbalPitchServoGain * sensors.attitude200Hz[PITCH] + rxCommand[PITCH],
                                  systemConfig.gimbalPitchServoMin, systemConfig.gimbalPitchServoMax );
            break;

        case MULTITYPE_FLYING_WING:
            motor[0] = rxCommand[THROTTLE];
            if (flightMode != ATTITUDE)
            { // do not use sensors for correction, simple 2 channel mixing
            	servo[0] = systemConfig.pitchDirectionLeft  * (rxCommand[PITCH] - systemConfig.midCommand) +
            			   systemConfig.rollDirectionLeft   * (rxCommand[ROLL ] - systemConfig.midCommand);
            	servo[1] = systemConfig.pitchDirectionRight * (rxCommand[PITCH] - systemConfig.midCommand) +
            			   systemConfig.rollDirectionRight  * (rxCommand[ROLL]  - systemConfig.midCommand);
            }
            else
            { // use sensors to correct (attitude only)
            	servo[0] = systemConfig.pitchDirectionLeft  * axisPID[PITCH] +
            			   systemConfig.rollDirectionLeft   * axisPID[ROLL];
            	servo[1] = systemConfig.pitchDirectionRight * axisPID[PITCH] +
            			   systemConfig.rollDirectionRight  * axisPID[ROLL];
            }
            servo[0] = constrain(servo[0] + systemConfig.midCommand, systemConfig.wingLeftMinimum,
            		                                                 systemConfig.wingLeftMaximum);
            servo[1] = constrain(servo[1] + systemConfig.midCommand, systemConfig.wingRightMinimum,
            		                                                 systemConfig.wingRightMaximum);
            break;
    }

    ///////////////////////////////////

    // this is a way to still have good gyro corrections if any motor reaches its max.

    maxMotor = motor[0];

    for (i = 1; i < numberMotor; i++)
        if (motor[i] > maxMotor)
            maxMotor = motor[i];

    for (i = 0; i < numberMotor; i++)
    {
        if (maxMotor > systemConfig.maxThrottle)
            motor[i] -= maxMotor - systemConfig.maxThrottle;

        motor[i] = constrain(motor[i], systemConfig.minThrottle, systemConfig.maxThrottle);

        if ((rxCommand[THROTTLE]) < systemConfig.minCheck)
        {
            motor[i] = systemConfig.minThrottle;
        }

        if ( armed == false )
            motor[i] = (float)MINCOMMAND;
    }
}

///////////////////////////////////////////////////////////////////////////////
