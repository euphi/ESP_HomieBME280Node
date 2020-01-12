![GitHub release (latest by date)](https://img.shields.io/github/v/release/fablabnbg/ESP_HomieBME280Node)
[![Build Status](https://travis-ci.org/fablabnbg/ESP_HomieBME280Node.svg?branch=master)](https://travis-ci.org/fablabnbg/ESP_HomieBME280Node)

# ESP_HomieBME280Node  
Node for Homie-ESP8266 (3.0+)  to connect a BME280 sensor

## Features

* Based on Sparkfun BME280 library
* Builds with platformio
* advertises MQTT topics according to Homie specification 3.0.1
* calculates and publishes dew point
* calculates air pressure at sea level

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
** homie-esp8266 is currently loaded from [develop-v3] branch due to support of convention v3.0.1

## Programm Logic

* `setup()`: initializes the sensor and advertises the homie nodes
* `loop()`: reads sensor values every minute and publishes them on MQTT

## Settings

The measured air pressure is automatically converted to the air pressure at sea-level, if a setting `HeightAboveSealevel` is set and valid.

E. g.:

```
        "settings": {
                "HeightAboveSealevel": 318.0
        }
```
  

## Outlook

* Support BMP280 (just leave out humidity)
* Support loading of calibration values
* Support setting reading interval 
* Fork Sparkfun BME280 library to remove unecessary code (e.g. SPI interface)

