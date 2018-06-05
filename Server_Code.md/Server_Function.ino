//////////////// Setup of Wifi Access Point
void setupWIFI() {
  Serial.print("Setup Wifi Communication on ");
  Serial.println("");
  WiFi.softAPdisconnect(true); //Disconnect stations from the network established by the soft-AP. It is set to true, so it will switch the soft-AP mode off.
  WiFi.disconnect(true); //Disconnects the WiFi shield from the current network.
  WiFi.softAPConfig(local, remote, netmask); // Configure the soft access point’s network interface. Syntax: softAPConfig (local_ip, gateway, subnet)
  WiFi.mode(WIFI_AP); // mode Access Point
  WiFi.softAP("MyWiFi"); // Set up a soft access point (MyWiFi) to establish a Wi-Fi network.
  WiFi.begin();

  Udp.begin(UDPPort); //listening to the port UDPPort   
}

//////////////// SENDING MESSAGES
void SendingMensage(){
  Udp.beginPacket(remote, UDPPort); // Starts the connection to write UDP data to the remote connection. Syntax: UDP.beginPacket(remoteIP, remotePort); 
  Udp.write(buf); // Writes UDP data to the remote connection. Must be wrapped between beginPacket() and endPacket(). Syntax: UDP.write(message); message: the outgoing message (char).
  Udp.endPacket();
  var=3;
}

//////////////// RECEIVING MESSAGES
void ReceivingMensage (){
  
  int packetSize1 = Udp.parsePacket(); // Checks for the presence of a UDP packet, and reports the size.

  // receive incoming UDP packets
  if (packetSize1) { //if the packet was received then:
    
    int len = Udp.read(packetBuffer, 255); // Udp.read() Reads UDP data from the specified buffer. If no arguments are given, it will return the next character in the buffer.      
    if (len > 0) { // if the size is bigger then 0 then:
      packetBuffer[len] = 0; //at the end of the packetBuffer it puts a 0. This is needed to identify the end of the packet for the Serial.printf().
      Serial.printf("Resp: %s\n", packetBuffer);
      var=1;
    }
  }
}


//===============================================================
// This routine is executed when you open the web server
//===============================================================
void handleRoot() {
  Serial.println("You called root page");
  String s = MAIN_page; //Read HTML contents
  server.send(200, "text/html", s); //Send web page
}
 
void handleLMsg() { 
  server.send(200, "text/html", packetBuffer); //Send ADC value only to client ajax request
}

void handleInComeMSG() {              // If a POST request is made to URI /login
  Serial.println(server.arg("Message"));
  String HPmsg = server.arg("Message");
  lenWebServer = HPmsg.length();
  HPmsg.toCharArray(buf, lenWebServer+1);
  server.send(200, "text/html", MAIN_page);
  msgWS=2;
}

void setupWebServer(){
 Serial.print("Setup Web Server on ");
 Serial.println("");
  WiFi.softAPdisconnect(true); //Disconnect stations from the network established by the soft-AP. It is set to true, so it will switch the soft-AP mode off.
  WiFi.disconnect(true); //Disconnects the WiFi shield from the current network.
  
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");
 
  while (WiFi.status() != WL_CONNECTED) { // Wait for connection
    delay(500);
    Serial.print(".");
  }
 
  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
 
  server.on("/",HTTP_GET, handleRoot);      //Which routine to handle at root location. This is display page
  server.on("/login", HTTP_POST, handleInComeMSG);
  server.on("/msg", handleLMsg);
  server.begin();                  //Start server
  
  Serial.println("HTTP server started");
}

