

/**
 * main.c
 */

#include "DIO/Dio.h"
#include "Reg.h"

void Test_WriteChannel(void);
void Test_WritePort(void);
void Test_ReadChannelGroup(void);

Dio_ChannelGroupType str = {0x1E,1,PORTF_NO};
Dio_ChannelGroupType str2 = {0x1E,1,10};

#define SYSCTL_RCGC2_R (*((volatile unsigned long *)0x400FE108))

int main(void)
{
    /*Activate PORTF Clock*/
    volatile unsigned long delay ;

    SYSCTL_RCGC2_R |= 0x00000020;     // 1) activate clock for Port F

    delay = SYSCTL_RCGC2_R;           // allow time for clock to start

    /*Disable Analog Function of PORTF*/
    PORTF->AMSEL = 0x00 ;
    /*Set Direction of PF1 , PF2 , PF3 output , PF4 i/p */
    PORTF->DIR |= 0x0E ;
    /*Disable Alternate Function of PORTF*/
    PORTF->AFSEL = 0x00 ;
    /*Enable digital I/O on PF1 , PF2 , PF3 */
    PORTF->DEN = 0xff ;
    /* Enable internal pull up */
    PORTF->PUR = 0x11;

    PORTF->DATA = 0x00;


    /**** NOTE ****/
    /* In order to get the expected results
     * The below functions should be called
     * only if the other two function are commented
     */
    Test_WriteChannel();
    Test_WritePort();
    Test_ReadChannelGroup();


    while(1)
    {

    }
	return 0;
}


void Test_WriteChannel(void)
{
    uint32 Time_Delay ;
    /* Valid Test Turn Led1*/
    Dio_WriteChannel(PF1_ID, STD_HIGH);
    /* Wait some time */
    for(Time_Delay=0u ; Time_Delay<=0x008fffffu ; Time_Delay++)
    {

    }

    /* InValid Test Turn Led3 and off all leds */
    Dio_WriteChannel(60u, STD_HIGH);
    /* Wait some time */
    for(Time_Delay=0u ; Time_Delay<=0x008fffffu ; Time_Delay++)
    {

    }
}

void Test_WritePort(void)
{
    uint32 Time_Delay ;
    /* Valid Test Turn Led1*/
    Dio_WritePort(PORTF_NO, STD_HIGH);

    /* Wait some time */
    for(Time_Delay=0u ; Time_Delay<=0x008fffffu ; Time_Delay++)
    {

    }

    /* InValid Test Turn Led3 and off all leds */
    Dio_WritePort(60u, STD_HIGH);

    /* Wait some time */
    for(Time_Delay=0u ; Time_Delay<=0x000fffffu ; Time_Delay++)
    {

    }
}

void Test_ReadChannelGroup(void)
{
    uint8 channelgrp ;
    uint32 Time_Delay ;

  while(1)
      {
          /*************** VALID TEST ***************/
          channelgrp =Dio_ReadChannelGroup(&str);
          /* Check if SW1 (PF3) is not pressed (1) value of group = 0x10 >> 1 ---> 0x08 and all leds are off */
          if(channelgrp == 0x08 )
          {
              PORTF->DATA |= 0x04;
          }
          /* If Btn pressed then value of port = 0x04 >> 1 ---> 0x02 */
          else if (channelgrp == 0x02)
          {
              PORTF->DATA |= 0x0E;
          }

          /* Wait some time */
         for(Time_Delay=0u ; Time_Delay<=0x000fffffu ; Time_Delay++)
         {

         }

         /*************** INVALID TEST ***************/
         channelgrp =Dio_ReadChannelGroup(&str2);
         for(Time_Delay=0u ; Time_Delay<=0x000fffffu ; Time_Delay++)
         {

         }
      }
}
