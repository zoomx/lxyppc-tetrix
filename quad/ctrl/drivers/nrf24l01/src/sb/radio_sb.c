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

/** @ingroup SB 
 * @file
 * Initialise the radio in ShockBurst mode. This is done by opening @b pipe0 
 * without auto ACK and disabeling auto retransmits.
 *
 * @author Per Kristian Schanke
 */

#include "hal_nrf.h"
#include "radio_sb.h"
#include "system.h"
#include "radio.h"

void radio_sb_init (const uint8_t *address, hal_nrf_operation_mode_t operational_mode)
{
  hal_nrf_close_pipe(HAL_NRF_ALL);               // First close all radio pipes
                                                 // Pipe 0 and 1 open by default
  hal_nrf_open_pipe(HAL_NRF_PIPE0, false);       // Open pipe0, without/autoack

  hal_nrf_set_crc_mode(HAL_NRF_CRC_16BIT);       // Operates in 16bits CRC mode
  hal_nrf_set_auto_retr(0, RF_RETRANS_DELAY);    // Disables auto retransmit

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

//hal_nrf_set_datarate(HAL_NRF_1MBPS);           // Uncomment this line for 
                                                 // compatibility with nRF2401 
                                                 // and nRF24E1

  start_timer(RF_POWER_UP_DELAY);                // Wait for the radio to 
  wait_for_timer();                              // power up

  radio_set_status (RF_IDLE);                    // Radio now ready
}                                                
