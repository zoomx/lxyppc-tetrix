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
 * $LastChangedRevision: 2089 $
 */ 

#ifndef RADIO_PL_H__
#define RADIO_PL_H__

/** For turning on dynamic payload on all pipes. Sets bits 0-6 */
#define ALL_PIPES (0x3F)

/** Initializes the radio in Enhanced ShockBurst mode with ACK payload. This mean that we 
 * enable auto-retransmit and auto-acknowledgment as in Enhanced ShockBurst, and the 
 * features auto-ack payload and dynamic payload width.
 *
 * @param address The radios working address
 * @param operational_mode The operational mode, either @c HAL_NRF_PRX or @c HAL_NRF_PTX
 */
void radio_pl_init (const uint8_t *address, hal_nrf_operation_mode_t operational_mode);

#endif
