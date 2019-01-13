/*
 * HomieBME280Node.cpp
 *
 *  Created on: 12.01.2019
 *      Author: ian
 */

#include <HomieBME280Node.h>

HomieBME280Node::HomieBME280Node():
	HomieNode("bme280", "BME280 Sensor", "sensor_t_h_p"),
	curPres(NAN), curTemp(NAN), curHum(NAN)
{
	advertise("temperature").setName("Temperatur").setDatatype("float").setUnit("°C");
	advertise("pressure").setName("Luftdruck").setDatatype("float").setUnit("hPa");
	advertise("humidity").setName("Luftfeuchtigkeit").setDatatype("float").setUnit("%");
}

void HomieBME280Node::setup() {
	sensor.settings.commInterface = I2C_MODE;
	sensor.settings.I2CAddress = 0x76;

	//  0, Sleep mode
		//  1 or 2, Forced mode
		//  3, Normal mode
		sensor.settings.runMode = 3; //Forced mode

		//tStandby can be:
		//  0, 0.5ms
		//  1, 62.5ms
		//  2, 125ms
		//  3, 250ms
		//  4, 500ms
		//  5, 1000ms
		//  6, 10ms
		//  7, 20ms
		sensor.settings.tStandby = 0;

		//filter can be off or number of FIR coefficients to use:
		//  0, filter off
		//  1, coefficients = 2
		//  2, coefficients = 4
		//  3, coefficients = 8
		//  4, coefficients = 16
		sensor.settings.filter = 0;

		//tempOverSample can be:
		//  0, skipped
		//  1 through 5, oversampling *1, *2, *4, *8, *16 respectively
		sensor.settings.tempOverSample = 1;

		//pressOverSample can be:
		//  0, skipped
		//  1 through 5, oversampling *1, *2, *4, *8, *16 respectively
	    sensor.settings.pressOverSample = 1;

		//humidOverSample can be:
		//  0, skipped
		//  1 through 5, oversampling *1, *2, *4, *8, *16 respectively
		sensor.settings.humidOverSample = 1;
		Wire.begin(SDA, SCL);
		Serial.println(sensor.begin(), HEX);
}

void HomieBME280Node::loop() {
	static uint32_t nextRead = 0;
	uint32_t now = millis();
	if (now > nextRead) {
		nextRead = now + 60000;
		curTemp = sensor.readTempC();
		curPres = sensor.readFloatPressure();
		curHum =  sensor.readFloatHumidity();
		Serial.printf("Read values:\n\tPressure: %f mbar\n\tTemperatur: %f °C\n\tHumidity:%f relH\n", curPres, curTemp, curHum);
		setProperty("temperature").send(String(curTemp));
		setProperty("pressure").send(String(curPres/100));
		setProperty("humidity").send(String(curHum));
	}
}

