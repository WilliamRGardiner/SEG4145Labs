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
#include <Wirefree.h>
#include <WifiClient.h>

#include "proc_startup_message.h"
#include "proc_until_obstacle.h"
#include "proc_obstacle_avoidance.h"
#include "intr_temperature.h"
#include "cont_movement.h"
#include "intr_proximity_sensor.h"
#include "intr_wifi.h"
#include "proc_wifi_commands.h"



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

   Serial.begin(9600);

  // Startup Messge
  procStartupMessageSetup();
  displayStartupMessage();

  // Face robot head forward
  sensorServo.attach(7);
  sensorServo.write(70);
  delay(1000);
  sensorServo.detach();

  // Wifi Setup
   intrWifiSetup(); 

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

  readCommands();

}
