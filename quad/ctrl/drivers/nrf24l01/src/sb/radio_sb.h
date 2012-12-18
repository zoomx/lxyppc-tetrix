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

#ifndef RADIO_SB_H__
#define RADIO_SB_H__

/** Initializes the radio in ShockBurst mode. This mean that there are no auto-retransmit
 * or auto-acknowledgment enabled.
 *
 * @param address The radios working address
 * @param operational_mode The operational mode, either @c HAL_NRF_PRX or @c HAL_NRF_PTX
 */
void radio_sb_init (const uint8_t *address, hal_nrf_operation_mode_t operational_mode);

#endif
