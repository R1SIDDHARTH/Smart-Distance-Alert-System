#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  delay(1000); // Give serial connection time to start

  // Initialize WiFi
  WiFi.mode(WIFI_MODE_STA);
  delay(100); // Give WiFi time to initialize
  
  // Print MAC Address
  Serial.println();
  Serial.println("ESP32 WiFi MAC Address:");
  Serial.println(WiFi.macAddress());
}

void loop() {
  // Nothing to do here
  delay(1000);
}
