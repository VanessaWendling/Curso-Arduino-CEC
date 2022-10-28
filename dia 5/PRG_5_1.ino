//Incluindo todas as bibliotecas necessárias
#include <LiquidCrystal.h>
#include <TinyDHT.h>
#include <Adafruit_BMP085.h>

//declaração dos pinos 
const int sensorUmidadeTemperatura = 1; // pino D1
int detectaChuva = 0; // pino D0
int quantidadeChuva = A3; // pino A3
int ledMeteorologia = 3; //  pino D3
int ledChuva = 2; // pino D2
const int backLight = 10; //pino D10 - contraste lcd

//instância dos sensores 
#define DHTTYPE DHT11
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Adafruit_BMP085 bmp; 
DHT dht(sensorUmidadeTemperatura, DHTTYPE);


// usado para indicar a tela que estamos. Pode variar de 1 até 4
int tela;

//limite das tensões dos botões de cima e baixo do lcd
int limite[] = { 150, 300 };


void setup() {
  //inicializando o lcd
  lcd.begin(16, 2);
  pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH);

  //inicializando e ligando o led da estação
  pinMode(ledMeteorologia, OUTPUT);
  digitalWrite(ledMeteorologia, HIGH);

  //inicializando as entradas e o led do sensor de chuva
  pinMode(detectaChuva, INPUT);
  pinMode(quantidadeChuva, INPUT);
  pinMode(ledChuva, OUTPUT);

  //inicializando o sensor barométrico
  bmp.begin();

  //setando qual a primeira tela para exibição
  tela = 1; 
}

void loop() {
  
  int leitura = analogRead(A0);
  if(leitura <= limite[0] && tela > 1)
    tela--;
  else if(leitura > limite[0] && leitura <= limite[1] && tela < 4)
    tela++;

  int chuva = digitalRead(detectaChuva);
  //operador ternário (if-else simplificado)
  digitalWrite(ledChuva, chuva == 1 ? LOW: HIGH);
  
  switch(tela){
    case 1:
      boasVindas();
      break;
    case 2:
      sensorDHT();
      break;
    case 3:
      sensorBarometrico(bmp.readPressure(), bmp.readAltitude());
      break;
    case 4:
      sensorDeChuva(chuva, analogRead(quantidadeChuva));
      break;
  }
 
  // Espera até a próxima leitura
  delay (500);
}


//criando funções para diminuir o código principal

void boasVindas() {
  lcd.setCursor(0,0);
  lcd.print("  Arduino UCP   ");
  lcd.setCursor(0,1);
  lcd.print("      2022      ");
}

void sensorDHT(){ 
  lcd.setCursor(0,0);
  lcd.print("Umidade:"); 
//lcd.print(dht.readHumidity(), 0);
  lcd.print("%");
      
  lcd.setCursor(0,1);
  lcd.print("Temp:");
//lcd.print(dht.readTemperature(),1);
  lcd.print((char)223);
  lcd.print("C");
}

void sensorBarometrico(float pressao, float altitude){
  lcd.setCursor(0,0);
  lcd.print("Press: ");
  lcd.print(pressao,0);
  lcd.print(" Pa");
  lcd.setCursor(0,1);
  lcd.print("Alt: ");
  lcd.print(altitude);
  lcd.print(" m");
}

void sensorDeChuva(int chuva, int valor_qtdChuva){
  lcd.setCursor(0,0);
  lcd.print("Chuva  : ");
  lcd.print(chuva == 1 ? "Nao   " : "Sim   ");

  lcd.setCursor(0,1);
  lcd.print("Intens.: ");
  if (valor_qtdChuva > 900 && valor_qtdChuva < 1023)
    lcd.print("----   ");
  else if (valor_qtdChuva > 600 && valor_qtdChuva < 900)
    lcd.print("Fraca   ");
  else if (valor_qtdChuva > 400 && valor_qtdChuva <600)
    lcd.print("Moder.   ");
  else if (valor_qtdChuva < 400)
    lcd.print("Forte   ");
}
