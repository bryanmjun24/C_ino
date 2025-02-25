#define maxSamplesNum 120 //define el numero de muestras en la tabla
#define numerodeonda 9// especifica el número de ondas posibles a generar
#define oneHzSample 1000000/maxSamplesNum  // sample for the 1Hz signal expressed in microseconds 


static int waveformsTable[numerodeonda][maxSamplesNum] = {
  // Sin wave 0
  {
    0x7ff, 0x86a, 0x8d5, 0x93f, 0x9a9, 0xa11, 0xa78, 0xadd, 0xb40, 0xba1,
    0xbff, 0xc5a, 0xcb2, 0xd08, 0xd59, 0xda7, 0xdf1, 0xe36, 0xe77, 0xeb4,
    0xeec, 0xf1f, 0xf4d, 0xf77, 0xf9a, 0xfb9, 0xfd2, 0xfe5, 0xff3, 0xffc,
    0xfff, 0xffc, 0xff3, 0xfe5, 0xfd2, 0xfb9, 0xf9a, 0xf77, 0xf4d, 0xf1f,
    0xeec, 0xeb4, 0xe77, 0xe36, 0xdf1, 0xda7, 0xd59, 0xd08, 0xcb2, 0xc5a,
    0xbff, 0xba1, 0xb40, 0xadd, 0xa78, 0xa11, 0x9a9, 0x93f, 0x8d5, 0x86a,
    0x7ff, 0x794, 0x729, 0x6bf, 0x655, 0x5ed, 0x586, 0x521, 0x4be, 0x45d,
    0x3ff, 0x3a4, 0x34c, 0x2f6, 0x2a5, 0x257, 0x20d, 0x1c8, 0x187, 0x14a,
    0x112, 0xdf, 0xb1, 0x87, 0x64, 0x45, 0x2c, 0x19, 0xb, 0x2,
    0x0, 0x2, 0xb, 0x19, 0x2c, 0x45, 0x64, 0x87, 0xb1, 0xdf,
    0x112, 0x14a, 0x187, 0x1c8, 0x20d, 0x257, 0x2a5, 0x2f6, 0x34c, 0x3a4,
    0x3ff, 0x45d, 0x4be, 0x521, 0x586, 0x5ed, 0x655, 0x6bf, 0x729, 0x794
  }
  ,

  // Triangular wave 1
  {
    0x44, 0x88, 0xcc, 0x110, 0x154, 0x198, 0x1dc, 0x220, 0x264, 0x2a8,
    0x2ec, 0x330, 0x374, 0x3b8, 0x3fc, 0x440, 0x484, 0x4c8, 0x50c, 0x550,
    0x594, 0x5d8, 0x61c, 0x660, 0x6a4, 0x6e8, 0x72c, 0x770, 0x7b4, 0x7f8,
    0x83c, 0x880, 0x8c4, 0x908, 0x94c, 0x990, 0x9d4, 0xa18, 0xa5c, 0xaa0,
    0xae4, 0xb28, 0xb6c, 0xbb0, 0xbf4, 0xc38, 0xc7c, 0xcc0, 0xd04, 0xd48,
    0xd8c, 0xdd0, 0xe14, 0xe58, 0xe9c, 0xee0, 0xf24, 0xf68, 0xfac, 0xff0,
    0xfac, 0xf68, 0xf24, 0xee0, 0xe9c, 0xe58, 0xe14, 0xdd0, 0xd8c, 0xd48,
    0xd04, 0xcc0, 0xc7c, 0xc38, 0xbf4, 0xbb0, 0xb6c, 0xb28, 0xae4, 0xaa0,
    0xa5c, 0xa18, 0x9d4, 0x990, 0x94c, 0x908, 0x8c4, 0x880, 0x83c, 0x7f8,
    0x7b4, 0x770, 0x72c, 0x6e8, 0x6a4, 0x660, 0x61c, 0x5d8, 0x594, 0x550,
    0x50c, 0x4c8, 0x484, 0x440, 0x3fc, 0x3b8, 0x374, 0x330, 0x2ec, 0x2a8,
    0x264, 0x220, 0x1dc, 0x198, 0x154, 0x110, 0xcc, 0x88, 0x44, 0x0
  }
  ,

  // Sawtooth wave 2
  {
    0x22, 0x44, 0x66, 0x88, 0xaa, 0xcc, 0xee, 0x110, 0x132, 0x154,
    0x176, 0x198, 0x1ba, 0x1dc, 0x1fe, 0x220, 0x242, 0x264, 0x286, 0x2a8,
    0x2ca, 0x2ec, 0x30e, 0x330, 0x352, 0x374, 0x396, 0x3b8, 0x3da, 0x3fc,
    0x41e, 0x440, 0x462, 0x484, 0x4a6, 0x4c8, 0x4ea, 0x50c, 0x52e, 0x550,
    0x572, 0x594, 0x5b6, 0x5d8, 0x5fa, 0x61c, 0x63e, 0x660, 0x682, 0x6a4,
    0x6c6, 0x6e8, 0x70a, 0x72c, 0x74e, 0x770, 0x792, 0x7b4, 0x7d6, 0x7f8,
    0x81a, 0x83c, 0x85e, 0x880, 0x8a2, 0x8c4, 0x8e6, 0x908, 0x92a, 0x94c,
    0x96e, 0x990, 0x9b2, 0x9d4, 0x9f6, 0xa18, 0xa3a, 0xa5c, 0xa7e, 0xaa0,
    0xac2, 0xae4, 0xb06, 0xb28, 0xb4a, 0xb6c, 0xb8e, 0xbb0, 0xbd2, 0xbf4,
    0xc16, 0xc38, 0xc5a, 0xc7c, 0xc9e, 0xcc0, 0xce2, 0xd04, 0xd26, 0xd48,
    0xd6a, 0xd8c, 0xdae, 0xdd0, 0xdf2, 0xe14, 0xe36, 0xe58, 0xe7a, 0xe9c,
    0xebe, 0xee0, 0xf02, 0xf24, 0xf46, 0xf68, 0xf8a, 0xfac, 0xfce, 0xff0
  }
  ,

  // Square wave 3
  {
    0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff,
    0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff,
    0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff,
    0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff,
    0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff,
    0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff, 0xfff,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
  }

  ,

  // rectificada completa 4
  {
 0, 216, 431, 645, 858, 1068, 1275, 1479, 1678, 1873, 
 2063, 2246, 2424, 2595, 2758, 2914, 3062, 3201, 3331, 3452, 
 3564, 3665, 3756, 3837, 3907, 3966, 4014, 4051, 4077, 4091, 
 4094, 4086, 4066, 4034, 3992, 3938, 3874, 3798, 3712, 3616,
 3509, 3393, 3267, 3133, 2989, 2837, 2677, 2510, 2336, 2155,
 1968, 1776, 1579, 1377, 1172, 963, 752, 538, 323, 108,
 108, 323, 538, 752, 963, 1172, 1377, 1579, 1776, 1968, 
 2155, 2336, 2510, 2677, 2837, 2989, 3133, 3267, 3393, 3509,
 3616, 3712, 3798, 3874, 3938, 3992, 4034, 4066, 4086, 4094,
 4091, 4077, 4051, 4014, 3966, 3907, 3837, 3756, 3665, 3564,
 3452, 3331, 3201, 3062, 2914, 2758, 2595, 2424, 2246, 2063, 
 1873, 1678, 1479, 1275, 1068, 858, 645, 431, 216, 0
  }

    ,

  // rectificada media onda 5
  {
 0, 216, 431, 645, 858, 1068, 1275, 1479, 1678, 1873, 
 2063, 2246, 2424, 2595, 2758, 2914, 3062, 3201, 3331, 3452,
 3564, 3665, 3756, 3837, 3907, 3966, 4014, 4051, 4077, 4091,
 4094, 4086, 4066, 4034, 3992, 3938, 3874, 3798, 3712, 3616,
 3509, 3393, 3267, 3133, 2989, 2837, 2677, 2510, 2336, 2155,
 1968, 1776, 1579, 1377, 1172, 963, 752, 538, 323, 108,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
  }
    ,

  // diente y seno 6
  {
 
0, 216, 431, 645, 858, 1068, 1275, 1479, 1678, 1873, 
2063, 2246, 2424, 2595, 2758, 2914, 3062, 3201, 3331, 3452,
3564, 3665, 3756, 3837, 3907, 3966, 4014, 4051, 4077, 4091, 
4094, 4086, 4066, 4034, 3992, 3938, 3874, 3798, 3712, 3616, 
3509, 3393, 3267, 3133, 2989, 2837, 2677, 2510, 2336, 2155,
1968, 1776, 1579, 1377, 1172, 963, 752, 538, 323, 108,
34, 103, 172, 240, 309, 378, 447, 516, 584, 653,
722, 791, 860, 929, 997, 1066, 1135, 1204, 1273, 1342, 
1410, 1479, 1548, 1617, 1686, 1754, 1823, 1892, 1961, 2030,
2099, 2167, 2236, 2305, 2374, 2443, 2512, 2580, 2649, 2718,
2787, 2856, 2924, 2993, 3062, 3131, 3200, 3269, 3337, 3406, 
3475, 3544, 3613, 3682, 3750, 3819, 3888, 3957, 4026, 0
}

    ,

  // triangular y seno 7
  {
 
0, 216, 431, 645, 858, 1068, 1275, 1479, 1678, 1873,
2063, 2246, 2424, 2595, 2758, 2914, 3062, 3201, 3331, 3452,
3564, 3665, 3756, 3837, 3907, 3966, 4014, 4051, 4077, 4091,
4094, 4086, 4066, 4034, 3992, 3938, 3874, 3798, 3712, 3616, 
3509, 3393, 3267, 3133, 2989, 2837, 2677, 2510, 2336, 2155,
1968, 1776 ,1579 ,1377, 1172, 963, 752, 538, 323, 108,
68, 206, 344, 481, 619, 757, 894, 1032, 1170, 1307, 
1445, 1582, 1720, 1858, 1995, 2133, 2271, 2408, 2546, 2684, 
2821, 2959, 3097, 3234, 3372, 3510, 3647, 3785, 3922, 4060,
3991, 3854, 3716, 3578, 3441, 3303, 3165, 3028, 2890, 2752,
2615, 2477, 2340, 2202, 2064, 1927, 1789, 1651 ,1514 ,1376 ,
1238, 1101, 963, 825, 688, 550, 412, 275, 137, 0
}
  
  
};


int muestra;//variable que toma la muestra en hertzios
int contador=0;//contador que elije de la tabla que onda deseamos poner 
int boton, anterior;// variables para evitar rebote del pulsante

void setup() {
  pinMode(3,INPUT_PULLUP);//pin para el pulsador
  analogWriteResolution(12);// la resolución del conversor usado en DAC
   Serial.begin(9600);//para el manejo de la comunicación serial 
   
}

void loop() {
  boton=digitalRead(3);//leo lo que pasa con el boton
  if(boton==LOW&&anterior==HIGH) //evaluo estados del boton 
  {
    anterior=boton;//toma el anterior valor del boton
    contador=contador++;//aumenta el número de la tabla, se elige la señal que va a usarse 
    }
   // Read the potentiometer and map the value  between the maximum and the minimum sample available
  // 1 Hz is the minimum freq for the complete wave
  // 170 Hz is the maximum freq for the complete wave. Measured considering the loop and the analogRead() time
  muestra = map(analogRead(A0), 0, 4095, 0, oneHzSample);//mapea la señal A0
 //De la siguiente forma map(value, fromLow, fromHigh, toLow, toHigh)
  muestra = constrain(muestra, 0, 4095);// restringe los valores tomados de
  for(int i=0;i<=maxSamplesNum;i++){
      analogWrite(DAC1, waveformsTable[contador][i]);//envia la señal al DAC1
  Serial.println(waveformsTable[contador][i]);//monitorea la señal con el serial plotter
   delayMicroseconds(muestra);//proporciona el retardo entre cada señal enviada
  }
if (contador==7)// si se llega al tope de las señales existentes
{
  contador=0;// se encera el contador
  }
    

}
