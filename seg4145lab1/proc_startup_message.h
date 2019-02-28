/******************************************************************************
 * Students: 
 *   (7267012) William Gardiner 
 *   (7865198) Dylan Greene
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

// Settings
#define STARTUP_STUDENT_NUMBER_1    "7267012" // Student number 1
#define STARTUP_STUDENT_NUMBER_2    "7865198" // Student number 2
#define STARTUP_TIME                5000      // Total display time of student number in milliseconds
#define STARTUP_LED_FLICKER_PERIOD  1000      // Time between (and including) light pulses in milliseconds
#define STARTUP_LED_ON_TIME          250      // Time the light remains on for each flash in milliseconds

// Footprints
void displayStartupMessage();
int ledDisplayOn(int remainingTime);
int ledDisplayOff(int remainingTime);
int adjustTime(int requestedDuration, int maxDuration);

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
  // displayCenteredMessage(STARTUP_STUDENT_NUMBER_1, STARTUP_STUDENT_NUMBER_2);
  int remainingTime = STARTUP_TIME;
  bool lightOn = false;
  for(int remainingTime = STARTUP_TIME, elapsedTime = 0; remainingTime > 0; remainingTime -= elapsedTime) {
    displayCenteredMessage(STARTUP_STUDENT_NUMBER_1, STARTUP_STUDENT_NUMBER_2);
    if(lightOn) {
      elapsedTime = ledDisplayOn(remainingTime);
    } else {
      elapsedTime = ledDisplayOff(remainingTime);
    }
    lightOn = !lightOn;
  }
  ledOff();
}

/******************************************************************************
* ledDisplayOn
*   Turns the LED light on for an amount of time bound by the remaining time 
*   in the startup and a predefined constant.
*   
* Parameters:
*   int remainingTime - the remaining time int the startup
*
* Returns:
*   int - The duration the light was on.
*****************************************************************************/
int ledDisplayOn(int remainingTime) {
  int duration = adjustTime(STARTUP_LED_ON_TIME, remainingTime);
  ledOn();
  delay(duration);
  return duration;
}

/******************************************************************************
* ledDisplayOff
*   Turns the LED light off for an amount of time bound by the remaining time 
*   in the startup and a predefined constant.
*   
* Parameters:
*   int remainingTime - the remaining time int the startup
*
* Returns:
*   int - The duration the light was off.
*****************************************************************************/
int ledDisplayOff(int remainingTime) {
  int duration = adjustTime(STARTUP_LED_FLICKER_PERIOD - STARTUP_LED_ON_TIME, remainingTime);
  ledOff();
  delay(duration);
  return duration;
}

/******************************************************************************
* ledDisplayOff
*   Takes the minimum of the requestedDuration and the maxDuration.
*   
* Parameters:
*   int requestedDuration - the requested duration
*   int maxDuration       - The maximum allowed duration
*
* Returns:
*   int - The minimum of the two nmbers given
*****************************************************************************/
int adjustTime(int requestedDuration, int maxDuration) {
  if(requestedDuration > maxDuration) {
    return maxDuration;
  } else {
    return requestedDuration;
  }
}

#endif
