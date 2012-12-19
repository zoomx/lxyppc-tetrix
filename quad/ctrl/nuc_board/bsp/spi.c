#include "spi.h"
#include "Driver\DrvSPI.h"
#include "Driver\DrvGPIO.h"

#define SPI_PORT    eDRVSPI_PORT1

void spi_init(void)
{
    /* Configure SPI0 related multi-function pins */
    DrvGPIO_InitFunction(E_FUNC_SPI1);
    /* Configure SPI0 as a master, 32-bit transaction */
    DrvSPI_Open(SPI_PORT, eDRVSPI_MASTER, eDRVSPI_TYPE1, 32);
    /* Enable the automatic slave select function of SS0. */
    DrvSPI_DisableAutoSS(SPI_PORT);
    /* Set the active level of slave select. */
    DrvSPI_SetSlaveSelectActiveLevel(SPI_PORT, eDRVSPI_ACTIVE_LOW_FALLING);
    /* SPI clock rate 2MHz */
    DrvSPI_SetClockFreq(SPI_PORT, 4000000, 0);
    
    DrvSPI_SetBitLength(SPI_PORT, 8);
}

uint8_t spi_transfer_byte(uint8_t byte)
{
    uint32_t au32SourceData = byte;
    while (DrvSPI_IsBusy(SPI_PORT)) {}
    DrvSPI_SingleWrite(SPI_PORT, &au32SourceData); 
    while (DrvSPI_IsBusy(SPI_PORT)) {}
    DrvSPI_SingleRead(SPI_PORT, &au32SourceData); 
    return (uint8_t)au32SourceData;
}

