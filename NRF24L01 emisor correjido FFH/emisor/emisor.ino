/**
Tutorial Arduino: Módulo NRF24L01
Más información en:
http://www.leantec.es/blog/44_Tutorial-Arduino--Modulo-NRF24L01.html

 * Pins del SPI:
 * Hardware SPI:
 * MISO -> 12
 * MOSI -> 11
 * SCK -> 13
 */
 
//Incluimos las librerías necesarias
#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

void setup(){
  Serial.begin(9600);
  Mirf.cePin = 9;                  // Cambiamos el pin CE al 9
  Mirf.csnPin = 10;                // Cambiamos el pin CSN al 10
  Mirf.spi = &MirfHardwareSpi;     // Configuramos el SPI de Arduino por Hardware
  Mirf.init();                     // Inciamos el módulo de RF
  Mirf.setRADDR((byte *)"clie1");  // Indicamos la dirección para recibir datos
  Mirf.payload = 1;                // Indicamos el número de datos que se espera recibir
  Mirf.config();     // Configuramos el módulo de RF 
  pinMode(3, INPUT); //Configuramos el pin 3 como entrada para leer el estado del pulsador
}

void loop(){
  uint8_t estadoPulsador[1];        // Variables modificadas según valor del pulsador
  estadoPulsador[0]=digitalRead(3); // Leemos el pulsador correjido por FFH era 3 y no 7 !!!

  Mirf.setTADDR((byte *)"serv1");  // Configuramos la dirección a donde vamos a enviar los datos
  Mirf.send(estadoPulsador);       // Enviamos los datos 
  while(Mirf.isSending()){}        // Esperamos que termine la emisión
}
  
