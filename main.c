#include <msp430.h>
#include <hal_general.h>
#include <hal_gpio.h>
#include <driver_general.h>
#include <hal_usciB1.h>

extern ButtonCom test;
extern USCIB1_SPICom TxBUF;


// Steering
#define LEFT_MAX 2750 //1,1ms
#define STRAIGHT 3750 //1,5ms
#define RIGHT_MAX 4750 //1,9ms

// Throttle
#define MAX_RPW 2500    //Max Reverse 1ms
#define MIN_RPW 5000    //Min Reverse 2ms
#define MAX_FPW 7500    //Max Forward 3ms
#define MIN_RPW 10000   //Min Forward 4ms


// Frquency
#define XTAL_FREQU  20000000 //20MHz
#define MCLK_FREQU  20000000 //20MHz
#define SMCLK_FREQU 2500000 //2,5MHz
#define ACLK_FREQU  625000  //0,625MHz

void main(void)
{
    HAL_Init();

    Driver_SetThrottle();

    /*while(1)
    {
        if (test.active == 1)
        {
            switch (test.button)
            {
            case START_BUTTON:
            {
                    LCD_BACKLIGHT_ON;
            }
            break;

            case STOP_BUTTON:
            {
                LCD_BACKLIGHT_OFF;
            }
            break;
            }
            test.active = 0;
        }
    }*/
}
