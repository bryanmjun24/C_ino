int boton;
int led=0;
int anterior;

void setup() {
  pinMode(3,INPUT);
  pinMode(2,OUTPUT);

}

void loop() {
  boton=digitalRead(3);
  if(boton==LOW&&anterior==HIGH)
  {
    led=1-led;
    delay(20);
    }
    anterior=boton;
    if(led==1)
    {
      digitalWrite(2,HIGH);
      }
      else{
        digitalWrite(2,LOW);
        }

}
