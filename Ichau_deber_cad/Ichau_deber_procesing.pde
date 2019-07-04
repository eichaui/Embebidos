/*
 *        UNIVERSIDAD TECNICA DEL NORTE 
 *            FICA-CIERCOM 
 *      ALEXANDER ICHAU
 *      
 *      DEBER EMBEBIDOS
 */
import controlP5.*;
import processing.serial.*;
Serial port;
ControlP5 cp5;
int con=0;

int on=0;
String envio;
String dato;
int conv;
int conversor;

void setup() {
  size(900, 700);
  noStroke();
  background(0);
  cp5=new ControlP5(this);
  
  cp5.addButton("CONEXION")
    .setPosition(340, 50)
    .setSize(200, 80)
    .setColorBackground(color(205, 235, 0));
    
  cp5.addSlider("CAD1")
    .setPosition(320, 300)
    .setSize(50, 205)
    .setColorForeground(color(5, 65, 56))
    ;
    
    cp5.addSlider("CAD2")
    .setPosition(470, 300)
    .setSize(50, 205)
    .setColorForeground(color(5, 145, 77))
    ;
}

void draw() {


  background(0);
  fill(0, 255, 0);
  ellipse(195, 200, 10, 10);
  fill(255, 255, 0);
  ellipse(420, 200, 10, 10);
  fill(255, 0, 0);
  ellipse(630, 200, 10, 10);
  textSize(12);
  fill(255);
  text("VERDE (<30)", 150, 180);
  text("NARANJA (>30 & <60)", 380, 180);
  text("ROJO (>60)", 600, 180);


  if (con==1) {
    if (port.available()>0) {
      dato=port.readString();
      conv=int(dato);
      conversor=int(dato);
      cp5.getController("CAD1").setValue(conv);
      
      cp5.getController("CAD2").setValue(conversor);

      if (conv>0 &&conv<10) {
        cp5.getController("CAD1").setColorForeground(color(0, 255, 0));
      } else if (conv>10&&conv<40) {
        cp5.getController("CAD1").setColorForeground(color(255, 255, 0));
      } else if (conv>40 &&conversor<=90) {
        cp5.getController("CAD1").setColorForeground(color(255, 0, 0));
      }
      
      if (conversor>0 && conversor<10) {
        cp5.getController("CAD2").setColorForeground(color(0, 255, 0));
      }else if (conversor>10 &&conversor<40) {
         cp5.getController("CAD2").setColorForeground(color(255, 255, 0));
      }else if (conversor>40 &&conversor<=90) {
        cp5.getController("CAD2").setColorForeground(color(255, 0, 0));
      }
    }
  }
}

void CONEXION() {
  con=1-con;
  if (con==1) {
    port=new Serial(this, "COM14", 9600);
    cp5.getController("CONEXION").setLabel("DESCONECTAR");
    cp5.getController("CONEXION").setColorBackground(color(5,255,5));
    
  } else {
    port.stop();
    cp5.getController("CONEXION").setLabel("CONEXION");
     cp5.getController("CONEXION").setColorForeground(color(255,5,0));
  }
}
