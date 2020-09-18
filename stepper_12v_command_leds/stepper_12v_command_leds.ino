const int redButtonPin = 8;
const int blueButtonPin = 9;
const int redLedPin = 10;
const int blueLedPin = 11;
const int potPin = 0;
const int dirPin = 2;
const int stepPin = 3;

const int stepsPerRevolution = 200;
const int maxPotValue = 1023;
const int minSpeed = 1500 + maxPotValue;

int potValue = 0;
int rotationDir = 0;

void setup() {
  pinMode(redButtonPin, INPUT_PULLUP);
  pinMode(blueButtonPin, INPUT_PULLUP);
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  digitalWrite(redLedPin, LOW);
  digitalWrite(blueLedPin, LOW);
}

void rotateMotor() {
  int ledPin = rotationDir == 1 ? redLedPin : blueLedPin;
  
  digitalWrite(stepPin, HIGH);
  digitalWrite(ledPin, HIGH);
  delayMicroseconds(minSpeed - potValue);
  digitalWrite(stepPin, LOW);
  digitalWrite(ledPin, LOW);
  delayMicroseconds(minSpeed - potValue);
}

void loop() {
  int redButtonState = digitalRead(redButtonPin);
  int blueButtonState = digitalRead(blueButtonPin);
  
  potValue = analogRead(potPin);

  if (redButtonState == LOW) {
    rotationDir = 1;
    digitalWrite(dirPin, HIGH);
  } else if (blueButtonState == LOW) {
    rotationDir = 2;
    digitalWrite(dirPin, LOW);
  } else {
    rotationDir = 0;
  }

  if (rotationDir != 0) {
    rotateMotor();
  }
}
