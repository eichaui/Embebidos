/*
 *      UNIVERSIDAD TECNICA DEL NORTE
 *          FICA-CIERCOM
 * ALEXANDER ICHAU    
 * SISTEMAS MICROPROCESADOS 
 *      
 *      MEMORIA EEPROM
 */
 #include <EEPROM.h>
 String v;
 int n;
 
void setup() {
 Serial.begin(9600);  
  EEPROM.write(0, 0);

}

void loop() {
  memoria();

}
void memoria(){
    if (Serial.available() >= 0) {  //verifica si va a llegar dato por seria
    Serial.print("Ingrese datos ");//impresion
    delay(200); 
    v = Serial.readString();  //lee el valor ingresado String
    n = v.toInt();          //conversion String a int 
    if (EEPROM.read(0) < n) { 
      EEPROM.update(0, n); 
      Serial.print("El valor es: ");  
      Serial.println(EEPROM.read(0)); 
      delay(300);
    } else {
      Serial.println("ERROR INGRESE DATO NUEVAMENTE"); //mensaje de advertencia
      delay(300);
    } } 
  
  }
