#include <ESP32Servo.h>

#define DO_PIN 13  // ESP32's pin GPIO13 connected to DO pin of the flame sensor
#define SERVO_PIN 8

Servo servo1;

void setup() {
  // initialize serial communication
  Serial.begin(115200);
  // initialize the ESP32's pin as an input
  pinMode(DO_PIN, INPUT);
  servo1.attach(SERVO_PIN);
  servo1.write(0); // posisi awal (pintu tertutup)
  delay(1000);

  Serial.println("Sistem Deteksi Kebakaran Siap...");
}

void loop() {
  int flame_state = digitalRead(DO_PIN);
  //High = Tidak ada api, Low = Ada api
    // ====== LOGIC ======
  if (flame_state == LOW) {
    Serial.println("Aman. Pintu tertutup.");
    servo1.write(0); // tutup pintu

  } else {
    Serial.println("🔥 KEBAKARAN TERDETEKSI! Pintu terbuka!");
    servo1.write(90); // buka pintu
  }

  Serial.println("----------------------");
  delay(2000);
}