const int analogInPin2 = A3;
const int analogOutPin = 9; 
const int ledPin =  13; 
int i=0,acond=0,dator=0,menu=1;
double sensorValue = 0; 
double sensorValue2 = 0;      
double outputValue = 0; 
double m=0,m1=0,m2=0,m3=0,m4=0,m5=0,e=0,e1=0,e2=0,e3=0,e4=0,e5=0,sp,vel=0,vel2=0,vel3=0,sum=0,ki=0,kd=0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sp= (dator*628.32)/255;
  vel3=vel2;
  vel2=vel;
  vel= (analogRead(analogInPin2)*628.32)/1023;
  vel=(vel3+vel2+vel)/3;
  
  e5=e4;
  e4=e3;
  e3=e2;
  e2=e1;
  e1=e;
  
  e=sp-vel;
  
  m5=m4;
  m4=m3;
  m3=m2;
  m2=m1;
  m1=m; 
  if(menu==3){
    sum=e+sum;
    kd=(e-e1)/0.025;
  ki=sum*0.0025;    
  if(sum<-24)
  sum=-24;
  
   }
  
  
  if(menu==1)
  m=1.9405*e-0.443*e1-1.6152*e2+0.1763*e3+0.0526*m1+0.7231*m2+0.2243*m3;// Tmin
  if(menu==2)
  m=1.3573*e1-2.19*e2+0.8351*e3+0.9022*m1+0.7385*m2-0.6407*m3; // Ragazzini
  if(menu==3)
  m=e/4+ki*0.1+kd/100;  // Isaac
  if(menu==4)
  m=0.3*e-0.0076*e1-0.2498*e2+m1; // PI Dayan
  if(m<0)
  m=0;
  if(m>24)
  m=24;
  if(dator==0)
  m=0;
  outputValue = map(m, 0, 24, 0, 255);
  if(outputValue<5)
  outputValue=0;
  analogWrite(analogOutPin, outputValue);  
  acond=vel*255/628.32;
  if (Serial.available()>0){
    dator=Serial.read();
    Serial.print(vel);

    if(dator==255){
      menu=1;
      dator= (sp*255)/628.32;
    }else if(dator==254){
      menu=2;
      dator= (sp*255)/628.32;
    }else if(dator==253){
      menu=3;
      dator= (sp*255)/628.32;
    }else if(dator==252){
      menu=4;
      dator= (sp*255)/628.32;
    }
    
    } 
} 
