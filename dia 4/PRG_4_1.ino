#include <Wire.h> //funções necessárias para gerenciar a comunicação entre os dispositivos através do protocolo I2C.
#include <Adafruit_BMP085.h> //INCLUSÃO DE BIBLIOTECA
 
Adafruit_BMP085 bmp; //OBJETO DO TIPO Adafruit_BMP085 (I2C)
const int portaSerial = 9600; // Inicia dados para 9600 bps

void setup(){
  Serial.begin(portaSerial);
  if (!bmp.begin()){ //Se o sensor não for inicializado
    Serial.println("Sensor BMP180 não foi identificado! Verifique as conexões."); 
    while(1){} // como não tem condição de parada, não entrará no looping
  }
}
   
void loop(){
    
    Serial.print("Temperatura: "); 
    Serial.print(bmp.readTemperature(), 0); //lê a pressão no sensor e retorna o resultado
    Serial.println("ºC"); 
        
    Serial.print("Pressão: "); 
    Serial.print(bmp.readPressure()); // lê a altitude no sensor e retornar o resultado
    Serial.println("Pa"); 
     
    Serial.print("Altitude: "); 
    Serial.print(bmp.readAltitude()); //altitude aproximada do sensor
    Serial.println("m");
    
    Serial.print("Pressão a nível do mar (calculada): ");
    Serial.print(bmp.readSealevelPressure()); //pressão do nível do mar
    Serial.println("Pa"); 
 
    Serial.print("Altitude real: ");
    Serial.print(bmp.readAltitude(101600)); //param da pressão média de Petrópolis em Pa
    Serial.println("m");
     
    Serial.println("-----------------------------------");
    delay(2000); //INTERVALO DE 2 SEGUNDOS
}
