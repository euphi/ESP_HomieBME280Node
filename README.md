# ESP_HomieBME280Node [![Build Status](https://travis-ci.org/fablabnbg/ESP_HomieBME280Node.svg?branch=master)](https://travis-ci.org/fablabnbg/ESP_HomieBME280Node)

Node for Homie-ESP8266 (3.0+)  to connect a BME280 sensor

## Features

* Based on Sparkfun BME280 library
* Builds with platformio
* advertises MQTT topics according to specification

## Build instructions

* to be built with platformio:
* If you don't have platformio installed, see https://platformio.org/platformio-ide for installation instructions.

### As own application:

Copy `examples/simplenode.cpp` to `src/`

Type

`platformio run`

### As library:

Create your own project with platformio  and add "ESP_HomieBME280Node" to the `lib_deps=` line in `platformio.ini`

### As library without platformio:

Why do you even want to do this?

(However, just copy the HomieBME280Node.cpp and HomieBME280Node.h to your sources/includes and use your own build system).


## Dependencies

**All dependencies are installed automatically by platformio**

* Sparkfun BME280 - libarary to read out BME280 sensors
* homie-ESP8266  - ESP8266 implementation of Homie convention
   homie-esp8266 is currently loaded from fork/branch due to support of convention v3.0.1

## Programm Logic

* `setup()`: initializes the sensor and advertises the homie nodes
* `loop()`: read sensor values every minute and publish them on MQTT

## Outlook

* Support BMP280 (just leave out humidity)
* Support loading of calibration values
* Support setting reading interval 
* Send also calculated values like sea level pressure or dew point.
* Fork Sparkfun BME280 library to remove unecessary code (e.g. SPI interface)

