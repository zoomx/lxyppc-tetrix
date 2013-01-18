#include "bsp.h"
#include "lsm303dlhc.h"

#define  LSM303DLHC_MAG_GAIN    LSM303DLHC_FS_8_1_GA

static uint8_t inited = 0;
void LSM303DLHC_acc_init(void)
{
    uint8_t temp;
    
    if(!inited){
        inited = 1;
        LSM303DLHC_INIT();
    }
                    
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
    if(!inited){
        inited = 1;
        LSM303DLHC_INIT();
    }
    
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


void LSM303DLHC_acc_read(int16_t * data)
{
    LSM303DLHC_Read_Buffer(ACC_I2C_ADDRESS, LSM303DLHC_OUT_X_L_A, (uint8_t*)data, 6);
    data[0] = -data[0];
    data[1] = -data[1];
    data[2] = -data[2];
    // we need normalize the value
}


// normalize to micro G
// data[0]  - x acc micro G
// data[1]  - y acc micro G
// data[2]  - z acc micro G
void read_acc_normalized(int32_t* data)
{
    int16_t buffer[3];
    LSM303DLHC_acc_read(buffer);
    // for 2G without fifo
    data[0] = buffer[0]*1000/16;
    data[1] = buffer[1]*1000/16;
    data[2] = buffer[2]*1000/16;
}

void read_acc_normalized_f(float* data)
{
    int16_t buffer[3];
    LSM303DLHC_acc_read(buffer);
    // for 2G without fifo
    data[0] = buffer[0]*1000.0/16.0;
    data[1] = buffer[1]*1000.0/16.0;
    data[2] = buffer[2]*1000.0/16.0;
}


#define swap_(x,y)  do{uint8_t t =x; x = y; y = t;}while(0)
// data[0] - x mag, int16
// data[1] - y mag, int16
// data[2] - z mag, int16
void LSM303DLHC_mag_read(int16_t * data)
{
    uint8_t * buffer = (uint8_t*) data;
    LSM303DLHC_Read_Buffer(MAG_I2C_ADDRESS, LSM303DLHC_OUT_X_H_M, buffer, 6);
    swap_(buffer[0], buffer[1]); // swap the byte order
    
    // this need unaligned access support
    //*(uint32_t*)(data + 1) = __REV( *(uint32_t*)(data + 1));
    swap_(buffer[2], buffer[5]); // swap the byte order and y,z
    swap_(buffer[3], buffer[4]);
}
    
// data[0]  - x mag micro Gauss
// data[1]  - y mag micro Gauss
// data[2]  - z mag micro Gauss
void read_mag_normalized(int32_t * data)
{
    int16_t buffer[3];
    int32_t LSM303DLHC_M_SENSITIVITY_XY;
    int32_t LSM303DLHC_M_SENSITIVITY_Z;
    if (LSM303DLHC_MAG_GAIN == LSM303DLHC_FS_1_3_GA){
      LSM303DLHC_M_SENSITIVITY_XY = LSM303DLHC_M_SENSITIVITY_XY_1_3Ga;
      LSM303DLHC_M_SENSITIVITY_Z = LSM303DLHC_M_SENSITIVITY_Z_1_3Ga;
    }else if( LSM303DLHC_MAG_GAIN == LSM303DLHC_FS_1_9_GA){
      LSM303DLHC_M_SENSITIVITY_XY  =  LSM303DLHC_M_SENSITIVITY_XY_1_9Ga;
      LSM303DLHC_M_SENSITIVITY_Z   = LSM303DLHC_M_SENSITIVITY_Z_1_9Ga;
    }else if( LSM303DLHC_MAG_GAIN == LSM303DLHC_FS_2_5_GA){
      LSM303DLHC_M_SENSITIVITY_XY  =  LSM303DLHC_M_SENSITIVITY_XY_2_5Ga;
      LSM303DLHC_M_SENSITIVITY_Z  =  LSM303DLHC_M_SENSITIVITY_Z_2_5Ga;
    }else if( LSM303DLHC_MAG_GAIN == LSM303DLHC_FS_4_0_GA){
      LSM303DLHC_M_SENSITIVITY_XY  =  LSM303DLHC_M_SENSITIVITY_XY_4Ga;
      LSM303DLHC_M_SENSITIVITY_Z  =  LSM303DLHC_M_SENSITIVITY_Z_4Ga;
    }else if( LSM303DLHC_MAG_GAIN == LSM303DLHC_FS_4_7_GA){
      LSM303DLHC_M_SENSITIVITY_XY  =  LSM303DLHC_M_SENSITIVITY_XY_4_7Ga;
      LSM303DLHC_M_SENSITIVITY_Z  =  LSM303DLHC_M_SENSITIVITY_Z_4_7Ga;
    }else if( LSM303DLHC_MAG_GAIN == LSM303DLHC_FS_5_6_GA){
      LSM303DLHC_M_SENSITIVITY_XY  =  LSM303DLHC_M_SENSITIVITY_XY_5_6Ga;
      LSM303DLHC_M_SENSITIVITY_Z  =  LSM303DLHC_M_SENSITIVITY_Z_5_6Ga;
    }else if( LSM303DLHC_MAG_GAIN == LSM303DLHC_FS_8_1_GA){
      LSM303DLHC_M_SENSITIVITY_XY  =  LSM303DLHC_M_SENSITIVITY_XY_8_1Ga;
      LSM303DLHC_M_SENSITIVITY_Z  =  LSM303DLHC_M_SENSITIVITY_Z_8_1Ga;
    }else{ 
      LSM303DLHC_M_SENSITIVITY_XY  =  LSM303DLHC_M_SENSITIVITY_XY_1_3Ga;
      LSM303DLHC_M_SENSITIVITY_Z  =  LSM303DLHC_M_SENSITIVITY_Z_1_3Ga;
    }
    LSM303DLHC_mag_read(buffer);
    data[0] = buffer[0]*1000/LSM303DLHC_M_SENSITIVITY_XY;
    data[1] = buffer[1]*1000/LSM303DLHC_M_SENSITIVITY_XY;
    data[2] = buffer[2]*1000/LSM303DLHC_M_SENSITIVITY_Z;
}

// data[0]  - x mag micro Gauss
// data[1]  - y mag micro Gauss
// data[2]  - z mag micro Gauss
void read_mag_normalized_f(float * data)
{
    int16_t buffer[3];
    int32_t LSM303DLHC_M_SENSITIVITY_XY;
    int32_t LSM303DLHC_M_SENSITIVITY_Z;
    if (LSM303DLHC_MAG_GAIN == LSM303DLHC_FS_1_3_GA){
      LSM303DLHC_M_SENSITIVITY_XY = LSM303DLHC_M_SENSITIVITY_XY_1_3Ga;
      LSM303DLHC_M_SENSITIVITY_Z = LSM303DLHC_M_SENSITIVITY_Z_1_3Ga;
    }else if( LSM303DLHC_MAG_GAIN == LSM303DLHC_FS_1_9_GA){
      LSM303DLHC_M_SENSITIVITY_XY  =  LSM303DLHC_M_SENSITIVITY_XY_1_9Ga;
      LSM303DLHC_M_SENSITIVITY_Z   = LSM303DLHC_M_SENSITIVITY_Z_1_9Ga;
    }else if( LSM303DLHC_MAG_GAIN == LSM303DLHC_FS_2_5_GA){
      LSM303DLHC_M_SENSITIVITY_XY  =  LSM303DLHC_M_SENSITIVITY_XY_2_5Ga;
      LSM303DLHC_M_SENSITIVITY_Z  =  LSM303DLHC_M_SENSITIVITY_Z_2_5Ga;
    }else if( LSM303DLHC_MAG_GAIN == LSM303DLHC_FS_4_0_GA){
      LSM303DLHC_M_SENSITIVITY_XY  =  LSM303DLHC_M_SENSITIVITY_XY_4Ga;
      LSM303DLHC_M_SENSITIVITY_Z  =  LSM303DLHC_M_SENSITIVITY_Z_4Ga;
    }else if( LSM303DLHC_MAG_GAIN == LSM303DLHC_FS_4_7_GA){
      LSM303DLHC_M_SENSITIVITY_XY  =  LSM303DLHC_M_SENSITIVITY_XY_4_7Ga;
      LSM303DLHC_M_SENSITIVITY_Z  =  LSM303DLHC_M_SENSITIVITY_Z_4_7Ga;
    }else if( LSM303DLHC_MAG_GAIN == LSM303DLHC_FS_5_6_GA){
      LSM303DLHC_M_SENSITIVITY_XY  =  LSM303DLHC_M_SENSITIVITY_XY_5_6Ga;
      LSM303DLHC_M_SENSITIVITY_Z  =  LSM303DLHC_M_SENSITIVITY_Z_5_6Ga;
    }else if( LSM303DLHC_MAG_GAIN == LSM303DLHC_FS_8_1_GA){
      LSM303DLHC_M_SENSITIVITY_XY  =  LSM303DLHC_M_SENSITIVITY_XY_8_1Ga;
      LSM303DLHC_M_SENSITIVITY_Z  =  LSM303DLHC_M_SENSITIVITY_Z_8_1Ga;
    }else{ 
      LSM303DLHC_M_SENSITIVITY_XY  =  LSM303DLHC_M_SENSITIVITY_XY_1_3Ga;
      LSM303DLHC_M_SENSITIVITY_Z  =  LSM303DLHC_M_SENSITIVITY_Z_1_3Ga;
    }
    LSM303DLHC_mag_read(buffer);
    data[0] = buffer[0]*1000.0/LSM303DLHC_M_SENSITIVITY_XY;
    data[1] = buffer[1]*1000.0/LSM303DLHC_M_SENSITIVITY_XY;
    data[2] = buffer[2]*1000.0/LSM303DLHC_M_SENSITIVITY_Z;
}


