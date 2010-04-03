/*******************************************************************************
* File Name          : StringResource.c
* Author             : lxyppc
* Version            : V1.0
* Date               : 10-01-21
* Description        : String resouce file
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "StringResource.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

const LPCSTR StringTable_ENG[STR_LAST] ={	
  [STR_CAMERA_ON]       = "Camera On",
  [STR_CAMERA_OFF]      = "Camera Off",
  [STR_JOYSTICK]        = "Joystick",
  [STR_MOUSE]           = "Mouse",
  [STR_AIR_MOUSE]       = "Air Mouse",
  [STR_KEYBOARD]        = "Keyboard",
  [STR_KB_NORMAL]       = "Normal",
  [STR_KB_SEQ]          = "Senquence",
};

const LPCSTR StringTable_CHS[STR_LAST] ={	
  [STR_CAMERA_ON]     = "摄像头开",
  [STR_CAMERA_OFF]    = "摄像头关",
  [STR_JOYSTICK]      = "游戏手柄",
  [STR_MOUSE]         = "鼠标",
  [STR_AIR_MOUSE]     = "感应鼠标",
  [STR_KEYBOARD]      = "键盘",
  [STR_KB_NORMAL]     = "正常",
  [STR_KB_SEQ]        = "顺序",
};
