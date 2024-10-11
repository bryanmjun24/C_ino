#include <avr/interrupt.h>
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  digitalWrite(2, LOW);
  attachInterrupt(digitalPinToInterrupt(2), disparo, RISING);
}
void disparo() {
  //delayMicroseconds(8000);
  int rt = analogRead(A0) * 7.7224;
  digitalWrite(3,HIGH);
  delayMicroseconds(rt);
  digitalWrite(3, LOW);
  digitalWrite(2, LOW);
 
  
}
void loop() {
  // put your main code here, to run repeatedly:
}
