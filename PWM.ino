void setup() {
  // put your setup code here, to run once:
pinMode(9,OUTPUT);
Serial.begin(9600);
}

void loop() {
  int a=65;
  // put your main code here, to run repeatedly:
//int pot= analogRead(A0);
//int potenc=map(pot,0,1023,0,15);
digitalWrite(9,HIGH);
delayMicroseconds(20+a);
digitalWrite(9,LOW);
delayMicroseconds(30100-a);
//digitalWrite(3,LOW);
//Serial.print(pot);
}

