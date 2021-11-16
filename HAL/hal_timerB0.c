#include <msp430.h>
#include "hal_timerB0.h"

void HAL_TimerB0_Init()
{

}

#pragma vector = TIMER1_B0_VECTOR
__interrupt void Timer_B0 (void)
{
    //LCD_BACKLIGHT_ON;
}
