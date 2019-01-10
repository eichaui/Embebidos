#include <LiquidCrystal.h>
#include <TimerOne.h>
#include <MsTimer2.h>
#include <EEPROM.h>
/*
 *            UNIVERSIDAD TECNICA DEL NORTE
 *                FICA-CIERCOM
 *    ALEXANDER ICHAU
 *    SISTEMA MICROPROCESADOS
 *              RELOJ CON ALARMA
 */
LiquidCrystal lcd (13,12,11,10,9,8);
int horas=0; 
int minutos=0; 
int segundos=0;
char ahora1,ahora2,aminuto1,aminuto2;
char ahora;
int i=0;
int leer_minutos;
int leer_hora;
int led=7;
int contador_alarma;
int alarma;
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  MsTimer2::set(1000,conteo);
  MsTimer2::start();
  pinMode(7,OUTPUT);
  attachInterrupt(7,pulsador,LOW);
   attachInterrupt(0,hora,FALLING);
  attachInterrupt(1,minuto,FALLING);
 

}
void loop() {
   lcd.clear();
  lcd.setCursor(2, 0);
    lcd.print("            ");
  lcd.print(ahora2);
    lcd.setCursor(2, 0);
    lcd.print(":");
    delay(400);
    lcd.setCursor(3, 0);
    lcd.print(aminuto2);
    delay(400);
    lcd.setCursor(5, 0);
    lcd.print(":");
    delay(400);
    lcd.setCursor(8, 0);
    lcd.print("  ALARMA");
    delay(400);
    lcd.setCursor(0,0);
  }

void contador(){
  segundos++;
  lcd.clear();
  lcd.setCursor(6,1);
  lcd.print(":");
  lcd.setCursor(9,1);
  lcd.print(":");
  if(horas<24){
    lcd.setCursor(4,1);
    if(horas<10)
      lcd.print("0");
   lcd.print(horas);
  }else{
    horas=0;
  }
  if(minutos<60){
    lcd.setCursor(7,1);
    if(minutos<10)
      lcd.print("0");
    lcd.print(minutos);
  }else{
    horas++;
    minutos=0;
  }
  if(segundos<60){
    lcd.setCursor(10,1);
    if(segundos<10)
      lcd.print("0");
    lcd.print(segundos);
  }else{
    minutos++;
    segundos=0;
  }
  delay(80);
  Alarma();
}

void hora(){
  delay(30);
  if(horas<24)
    horas++;
   }

void minuto(){
  delay(30);
  if(minutos<60){
    minutos++;
   
  }
}

void Alarma(){
  if (Serial.available() > 0) {
    while (Serial.available() > 0) {
             
      ahora1= Serial.read(); //leer palabras
     ahora2=leer_hora;
        }
    while (Serial.available() > 0) {
      aminuto1 = Serial.read(); //leer palabras
      aminuto2= leer_minutos;    
      
  }
  }
    if(alarma ==true){
    
   
    
      if(segundos == 0 && ahora1 == ahora2 && aminuto1 ==aminuto2){
        digitalWrite(led, HIGH);
              
        lcd.print("alarma on");
      }
      
    }else{
      
    }

    if(contador_alarma==60){
      digitalWrite(led, LOW);
      contador_alarma=0;
    }
  
  
  }



void hora1(){
if(Serial.available()){
  ahora1 = Serial.read()-48;
 }
 
}

void hora2(){
if(Serial.available()){
  ahora2 = Serial.read()-48;
 }
 
}void minuto1(){
if(Serial.available()){
  aminuto1 = Serial.read()-48;
 }
 
}
void minuto2(){
if(Serial.available()){
  aminuto2 = Serial.read()-48;
 }
 
}
void conteo(){
i++;
}

void pulsador(){
 Serial.print("Tiempo:");
 Serial.println(i);
  if(i<20)  
  i=0;
 Serial.print("Presione pulsador");
  }
