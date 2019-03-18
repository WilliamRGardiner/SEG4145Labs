#ifndef INTR_WIFI
#define INTR_WIFI

#include "intr_wifi.h"

#define SONAR_SENSOR_PIN 22

void intrWifiSetup();

bool INTR_WIFI_SETUP = false;

WIFI_PROFILE wireless_prof = {
 /* SSID */ "stingray",
 /* WPA/WPA2 passphrase */ "12345678",
 /* Robot IP address */ "192.168.1.141",
 /* subnet mask */ "255.255.255.0",
 /* Gateway IP */ "192.168.1.1", };
 
String remote_server = "192.168.1.177"; // peer device IP address.

String remote_port = "4242"; // arbitrary 

//Creates a client that can connect to a specified internet IP address and port number
WifiClient client(remote_server, remote_port, PROTO_TCP);

void intrWifiSetup() {
  if(!INTR_WIFI_SETUP) {
     
     Serial.println("Starting Wifi...");
     
     // connect to AP
     Wireless.begin(&wireless_prof);
    
    //Serial.println("client.connect() = "+ client.connect());
    // if you get a connection, report back via serial. client.connect() connect to the IP address and port specified earlier. It returns true if the connection succeeds, false if not.
    if (client.connect()) {
      Serial.println("connected"); // prints to serial monitor. Check the Serial Monitor Section at the end of  this manual.
      // Send message over UDP socket to peer device
      client.println("Robot10"); //Your own message
    }
    else {
      // if connection setup failed:
      Serial.println("failed");
    } 
   
    INTR_WIFI_SETUP = true;   
  }
}

#endif
