#include <MsTimer2.h>
#include <EEPROM.h>
#include <avr/wdt.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8); 

/*              UNIVERSIDAD TECNICA DEL NORTE
 *                  FICA-CIERCOM
 *  ALEXANDER ICHAU
 *  22-01-2019
 *  
 *  
        Se necesita emular el funcionamiento de un control de auto ChevyStar.
        Para ello, se tienen las siguientes características.
    • Se cuenta con 4 botones, uno máster y 3 para la contraseña.
    • La contraseña es de 5 dígitos que debe ser la combinación de los 3 botones.
    • El sistema al presionar una vez (solo botón máster) y sin contraseña envía por comunicación serial el mensaje de activado o desactivado.
    • Si es digitada la contraseña es correcta (se presiona la combinación de los 3 botones y luego el máster),
    envía por mensaje serial que se puede encender el carro. Caso contrario, se tendrá hasta 2 intentos más para acertar a la contraseña. Si no es el caso, 
    el control se reinicia y genera otra contraseña de forma aleatoria de la combinación de los pulsadores. 
    La nueva contraseña se envía por comunicación serial
 * 
 */
 
 char dato;
int clave[5];
int datosC[5]={4,5,6,4,7};
 int led=6;
 int p=4;//p clave
 int p_1=5;//p clave
 int p_2=6;//p clave
 int p_3=7;//master
  int pulsador=4;
 int pulsador_1=5;
 int pulsador_2=6;
 int pulsador_3=7;
 int contador=0,incorrecto=0,estados=0,co=0;
 int i=0;
 int  v=0;
 int k=0;
 int pos=0;
 int intentos=2;
 int g;
 int h;
 int j;
 
 void setup() {
 EEPROM.write(0,datosC); 
 lcd.begin(16,2);
Serial.begin(9600) ;
pinMode(p,INPUT);  
pinMode(p_1,INPUT);
pinMode(p_2,INPUT);
pinMode(p_3,INPUT);
//MsTimer2::set(1000,conteo);
MsTimer2::start();
 impresionD();
}

void loop() {
  if(digitalRead(p_3)==HIGH){
    Serial.println("Boton master pulsado");
    }
     
    if(estados==1){
                
         Serial.print("Sistema ON   ");
         delay(1000);
         i=1;
      }
    
      
if(estados==2){
   if(v==0){
    Serial.print("Verificando...     ");
   Serial.print("             ");
     delay(1000);
     v=1;
     validarC();
   }
  }
}
void eventos(){
if(estados==1){
     switch(contador){
      case 0:
     Serial.print(dato);
      delay(200);
      clave[contador]=dato;
      contador++;
      break;
      
      case 1:
      Serial.print(dato);
      delay(200);
      clave[contador]=dato;
      contador++;
      break;
      
      case 2:
      Serial.print(dato);
      delay(200);
      clave[contador]=dato;
      contador++;
      break;
      
      case 3:
     Serial.print(dato);
      delay(200);
      clave[contador]=dato;
      contador=0;
      break;
      }
    }
}


if(estados==2){
    switch(contador){
      case 0:
      Serial.print(dato);
      datosC[contador]=dato;
      contador++;
      break;
      
      case 1:
     Serial.print(dato);
      datosC[contador]=dato;
      contador++;
      break;
      
      case 2:
     Serial.print(dato);
     datosC[contador]=dato;
      contador++;
      break;
      
      case 3:
      Serial.print(dato);
      datosC[contador]=dato;
      contador=0;
      break;
      }
    }
}

}

  
  void impresionD(){
  Serial.println("El boton 1 master");
  delay(500);
  Serial.println("Boton 2,3,4 son de ingreso de contrasena");
  delay(500);
  } 
void clavee() {
 if (digitalRead(p) == HIGH) {
datosC[pos] = pulsador;
EEPROM.update();
pos++;
delay(500);
}

if (digitalRead(p_1) == HIGH) {
datosC[pos] = pulsador_1;
pos++;
delay(500);
}
if (digitalRead(p_2) == HIGH) {
datosC[pos] = pulsador_2;
pos++;
delay(500);
}
if (digitalRead(p_3) == HIGH) {
datosC[pos] = pulsador_3;
pos++;
delay(500); }
  
}    

void validarC(){
  if(v==1){
  if(pos==5){
  if(clave[0]==datosC[0]&&clave[1]==datosC[1]&&clave[2]==datosC[2]&&clave[3]==datosC[3]&&clave[4]==datosC[4]){
      Serial.print("CORRECTA..     ");
     Serial.print("               ");
     Serial.println("Puede encender el carro");
      incorrecto=0;
      intentos=2;
      }}
      else{
      incorrecto++;
      Serial.println("INCORRECTA...   ");
      if(incorrecto==1&&k==0){
      Serial.println("Primer int.     ");
      delay(500);           
      estados=1;
      v=0;
      }
      if(incorrecto==2&&k==0){
      Serial.print("Segundo int.");
      delay(1000);
      estados=1; 
      v=0;
       k=1;
       Serial.println("Ingrese nueva contrasena");
      g=(random(5,7));
      h=(random(5,7)) ;
      j=( random(5,7)) ;
      datosC[]={g};
      datosC[]={h};
      datosC[]={j};
      datosC[]={g};
      datosC[]={h};
      
      
      }    
      
      if(k==1){
     Serial.print("Sist. reiniciara     ");
     conteo();
    wdt_reset();
        }
        }  
  }}
  void conteo(){
  co++;
  lcd.setCursor(0,0);
  lcd.println(co);
  }


