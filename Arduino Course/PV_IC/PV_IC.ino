int PWM =9;          // Pin de salida de la seÒal PWM.         // PotenciÛmetro en el pin analÛgico 0, permite variar frecuencia.
int Pot2 = 1; 
int i=0;// PotenciÛmetro en el pin analÛgico 1, permite variar el ciclo de trabajo.
unsigned long DPot1;  // Lectura de datos en la entrada analÛgica 1.
unsigned long DPot2;  // Lectura de datos en la entrada analÛgica 2.
float Aux1 = 0;       

void setup() {
  pinMode(PWM, OUTPUT);
  TCCR1A = _BV(COM1A1) | _BV(COM1B1) ;  // ConfiguraciÛn del modo fase y frecuencia correcta.
  TCCR1B = _BV(WGM13) | _BV(CS11);      // SelecciÛn del modo 8 y divisiÛn entre 8 de la f principal.
}

void loop() {
  for(int i=0,j=0;i<255;i++)
{
 
  j++;
  j--;
  
}          


 
    ICR1 =  500; //valor para 2kf
  
  DPot2 = analogRead(Pot2);     // Lee el valor analÛgico de 10 bits del potenciÛmetro.                           

  if (DPot2 >= 0 && DPot2 <= 102) {
    OCR1A =int(918);            // Si la condiciÛn anterior se cumple se envia el 10%.
                                // del duty cycle al pin PWM como lÌmite, de lo contario.
  } else if (DPot2 >= 922 && DPot2 <= 1024)  {
    OCR1A = int(8302);         // Si la condiciÛn anteriror se cumple se envia el 90%
                               // del duty cycle al pin PWM como lÌmite, de lo contrario.
  } else {                     // Si ninguna condiciÛn anterior se cumple se envia al
    Aux1 = float(DPot2);      
    Aux1 = Aux1 * ICR1;
    Aux1 = Aux1 / 1024; 
    OCR1A = int(Aux1);
  }                              
}
