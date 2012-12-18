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

#ifndef RADIO_H__
#define RADIO_H__
 
 /** @file
 * @ingroup main
 * Radio header file for the nRF24LU1 example application
 * 
 * @author Per Kristian Schanke
 */

/** Defines the channel the radio should operate on*/
#define RF_CHANNEL 40

/** Defines the time it takes for the radio to come up to operational mode */
#define RF_POWER_UP_DELAY 2

/** Defines the payload length the radio should use */
#define RF_PAYLOAD_LENGTH 10                           

/** Defines how many retransmitts that should be performed */
#define RF_RETRANSMITS 15

/** Defines the retransmit delay. Should be a multiple of 250. If the 
 * RF_PAYLOAD_LENGTH is larger than 18, a higher retransmitt delay need to
 * be set. This is because both the original package and ACK payload will
 * be of this size. When the ACK payload exeedes 18 byte, it will not be able
 * to recieve the full ACK in the ordinary 250 mikroseconds, so the delay
 * will need to be increased. */
#if (RF_PAYLOAD_LENGTH <= 18)
#define RF_RETRANS_DELAY 250
#else
#define RF_RETRANS_DELAY 500
#endif

/** Enumerates the different states the radio may
 * be in.
 */
typedef enum {
  RF_IDLE,    /**< Radio is idle */
  RF_MAX_RT,  /**< Maximum number of retries have occured */
  RF_TX_DS,   /**< Data is sent */
  RF_RX_DR,   /**< Data recieved */
  RF_TX_AP,   /**< Ack payload recieved */
  RF_BUSY     /**< Radio is busy */
} radio_status_t;

/** Get the current status of the radio.
 *
 * @return Status of the radio. May be one of:
 * @retval RF_IDLE   Radio is idle
 * @retval RF_MAX_RT Maximum number of retries have occured
 * @retval RF_TX_DS  The data are sent
 * @retval RF_RX_DR  Data is recieved
 * @retval RF_TX_AP  Ack payload recieved
 * @retval RF_BUSY   Radio is busy
 */
radio_status_t radio_get_status (void);

/** Sets the status of the radio. Input parameter is
 * checked to see if it is allowed.
 *
 * @param new_status The new status of the radio
 */
void radio_set_status (radio_status_t new_status);

/** Gets the bit at position @a byte_index in @b pload. 
 *
 * @param byte_index The index of the bit
 * @return The value of @b pload[byte_index]
 */
uint8_t radio_get_pload_byte (uint8_t byte_index);

/** This function load the data to be sent into the radio, sends it, and waits for
 * the response.
 * @param packet The data to send. Maximum 2 byte
 * @param length The length of the data
*/
void radio_send_packet(uint8_t *packet, uint8_t length);

/** This function reads the interrupts. It does the work
 * of a interrupt handler by manually reading the interrupt
 * flags and act on them. Sets the status with \
 */
void radio_irq (void);

#endif
