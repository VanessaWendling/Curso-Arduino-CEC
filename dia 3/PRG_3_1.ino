#include <TinyDHT.h>
//#include "src/TinyDHT/TinyDHT.h"

#define DHTTYPE DHT11 // DHT 11

const int sensorUmidadeTemperatura = A1; // porta A1
const int portaSerial = 9600; // Inicia dados para 9600 bps 

//Inicializando o objeto dht do tipo DHT passando como parâmetro o pino e o tipo do sensor
DHT dht(sensorUmidadeTemperatura, DHTTYPE);
 
void setup() 
{
  Serial.begin(portaSerial); // Configura a taxa de transferência para transmissão serial.
  dht.begin();
}
 
void loop() 
{
  // Leitura do valor da umidade
  float umidade = dht.readHumidity();

  // Leitura do valor da temperatura em Celsius
  float tempC = dht.readTemperature();

  // Leitura do valor da temperatura em Fahrenheit
  float tempF = dht.readTemperature(true);
 
  Serial.print("Umidade: ");
  Serial.print(umidade, 0);
  Serial.println("%");
  
  Serial.print("Temperatura: ");
  Serial.print(tempC, 0);
  Serial.println("ºC");
  
  Serial.print("Temperatura: ");
  Serial.print(tempF, 0);
  Serial.println("ºF");
}