long muestra;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);//para el manejo de la comunicación serial 
  pinMode(2,OUTPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:
muestra = map(analogRead(A0), 0, 1023, 0, 10000);
Serial.println(muestra);
//digitalWrite(2,HIGH);

}
