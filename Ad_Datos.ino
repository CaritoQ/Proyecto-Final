/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 * FACULTAD DE INGENIERÍA EN CIENCIAS APLICADAS
 * CARRERA DE INGENIERÍA EN TELECOMUNICACIONES
 * 
 * Carolina Quinatoa- Viviana Yucailla
 * Proyecto Final
 * 
 * Código Adquisición de Datos
 */
#include <MsTimer2.h>
#include <EEPROM.h>

int sensor1;
int sensor2;
int s1;
int s2;
int i=0;
int j=200;
int muestras=100;

void setup() {
  
  pinMode(3,INPUT);
  
  Serial.begin(9600);
  
  
  Serial.println("LEER DATOS");
  Serial.println("----------------------");
  for(int l=0;l<100;l++){
  Serial.println("S1"+String(EEPROM.read(l))+" S2"+String(EEPROM.read(l+200)));
  }
                               
  delay(5000);
                               
  Serial.println("INICIO");
  Serial.println("----------------------");
  
  delay(2000);
  
  MsTimer2::set(500000,cont);//contador para que los datos sean tomados cada 5 minutos
  MsTimer2::start();
  
}

void loop() {
}

void cont(){
if(muestras>0){
  i++;
  j++;
  if(digitalRead(3)==HIGH){
//Leer datos  
  sensor1=analogRead(0);
  s1=map(sensor1,0,1023,0,255);
  sensor2=analogRead(1);
  s2=map(sensor2,0,1023,0,255);
//Escribir datos
  EEPROM.write(i,sensor1);
  EEPROM.write(j,sensor2);
  Serial.println("--------------------------");
  Serial.println("Muestra N "+String(i));
  Serial.println("S1: "+String(sensor1)+" S2: "+String(sensor2));
  Serial.println("--------------------------");
  muestras--;
      }
    else{
  Serial.println("Conecte el pin3 a 5V");
      }
  }
  else{
  Serial.println("Datos Listos");
  MsTimer2::stop();
  }
  }
