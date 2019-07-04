#include <TimerOne.h>
/*
 *        UNIVERSIDAD TECNICA DEL NORTE 
 *            FICA-CIERCOM 
 *      ALEXANDER ICHAU
 *      
 *      DEBER EMBEBIDOS
 */
float conversor;
float dato=A0;
float conv;
float dato_1=A1;
void setup() {
  Serial.begin(9600);
   Serial.begin(9600);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(conteo);
}

void loop() {
   conv=(analogRead(dato)*9)/1023;
  Serial.println("El dato del CAD 1 es:");
  delay(500);
  Serial.println(conv);
   delay(500);
  conversor=(analogRead(dato_1)*9)/1023;
  Serial.println("El dato del CAD 2 es:");
  delay(500);
  Serial.println(conversor);
   delay(500);


  
if(dato>0 && dato<=3){
  Serial.println("Verde");
  
  }  
if(conv>3 && conv<=6){
  Serial.println("Naranja");
  delay(500);
  } 
   if(conv>6 && conv<=9){
  Serial.println("Rojo");
   delay(500);
    }
    if(conversor>0 && conversor<=3){
  Serial.println("Verde");
   delay(500);
  
  }  
if(conversor>3 && conversor<=6){
  Serial.println("Naranja");
   delay(500);
    } 
   if(conversor>6 && conversor<=9){
  Serial.println("Rojo");
     delay(500);
    }
  }


void conteo(){
   
    Serial.print(random(100));
    }

