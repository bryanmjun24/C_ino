int velo=0;
int a=0;
float cent=0;
void setup() {
  Serial.begin(9600);
  pinMode(3,OUTPUT);//rojo
  pinMode(5,OUTPUT);//verde
  pinMode(6,OUTPUT);//azul
  pinMode(9,OUTPUT);//motor

}

void loop() {
  a=analogRead(A0);
  cent=(500*a/1023);
  velo=(cent-27)*40;
  Serial.println(cent);
  delay(300);
  if(cent>=28)
  {
    analogWrite(9,velo);
    }
   if (cent<28)
   {
     analogWrite(3,255-230);//en mi ledsito se pone contrario osea si quiero prender mando 0 y apagar 255
     analogWrite(5,0);
     analogWrite(6,255);
     }
     if(cent>=28&&cent<30)
     {
     analogWrite(3,0);
     analogWrite(5,255-128);
     analogWrite(6,255);     
       
       }
       if(cent>=30)
       {
         analogWrite(3,0);
         analogWrite(5,255);
         analogWrite(6,255);  
         }
         if(cent<28)
         {
           analogWrite(9,0);
           }
         
  
  
}
