/*
                          UNIVERSIDAD TECNICA DEL NORTE 
                                   FICA-CIERCOM 
                              SISTEMAS MICROPROCESADOS 
     NOMBRE:ALEXANDR ICHAU

                                  DEBER

  Realizar un sistema que permite determinar el número de vocales dentro de una palabra. 
  Este dato es ingresado por comunicación serial y la respuesta del mismo de igual manera
 */
String valor;
int con_A=0,con_a=0;//Variables contador mayusculas minusculas 

void setup() {
Serial.begin(9600);

}

void loop() {
  if (Serial.available()) //Obtenga la cantidad de bytes (caracteres) disponibles para leer desde el puerto serie. Se trata de datos que ya han llegado y se han almacenado en el búfer de recepción en serie. available () hereda de la clase de utilidad Stream .
  {
    valor = Serial.read();//variable para leer en serial
  if(valor=='65' && valor=='69' && valor=='73' && valor=='79' && valor=='85') //condicion si valor es igual a 65=A por codigo asccii
     {con_A++; //habilita conteo mayusculas 
     Serial.println(" ");//ingresar datos
     delay(300); 
     Serial.println("el numero de vocales es");//mensaje
    Serial.println(con_A);//imprime las letras mayu
     Serial.print(con_A++);
     }
  
     if(valor=='97' && valor=='101' && valor=='105' && valor=='111' && valor=='117')//condicion si valor es igual a 97=a por codigo ascii
     {con_a++;//habilita conteo minusculas
     Serial.println(" ");//ingresar datos
     delay(300); 
     Serial.println("el numero de vocales es");//mensaje
    Serial.println(con_a);//imprime letras minusculas
     Serial.println(con_a++);
     }    
     
   
  }
  
 }
   

 

