int a;
int b;
int ant1=HIGH;
int ant2=HIGH;
void setup() {
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(13,OUTPUT);
  Serial.begin(9600);

}

void loop() 
{
  a=digitalRead(2);
  //b=digitalRead(3);  
  if(a==LOW&&ant1==HIGH)
  {
    ant1=a;
    Serial.println("Gaseosa LLena");
    b=digitalRead(3);
    while(b==LOW)
    {
      
    }
    Serial.println("Gaseosa tapada");
    digitalWrite(13,HIGH);
      Serial.println("Gaseosa bien empacada");
    //b=digitalRead(3);  
    /*if(b==LOW&&ant2==HIGH)
    {
      ant2=b;
      Serial.println("Gaseosa tapada");
      //Serial.println("Gaseosa bien empacada")
      digitalWrite(13,HIGH);
      Serial.println("Gaseosa bien empacada");
    }*/
    
    /*else
    {
     Serial.println("Gaseosa Sin tapa");
    }
    */

  }
  /*else 
  {
    Serial.println("Gaseosa sin llenar");
  }
  */

}
