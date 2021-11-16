#include <msp430.h>
#include "hal_usciB1.h"
#include "hal_general.h"
//#include "main.c"

extern USCIB1_SPICom TxBUF;
int LCD_Input;

void HAL_USCIB1_Init()
{
        UCB1CTL1 |= UCSWRST;   // reset enable
//-----------------------------------------------------------------------------
        UCB1CTL1 |= UCSSEL_3;  //* select Submaster Clock

        UCB1CTL0 &= UCCKPH;    //* select phase 0
        UCB1CTL0 |= UCCKPL;    //* polarity = 1
        UCB1CTL0 |= UCMSB;     //* MSB first
        UCB1CTL0 |= UC7BIT;    //* select 8 Bit
        UCB1CTL0 |= UCMST;     //* select Master Mode

        UCB1BR0 = 25;          //*
        UCB1BR1 = 0;           //*
//----------------------------------------------------------------------------
        UCB1CTL1 &= UCSWRST;   // disable reset


        UCB1IE |= UCRXIE;       //interrupt when received
        UCB1IE   |= UCTXIE;    //interrupt enable
}


void HAL_USCIB1_Transmit (int LCD_Input)
{
    TxBUF.Status.B.TxSuc = 0;
    TxBUF.TxData.cnt = 0;

    UCTXBUFx = TxBUF.TxData.Data[TxBUF.TxData.cnt];
    //CS_Active
    TxBUF.TxData.len = LCD_Input;
}

#pragma vector = USCI_B1_VECTOR
__interrupt void USCI_B1 (void)
{

}




