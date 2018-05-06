// Connect ESP8266 to these Arduino pins:
//
// Board           ESP8266.rx  ESP8266.tx
// -----           ----------  ----------
// Arduino Uno         3            2
// Arduino Nano        3            2
// Arduino Mini        3            2
// Arduino Pro Mini    3            2
// Arduino Leonardo    3            2
// Arduino Micro       3            2
// Arduino Mega 2560  18           19
// Arduino Due        18           19

#include "ESP8266_Device.h"

#define SSID      "TP-LINK"
#define PASSWORD  "12345678"
int S1 = 0;
int S2 = 0;
int S3 = 0;
int S4 = 0;
int sensorinfra1 = 6;
int sensorinfra2 = 7;
int sensorinfra3 = 8;
int sensorinfra4 = 8;
ESP8266_Device device;

void setup() {
  Serial.begin(9600);
  pinMode(sensorinfra1, INPUT);  
  pinMode(sensorinfra2, INPUT);  
  pinMode(sensorinfra3, INPUT);  
  pinMode(sensorinfra4, INPUT);  
  Serial.println("+++ Iniciando o teste +++");

  Serial.println("Conectando a rede " + String(SSID));
  if (!device.connectWifi(SSID, PASSWORD)) {
    Serial.println("FALHA: nao foi possivel a conexao com Wifi!");
    for (;;);
  }
  Serial.println("SUCESSO! Conectado a rede " + String(SSID));

  Serial.println("\r\nConectando ao Exosite");
  if (!device.connectExosite("2d3108ada14763a5fd19dd040cfbe025f98c579a")) {
    Serial.println("FALHA: nao foi possivel a conexao com Exosite!");
    for (;;);
  }
  Serial.println("SUCESSO! Conectado ao Exosite");
  
}

void loop() {
  device.link("pps",&S1);
  S1 = digitalRead(sensorinfra1);
 if (S1 == 1){
    S1 = 1;
    device.send();    
    delay(S1);
 }
 else{
    S1 = 0;
    device.send();
    delay(S1);
 }
 S2 = digitalRead(sensorinfra2);
 if (S2 == 1){
    S2 = 1;
    device.send();    
    delay(S2);
 }
 else{
    S2 = 0;
    device.send();
    delay(S2);
 }
 S3 = digitalRead(sensorinfra3);
 if (S3 == 1){
    S3 = 1;
    device.send();    
    delay(S3);
 }
 else{
    S3 = 0;
    device.send();
    delay(S3);
 }
 S4 = digitalRead(sensorinfra4);
 if (S4 == 1){
    S4 = 1;
    device.send();    
    delay(S4);
 }
 else{
    S4 = 0;
    device.send();
    delay(S4);
 }
}
