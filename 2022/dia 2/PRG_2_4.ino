// Bibliotecas
#include <LiquidCrystal.h>
 
// Define os terminais e cria o objeto para acesso
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
const int backLight = 10;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 
// Limites para detecção das teclas, em ordem crescente
struct {
  int limite;
  char *nome;
} teclas[] = {
  {   50, "Direita " },
  {  150, "Cima    " },
  {  300, "Baixo   " },
  {  500, "Esquerda" },
  {  750, "Select  " },
  { 1024, "        " }  // nenhuma tecla apertada
};
 
// Configurações
void setup() {
  //Progama o pino de backlight como saída
  pinMode(backLight, OUTPUT);
  // Inicia o display e coloca uma mensagem
  lcd.begin(16, 2);
  lcd.print("Arduino CEC 2022");
  // Acende o backlight
  digitalWrite(backLight, HIGH);
}
 
// Código principal
void loop() {
  static int teclaAnt = -1;   // última tecla detectada
 
  // Lê a tensão no pino A0
  int leitura = analogRead(A0);
 
  // Identifica a tecla apertada pela tensão lida
  int teclaNova;
  for (teclaNova = 0; ; teclaNova++) {
    if (leitura < teclas[teclaNova].limite) {
      break;
    }
  }
 
  // Atualiza a tela se pressionou uma nova tecla
  if (teclaNova != teclaAnt) {
    lcd.setCursor(0,1);
    lcd.print(teclas[teclaNova].nome);
    teclaAnt = teclaNova;
  }
 
  // Espera até a próxima leitura
  delay (100);
}