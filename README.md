# Smart-Chop-Saw-Safety-System-ESP32-Arduino-IoT-Cloud-

This project turns a standard chop saw into a smart, safety-enhanced machine using an ESP32, an HC-SR04 ultrasonic sensor, and a servo-based emergency brake.
It’s fully connected to the Arduino IoT Cloud, allowing you to start/stop the saw remotely and trigger an emergency stop from a dashboard.

<img width="531" height="664" alt="Στιγμιότυπο οθόνης 2025-11-03 011610" src="https://github.com/user-attachments/assets/4d742e82-98da-43e8-8f93-6274cf2652b6" />

If the sensor detects a hand or object closer than 3 cm, the saw automatically shuts down and activates a servo brake to immobilize the blade,then releases it after a short delay.

![1000005483](https://github.com/user-attachments/assets/f8730118-a404-4efb-add5-570a8b56eb43)

The entire operation of the chop saw can be fully managed through the Arduino IoT Cloud, making it very easy to monitor and control from any computer or smartphone.
Using the IoT dashboard, the user can:

Turn the saw ON or OFF remotely,

Activate the emergency brake with a single tap

<img width="876" height="337" alt="Στιγμιότυπο οθόνης 2025-11-03 002257" src="https://github.com/user-attachments/assets/c2e02632-c328-4fd9-b402-89e6a1542be7" />

