#include<Servo.h>//insertar libreria de servomores
Servo motorsin;
int potencio;
int angulo;
const int max_pulso=650;//cuando el servo es 0 grados 1000
const int min_pulso=2000;//cuando el servo esta a 180 grados2000

void setup() {
  motorsin.attach(4,min_pulso,max_pulso);// si no pongo comas me da esos de arriba x default
  

}

void loop() {
  potencio=analogRead(A0);
  angulo=map(potencio,0,1023,0,180); 
  motorsin.write(angulo);
  delay(20);

}
