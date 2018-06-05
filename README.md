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
figure 1. Block schema from the project.

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
## Main Project
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



