const byte Pin1 = 2;
const byte Pin2 = 3;
static volatile unsigned long debounce = 0; // Tiempo del rebote.
static volatile unsigned long debounce2 = 0; // Tiempo del rebote.

int i=0,acond=0,dator=0,menu=1;
const int analogOutPin = 10; // Analog output pin
byte outputValue = 0;
float pi=3.14159265;
void counter ();
void counter2 ();
double u=0,u1=0,u2=0,u3=0,u4=0,u5=0,e=0,e1=0,e2=0,e3=0,e4=0,e5=0,set,pos=0,pos2=0,pos3=0,sum=0,ki=0,kd=0;

void setup() 
    { 
       pinMode (7,OUTPUT);
       pinMode (8,OUTPUT);
       pinMode(Pin1, INPUT);
       attachInterrupt(digitalPinToInterrupt(Pin1),counter , RISING);
       pinMode(Pin2, INPUT);
       attachInterrupt(digitalPinToInterrupt(Pin2),counter2, RISING);
       Serial.begin (9600);
    }

void loop() 
    {
       set=(dator*360)/255;
       pos3=pos2;
       pos2=pos;
       
       pos=(pos3+pos2+pos);
       
           
       e5=e4;
       e4=e3;
       e3=e2;
       e2=e1;
       e1=e;
       
       e=set-pos;
      
       u5=u4;
       u4=u3;
       u3=u2;
       u2=u1;
       u1=u; 
       
       if(menu==1)
        u=1.9405*e-0.443*e1-1.6152*e2+0.0526*u1+0.7231*u2+0.2243*u3;// Tmin
       if(menu==2)
        u=1.3573*e1-2.19*e2+0.8351*e3+0.9022*u1+0.7385*u2-0.6407*u3; // Ragazzini
        
        if(u<0)
        u=0;
        if(u>5)
        u=5;
        if(dator==0)
        u=0;
        
        outputValue = map(u, 0, 5, 0, 255);
        if(outputValue<5)
        outputValue=0;
        
         analogWrite(analogOutPin, outputValue);
      
      
      if (Serial.available()>0) 
        {
            dator=Serial.read();
            Serial.print(pos);
           if(dator==255){
            menu=1;
            dator= (set*255)/360;
          }else if(dator==254){
            menu=2;
            dator= (set*255)/360;
          }else if(dator==253){
            menu=3;
            dator= (set*255)/360;
          }else if(dator==252){
            menu=4;
            dator= (set*255)/360;
          } 
                  
            
            
            
        }
        
    }
    
    
    void counter()
{
  if(  digitalRead (Pin1)==1 && (micros()-debounce > 500) ) { 
// Vuelve a comprobar que el encoder envia una señal buena y luego comprueba que el tiempo es superior a 1000 microsegundos y vuelve a comprobar que la señal es correcta.
        debounce = micros(); // Almacena el tiempo para comprobar que no contamos el rebote que hay en la señal.
       if(  digitalRead (Pin1)==1 && digitalRead (Pin2)==0) {
        pos=pos-0.9;
       }
        if(  digitalRead (Pin1)==1 && digitalRead (Pin2)==1) {
        pos=pos+0.9;
       }
           
     }  

    } 
void counter2()
{
  if(  digitalRead (Pin2)==1 && (micros()-debounce2 > 500)) { 
// Vuelve a comprobar que el encoder envia una señal buena y luego comprueba que el tiempo es superior a 1000 microsegundos y vuelve a comprobar que la señal es correcta.
        debounce2 = micros(); // Almacena el tiempo para comprobar que no contamos el rebote que hay en la señal.
        if(  digitalRead (Pin2)==1 && digitalRead (Pin1)==0) {
        pos=pos+0.9;
       }
        if(  digitalRead (Pin2)==1 && digitalRead (Pin1)==1) {
        pos=pos-0.9;
       }
       }  
}
  
      
