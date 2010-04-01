#ifndef   TASK_H
#define   TASK_H

extern  u32      mainStackPosition;
extern  u32      procStackPosition;
extern  u32*     currentTaskStack;
extern  u32*     nextTaskStack;

#define   SwitchToProc()    \
  if(currentTaskStack != &mainStackPosition){\
    currentTaskStack = &mainStackPosition;  \
    nextTaskStack = &procStackPosition; \
     /*Turn on the led */\
    Led2On();\
    SCB->ICSR |= ((u32)0x01<<(SystemHandler_PSV & 0x1F));\
  }

#define   SwitchToMain()    \
  if(currentTaskStack != &procStackPosition){\
    currentTaskStack = &procStackPosition;  \
    nextTaskStack = &mainStackPosition; \
      /*Turn off the led */\
    Led2Off();\
    SCB->ICSR |= ((u32)0x01<<(SystemHandler_PSV & 0x1F));\
  }

void   InitialProcTask(void);

void    SendImage(void);



// Messge process
typedef   unsigned long   Msg;
#define     MSG_STACK_SIZE    16
#define     MSG_STACK_MASK    15
extern  volatile unsigned char wrMsgIndex;
extern  unsigned char rdMsgIndex;
extern  Msg     msgStack[MSG_STACK_SIZE];
/*******************************************************************************
* Function Name  : GetMessage
* Description    : Get message
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
#define   GetMessage()  \
    ((wrMsgIndex != rdMsgIndex) ? \
      msgStack[rdMsgIndex++ & MSG_STACK_MASK] : 0)

#define  PostMessage(msg)   \
  {\
    msgStack[wrMsgIndex & MSG_STACK_MASK] = msg;\
    wrMsgIndex++;\
  }

#endif
