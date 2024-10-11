int ence=0;
int apag=0;
int dire=0;
int ante=0;
int enable=0;////////
int velocidad=0;
int direccion=0;
void setup() {
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(4,OUTPUT);//control11
  pinMode(5,OUTPUT);//control12
  pinMode(6,OUTPUT);//enable
  digitalWrite(6,LOW);

}

void loop() {
  ence=digitalRead(2);
  delay(1);
  dire=digitalRead(3);
  velocidad=analogRead(A0)/4;//como es de 1023 le divido para 4 xq el maximo q puedo dar es 255
  if(ence==LOW&&apag==HIGH)
  {
    enable=!enable;
    }
    if(dire==LOW&&ante==HIGH)
    {
      direccion=!direccion;
      }
      if(direccion==1)
      {
        digitalWrite(4,HIGH);
        digitalWrite(5,LOW);
        }
        else
        {
          digitalWrite(4,LOW);
          digitalWrite(5,HIGH);
          }
       if(enable==1)
       {
         analogWrite(6,velocidad);
         }
         else
         {
           analogWrite(6,0);
           }
           ence=apag;
           dire=ante;

}
