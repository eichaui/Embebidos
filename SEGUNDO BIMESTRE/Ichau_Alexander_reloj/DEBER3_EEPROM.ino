/*
 *      UNIVERSIDAD TECNICA DEL NORTE
 *          FICA-CIERCOM
 * ALEXANDER ICHAU    
 * SISTEMAS MICROPROCESADOS 
 *      
 *      MEMORIA EEPROM
 */
 #include <EEPROM.h>
 String v;//variable de dato a ingresar
 int p;//variable posicion de la memoria 
 int d;//valor guardado en la memoria
 
void setup() {
 Serial.begin(9600);  
  EEPROM.write(0, 0);

}

void loop() {
  memoria();

}
void memoria(){
    if (Serial.available() >= 0) {  //verifica si va a llegar dato por seria
    Serial.println("Ingrese datos ");//impresion
    delay(200); 
    v = Serial.readString();  //lee el valor ingresado String
    p= v.toInt();          //conversion String a int 
     d=EEPROM.read(0);   
     if (d < p) { 
      EEPROM.update(0, p); //actualiza los valores de la memoria 
      Serial.println("El valor es: ");  
      Serial.println(EEPROM.read(0)); // imprime valor guardado en la memoria 
      delay(300);
    } 
     else {
      Serial.println("ERROR INGRESE DATO NUEVAMENTE"); //mensaje de advertencia
      delay(300);
    } } 
  
  }
