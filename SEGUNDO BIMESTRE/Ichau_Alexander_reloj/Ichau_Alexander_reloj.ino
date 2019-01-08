/*
 *              UNIVERSIDAD TECNICA DEL NORTE
 *                  FICA-CIERCOM
 *  ALEXANDER ICHAU
 *  SISTEMAS MICROPROCESADOS 
 *                  DEBER 1 SEGUNDO BIMESTRE 
 *                  
 *                      RELOJ
 */
#include <MsTimer2.h>
#include <LiquidCrystal.h>
#include <TimerOne.h>

LiquidCrystal lcd(13,12,11,10,9,8,7);
int h=0, m=0, s=0;
void setup() {
  Serial.begin(9600);
  lcd.begin(16,4);
  attachInterrupt(0,hor,LOW);
  attachInterrupt(1,minut,LOW);
   MsTimer2::set(1000,contador);
   MsTimer2::start();
   lcd.setCursor(2,0);
  lcd.print("***CLOCK***");
}

void loop() {
  funcionamiento();
}
void funcionamiento(){
    lcd.clear();  
  lcd.setCursor(6,1);
  lcd.print(":");
  lcd.setCursor(9,1);
  lcd.print(":");
  if(h<24){
    lcd.setCursor(5,1);
    if(h<10)
      lcd.print("0");
    lcd.print(h);
  }else{
    h=0;
  }
  if(m<60){
    lcd.setCursor(8,1);
    if(m<10)
      lcd.print("0");
    lcd.print(m);
  }else{
    h++;
    m=0;
  }
  if(s<60){
    lcd.setCursor(11,1);
    if(s<10)
      lcd.print("0");
    lcd.print(s);
  }else{
    m++;
    s=0;
  }
  }
void minut(){
    if(m<60)
    m++;
  else
    m=0;
}

void hor(){
    if(h<24)
    h++;
  else
    h=0;
}

void contador(){
  s++;
  Serial.println(s);
}

