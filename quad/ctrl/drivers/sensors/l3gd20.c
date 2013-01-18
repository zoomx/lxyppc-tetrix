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
    
    temp = L3GD20_MODE_ACTIVE | L3GD20_OUTPUT_DATARATE_760Hz | L3GD20_AXES_ENABLE | L3GD20_BANDWIDTH_4;
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
    
    // enable data ready interrupt
    L3GD20_Read_buffer(&temp, L3GD20_CTRL_REG3_ADDR, 1);
    temp |= L3GD20_INT2INTERRUPT_ENABLE;
    L3GD20_Write_buffer(&temp, L3GD20_CTRL_REG3_ADDR, 1);
    
    L3GD20_IO_INT_SETUP();
}

void L3GD20_gyro_read(int16_t * data)
{
    L3GD20_Read_buffer((uint8_t*)data,L3GD20_OUT_X_L_ADDR,6);
    data[0] = -data[0];
    data[1] = -data[1];
    data[2] = -data[2];
    // setting is LSB, no need to swap bytes order
}


#define L3G_250dps     (float)114.285f         /*!< gyroscope sensitivity with 250 dps full scale [LSB/dps] */
#define L3G_500dps     (float)57.1429f        /*!< gyroscope sensitivity with 500 dps full scale [LSB/dps] */
#define L3G_2000dps    (float)14.285f	      /*!< gyroscope sensitivity with 2000 dps full scale [LSB/dps] */
#define _PI            (float)3.14159265f

void read_gyro_normalized(int32_t* data)
{
    int16_t buffer[3];
    L3GD20_gyro_read(buffer);
    data[0] = buffer[0]*500 / 28571;
    data[1] = buffer[1]*500 / 28571;
    data[2] = buffer[2]*500 / 28571;
}

void read_gyro_normalized_f(int32_t* data)
{
    int16_t buffer[3];
    L3GD20_gyro_read(buffer);
    data[0] = buffer[0]/L3G_500dps;
    data[1] = buffer[1]/L3G_500dps;
    data[2] = buffer[2]/L3G_500dps;
}


void L3GD20_compute_gyro_runtime_bias(float* bias, uint32_t samples)
{
    int16_t gyro[3];
    uint32_t i;
    int32_t sum[3] = {0};
    L3GD20_DI();
    for(i=0;i<samples;i++){
        while(!L3GD20_INT2); // wait data ready
        L3GD20_gyro_read(gyro);
        sum[0] += gyro[0];
        sum[1] += gyro[1];
        sum[2] += gyro[2];
    }
    bias[0] = (float)sum[0]/(float)samples;
    bias[1] = (float)sum[1]/(float)samples;
    bias[2] = (float)sum[2]/(float)samples;
    L3GD20_EI();
}



