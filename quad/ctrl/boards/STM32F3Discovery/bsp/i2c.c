#include "i2c.h"
#include "stm32f30x.h"

#define I2C_TIMEOUT  0x8000

void i2c1_init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  I2C_InitTypeDef  I2C_InitStructure;
  
  /* Enable the I2C periph */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
  
  /* Enable SCK and SDA GPIO clocks */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB , ENABLE);
  
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_4);
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_4);
  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  
  /* I2C SCK pin configuration */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  
  /* I2C SDA pin configuration */
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_7;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  
  /* I2C configuration -------------------------------------------------------*/
  I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
  I2C_InitStructure.I2C_AnalogFilter = I2C_AnalogFilter_Enable;
  I2C_InitStructure.I2C_DigitalFilter = 0x00;
  I2C_InitStructure.I2C_OwnAddress1 = 0x00;
  I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
  I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
  I2C_InitStructure.I2C_Timing = 0x00902025;
  
  /* Apply LSM303DLHC_I2C configuration after enabling it */
  I2C_Init(I2C1, &I2C_InitStructure);
  
  /* LSM303DLHC_I2C Peripheral Enable */
  I2C_Cmd(I2C1, ENABLE);
}

// 1 for success, 0 for fail
uint8_t i2c_write(I2C_TypeDef* I2Cx, uint8_t DeviceAddr, uint8_t RegAddr, const uint8_t* pBuffer, uint16_t len)
{  
  /* Test on BUSY Flag */
  uint32_t timeout = I2C_TIMEOUT;
  while(I2C_GetFlagStatus(I2Cx, I2C_ISR_BUSY) != RESET)
  {
    if((timeout--) == 0) return 0;
  }
  
  /* Configure slave address, nbytes, reload, end mode and start or stop generation */
  I2C_TransferHandling(I2Cx, DeviceAddr, 1, I2C_Reload_Mode, I2C_Generate_Start_Write);
  
  /* Wait until TXIS flag is set */
  timeout = I2C_TIMEOUT;
  while(I2C_GetFlagStatus(I2Cx, I2C_ISR_TXIS) == RESET)   
  {
    if((timeout--) == 0) return 0;
  }
  
  /* Send Register address */
  I2C_SendData(I2Cx, (uint8_t) RegAddr);
  
  /* Wait until TCR flag is set */
  timeout = I2C_TIMEOUT;
  while(I2C_GetFlagStatus(I2Cx, I2C_ISR_TCR) == RESET)
  {
    if((timeout--) == 0) return 0;
  }
  
  /* Configure slave address, nbytes, reload, end mode and start or stop generation */
  I2C_TransferHandling(I2Cx, DeviceAddr, len, I2C_AutoEnd_Mode, I2C_No_StartStop);
       
  while(len){
      /* Wait until TXIS flag is set */
      timeout = I2C_TIMEOUT;
      while(I2C_GetFlagStatus(I2Cx, I2C_ISR_TXIS) == RESET)
      {
        if((timeout--) == 0) return 0;
      }  
        
      /* Write data to TXDR */
      I2C_SendData(I2Cx, *pBuffer);
      len--;
  }
  /* Wait until TXIS flag is set */
  timeout = I2C_TIMEOUT;
  while(I2C_GetFlagStatus(I2Cx, I2C_ISR_TXIS) == RESET)
  {
    if((timeout--) == 0) return 0;
  }  
      
  /* Wait until STOPF flag is set */
  timeout = I2C_TIMEOUT;
  while(I2C_GetFlagStatus(I2Cx, I2C_ISR_STOPF) == RESET)
  {
    if((timeout--) == 0) return 0;
  }   
  
  /* Clear STOPF flag */
  I2C_ClearFlag(I2Cx, I2C_ICR_STOPCF);
  
  return 1;
}

uint8_t i2c1_write(uint8_t DeviceAddr, uint8_t RegAddr, const uint8_t* pBuffer, uint16_t len)
{
    return i2c_write(I2C1, DeviceAddr, RegAddr, pBuffer, len);
}



uint8_t i2c_read(I2C_TypeDef* I2Cx, uint8_t DeviceAddr, uint8_t RegAddr, uint8_t* pBuffer, uint16_t len)
{    
  /* Test on BUSY Flag */
  uint32_t timeout = I2C_TIMEOUT;
  while(I2C_GetFlagStatus(I2Cx, I2C_ISR_BUSY) != RESET)
  {
    if((timeout--) == 0) return 0;
  }
  
  /* Configure slave address, nbytes, reload, end mode and start or stop generation */
  I2C_TransferHandling(I2Cx, DeviceAddr, 1, I2C_SoftEnd_Mode, I2C_Generate_Start_Write);
  
  /* Wait until TXIS flag is set */
  timeout = I2C_TIMEOUT;
  while(I2C_GetFlagStatus(I2Cx, I2C_ISR_TXIS) == RESET)
  {
    if((timeout--) == 0) return 0;
  }
  
  /* Send Register address */
  I2C_SendData(I2Cx, (uint8_t)RegAddr);
  
  /* Wait until TC flag is set */
  timeout = I2C_TIMEOUT;
  while(I2C_GetFlagStatus(I2Cx, I2C_ISR_TC) == RESET)
  {
    if((timeout--) == 0) return 0;
  }  
  
  /* Configure slave address, nbytes, reload, end mode and start or stop generation */
  I2C_TransferHandling(I2Cx, DeviceAddr, len, I2C_AutoEnd_Mode, I2C_Generate_Start_Read);
  
  /* Wait until all data are received */
  while (len)
  {   
    /* Wait until RXNE flag is set */
    timeout = I2C_TIMEOUT;
    while(I2C_GetFlagStatus(I2Cx, I2C_ISR_RXNE) == RESET)    
    {
      if((timeout--) == 0) return 0;
    }
    
    /* Read data from RXDR */
    *pBuffer = I2C_ReceiveData(I2Cx);
    /* Point to the next location where the byte read will be saved */
    pBuffer++;
    
    /* Decrement the read bytes counter */
    len--;
  } 
  
  /* Wait until STOPF flag is set */
  timeout = I2C_TIMEOUT;
  while(I2C_GetFlagStatus(I2Cx, I2C_ISR_STOPF) == RESET)   
  {
    if((timeout--) == 0) return 0;
  }
  
  /* Clear STOPF flag */
  I2C_ClearFlag(I2Cx, I2C_ICR_STOPCF);
  
  /* If all operations OK */
  return 1;  
}

uint8_t i2c1_read(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t* pBuffer, uint16_t len)
{
    return i2c_read(I2C1, DeviceAddr, RegAddr, pBuffer, len);
}
