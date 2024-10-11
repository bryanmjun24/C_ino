#include <LiquidCrystal.h>
#include <Servo.h>
LiquidCrystal lcd(4,5,6,7,8,9);
Servo valvula;
//***VARIABLES***************
float angulo=0;
int setpoint=100,setpoint1=0;
int variable=0;
const int pinServo = 10;

void setup()
{
  lcd.begin(16,2);
  valvula.attach(pinServo);
  pinMode(2,INPUT);
  pinMode(11,INPUT);
  pinMode(3,INPUT);
  lcd.setCursor(3,0);
  lcd.print("SERVOVALVULA");
  lcd.setCursor(5,1);
  lcd.print("P10");
  delay(1000);
}

void loop()
{
  if (digitalRead(2)==LOW)subir();
  if (digitalRead(11)==LOW)bajar();
  if (digitalRead(3)==LOW)conf();
  if(variable==0)
 {
   lcd.setCursor(0,0);
   lcd.print("Set Point =      ");
   lcd.setCursor(11,0);
   lcd.print(setpoint);
  if(setpoint1!=0 && setpoint1!=setpoint)
   {lcd.setCursor(0,1);
   lcd.print("Valor actual=    ");
   lcd.setCursor(14,1);
   lcd.print(setpoint1);
   }
   if(setpoint==setpoint1)
  {lcd.setCursor(0,1);lcd.print("Valvula Abierta ");}
  if(setpoint1==0) 
  {lcd.setCursor(0,1);lcd.print("Valvula Cerrada ");}
  valvula.write(angulo);
 }
  if (variable==1)
 {
   lcd.setCursor(0,0);
   lcd.print("SetPoint:        ");
   lcd.setCursor(0,1);
   lcd.print(setpoint);
   lcd.setCursor(3,1);
   lcd.print("                  ");
 }
}

//******************FUNCIONES****************

void subir()
{delay(400);
  if (variable==0)
  {
    if (setpoint1 < setpoint)
    {
      angulo=angulo+4;
      setpoint1=setpoint1+5;
    }
  }
  if (variable==1)
  {
    if (setpoint < 100)
    {
          setpoint=setpoint+5;
    }
  }
}
void bajar()
{delay(400);
  if (variable==0)
   {
     if (setpoint1 > 0)
     {
      angulo=angulo-4;
      setpoint1=setpoint1-5;
     }
   }
  if (variable==1)
   {
     if (setpoint > 0)
     {
      setpoint=setpoint-5;
     }
     if (setpoint<100)
     {lcd.setCursor(2,1);lcd.print(" ");}
   }

}
void conf()
{delay(400);
    variable=!variable;
    delay(500);
}


  
