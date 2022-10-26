#include <TinyDHT.h>
#include <LiquidCrystal.h>

#define DHTTYPE DHT11 // DHT 11

const int sensorUmidadeTemperatura = A1; // porta A1
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Inicializando o objeto dht do tipo DHT passando como parâmetro o pino e o tipo do sensor
DHT dht(sensorUmidadeTemperatura, DHTTYPE);
 
void setup() 
{
  lcd.begin(16, 2);
}
 
void loop() 
{
  // Leitura do valor da umidade
  float umidade = dht.readHumidity();

  // Leitura do valor da temperatura
  float temperatura = dht.readTemperature();

  lcd.setCursor(0,0);
  lcd.print("Umidade:");
  lcd.print(umidade, 0);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print("Temp:");
  lcd.print(temperatura,1);
  lcd.print((char)223);
  lcd.print("C");
}