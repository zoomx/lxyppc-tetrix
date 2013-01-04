/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright (c) Nuvoton Technology Corp. All rights reserved.                                             */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include "string.h"
#include "NUC1xx.h"
#include "Driver\DrvSYS.h"
#include "Driver\DrvSPI.h"
#include "Driver\DrvUART.h"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvPDMA.h"
#include "nrf24l01.h"
#include "nrf24l01_config.h"

#define TEST_COUNT 64

volatile uint32_t g_Spi0IntFlag;
volatile uint32_t g_Spi1IntFlag;
volatile uint32_t g_PdmaIntFlag;
uint32_t g_au32SlaveRxData[TEST_COUNT];
uint32_t g_u32SlaveRxDataCount;
const uint8_t addr[] = TX_ADDR;
void nrf_test_reg(void);

static uint8_t tx_done = 0;
void nrf_tx_done(uint8_t success)
{
    if(success){
        tx_done = 1;
    }else{
        tx_done = 2;
    }
}
static uint8_t rx_done = 0;
static uint8_t rx_len;
uint8_t rx_chn;
static uint8_t rx_buffer[32];
void nrf_on_rx_data(const void* data, uint32_t len, uint8_t channel)
{
    rx_done = 1;
    rx_len = len;
    rx_chn = channel;
    memcpy(rx_buffer,data,len);
}

int main(void)
{
    uint8_t buffer[32] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    /* Unlock the protected registers */
    UNLOCKREG();

    /* Enable the 12MHz oscillator oscillation */
    DrvSYS_SetOscCtrl(E_SYS_XTL12M, 1);
 
    /* Waiting for 12MHz Xtal stable */
    DrvSYS_Delay(5000);
 
    /* HCLK clock source. 0: external 12MHz. */
    DrvSYS_SelectHCLKSource(0);

    LOCKREG();

    DrvSYS_SetClockDivider(E_SYS_HCLK_DIV, 0); /* HCLK clock frequency = HCLK clock source / (HCLK_N + 1) */

    nrf_init();
    
    nrf_detect();
    
    //nrf_rx_mode_no_aa(addr,5,16,40);
    //nrf_rx_mode(addr,5,16,40);
    nrf_rx_mode_dual(addr,5,40);
    
    nrf_test_reg();
    
    DrvGPIO_Open(E_GPA, 2, E_IO_OUTPUT);
    DrvGPIO_Open(E_GPA, 3, E_IO_OUTPUT);
    DrvGPIO_Open(E_GPA, 4, E_IO_OUTPUT);
    DrvGPIO_Open(E_GPA, 5, E_IO_OUTPUT);
    {
        uint8_t status = nrf_read_reg(NRF_STATUS);
        nrf_write_reg(NRF_WRITE_REG|NRF_STATUS,status); // clear IRQ flags
        nrf_write_reg(NRF_FLUSH_RX, 0xff);
        nrf_write_reg(NRF_FLUSH_TX, 0xff);
    }
    
    while(1){
        uint8_t buffer[32];
        if(tx_done){
            static uint8_t yy = 0;
            yy++;
            if(yy&1){
                DrvGPIO_SetBit(E_GPA,2);
            }else{
                DrvGPIO_ClrBit(E_GPA,2);
            }
            if(tx_done == 1){
            }else{
            }
            buffer[0] = tx_done;
            tx_done = 0;
        }
        if(rx_done){
            static uint8_t xx = 0;
            rx_done = 0;
            xx++;
            if(xx & 1)
                DrvGPIO_SetBit(E_GPA,5);
            else
                DrvGPIO_ClrBit(E_GPA,5);
            
            //nrf_ack_packet(0,buffer, (xx&15) + 1);
            nrf_ack_packet(0,rx_buffer, rx_len);
        }
    }
    
    while(1){
        static uint8_t cnt = 0;
        if(cnt&1){
            DrvGPIO_SetBit(E_GPA,2);
        }else{
            DrvGPIO_ClrBit(E_GPA,2);
        }
        DrvSYS_Delay(50000*2);
        cnt++;
        //nrf_tx_packet(buffer, 16);
        //buffer[0]++;
        
        if(nrf_rx_packet(buffer,16) == NRF_RX_OK)
        {
            static uint8_t xx = 0;
            xx++;
            if(xx & 1)
                DrvGPIO_SetBit(E_GPA,5);
            else
                DrvGPIO_ClrBit(E_GPA,5);
        }
    }
    return 0;
}




