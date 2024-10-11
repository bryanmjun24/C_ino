
int a;
int b;
int led=0;
int antes1;
int antes2;
void setup() {
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(4,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  a=digitalRead(2);
  b=digitalRead(3);
  if(a==LOW&&antes1==HIGH)
  {
    led=1-led;
     if(led==1)
  {
    
    Serial.println("led prendido");
    }
    else{
      Serial.println("led apagado");
      }
}
antes1=a;
if(b==LOW&&antes2==HIGH)
{
  led=1-led;
  if(led==1)
  {
    
    Serial.println("led prendido");
    }
    else{
      Serial.println("led apagado");
      }
}
antes2=b;
if(led==1)
{
  digitalWrite(4,HIGH);
  //Serial.println("led prendido");
}
//antes2=b;
  else
  {
    digitalWrite(4,LOW);
    //Serial.println("led apagado");
  }
}
