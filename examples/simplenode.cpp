#include <Homie.hpp>
//#include <LoggerNode.h>

#include <Wire.h>
#include <HomieBME280Node.h>

#define FW_NAME "SimpleBME280Node"
#define FW_MAJOR "0"
#define COMMIT_COUNTER "1"
#define BUILD_NUMBER "1"

#define FW_VERSION FW_MAJOR "." COMMIT_COUNTER "." BUILD_NUMBER

//LoggerNode LN;
HomieBME280Node sensorNode;
//

void setup() {
  Homie_setFirmware(FW_NAME, FW_VERSION);
  Serial.begin(74880);  // Baudrate of ESP8266 Boot loader. Set it here to same value, so you can see both the boot loader's messages and your's.
  Serial.println("Start");
  Serial.flush();
  Homie.disableLedFeedback();
  Homie.disableResetTrigger();
  Homie.setLoggingPrinter(&Serial);

  Homie.setup();
  Wire.begin(SDA, SCL);

}


void loop() {
  Homie.loop();
}


