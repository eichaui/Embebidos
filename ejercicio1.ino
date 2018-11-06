/*                    UNIVERSIDAD TECNICA DEL NORTE 
                               FICA-CIERCOM
 Nombre:Alexander Ichau
               DEBER 1 DISPLAY 7 SEGMENTOS

  Realizar un sistema que permita contar de forma automática (sin pulsador,
  el sistema inicia y empieza a contar sin necesidad de una actividad del usuario). 
  Del 1 al 200 mediante la multiplexación de displays.
 */

int A=5; // pin de salida para display
int B=4; // pin de salida para display
int C=3; // pin de salida para display
int D=2; // pin de salida para display
int b1=6; // pin de entrada para pulsador
int i=0;  // variable de conteo
int cent=10;//activacion centenas
int dec=9; // acitivacion de display decenas
int uni=8;  //activacion unidades
int centenas;//almacenamiento centenas
int decenas; // almacenamiento de decenas
int unidades; // almacenamiento de unidades
void setup(){
  // configuracion de pin tanto como entrada o salida
 pinMode(A,OUTPUT);
 pinMode(B,OUTPUT); 
 pinMode(C,OUTPUT); 
 pinMode(D,OUTPUT); 
 pinMode(b1,INPUT);  
pinMode(dec,OUTPUT); 
pinMode(uni,OUTPUT); 
pinMode(cent,OUTPUT); 

}

void loop(){
   if(i<200){     // limite de conteo
     i++;       // aumento de variable
     centenas=(i/100);  //Valor de centenas
     decenas=(i-(centenas*100))/10;  // valor de decenas
     unidades=(i-(centenas*100+decenas*10)); // valor unidades
    }
   else{
    i=0; // reset conteo
   
    unidades=0; // reset unidades
   decenas=0;  // reset decenas
    centenas=0;// reset centenas
  }
 
 digitalWrite(uni,HIGH); // activacion de pin de unidades
 digitalWrite(dec,LOW);  // desactivacion de pin de decenas
 digitalWrite(cent,LOW);
 contador(unidades);    // llamo metodo de visualizacion
 delay(100);  // espero
digitalWrite(uni,LOW);   // desactivacion de pin de unidades
 digitalWrite(dec,HIGH);  // activacion de pin de decenas
 digitalWrite(cent,LOW);
 contador(decenas);  // llamo metodo de visualizacion
 delay(100); // espero
 digitalWrite(uni,LOW);   // desactivacion de pin de unidades
 digitalWrite(dec,LOW);  // desactivacion de pin de decenas
 digitalWrite(cent,HIGH);  // activacion de pin de centenas
 contador(centenas);  // llamo metodo de visualizacion
 delay(100); 
}
// metodo de visualizacion de numero en display 

void contador (int j){
switch(j){
  //0
  case 0:
digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
//1
 case 1:
digitalWrite(A,HIGH);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
//2
case 2:
digitalWrite(A,LOW);
digitalWrite(B,HIGH);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
//3
case 3:
digitalWrite(A,HIGH);
digitalWrite(B,HIGH);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
//4
case 4:
digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
//5
case 5:
digitalWrite(A,HIGH);
digitalWrite(B,LOW);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
//6
case 6:
digitalWrite(A,LOW);
digitalWrite(B,HIGH);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
//7
case 7:
digitalWrite(A,HIGH);
digitalWrite(B,HIGH);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
//8
case 8:
digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,HIGH);
break;
//9
case 9:
digitalWrite(A,HIGH);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,HIGH);
break;
}
}
