#include <Servo.h>

Servo servo;

const int servoPin = 8;
const int buttonPin = 7;

void setup() {
  Serial.begin(9600);
  
  pinMode(buttonPin, 7);
  
  servo.attach(servoPin);
  servo.write(0);
}

void loop() {
////  digitalWrite(servoPin, HIGH);
//  delay(1000);
//  servo.write(90);
////  digitalWrite(servoPin, LOW);
//  delay(1000);
//  servo.write(0);

  int buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    servo.write(40);
  } else {
    servo.write(90);
  }
}
