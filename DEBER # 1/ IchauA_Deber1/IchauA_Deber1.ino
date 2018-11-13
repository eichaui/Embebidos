/*
 *                          UNIVERSIDAD TECNICA DEL NORTE
                                    FICA-CIERCOM 
                               SISTEMAS MICROPROCESADOS
 NOMBRE: ALEXANDER ICHAU                              

                                DEBER 1 
                                PUERTOS SALIDA 
  
 1.- Realizar un juego de lueces que se prendan secuencialmente los leds impartes (1,3,5). 

                  CODIGO
*/
int juego[6]={8,9,10,11,12,13};  //crear vector con todas las salidas para las luces 
int i=0; //variable para el ciclo for

void setup() {
for(;i<6;i++){
  pinMode(juego[i],OUTPUT);   //dar la instruccion si son de salida 
  } i=0;  

}

void loop() {
 for(int i=;i<6;i=i+2){   // for inicializado en la primera posicion impar que es 1 por en el i=1 
  digitalWrite(juego[i],HIGH);  
  delay(600);  
    } i=0;
   for(int i=1;i<6;i=i+2){    
  digitalWrite(juego[i],LOW);     
   }i=0;
  for(int i=1;i<6;i=i+2){   // for inicializado en la primera posicion impar que es 1 por en el i=1 
  digitalWrite(juego[i],HIGH);  
  delay(600);  
    } i=0;
   } 

    

int valor;
int j;
int k;


//------------------------------------------------------------------------------------------------------------------------------------


/*      
         2.- Realizar un programa que se enciendan uno por uno los leds pares (0,2,4). 
                          CODIGO

 int juego_2[6]={8,9,10,11,12,13};  //crear vector con todas las salidas para las luces 
int i=0; //variable para el ciclo for

void setup() {
for(;i<6;i++){
  pinMode(juego_2[i],OUTPUT);   //dar la instruccion si son de salida 
  } i=0;  

}

void loop() {
 for(;i<6;i=i+2){
  digitalWrite(juego_2[i],HIGH);  
  delay(300);  
  } i=0;  
}
*/

//-------------------------------------------------------------------------------------------------------------------------------------
/*
 3.- Realizar un juego que se enciendan y apaguen los leds de forma aleatoria.  */
 
int juego_3[6]={8,9,10,11,12,13};  //crear vector con todas las salidas para las luces 
int i=0; //variable para el ciclo for




void setup() {
for(;i<6;i++){
  pinMode(juego_3[i],OUTPUT);   //dar la instruccion si son de salida 
  } i=0;  

}
void loop() {
 for(;i<6;i++){
  digitalWrite(juego_3[random(6)],HIGH);  
  delay(300);  
  } i=0;  
  for(;i<6;i++){
  digitalWrite(juego_3[random(6)],LOW);  
  delay(300);  
  } i=0; 
}

    
     


