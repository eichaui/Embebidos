#include <avr/sleep.h>
#include <LowPower.h>
#include <MsTimer2.h>
/*
 * UNIVERSIDAD TECNICA DEL NORTE 
 *    FICA CIERCOM
 *   ALEXANDER ICHAU
 *   
 *   
 *  realizar un programa que permita poner  al sistema 19 segundos en modo sleep, se despierte, realice un lectura
      del conversor análogo digital, lo imprima por comunicación serial y vuelva a dormir 19 segundos

 */
int cont=0;
float cad=0;
int A=0;

void setup() {
Serial.begin(9600);
   MsTimer2::set(500, conteo);
  MsTimer2::start();
  Serial.println(cont);

}

void loop()   { 
  
if(cont==19){
  for(int i=0;i<6;i++){  
 LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);    
     
   }Serial.println(cad);}}

   void conteo(){
     cad=(analogRead(A0));
    cont++;
    //Serial.println(cad);
   
    }
