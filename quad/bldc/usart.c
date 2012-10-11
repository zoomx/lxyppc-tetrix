#include "usart.h"
#include "ring_buffer.h"
#include "data_process.h"

static uint8_t txBuffer[64];
extern ring_buffer_t* cmd_buffer;
static __IO  uint8_t txBusy = 0;
static uint32_t txTimeout;

#define USART2_TDR_ADDRESS  ((uint32_t)(USART2_BASE + 0x28))
#define USART1_TDR_ADDRESS  ((uint32_t)(USART1_BASE + 0x28))

// init usart 
// usart will use PA14 and PA15, PA14 also used as SWD interface
// PA14 is the TX pin for USART, so I will not config the PA14 as
// USART Tx, until it receive a valid command from Rx PIN
// When boot from the system memory, the PA14 is used as Tx.
// This will also diable the SWD function
// To prevent disable the SWD in both system memory and user app
// I will leave the PA14 as SWD pin, until receive a valid command
void init_usart(void)
{
    USART_InitTypeDef   USART_InitStructure;
    GPIO_InitTypeDef    GPIO_InitStructure;
    NVIC_InitTypeDef    NVIC_InitStructure;
    DMA_InitTypeDef         DMA_InitStructure;
    
    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_Init(USART2, &USART_InitStructure);
    
    /* Configure USART Tx and Rx as alternate function push-pull */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Level_3;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    /* Connect PA14 to USART2_Tx */
    // Tx is used as SWD clk pin, this will disable the SWD
    // So I will enable the TX after receive a valid command from Rx
    //GPIO_PinAFConfig(GPIOA, GPIO_PinSource14, GPIO_AF_1);
    
    /* Connect PA15 to USART2_Rx */
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource15, GPIO_AF_1);
    
    /* Enable the UASRT2 global Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    // Use DMA to send data
    //USART_DMACmd(USART2, USART_DMAReq_Tx, ENABLE);
    DMA_DeInit(DMA1_Channel4);
    
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)USART2_TDR_ADDRESS;
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)txBuffer;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
    DMA_InitStructure.DMA_BufferSize = 64;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
    DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
    
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(DMA1_Channel4, &DMA_InitStructure);
    
    //DMA_Cmd(DMA1_Channel4, ENABLE);
    
    NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel4_5_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    
    DMA_ITConfig(DMA1_Channel4, DMA_IT_TC | DMA_IT_TE, ENABLE);
    
    
    USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
    
    USART_Cmd(USART2, ENABLE);
}



void send_data(USART_TypeDef* USARTx, const void* p, uint32_t len)
{
    //DMA_InitTypeDef         DMA_InitStructure;
    //DMA_Cmd(DMA1_Channel4, DISABLE);
    //USART_DMACmd(USART1, USART_DMAReq_Tx, DISABLE);
    
//     DMA_DeInit(DMA1_Channel4);
//     DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)USART1_TDR_ADDRESS;
//     DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)txBuffer;
//     DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
//     DMA_InitStructure.DMA_BufferSize = len;
//     DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
//     DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
//     DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
//     DMA_InitStructure.DMA_MemoryDataSize = DMA_PeripheralDataSize_Byte;
//     DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
//     DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
//     
//     DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
//     DMA_Init(DMA1_Channel4, &DMA_InitStructure);
    txTimeout = 65535;
    while(txBusy && txTimeout--);
    
    DMA1_Channel4->CNDTR = len;
    DMA1_Channel4->CMAR = (uint32_t)txBuffer;
    
    DMA_ClearFlag(DMA1_FLAG_GL4);
    
    mymemcpy(txBuffer,p,len);
    
    USART_DMACmd(USARTx, USART_DMAReq_Tx, ENABLE);
    USART_ClearFlag(USARTx, USART_FLAG_TC);
    
    //DMA_ITConfig(DMA1_Channel4, DMA_IT_TC | DMA_IT_TE, ENABLE);
    DMA_Cmd(DMA1_Channel4, ENABLE);
    txBusy = 1;
}

// USART2 IRQ handler
void USART2_IRQHandler(void)
{
    /* USART in mode Receiver --------------------------------------------------*/
    if (USART_GetITStatus(USART2, USART_IT_RXNE) == SET)
    {
        uint16_t data = (uint8_t)USART_ReceiveData(USART2);
        // use systick for time out
        process_data((uint8_t)data);
        // when valid data received, we should set the tx pin to AF_1
        // this will disable SWD
        //USART_SendData(USART2, data);
    }
}


// When debug, use usart1 on the i2c port
// 
void init_usart_dbg(void)
{
    USART_InitTypeDef   USART_InitStructure;
    GPIO_InitTypeDef    GPIO_InitStructure;
    NVIC_InitTypeDef    NVIC_InitStructure;
    DMA_InitTypeDef         DMA_InitStructure;
    
    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_Init(USART1, &USART_InitStructure);
    
    /* Configure USART Tx and Rx as alternate function push-pull */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Level_3;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    /* Connect PB6 to USART1_Tx */
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_0);
    
    /* Connect PB7 to USART1_Rx */
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_0);
    
    /* Enable the UASRT1 global Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    // Remap the USART tx1 dma to channel 4
    SYSCFG_DMAChannelRemapConfig(SYSCFG_DMARemap_USART1Tx, ENABLE);
    
    // Use DMA to send data
    //USART_DMACmd(USART2, USART_DMAReq_Tx, ENABLE);
    DMA_DeInit(DMA1_Channel4);
    
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)USART1_TDR_ADDRESS;
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)txBuffer;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
    DMA_InitStructure.DMA_BufferSize = 64;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
    DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
    
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(DMA1_Channel4, &DMA_InitStructure);
    
    //DMA_Cmd(DMA1_Channel4, ENABLE);
    
    NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel4_5_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    
    DMA_ITConfig(DMA1_Channel4, DMA_IT_TC | DMA_IT_TE, ENABLE);
    
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
    USART_Cmd(USART1, ENABLE);
    //USART_ITConfig(USART1, USART_IT_TXE, ENABLE);
}

// USART2 IRQ handler
void USART1_IRQHandler(void)
{
    /* USART in mode Receiver --------------------------------------------------*/
    if (USART_GetITStatus(USART1, USART_IT_RXNE) == SET)
    {
        uint16_t data = /*(uint8_t)*/USART_ReceiveData(USART1);
        //data++;
        // use systick for time out
        process_data((uint8_t)data);
        // when valid data received, we should set the tx pin to AF_1
        // this will disable SWD
        //USART_SendData(USART1, data);
    }
    if (USART_GetITStatus(USART1, USART_IT_ORE) == SET){
        USART_ClearITPendingBit(USART1, USART_IT_ORE);
    }
}

void DMA1_Channel4_5_IRQHandler(void)
{
    if(DMA_GetITStatus(DMA1_IT_TC4) == SET){
        DMA_ClearITPendingBit(DMA1_IT_TC4);
        DMA_Cmd(DMA1_Channel4, DISABLE);
        USART_DMACmd(USART1, USART_DMAReq_Tx, DISABLE);
        txBusy = 0;
        // Tx data success
    }
    if(DMA_GetITStatus(DMA1_IT_TE4) == SET){
        DMA_ClearITPendingBit(DMA1_IT_TE4);
        DMA_Cmd(DMA1_Channel4, DISABLE);
        USART_DMACmd(USART1, USART_DMAReq_Tx, DISABLE);
        txBusy = 0;
        // Tx data fail
    }
}

void enable_tx_PA14(void)
{
    static uint32_t txReady = 0;
    if(txReady == 0){
        GPIO_PinAFConfig(GPIOA, GPIO_PinSource14, GPIO_AF_1);
        txReady = 1;
    }
}

void data_ready(const void* p, uint32_t len)
{
    ring_buf_push(cmd_buffer,p,len);
}
