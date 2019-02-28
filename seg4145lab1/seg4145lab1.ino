/******************************************************************************
 * Students: 
 *   (7267012) William Gardiner 
 *   (7865198) Dylan Greene
 * Course Info: 
 *   SEG 4145
 *   Lab 1
 *
 * seg4145lab1
 *   The main file for Lab 1. Contains the setup and the loop.
 *
 * Date: 
 *   15 January 2019
 *****************************************************************************/
#include <string.h>
#include <unistd.h>
#include <SoftwareSerial.h>

#include "proc_startup_message.h"
#include "proc_follow_path.h"
#include "proc_halt.h"
#include "intr_motor_v2.h"

// Global Variables
SoftwareSerial LCD = SoftwareSerial(0, LCD_PIN); // The LCD display.

/******************************************************************************
* setup
*   Performs the required setup before the loop is called.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void setup() {

  // Interface Setup
//  lcdSetup();
  motorSetupV2();
//  ledSetup();

  // Startup Messge
//   displayStartupMessage();
    
}

/******************************************************************************
* loop
*   Runs the lab excercise.
*   
* Parameters:
*   None
*
* Returns:
*   void
*****************************************************************************/
void loop() {
//  runPath1(false);
//  delay(5000);
//  runPath2(false);
//  halt();
//  rotateRight();
  forwardV2();
}
