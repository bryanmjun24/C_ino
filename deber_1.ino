void setup(){
int x=0;                 // Asinamos la variable x.
  for(x=6;x<14;x=x+1)      // Iniciamos funcion FOR para apagar los leds desde un inicio.
  {
    pinMode(x,OUTPUT);     // Todos se asignan como salidas.
    digitalWrite(x,LOW);   // Todos se apagan de inicio.
  }
}
void loop() {
 int pinActual=0;                                            // Asignamos la variable pinActual.
  for(pinActual=7;pinActual<14;pinActual=pinActual+1)         // Iniciamos funcion FOR para ir desde el pin 6 hasta el pin 13.
  {
    digitalWrite (pinActual,HIGH);                           // Encendemos el led que este con el numero de pinActual.
    delay(50);                                              // Duracion de medio segundo.
    digitalWrite (pinActual, LOW);                           // Apagamos el led que este con el numero de pinActual .
    delay(50);                                              // Duracion de medio segundo.
  }
  for(pinActual=13;pinActual>5;pinActual=pinActual-1)         // Iniciamos funcion FOR para ir desde el pin 13 hasta el pin 6.
  {
    digitalWrite (pinActual,HIGH);                           // Encendemos los leds.
    delay(50);                                              // Duracion de medio segundo.
    digitalWrite (pinActual, LOW);                           // Apagamos los leds.
    delay(50);                                              // Duracion de medio segundo.
  }
}
