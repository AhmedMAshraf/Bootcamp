

/**
 * main.c
 */
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

#include "Buzzer.h"
#include "Leds.h"
#include "Lcd.h"
#include "PushBtn.h"
#include "Delay.h"
#include "SysTick.h"


uint16_t Time_Count = 1 ;


int main(void)
{
    uint16_t Led1_Periodicity = 100 ;
    uint16_t Led2_Periodicity = 200 ;
    uint16_t Led3_Periodicity = 1000 ;
    uint16_t Buzzer_Periodicity = 10 ;
    uint8_t Btn = 0 , BtnPrev = 0 ;
    uint16_t Btn_Count ;


    //Leds_Init();
    Buzzer_Init();
    //Btns_Init();
    LCD_INIT();

    LCD_Send_Command (CLEAR_LCD);
    LCD_Send_Data('a');
    LCD_Send_Data('B');
    LCD_Send_Data('M');
    while(1)
    {
       if(Time_Count % Led1_Periodicity == 0)
           Led1_Blink();

       if(Time_Count%Led2_Periodicity == 0)
           Led2_Blink();

       if(Time_Count%Led3_Periodicity == 0)
           Led3_Blink();

       if(Time_Count%Buzzer_Periodicity == 0)
           Buzzer_Toggle();

       Btn = Btn1_Read();
       BtnPrev = Btn ;
       SysTick_Delay(1);
       Time_Count++;


    }

	return 0;
}
