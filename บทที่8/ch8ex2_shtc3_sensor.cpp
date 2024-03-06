#include <Wire.h>
#include "SHTSensor.h“
SHTSensor sht;
void setup() {
  Serial.begin(115200); 
  Wire.begin();
	if (sht.init()) {
		Serial.print("init(): success\n");
	} else {
		Serial.print("init(): failed\n");
	}
  sht.setAccuracy(SHTSensor::SHT_ACCURACY_MEDIUM); 
}
void loop() {
	sht.readSample();
	Serial.println(sht.getTemperature());
  Serial.println(sht.getHumidity());
	delay(1000);
}

