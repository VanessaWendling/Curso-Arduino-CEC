// Declarando terminais, constantes e variáveis
int estadoBotao = 0; // Variável booleana para registrar o click no botão
const int led = 3; // LED ligado ao pino D3
const int  botao = 9; // Botão ligado ao pino D9

// Configurações
void setup(){
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
}

// Código principal
void loop(){
    // Leitura do valor do potenciômetro
    estadoBotao = digitalRead(botao);

    if(estadoBotao == 0) // Botão não está pressionado
      digitalWrite(led, LOW);
    else // Botão está pressionado
      digitalWrite(led, HIGH);
}