#include <Adafruit_BMP085.h> //INCLUSÃO DE BIBLIOTECA
#include <LiquidCrystal.h>

Adafruit_BMP085 bmp; //OBJETO DO TIPO Adafruit_BMP085 (I2C)
const int portaSerial = 9600; // Inicia dados para 9600 bps

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup(){
  if (!bmp.begin()){ //Se o sensor não for inicializado
    while(1){} // como não tem condição de parada, não entrará no looping
  }
  lcd.begin(16, 2);
}
   
void loop(){

    lcd.setCursor(0,0);
    lcd.print("Temp:");
    lcd.print(bmp.readTemperature(), 0);
    lcd.print((char)223);
    lcd.print("C");
 
    lcd.setCursor(0,1);
    lcd.print("Altitude:");
    lcd.print(bmp.readAltitude(101600));
    lcd.print("m");
    delay(2000); //INTERVALO DE 2 SEGUNDOS
}
