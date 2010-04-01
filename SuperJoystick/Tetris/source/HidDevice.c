/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : HidDevice.c
* Author             : lxyppc
* Version            : V1.0
* Date               : 04/01/2010
* Description        : Usb Hid device implemetion, simulation mouse,keyboard and
*                      joystick in same device
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_lib.h"
#include "usb_lib.h"
#include "usb_desc.h"
#include "hw_config.h"
#include "usb_prop.h"
#include "stm32f10x_it.h"
#include "Tetris.h"
#include "HidDevice.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define   BOOT_PROTOCOL           0
#define   REPORT_PROTOCOL         1

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static  u8  mouseProtocol = 0;      // 0 for boot, 1 for report
static  u8  keyboardProtocol = 0;   // 0 for boot, 1 for report
static  u8  mouseIdle = 0;          // 4ms for LSB
static  u8  joystickIdle = 0;       // 4ms for LSB
static  u8  keyboardIdle = 0;       // 4ms for LSB
static  u8  keyboardLED = 0;        // current led status
static  u8  keyboardLedChange = 1;

/* Extern variables ----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/**
  Set report sample when LED status of keyboard changes
  
                        OUTPUT
            reportID  reportType   Interface   data length
      21 09    00        02         03 00        01 00
 */


/*******************************************************************************
* Function Name  : GetIdle.
* Description    : Get idle value for specify interface and ID.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
u8    GetIdle(u8 interface, u8 ID)
{
  switch(interface){
  case MOUSE_INT:
    if(ID == MOUSE_REPORT_ID){
      return mouseIdle;
    }else if(ID == JOYSTICK_REPORT_ID){
      return joystickIdle;
    }
    return 0;
  case KEYBOARD_INT:
    return keyboardIdle;
  }
  return 0;
}

/*******************************************************************************
* Function Name  : GetProtocol.
* Description    : Get protocol value for specify interface.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
u8    GetProtocol(u8 interface)
{
  switch(interface){
  case MOUSE_INT:
    return mouseProtocol;
  case KEYBOARD_INT:
    return keyboardProtocol;
  }
  return 0;
}

void  SetIdle(u8 interface, u8 ID, u8 data)
{
  switch(interface){
  case MOUSE_INT:
    if(ID == MOUSE_REPORT_ID){
      mouseIdle = data;
    }else if(ID == JOYSTICK_REPORT_ID){
      joystickIdle = data;
    }
    break;
  case KEYBOARD_INT:
    keyboardIdle = data;
    break;
  }
  return;
}

void  SetProtocol(u8 interface, u8 data)
{
  switch(interface){
  case MOUSE_INT:
    mouseProtocol = data;
    break;
  case KEYBOARD_INT:
    keyboardProtocol = data;
    break;
  }
  return;
}

// This routine only used when set the keyboard LED status
void  SetReport(u8 interface, u8 ID, u8 value)
{
  if(interface == KEYBOARD_INT){
    keyboardLedChange = 1;
    keyboardLED = value;
  }
}

void  HidProcess(void)
{
  if(keyboardLedChange){
    keyboardLedChange = 0;
    if(keyboardLED&NUM_LOCK){
      Led3On();
    }else{
      Led3Off();
    }
    if(keyboardLED&CAPS_LOCK){
      Led4On();
    }else{
      Led4Off();
    }
    if(keyboardLED&SCROLL_LOCK){
      Led5On();
    }else{
      Led5Off();
    }
  }
}
