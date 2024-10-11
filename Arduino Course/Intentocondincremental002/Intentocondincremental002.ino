float Sensibilidad=0.100; //sensibilidad en Voltios/Amperio para sensor de 20A
int PWM =9;          // Pin de salida de la seÒal PWM.         // PotenciÛmetro en el pin analÛgico 0, permite variar frecuencia.
int Pot2 = 1; 
int i=0;// PotenciÛmetro en el pin analÛgico 1, permite variar el ciclo de trabajo.
unsigned long DPot1;  // Lectura de datos en la entrada analÛgica 1.
unsigned long DPot2;  // Lectura de datos en la entrada analÛgica 2.
float Aux1 = 0, N=0.005, paso;      
float V0=669, V, dV;
float I0=3, dI;
float P, P0, dP;
float D, D0=249;
float iv;





void setup() {
  
  Serial.begin(9600);
  pinMode(PWM, OUTPUT);
  TCCR1A = _BV(COM1A1) | _BV(COM1B1) ;  // ConfiguraciÛn del modo fase y frecuencia correcta.
  TCCR1B = _BV(WGM13) | _BV(CS11);      // SelecciÛn del modo 8 y divisiÛn entre 8 de la f principal.
  
  
}

void loop() {
  
  float I=get_corriente(200);//obtenemos la corriente promedio de 200 muestras 
  //Serial.print("Corriente: ");
  //Serial.println(I,3);
  V=analogRead(A1);
  dV=V-V0;
  dI=I-I0;
  P=V*I;
  P0=V0*I0;
  dP=P-P0;
  paso=10*N*abs(dP/(dV-dI));//multiplico por 499 porque 500 es la amplitud maxima de mi paso en el OCR1A = int(249)
  //lazo principal
  iv=-I/V;
  
  if(dV=0){
    if(dI==0){
      D=D0;
      OCR1A = int(D);
      }
    else{
      if(dI>0){
        D=D0+paso;
        OCR1A = int(D);
        }

      else {
        D=D0-paso;
        OCR1A = int(D);
        }
      
      }
    
  }
  else {
    //utilizo IV para -I/V
    
    if((dI/dV)==iv){ 
      D=D0;
      OCR1A = int(D);
    }
    else {
      if ((dI/dV)>iv){
        D=D0-paso;
        OCR1A = int(D);
        }
      else {
        D=D0+paso;
        OCR1A = int(D);
        }      
      }
  }

  V0=V;
  I0=I;
          Serial.print("delta");
        Serial.println(D,4);
  
  
  

   








   ICR1 =  499; //valor para 2kf porque ciclo de maquina 1/16MHz entonces preescalador 8 
   //modo pWM correcto con tope en ICR1 
   //entonces 500 *2*8* 65*10 a la -9

 OCR1A = int(249);
   
  /*
  DPot2 = analogRead(Pot2);     // Lee el valor analÛgico de 10 bits del potenciÛmetro.                           

  if (DPot2 >= 0 && DPot2 <= 102) {
    OCR1A =int(50);            // Si la condiciÛn anterior se cumple se envia el 10%.
                                // del duty cycle al pin PWM como lÌmite, de lo contario.
  } else if (DPot2 >= 922 && DPot2 <= 1024)  {
    OCR1A = int(450);         // Si la condiciÛn anteriror se cumple se envia el 90%
                               // del duty cycle al pin PWM como lÌmite, de lo contrario.
  } else {                     // Si ninguna condiciÛn anterior se cumple se envia al
    Aux1 = float(DPot2);      
    Aux1 = Aux1 * ICR1;
    Aux1 = Aux1 / 1024; 
    OCR1A = int(Aux1);
  }               
      */
}













float get_corriente(int n_muestras)
{
  float voltajeSensor;
  float corriente=0;
  for(int i=0;i<n_muestras;i++)
  {
    voltajeSensor = analogRead(A0) * (5.0 / 1023.0);////lectura del sensor
    corriente=corriente+(voltajeSensor-2.5)/Sensibilidad; //Ecuación  para obtener la corriente
  }
  corriente=corriente/n_muestras;
  return(corriente);

}
