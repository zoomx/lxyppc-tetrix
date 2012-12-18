/* Copyright (c) 2006 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is confidential property of Nordic Semiconductor. The use,
 * copying, transfer or disclosure of such information is prohibited except by express written
 * agreement with Nordic Semiconductor.
 */

/** @file
 * MCU depenent source code for accessing the nRF24L01 radio
 *
 * @author Runar Kjellhaug
 *
 */

#include <stdint.h>
#include <Cygnal\C8051F320.h>

uint8_t hal_nrf_rw(uint8_t value)
{
  SPIDAT = value;
  while(!SPIF)                  // wait for byte transfer finished
    ;
  SPIF = 0;                     // and clear SPI flag

  return SPIDAT;                // return SPI read value.
}

void hal_spi_init(uint8_t spi_speed)
{
  SPI0CKR = spi_speed;          // Set SPI(nRF24L01) speed    

  SPI0CFG = 0x40;               // SPI Master mode
  NSSMD0 = 0;                   // 3-Wire SPI mode
  NSSMD1 = 0;                   // NSS not used..
    
  XBR0 |= 0x02;                 // XBAR SPI I/O enable
  SPIEN = 1;                 // SPI enable
}
