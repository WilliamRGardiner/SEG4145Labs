/******************************************************************************
 * Students: 
 *   (7267012) William Gardiner 
 *   (7865198) Dylan Greene
 *   (8135145) Jessica Zhan
 * Course Info: 
 *   SEG 4145
 *   Common Utility
 *
 * intr_led
 *   This module acts as a hardware interface for the LED.
 *
 * Date: 
 *   15 January 2019
 *****************************************************************************/
#ifndef INTR_LED_H
#define INTR_LED_H
#include "Arduino.h"
 
// Physical Properties
#define LED_PIN 13  // The pin the Arduino LED is on

// Signatures
void ledSetup();
void ledOn();
void ledOff();

bool INTR_LED_SETUP = false;
/******************************************************************************
* intrLedSetup
*   Prepares the LED to be used.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void intrLedSetup() {
  if(!INTR_LED_SETUP) {
    pinMode(LED_PIN, OUTPUT);
    INTR_LED_SETUP = true;
  }
}

/******************************************************************************
* ledOn
*   Turns the LED on.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void ledOn() {
  digitalWrite(LED_PIN, HIGH);
}

/******************************************************************************
* ledOn
*   Turns the LED off.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void ledOff() {
  digitalWrite(LED_PIN, LOW);
}
#endif
