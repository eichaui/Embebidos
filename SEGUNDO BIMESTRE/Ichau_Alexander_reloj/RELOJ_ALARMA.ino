
/*
 *            UNIVERSIDAD TECNICA DEL NORTE
 *                FICA-CIERCOM
 *    ALEXANDER ICHAU
 *    SISTEMA MICROPROCESADOS
 *              RELOJ CON ALARMA
 */
#include <LiquidCrystal.h>
#include <MsTimer2.h>
LiquidCrystal lcd (13,12,11,10,9,8);
int h=0; 
int m=0; 
int s=0;
String ah1,ah2,am1,am2;//variables reloj y alarma de horas y minutos
String ah;
int i=0;
int leer_minutos;
int leer_hora;
int led=7;
int contador_alarma;
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  MsTimer2::set(1000,conteo);
  MsTimer2::start();
  pinMode(7,OUTPUT);
  attachInterrupt(7,pulsador,LOW);
  attachInterrupt(1,minuto,FALLING);
 

}
void loop() {
   lcd.clear();
  lcd.setCursor(2, 0);
    lcd.print("            ");
  lcd.print(ah2);
    lcd.setCursor(2, 0);
    lcd.print(":");
    lcd.setCursor(3, 0);
    lcd.print(am2);
   lcd.setCursor(5, 0);
    lcd.print(":");
     lcd.setCursor(8, 0);
    lcd.print("  ALARMA");
      lcd.setCursor(0,0);
  }

void contador(){
  segundos++;
  lcd.clear();
  lcd.setCursor(6,1);
  lcd.print(":");
  lcd.setCursor(9,1);
  lcd.print(":");
  if(h<24){
    lcd.setCursor(4,1);
    if(h<10)
      lcd.print("0");
   lcd.print(h);
  }else{
    h=0;
  }
  if(m<60){
    lcd.setCursor(7,1);
    if(m<10)
      lcd.print("0");
    lcd.print(m);
  }else{
    h++;
    m=0;
  }
  if(s<60){
    lcd.setCursor(10,1);
    if(s<10)
      lcd.print("0");
    lcd.print(s);
  }else{
    m++;
    s=0;
  }
  delay(80);
  Alarma();
}

void hora(){
  delay(30);
  if(h<24)
    h++;
   }

void minuto(){
  delay(30);
  if(m<60){
    m++;
   
  }
}

void Alarma(){
  if (Serial.available() > 0) {
    while (Serial.available() > 0) {
             
      ah1=Serial.readString();
      delay(200);
     ah2=leer_hora.toInt();
      
        }
    while (Serial.available() > 0) {
      am1 =Serial.readString();
        delay(200);
      am2= leer_minutos.toInt();    
      
  }
  }
    if(alarma ==true){
    
   
    
      if(s == 0 && ah1 == ah2 && am1 ==am2){
        digitalWrite(led, HIGH);
         Serial.println("Alarma on");     
        lcd.print("alarma on");
      }else{
        digitalWrite(led, HIGH);
         Serial.println("Alarma off");     
        lcd.print("alarma on");
      }
      
    }
      
    }

    if(contador_alarma==60){
      digitalWrite(led, LOW);
      contador_alarma=0;
    }
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
