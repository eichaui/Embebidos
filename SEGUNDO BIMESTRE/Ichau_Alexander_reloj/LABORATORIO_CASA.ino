/*                              UNIVERSIDAD TECNICA DEL NORTE
 *                           FICA-CIERCOM-SISTEMAS MICROPROCESADOS
 * Integrantes: Cuascota Henry
 *              Fernandez Sergio
 *              Ichau Alexander
 * Tema:
 */
#include <EEPROM.h>// Libreria Memoria EEPROM
#include <TimerOne.h>
#include <Keypad.h> //Libreria Teclado
#include <MsTimer2.h>  // Libreria del Timer Dos
#include <LiquidCrystal.h> //Libreria de la LCD
const byte ROWS = 3; //filas
const byte COLS = 3; //columnas
char hexaKeys[ROWS][COLS] = { //matriz teclado
{'1', '2', '3'},
{'4', '5', '6'},
{'7', '8', '9'},
};
byte rowPins[ROWS] = {4,3,2};
byte colPins[COLS] = {7,6,5};
char pwd [5]={'1','2','3','4','5'};
char pwdof [5]={'1','2','3','4','5'};
char usuario1 [5];
char usuarioof [5];
int A=13; //variable para LCD
int B=12; //variable para LCD
int C=11; //variable para LCD
int D=10; //variable para LCD
int E=9;  //variable para LCD
int F=8;  //variable para LCD
LiquidCrystal lcd(13,12,11,10,9,8); //  conf 
int horero=0; //Variable para las horas
int minutero=0; //Variable para los minutos
int segundos=0; //Variable para los segundos
int h=0;//variable de almacenamiento de datos
int i=0;
int a=0;
int j=0;
int m=0;
int posicion=0; // contador de posicion
int mostrador=0;
int ldrvent_1=A0;
int ldrpuerta=A1;
int ldrvent_2=A2;
int contador=0;
int alerta=A3;
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
void setup() {
  Serial.begin(9600); 
  pinMode(alerta,OUTPUT);
  lcd.clear();
  lcd.begin(16,2); // Inicializacion de la LCD
  MsTimer2::set(1000,reloj); // Timer 1seg con un metodo
  MsTimer2::start();//Inicio del timer
  for(;posicion<=255;posicion++ ){ // Contador para encerar la memoria EEPROM
     EEPROM.write(posicion,0);
     delay(1);
}}

void loop() {
  funcionamiento();
    } 
 //-----------------------------------------Metodo CONTEO---------------------------   
void conteo(){
  contador++;//activa contadr
  if(contador>=25){//condicion contador
     mostrador=1;
    if(mostrador==1){//valida mostrador
      Serial.println("Sensores Activados");//mensaje serial
      lcd.setCursor(9,1);//posicion lcd
      lcd.print("A-ON");//mensaje lcd
    }
    sensores();//llama metodo sensores
  }
  }
 //---------------------------------------FUNCIONAMIENTO CONTRA--------------------------   
void funcionamiento(){
  if(h==0){
    char customKey = customKeypad.getKey();//obtiene los datos 
    if (customKey != NO_KEY) {//valida la clave
        usuario1[i]=customKey;//si es correcta la clave
        i++;}//
    }
    if(i==5){
     if(usuario1[0]==pwd[0]&&//validacion de contrasena
        usuario1[1]==pwd[1]&&//validacion de contrasena
        usuario1[2]==pwd[2]&&//validacion de contrasena
        usuario1[3]==pwd[3]&&//validacion de contrasena
        usuario1[4]==pwd[4]){
        a=0;
       Serial.println("CONT-CORRECTA");//mensaje
       Timer1.initialize(100000);
       Timer1.attachInterrupt(conteo);
       m++;
       i=0;}
       }
       if(m==1){
        Serial.println("Inicio conteo");//mensaje
          m=0;
          h++;
       }
       
       if(h==1){//apaga alarmas
        char customKeyof = customKeypad.getKey();//verifica clave para activar alarma
    if (customKeyof != NO_KEY) {
        usuarioof[a]=customKeyof;
        a++;
    }
    }
    
    if(a==5){
     if(usuarioof[0]==pwdof[0]&&//validacion de contrasena
        usuarioof[1]==pwdof[1]&&//validacion de contrasena
        usuarioof[2]==pwdof[2]&&
        usuarioof[3]==pwdof[3]&&
        usuarioof[4]==pwdof[4]){
        contador==0;
        mostrador==0;
        m==0;
        ldrvent_1=10;
        ldrpuerta=10;
        ldrvent_2=10;  
       Serial.println("Alarmas Apagadas");//mensaje
       digitalWrite(alerta,LOW);
       lcd.setCursor(9,1);
       lcd.print("A-OF");
       h=0;
       }
      }
      }
//--------------------------------SENSORES-------------------------------
void sensores(){
   ldrvent_1=(analogRead(A0)*9)/1024; //conversor analogo digital para sensores
   ldrpuerta=(analogRead(A1)*9)/1024;//conversor analogo digital para sensores
   ldrvent_2=(analogRead(A2)*9)/1024;//conversor analogo digital para sensores
   if(ldrvent_1<=3){//condicion de voltaje para verificar ventaja 
    Serial.println("ALERTA VENTANA 1 ABIERTO");//mensaje
    digitalWrite(alerta,HIGH);
    delay(500);
   }
   delay(500);
   if(ldrpuerta<=3){
    Serial.println("ALERTA PUERTA ABIERTA");//mensaje 
    digitalWrite(alerta,HIGH);//alarma
    delay(500);
   }
   if(ldrvent_2<=3){
    Serial.println("ALERTA VENTANA 2 ABIERTO");//mensaje
    digitalWrite(alerta,HIGH);//alarma
    delay(500);
   }
   
}
//--------------------------------------RELOJ---------------------------
void reloj(){
  lcd.clear(); //Limpieza de la LCD
  lcd.setCursor(0,0); //Posicion para la impresion
  lcd.print("La Hora Es:"); // Caracteres a imprimir
  if(segundos<59){
      segundos++;
    }
    else{
         if(minutero<59){
           minutero++;
           EEPROM.write(0,minutero);
           segundos=0;
          }
          else{
              if(horero<24){
                horero++;
                EEPROM.write(1,horero);
                minutero=0;
                }
                else{
                   horero=0;
                  }
            }
      }

      if(horero<24){ //condicion Horero
        lcd.setCursor(0,1); //Posicion para la impresion
        if(horero<10) //condicion horero menor a 10
        lcd.print("0"); //Caracter a imprimir
        lcd.print(horero); //Variable a imprimir
        }
        lcd.setCursor(2,1);  //Posicion a imprimir
        lcd.print(":"); // Caracter a imprimir
        if(minutero<60){ //condicion minutero
        lcd.setCursor(3,1); //Posicion para la impresion
        if(minutero<10) // condicion minutero menor a 10
        lcd.print("0"); // Caracter a imprimir
        lcd.print(minutero); //Variable a imprimir
        }
        lcd.setCursor(5,1); //Posicion para la impresion
        lcd.print(":"); // Caracter a imprimir
        if(segundos<60){ //Condicion del segundero
        lcd.setCursor(6,1); //Posicion para la impresion
      if(segundos<10) //Condicon del segundero menor a 10
        lcd.print("0");  // Caracter a imprimir
        lcd.print(segundos); //Variable a imprimir
        }}
