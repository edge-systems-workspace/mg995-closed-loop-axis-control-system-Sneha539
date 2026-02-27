/**
* @file main.ino
 * @brief MG995 Closed-Loop Axis Control System
 * @author Sneha Singh
 * @date 19-02-2026
 *
 * @details
 * Implements PWM-based closed-loop control for MG995 servo motor.
 * Accepts angle input via Serial Monitor and validates range (0–180).
 */

/**Code Overview
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
    long duration = pulseIn(echoPin, HIGH);
    long distance = (duration * 0.0343) / 2;

    if (distance <= 5) {
        MYSERVO.write(180);   // rotate servo
    } else {
        MYSERVO.write(0);     // reset servo
    }

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(500);
}
