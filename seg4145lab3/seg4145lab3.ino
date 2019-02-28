/******************************************************************************
 * Students: 
 *   (7267012) William Gardiner 
 *   (7865198) Dylan Greene
 *   (8135145) Jessica Zhan
 * Course Info: 
 *   SEG 4145
 *   Lab 3
 *
 * seg4145lab3
 *   The main file for Lab 3. Contains the setup and the loop.
 *
 * Date: 
 *    February 11 2019
 *****************************************************************************/
#include <string.h>
#include <unistd.h>
#include <SoftwareSerial.h>
#include <Servo.h>

#include "proc_startup_message.h"
#include "proc_until_obstacle.h"
#include "proc_obstacle_avoidance.h"
#include "cont_movement.h"


// Global Variables
SoftwareSerial LCD = SoftwareSerial(0, LCD_PIN); // The LCD display.
Servo sensorServo;

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
void setup() { //stingray

  // Startup Messge
  procStartupMessageSetup();
  displayStartupMessage();

 sensorServo.attach(7);
 sensorServo.write(70);
 delay(1000);
 sensorServo.detach();
   
  // Interface Setup
  contMovementSetup();
  procUntilObstacleSetup();
  procObstacleAvoidanceSetup();

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
  moveForwardUntilObstacle(10);
  obstacleAvoidanceProcedure();
}
