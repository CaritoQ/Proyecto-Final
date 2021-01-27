/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 * FACULTAD DE INGENIERÍA EN CIENCIAS APLICADAS
 * CARRERA DE INGENIERÍA EN TELECOMUNICACIONES
 * 
 * Carolina Quinatoa- Viviana Yucailla
 * Proyecto Final
 * 
 * Código Algoritmo Bayes
 */
#include "datos.h"
float test [3] = {202,298,2};

float Px1; //Probabilidad del dato sea etiqueta 1 ---- (Px1x)(P1)/(Px)
float Px2; //Probabilidad del daro sea etiqueta 2 ---- (Px2x)(P2)/(Px)
float P1=0; //Probabilidad de etiqueta 1 ---- (#etiquetas1)/(total de observaciones)
float P2=0; //Probabilidad de etiqueta 2 ---- (#etiquetas2)/(total de observaciones)
float Px; //Probablidad de datos cercanos al radio ---- (# datos dentro del radio)/(total de observaciones)
float Px1x=0; //Probablidad de etiqueta1 dentro del radio ---- (#etiquetas1 dentro del radio)/(#etiquetas1)
float Px2x=0; //Probablidad de etiqueta2 dentro del radio ---- (#etiquetas2 dentro del radio)/(#etiquetas2)

float radio=0.3; //de 0 a 1 ---- Distancia normalizada

int fil = 0;
int col = 0;
float distanciaMax=0.0001;
float distancia; 
float distancias[180]; //Vector almacena las distancias a cada uno de los datos
float distanciasNormal[180];//Vector almacena las distancias normalizadas
float aux;
float aux2;

void setup() {
  Serial.begin(9600);
//--------------------Calcula la distancia entre la base de datos y el nuevo dato----------------------------------
  for (; fil < 180; fil++) {
    for (col = 0; col < 2; col++) {
      distancia = distancia + pow(matriz[fil][col] - test[col], 2);
    }
    distancia = sqrt(distancia);
    distancias[fil] = distancia;
    //Serial.println(distancia);
    distancia=0;   
  }
//--------------------Calcula la distancia normalizada-----------------------------------------------------------------
    for(int i=0;i<180;i++){
      if(distancias[i]>distanciaMax){
        distanciaMax=distancias[i];
        }
      }
    for(int i=0;i<180;i++){
      distanciasNormal[i]=distancias[i]/distanciaMax;
      //Serial.println(distanciasNormal[i]);
      }
//--------------------Px1x Px2x- etiquetas dentro del radio--------------------------------------------------------------
  for(int i=0;i<180;i++){
    if(distanciasNormal[i]<=radio){
      if(matriz[i][2]==1){
        Px1x=Px1x+1;
        }else{
          Px2x=Px2x+1;
          }
      }
//--------------------P1 y P2-----------------------------------------------------------------------------------
      if(matriz[i][2]==1){
      P1=P1+1;
      }
      else{
        P2=P2+1;
        }
  }
  Px=(Px1x+Px2x)/180;
  Px1x=Px1x/P1;
  Px2x=Px2x/P2;
  P1=P1/180;
  P2=P2/180;

  Px1=(Px1x)*(P1)/Px;
  Px2=(Px2x)*(P2)/Px;
  
  Serial.println("---------------------------------");
  Serial.println("            P1 Y P2              ");
  Serial.println("---------------------------------");
  Serial.println("P1: "+String(P1));
  Serial.println("P2: "+String(P2));

  Serial.println("---------------------------------");
  Serial.println("            Px1x Y Px2x              ");
  Serial.println("---------------------------------");
  Serial.println("Px1x: "+String(Px1x));
  Serial.println("Px2x: "+String(Px2x));
  
  Serial.println("---------------------------------");
  Serial.println("                Px              ");
  Serial.println("---------------------------------");
  Serial.println("Px: "+String(Px));
  
  Serial.println("---------------------------------");
  Serial.println("       Px1=(Px1x)(P1)/(Px)       ");
  Serial.println("       Px2=(Px2x)(P2)/(Px)       ");
  Serial.println("---------------------------------");
  Serial.println("Px1: "+String(Px1));
  Serial.println("Px2: "+String(Px2));

  
  Serial.println("---------------------------------");
  Serial.print("   Pertenece a la etiqueta");
  if(Px1>Px2){
  Serial.println(" 1");
    }else{
  Serial.println(" 2");
      }
  Serial.println("---------------------------------");
  
}
void loop() {
 
}
