/**
* @file main.ino
 * @brief MG995 Closed-Loop Axis Control System
 * @author YOUR_NAME
 * @date YYYY-MM-DD
 *
 * @details
 * Implements PWM-based closed-loop control for MG995 servo motor.
 * Accepts angle input via Serial Monitor and validates range (0–180).
 */

## 🧠 Code Overview
The system uses the `Servo.h` library to generate PWM signals for angular positioning.
**/
#include <Arduino.h>
#include <Servo.h>
Servo MYSERVO;
int trigPin = 9;
int echoPin = 10;
void setup() {
    pinMode(trigPin,OUTPUT);
    pinMode(echoPin,INPUT);
    MYSERVO.attach(5);
    Serial.begin(9600);
// write your initialization code here

}
void loop() {
// write your code here
    digitalWrite(trigPin,0);
    delayMicroseconds(2);

    digitalWrite(trigPin, 1);
    delayMicroseconds(10);

    digitalWrite(trigPin,0);
    delayMicroseconds(2);
