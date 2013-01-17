#ifndef PWM_H
#define PWM_H

#include "stm32f30x.h"
#include "stdint.h"

#define  INPUT_TIMER_BIT    32
void pwm_input_init(void);
void pwm_output_init(void);

/**
  * @brief  Get input ppm values
  * @param  values: point to buffer to receive the data
  * @param  count: buffer size
  * @retval real ppm values counts, maybe larger than count
  */

uint32_t get_pwm_values(uint16_t* values, uint32_t count);

#endif
