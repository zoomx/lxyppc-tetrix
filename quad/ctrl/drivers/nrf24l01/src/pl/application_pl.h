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
 * $LastChangedRevision: 2088 $
 */ 

#ifndef APPLICATION_PL_H__
#define APPLICATION_PL_H__

/** This function is called if the application is entering the PTX mode.
 * This is an endless loop, TX mode (PTX) function.
*/
void device_ptx_mode_pl(void);

/** This function is called if the application is entering the PRX mode.
 * This is an endless loop, RX mode (PRX) function.
*/
void device_prx_mode_pl(void);

#endif
