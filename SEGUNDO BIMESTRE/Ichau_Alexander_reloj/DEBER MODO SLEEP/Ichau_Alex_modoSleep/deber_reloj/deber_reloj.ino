#include <TimerOne.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13); 
#include <LowPower.h>
#include <LiquidCrystal.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <MsTimer2.h>

/*UNIVERSIDAD TÉCNICA DEL NORTE
   FICA-CIERCOM
   ALEXANDER ICHAU
   
   Realizar un reloj mediante el uso de timers con el menor coste computacional
*/
int Sec = 0;
int Min = 0;
int Hor = 0;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  MsTimer2::set(1000,contador);
  MsTimer2::start();
  attachInterrupt(1,hor,FALLING);
  attachInterrupt(0,minu,HIGH);
    
  set_sleep_mode(SLEEP_MODE_PWR_SAVE);
  sleep_enable();
}

void loop() {
dormir();
}
void dormir(){
sleep_mode();
power_adc_enable ();
power_spi_enable ();
power_usart0_enable (); 
power_timer0_enable (); 
power_twi_enable ();
}
void contador(){
  lcd.clear();
  if(Hor<10){
    lcd.setCursor(0, 0);
    lcd.print(0);
    lcd.setCursor(1,0);
    lcd.print(Hor);
  } 
  else{
    lcd.setCursor(0,0);
    lcd.print(Hor);
  }
  lcd.setCursor(2, 0);
  lcd.print(":");

  if(Min< 10){
    lcd.setCursor(3,0);
    lcd.print(0);
    lcd.setCursor(4,0);
    lcd.print(Min);
  }
  else{
    lcd.setCursor(3, 0);
    lcd.print(Min);
  }
  lcd.setCursor(5, 0);
  lcd.print(":");

  if(Sec< 10){
    lcd.setCursor(6,0);
    lcd.print(0);
    lcd.setCursor(7,0);
    lcd.print(Sec);
  }
  else{
    lcd.setCursor(6,0);
    lcd.print(Sec);
  }
 
  Sec++;
    if(Sec == 60){
      Min++;
      Sec = 0;
    }
    if (Min == 60){
      Hor++;
      Min = 0;
    }
    if(Hor==24){
      Hor=0;
      Min=0;
      Sec=0;
    }
}

  void hor(){
    lcd.setCursor(0,1);
    lcd.print("Ingrese Hora ");
    Hor++; 
    lcd.setCursor(14,1);
    lcd.print(Hor);
    delay(1000);
}
    void minu(){
    lcd.setCursor(0,1);
    lcd.print("Ingrese Min ");
    Min++; 
    lcd.setCursor(14,1);
    lcd.print(Min);
    delay(1000);
    }
