void setup() {
  Serial.begin(9600);//En el monitor serial toka poner donde dice sin ajuste de linea toka ´poner nueva linea
  pinMode(3,OUTPUT);// si son salidas analogas, automaticamente ya se les denomina como salidas
  //al usar el analog write
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);

}

void loop() {
  while(Serial.available()>0)//es para ver si hay algoi que meta en el serial
  {
    int r=Serial.parseInt();//esta funcion entrega el primer entero valido en el buffer serial
    int v=Serial.parseInt();//ingnora caracteres q no sean int
    int az=Serial.parseInt();
    if(Serial.read()=='\n' )
    {
      r=255-constrain(r,0,255);//los valores solo pueden estar entre el 0 y el 255
      v=255-constrain(v,0,255);
      az=255-constrain(az,0,255);
      
      analogWrite(3,r);
      analogWrite(5,v);
      analogWrite(6,az);
      Serial.print("Rojo:");
      Serial.print(255-r);
      Serial.print(", ");
      Serial.print("Verde:");
      Serial.print(255-v);
      Serial.print(", ");
      Serial.print("Azul:");
      Serial.print(255-az);
      Serial.print("\n");
      
      }
    
    }

}
