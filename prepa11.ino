
void setup() {
  // put your setup code here, to run once:
pinMode(7,OUTPUT);//1
pinMode(8,OUTPUT);//2
pinMode(9,OUTPUT);//3
pinMode(10,OUTPUT);//4

}

void loop() {
  // 60HZ T=2.788m[s]

    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
delayMicroseconds(8333);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
delayMicroseconds(10);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10,HIGH);
delayMicroseconds(8333);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
delayMicroseconds(10);

  }
  // put your main code here, to run repeatedly:

