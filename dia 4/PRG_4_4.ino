#include <LiquidCrystal.h> 
int detectaChuva = 11; // D11
int quantidadeChuva = A5; // A5
int valor_detectorChuva = 0; //Armazena o valor lido do pino digital
int valor_quantidadeChuva = 0; //Armazena o valor lido do pino analogico
const int portaSerial = 9600;

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 
void setup()
{
  lcd.begin(16, 2); 
  pinMode(detectaChuva, INPUT);
  pinMode(quantidadeChuva, INPUT);
  Serial.begin(portaSerial);
  lcd.setCursor(0,0);
  lcd.print("Chuva  : ");
  lcd.setCursor(0,1);
  lcd.print("Intens.: ");
}
 
void loop()
{ 
  valor_detectorChuva = digitalRead(detectaChuva);
  valor_quantidadeChuva = analogRead(quantidadeChuva);
  
  Serial.print("Valor digital : ");
  Serial.print(valor_detectorChuva);
  Serial.print(" - Valor analogico : ");
  Serial.println(quantidadeChuva);
  
  lcd.setCursor(10,0);
  if (valor_detectorChuva == 1)
    lcd.print("Nao");
  else
    lcd.print("Sim");


  lcd.setCursor(10,1);
  lcd.print("      ");
  lcd.setCursor(10,1);
    
  if (valor_quantidadeChuva >900 && valor_quantidadeChuva <1023)
    lcd.print("----");
  else if (valor_quantidadeChuva >600 && valor_quantidadeChuva <900)
    lcd.print("Fraca");
  else if (valor_quantidadeChuva>400 && valor_quantidadeChuva <600)
    lcd.print("Moder.");
  else if (valor_quantidadeChuva <400)
    lcd.print("Forte");
    
  delay(1000);
}
