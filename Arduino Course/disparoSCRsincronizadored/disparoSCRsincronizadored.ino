//disparo scr sync con la red
int zcross = 2;
int pinOut = 10;
int pinOut2 = 11;
int pinIn = A0;
int var1,var2;

volatile int con = 0;
unsigned int timee = 0;

void setup(){
  pinMode(pinOut, OUTPUT);
  pinMode(pinOut2, OUTPUT);
  pinMode(zcross, INPUT_PULLUP);
  pinMode(pinIn, INPUT);
  digitalWrite(pinOut, LOW);
  digitalWrite(pinOut2, LOW);

  attachInterrupt(digitalPinToInterrupt(zcross), zcrossInterrup, CHANGE);
//  Serial.begin(115200); 
}

void loop(){
   
   if (con == 1){
      timee = map(analogRead(pinIn),0,1023,1,8000); //8333
      delayMicroseconds (timee);
      digitalWrite(pinOut, HIGH);
      digitalWrite(pinOut2, HIGH);
      delayMicroseconds (15);
      digitalWrite(pinOut, LOW);
      digitalWrite(pinOut2, LOW);
      con = 0;
   }  
}

void zcrossInterrup(){
       con = 1;
}
