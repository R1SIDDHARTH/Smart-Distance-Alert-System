# ESP32 with ESP-NOW  PROTOCOL and Blynk IOT APP

## 📊 Overview
This project demonstrates the use of two ESP32 boards for seamless communication using **ESP-NOW** protocol. The first ESP32 (Sender) collects data from an ultrasonic sensor, and the second ESP32 (Receiver) processes the data. The Receiver controls an LED based on the received data and optionally visualizes the data on the **Blynk IoT Cloud**.

---

## 🌟 Features
- **ESP-NOW Communication**: Peer-to-peer data transfer between ESP32 boards.
- **Ultrasonic Sensor Integration**: Measures distance and transmits it to the Receiver ESP32.
- **LED Control**: Turns ON/OFF based on distance thresholds.
- **Blynk IoT Integration** *(optional)*: Displays data on the Blynk IoT dashboard.

---

## 🚀 Technologies Used
- **ESP-NOW Protocol**: For efficient communication.
- **Ultrasonic Sensor**: Distance measurement.
- **Wi-Fi**: Optional, for Blynk integration.
- **Blynk IoT**: Real-time data visualization.

---

## 📂 File Structure
```bash
├── sender.ino             # Sender ESP32 code
├── receiver.ino           # Receiver ESP32 code
├── README.md              # Project documentation
```

---

## 📋 Requirements
- **ESP32 Boards** (2 units)
- **Ultrasonic Sensor** (e.g., HC-SR04)
- **LED** (optional)
- **Jumper Wires**

---

## 📊 System Architecture

### Overview Diagram
![System Architecture](https://example.com/system-architecture.png)

1. **Sender ESP32**:
   - Reads distance data from the ultrasonic sensor.
   - Transmits data via ESP-NOW.

2. **Receiver ESP32**:
   - Receives distance data.
   - Controls an LED based on the distance.
   - Optionally forwards data to Blynk IoT.

---

## 📚 Setup Instructions

### **1. Get ESP32 MAC Address**
Upload the following code to both ESP32 boards to retrieve their MAC addresses:

```cpp
#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  Serial.print("ESP32 MAC Address: ");
  Serial.println(WiFi.macAddress());
}

void loop() {}
```

### **2. Hardware Connections**
#### Sender ESP32:
- **Ultrasonic Sensor**:
  - VCC -> 5V
  - GND -> GND
  - TRIG -> GPIO 5
  - ECHO -> GPIO 18

#### Receiver ESP32:
- **LED**:
  - Anode -> GPIO 2 (via a resistor)
  - Cathode -> GND

### **3. Software Setup**
#### Clone Repository
```bash
git clone https://github.com/your-username/esp-now-blynk-integration.git
cd esp-now-blynk-integration
```

#### Install Dependencies
Ensure you have the ESP32 board library installed in your Arduino IDE. Add required libraries for Blynk if using IoT integration.

---

## 🛠️ How to Use

1. **Sender ESP32**:
   - Upload `sender.ino` to the Sender ESP32.
   - Set the Receiver's MAC address in the code.

2. **Receiver ESP32**:
   - Upload `receiver.ino` to the Receiver ESP32.
   - Connect to Wi-Fi if using Blynk.

3. **Visualize Data**:
   - Open the Serial Monitor to view distance readings and LED status.
   - If Blynk is enabled, check the Blynk IoT dashboard for real-time updates.

---

## 📊 Visuals

### 📷 Hardware Setup
![Hardware Setup](https://example.com/hardware-setup.png)

### 📊 Blynk Dashboard
![Blynk Dashboard](https://example.com/blynk-dashboard.png)

---

## 🤖 Future Enhancements
- Add more sensors for additional functionality.
- Enable real-time updates using MQTT for larger IoT setups.
- Improve energy efficiency with sleep modes.

---

## 🌟 Contributors
- **Siddharth R**  
  📧 Contact: siddharth.r.college@gmail.com

---

