/*
 * HomieBME280Node.h
 *
 *  Created on: 12.01.2019
 *      Author: ian
 */

#ifndef SRC_HOMIEBME280NODE_H_
#define SRC_HOMIEBME280NODE_H_

#include "HomieNode.hpp"
#include "SparkFunBME280.h"
#include <functional>

class HomieBME280Node: public HomieNode {
public:
    typedef std::function<bool(float temp, float hrel, float pressure)> EnvDataChangedCallback;
	HomieBME280Node();
	virtual void setup() override;
	virtual void loop() override;

	float getRelHum() const {
		return curHum;
	}

	float getPress() const {
		return curPres;
	}

	float getTemp() const {
		return curTemp;
	}

	void setEnvDataCallback(const EnvDataChangedCallback &callback) {
		this->callback = callback;
	}



	//virtual void onReadyToOperate() override;
	//virtual bool handleInput(const HomieRange& range, const String  &property, const String &value) override;


private:
	static HomieSetting<double> heightAboveSealevel;
	BME280 sensor;
	float curPres;
	float curTemp;
	float curHum;
	EnvDataChangedCallback callback;

};

#endif /* SRC_HOMIEBME280NODE_H_ */
