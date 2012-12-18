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
 * $LastChangedRevision: 2185 $
 */ 

/** @ingroup ESB 
 * @file
 * Initialise the radio in Enhanced ShockBurst mode. This is done by opening 
 * @b pipe0 with auto ACK and with auto retransmits.
 *
 * @author Per Kristian Schanke
 */

#include "hal_nrf.h"
#include "radio_esb.h"
#include "radio.h"

void radio_esb_init (const uint8_t *address, hal_nrf_operation_mode_t operational_mode)
{
  hal_nrf_close_pipe(HAL_NRF_ALL);               // First close all radio pipes
                                                 // Pipe 0 and 1 open by default
  hal_nrf_open_pipe(HAL_NRF_PIPE0, true);        // Then open pipe0, w/autoack
                                                 // Changed from sb/radio_sb.c

  hal_nrf_set_crc_mode(HAL_NRF_CRC_16BIT);       // Operates in 16bits CRC mode
  hal_nrf_set_auto_retr(RF_RETRANSMITS, RF_RETRANS_DELAY);                 
                                                 // Enables auto retransmit.
                                                 // 3 retrans with 250ms delay
                                                 // Changed from sb/radio_sb.c

  hal_nrf_set_address_width(HAL_NRF_AW_5BYTES);  // 5 bytes address width
  hal_nrf_set_address(HAL_NRF_TX, address);      // Set device's addresses
  hal_nrf_set_address(HAL_NRF_PIPE0, address);   // Sets recieving address on 
                                                 // pipe0
  
  if(operational_mode == HAL_NRF_PTX)            // Mode depentant settings
  {
    hal_nrf_set_operation_mode(HAL_NRF_PTX);     // Enter TX mode
  }
  else
  {
    hal_nrf_set_operation_mode(HAL_NRF_PRX);     // Enter RX mode
    hal_nrf_set_rx_pload_width((uint8_t)HAL_NRF_PIPE0, RF_PAYLOAD_LENGTH);
                                                 // Pipe0 expect 
                                                 // PAYLOAD_LENGTH byte payload
                                                 // PAYLOAD_LENGTH in radio.h
  }

  hal_nrf_set_rf_channel(RF_CHANNEL);            // Operating on static channel 
                                                 // Defined in radio.h.
                                                 // Frequenzy = 
                                                 //        2400 + RF_CHANNEL
  hal_nrf_set_power_mode(HAL_NRF_PWR_UP);        // Power up device

  //start_timer(RF_POWER_UP_DELAY);                // Wait for the radio to 
  //wait_for_timer();                              // power up
  delay_ms(RF_POWER_UP_DELAY);
  
  radio_set_status (RF_IDLE);                     // Radio now ready
}


static radio_status_t status = 0;
radio_status_t radio_get_status (void)
{
  return status;
}

void radio_set_status (radio_status_t new_status)
{
  status = new_status;
}
