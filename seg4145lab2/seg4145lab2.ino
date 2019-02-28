/******************************************************************************
 * Students: 
 *   (7267012) William Gardiner 
 *   (7865198) Dylan Greene
 *   (8135145) Jessica Zhan
 * Course Info: 
 *   SEG 4145
 *   Lab 2
 *
 * seg4145lab2
 *   The main file for Lab 2. Contains the setup and the loop.
 *
 * Date: 
 *   28 January 2019
 *****************************************************************************/
#include <string.h>
#include <unistd.h>
#include <SoftwareSerial.h>

#include "proc_startup_message.h"
#include "proc_follow_path.h"
#include "proc_halt.h"

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
  procFollowPathSetup();
  procStartupMessageSetup();

  // Startup Messge
   //displayStartupMessage();
    
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
  runPath(false);
  halt();
}
