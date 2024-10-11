#include <avr/io.h>               //Librería para generación de PWM
#include <avr/interrupt.h>     //Librería para activar interrupciones
#define DETECT 2               //Asigno nombre para la detección cruce por cero
#define GATE 9                    //Asigno nombre para el pin donde se obtendrá la señal  
int i = 483;
void setup()
{
  // Asignación de pines
  pinMode(DETECT, INPUT);       //Detecta el cruce por cero
  digitalWrite(DETECT, HIGH);     //Habilita la Resistencia de Pull-up
  pinMode(GATE, OUTPUT);        // Pin del microcontrolador por donde se obtendrá la señal
  // Configurar  Timer 1
  //OCR1A = 100;      //Inicializa el comparador
  TIMSK1 = 0x03;     //Habilita el comparador A y la interrupción por desborde
  TCCR1A = 0x00;    //Asignación del registro del timer
  TCCR1B = 0x00;    //Operacion normal, timer deshabilitado
  // Configurar la interrupción de cruce por cero.
  attachInterrupt(0, zeroCrossingInterrupt, CHANGE);
  //IRQ0 is pin 2. Llamar a la interrupción de cruce por cero para flanco de subida
}
//Rutinas de interrupción
void zeroCrossingInterrupt() {   //Detección de cruce por cero
  TCCR1B = 0x04;                  //Iniciar timer dividido para entrada de 256
  TCNT1 = 0;                           //Reset timer – Inicia el contador en cero
}
ISR(TIMER1_COMPA_vect) { //Comparada el valor del timer con el valor establecido como   límite
  digitalWrite(GATE, HIGH);  //Coloca en 1L a la variable GATE
  TCNT1 = 65536 - (500 - i);  //Ancho de pulso
}
ISR(TIMER1_OVF_vect) {   //Desbordamiento Timer1
  digitalWrite(GATE, LOW);   //Colocar 0L en la variable GATE
  TCCR1B = 0x00;                 //Des habilitar el timer
}
void loop() {
  int pot = analogRead(A0);
  pot = pot / 2;                          // Porque al dividir para dos tengo un numero entre 0 y 512
  if (pot > 467)                         // Para el 10% de la relación de trabajo (0.9*520.83=468.747)
  {
    pot = 467;
    // Se asigna un valor a la salida
  }
  if (pot < 52)                           // para el 90% de relación de trabajo (0.1*520.83=52.083)
  {
    pot = 52; // do something here
  }
  i = pot;
  OCR1A = i;                            //Asignar el valor del comparador a un registro.
}

