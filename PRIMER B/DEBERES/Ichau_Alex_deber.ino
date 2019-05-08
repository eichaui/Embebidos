#include "BASEDATOS.h"
/*
 *      UNIVERSIDAD TECNICA DEL NORTE 
 *          FICA-CIERCOM
 *    ALEXANDER ICHAU 
 *    SISTEMAS EMBEBIDOS 
 *        DEBER REGRESION LINEAL SIMPLE
 */
float sum_x,sum_y,sum_xy,sum_x2;//VARIABLES DE SUMATORIAS 
int col=0;//VARIABLE COLUMNAS 
int fil=0;//VARIABLE FILAS
int i=0;
//segundo caso variables
float prom_x;//VVARIABLE PARA CALCULAR EL PROMEDIO
float prom_y;//VARIABLE PARA CALCULAR EL PROMEDIO EN LAS VARIABLES DE Y
float xi_promedio;
float yi_promedio;
float xi2_promedio[29];
float yi2_promedio;
float xiyi;
float SSxy;
float SSxx;
float pendiente;
float ordenada_Bo ;
float xi_prom[29];
float yi_prom[29];
float xy[29];
float Ssxx[29];


void setup() {
Serial.begin(9600);

}

void loop() {
 for(;fil<29;fil++){
   sum_x=sum_x+matriz[fil][0];
   sum_y=sum_y+matriz[fil][1];  
  }
  prom_x=sum_x/29;
  prom_y=sum_y/29; 
 for(fil=0  ;fil<29;fil++){
    xi_prom[fil]=matriz[fil][0]-prom_x;
    yi_prom[fil]=matriz[fil][1]-prom_y; 
    xy[fil]=xi_prom[fil]*yi_prom[fil];
    xi2_promedio[fil]=xi_prom[fil]*xi_prom[fil]; 
    SSxy=SSxy+xy[fil]; 
    SSxx=SSxx+xi2_promedio[fil];// 
  }
pendiente=SSxy/SSxx;//PENDIENTE
ordenada_Bo=(prom_y-pendiente*prom_x);//FUNCION 
Serial.println("Bo=y-B1x");
Serial.print("y=");
Serial.println(pendiente);
Serial.print("x=");
Serial.println(ordenada_Bo); 
delay(50000);

}
