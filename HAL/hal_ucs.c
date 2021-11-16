#include <msp430.h>
#include "hal_ucs.h"

void HAL_UCS_Init()
{
    UCSCTL6 &= ~XT2OFF;
    UCSCTL3 |= SELREF_2;
    UCSCTL4 |= SELA_2;

    while (SFRIFG1 & OFIFG) //Wait until all error flags are cleared and not set again
        {
            UCSCTL7 &= ~(XT2OFFG | DCOFFG | XT1HFOFFG | XT1LFOFFG);
            SFRIFG1 &= ~OFIFG;
         }

    UCSCTL6 &= ~XT2DRIVE_3; // drive strength to lowest
    UCSCTL6 |=  XT2DRIVE_2; // drive strength to 16-24Mhz

    UCSCTL4 |= SELS_5; // XT2 as source for SubMaster clock
    UCSCTL4 |= SELM_5; // XT2 as source for Master clock


    UCSCTL5 |= DIVS_3; // dividing source clock (XT2 = 20MHz) by 8 to 2.5MHz (SubMaster)
    UCSCTL5 |= DIVA_5; // dividing source clock (XT2 = 20MHz) by 32 to 0.625MHz (Auxillary)
}


