#include "i2c.h"
#include "stm32f0xx.h"
#include "simple_io.h"
#include "ring_buffer.h"

extern ring_buffer_t* cmd_buffer;

#define BROADCAST_ADDR          (I2C_ADDR_PREFIX | 0x0f)
#define I2C_BUF_LEN             32

uint8_t i2c_rxBuffer[I2C_BUF_LEN];
uint8_t i2c_txBuffer[I2C_BUF_LEN];
uint32_t i2c_rx_idx = 0;
uint32_t i2c_rx_cnt = 0;
uint32_t i2c_tx_idx = 0;
uint32_t i2c_tx_cnt = 0;

#define I2C1_RXDR_Address     ((uint32_t)(I2C1_BASE + 0x24))
// Initialize the I2C
void init_i2c(void)
{
    // Think we can keep things simple, just use the std library
    I2C_InitTypeDef     I2C_InitStructure;
    GPIO_InitTypeDef    GPIO_InitStructure;
    NVIC_InitTypeDef    NVIC_InitStructure;
    DMA_InitTypeDef     DMA_InitStructure;

    /*!< Configure I2C1 pins: SCL */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    /*!< Configure I2C1 pins: SDA */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    /* Connect PB6 to I2C_SCL*/
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_1);
    /* Connect PB7 to I2C_SDA*/
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_1);
  
    I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
    I2C_InitStructure.I2C_AnalogFilter = I2C_AnalogFilter_Enable;
    I2C_InitStructure.I2C_DigitalFilter = 0x00;
    I2C_InitStructure.I2C_OwnAddress1 = OWN_ADDRESS;
    I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
    I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
    I2C_InitStructure.I2C_Timing = I2C_TIMING;
    I2C_Init(I2C1, &I2C_InitStructure);
    
    I2C_OwnAddress2Config(I2C1, BROADCAST_ADDR, 0);
    I2C_DualAddressCmd(I2C1, ENABLE);
    
    DMA_DeInit(DMA1_Channel3);

    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)I2C1_RXDR_Address;
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)i2c_rxBuffer;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
    DMA_InitStructure.DMA_BufferSize = I2C_BUF_LEN;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(DMA1_Channel3, &DMA_InitStructure);
    
    //DMA_Cmd(DMA1_Channel3, ENABLE);
    //I2C_DMACmd(I2C1, I2C_DMAReq_Rx, ENABLE);
    
    NVIC_InitStructure.NVIC_IRQChannel = I2C1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    I2C_ITConfig(I2C1, I2C_IT_ADDRI | I2C_IT_RXI , ENABLE);
    
    I2C_Cmd(I2C1, ENABLE);
    
    
#ifdef  USE_CPAL
    // I2C need CPAL library 
    sRxStructure.wNumData = BufferSize;       /* Maximum Number of data to be received */
    sRxStructure.pbBuffer = tRxBuffer;        /* Common Rx buffer for all received data */
    sRxStructure.wAddr1 = OWN_ADDRESS;        /* Not needed */
    sRxStructure.wAddr2 = 0;                  /* Not needed */
  
    /* Initialize local Transmission structures */
    sTxStructure.wNumData = BufferSize;       /* Maximum Number of data to be received */
    sTxStructure.pbBuffer = (uint8_t*)tStateSignal;     /* Common Rx buffer for all received data */
    sTxStructure.wAddr1 = OWN_ADDRESS;        /* The own board address */
    sTxStructure.wAddr2 = 0;                  /* Not needed */
    
    RCC_I2CCLKConfig(RCC_I2C1CLK_SYSCLK);
    CPAL_I2C_StructInit(&I2C_DevStructure);
    I2C_DevStructure.CPAL_Mode = CPAL_MODE_SLAVE;
    I2C_DevStructure.CPAL_Direction = CPAL_DIRECTION_RX;
#ifdef CPAL_I2C_DMA_PROGMODEL
    I2C_DevStructure.wCPAL_Options =  CPAL_OPT_NO_MEM_ADDR | CPAL_OPT_DMARX_TCIT;
    I2C_DevStructure.CPAL_ProgModel = CPAL_PROGMODEL_DMA;
#elif defined (CPAL_I2C_IT_PROGMODEL)
    I2C_DevStructure.wCPAL_Options =  CPAL_OPT_NO_MEM_ADDR;
    I2C_DevStructure.CPAL_ProgModel = CPAL_PROGMODEL_INTERRUPT;
#else
 #error "Please select one of the programming model (in stm32f0xx_i2c_cpal_conf.h)"
#endif
    I2C_DevStructure.pCPAL_I2C_Struct->I2C_Timing = I2C_TIMING;
    I2C_DevStructure.pCPAL_I2C_Struct->I2C_OwnAddress1 = OWN_ADDRESS;
    I2C_DevStructure.pCPAL_TransferRx = &sRxStructure;
    I2C_DevStructure.pCPAL_TransferTx = &sTxStructure;
  
    CPAL_I2C_Init(&I2C_DevStructure);
#endif
}

uint8_t cmd;
#define IS_TX_CMD(cmd)  ((cmd) & 0x80)
static uint32_t prepare_tx_data(uint8_t cmd, uint32_t cnt);
uint32_t I2C1_IRQHandler(void)
{
    if(I2C_GetITStatus(I2C1, I2C_IT_ADDRI)){
        I2C_ClearITPendingBit(I2C1, I2C_IT_ADDRI);
        i2c_rx_idx = 0;
    }
    
    if(I2C_GetITStatus(I2C1, I2C_IT_RXNE)){
        //I2C_ClearITPendingBit(I2C1, I2C_IT_RXNE);
        uint8_t d = I2C_ReceiveData(I2C1);
        if(i2c_rx_idx == 0){
            // get cmd from i2c
            cmd = d;
        }else if(i2c_rx_idx == 1){
            if(IS_TX_CMD(cmd)){
                i2c_rx_cnt = 0;
                i2c_tx_cnt = prepare_tx_data(cmd, d);
                i2c_tx_idx = 0;
                I2C_SendData(I2C1,i2c_txBuffer[i2c_tx_idx++]);
                I2C_ITConfig(I2C1, I2C_IT_TXI , ENABLE);
            }else{
                i2c_rx_cnt = d;
            }
        }
        i2c_rxBuffer[i2c_rx_idx++] = d;
        if((i2c_rx_cnt+2) == i2c_rx_idx){
            // rx data success
            i2c_rxBuffer[1] = i2c_rxBuffer[0];
            ring_buf_push(cmd_buffer,i2c_rxBuffer+1,i2c_rx_cnt+1);
        }
    }
    
    if(I2C_GetITStatus(I2C1, I2C_IT_TXI)){
        //I2C_SendData
        if(i2c_tx_idx < i2c_tx_cnt){
            I2C_SendData(I2C1,i2c_txBuffer[i2c_tx_idx++]);
        }else{
            I2C_ITConfig(I2C1, I2C_IT_TXI , DISABLE);
            I2C_ClearITPendingBit(I2C1, I2C_IT_TXI);
        }
    }
    
    return 0;
}


static uint32_t prepare_tx_data(uint8_t cmd, uint32_t len)
{
    mymemcpy(i2c_txBuffer,i2c_rxBuffer+1, len);
    return len;
}


uint8_t get_i2c_addr(void)
{
    return get_addr_value() | I2C_ADDR_PREFIX;
}

