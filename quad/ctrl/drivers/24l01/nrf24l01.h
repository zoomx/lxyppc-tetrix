#ifndef NRF24L01_H
#define NRF24L01_H
#include "bsp/bsp.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//NRF24L01 command
#define NRF_READ_REG        0x00  //读配置寄存器,低5位为寄存器地址
#define NRF_WRITE_REG       0x20  //写配置寄存器,低5位为寄存器地址
#define NRF_ACTIVATE        0x50  // 
#define NRF_RD_RX_PL_WID    0x60  // read rx payload width
#define NRF_RD_RX_PLOAD     0x61  //读RX有效数据,1~32字节
#define NRF_WR_TX_PLOAD     0xA0  //写TX有效数据,1~32字节
#define NRF_WR_ACK_PAYLOAD  0xA8  //
#define NRF_FLUSH_TX        0xE1  //清除TX FIFO寄存器.发射模式下用
#define NRF_FLUSH_RX        0xE2  //清除RX FIFO寄存器.接收模式下用
#define NRF_REUSE_TX_PL     0xE3  //重新使用上一包数据,CE为高,数据包被不断发送.
#define NRF_NOP             0xFF  //空操作,可以用来读状态寄存器	 
//NRF24L01 address
#define NRF_CONFIG          0x00  //配置寄存器地址;bit0:1接收模式,0发射模式;bit1:电选择;bit2:CRC模式;bit3:CRC使能;
                              //bit4:中断MAX_RT(达到最大重发次数中断)使能;bit5:中断TX_DS使能;bit6:中断RX_DR使能
#define NRF_EN_AA           0x01  //使能自动应答功能  bit0~5,对应通道0~5
#define NRF_EN_RXADDR       0x02  //接收地址允许,bit0~5,对应通道0~5
#define NRF_SETUP_AW        0x03  //设置地址宽度(所有数据通道):bit1,0:00,3字节;01,4字节;02,5字节;
#define NRF_SETUP_RETR      0x04  //建立自动重发;bit3:0,自动重发计数器;bit7:4,自动重发延时 250*x+86us
#define NRF_RF_CH           0x05  //RF通道,bit6:0,工作通道频率;
#define NRF_RF_SETUP        0x06  //RF寄存器;bit3:传输速率(0:1Mbps,1:2Mbps);bit2:1,发射功率;bit0:低噪声放大器增益
#define NRF_STATUS          0x07  //状态寄存器;bit0:TX FIFO满标志;bit3:1,接收数据通道号(最大:6);bit4,达到最多次重发
                              //bit5:数据发送完成中断;bit6:接收数据中断;

#define NRF_OBSERVE_TX      0x08  //发送检测寄存器,bit7:4,数据包丢失计数器;bit3:0,重发计数器
#define NRF_CD              0x09  //载波检测寄存器,bit0,载波检测;
#define NRF_RPD             0x09  //载波检测寄存器,bit0,载波检测;
#define NRF_RX_ADDR_P0      0x0A  //数据通道0接收地址,最大长度5个字节,低字节在前
#define NRF_RX_ADDR_P1      0x0B  //数据通道1接收地址,最大长度5个字节,低字节在前
#define NRF_RX_ADDR_P2      0x0C  //数据通道2接收地址,最低字节可设置,高字节,必须同RX_ADDR_P1[39:8]相等;
#define NRF_RX_ADDR_P3      0x0D  //数据通道3接收地址,最低字节可设置,高字节,必须同RX_ADDR_P1[39:8]相等;
#define NRF_RX_ADDR_P4      0x0E  //数据通道4接收地址,最低字节可设置,高字节,必须同RX_ADDR_P1[39:8]相等;
#define NRF_RX_ADDR_P5      0x0F  //数据通道5接收地址,最低字节可设置,高字节,必须同RX_ADDR_P1[39:8]相等;
#define NRF_TX_ADDR         0x10  //发送地址(低字节在前),ShockBurstTM模式下,RX_ADDR_P0与此地址相等
#define NRF_RX_PW_P0        0x11  //接收数据通道0有效数据宽度(1~32字节),设置为0则非法
#define NRF_RX_PW_P1        0x12  //接收数据通道1有效数据宽度(1~32字节),设置为0则非法
#define NRF_RX_PW_P2        0x13  //接收数据通道2有效数据宽度(1~32字节),设置为0则非法
#define NRF_RX_PW_P3        0x14  //接收数据通道3有效数据宽度(1~32字节),设置为0则非法
#define NRF_RX_PW_P4        0x15  //接收数据通道4有效数据宽度(1~32字节),设置为0则非法
#define NRF_RX_PW_P5        0x16  //接收数据通道5有效数据宽度(1~32字节),设置为0则非法
#define NRF_FIFO_STATUS     0x17  //FIFO状态寄存器;bit0,RX FIFO寄存器空标志;bit1,RX FIFO满标志;bit2,3,保留
                              //bit4,TX FIFO空标志;bit5,TX FIFO满标志;bit6,1,循环发送上一数据包.0,不循环;
#define NRF_DYNPD           0x1C
#define NRF_FEATURE         0x1D
//////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////
/// NRF24L01 bit field
// config register
#define NRF_PRIM_RX         0x01
#define NRF_PRIM_TX         0x00
#define NRF_POWER_UP        0x02
#define NRF_CRC0            0x04
#define NRF_CRC_1B          0x00
#define NRF_CRC_2B          0x04
#define NRF_EN_CRC          0x08
#define NRF_DIS_CRC         0x00
#define NRF_MASK_MAX_RT     0x10
#define NRF_EN_MAX_RT_IRQ   0x00
#define NRF_DIS_MAX_RT_IRQ  0x10
#define NRF_MASK_TX_OK      0x20
#define NRF_EN_TX_OK_IRQ    0x00
#define NRF_DIS_TX_OK_IRQ   0x20
#define NRF_MASK_RX_OK      0x40
#define NRF_EN_RX_OK_IRQ    0x00
#define NRF_DIS_RX_OK_IRQ   0x40
#define NRF_EN_ALL_IRQ      0x00
#define NRF_DIS_ALL_IRQ     (NRF_DIS_MAX_RT_IRQ | NRF_DIS_TX_OK_IRQ | NRF_DIS_RX_OK_IRQ)
// EN_AA
#define NRF_ENAA_P0         0x01
#define NRF_ENAA_P1         0x02
#define NRF_ENAA_P2         0x04
#define NRF_ENAA_P3         0x08
#define NRF_ENAA_P4         0x10
#define NRF_ENAA_P5         0x20
// EN_RXADDR
#define NRF_ERX_P0          0x01
#define NRF_ERX_P1          0x02
#define NRF_ERX_P2          0x04
#define NRF_ERX_P3          0x08
#define NRF_ERX_P4          0x10
#define NRF_ERX_P5          0x20
// SETUP_AW
#define NRF_AW_3            0x01
#define NRF_AW_4            0x02
#define NRF_AW_5            0x03
// SETUP_RETR
#define NRF_ARD(us)      ( (( (us-1)/250  )&0x0f)<<4 )
#define NRF_ARDx( X_250_plus_250_us)     ( ((X_50_plus_250_us&)&0x0f)<<4 )
#define NRF_ARC( arc_count )            ((arc_count) & 0x0f)
// RF_CH
// RF_SETUP
#define NRF_PWR_18dBm         (0x0<<1)
#define NRF_PWR_12dBm         (0x1<<1)
#define NRF_PWR_6dBm          (0x2<<1)
#define NRF_PWR_0dBm          (0x3<<1)
#define NRF_DR_250Kbps        (1<<5)
#define NRF_DR_1Mbps          (0<<3)
#define NRF_DR_2Mbps          (1<<3)
#define NRF_PLL_LOCK          (1<<4)
#define NRF_CONT_WAVE            (1<<7)
// STATUS register
#define NRF_MAX_RT  	    0x10  //达到最大发送次数中断
#define NRF_TX_OK   	    0x20  //TX发送完成中断
#define NRF_RX_OK   	    0x40  //接收到数据中断
#define NRF_RX_P_NO_MASK    (0x07<<1)
#define NRF_TX_FULL         0x01
// OBSERVE_TX
#define  NRF_PLOS_CNT       0xF0
#define  NRF_ARC_CNT        0x0F
// FIFO_STATUS
#define  NRF_FIFO_RX_EMPTY  0x01
#define  NRF_FIFO_RX_FULL   0x02
#define  NRF_FIFO_TX_EMPTY  0x10
#define  NRF_FIFO_TX_FULL   0x20
#define  NRF_FIFO_TX_REUSE  0x40
// DYNPD
#define  NRF_DPL_P0         0x01
#define  NRF_DPL_P1         0x02
#define  NRF_DPL_P2         0x04
#define  NRF_DPL_P3         0x08
#define  NRF_DPL_P4         0x10
#define  NRF_DPL_P5         0x20
// FEATURE
#define  NRF_EN_DYN_ACK         0x01
#define  NRF_EN_ACK_PAYLOAD     0x02
#define  NRD_EN_DPL             0x04

#ifndef  NRF_CE_SET
#define  NRF_CE_SET
#endif 
#ifndef  NRF_CE_RESET
#define  NRF_CE_RESET
#endif 
#ifndef  NRF_CS_SET
#define  NRF_CS_SET
#endif 
#ifndef  NRF_CS_RESET
#define  NRF_CS_RESET
#endif

#define  NRF_CE_ENABLE      NRF_CE_SET
#define  NRF_CE_DISABLE     NRF_CE_RESET
#define  NRF_CS_ENABLE      NRF_CS_RESET
#define  NRF_CS_DISABLE     NRF_CS_SET
#define  NRF_READY          (NRF_IRQ == 0)

#define  NRF_MAX_CHANNEL    127

#define  NRF_TX_FAIL        0
#define  NRF_TX_SUCCESS     1
#define  NRF_ACK_SUCCESS    2

void nrf_init(void);
uint8_t nrf_detect(void);
uint8_t nrf_write_reg(uint8_t reg,uint8_t value);
uint8_t nrf_read_reg(uint8_t reg);
uint8_t nrf_read_buf(uint8_t reg,uint8_t *pBuf,uint32_t len);
uint8_t nrf_write_buf(uint8_t reg, const uint8_t *pBuf, uint32_t len);

uint8_t nrf_tx_packet(const uint8_t *txbuf, uint32_t len);
uint8_t nrf_tx_packet_no_wait(const uint8_t *txbuf, uint32_t len);
uint8_t nrf_ack_packet(uint8_t pipe, const uint8_t *ackbuf, uint32_t len);
uint8_t nrf_rx_packet(uint8_t *rxbuf, uint32_t len);
void nrf_rx_mode(const uint8_t* addr, uint8_t addr_len, uint32_t rx_len, uint8_t channel);
void nrf_tx_mode(const uint8_t* addr, uint8_t addr_len, uint8_t channel);

void nrf_rx_mode_no_aa(const uint8_t* addr, uint8_t addr_len, uint32_t rx_len, uint8_t channel);
void nrf_tx_mode_no_aa(const uint8_t* addr, uint8_t addr_len, uint8_t channel);

void nrf_tx_mode_dual(const uint8_t* addr, uint8_t addr_len, uint8_t channel);
void nrf_rx_mode_dual(const uint8_t* addr, uint8_t addr_len, uint8_t channel);

uint8_t nrf_get_status(void);
uint8_t nrf_test_carrier(void);
uint8_t nrf_rx_available(void);

void nrf_tx_done(uint8_t success);
void nrf_on_rx_data(const void* data, uint32_t len, uint8_t channel);
#endif
