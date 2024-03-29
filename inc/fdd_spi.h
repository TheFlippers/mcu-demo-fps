#ifndef __FDD_SPI_H
#define __FDD_SPI_H

#include "stm32f4xx.h"

void FDDspi_spi_init();

void FDDspi_GPIO_init();
void FDDspi_slave_init();
void FDDspi_slave_wDMA_init();
void FDDspi_dma_init(uint8_t*, uint8_t*);

#endif
