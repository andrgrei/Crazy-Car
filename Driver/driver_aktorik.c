#include <msp430.h>
#include "driver_aktorik.h"

#define MAX_RPW 2500    //Max Reverse 1ms
#define MIN_RPW 5000    //Min Reverse 2ms
#define MIN_FPW 7500    //Max Forward 3ms
#define MAX_FPW 10000   //Min Forward 4ms

extern int throttle_cnt;

void Driver_SetSteering ()
{

}

void Driver_SetThrottle()
{
    throttle_cnt = 0;
    while (throttle_cnt < 560)
    {
       if (throttle_cnt <= 3)
        {
            TA1CCR1 = MAX_RPW;
        }

       else if (throttle_cnt <= 131)
        {
            TA1CCR1 = MAX_RPW;
        }

       else if (throttle_cnt <= 259)
        {
            TA1CCR1 = MIN_RPW;
        }

       else if (throttle_cnt <= 387)
        {
          TA1CCR1 = MIN_FPW;
        }

       else if (throttle_cnt <= 515)
        {
          TA1CCR1 = MAX_FPW;
        }

       else if (throttle_cnt <= 555)
        {
          TA1CCR1 = 6500;
        }
       else if (throttle_cnt == 559)
       {
          TA1CCTL0 &= ~CCIE;
          throttle_cnt ++;
       }

    }
}

