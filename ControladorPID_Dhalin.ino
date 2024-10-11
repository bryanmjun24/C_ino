
//Para el test 3.5 con el controlador  discreto en funcion de Transferencia
float u;//señal de control
float u1 = 0;
float error = 0; //señal del error que viene de la compu
float error1 = 0;
float Kp = 2.9185875;
float Ki = 0.34925956;
float Kd = 0.87061465;
float P;
float I;
float D;
const float Tm = 0.5;
float data;
int bandera = 0;
void setup() {
  Serial.begin(9600);


}

void loop() {
  adquirir_datos();
  controlador();
  enviar_datos();

}

void adquirir_datos(void) {
  if (Serial.available())
  {
    data = Serial.parseFloat();
    bandera = 1;
  }
}

void controlador(void) {
  
  if (bandera == 1) {
    error = data;
    P = Kp * error ;
    I = Ki * error * 0.05 + I;
    D = Kd * (error - error1) / 0.05;
    // Se despeja la funcion discreta a funcion de diferencias
    u = P + I + D;
    error1 = error;
    u1 = u;
  }
}

void enviar_datos(void) {

  if (bandera == 1) {
    Serial.println(u, 8);//Envio la señal de control con 8 decimales

    bandera = 0;
  }
}
