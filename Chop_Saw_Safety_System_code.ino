#include "thingProperties.h"
#include <ESP32Servo.h>

#define MOTOR_PIN 26
#define TRIG_PIN 5
#define ECHO_PIN 34
#define SERVO_PIN 19

Servo brakeServo;

// angles
const int SERVO_REST = 0;      // initial position
const int SERVO_ENGAGED = 10;  // when it presses the saw
bool brakeEngaged = false;

void setup() {
  Serial.begin(115200);
  delay(1500);

  pinMode(MOTOR_PIN, OUTPUT);
  digitalWrite(MOTOR_PIN, LOW);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  brakeServo.attach(SERVO_PIN);
  brakeServo.write(SERVO_REST);

  // connect to Arduino IoT Cloud
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
}

void loop() {
  ArduinoCloud.update();
  measureDistance();

  // Automatic safety stop if object too close
  if (distance > 0 && distance < 3.0) {
    triggerEmergencyBrake();
  }

  delay(200);
}

// ---- Measure distance with HC-SR04 ----
void measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  if (duration > 0) {
    distance = (duration * 0.0343) / 2.0;
  } else {
    distance = -1;
  }

  Serial.print("Distance: ");
  Serial.println(distance);
}

// ---- Cloud variable callback for motor toggle ----
void onMotorStateChange() {
  if (!brakeEngaged) {
    digitalWrite(MOTOR_PIN, motorState ? HIGH : LOW);
    Serial.print("Motor ");
    Serial.println(motorState ? "ON" : "OFF");
  }
}

// ---- Cloud variable callback for emergency button ----
void onEmergencyBreakChange() {
  if (emergency_break) {
    triggerEmergencyBrake();
    // reset cloud button after handling
    emergency_break = false;
  }
}

// ---- Emergency brake routine ----
void triggerEmergencyBrake() {
  if (brakeEngaged) return; // already braking

  brakeEngaged = true;
  Serial.println("⚠️  EMERGENCY BRAKE ACTIVATED!");

  // stop motor immediately
  digitalWrite(MOTOR_PIN, LOW);
  motorState = false;

  // engage servo brake
  brakeServo.write(SERVO_ENGAGED);
  delay(500);   // press for half a second

  // release servo
  brakeServo.write(SERVO_REST);
  delay(500);

  brakeEngaged = false;
  Serial.println("✅ Brake released, system reset.");
}
