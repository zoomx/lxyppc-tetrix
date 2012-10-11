#ifndef PWM_H
#define PWM_H
#include "stdint.h"

#define     SYSTEM_FREQ      48000000ul
#define     PWM_FREQ            40000ul


void init_pwm(void);
void set_duty(uint16_t duty); // max value (SYSTEM_FREQ / PWM_FREQ) - 1
//
//  0 pwm output
//  1 always on
//  other value always off 

#define H_PWM   0
#define H_ON    1
#define H_OFF   2

#define L_PWM   (0<<4)
#define L_ON    (1<<4)
#define L_OFF   (2<<4)

void pwm_force_output(uint8_t a, uint8_t b, uint8_t c);

#endif
