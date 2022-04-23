#include "homeauto.h"
void LCD_Command(unsigned char cmnd) 				/*LCD Commands initialisation*/
{
	LCD_Port = (LCD_Port & 0x0F) | (cmnd & 0xF0); 		/* sending upper nibble */
	LCD_Port &= ~(1 << RS);					/* RS=0, command reg. */
	LCD_Port |= (1 << EN);					/* Enable pulse */
	_delay_us(1);
	LCD_Port &= ~(1 << EN); 				/* Disables Enable pin*/
	_delay_us(200);
	LCD_Port = (LCD_Port & 0x0F) | (cmnd << 4); 		/* sending lower nibble */
	LCD_Port |= (1 << EN);					/* Disable Enable pin */
	_delay_us(1);
	LCD_Port &= ~(1 << EN); 				/* Toggling pulse*/
	_delay_ms(2);
}
void LCD_Char(unsigned char data)				/*Prints character on screen*/
{
	LCD_Port = (LCD_Port & 0x0F) | (data & 0xF0); 		/* sending upper nibble */
	LCD_Port |= (1 << RS);					/* RS=1, data reg. */
	LCD_Port |= (1 << EN);					/* Enable pulse */
	_delay_us(1);
	LCD_Port &= ~(1 << EN); 				/* Disable enable pins*/
	_delay_us(200);
	LCD_Port = (LCD_Port & 0x0F) | (data << 4); 		/* sending lower nibble */
	LCD_Port |= (1 << EN);					/* Enable pulse */
	_delay_us(1);
	LCD_Port &= ~(1 << EN); 				/* Disables enable pin */
	_delay_ms(2);
}
void LCD_Init(void) 						/* LCD Initialize function */
{
	LCD_Dir = 0xFF;	   					/* Make LCD port direction as o/p */
	_delay_ms(20);	   					/* LCD Power ON delay always >15ms */
	LCD_Command(0x02);					/* send for 4 bit initialization of LCD  */
	LCD_Command(0x28); 					/* 2 line, 5*7 matrix in 4-bit mode */
	LCD_Command(0x0c); 					/* Display on cursor off*/
	LCD_Command(0x06); 					/* Increment cursor (shift cursor to right)*/
	LCD_Command(0x01); 					/* Clear display screen*/
	_delay_ms(2);
}

void LCD_String(char *str) 					/* Send string to LCD function */
{
	int i;
	for (i = 0; str[i] != 0; i++) 				/* Send each char of string till the NULL */
	{
		LCD_Char(str[i]);
	}
}

void LCD_String_xy(char row, char pos, char *str) 		/* Send string to LCD with xy position */
{
	if (row == 0 && pos < 16)
		LCD_Command((pos & 0x0F) | 0x80); 		/* Command of first row and required position<16 */
	else if (row == 1 && pos < 16)
		LCD_Command((pos & 0x0F) | 0xC0); 		/* Command of first row and required position<16 */
	LCD_String(str);					/* Call LCD string function */
}

void LCD_Clear() 						/*Initialisation of Clearing LCD*/
{
	LCD_Command(0x01); 					/* Clear display */
	_delay_ms(2);
	LCD_Command(0x80); 					/* Cursor at home position */
}

unsigned char keypad[4][4] = {{'7', '8', '9', '7'},
			      {'4', '5', '6', '4'},
			      {'1', '2', '3', '1'},
			      {'*', '0', '#', '*'}};

unsigned char col, row;
char keyfind() 							/*Keypad Check Initialisation*/
{
	while (1)
	{
		KEY_DDR = 0xF0; 				/* set PORT direction as input-output */
		KEY_PRT = 0xFF; 				/*Set PORT status to write*/
		do	
		{
			KEY_PRT &= 0x0F;			/* mask PORT for column read only */
			col = (KEY_PIN & 0x0F); 		/* read status of column */
		} while (col != 0x0F);

		do
		{
			do
			{
				
				_delay_ms(20);			/* 20ms key debounce time */
				col = (KEY_PIN & 0x0F); 	/* read status of column */
			} while (col == 0x0F);			/* check for any key press */
								/* 20 ms key debounce time */
			_delay_ms(40);
			col = (KEY_PIN & 0x0F);
		} while (col == 0x0F);

								/* now check for rows */
								/* check for pressed key in 1st row */
		KEY_PRT = 0xEF;
		col = (KEY_PIN & 0x0F);
		if (col != 0x0F)
		{
			row = 0;
			break;
		}
								/* check for pressed key in 2nd row */
		KEY_PRT = 0xDF;
		col = (KEY_PIN & 0x0F);
		if (col != 0x0F)
		{
			row = 1;
			break;
		}
								/* check for pressed key in 3rd row */
		KEY_PRT = 0xBF;
		col = (KEY_PIN & 0x0F);
		if (col != 0x0F)
		{
			row = 2;
			break;
		}
								/* check for pressed key in 4th row */
		KEY_PRT = 0x7F;
		col = (KEY_PIN & 0x0F);
		if (col != 0x0F)
		{
			row = 3;
			break;
		}
	}

	if (col == 0x0E)
		return (keypad[row][3]);
	else if (col == 0x0D)
		return (keypad[row][1]);
	else if (col == 0x0B)
		return (keypad[row][2]);
	else
		return (keypad[row][3]);
}

void ADC_Init() 						/*Initialising Analog to Digital Conversion*/
{
	DDRC &= ~(1 << 5); 					/* Make ADC port as input */
	ADCSRA = 0x87;	   					/* Enable ADC, fr/128  */
	ADMUX = 0x40;	   					/* Vref: Avcc, ADC channel: 0 */
}
int ADC_Read(char channel) 					/*Initialising Analog Data Read*/
{
	int Ain, AinLow;
	ADMUX = ADMUX | (channel & 0x0f); 			/* Set input channel to read */
	ADCSRA |= (1 << ADSC);			  		/* Start conversion */
	while ((ADCSRA & (1 << ADIF)) == 0); 			/* Monitor end of conversion interrupt */
	_delay_us(10);
	AinLow = (int)ADCL;	  				/* Read lower byte*/
	Ain = (int)ADCH * 256; 					/* Read higher 2 bits and Multiply with weight */
	Ain = Ain + AinLow;
	return (Ain); 						/* Return digital value*/
}

int map(int x, int in_min, int in_max, int out_min, int out_max)/*Initialising Function to Map values*/
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min; /*Formula for Mapping*/
}
int password(char arr[]) 					/*Password Check Function*/
{
	LCD_Clear(); 						/*Clear LCD*/
	LCD_Init();						/*LCD Initialisation*/
	int flag = 0;
first:
	LCD_String("Enter pwd:");
	for (int i = 0; i < 4; i++) 				/*LOOP For password Check*/
	{
		char pwd = keyfind();
		LCD_Char(pwd);
		if (i == 0 && pwd == arr[i])
			continue;
		else if (i == 1 && pwd == arr[i])
			continue;
		else if (i == 2 && pwd == arr[i])
			continue;
		else if (i == 3 && pwd == arr[i])
			continue;
		else
		{
			flag = 1;
			for (i++; i < 4; i++)
			{
				char pwd = keyfind();
				LCD_Char(pwd);
			}
		}
	}
	if (flag == 1)
	{
		LCD_Clear(); 					/* Clear display */
		LCD_String("Wrong pwd");
		flag = 0;
		_delay_ms(2500);
		LCD_Clear(); 					/* Clear display */
		goto first;
	}
	else if (flag == 0)
	{
		return 1;
	}
}
