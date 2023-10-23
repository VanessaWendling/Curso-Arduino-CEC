#include <LiquidCrystal.h>

const int backLight = 10;
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Configurações
void setup() {
  // Inicia o display de dimensão 16X2
  lcd.begin(16, 2);
}
 
// Código principal
void loop() {
  lcd.setCursor(2,0);
  lcd.print("Oi,");
  
  lcd.setCursor(5,1);
  lcd.print("Mundo :)");
}
