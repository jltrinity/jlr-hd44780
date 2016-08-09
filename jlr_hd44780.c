/*
 * Juan Luis Román
 * HD44780 LCD for AVR Microcontrollers
 * 8 August 2016
 * Version: 1.0
 *
*/

void LCD_init_Port(void){
	DDRB = 0x3F; //B0-B5 outputs
}

void LCD_init(void){
	LCD_sendCmd(0x33); //initialize controller
	LCD_sendCmd(0x32); //set to 4-bit input mode
	LCD_sendCmd(0x28); //2 line, 5x7 matrix
	LCD_sendCmd(0x0C); //turn cursor off - 0x0E to enable
	LCD_sendCmd(0x06); //cursor direction = right
	LCD_sendCmd(0x01); //start with clear display
	_delay_ms(3);
}

void LCD_sendNibble(byte data){
	PORTB &= 0xC3; //clear 4 data lines = 1100.0011
	if(data & _BV(4))	PORTB |= (1 << DAT4);
	if(data & _BV(5))	PORTB |= (1 << DAT5);
	if(data & _BV(6))	PORTB |= (1 << DAT6);
	if(data & _BV(7))	PORTB |= (1 << DAT7);	
}

void LCD_pulseEnableLine(void){
	PORTB |= (1 << LCD_E);
	_delay_ms(1);
	PORTB &= ~(1 << LCD_E);
}

void LCD_sendByte(byte data){
	LCD_sendNibble(data);
	LCD_pulseEnableLine();
	data <<= 4;
	LCD_sendNibble(data);
	LCD_pulseEnableLine();
	//??
}

void LCD_sendChar(byte ch){
	PORTB |= (1 << LCD_RS); //character data
	LCD_sendByte(ch); //send it
}

void LCD_sendCmd(byte cmd){
	PORTB &= ~(1 << LCD_RS); //command data
	LCD_sendByte(cmd); //send it
}

void LCD_showMessage(const char *t){
	while(*t){
		LCD_sendChar(*t++);	
	}
}

void LCD_goTo(byte x, byte y){
	byte addr = 0;
	
	switch(y){
		case 1: addr=0x40; break;
		case 2: addr=0x14; break;
		case 3: addr=0x54; break;
	}
	LCD_sendCmd(SET_CURSOR+addr+x);
}

void LCD_clear(void){
	LCD_sendCmd(CLEAR_DISPLAY);
	_delay_ms(3);
}

void LCD_int(int data){
	char str[8] = "";
	itoa(data,str,10);
	LCD_showMessage(str);
}

