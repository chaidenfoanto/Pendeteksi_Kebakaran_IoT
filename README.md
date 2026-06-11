# Fire Detector IoT

An embedded IoT system built as a group assignment for an Internet of Things course. The system detects fire using a flame sensor and automatically opens an emergency door via a servo motor, allowing evacuation without manual intervention. Built with an ESP32-S3-Wroom microcontroller.

![Circuit Image](https://github.com/chaidenfoanto/Pendeteksi_Kebakaran_IoT/blob/main/circuit_image.png)

---

## Team

- Chaiden Richardo Foanto
- Levin Dawson Wisan
- Apryadi Dwi Putra Tangalayuk
- Franklin Jaya

---

## How It Works

The flame sensor outputs a digital signal that is read by the ESP32 every 2 seconds.

- flame_state LOW → no fire → servo stays at 0 degrees (door closed)
- flame_state HIGH → fire detected → servo rotates to 90 degrees (door opens)

All state changes are logged to the Serial Monitor at 115200 baud for monitoring and debugging.

---

## Hardware

| Component | Details |
|-----------|---------|
| Microcontroller | ESP32-S3-Wroom-1 |
| Flame Sensor | Digital output (DO), connected to GPIO13 |
| Servo Motor | MG90S, connected to GPIO8 |
| Power Supply | MB102 breadboard power supply |

The MB102 power supply provides dedicated power to the servo and flame sensor through the breadboard power rails. This prevents the onboard ESP32 voltage regulator from being overloaded when driving the servo.

---

## Pin Mapping

| Component | Pin | Connected To |
|-----------|-----|--------------|
| Flame Sensor VCC | - | MB102 3.3V rail |
| Flame Sensor GND | - | MB102 GND rail |
| Flame Sensor DO | GPIO13 | ESP32-S3 |
| Servo +5V | - | MB102 5V rail |
| Servo GND | - | MB102 GND rail |
| Servo PWM | GPIO8 | ESP32-S3 |
| ESP32-S3 GND | - | MB102 GND rail |

---

## Tech Stack

- Platform: ESP32-S3-Wroom-1
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

## Troubleshooting Notes

During development the team ran into three issues worth documenting.

**Inverted sensor logic**
The flame sensor's digital output behaves opposite to what most people expect. HIGH means fire is detected, LOW means no fire. This caused incorrect system behavior early on until the branch logic in the code was adjusted to match the actual sensor characteristics.

**Servo instability without delay**
Without adequate delay in the loop, the servo did not have enough time to complete its movement before the next read cycle. Adding a 2000ms delay between readings resolved this and made servo movement stable and predictable.

**Analog output inconsistency**
The team initially tested both the digital output (DO) and analog output (AO) of the flame sensor. The analog output produced inconsistent readings and made calibration difficult, so the team decided to use only the digital output, which was more stable and sufficient for this use case.

---

## What We Learned

This project gave us hands-on experience with hardware-software integration and the kind of debugging that only becomes obvious when you test on real components. The inverted sensor logic and servo timing issues were not visible in the circuit diagram or simulation, and only surfaced during actual testing. It reinforced how much real embedded development depends on understanding the behavior of each component, not just how they connect.
