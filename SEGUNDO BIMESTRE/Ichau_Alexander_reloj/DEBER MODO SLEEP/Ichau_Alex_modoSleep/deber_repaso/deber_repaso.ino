#include <avr/sleep.h>
#include <LowPower.h>
#include <MsTimer2.h>
/*
 * UNIVERSIDAD TECNICA DEL NORTE 
 *    FICA CIERCOM
 *   ALEXANDER ICHAU
 *   
 *   
 *   Realizar un sistema que permita configurar por 
comunicación serial o por pulsadores el modo sleep cada 25 segundos.

 */
int cont=0;
float cad=0;
int A=0;
String dato;
int d;
void setup() {
Serial.begin(9600);
   MsTimer2::set(1000, conteo);
  MsTimer2::start();
  Serial.println(cont);

}

void loop()   { 
  

  for(int i=0;i<4;i++){  
 LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);    
  if(Serial.available()>0){
    Serial.print("Ingrese dato");
   dato=Serial.readString();
    d=dato.toInt();
    }   
 }}

   void conteo(){
    cont++;   
    }

 
