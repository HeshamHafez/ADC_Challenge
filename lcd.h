 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.h
 *
 * Description: Header file for the LCD driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef LCD_H_
#define LCD_H_

#include "std_types.h"
#include "Macro.h"
#include "DIO.h"


/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
/* LCD HW Pins */
#define RS ((DIO_PIN28)-(DIO_PIN24))
#define RW ((DIO_PIN29)-(DIO_PIN24))
#define E  ((DIO_PIN30)-(DIO_PIN24))

#define LCD_CTRL_PORT 			DIO_PORTD
#define LCD_CTRL_PORT_DIR 		DIO_DDRD
#define LCD_DATA_PORT 			DIO_PORTC
#define LCD_DATA_PORT_DIR 		DIO_DDRC

/* LCD Commands */
#define CLEAR_COMMAND 0x01
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80 

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void LCD_sendCommand(uint8 command);
void LCD_displayCharacter(uint8 data);
void LCD_displayString(const char *Str);
void LCD_init(void);
void LCD_clearScreen(void);
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);
void LCD_goToRowColumn(uint8 row,uint8 col);
void LCD_intgerToString(int32 data);

#endif /* LCD_H_ */
