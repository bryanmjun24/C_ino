//#include <HC05.h>
#include<Servo.h>//insertar libreria de servomores
#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3);
//int BTTx = 2; // Sparkfun Bluetooth Module: TX
//int BTRx = 3; // Sparkfun Bluetooth Module: RX
Servo motorsin;
char dato[255];
//int dato
int i=0;
const int max_pulso=650;//cuando el servo es 0 grados 1000
const int min_pulso=2000;//cuando el servo esta a 180 grados2000


void setup() {
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
   motorsin.attach(9,min_pulso,max_pulso);

}

void loop() {
   if (BT.available())
   {
    digitalWrite(13, HIGH);
    char dato=BT.read();
    Serial.println(BT.read());
    //digitalWrite(6,HIGH);
    //motorsin.write(90);
    if (dato==49)
    {
      digitalWrite(4,HIGH);
      digitalWrite(5, LOW);
    }
    if (dato==50)
    {
      digitalWrite(4,LOW);
      digitalWrite(5, HIGH);
    }
   if(dato==51)
   {
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
   }
   if (dato==52)
   {
    motorsin.write(68);
    
   }
   if (dato==53)
   {
    motorsin.write(120);
    
   }
    
   if (dato==54)
   {
    motorsin.write(93);
    
   }
    
  }
  
}
