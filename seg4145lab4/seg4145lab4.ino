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


// Global Variables
SoftwareSerial LCD = SoftwareSerial(0, LCD_PIN); // The LCD display.
Servo sensorServo;

WIFI_PROFILE wireless_prof = {
 /* SSID */ "Stingray",
 /* WPA/WPA2 passphrase */ "",
 /* Robot IP address */ "10.136.160.24",
 /* subnet mask */ "255.255.255.0",
 /* Gateway IP */ "10.136.160.1", };
 
String remote_server = "192.168.1.145"; // peer device IP address.

String remote_port = "9876"; // arbitrary 

//Creates a client that can connect to a specified internet IP address and port number
WifiClient client(remote_server, remote_port, PROTO_UDP);

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

  intrMotorSetup();
  contMovementSetup();
  intrTemperatureSetup();
  contMessagesSetup();

  // Startup Messge
  procStartupMessageSetup();
  displayStartupMessage();
  
  sensorServo.attach(7);
  sensorServo.write(70);
  delay(1000);
  sensorServo.detach();

  // connect to AP
  Wireless.begin(&wireless_prof);

  // if you get a connection, report back via serial. client.connect() connect to the IP address and port specified earlier. It returns true if the connection succeeds, false if not.
  if (client.connect()) {
    Serial.println("connected"); // prints to serial monitor. Check the Serial Monitor Section at the end of  this manual.
    // Send message over UDP socket to peer device
    client.println("aBcDe"); //Your own message
  }
  else {
    // if connection setup failed:
    Serial.println("failed");
  } 

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
// if there are incoming bytes available from the peer device, read them and print them:
 while (client.available()) {
  int in;
  while ((in = client.read()) == -1);
    Serial.print((char)in);

    if((char)in == '1'){
      Serial.print("1 - Move the robot forward");
      attachLeftMotorServo();
      attachRightMotorServo();
      moveForward(10);
    }
    else if((char)in == '2'){
      Serial.print("2 - Move the robot backward");
      attachLeftMotorServo();
      attachRightMotorServo();
      moveBackward(10);
    }
    else if((char)in == '3'){
      Serial.print("3 - Rotate the robot clockwise");
       attachLeftMotorServo();
       attachRightMotorServo();
       turnRight(20);
    }
    else if((char)in == '4'){
       Serial.print("4 - Rotate the robot counter clockwise");
       attachLeftMotorServo();
       attachRightMotorServo();
       turnLeft(20);
    }
    else if((char)in == '5'){
      Serial.print("5 - Read the distance to the nearest object");
      
    }
    else if((char)in == '6'){
      Serial.print("6 - Read temperature values");
      displayTemperature(readTemp());

    }
    else if((char)in == '6'){
      Serial.print("7 - Quit");
      stopMovement();
    }
    else{
      Serial.print("Invalid Operation: "+ (char)in);
      
    }
 }
 
 delay(1);
}
