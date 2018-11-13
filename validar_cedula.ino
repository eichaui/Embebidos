/*
            UNIVERSIDAD TECNICA DEL NORTE
                  FICA-CIERCOM
    Nombre:Alexander Ichau

 -Realizar un programa que permita ingresar el número de cédula con el guión
 y posteriormente validarlo. El dato se lo ingresa por comunicación serial. 
 */

char cedula;
char ced[11];
char ced_val[11];
int i=0;
int lv_prov;
int lv_numced;
int ll_TenDig;
int ll_sum=0;
int ll_Cnt=0;
int ll_CntPos=0;
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
   validacion();
    
  
  

}
void control(){
// Control de provincia entre 1 y 24
  if ( lv_prov>=1 && lv_prov<=24) {
 
 lv_numced=cedula;
//  ll_TenDig=Number(cedula.substring(9,10));
    ll_sum=0;
    ll_Cnt=0;
    ll_CntPos=0;
    
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
  }}
