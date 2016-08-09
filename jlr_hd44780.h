/*
 * Juan Luis Román
 * HD44780 LCD for AVR Microcontrollers
 * 8 August 2016
 * Version: 1.0
 *
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



