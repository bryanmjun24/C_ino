void setup() {
  // put your setup code here, to run once:
pinMode(5, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ciclo=(analogRead(A0)*0.782);
  digitalWrite(5, HIGH);
  delayMicroseconds(ciclo);
  digitalWrite(5, LOW);
  delayMicroseconds(800-ciclo);
}
