// Declarando terminais, constantes e variáveis
int led = 3; // LED ligado ao pino D3
int tempo = 1000;    // Tempo (em ms) que os LEDs ficam acesos/apagados

// Configurações
void setup(){
  pinMode(led, OUTPUT); // Pino 8 (led) configurado como saída
}

// Código principal
void loop(){
  digitalWrite(led, HIGH); // Acende LED
  delay(tempo); // Espera tempo
  
  digitalWrite(led, LOW); // Apaga LED
  delay(tempo); // Espera tempo
}