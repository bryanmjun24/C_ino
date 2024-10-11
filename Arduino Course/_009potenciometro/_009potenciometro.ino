float n;
int a;

//float decimal(int x);
void setup() {
  //cuando se inician variablkes analogas no se necesita 
  //declarar un imput
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  //pinMode(2,OUTPUT);

}

void loop() {
  a=analogRead(A0);
  //n=(a*(5/1023));
  
  a=map(a,50,700,0,100);
  Serial.println(a);
  delay(50);
  if(a<20&&a>0)
  {
    digitalWrite(13,HIGH);
    }
    if(a<40&&a>20)
  {
    digitalWrite(2,HIGH);
    }
    if(a<60&&a>40)
  {
    digitalWrite(3,HIGH);
    }
    if(a<80&&a>60)
  {
    digitalWrite(4,HIGH);
    }
    if(a<100&&a>80)
  {
    digitalWrite(5,HIGH);
    }
 /* if(a>0)
  {
    if(a<20)
    {
    digitalWrite(13,HIGH);
    }
    }
    else if(a>20)
  {
    if(a<40)
    {
    digitalWrite(2,HIGH);
    }
    }
    else if(a>40)
  {
    if(a<60)
    {
    digitalWrite(3,HIGH);
    }
    }
    else if(a>60)
  {
    if(a<80)
    {
    digitalWrite(4,HIGH);
    }
    }
    else if(a>80)
  {
    if(a<100)
    {
    digitalWrite(5,HIGH);
    }
    }*/
    
    /*else 
    {
      digitalWrite(13,LOW);
      }*/
     
  //Serial.println(a);
  //delay(100);
  /*if(n==5)
  {
    digitalWrite(13,HIGH);
    }
    else 
    {
      digitalWrite(13,LOW);
      }
  Serial.println(n);
  delay(300);*/
  

}
/*float decimal(int a)
{
  float x;
  x=((5/1023)*a);
  return(x);
  }*/
