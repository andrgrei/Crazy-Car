#include <msp430.h>
#include "driver_general.h"
#include "driver_aktorik.h"

void Driver_Init ()
{
    Driver_SetSteering();
    Driver_SetThrottle();
}
