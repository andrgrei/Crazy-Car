#include "hal_timerA1.h"
#include <msp430.h>

int throttle_counter = 0;

void HAL_TimerA1_Init()
{

    //TTA1CCTL0 |= CCIE;
    TA1CTL   |= MC_1;        // UpMode
    TA1CTL   |= TASSEL_2;    // source SubMasterCLK

    TA1CCTL2 |= OUTMOD_7;   //OutputMode Set/Reset
    //TA1CCTL2 &= ~CAP;      //CompareMode
    //TA1CCTL2 |= CCIE;     //Interrupt Enable

    TA1CCTL1 |= OUTMOD_7;
    //TA1CCTL1 &= ~CAP;
    //TA1CCTL1 |= CCIE;




    TA1CCR0 = 41666;    //Register 0 //60Hz
    TA1CCR1 = 0;        //Register Throttle
    TA1CCR2 = 0;        //Register Steering


}

#pragma vector = TIMER1_A0_VECTOR
__interrupt void Timer_A1 (void)
{
    throttle_counter ++;
}




