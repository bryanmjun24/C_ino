const int inputPin = 2;
 
int val = 0;
int var,var1;
 
void setup() {
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
  pinMode(10,OUTPUT);
   pinMode(11,OUTPUT);
}
 
void loop(){
    var=(analogRead(A0));
    var1=map(var,0,1024,0,17);
  val = digitalRead(inputPin);  //lectura digital de pin
 
  //mandar mensaje a puerto serie en función del valor leido
  if (val == HIGH) {
      digitalWrite(10,HIGH);
      //digitalWrite(11,HIGH);
      
  }
  else {
      digitalWrite(10,LOW);
     // digitalWrite(11,LOW);
      delay(var1);
  }

}
