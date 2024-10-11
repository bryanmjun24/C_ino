char letra;

void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(13,OUTPUT);

}

void loop() {
  letra=Serial.read();
  if(letra=='A')
  {
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(13,HIGH);
    }
    else if(letra=='B')
    {
      digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(13,HIGH);
      }
      else if(letra=='C')
      {
        digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(13,LOW);
        
        }
        else {
          Serial.println("Error");
          //AAAAAAAAAAAAAAAAAAdelay(5000);
          }
          

}
