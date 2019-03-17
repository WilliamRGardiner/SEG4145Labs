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
#ifndef CONT_MESSAGES_H
#define CONT_MESSAGES_H
#include "intr_lcd_display.h"
#include "intr_led.h"

// Settings
#define STARTUP_LED_FLICKER_PERIOD  1000      // Time between (and including) light pulses in milliseconds
#define STARTUP_LED_ON_TIME          250      // Time the light remains on for each flash in milliseconds

// Footprints
void contMessagesSetup();
void displayMessage(char const* top, char const* bottom, int duration);
int ledDisplayOn(int remainingTime);
int ledDisplayOff(int remainingTime);
int adjustTime(int requestedDuration, int maxDuration);

bool CONT_MESSAGES_SETUP = false;

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
void contMessagesSetup() {
  if(!CONT_MESSAGES_SETUP) {
    intrLcdDisplaySetup();
    intrLedSetup();
    CONT_MESSAGES_SETUP = true;
  }
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
void displayMessage(char const* top, char const* bottom, int duration) {
  bool lightOn = false;
  for(int remainingTime = duration * STARTUP_LED_FLICKER_PERIOD, elapsedTime = 0; remainingTime > 0; remainingTime -= elapsedTime) {
    displayCenteredMessage(top, bottom);
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
