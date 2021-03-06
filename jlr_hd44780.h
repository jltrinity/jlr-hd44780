/*
 * Juan Luis Rom�n
 * HD44780 LCD for AVR Microcontrollers
 * August 2016
 * Version: 1.0
 *
*/

/* PINOUT */
/* LCD -- AVR
*  1 GND 		-- 	GND
*  2 VCC 		-- 	VCC
*  3 Contrast 	--  GND or potentiometer	
*  4 RS			--  PB0
*  5 RW			--  GND
*  6 CLK		--  PB1
*  7 D0			--  
*  8 D1			--
*  9 D2			--
*  10 D3		--
*  11 D4		--  PB2
*  12 D5		--  PB3
*  13 D6		--  PB4
*  14 D7		--  PB5
*  15 + LED		--  VCC
*  16 - LED		--  GND
*/

#define byte uint8_t
#define sbyte int8_t

//lcd defines
#define LCD_RS 0
#define LCD_E 1
#define DAT4 2
#define DAT5 3
#define DAT6 4
#define DAT7 5

#define CLEAR_DISPLAY 0x01
#define SET_CURSOR 0x80

void LCD_init_Port(void);
void LCD_init(void);
void LCD_sendNibble(byte data);
void LCD_pulseEnableLine(void);
void LCD_sendByte(byte data);
void LCD_sendChar(byte ch);
void LCD_sendCmd(byte cmd);
void LCD_showMessage(const char *t);
void LCD_goTo(byte x, byte y);
void LCD_clear(void);
void LCD_int(int data);



