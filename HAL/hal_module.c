#include "hal_module.h"
#include <msp430.h>

void HAL_Wdt_Init()
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
}


