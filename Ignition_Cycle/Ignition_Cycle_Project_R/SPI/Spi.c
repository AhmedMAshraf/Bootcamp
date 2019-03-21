/*
 * Spi.c
 *
 *  Created on: Mar 20, 2019
 *      Author: AVE-LAP-062
 */
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/ssi.h"
#include "utils/uartstdio.h"
#include "../FreeRTOS.h"
#include "../task.h"
#include "../queue.h"
#include "../semphr.h"
#include "../Includes/Spi.h"

extern QueueHandle_t xSPIRecv ;

/*******************************************************************/
/* SPI_Init                                                        */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : void                                                   */
/* fn that init SPI Module                                         */
/*******************************************************************/
void SPI3_Slave_Init(void)
{
    // Enable the SSI0 peripheral
                 //
                 SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI3);
                 //
                 // Wait for the SSI0 module to be ready.
                 //
                 while(!SysCtlPeripheralReady(SYSCTL_PERIPH_SSI3))
                 {
                 }
           SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
                   //
                   // Wait for the SSI0 module to be ready.
                   //
                   while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOD))
                   {
                   }

           // Enable SPI0 functionality on GPIO Port A pins 2 to 4.
             //
             GPIOPinConfigure(GPIO_PD0_SSI3CLK);
             GPIOPinConfigure(GPIO_PD1_SSI3FSS);
             GPIOPinConfigure(GPIO_PD2_SSI3RX);
             GPIOPinConfigure(GPIO_PD3_SSI3TX);

             GPIOPinTypeSSI(GPIO_PORTD_BASE, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2| GPIO_PIN_3);

             //
             // Configure the SSI.
             //
             SSIConfigSetExpClk(SSI3_BASE, SysCtlClockGet(), SSI_FRF_MOTO_MODE_0,
             SSI_MODE_SLAVE, 2000000, 8);
             //
             // Enable the SSI module.
             //
             SSIEnable(SSI3_BASE);


}

/*******************************************************************/
/* SPI_Send                                                        */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : void                                                   */
/* fn that send data on SPI                                        */
/*******************************************************************/
void SPI2_Send(uint8_t data_to_send)
{
    SSIDataPut(SSI2_BASE, data_to_send);
}

/*******************************************************************/
/* SPI_Receive                                                     */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : void                                                   */
/* fn that Recieve data From spi                                   */
/*******************************************************************/
uint32_t SPI3_Recieve(void)
{
    static uint32_t received_data ;
    if(SSIDataGetNonBlocking(SSI3_BASE, &received_data) != 0 )
    {
        return received_data ;
    }
    else
        return 0 ;
}


/*******************************************************************/
/* SPI_Recieve_Task                                                */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : void                                                   */
/* task that handles SPI recept data                               */
/*******************************************************************/
void SPI_Recieve_Task(void *pvParameters)
{
    SPI3_Slave_Init();
    vTaskDelay(500);
    while(1)
    {
        uint32_t data = 0 ;
        data = SPI3_Recieve();
        if(data)
        {
            xQueueSendToBack(xSPIRecv, &data , 10 );
        }
        vTaskDelay(10);
    }
}
