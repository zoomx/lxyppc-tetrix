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

typedef void(* isr_callback_t)(void);

// TIM15 is used to update the TIM1 channel setting
void init_tim15(void);
void set_duty(uint16_t duty, uint16_t cc4_duty); // max value (SYSTEM_FREQ / PWM_FREQ) - 1
void set_update_rate(uint16_t rate);
void switch_phase_6_step(void);
void set_phase_update_freq(uint32_t freq, isr_callback_t callback);

#define  SET_DUTY_PERCENT(percent)      set_duty(DUTY(percent))

#define PWM     0
#define ON      1
#define OFF     2

#define  A_B    PWM,ON,OFF
#define  C_B    OFF,ON,PWM
#define  C_A    ON,OFF,PWM
#define  B_A    ON,PWM,OFF
#define  B_C    OFF,PWM,ON
#define  A_C    PWM,OFF,ON

extern isr_callback_t  on_phase_update_done;
extern isr_callback_t  on_tim1_cc4;
//
//  0 High side pwm output, low side off
//  1 High side off, low side always on
//  other value both high and low sides are off 
void pwm_force_output(uint8_t a, uint8_t b, uint8_t c);

void update_pwm(uint8_t a, uint8_t b, uint8_t c);

#endif
