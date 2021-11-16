#ifndef HAL_HAL_GPIO_H_
#define HAL_HAL_GPIO_H_
#define LCD_BACKLIGHT_ON  (P8OUT |= LCD_BL)
#define LCD_BACKLIGHT_OFF (P8OUT &= ~LCD_BL)

// ------------------------ Port 1 -------------------------
//        XX                BIT0        // locked R
//        XX                BIT1        // locked R
//        XX                BIT2        // locked R
#define RPM_SENSOR          BIT3        // in
#define RPM_SENSOR_DIR      BIT4        // in
#define I2C_INT_MOTION      BIT5        // out
#define START_BUTTON        BIT6        // en
#define STOP_BUTTON         BIT7        // en



// ------------------------ Port 2 -------------------------
#define DEBUG_TXID          BIT0        // in
#define DEBUG_RXID          BIT1        // out
#define AUX_PIN_1           BIT2        // in/out
#define AUX_PIN_2           BIT3        // in/out
#define AUX_PIN_3           BIT4        // in/out
#define AUX_PIN_4           BIT5        // in/out
#define I2C_SDA_MOTION      BIT6        // in/out
#define I2C_SCL_MOTION      BIT7        // out


// ------------------------ Port 3 -------------------------
//        XX                BIT0        // locked R
//        XX                BIT1        // locked R
#define THROTTLE            BIT2        // out
#define STEERING            BIT3        // out
#define SMCLK               BIT4        // out
//        XX                BIT5        // locked R
//        XX                BIT6        // locked R
#define DISTANCE_FRONT_EN   BIT7        // out

//P3DIR = 8b10011100;
//P3REN = 8b01100011;
//P3OUT = 8b10011100;


// ------------------------ Port 4 -------------------------
//        XX                BIT0        // locked R
//        XX                BIT1        // locked R
//        XX                BIT2        // locked R
#define LINE_FOLLOW_2       BIT3        // in
#define LINE_FOLLOW_1       BIT4        // in
#define LINE_FOLLOW_3       BIT5        // in
#define LINE_FOLLOW_4       BIT6        // in
#define LINE_FOLLOW_5       BIT7        // in

//P4DIR = 8(1b0);
//P4REN = 8b00000111;
//P4OUT

// ------------------------ Port 5 -------------------------
//        XX                BIT0        // locked R
//        XX                BIT1        // locked R
//        XX                BIT2        // locked R
//        XX                BIT3        // locked R
//        XX                BIT4        // locked R
//        XX                BIT5        // locked R
//        XX                BIT6        // locked R
//        XX                BIT7        // locked R

//P5DIR = 8(1b0);
//P5REN = 8(1b1);
//P5OUT =


// ------------------------ Port 6 -------------------------
#define DISTANCE_RIGHT      BIT0        // in
#define DISTANCE_LEFT       BIT1        // in
#define DISTANCE_FRONT      BIT2        // in
#define VBAT_MEASURE        BIT3        // in
#define DISTANCE_LEFT_EN    BIT4        // out
//        XX                BIT5        // locked R
//        XX                BIT6        // locked R
//        XX                BIT7        // locked R

//P6DIR = 8b(1b0);
//P6REN = 8b11100000;
//P6OUT =

// ------------------------ Port 7 -------------------------
//        XX                BIT0        // N/A
//        XX                BIT1        // N/A
#define XT2_IN              BIT2        // in
#define XT2_OUT             BIT3        // out
//        XX                BIT4        // locked R
//        XX                BIT5        // locked R
//        XX                BIT6        // locked R
//        XX                BIT7        // locked R

//P7DIR = 8b(1b0);
//P7REN = 8b11100000;
//P6OUT = 8bxxxxxxxx;

// ------------------------ Port 8 -------------------------
#define LCD_BL              BIT0        // out
#define LCD_SPI_CS          BIT1        // out
#define UART_TXD_AUX        BIT2        // out
#define UART_RXD_AUX        BIT3        // in
#define LCD_SPI_CLK         BIT4        // out
#define LCD_SPI_MOSI        BIT5        // out
#define LCD_SPI_MISO        BIT6        // in
#define LCD_DATA_CMD        BIT7        // out

//P2DIR = 8b10xxxx0;

// ------------------------ Port 9 -------------------------
#define LCD_RESET           BIT0        // out
//        XX                BIT1        // locked R
//        XX                BIT2        // locked R
//        XX                BIT3        // locked R
//        XX                BIT4        // locked R
//        XX                BIT5        // locked R
//        XX                BIT6        // locked R
#define DISTANCE_RIGHT_EN   BIT7        // out

// ---------------------------------------------------------
// ---------------------------------------------------------

typedef struct {
    unsigned char active;
    unsigned char button;
}ButtonCom;







#endif /* HAL_HAL_GPIO_H_ */
