float uk=0,uk1=0,ek=0,ek1=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}

void loop() {
Serial.println(uk,6); // envio 6 decimales
ek1=ek; // guardo el error anterior
ek=Serial.parseFloat(); // recibo error flotante

//tiempo2=millis();
//if (tiempo2=tm){
//uk1=uk; // guardo el valor anterior
//uk=uk1-0.3051*ek+0.2935*ek1; // ley de control
//}

uk1=uk; // guardo el valor anterior
uk=uk1-0.3051*ek+0.2935*ek1; // ley de control
}
