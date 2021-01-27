/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 * FACULTAD DE INGENIERÍA EN CIENCIAS APLICADAS
 * CARRERA DE INGENIERÍA EN TELECOMUNICACIONES
 * 
 * Carolina Quinatoa- Viviana Yucailla
 * Proyecto Final
 * 
 * Código Algoritmo K-nn
 */
#include "datos.h"

float test [3] = {218,315,2}; //Dato de prueba

int fil = 0;
int col = 0;

float distancia;
float etiqueta;
float distancias[180];
float etiquetas[180];

float aux;
float aux2;

int k = 5; //Cantidad de datos mas cercanos siempre tiene que Ser impar
int a = 0; //Variables para contar las 2 etiquetas
int b = 0; //


void setup() {
  Serial.begin(9600);
  
//Calculamos la distancia del dato ingresado a cada dato de la matriz de datos.------------------------------------
  for (; fil < 180; fil++) {
    for (col = 0; col < 2; col++) {
      //distancia
      distancia = distancia + pow(matriz[fil][col] - test[col], 2); //dis=(x1-x2)^2 - (y1-y2)^2
    }
    distancia = sqrt(distancia); //d=raiz(dis)
 
    distancias[fil] = distancia; //Almacenamos en un vector todas las distancias
    etiquetas[fil] = matriz[fil][2]; //Almacenamos en un vector todas las etiquetas

     distancia=0; //Reestablecemos la distancia en 0.. para utilizarla con el siguiente dato
  }

  //Ordena distancias de distancias y a la vez de etiquetas.
  for (int i = 0; i < 180; i++) {
    for (int j = 0; j < (180); j++) {
      if (distancias[j] > distancias[j + 1]) {
        aux = distancias[j];
        aux2 = etiquetas[j];
        distancias[j] = distancias[j + 1];
        etiquetas[j] = etiquetas[j + 1];
        distancias[j + 1] = aux;
        etiquetas[j + 1] = aux2;
      }
    }
  }
  
  //ver distancias y etiquetas ordenadas.
  
//Serial.println("distancias ORDENADO");
//for (int x = 1; x < 180; x++) {
//      Serial.println(distancias[x]);
//      Serial.println(etiquetas[x]);
//  }

Serial.println("ETIQUETAS PARA VALORES DE K");
  //contar la cantidad de etiquetas, K=3
  for (int y = 1; y < k+1; y++) {
    if (etiquetas[y] == 1.00) {
      a = a + 1;
    }
    if (etiquetas[y] == 2.00) {
      b = b + 1;
    }
    Serial.print("k = ");
    Serial.print(y);
    Serial.print(" :  ");
    Serial.println(etiquetas[y]);
  }
  //Verificar que etiqueta tiene mas valores
  if (a > b) {
    etiqueta = 1;
  }
  if (b > a) {
    etiqueta = 2;
  }

  Serial.println(String("datos son de etiqueta: ") + String(etiqueta));

}

void loop() {

}
