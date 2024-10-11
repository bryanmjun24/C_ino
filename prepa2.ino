
void setup() {
  // put your setup code here, to run once:
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(6,INPUT);
pinMode(5,INPUT);

}

void loop() {
 // conduccion 120 grados
if (digitalRead(5) == HIGH){
 while (digitalRead(6) == HIGH) {
  // 60HZ T=2.788m[s]
    //PRIMER INTERVALO
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    delayMicroseconds(2788);
    //SEGUNDO INTERVALO
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    delayMicroseconds(2788);
    //TERCER INTERVALO
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    delayMicroseconds(2788);
    //CUARTO INTERVALO
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    delayMicroseconds(2788);
    //QUINTO INTERVALO
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    delayMicroseconds(2788);
    //SEXTO INTERVALO
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    delayMicroseconds(2788);   
  }
   while (digitalRead(6) == LOW) {
  // 30HZ T=5.556m[s]
    //PRIMER INTERVALO
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    delayMicroseconds(5556);
    //SEGUNDO INTERVALO
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    delayMicroseconds(5556);
    //TERCER INTERVALO
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    delayMicroseconds(5556);
    //CUARTO INTERVALO
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    delayMicroseconds(5556);
    //QUINTO INTERVALO
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    delayMicroseconds(5556);
    //SEXTO INTERVALO
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    delayMicroseconds(5556);   
  }
   }
   else{//conduccion a 180
 while (digitalRead(6) == HIGH) {
  // 60HZ T=2.788m[s]
    //PRIMER INTERVALO
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    delayMicroseconds(2788);
    //SEGUNDO INTERVALO
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    delayMicroseconds(2788);
    //TERCER INTERVALO
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    delayMicroseconds(2788);
    //CUARTO INTERVALO
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    delayMicroseconds(2788);
    //QUINTO INTERVALO
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    delayMicroseconds(2788);
    //SEXTO INTERVALO
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    delayMicroseconds(2788);   
  }
   while (digitalRead(6) == LOW) {
  // 30HZ T=5.556m[s]
   //PRIMER INTERVALO
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    delayMicroseconds(5556);
    //SEGUNDO INTERVALO
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    delayMicroseconds(5556);
    //TERCER INTERVALO
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    delayMicroseconds(5556);
    //CUARTO INTERVALO
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    delayMicroseconds(5556);
    //QUINTO INTERVALO
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    delayMicroseconds(5556);
    //SEXTO INTERVALO
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    delayMicroseconds(5556); 
  }   
   }
  }
  // put your main code here, to run repeatedly:

