#include "hal_gpio.h"

#ifndef HAL_HAL_USCIB1_H_
#define HAL_HAL_USCIB1_H_

#define CS_INACTIVE   (P8OUT |= LCD_SPI_CS)
#define CS_ACTIVE (P8OUT &= ~LCD_SPI_CS)

//#define 100KHz_CLOCK_FREQ 25

typedef struct {

 union{
  unsigned char R;
  struct {
   unsigned char TxSuc:1; // Bit=1 wenn Daten übertragen wurden
   unsigned char dummy:7;
  }B;
 }Status;

 struct {
  unsigned char len;        // Länge der Daten in Bytes die übertragen werden
  unsigned char cnt;        // Index auf momentan übertragene Daten
  unsigned char Data[256];  // Tx Daten Array
 }TxData;

 struct {
  unsigned char len;        // Länge der empfangenen Daten
  unsigned char Data[256];  // Rx Daten Array
 }RxData;

}USCIB1_SPICom;


#endif /* HAL_HAL_USCIB1_H_ */

void HAL_USCIB1_Init(void);

void HAL_USCIB1_Transmit(int LCD_Input);

