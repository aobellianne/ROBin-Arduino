/* Example sketch to control a 28BYJ-48 stepper motor with ULN2003 driver board and Arduino UNO. More info: https://www.makerguides.com */
#include <Stepper.h>

const int stepsPerRevolution = 2048;
const int buttonPin = 2;
const int ledPin =  7; 
const int extensionLedPin = 1;

//Pin connected to ST_CP of 74HC595
int latchPin = 4;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 3;

int buttonState = 1;
int previousState = 1;

Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  myStepper.setSpeed(5);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);

//  digitalWrite(1, HIGH);
//  digitalWrite(5, HIGH);

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    registerWrite(extensionLedPin, HIGH);
    myStepper.step(1);
  } else {
    digitalWrite(ledPin, LOW);
    registerWrite(extensionLedPin, LOW);
  }
}

void registerWrite(int whichPin, int whichState) {
  byte bitsToSend = 0;
  digitalWrite(latchPin, LOW);
  bitWrite(bitsToSend, whichPin, whichState);
  shiftOut(dataPin, clockPin, MSBFIRST, bitsToSend);
  digitalWrite(latchPin, HIGH);
}
