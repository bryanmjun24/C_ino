int velo=0;
int a=0;
float cent=0;
void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);

}

void loop() {
  a=analogRead(A0);
  cent=(500*a/1023);
  velo=(cent-27)*150;
  Serial.println(cent);
  delay(300);
  if(cent>=28)
  {
    analogWrite(11,velo);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
  }
  else
  {
    analogWrite(11,0);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
  }
  
}
