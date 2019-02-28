/******************************************************************************
 * Students: 
 *   (7267012) William Gardiner 
 *   (7865198) Dylan Greene
 * Course Info: 
 *   SEG 4145
 *   Common Utility
 *
 * intr_lcd_display
 *   This module acts as a hardware interface for the LCD Display.
 *
 * Date: 
 *   15 January 2019
 *****************************************************************************/
#ifndef INTR_LCD_DISPLAY
#define INTR_LCD_DISPLAY
#include "Arduino.h"
#include <SoftwareSerial.h>

// Physical Properties
#define LCD_PIN             18  // The pin for the LCD
#define LCD_DELAY           10  // The delay after an LCD command
#define ROW_MULTIPLIER      64  // Used for positioning the cursor
#define STARTING_POSITION  128  // Used for positioning the cursor
#define DATA_RATE         9600  // Used in the setup

// Display Properties
#define LCD_WIDTH   16  // The width in characters of the LCD display
#define TOP_LINE     0  // The row index for the top line
#define BOTTOM_LINE  1  // The row index for the bottom line

// Commands
#define CLEAR_SCREEN      0x01  // The hex for clear screen
#define DISPLAY_OFF       0x08  // The hex to turn the display off
#define DISPLAY_ON        0x0C  // The hex to turn the display on
#define SCROLL_TEXT_LEFT  0x18  // The hex to scroll the text to the left
#define SCROLL_TEXT_RIGHT 0x1C  // The hex to scroll the text to the right
#define BACKLIGHT_ON      0x9D  // The hex to turn the backlight on
#define BACKLIGHT_OFF     0x80  // The hex to turn the backlight off
#define COMMAND_MODE      0xFE  // The hex to enter command mode

// Footprints
void lcdSetup();
int getCenterCol(int textWidth);
void displayCenteredMessage(char const* line1, char const* line2);
void displayCenteredLine(int row, char const* text);
void displayCenteredLineStr(int row, String text);
int getCenterCol(int textWidth);
void displayText(int row, int col, char const* text);
void displayTextStr(int row, int col, String text);
int cursorPosition(int row, int col);
void displayOn();
void displayOff();
void backlightOn();
void backlightOff();

extern SoftwareSerial LCD; // The LCD display.

/******************************************************************************
* lcdSetup
*   Prepares the LCD to be used.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void lcdSetup() {
  LCD.begin(9600);
}

/******************************************************************************
* clearLcd
*   Clears the LCD display.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void clearLcd() {
  LCD.write(COMMAND_MODE);
  LCD.write(CLEAR_SCREEN);
  delay(LCD_DELAY);
}

/******************************************************************************
* displayCenteredMessage
*   Displays a message centered on the LCD display.
*   
* Parameters:
*   char* line1 - The message to display on the top line
*   char* line2 - The message to display on the bottom line
*
* Returns:
*   void
*****************************************************************************/
void displayCenteredMessage(char const* line1, char const* line2) {
  clearLcd();
  displayCenteredLine(TOP_LINE, line1);
  displayCenteredLine(BOTTOM_LINE, line2);
}

/******************************************************************************
* displayCenteredMessage
*   Displays a message centered on the LCD display.
*   
* Parameters:
*   char* line1 - The message to display on the top line
*   char* line2 - The message to display on the bottom line
*
* Returns:
*   void
*****************************************************************************/
void displayCenteredMessageStr(String line1, String line2) {
  clearLcd();
  displayCenteredLineStr(TOP_LINE, line1);
  displayCenteredLineStr(BOTTOM_LINE, line2);
}

/******************************************************************************
* displayCenteredLine
*   Displays a message centered a given line.
*   
* Parameters:
*   char* text - The message to display on the line
*   int   row  - The line to display the message on
*
* Returns:
*   void
*****************************************************************************/
void displayCenteredLine(int row, char const* text) {
  displayText(row, getCenterCol(strlen(text)), text);
}

/******************************************************************************
* displayCenteredLine
*   Displays a message centered a given line.
*   
* Parameters:
*   char* text - The message to display on the line
*   int   row  - The line to display the message on
*
* Returns:
*   void
*****************************************************************************/
void displayCenteredLineStr(int row, String text) {
  displayTextStr(row, 0, text);
}

/******************************************************************************
* getCenterCol
*   Calculates the column the cursor should be on to center the text.
*   
* Parameters:
*   int textWidth  - The width of the text to be displayed
*
* Returns: 
*   int - the calculated column
*****************************************************************************/
int getCenterCol(int textWidth) {
   if(textWidth > LCD_WIDTH) {
    return 0;
  } else {
    return (LCD_WIDTH - textWidth) / 2;
  }
}

/******************************************************************************
* displayText
*   Prints the text in the given row and column.
*   
* Parameters:
*   int   row  - The line to display the message on
*   int   col  - The column to start printing the text on
*   char* text - The message to display on the line
*
* Returns: 
*   void
*****************************************************************************/
void displayText(int row, int col, char const* text){
    LCD.write(COMMAND_MODE);
    LCD.write(cursorPosition(row, col));
    LCD.print(text);
    delay(LCD_DELAY);
}

/******************************************************************************
* displayText
*   Prints the text in the given row and column.
*   
* Parameters:
*   int   row  - The line to display the message on
*   int   col  - The column to start printing the text on
*   char* text - The message to display on the line
*
* Returns: 
*   void
*****************************************************************************/
void displayTextStr(int row, int col, String text){
    LCD.write(COMMAND_MODE);
    LCD.write(cursorPosition(row, col));
    LCD.print(text);
    delay(LCD_DELAY);
}

/******************************************************************************
* cursorPosition
*   Calculates the gursor postition for a row and column.
*   
* Parameters:
*   int   row  - The row
*   int   col  - The column
*
* Returns: 
*   int - the calculated position
*****************************************************************************/
int cursorPosition(int row, int col) {
  return col + row*ROW_MULTIPLIER + STARTING_POSITION;
}

/******************************************************************************
* displayOn
*   Turns the display on.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void displayOn() {
  LCD.write(COMMAND_MODE);
  LCD.write(DISPLAY_ON);
  delay(LCD_DELAY);
}

/******************************************************************************
* displayOff
*   Turns the display off.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void displayOff() {
  LCD.write(COMMAND_MODE);
  LCD.write(DISPLAY_OFF);
  delay(LCD_DELAY);
}

/******************************************************************************
* backlightOn
*   Turns the backlight on.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void backlightOn() {
  LCD.write(COMMAND_MODE);
  LCD.write(BACKLIGHT_ON);
  delay(LCD_DELAY);
}

/******************************************************************************
* backlightOff
*   Turns the backlight off.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void backlightOff() {
  LCD.write(COMMAND_MODE);
  LCD.write(BACKLIGHT_OFF);
  delay(LCD_DELAY);
}

#endif
