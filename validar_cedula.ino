/*
            UNIVERSIDAD TECNICA DEL NORTE
                  FICA-CIERCOM
    Nombre:Alexander Ichau

 -Realizar un programa que permita ingresar el número de cédula con el guión
 y posteriormente validarlo. El dato se lo ingresa por comunicación serial. 
 */

long int cedula;
char ced[11];
char ced_val[11];
int i=0;
int region;
int udig;
int pares,impares;
int numero1,numero3,numero5,numero7,numero9;
int suma_total;
int digito_validador;
int  pdig_suma;
int decena;
void setup() {
 Serial.begin(9600);
  
Serial.println("Ingrese cedula");
  for (;i<11;i){
    if (Serial.available()>0){
      ced[i]=Serial.read();
      i++;
    }
}}

void loop() { 
  
  
  Serial.println(" ");
  if (Serial.available()>0){
      ced_val[i]=Serial.read();
      i++;
    }
 
    
  
  

}
void control(){
 if(cedula==11){
    region=cedula.substring(0,2);
    //Si la region existe ecuador divide en 24 regiones
    if(region>=1 || region<=24){
      udig=cedula.substring(10,11);
      }
    pares=parseInt(cedula.substring(1,2))+parseInt(cedula.substring(3,4))parseInt(cedula.substring(5,6))parseInt(cedula.substring(7,8))
    //Agrupo los impares, los multiplico por un factor de 2, si la resultante es > que 9 le restamos el 9 a la resultante
           numero1 = cedula.substring(0,1);
           numero1 = (numero1 * 2);
          if( numero1 > 9 ){ var numero1 = (numero1 - 9); }

           numero3 = cedula.substring(2,3);
           numero3 = (numero3 * 2);
          if( numero3 > 9 ){ var numero3 = (numero3 - 9); }

          numero5 = cedula.substring(4,5);
          numero5 = (numero5 * 2);
          if( numero5 > 9 ){ var numero5 = (numero5 - 9); }

           numero7 = cedula.substring(6,7);
           numero7 = (numero7 * 2);
          if( numero7 > 9 ){ var numero7 = (numero7 - 9); }

          var numero9 = cedula.substring(8,9);
          var numero9 = (numero9 * 2);
          if( numero9 > 9 ){ var numero9 = (numero9 - 9); } 
         impares = numero1 + numero3 + numero5 + numero7 + numero9;
        suma_total = (pares + impares);
        //extraemos el primero digito
          pdig_suma = String(suma_total).substring(0,1);

          //Obtenemos la decena inmediata
          decena = (parseInt(pdig_suma) + 1)  * 10;

          //Obtenemos la resta de la decena inmediata - la suma_total esto nos da el digito validador
          digito_validador = decena - suma_total;

          
        }
     }
    
    
  }}
void validacion(){
  Serial.println(" ");
  if(ced[0]==ced_val[0]||ced[1]==ced_val[1]||ced[2]==ced_val[2]||ced[3]==ced_val[3]
  ||ced[4]==ced_val[4]||ced[5]==ced_val[5]||ced[6]==ced_val[6]||ced[7]==ced_val[7]
  ||ced[8]==ced_val[8]||ced[9]==ced_val[9]||ced[10]==ced_val[10]){
    Serial.println("Verificando...");
    delay(250);
    Serial.println("Cedula correcta");
    Serial.println(" ");
  }else{
    Serial.println("Cedula incorrecta");
    Serial.println(" ");
  }
  //Si el digito validador es = a 10 toma el valor de 0
          if(digito_validador == 10)
            digito_validador = 0;

          //Validamos que el digito validador sea igual al de la cedula
          if(digito_validador == udig){
            Serial.println("la cedula:" + cedula + " es correcta");
          }else{
            Serial.println("la cedula:" + cedula + " es incorrecta");
          }
          
          }else{
          // imprimimos en consola si la region no pertenece
         Serial.println("La cedula no pertenece a ninguna region");
  
  }}}
  
