/*
 *      UNIVERSIDAD TECNICA DEL NORTE
 *          FICA-CIERCOM
 * ALEXANDER ICHAU    
 * SISTEMAS MICROPROCESADOS 
 *      
 *      MEMORIA EEPROM
 */
 #include <EEPROM.h>
 
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
void memoria(){
    if (Serial.available() >= 0) {  //comprobar si hay algo en la CX serial
    Serial.print("Ingrese el valor a guardar entre 0 y 255: "); //mensaje de informacion
    delay(500); 
    var = Serial.readString();  //Tomar valor del monitor serie
    num = var.toInt();          //convertir string a int
    if (EEPROM.read(0) < num) { //condicion para guardar informacion
      EEPROM.update(0, num);    //actualizar la EEPROM en la posicion 0
      Serial.print("El valor guardado en la EEPROM es: ");  //mensaje de confirmacion
      Serial.println(EEPROM.read(0)); //Impresion por serial del valor en la EEPROM
      delay(100);
    } else {
      Serial.println("No puede ingresar letras o el valor es igual o menor al guardado. "); //mensaje de advertencia
      delay(100);
    }
  }
  
  
  }
