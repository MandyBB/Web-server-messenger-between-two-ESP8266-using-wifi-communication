# Web-server-messenger-between-two-ESP8266-using-wifi-communication
This is a project to do a messaging web page where it is possible the communication between two Web servers through a WiFi communication using two ESP8266.The objective of this project is to learn how works the WiFi protocol at an ESP8266 and work at different types of WiFi communication.

## Contents
- [Introduction](#Introduction)
- [Tutorials](#Tutorials)
- [WiFi communication between two ESP8266](#WiFi-communication-between-two-ESP8266)
- [Web Server with ESP8266](#Web-Server-with-ESP8266)
- [Main Project](#Main-Project)
- [The code](#The-code)
- [Variables and Libraries](#Variables-and-Libraries)
- [Functions](#Functions)
- [Setup](#Setup)
- [Loop](#Loop)
- [Tests, problems and solutions](#Tests,-problems-and-solutions)
- [1st Simulation](#1st-Simulation)
- [2nd Simulation](#2nd-Simulation)
- [Solution](#Solution)
- [Conclusion](#Conclusion)

## Introduction
  This is a project to do a messaging web page where it is possible the communication between two Web pages through two WiFi communications using two ESP8266.The objective of this project is to learn how works the WiFi protocol at an ESP8266 and work at different types of WiFi communication.

![Pin Functions](Images.md/figura1.png)

Figure 1. Block schema from the project.

  The project messaging flow has to go from the the web page created by the Webserver of one ESP8266 to the other ESP8266 web page as seen at the figure 1. So it is necessary a WiFi communication between the both ESP8266 and a Webserver, to each ESP8266, to create a HTML that forms a web page and respond a request from the client. As we can see at the figure 2, where it shows the message flow (the arrows in red), the messages have to flow through Web pages and ESP8266s.
  To do it, this project was divided in two main sections, the WiFi communication between the two ESP8266 and the creation of two Web servers that communicate with the ESP8266s by WiFi.
  The materials used for this project are two ESP8266, two USB cables and two computers with Arduino Software IDE installed.
  
  ![Pin Functions](Materials.jpg)

Figure 3. Material.

## Tutorials
  For the development of the project we use four different tutorials. One for the creation of the WiFi communication between the two ESP8266 and others two combining for the creation of the Web Servers.

### WiFi communication between two ESP8266
  For our main project the Wi-Fi communication between two ESP8266 is one of the two big parts, so we searched for a tutorial that explained how to create this communication. The tutorial chosen is called “UDP Android ESP” that can be found in the github link: https://github.com/gowgear/UDP-Android-ESP .
  The reason for the selection of this tutorial is that this gitHub project was made at the Service d'électronique et de Microélectronique of UMONS, meaning that we could have contact with the owner of this project. Also, it was selected because it is very similar to what we will use in this project and the coding was very simple and clear to understand.
  The first time we runned the program it did not work. The two ESP8266 did not connect to each other. Because we didn’t know what was the problem, we asked the creator of the project of the tutorial for help. He said that the problem was on the setup of the client.
  Since the original project uses an Android client it wasn’t clear that the ESP8266 client has different setup then the server in the programming with the IDE and must be settled different. So, from this point on, we had two codes, one for the server and one for the client. And the server sent fixed message through the channel were the client would listen and show at its serial plot.
  Once we did this, the next step was to make the message, that was sent until now with a fixed char data type (char  ReplyBuffer[] = "Hardware & Software Labs"), to be written in the serial plot, simulating the client writing something from an external window. To do it so, it was used the serial plot.
  The last step was sending the message in both directions in real time, since the tutorial only sent messages in both ways only during the setup and this part wasn’t working. In conclusion, adapting the tutorial we created a communication ping pong.
With the intention of sharing our changes to others, which may be useful to someone else, we've created a GitHub for this part only. Here is the link: “https://github.com/MandyBB/Wifi-Communication-with-two-ESP8266”. On this GitHub there is the codes and a demo video.

### Web Server with ESP8266
  The other part of the project was the creation of a webserver with the ESP8266 to process incoming network requests of a client over an HTML from a Web page. Creating the interface of the messenger where the user can work on.
  For the creation of this part it has been used three tutorials. With the first tutorial, called “ESP8266 Web Server with HTML Web Page”, that can be fount at the link https://circuits4you.com/2016/12/16/esp8266-web-server-html/, we learned how to create with an ESP8266 a web server with HTML web page. In this tutorial,  the ESP8266 connects to a WiFi Network that provides internet and sends a simple text to the web page.
  At this same tutorial, it was possible to find some examples and other tutorials related to the content. One of them was used too to this project. The tutorial “ESP8266 Arduino WiFi Web Server LED on off control”, that can be checked at the link https://circuits4you.com/2018/02/05/esp8266-arduino-wifi-web-server-led-on-off-control/, was used to create the answer part of the project. This tutorial taught us how to implement a button to check some message in a window without refreshing the page.
  The last tutorial, called “ESP8266 First Web Server” from the link https://tttapa.github.io/ESP8266/Chap10%20-%20Simple%20Web%20Server.html, we learned how to use the web server to serve interactive pages, and to use POST and GET request. This was the base to create the part for our user writing and sending a message.
  All of this tutorial were tested and worked perfectly, so the next step was using this three as models for the WebServer that would be used at the main project. We started with the third tutorial to create the Web Server and to send the message. With that, it was possible to store the message created by the User. The second thing we did was using the second tutorial to show a message without reloading the page by pressing a button. And to finish, we unite both parts to create a Web page where a user sends a message pressing the button to send and sees this message on the button to see answers. 
The main changes done for this project can be seen at the list below:
- Created the variable MAIN_page where is stored our HTML page in an array of characters. Here we changed the format of the web page from the second tutorial. We added a Text Box where you can write the word desired for sending, one button (submit called “Login”) for sending the word, one button to see the message received and one frame where the word sending is printed. The last two vinculated to a target (“myIframe”).
- After that, was the time to change the receiving and sending aspects of the tutorial. For this part, not much was changed, but we connected the variables of the message that was sended with the message that was received. This part was more about understanding how the GET and POST functions of the WebServer worked, how to handle with them and also how the iframe worked. In the tutorial, the ESP8266 hosts a web page with a button. When the button is pressed, the browser sends a POST request to /LED. For our case. We have used the POST for catch the writing value in the TextBox and in the handleInComeMSG (associated to the webpage by "/login") we convert the string to a char, due to the fact that in the serial port we only can transmit char values. (See it better in the code).
  With the intention of sharing our changes and being useful for other people we also have created another GitHub only for this part. The link is below. On the GitHub there is also a video of the demonstration.

https://github.com/josehp22/Webserver-with-ESP8266

  Once we have these two big parts created, we can put them together and create our project.

## Main Project
  The main project, like said at the introduction, is a messenger between 2 ESP8266 based on a wifi communication and a web server software. So, once we have the two parts done, we have to join them together.
  Since both parts works with the Wi-Fi system from their ESP8266 and the ESP8266 works only with one channel per time, it is important to turn on/off the Wi-Fi channel every single time it is used. To do it so, we elaborated a sequence of events that the both ESP8266 should follow.

[1] - Turn on Wi-Fi communication as Server
      Wait for msg
[2] - Turn on WebServer
      Wait for msgWB from WebServer
       
if (msgWS arrives):
	[2] - Stores the msgWS in msg
		       Turn off WebServer
    	   Turn on Wi-Fi Communication as Client
    	   Send msg to [1]
	[1] - Listen msg
 	      Send ConfMsg for confirmation of received msg to [2]
	[2] - Receives ConfMsg;
 	      Stop sending msg;
 	      Turn off Wi-Fi Communication as Client;
	[1] - Turn off Wi-Fi communication as server;
 	      Turn on WebServer;
  	     Send msg to WebServer;
	[2] - Turn on Wi-Fi Communication as Server;
  	     Wait for msg;
	[2] = [1] and [1]=[2];
	return;

  So, as it is possible to see at the figure 7, there has 2 ESP8266 with different codes, but both must have all the functions as initializations for clients and server, which was showed to have a lot of problem in the union of the codes. So, it was created another resolution for the unique Wi-Fi channel which is shown at figure 8. In this resolution, the Server ESP8266 is always the Wi-Fi communication server and the Client ESP8266 will always be the Wi-Fi communication client.


### The code
#### Variables and Libraries
#### Functions
#### Setup
#### Loop
### Tests, problems and solutions
#### 1st Simulation
#### 2nd Simulation
#### Solution
## Conclusion



