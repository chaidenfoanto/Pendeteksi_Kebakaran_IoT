# Fire Detector IoT

An embedded IoT system that detects fire using a flame sensor and automatically opens a door via a servo motor. Built with an ESP32-S3-Wroom microcontroller as a practical exercise in hardware integration and real-time sensor response.

![Circuit Image](https://github.com/chaidenfoanto/Pendeteksi_Kebakaran_IoT/blob/main/circuit_image.png)

---

## How It Works

The flame sensor outputs a digital LOW signal when fire is detected. The ESP32 reads this signal every 2 seconds and responds accordingly.

- No fire detected → servo stays at 0 degrees (door closed)
- Fire detected → servo rotates to 90 degrees (door opens)

All state changes are also logged to the Serial Monitor at 115200 baud for debugging and monitoring.

---

## Hardware

| Component | Details |
|-----------|---------|
| Microcontroller | ESP32-S3-Wroom |
| Flame Sensor | Digital output (DO), connected to GPIO13 |
| Servo Motor | MG90S, connected to GPIO8 |
| Power Supply | MB102 breadboard power supply for servo and sensor |

The MB102 power supply is used to provide dedicated power to the servo and flame sensor so the onboard ESP32 voltage regulator is not overloaded.

---

## Wiring

| Component | ESP32 Pin |
|-----------|-----------|
| Flame Sensor DO | GPIO13 |
| Servo Signal | GPIO8 |
| Servo Power | MB102 5V rail |
| Sensor Power | MB102 3.3V or 5V rail |

---

## Tech Stack

- Platform: ESP32-S3-Wroom
- Language: C++ (Arduino framework)
- Library: ESP32Servo

---

## Setup and Flash

Make sure you have the Arduino IDE installed with ESP32 board support added.

Install the ESP32Servo library via Arduino Library Manager.

Select the correct board and port, then upload Pendeteksi_Kebakaran.ino to your ESP32.

Open Serial Monitor at 115200 baud to see live detection output.

---

## Project Structure

```
Pendeteksi_Kebakaran_IoT/
├── Pendeteksi_Kebakaran.ino    # Main firmware
└── circuit_image.png           # Circuit wiring photo
```

---

## What I Learned

This project introduced me to the basics of embedded systems and hardware-software integration. One practical lesson was understanding why a separate power supply matters when driving components like servos alongside a microcontroller. Relying solely on the ESP32 regulator would have caused voltage drops and unstable behavior, and adding the MB102 solved that cleanly. It was a small but concrete example of how hardware constraints shape design decisions.
