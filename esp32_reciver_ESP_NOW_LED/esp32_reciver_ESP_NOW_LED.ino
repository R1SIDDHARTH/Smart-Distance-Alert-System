#include <esp_now.h>
#include <WiFi.h>

#define LED_PIN 2  // Built-in LED pin for ESP32

int receivedData = 0;  // Removed volatile keyword

// Updated callback function signature to match new ESP-NOW API
void onDataRecv(const esp_now_recv_info_t *esp_now_info, const uint8_t *data, int len) {
  int tempData;
  memcpy(&tempData, data, sizeof(tempData));
  receivedData = tempData;  // Safe assignment
  
  Serial.print("Data received: ");
  Serial.println(receivedData);
  
  // Control LED based on distance threshold
  if (receivedData < 10) {
    digitalWrite(LED_PIN, HIGH);  // Turn ON LED
    Serial.println("LED ON");
  } else {
    digitalWrite(LED_PIN, LOW);   // Turn OFF LED
    Serial.println("LED OFF");
  }
}

void setup() {
  Serial.begin(115200);
  
  // Initialize LED pin
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);  // Initially OFF
  
  // Initialize ESP-NOW
  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW initialization failed");
    return;
  }
  
  esp_now_register_recv_cb(onDataRecv);
  Serial.println("ESP-NOW Initialized Successfully");
}

void loop() {
  // Just keep the ESP-NOW connection alive
  delay(10);
}
