#ifndef PWM_H
#define PWM_H
#include "stdint.h"

#define     SYSTEM_FREQ      48000000ul
#define     PWM_FREQ            20000ul
#define     FULL_DUTY        (SYSTEM_FREQ/PWM_FREQ-1)
#define     DUTY(percent)    (SYSTEM_FREQ/PWM_FREQ*percent/100-1)

// 1 high pwm, 0 low pwm
#define     PWM_MODE          1

void init_pwm(void);

// TIM15 is used to update the TIM1 channel setting
void init_tim15(void);

void set_duty(uint16_t duty); // max value (SYSTEM_FREQ / PWM_FREQ) - 1
void set_update_rate(uint16_t rate);

#define  SET_DUTY_PERCENT(percent)      set_duty(DUTY(percent))

#define PWM     0
#define ON      1
#define OFF     2

//
//  0 High side pwm output, low side off
//  1 High side off, low side always on
//  other value both high and low sides are off 
void pwm_force_output(uint8_t a, uint8_t b, uint8_t c);

#endif
