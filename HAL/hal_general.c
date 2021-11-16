
#include <msp430.h>
#include "hal_pmm.h"
#include "hal_general.h"
#include "hal_module.h"
#include "hal_gpio.h"
#include "hal_ucs.h"
#include "hal_timerA1.h"
#include "hal_timerB0.h"
#include "hal_usciB1.h"


ButtonCom test;

USCIB1_SPICom TxBUF;

void HAL_Init()
{
    HAL_Wdt_Init();
    HAL_PMM_Init();
    HAL_GPIO_Init();
    HAL_UCS_Init();
    HAL_TimerA1_Init();
    HAL_USCIB1_Init();
    HAL_USCIB1_Transmit();

    __enable_interrupt();

}





