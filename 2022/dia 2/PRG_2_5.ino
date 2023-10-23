#include <LiquidCrystal.h>

// Declarando terminais, constantes e variáveis
int valor_pot = 0;
const int led = 11; // LED ligado ao pino D3
const int  potenciometro = A5; // Potenciômetro ligado ao pino analógico A5

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Configurações
void setup(){
  pinMode(led, OUTPUT);
  
  lcd.begin(16, 2);
  lcd.setCursor(1,0);
   lcd.print("Valor da pot = ");
}

// Código principal
void loop(){
    // Leitura do valor do potenciômetro
    valor_pot = analogRead(potenciometro);
   
    lcd.setCursor(6,1);
    lcd.print(valor_pot);
   
    if(valor_pot < 1000)
      lcd.print(" ");
    
    digitalWrite(led, HIGH);
    delay(valor_pot);
       
    digitalWrite(led, LOW);
    delay(valor_pot);

    
}