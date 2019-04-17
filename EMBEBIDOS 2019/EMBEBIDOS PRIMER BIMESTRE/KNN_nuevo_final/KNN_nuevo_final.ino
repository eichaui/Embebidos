#include "datos.h"//matriz entrenamiento 
/*
   UNIVERSIDAD TECNICA DEL NORTE 
   FIC-CIERCOM 
   ALEXANDER ICHAU 
   KNN

*/
int col;
int fila=0;
float promedio=0;//determinar la distancia entre dos puntos 
float distancia; //formula de la distacia
float datos_entrada [5]={7.1,2.9,6.3,1.8,3};
int i=0;
int j;
int k=3;
float dist_menores [2][3];//ordenar distancias menores
float aux,aux1;
float num_etiquetas [2][3];
int l=0;
float respuesta;//imprimir etiqueta gananadora
float mayor=0;
void setup() {
 Serial.begin(9600);
  //llenar matriz distanias menores 
  for(;i<k;i++){
    dist_menores[0][i]=4000+i;
    dist_menores[1][i]=0;
    
    }
    i=0;
     for(;i<k;i++){
        num_etiquetas[0][i]=i+1;
        num_etiquetas[1][i]=0;
      }
      i=0;
}

void loop() {
 for(;fila<90;fila++){//ciclo lecturas filas
    for(col=0;col<4;col++){
   promedio=promedio+pow(datos_entrada[col]-matriz[fila][col],2);
      }
    distancia=sqrt(promedio); 
    promedio=0;
  //  Serial.println(distancia);
  if (distancia<dist_menores[0][k-1]){
    dist_menores[0][k-1]=distancia;
    dist_menores[1][k-1]=matriz[fila][4];
    
    }
  //ordenamiento vecto menor a mayor
  for(i=0;i<k;i++){
      for(j=i+1;j<k;j++){
        if(dist_menores[0][i]>dist_menores[0][j]){
          aux=dist_menores[0][i];
          dist_menores[0][i]=dist_menores[0][j];
          dist_menores[0][j]=aux;
          ///etiquetas
          aux1=dist_menores[1][i];
          dist_menores[1][i]=dist_menores[1][j];
          dist_menores[1][j]=aux1;   
          
          
          
          }   
        
        }
    
    }
  }
  //determinar el numero de cada etiqueta
  for(i=0;i<k;i++){
 //   Serial.println(dist_menores[0][i]);
      for(j=0;j<k;j++){
        if(num_etiquetas[0][i]==dist_menores[1][j]){
          num_etiquetas[1][i]=1+num_etiquetas[1][i];
          }
        }
    }  
for(;l<k;l++){
//  Serial.println(num_etiquetas[0][l]); //imprimir etiqueta
    if(num_etiquetas[1][l]>mayor){
      mayor=num_etiquetas[1][l];
      respuesta=num_etiquetas[0][l];
      }
  
  Serial.println(respuesta);
  delay(10000);
  }
}
