#include <hal_gpio.h>
#include "msp430.h"
#include "hal_gpio.h"
#include "hal_general.h"

extern ButtonCom test;

void HAL_GPIO_Init()
{
    P1DIR = 0xFF; P1IE = 0x00; P1IES = 0x00; P1OUT = 0x00; //P1IFG = 0x00;
    P2DIR = 0xFF;
    P3DIR = 0xFF;
    P4DIR = 0xFF;
    P5DIR = 0xFF;
    P6DIR = 0xFF;
    P7DIR = 0xFF;
    P8DIR = 0xFF;
    P9DIR = 0xFF;



    //                  ---------- Port 1 ----------
    //P1DIR = 8b00100000;

    P1DIR &= ~START_BUTTON;
    P1DIR &= ~STOP_BUTTON;
    P1DIR &= ~RPM_SENSOR;
    P1DIR &= ~RPM_SENSOR_DIR;

    //P1REN = 8b00000111;
    //P1OUT = 8b11100000;

    P1IE  |= START_BUTTON;
    P1IE  |= STOP_BUTTON;

    P1IES |= START_BUTTON;
    P1IES |= STOP_BUTTON;

    P1OUT |= START_BUTTON;
    P1OUT |= STOP_BUTTON;

    //P1IFG |= START_BUTTON;
    //P1IFG |= STOP_BUTTON;


    //                      ---------- Port 2 ----------
    //P2DIR = 8b11111110;
    P2DIR &= ~I2C_SCL_MOTION;


    //                      ---------- Port 3 ----------

    P3SEL |= SMCLK;
    P3SEL |= THROTTLE;
    P3SEL |= STEERING;


    P3DIR |= THROTTLE;
    P3DIR |= STEERING;



    //                      ---------- Port 4 ----------
    //P4DIR = 00000111;
    P4DIR &= ~LINE_FOLLOW_2;
    P4DIR &= ~LINE_FOLLOW_3;
    P4DIR &= ~LINE_FOLLOW_4;
    P4DIR &= ~LINE_FOLLOW_5;

    //                      ---------- Port 5 ----------
    //P5DIR = 8b00000000;
    P5DIR = ~P5DIR;

    //                      ---------- Port 6 ----------
    //P6DIR = 8b11110000;
    P6DIR &= ~DISTANCE_RIGHT;
    P6DIR &= ~DISTANCE_LEFT;
    P6DIR &= ~DISTANCE_FRONT;
    P6DIR &= ~VBAT_MEASURE;

    //                      ---------- Port 7 ----------

    P7SEL |= XT2_IN;
    P7SEL |= XT2_OUT;
    UCSCTL6 &= ~XT2BYPASS;



    //                      ---------- Port 8 ----------
    //P7DIR = 8b10110111;
    P8DIR |= (LCD_BL | LCD_SPI_CS | UART_TXD_AUX | LCD_SPI_CLK | LCD_SPI_MOSI | LCD_DATACMD);
    P8DIR &= ~UART_RXD_AUX;
    P8DIR &= ~LCD_SPI_MISO;
    P8SEL |= (LCD_SPI_MISO | LCD_SPI_CLK | LCD_SPI_MOSI);




    //                      ---------- Port 9 ----------
    //P9DIR = 8b11111111;

}

#pragma vector = PORT1_VECTOR
__interrupt void P1_ISR(void)

{
    switch (P1IFG)
    {
        case START_BUTTON:
                {
                    test.active == 1;
                    test.button == START_BUTTON;
                    P1IFG &= ~START_BUTTON;
                }
        break;
        case STOP_BUTTON:
                {
                    test.active == 1;
                    test.button == STOP_BUTTON;
                    P1IFG &= ~STOP_BUTTON;
                }
        break;
        default:
            P1IFG = 0x00;
            break;

    }
}

