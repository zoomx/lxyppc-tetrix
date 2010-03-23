#include "stm32f10x_lib.h"
#include "usb_lib.h"
#include "usb_desc.h"
#include "hw_config.h"
#include "usb_prop.h"
#include "stm32f10x_it.h"
#include "Task.h"

/* Private typedef -----------------------------------------------------------*/
typedef   struct _TaskContext
{
  /// Remain context
  u32 R4;
  u32 R5;
  u32 R6;
  u32 R7;
  u32 R8;
  u32 R9;
  u32 R10;
  u32 R11;
  
  /// Auto protected context
  u32 R0;
  u32 R1;
  u32 R2;
  u32 R3;
  u32 R12;          /// R12
  u32 LR;           /// LR
  u32 EntryPoint;   /// PC
  u32 xPSR;         /// xPSR
  
}TaskContext , *PTaskContext;

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Extern variables ----------------------------------------------------------*/
u32      mainStackPosition;
u32      procStackPosition;
u32*     currentTaskStack;
u32*     nextTaskStack;

/* Private function prototypes -----------------------------------------------*/
/* Extern function prototypes ------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

#pragma language=extended
#pragma segment="CSTACK"

void   InitialProcTask(void)
{
  TaskContext* pTask;
  procStackPosition = (u32)__sfe( "CSTACK" ) + 1024; // Allocate 1K for the Process
  procStackPosition -= sizeof(TaskContext);
  pTask = (TaskContext*) procStackPosition;
  pTask->EntryPoint = (u32)SendImage;
  pTask->R0 = 0x00;
  pTask->R1 = 0x01;
  pTask->R2 = 0x02;
  pTask->R3 = 0x03;
  pTask->R4 = 0x04;
  pTask->R5 = 0x05;
  pTask->R6 = 0x06;
  pTask->R7 = 0x07;
  pTask->R8 = 0x08;
  pTask->R9 = 0x09;
  pTask->R10 = 0x10;
  pTask->R11 = 0x11;
  pTask->R12 = 0x12;
  pTask->xPSR = 0x01000000;
  nextTaskStack = &mainStackPosition;
}
