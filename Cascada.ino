float uk=0,uk_1=0,ek=0,ek_1=0;
float uk1=0,uk1_1=0,ek1=0,ek1_1=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}

void loop() {

ek1_1=ek1; // guardo el error anterior
ek1=Serial.parseFloat(); // recibo error flotante

uk1_1=uk1; // guardo el valor anterior
uk1=uk1_1-0.6098*ek1+0.5882*ek1_1; // ley de control

ek_1=ek; // guardo el error anterior
ek=Serial.parseFloat(); // recibo error flotante

uk_1=uk; // guardo el valor anterior
uk=0.458*ek; // ley de control

Serial.print(uk1,6);
Serial.print(',');
Serial.println(uk,6); // envio 6 decimales




}
