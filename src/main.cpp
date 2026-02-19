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

    long duration = pulseIn(echoPin,1);
    long distance = (duration*0.0343)/2;
    if(distance<=5){
        MYSERVO.write(360);
    }
    else{
        MYSERVO.write(0);
    }
    Serial.print("distance: ");
    Serial.print(distance);
    Serial.println("cm");

    delay(500);
}