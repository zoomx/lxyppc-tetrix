#include "bsp.h"
#include "l3gd20.h"

static void L3GD20_Write_buffer(uint8_t* pBuffer, uint8_t WriteAddr, uint16_t NumByteToWrite)
{
  /* Configure the MS bit: 
       - When 0, the address will remain unchanged in multiple read/write commands.
       - When 1, the address will be auto incremented in multiple read/write commands.
  */
  if(NumByteToWrite > 0x01)
  {
    WriteAddr |= (uint8_t)MULTIPLEBYTE_CMD;
  }
  /* Set chip select Low at the start of the transmission */
  L3GD20_CS_LOW();
  
  /* Send the Address of the indexed register */
  L3GD20_XFER_BYTE(WriteAddr);
  /* Send the data that will be written into the device (MSB First) */
  while(NumByteToWrite >= 0x01)
  {
    L3GD20_XFER_BYTE(*pBuffer);
    NumByteToWrite--;
    pBuffer++;
  }
  
  /* Set chip select High at the end of the transmission */ 
  L3GD20_CS_HIGH();
}

static void L3GD20_Read_buffer(uint8_t* pBuffer, uint8_t ReadAddr, uint16_t NumByteToRead)
{  
  if(NumByteToRead > 0x01)
  {
    ReadAddr |= (uint8_t)(READWRITE_CMD | MULTIPLEBYTE_CMD);
  }
  else
  {
    ReadAddr |= (uint8_t)READWRITE_CMD;
  }
  /* Set chip select Low at the start of the transmission */
  L3GD20_CS_LOW();
  
  /* Send the Address of the indexed register */
  L3GD20_XFER_BYTE(ReadAddr);
  
  /* Receive the data that will be read from the device (MSB First) */
  while(NumByteToRead > 0x00)
  {
    /* Send dummy byte (0x00) to generate the SPI clock to L3GD20 (Slave device) */
    *pBuffer = L3GD20_XFER_BYTE(DUMMY_BYTE);
    NumByteToRead--;
    pBuffer++;
  }
  
  /* Set chip select High at the end of the transmission */ 
  L3GD20_CS_HIGH();
}  

void L3GD20_gyro_init(void)
{
    uint8_t temp;
    L3GD20_INIT();
    
    temp = L3GD20_MODE_ACTIVE | L3GD20_OUTPUT_DATARATE_1 | L3GD20_AXES_ENABLE | L3GD20_BANDWIDTH_4;
    L3GD20_Write_buffer(&temp, L3GD20_CTRL_REG1_ADDR, 1);
    
    temp = L3GD20_BlockDataUpdate_Continous | L3GD20_BLE_LSB | L3GD20_FULLSCALE_500;
    L3GD20_Write_buffer(&temp, L3GD20_CTRL_REG4_ADDR, 1);
    
    L3GD20_Read_buffer(&temp, L3GD20_CTRL_REG2_ADDR, 1);
    temp &= 0xC0;
    temp |= L3GD20_HPM_NORMAL_MODE_RES | L3GD20_HPFCF_0;
    L3GD20_Write_buffer(&temp, L3GD20_CTRL_REG2_ADDR, 1);
    
    L3GD20_Read_buffer(&temp, L3GD20_CTRL_REG5_ADDR, 1);

    temp |= L3GD20_HIGHPASSFILTER_ENABLE;
    L3GD20_Write_buffer(&temp, L3GD20_CTRL_REG5_ADDR, 1);
}

void L3GD20_gyro_read(void)
{
    uint8_t buffer[6];
    // we need normalize the value
    L3GD20_Read_buffer(buffer,L3GD20_OUT_X_L_ADDR,6);
}






