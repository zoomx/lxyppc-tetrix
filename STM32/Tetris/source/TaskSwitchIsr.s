;******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
;* File Name          : TaskSwitchIsr.s
;* Author             : lxyppc
;* Version            : V0.01
;* Date               : 03/23/2010
;* Description        : Isr wrappers
;*******************************************************************************

; export functions

  RSEG CODE:CODE(2)
  
  EXPORT  PendSVC
  EXPORT  __CLZ
  IMPORT  currentTaskStack
  IMPORT  nextTaskStack
  
  

;*******************************************************************************
; Function Name  : PendSVC
; Description    : PendSVC interrupt handler.
; Input          : None
; Return         : None
;*******************************************************************************
PendSVC
    ; Disable interrupts
    MRS     r2, PRIMASK
    CPSID   I
    
    ; store context for current task
    ldr     r0, =currentTaskStack   ;
    ldr     r0,[r0]                 ;
    mrs     r1,msp                  ;
    STMFD   r1!, {r4 - r11}         ; store r4 ~ r11
    str     r1,[r0]
    
    ; load context from next task
    ldr     r0, =nextTaskStack      ;
    ldr     r0,[r0]                 ;
    ldr     r1,[r0]                 ;
    LDMFD   r1!, {r4 - r11}         ; load r4 ~ r11
    msr     msp,r1
    
    ; Enable interrupts
    MSR     PRIMASK, r2
    BX lr
    
__CLZ
    clz     r0,r0
    bx      lr
    
    
 END
 
 ; end of the assembly file