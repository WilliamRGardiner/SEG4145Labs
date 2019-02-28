/******************************************************************************
 * Students: 
 *   (7267012) William Gardiner 
 *   (7865198) Dylan Greene
 *   (8135145) Jessica Zhan
 * Course Info: 
 *   SEG 4145
 *   Common Utility
 *
 * proc_startup_message
 *   This module defines a procedure for displaying a startup message.
 *
 * Date: 
 *   15 January 2019
 *****************************************************************************/
#ifndef PROC_STARTUP_MESSAGE_H
#define PROC_STARTUP_MESSAGE_H
#include "intr_lcd_display.h"
#include "intr_led.h"
#include "cont_messages.h"

// Settings
#define STARTUP_STUDENT_NUMBER_1 "7267012" // Student number 1
#define STARTUP_STUDENT_NUMBER_2 "7865198" // Student number 2
#define STARTUP_TIME             5      // Total display time of student number in seconds

// Footprints
void procStartupMessageSetup();
void displayStartupMessage();

/******************************************************************************
* procFollowPathSetup
*   Sets up the startup message precedure.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void procStartupMessageSetup() {
  intrLcdDisplaySetup();
  intrLedSetup();
  contMessagesSetup();
}

/******************************************************************************
* runPath1
*   Displays the required startup message on the LCD.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void displayStartupMessage() {
  displayMessage(STARTUP_STUDENT_NUMBER_1, STARTUP_STUDENT_NUMBER_2, STARTUP_TIME);
}
#endif
