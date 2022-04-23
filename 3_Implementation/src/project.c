#include "homeauto.h"
int main(void)
{
	int count = 0, count1 = 0, count2 = 0, res = 0, value, flag1 = 0;
	char string;
	char arr[4] = {'1', '2', '3', '4'};
	LCD_Init(); /*LCD Initialisation*/
up:
	res = password(arr);
	if (res == 1)
	{ /*Gives access to Keypad if password matches*/
		LCD_Clear();
		DDRC = 0xFF;
		while (1)
		{

			LCD_String_xy(0, 1, "Press a key"); 		/* Send string to LCD with xy position */
			LCD_Command(0xc0);				/*LCD Initialisation with first row and required position<16*/
			char result = keyfind();
			LCD_Char(result);
			if (result == '1') 				/*Main door Opens*/
			{

				PORTC ^= (1 << 0);
			}
			else if (result == '2') 			/*Main door Closes*/
			{
				PORTC ^= (1 << 1);
			}
			else if (result == '3')				/*Light1 Control*/
			{ 							

				PORTC ^= (1 << 2);
			}
			else if (result == '4') 			/*Light2 Control*/
			{
				PORTC ^= (1 << 3);
			}
			else if (result == '5')				/*Light3 Control*/		
			{ 

				PORTC ^= (1 << 4);
			}
			else if (result == '6')				/*Fan1 Control*/
			{
				PORTC ^= (1 << 6);
			}
			else if (result == '7') 			/*Fan2 Control*/
			{
				PORTB ^= (1 << 2);
			}
			else if (result == '8') 			/*Fan3 Control*/
			{
				PORTB ^= (1 << 3);
			}

			else if (result == '9') 			/*Room Temperature Display*/
			{
				char String[5];
				int value;
				LCD_Clear();
				ADC_Init();
				LCD_Init();				/* Initialization of LCD */
				LCD_Command(0xd4);			/* LCD16x2 cursor position */
				LCD_String("TEMP: ");			/* Write string on 1st line of LCD */
				value = ADC_Read(5);			/* Read ADC channel 5 */
				int val = map(value, 492, 478, 20, 35); /* Calling Map Function*/
				itoa(val, String, 10);			/* Integer to string conversion */
				LCD_String(String);			/* Initialising LCD String */
				LCD_String("  ");
				_delay_ms(2500);
				LCD_Clear(); 				/* Clearing LCD */
				LCD_Init();	 			/* Initialisation of LCD */
			}
									/* Gives no of appliances on*/
			else if (result == '*')
			{ 
				if (PORTC & (1 << 2))
					count1++;
				if (PORTC & (1 << 3))
					count1++;
				if (PORTC & (1 << 4))
					count1++;
				if (PORTC & (1 << 6))
					count2++;
				if (PORTB & (1 << 3))
					count2++;
				if (PORTB & (1 << 2))
					count2++;
				LCD_Clear();
				LCD_Char('l');
				LCD_Char('i');
				LCD_Char('g');
				LCD_Char('h');
				LCD_Char('t');
				LCD_Char('o');
				LCD_Char('n');
				LCD_Char(':');
				char charvalue = count1 + '0'; 		/*Converts int value into char but only happens for 0-9*/
				LCD_Char(charvalue);
				_delay_ms(2500);
				LCD_Clear(); 				/* Clearing LCD */
				LCD_Char('f');
				LCD_Char('a');
				LCD_Char('n');
				LCD_Char('o');
				LCD_Char('n');
				LCD_Char(':');
				char charvalue1 = count2 + '0';
				LCD_Char(charvalue1);
				count1 = 0;
				count2 = 0;
				_delay_ms(2500);
				LCD_Clear();				/* Clearing LCD */
				LCD_String_xy(0, 1, "Press a key");	/* Send string to LCD with xy position */
			}
			else if (result == '0') 			/*Password Reset*/
			{
				int result = 0;
				result = password(arr);
				if (result == 1)
				{
					LCD_Clear();
					LCD_Init();
					LCD_String("Resetpwd:");
					for (int i = 0; i < 4; i++)
					{
						int res1 = keyfind();
						arr[i] = res1;
						LCD_Char(res1);
					}
					LCD_Clear();
				}
			}
			else if (result == '#') 			/*Microcontroller Reset*/
			{
				PORTC = (0 << 0);
				PORTC = (0 << 1);
				PORTC = (0 << 2);
				PORTC = (0 << 3);
				PORTC = (0 << 4);
				PORTC = (0 << 6);
				PORTB = (0 << 1);
				PORTB = (0 << 2);

				goto up;
			}
		}
	}
}
