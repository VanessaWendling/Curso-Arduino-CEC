// Declarando terminais, constantes e variáveis
int valor_pot = 0;
const int led = 3; // LED ligado ao pino D3
const int  potenciometro = A5; // Potenciômetro ligado ao pino analógico A5

// Configurações
void setup(){
  pinMode(led, OUTPUT);
}

// Código principal
void loop(){
    // Leitura do valor do potenciômetro
    valor_pot = analogRead(potenciometro);
    
    digitalWrite(led, HIGH);
    delay(valor_pot);
    
    digitalWrite(led, LOW);
    delay(valor_pot);
}
