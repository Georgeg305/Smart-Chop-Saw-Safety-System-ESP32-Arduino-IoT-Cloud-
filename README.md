# Smart-Chop-Saw-Safety-System-ESP32-Arduino-IoT-Cloud-

This project turns a standard chop saw into a smart, safety-enhanced machine using an ESP32, an HC-SR04 ultrasonic sensor, and a servo-based emergency brake.
It’s fully connected to the Arduino IoT Cloud, allowing you to start/stop the saw remotely and trigger an emergency stop from a dashboard.

<img width="531" height="664" alt="Στιγμιότυπο οθόνης 2025-11-03 011610" src="https://github.com/user-attachments/assets/4d742e82-98da-43e8-8f93-6274cf2652b6" />

If the sensor detects a hand or object closer than 3 cm, the saw automatically shuts down and activates a servo brake to immobilize the blade — then releases it after a short delay.
