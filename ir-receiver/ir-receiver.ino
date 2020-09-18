#include <IRremote.h>

const int irReceiverPin = A0;
const int irLedPin = 11;
int sensorValue = 0;
int clockCount = 0;

IRrecv irrecv(irReceiverPin);
decode_results results;

void setup() {
//  pinMode(irReceiverPin, INPUT);
  irrecv.enableIRIn();

  pinMode(irLedPin, OUTPUT);
  Serial.begin(9600);

  digitalWrite(irLedPin, LOW);
}

void loop() {
//  irrecv.decode(&results);
//  
////  if (irrecv.decode(&results)) {
////    Serial.println(results.value, HEX);
////    irrecv.resume();
////  } 
//    
//  if (clockCount % 10000 == 0) {
////    sensorValue = analogRead(irReceiverPin);
////    Serial.println(sensorValue);
//    Serial.println(results.value);
//  }
//  clockCount++;
}
