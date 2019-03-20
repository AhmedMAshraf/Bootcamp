/*
 * UART.c
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-016
 */
#include "UART.h"

volatile uint8_t UART_Flag = 0 ;
volatile uint8_t DataToSend = 0 ;
void UART0_init(void)
{
    //
        // Enable the UART0 module.
        //
        //
        // Enable the GPIOB peripheral
        //
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
        //
        // Wait for the GPIOB module to be ready.
        //
        while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOE))
        {
        }

        /* Configure GPIO Port B pins 0 and 1 to be used as UART1.*/
        GPIOPinTypeUART(GPIO_PORTE_BASE, GPIO_PIN_4 | GPIO_PIN_5);
        //
        // Enable UART1 functionality on GPIO Port B pins 0 and 1.
        //
        GPIOPinConfigure(GPIO_PE4_U5RX);
        GPIOPinConfigure(GPIO_PE5_U5TX);

        SysCtlPeripheralEnable(SYSCTL_PERIPH_UART5);

        /* Wait for the UART0 module to be ready. */
        while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART5))
        {
        }
        // Initialize the UART. Set the baud rate, number of data bits, turn off
        // parity, number of stop bits, and stick mode. The UART is enabled by the
        // function call.
        //
        UARTConfigSetExpClk(UART5_BASE, SysCtlClockGet(), 38400,
        (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
        UART_CONFIG_PAR_NONE));
}

/*******************************************************************/
/* UART0_Send_Task                                                 */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : void                                                   */
/* task that send data on UART0                                    */
/*******************************************************************/
void UART0_Send(uint8_t data)
{
  UARTCharPut(UART5_BASE, data);
}

/*******************************************************************/
/* UART0_Recv                                                      */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : void                                                   */
/* fn that recv data on UART0                                      */
/*******************************************************************/
uint8_t UART0_Recv(void)
{
    uint8_t data = 0;
    if(UARTCharsAvail(UART5_BASE))
    {
        data = UARTCharGetNonBlocking(UART5_BASE);
    }
    return data ;
}
