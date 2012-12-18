/* Copyright (c) 2007 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT. 
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRENTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 * $LastChangedRevision: 2311 $
 */ 
 
/** @file
 * @ingroup L01
 * Implementation of C8051F320 hardware functions. This file implements the
 * system_init() function, that sets up hardware such as internal clocks,
 * timers, and IO ports.
 *
 * @author Per Kristian Schanke
 */
 
//#include "fap.h"
#include <Cygnal\c8051f320.h>
#include "stdint.h"
#include "stdbool.h"
#include "system.h"

static void sysclk_init(void);
static void port_init(void);
extern void hal_spi_init(uint8_t spi_speed);

//-----------------------------------------------------------------------------
// Definitions
//-----------------------------------------------------------------------------

// USB clock selections (SFR CLKSEL)
#define USB_4X_CLOCK       0x00         // Select 4x clock multiplier, for USB

// System clock selections (SFR CLKSEL)
#define SYS_INT_OSC        0x00         // Select to use internal oscillator

//-----------------------------------------------------------------------------
// Global Variable Declarations
//-----------------------------------------------------------------------------

void system_init (void)
{
  uint16_t temp;

  PCA0MD &= ~0x40;              // Disable Watchdog timer

  REG0CN |= 0x80;               // Internal Voltage Regulator Disabled

  sysclk_init();                // initialize system clock
  
  port_init();                  // configure cross bar
 
  TCON |= 0x01;                 // Int1 level triggered  xxx same as ir0 = 1

  // Radio IRQ setup
  IT0 = 1;                      // /INT0, edge sens    
  IE0 = 0;                      // clear pending interrupt  
  EX0 = 0;                      // Extern interrupt0 (nRF) enabled  
 
   // PS2 IRQ setup
  IT1 = 1;                      // Int1 edge sens
  IE1 = 0;
  EX1 = 0;                      // PS2 IRQ
  PX1=1;                        // Int1 priority bit set (ps2)    
  
  hal_spi_init(0);              // SPI Init, 3-wire mode, CK/2 speed

  temp=0xffff;                  // Waiting ...  
  while(--temp)                 // nRF radio is booting up
    ;                           // temp value can be tuned.
}

void sysclk_init (void)
{
#ifdef _USB_LOW_SPEED_
  
  OSCICN |= 0x03;                       // Configure internal oscillator for
                                        // its maximum frequency and enable
                                        // missing clock detector
  
  CLKSEL  = SYS_EXT_OSC;                // Select System clock
  CLKSEL |= USB_INT_OSC_DIV_2;          // Select USB clock
#else
  OSCICN |= 0x03;                       // Configure internal oscillator for
                                        // its maximum frequency and enable
                                        // missing clock detector
  
  CLKMUL  = 0x00;                       // Select internal oscillator as
                                        // input to clock multiplier
  
  CLKMUL |= 0x80;                       // Enable clock multiplier
  
  delay_100ms();                       // Delay for clock multiplier to begin
  
  CLKMUL |= 0xC0;                       // Initialize the clock multiplier
  
  while(!(CLKMUL & 0x20))               // Wait for multiplier to lock
    ;
  CLKSEL  = SYS_INT_OSC;                // Select system clock
  CLKSEL |= USB_4X_CLOCK;               // Select USB clock
#endif  /* _USB_LOW_SPEED_ */
}

void port_init (void)
{
  P0MDIN = 0xff;                        // Port 0 set as digital IO
  P1MDIN = 0xff;                        // Port 1 set as digital IO
  P2MDIN = 0xff;                        // Port 2 set as digital IO

  P0MDOUT = 0x8D;                       // P0.0(SCK), P0.2(MOSI), P0.3(CSN), P0.4(CE) Outputs, P0.5(IRQ) rest inputs
  P1MDOUT = 0x63;                       // P1.0(LED1), P1.1(LED2), P1.2(LED3), P1.3(LED4) Outputs, rest inputs
  P2MDOUT = 0x00;                       // P2.1(SW1), P2.2(SW2), P2.3(SW3), P2[7..4] Rotary Switch, Inputs

  P0 = 0x6A;                            // P0.3(CSN), P0.5(IRQ) High(pullups), rest low
  P1 = 0x7F;                            // P1[3..0] LEDS OFF
  P2 = 0xff;                            // P2[3..1] low(ext.pullups), P2[7..4] pullups

  XBR0 = 0x00;                          // No periferi routed to crossbar
  XBR1 |= 0x40;                         // Enable Crossbar
  IT01CF = 0x65;                        // Int0 assigned to P0.5 and Int1 assigned to P0.6
                                        // Both active low 
}
