/*
 *              UNIVERSIDAD TECNICA DEL NORTE 
 *                      FICA-CIERCOM
 *  ALEXANDER ICHAU 
 * 22-01-2019 

 Realizar un programa que permita que el conversor análogo digital
 configure al perro guardían a 10,20,30 y 40 segundos.
 Este proceso se visualiza en una lcd.
 
 */
#include <MsTimer2.h>
#include <avr/wdt.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8); 

 float conv=0;
 int c;
 int contador;
int led=6;
 
void setup() {
 // wdt_disable();
Serial.begin(9600);
lcd.begin(16,2);
MsTimer2::set(500,conteo);
MsTimer2::start();
pinMode(led,OUTPUT);
}

void loop() {
    lcd.clear();
  conv=(analogRead(A0)*50)/1023;
  Serial.println("El valor del CAD es:");
  delay(600);
  Serial.println(conv);
  if(conv==10){
  lcd.setCursor(4,0);
lcd.println("Contador :");
lcd.setCursor(2,1);
lcd.println(contador);
    if(contador==6){
       wdt_enable(WDTO_4S);
       digitalWrite(led,HIGH);
            }
    }

        if(conv==20){
        contador++;
        if(contador==16){
           wdt_enable(WDTO_4S);
           digitalWrite(led,HIGH);
                }
        }

                        if(conv==30){
              contador++;
              if(contador==26){
                 wdt_enable(WDTO_4S);
                 digitalWrite(led,HIGH);
                      } }


                      
                        if(conv==40){
              contador++;
              if(contador==32){
                 wdt_enable(WDTO_8S);
                 digitalWrite(led,HIGH);
                      } }
             


}
void conteo(){
  if(conv==10)
contador++;
  if(conv==20)
contador++;
  if(conv==30)
contador++;
  if(conv==40)
contador++;
//lcd.setCursor(4,0);
//lcd.println("Contador :");
//lcd.setCursor(2,1);
//lcd.println(contador);

  }



