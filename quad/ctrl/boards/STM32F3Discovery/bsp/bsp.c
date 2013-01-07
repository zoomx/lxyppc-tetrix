#include "bsp.h"

void delay_ms(uint32_t ms)
{
    delay_us(ms * 1000);
}

void delay_us(uint32_t usec)
{
  uint32_t count = 0;
  const uint32_t utime = (120 * usec / 7);
  do
  {
    if ( ++count > utime )
    {
      return ;
    }
  }
  while (1);
}
