#include "i2c.h"
#include "stm32f10x.h"
#include "bsp.h"

#define I2C_TIMEOUT  0x8000
#define I2C_DEFAULT_TIMEOUT 30000

#define  I2C1_SCL_PIN       GPIO_Pin_6
#define  I2C1_SDA_PIN       GPIO_Pin_7
#define  I2C1_GPIO_PORT     GPIOB
#define  I2C2_SCL_PIN       GPIO_Pin_10
#define  I2C2_SDA_PIN       GPIO_Pin_11
#define  I2C2_GPIO_PORT     GPIOB

void i2c_init(I2C_TypeDef * I2C);

typedef struct I2C_context_t{
    I2C_TypeDef* I2Cx;
    volatile uint16_t i2cErrorCount;
    volatile uint8_t error;
    volatile uint8_t busy;
    volatile uint8_t addr;
    volatile uint8_t reg;
    volatile uint8_t bytes;
    volatile uint8_t writing;
    volatile uint8_t reading;
    volatile uint8_t *write_p;
    volatile uint8_t *read_p;
    volatile uint8_t init;
}I2C_context_t;
static I2C_context_t i2c1_context = {I2C1};
static I2C_context_t i2c2_context = {I2C2};

static void i2c_er_handler(I2C_TypeDef* I2Cx, I2C_context_t * context)
{
    volatile uint32_t SR1Register, SR2Register;

    SR1Register = I2Cx->SR1;    //Read the I2C1 status register

    if (SR1Register & 0x0F00)   //an error
    {
        // I2C1error.error = ((SR1Register & 0x0F00) >> 8);               //save error
        // I2C1error.job = job;    //the task
    }

    if (SR1Register & 0x0700)   //If AF, BERR or ARLO, abandon the current job and commence new if there are jobs

    {
        SR2Register = I2Cx->SR2;        //read second status register to clear ADDR if it is set (note that BTF will not be set after a NACK)
        I2C_ITConfig(I2Cx, I2C_IT_BUF, DISABLE);        //disable the RXNE/TXE interrupt - prevent the ISR tailchaining onto the ER (hopefully)
        if (!(SR1Register & 0x0200) && !(I2Cx->CR1 & 0x0200))   //if we dont have an ARLO error, ensure sending of a stop
        {
            if (I2Cx->CR1 & 0x0100)     //We are currently trying to send a start, this is very bad as start,stop will hang the peripheral
            {
                while (I2Cx->CR1 & 0x0100);     //wait for any start to finish sending
                I2C_GenerateSTOP(I2Cx, ENABLE); //send stop to finalise bus transaction
                while (I2Cx->CR1 & 0x0200);     //wait for stop to finish sending
                i2c_init(I2Cx);  //reset and configure the hardware
            } else {
                I2C_GenerateSTOP(I2Cx, ENABLE); //stop to free up the bus
                I2C_ITConfig(I2Cx, I2C_IT_EVT | I2C_IT_ERR, DISABLE);   //Disable EVT and ERR interrupts while bus inactive
            }
        }
    }
    I2Cx->SR1 &= ~0x0F00;       //reset all the error bits to clear the interrupt
    context->busy = 0;
}


uint8_t i2cWriteBuffer(I2C_TypeDef* I2Cx, I2C_context_t * context, uint8_t addr_, uint8_t reg_, uint8_t len_, const uint8_t * data)
{
    uint8_t i;
    uint8_t my_data[16];
    uint32_t timeout = I2C_DEFAULT_TIMEOUT;

    context->addr = addr_ << 1;
    context->reg = reg_;
    context->writing = 1;
    context->reading = 0;
    context->write_p = my_data;
    context->read_p = my_data;
    context->bytes = len_;
    context->busy = 1;

    if (len_ > 16)
        return 0;           //too long

    for (i = 0; i < len_; i++)
        my_data[i] = data[i];

    if (!(I2Cx->CR2 & I2C_IT_EVT))      //if we are restarting the driver
    {
        if (!(I2Cx->CR1 & 0x0100))      //ensure sending a start
        {
            while (I2Cx->CR1 & 0x0200) {;
            }                   //wait for any stop to finish sending
            I2C_GenerateSTART(I2Cx, ENABLE);    //send the start for the new job
        }
        I2C_ITConfig(I2Cx, I2C_IT_EVT | I2C_IT_ERR, ENABLE);    //allow the interrupts to fire off again
    }

    while (context->busy && --timeout > 0);
    if (timeout == 0) {
        context->i2cErrorCount++;
        i2c_init(I2Cx);          // reinit peripheral + clock out garbage
        return 0;
    }

    return 1;
}

///////////////////////////////////////////////////////////////////////////////

uint8_t i2cWrite(I2C_TypeDef* I2Cx, I2C_context_t * context, uint8_t addr_, uint8_t reg_, uint8_t data)
{
    return i2cWriteBuffer(I2Cx, context, addr_, reg_, 1, &data);
}

///////////////////////////////////////////////////////////////////////////////

uint8_t i2cRead(I2C_TypeDef* I2Cx, I2C_context_t * context, uint8_t addr_, uint8_t reg_, uint8_t len, uint8_t * buf)
{
    uint32_t timeout = I2C_DEFAULT_TIMEOUT;

    context->addr = addr_ << 1;
    context->reg = reg_;
    context->writing = 0;
    context->reading = 1;
    context->read_p = buf;
    context->write_p = buf;
    context->bytes = len;
    context->busy = 1;

    if (!(I2Cx->CR2 & I2C_IT_EVT))      //if we are restarting the driver
    {
        if (!(I2Cx->CR1 & 0x0100))      //ensure sending a start
        {
            while (I2Cx->CR1 & 0x0200) {;
            }                   //wait for any stop to finish sending
            I2C_GenerateSTART(I2Cx, ENABLE);    //send the start for the new job
        }
        I2C_ITConfig(I2Cx, I2C_IT_EVT | I2C_IT_ERR, ENABLE);    //allow the interrupts to fire off again
    }

    while (context->busy && --timeout > 0);
    if (timeout == 0) {
        context->i2cErrorCount++;        // reinit peripheral + clock out garbage
        i2c_init(I2Cx);
        return 0;
    }

    return 1;
}

///////////////////////////////////////////////////////////////////////////////

void i2c_ev_handler(I2C_TypeDef* I2Cx, I2C_context_t * context)
{
    static uint8_t subaddress_sent, final_stop; //flag to indicate if subaddess sent, flag to indicate final bus condition
    static int8_t index;        //index is signed -1==send the subaddress

    uint8_t SReg_1 = I2Cx->SR1; //read the status register here

    if (SReg_1 & 0x0001)        //we just sent a start - EV5 in ref manual
    {
        I2Cx->CR1 &= ~0x0800;   //reset the POS bit so ACK/NACK applied to the current byte
        I2C_AcknowledgeConfig(I2Cx, ENABLE);    //make sure ACK is on
        index = 0;              //reset the index
        if (context->reading && (subaddress_sent || 0xFF == context->reg))        //we have sent the subaddr
        {
            subaddress_sent = 1;        //make sure this is set in case of no subaddress, so following code runs correctly
            if (context->bytes == 2)
                I2Cx->CR1 |= 0x0800;    //set the POS bit so NACK applied to the final byte in the two byte read
            I2C_Send7bitAddress(I2Cx, context->addr, I2C_Direction_Receiver);    //send the address and set hardware mode
        } else                  //direction is Tx, or we havent sent the sub and rep start
        {
            I2C_Send7bitAddress(I2Cx, context->addr, I2C_Direction_Transmitter); //send the address and set hardware mode
            if (context->reg != 0xFF)    //0xFF as subaddress means it will be ignored, in Tx or Rx mode
                index = -1;     //send a subaddress
        }
    } else if (SReg_1 & 0x0002) //we just sent the address - EV6 in ref manual
    {
        //Read SR1,2 to clear ADDR
        volatile uint8_t a;
        __DMB();                //memory fence to control hardware
        if (context->bytes == 1 && context->reading && subaddress_sent)   //we are receiving 1 byte - EV6_3
        {
            I2C_AcknowledgeConfig(I2Cx, DISABLE);       //turn off ACK
            __DMB();
            a = I2Cx->SR2;      //clear ADDR after ACK is turned off
            I2C_GenerateSTOP(I2Cx, ENABLE);     //program the stop
            final_stop = 1;
            I2C_ITConfig(I2Cx, I2C_IT_BUF, ENABLE);     //allow us to have an EV7
        } else                  //EV6 and EV6_1
        {
            a = I2Cx->SR2;      //clear the ADDR here
            __DMB();
            if (context->bytes == 2 && context->reading && subaddress_sent)       //rx 2 bytes - EV6_1
            {
                I2C_AcknowledgeConfig(I2Cx, DISABLE);   //turn off ACK
                I2C_ITConfig(I2Cx, I2C_IT_BUF, DISABLE);        //disable TXE to allow the buffer to fill
            } else if (context->bytes == 3 && context->reading && subaddress_sent)        //rx 3 bytes
                I2C_ITConfig(I2Cx, I2C_IT_BUF, DISABLE);        //make sure RXNE disabled so we get a BTF in two bytes time
            else                //receiving greater than three bytes, sending subaddress, or transmitting
                I2C_ITConfig(I2Cx, I2C_IT_BUF, ENABLE);
        }
    } else if (SReg_1 & 0x004)  //Byte transfer finished - EV7_2, EV7_3 or EV8_2
    {
        final_stop = 1;
        if (context->reading && subaddress_sent) //EV7_2, EV7_3
        {
            if (context->bytes > 2)      //EV7_2
            {
                I2C_AcknowledgeConfig(I2Cx, DISABLE);   //turn off ACK
                context->read_p[index++] = I2C_ReceiveData(I2Cx);        //read data N-2
                I2C_GenerateSTOP(I2Cx, ENABLE); //program the Stop
                final_stop = 1; //required to fix hardware
                context->read_p[index++] = I2C_ReceiveData(I2Cx);        //read data N-1
                I2C_ITConfig(I2Cx, I2C_IT_BUF, ENABLE); //enable TXE to allow the final EV7
            } else              //EV7_3
            {
                if (final_stop)
                    I2C_GenerateSTOP(I2Cx, ENABLE);     //program the Stop
                else
                    I2C_GenerateSTART(I2Cx, ENABLE);    //program a rep start
                context->read_p[index++] = I2C_ReceiveData(I2Cx);        //read data N-1
                context->read_p[index++] = I2C_ReceiveData(I2Cx);        //read data N
                index++;        //to show job completed
            }
        } else                  //EV8_2, which may be due to a subaddress sent or a write completion
        {
            if (subaddress_sent || (context->writing)) {
                if (final_stop)
                    I2C_GenerateSTOP(I2Cx, ENABLE);     //program the Stop
                else
                    I2C_GenerateSTART(I2Cx, ENABLE);    //program a rep start
                index++;        //to show that the job is complete
            } else              //We need to send a subaddress
            {
                I2C_GenerateSTART(I2Cx, ENABLE);        //program the repeated Start
                subaddress_sent = 1;    //this is set back to zero upon completion of the current task
            }
        }
        while (I2Cx->CR1 & 0x0100) {;
        }                       //we must wait for the start to clear, otherwise we get constant BTF
    } else if (SReg_1 & 0x0040) //Byte received - EV7
    {
        context->read_p[index++] = I2C_ReceiveData(I2Cx);
        if (context->bytes == (index + 3))
            I2C_ITConfig(I2Cx, I2C_IT_BUF, DISABLE);    //disable TXE to allow the buffer to flush so we can get an EV7_2
        if (context->bytes == index)     //We have completed a final EV7
            index++;            //to show job is complete
    } else if (SReg_1 & 0x0080) //Byte transmitted -EV8/EV8_1
    {
        if (index != -1) {      //we dont have a subaddress to send
            I2C_SendData(I2Cx, context->write_p[index++]);
            if (context->bytes == index) //we have sent all the data
                I2C_ITConfig(I2Cx, I2C_IT_BUF, DISABLE);        //disable TXE to allow the buffer to flush
        } else {
            index++;
            I2C_SendData(I2Cx, context->reg);    //send the subaddress
            if (context->reading || !context->bytes)      //if receiving or sending 0 bytes, flush now
                I2C_ITConfig(I2Cx, I2C_IT_BUF, DISABLE);        //disable TXE to allow the buffer to flush
        }
    }
    if (index == context->bytes + 1)     //we have completed the current job
    {
        //Completion Tasks go here
        //End of completion tasks
        subaddress_sent = 0;    //reset this here
        if (final_stop)         //If there is a final stop and no more jobs, bus is inactive, disable interrupts to prevent BTF
            I2C_ITConfig(I2Cx, I2C_IT_EVT | I2C_IT_ERR, DISABLE);       //Disable EVT and ERR interrupts while bus inactive
        context->busy = 0;
    }
}



static void i2cUnstick(I2C_TypeDef * I2C)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    uint8_t i;
    uint16_t I2C_SCL_PIN,I2C_SDA_PIN;
    GPIO_TypeDef* I2C_PORT;
    if(I2C == I2C1){
        I2C_SCL_PIN = I2C1_SCL_PIN;
        I2C_SDA_PIN = I2C1_SDA_PIN;
        I2C_PORT = I2C1_GPIO_PORT;
    }else if(I2C == I2C1){
        I2C_SCL_PIN = I2C2_SCL_PIN;
        I2C_SDA_PIN = I2C2_SDA_PIN;
        I2C_PORT = I2C2_GPIO_PORT;
    }else{
        I2C_SCL_PIN = I2C1_SCL_PIN;
        I2C_SDA_PIN = I2C1_SDA_PIN;
        I2C_PORT = I2C1_GPIO_PORT;
    }

    GPIO_InitStructure.GPIO_Pin = I2C_SCL_PIN | I2C_SDA_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;

    GPIO_Init(I2C_PORT, &GPIO_InitStructure);

    GPIO_SetBits(I2C_PORT, I2C_SCL_PIN | I2C_SDA_PIN);
    for (i = 0; i < 8; i++) {
        while (!GPIO_ReadInputDataBit(I2C_PORT, I2C_SCL_PIN))      // Wait for any clock stretching to finish
            delay_us(3);

        GPIO_ResetBits(I2C_PORT, I2C_SCL_PIN);     //Set bus low
        delay_us(3);

        GPIO_SetBits(I2C_PORT, I2C_SCL_PIN);       //Set bus high
        delay_us(3);
    }

    // Generate a start then stop condition

    GPIO_ResetBits(I2C_PORT, I2C_SDA_PIN); //Set bus data low
    delay_us(3);
    GPIO_ResetBits(I2C_PORT, I2C_SCL_PIN); //Set bus scl low
    delay_us(3);
    GPIO_SetBits(I2C_PORT, I2C_SCL_PIN);   //Set bus scl high
    delay_us(3);
    GPIO_SetBits(I2C_PORT, I2C_SDA_PIN);   //Set bus sda high
    delay_us(3);
}

void i2c_init(I2C_TypeDef * I2C)
{
    NVIC_InitTypeDef NVIC_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;
    I2C_InitTypeDef I2C_InitStructure;
    
    uint16_t I2C_SCL_PIN,I2C_SDA_PIN;
    GPIO_TypeDef* I2C_PORT;
    I2C_context_t* context;
    if(I2C == I2C1){
        I2C_SCL_PIN = I2C1_SCL_PIN;
        I2C_SDA_PIN = I2C1_SDA_PIN;
        I2C_PORT = I2C1_GPIO_PORT;
        context = &i2c1_context;
    }else if(I2C == I2C2){
        I2C_SCL_PIN = I2C2_SCL_PIN;
        I2C_SDA_PIN = I2C2_SDA_PIN;
        I2C_PORT = I2C2_GPIO_PORT;
        context = &i2c2_context;
    }else{
        I2C_SCL_PIN = I2C1_SCL_PIN;
        I2C_SDA_PIN = I2C1_SDA_PIN;
        I2C_PORT = I2C1_GPIO_PORT;
        context = &i2c1_context;
    }
    
    if(context->init) return;
    
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    i2cUnstick(I2C);               // clock out stuff to make sure slaves arent stuck

    // SCL  PB6
    // SDA  PB7

    GPIO_InitStructure.GPIO_Pin = I2C_SCL_PIN | I2C_SDA_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;

    GPIO_Init(I2C_PORT, &GPIO_InitStructure);

    // Init I2C
    I2C_DeInit(I2C);
    I2C_StructInit(&I2C_InitStructure);

    I2C_ITConfig(I2C, I2C_IT_EVT | I2C_IT_ERR, DISABLE);       //Disable EVT and ERR interrupts - they are enabled by the first request

    I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
    I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
    I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
    I2C_InitStructure.I2C_ClockSpeed = 400000;

    I2C_Init(I2C, &I2C_InitStructure);

    I2C_Cmd(I2C, ENABLE);

    if(I2C == I2C1){
        // I2C ER Interrupt
        NVIC_InitStructure.NVIC_IRQChannel = I2C1_ER_IRQn;
        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
        NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

        NVIC_Init(&NVIC_InitStructure);

        // I2C EV Interrupt
        NVIC_InitStructure.NVIC_IRQChannel = I2C1_EV_IRQn;
        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
        NVIC_Init(&NVIC_InitStructure);
    }else if(I2C == I2C2){
        // I2C ER Interrupt
        NVIC_InitStructure.NVIC_IRQChannel = I2C2_ER_IRQn;
        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
        NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

        NVIC_Init(&NVIC_InitStructure);

        // I2C EV Interrupt
        NVIC_InitStructure.NVIC_IRQChannel = I2C2_EV_IRQn;
        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
        NVIC_Init(&NVIC_InitStructure);
    }
    
    context->init = 1;
}

void i2c1_init(void)
{
    i2c_init(I2C1);
}

void i2c2_init(void)
{
    i2c_init(I2C2);
}

void I2C1_ER_IRQHandler(void)
{
    i2c_er_handler(I2C1, &i2c1_context);
}

void I2C1_EV_IRQHandler(void)
{
    i2c_ev_handler(I2C1, &i2c1_context);
}

void I2C2_ER_IRQHandler(void)
{
    i2c_er_handler(I2C2, &i2c2_context);
}

void I2C2_EV_IRQHandler(void)
{
    i2c_ev_handler(I2C2, &i2c2_context);
}

uint8_t i2c1_write(uint8_t DeviceAddr, uint8_t RegAddr, const uint8_t* pBuffer, uint16_t len)
{
    return i2cWriteBuffer(I2C1, &i2c1_context, DeviceAddr,RegAddr,len,pBuffer);
}

uint8_t i2c1_read(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t* pBuffer, uint16_t len)
{
    return i2cRead(I2C1, &i2c1_context, DeviceAddr,RegAddr,len,pBuffer);
}

uint8_t i2c2_write(uint8_t DeviceAddr, uint8_t RegAddr, const uint8_t* pBuffer, uint16_t len)
{
    return i2cWriteBuffer(I2C2, &i2c2_context, DeviceAddr,RegAddr,len,pBuffer);
}

uint8_t i2c2_read(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t* pBuffer, uint16_t len)
{
    return i2cRead(I2C2, &i2c2_context, DeviceAddr,RegAddr,len,pBuffer);
}
