#include <esp_now.h>
#include <WiFi.h>

// MAC address of ESP32 (2)
uint8_t receiverMAC[] = {0x8C, 0x4F, 0x00, 0x27, 0xAA, 0x98};

// Ultrasonic Sensor Pins
const int TRIGGER_PIN = 5;  // GPIO5
const int ECHO_PIN = 18;    // GPIO18

// Constants for ultrasonic sensor
const float SOUND_SPEED = 0.034;  // Speed of sound in cm/microsecond

void setup() {
  Serial.begin(115200);
  
  // Initialize ultrasonic sensor pins
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  // Initialize WiFi in Station mode
  WiFi.mode(WIFI_STA);
  
  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW initialization failed");
    return;
  }
  
  esp_now_peer_info_t peerInfo;
  memcpy(peerInfo.peer_addr, receiverMAC, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
}

void loop() {
  int distance = readUltrasonicSensor();
  esp_now_send(receiverMAC, (uint8_t *)&distance, sizeof(distance));
  Serial.println("Distance: " + String(distance) + " cm");
  Serial.println("Data sent!");
  delay(1000);
}

int readUltrasonicSensor() {
  // Clear the trigger pin
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  
  // Set the trigger pin HIGH for 10 microseconds
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  // Read the echo pin
  long duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculate the distance
  float distance = duration * SOUND_SPEED / 2;
  
  return (int)distance;
}
