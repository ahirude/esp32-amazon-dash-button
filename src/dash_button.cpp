#include <WiFi.h>
#include <HTTPClient.h>

#include "project.h"

void DashButtonWiFi_setup() {
  WiFi.disconnect();
  WiFi.mode(WIFI_MODE_STA);
}

String DashButtonWiFi_loop() {
  HTTPClient http;
  String deviceId = "";

  WiFi.begin(AMAZON_SSID);
  while (WiFi.status() != WL_CONNECTED)  delay(1000); // looking for Button's WiFi

  Serial.println("WiFi connected.");
  delay(2000);  // without this delay, http.get may fail.

  http.addHeader("Content-Type", "text/html");

  http.begin(AMAZON_URL1);
  int rescode = http.GET();
  Serial.println(rescode);

  if (rescode == 200) {
    String page = http.getString();
    int pos = page.indexOf("name=\"amzn_devid\"");
    Serial.println(pos);
    if (pos != -1)  deviceId = page.substring(pos + 25, pos + 25 + 16);  // G123QC1234567890 - 16chars
    http.begin(AMAZON_URL2);  // access to force the button shutdown
    http.GET();
  }
  http.end();
  WiFi.disconnect(true);
  while (WiFi.status() == WL_CONNECTED) delay(500); // make sure of disconnect

  Serial.println("exit");
  return deviceId;
}
