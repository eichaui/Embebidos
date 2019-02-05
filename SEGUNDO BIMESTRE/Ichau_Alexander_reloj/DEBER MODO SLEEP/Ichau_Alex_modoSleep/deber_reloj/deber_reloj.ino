/*UNIVERSIDAD TÉCNICA DEL NORTE
   FICA-CIERCOM
   ALEXANDER ICHAU
   
   Realizar un reloj mediante el uso de timers con el menor coste computacional
*/
#include <LiquidCrystal.h>   //usamos esta libreria para que pueda funcionar el LCD
#include <LowPower.h>
#include <LiquidCrystal.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <MsTimer2.h>
LiquidCrystal lcd(8,9,10,11,12,13);
int ss = 00;   //inicializamos los segundos en 0
int mm = 07;  //ponemos los minutos que son ahora, justo en el instante
int hh = 9;  // lo mismo, la hora

void setup()
{
   Serial.begin(9600);
  lcd.begin(16,2);    //esta funcion signifca empezar
}

void loop()
{
  
 reloj();
 dormir();
}
void reloj(){ for(ss=0;ss<60;ss++){     //los segs van de 0 a 60 una y otra vez y durante este periodo:
    lcd.clear();            //esta funcion nos permite borrar la pantalla
    lcd.setCursor(2,0);     //columna 2, fila primera
    lcd.print("Hrs");       //nos imprime los caracteres de horas en  el LCD

    lcd.setCursor(2,1);     //columna 2, fila segunda
    lcd.print(hh);

    lcd.setCursor(5,1);     //columna 5, fila segunda
    lcd.print(":");

    lcd.setCursor(7,0);
    lcd.print("Min");

    lcd.setCursor(7,1);
    lcd.print(mm);

    lcd.setCursor(10,1);
    lcd.print(":");

    lcd.setCursor(11,0);
    lcd.print("Seg");

    lcd.setCursor(12,1);
    lcd.print(ss);

    delay(1000);
  }
    if(ss > 59){     //si los segundos pasan a 60, automaticamente
      ss = 00;       //los segundos vuelven a 0
      mm = mm+1;}    //se aumenta los minutos una unidad cada vez

      if(mm > 59){   //si los minutos pasan a 60, automaticamente
        mm = 00;     //los minutos vuelven 0
        hh = hh+1;}  //se aumenta la hora en una unidad cada vez

        if (hh == 24){  //si llega a 24, automaticamente
          hh = 00;      //pasa todo a 0
          mm = 00;
          ss = 00;
    }}
    void dormir(){
//power_adc_enable ();
power_spi_enable ();
power_usart0_enable (); 
power_timer0_enable (); 
power_twi_enable ();}
