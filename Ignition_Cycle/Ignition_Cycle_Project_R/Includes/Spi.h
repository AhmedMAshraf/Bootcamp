/*
 * Spi.h
 *
 *  Created on: Mar 20, 2019
 *      Author: AVE-LAP-062
 */

#ifndef INCLUDES_SPI_H_
#define INCLUDES_SPI_H_


extern void SPI3_Slave_Init(void);
extern void SPI2_Send(uint8_t data_to_send);
extern uint32_t SPI3_Recieve(void);
extern void SPI_Recieve_Task(void *pvParameters);

#endif /* INCLUDES_SPI_H_ */
