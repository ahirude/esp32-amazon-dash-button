#include <Arduino.h>
#include "project.h"

void setup() {
  Serial.begin(115200);

  DashButtonWiFi_setup();
}

void loop() {
  String deviceId = DashButtonWiFi_loop();
  Serial.println(deviceId);   // GnnnQCnnnnnnnnnn  n=0..9
}
