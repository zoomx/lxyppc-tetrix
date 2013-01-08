#include "bsp.h"
#include "lsm303dlhc.h"



void LSM303DLHC_acc_init(void)
{
    uint8_t temp;
    
    LSM303DLHC_INIT();
                    
    temp = LSM303DLHC_NORMAL_MODE | LSM303DLHC_ODR_50_HZ | LSM303DLHC_AXES_ENABLE;
    LSM303DLHC_Write_Byte(ACC_I2C_ADDRESS, LSM303DLHC_CTRL_REG1_A, temp);
    temp = LSM303DLHC_BlockUpdate_Continous | LSM303DLHC_BLE_LSB | LSM303DLHC_HR_ENABLE | LSM303DLHC_FULLSCALE_2G;
    LSM303DLHC_Write_Byte(ACC_I2C_ADDRESS, LSM303DLHC_CTRL_REG4_A, temp);
    
    LSM303DLHC_Read_Buffer(ACC_I2C_ADDRESS, LSM303DLHC_CTRL_REG2_A, &temp, 1);
    temp &= 0x0C;
    temp |= (uint8_t) (
        LSM303DLHC_HPM_NORMAL_MODE | LSM303DLHC_HPFCF_16 | LSM303DLHC_HPF_AOI1_DISABLE | LSM303DLHC_HPF_AOI2_DISABLE
    );
    LSM303DLHC_Write_Byte(ACC_I2C_ADDRESS, LSM303DLHC_CTRL_REG2_A, temp);
}

void LSM303DLHC_mag_init(void)
{
    uint8_t temp;
    temp = LSM303DLHC_ODR_30_HZ | LSM303DLHC_TEMPSENSOR_DISABLE;
    /* Write value to Mag MEMS CRA_REG regsister */
    LSM303DLHC_Write_Byte(MAG_I2C_ADDRESS, LSM303DLHC_CRA_REG_M, temp);
  
    temp = LSM303DLHC_FS_8_1_GA;
    /* Write value to Mag MEMS CRB_REG regsister */
    LSM303DLHC_Write_Byte(MAG_I2C_ADDRESS, LSM303DLHC_CRB_REG_M, temp);

    /* Write value to Mag MEMS MR_REG regsister */
    temp = LSM303DLHC_CONTINUOS_CONVERSION;
    LSM303DLHC_Write_Byte(MAG_I2C_ADDRESS, LSM303DLHC_MR_REG_M, temp);
}


void LSM303DLHC_acc_read(void)
{
    uint8_t buffer[6];
    LSM303DLHC_Read_Buffer(ACC_I2C_ADDRESS, LSM303DLHC_OUT_X_L_A, buffer, 6);
    
    // we need normalize the value
}

void LSM303DLHC_mag_read(void)
{
    uint8_t buffer[6];
    LSM303DLHC_Read_Buffer(MAG_I2C_ADDRESS, LSM303DLHC_OUT_X_H_M, buffer, 6);
    
    // we need normalize the value
}






