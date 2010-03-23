#ifndef   TASK_H
#define   TASK_H

extern  u32      mainStackPosition;
extern  u32      procStackPosition;
extern  u32*     currentTaskStack;
extern  u32*     nextTaskStack;

#define   SwitchToProc()    \
  currentTaskStack = &mainStackPosition;  \
  nextTaskStack = &procStackPosition; \
   /*Turn on the led */\
  GPIOF->BRR = GPIO_Pin_7;\
  SCB->ICSR |= ((u32)0x01<<(SystemHandler_PSV & 0x1F));

#define   SwitchToMain()    \
  currentTaskStack = &procStackPosition;  \
  nextTaskStack = &mainStackPosition; \
    /*Turn off the led */\
  GPIOF->BSRR = GPIO_Pin_7;\
  SCB->ICSR |= ((u32)0x01<<(SystemHandler_PSV & 0x1F));

void   InitialProcTask(void);

void    SendImage(void);

#endif
