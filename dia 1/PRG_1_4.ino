// Declarando terminais, constantes e variáveis
int valor_pot = 0;
const int led = 3; // LED ligado ao pino D8
const int  potenciometro = A5; // Potenciômetro ligado ao pino analógico A5

// Configurações
void setup(){
  pinMode(led, OUTPUT);
}

// Código principal
void loop(){
    // Leitura do valor do potenciômetro
    valor_pot = analogRead(potenciometro);
   
    // Gera um sinal PWM proporcional à leitura do potenciômetro
    analogWrite(led, valor_pot / 4);
    // Deve-se dividir por 4 pois a faixa do AD é 1024 e a faixa do PWM é 256
}
