int encendi=0;
int anterior=0;
int enable=0;
void setup() {
  pinMode(3,INPUT_PULLUP);
  pinMode(6, OUTPUT);

}

void loop() {
  encendi=digitalRead(3);
  if(encendi==LOW&&anterior==HIGH)
  {
    enable=!enable;
    }
    if(enable==1)
    {
      digitalWrite(6,HIGH);
      }
      else
      {
        digitalWrite(6,LOW);
        }
        anterior=encendi;

}
