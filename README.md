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
## Tutorials
### WiFi communication between two ESP8266
### Web Server with ESP8266
## Main Project
## The code
## Variables and Libraries
## Functions
## Setup
## Loop
## Tests, problems and solutions
## 1st Simulation
## 2nd Simulation
## Solution
## Conclusion


## Development Status
Most of the framework is implemented. Most noticable is the missing analogWrite. While analogWrite is on it's way, there are a few other options that you can use:
- 16 channels [LEDC](cores/esp32/esp32-hal-ledc.h) which is PWM
- 8 channels [SigmaDelta](cores/esp32/esp32-hal-sigmadelta.h) which uses SigmaDelta modulation
- 2 channels [DAC](cores/esp32/esp32-hal-dac.h) which gives real analog output

## Installation Instructions

- Using Arduino IDE
  + [Instructions for Windows](docs/arduino-ide/windows.md)
  + [Instructions for Mac](docs/arduino-ide/mac.md)
  + [Instructions for Debian/Ubuntu Linux](docs/arduino-ide/debian_ubuntu.md)
  + [Instructions for Fedora](docs/arduino-ide/fedora.md)
  + [Instructions for openSUSE](docs/arduino-ide/opensuse.md)
- [Using PlatformIO](docs/platformio.md)
- [Building with make](docs/make.md)
- [Using as ESP-IDF component](docs/esp-idf_component.md)

#### Decoding exceptions

You can use [EspExceptionDecoder](https://github.com/me-no-dev/EspExceptionDecoder) to get meaningful call trace.

#### Issue/Bug report template
Before reporting an issue, make sure you've searched for similar one that was already created. Also make sure to go through all the issues labelled as [for reference](https://github.com/espressif/arduino-esp32/issues?utf8=%E2%9C%93&q=is%3Aissue%20label%3A%22for%20reference%22%20).

Finally, if you're sure no one else had the issue, follow the [ISSUE_TEMPLATE](docs/ISSUE_TEMPLATE.md) while reporting any issue.


## ESP32Dev Board PINMAP

![Pin Functions](docs/esp32_pinmap.png)

## Hint

Sometimes to program ESP32 via serial you must keep GPIO0 LOW during the programming process
