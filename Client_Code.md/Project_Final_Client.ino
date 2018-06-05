/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generated  with TUNIOT FOR ESP8266 Website: Easycoding.tn                                           //
// Found in https://github.com/gowgear/UDP-Android-ESP                                                 //
// And also with the help of Arduino Forum found in:                                                   //
// https://forum.arduino.cc/index.php?topic=6666.0                                                     //
//                                                                                                     //
// Adaptation of Borges. A. & Huertas. J.                                                              //
/////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                TALKING CLIENT                                                       //
/////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>


//------------------------------------------------------------------------------------------------------
// Wifi-Communication data
unsigned int UDPPort = 2380; // local port to listen on
char packetBuffer[255]; //buffer to hold incoming packet

String readStrings;
char MsgSending;
char readchars;
char PackageSended[255];
unsigned int len;

WiFiUDP Udp;

// Ip configuration
const IPAddress local(11, 11, 11, 11); // ip: the IP address of the device.
const IPAddress dns(11, 11, 11, 11); // dns: the address for a DNS server.
const IPAddress netmask(255, 255, 255, 0); // subnet mask
const IPAddress remote(11,11,11,11); // gateway IP address
//------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------
// Web_Page data
char buf[255];
unsigned int lenWebServer;
 
//---------------------------------------------------------------
//HTML webpage contents in program memory
const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
<center>
<h1>WiFi Receive message</h1>
</center>
</head>
<body>
<form action="/login" method="POST">
<input type="text" name="Message" placeholder="Message to Send"></br>
<input type="submit" value="Submit">
</form>
<p>Click to see <a href="msg" target="myIframe">RESPONSE</a></p>
<p>Received message:<iframe name="myIframe" width="200" height="25" frameBorder="0"></p><br>
<hr>
</body>
</html>
)=====";
//---------------------------------------------------------------

//SSID and Password of your WiFi router
char* ssid = "SEMI_PUBLIC";
char* password = "microelecpub";

//Declare a global object variable from the ESP8266WebServer class.
ESP8266WebServer server(80); //Server on port 80
 
//------------------------------------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                SETUP                                                                //
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(115200); //Number of the serial port
  setupWebServer();       
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                LOOP                                                                 //
/////////////////////////////////////////////////////////////////////////////////////////////////////////
int var=3;
int msgWS=0;
int msgWC=0;


void loop() {
  switch (var) {
    case 1:
      setupWIFI();
      SendingMensage();
      break;
    case 2:
      ReceivingMensage();
      break;
    case 3:
      setupWebServer();
      while (var==3){
          server.handleClient();   //Callback function to monitor the presence of a client and delivers the request of the HTML page
          if (msgWS==2){
            var=1;
            msgWS=0;
          }
      }
      break;     
    default:
      break;
  }
}
