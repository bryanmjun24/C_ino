#define Pecho 6

#define Ptrig 7
long duracion, distancia, d, m, b;   
int lvlmin=5, lvlmax=30, aux;

void setup() {
  // put your setup code here, to run once:
 Serial.begin (9600);       // inicializa el puerto seria a 9600 baudios
  pinMode(Pecho, INPUT);     // define el pin 6 como entrada (echo)
  pinMode(Ptrig, OUTPUT);    // define el pin 7 como salida  (triger)
  digitalWrite(Ptrig, LOW);
  pinMode(13, 1);            // Define el pin 13 como salida
  analogWriteResolution(12);// la resolución del conversor usado en DAC

}

void loop() {
 
  digitalWrite(Ptrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig, HIGH);   // genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW);
  
  duracion = pulseIn(Pecho, HIGH);
  distancia = (duracion/2) / 29;     
  d=duracion/59;
  if (d>lvlmin&&d<lvlmax){
    m=4090/(lvlmax-lvlmin);
    b=m*lvlmin;
    aux=m*d-b;
   analogWrite(DAC0,aux);
    
  }
  
   //Serial.print(distancia);           // envia el valor de la distancia por el puerto serial
   Serial.println(d); 
   //Serial.println("cm");              // le coloca a la distancia los centimetros "cm"
   //analogWrite(DAC0,4095);
   Serial.println(aux);
   //Serial.println(m);
   //Serial.println(b);


   // analogWrite(DAC0,4090);

   

  delay(400); 

}
