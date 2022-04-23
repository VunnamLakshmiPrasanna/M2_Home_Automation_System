/**
 * @file homeauto.h
 * @author Yendamuri Manjunadh
 * @brief
 * @version 0.1
 * @date 2022-03-03
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __HOMEAUTO__H__
#define __HOMEAUTO__H__
#ifndef __AVR_ATmega328__
#define __AVR_ATmega328__
#endif
#define F_CPU 8000000UL                     /*Setting CPU Frequency*/
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

/**
 * @brief For PortC
 * Defines data port direction for Output
 * Define data port for Output
 * Define data read pin for Output
 */
#define DIS_DDR DDRC                        /* Define data port direction for Output */
#define DIS_PRT PORTC                       /* Define data port for Output*/
#define DIS_PIN PINC                        /*Define data read pin for Output*/

/**
 * @brief  For PORT D
 * Define data port direction for Keypad
 * Define data port for keypad
 * Define data read pin for Keypad
 */
#define KEY_DDR DDRD                        /* Define data port direction for Keypad */
#define KEY_PRT PORTD                       /* Define data port for keypad*/
#define KEY_PIN PIND                        /*Define data read pin for Keypad*/

/**
 * @brief For PORT B
 * Define LCD data port direction
 * Define Register Select pin
 * Define LCD data port
 * Define Enable signal pin
 */
#define LCD_Dir DDRB                       /* Define LCD data port direction */
#define LCD_Port PORTB                     /* Define LCD data port */
#define RS PB0                             /* Define Register Select pin */
#define EN PB1                             /* Define Enable signal pin */

/**
 * @brief Performs all the LCD commands
 * @param cmnd
 */
void LCD_Command(unsigned char cmnd);     /*LCD Commands initialisation*/

/**
 * @brief Prints Character on the LCD
 * @param data
 */
void LCD_Char(unsigned char data);       /*Prints character on screen*/

/**
 * @brief Initialises LCD Screen
 */
void LCD_Init(void);                     /* LCD Initialize function */

/**
 * @brief Prints string on the LCD Screen
 * @param str
 */
void LCD_String(char *str);              /* Send string to LCD function */

/**
 * @brief Displas string by selecting exact rows and columns
 * @param row
 * @param pos
 * @param str
 */
void LCD_String_xy(char row, char pos, char *str); /* Send string to LCD with xy position */

/**
 * @brief Clears LCD Screen
 */
void LCD_Clear();                        /*Initialisation of Clearing LCD*/

/**
 * @brief Detect the Kepad button we press
 * @return char
 */
char keyfind();                          /*Keypad Check Initialisation*/

/**
 * @brief Reads Analog bits and convert them into digital
 * @param channel
 * @return int
 */
int ADC_Read(char channel);              /*Initialising Analog to Digital Conversion*/

/**
 * @brief Initialises analog to digital conversion
 */
void ADC_Init();                         /*Initialising Analog Data Read*/

/**
 * @brief Maps our digital values into the range we want
 * @param x
 * @param in_min
 * @param in_max
 * @param out_min
 * @param out_max
 * @return int
 */
int map(int x, int in_min, int in_max, int out_min, int out_max); /*Initialising Function to Map values*/

/**
 * @brief Provides security by checking password
 * @param arr
 * @return int
 */
int password(char arr[]);                /*Password Check Function*/
#endif
