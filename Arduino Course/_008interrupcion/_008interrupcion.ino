int actual=LOW;

void setup() {
  pinMode(13,OUTPUT);
  pinMode(2,INPUT_PULLUP);
  attachInterrupt(0,funcionsita,FALLING);
  

}

void loop() {
  delay(20);
  digitalWrite(13,actual);

}
void funcionsita()
{
  actual=!actual;
  
  }
