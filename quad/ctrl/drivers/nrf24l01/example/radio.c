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
 * $LastChangedRevision: 2310 $
 */ 

 /** @file
 * @ingroup Main
 * Radio functions.
 *
 * This file handles all radio communication for the example application, i.e. 
 * radio_init, radio_send_packet and radio_interrupt function.
 *
 * @author Per Kristian Schanke
 */

#include "hal_nrf.h"
#include "system.h"
#include "radio.h"
#include "target_includes.h"

/** The payload sent over the radio. Also contains the recieved data. 
 * Should be read with radio_get_pload_byte(). */
static xdata uint8_t pload[RF_PAYLOAD_LENGTH];
/** The current status of the radio. Should be set with radio_set_status(), 
 * and read with radio_get_status().
 */
static radio_status_t status;

void radio_send_packet(uint8_t *packet, uint8_t length)
{
  hal_nrf_write_tx_pload(packet, length);      // load message into radio
  
  CE_PULSE();                                 // send packet

  radio_set_status (RF_BUSY);                 // trans. in progress; RF_BUSY
}

radio_status_t radio_get_status (void)
{
  return status;
}

uint8_t radio_get_pload_byte (uint8_t byte_index)
{
  return pload[byte_index];
}

void radio_set_status (radio_status_t new_status)
{
  status = new_status;
}

void radio_irq(void) 
{
  if (RADIO_ACTIVITY())                         // Check if an interupt is
  {                                             // triggered
    switch(hal_nrf_get_clear_irq_flags ())
    {
      case (1<<HAL_NRF_MAX_RT):                 // Max retries reached
        hal_nrf_flush_tx();                     // flush tx fifo, avoid fifo jam
        radio_set_status (RF_MAX_RT);
        break;
      
      case (1<<HAL_NRF_TX_DS):                  // Packet sent
        radio_set_status (RF_TX_DS);
        break;
      
      case (1<<HAL_NRF_RX_DR):                  // Packet received
        while (!hal_nrf_rx_fifo_empty ())
        {
          hal_nrf_read_rx_pload(pload);
        }
        radio_set_status (RF_RX_DR);
        break;
  
      case ((1<<HAL_NRF_RX_DR)|(1<<HAL_NRF_TX_DS)): // Ack payload recieved
        while (!hal_nrf_rx_fifo_empty ())
        {
          hal_nrf_read_rx_pload(pload);
        }
        radio_set_status (RF_TX_AP);
        break;
  
      default:
        break;    
    }

    RESET_RADIO_ACTIVITY();
  }
}
