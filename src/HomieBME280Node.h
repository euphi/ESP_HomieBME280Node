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

class HomieBME280Node: public HomieNode {
public:
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

	//virtual void onReadyToOperate() override;
	//virtual bool handleInput(const HomieRange& range, const String  &property, const String &value) override;


private:
	static HomieSetting<double> heightAboveSealevel;

	BME280 sensor;
	float curPres;
	float curTemp;
	float curHum;
};

#endif /* SRC_HOMIEBME280NODE_H_ */
