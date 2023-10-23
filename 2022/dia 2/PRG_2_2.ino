// Declarando terminais, constantes e variáveis
int valor_pot = 0;
const int led = 3; // LED ligado ao pino D8
const int  potenciometro = A5; // Potenciômetro ligado ao pino analógico A5
const int portaSerial = 9600; // Inicia dados para 9600 bps 

// Configurações
void setup(){
  pinMode(led, OUTPUT);
   Serial.begin(9600); // Configura a taxa de transferência para transmissão serial.
}

// Código principal
void loop(){
    // Leitura do valor do potenciômetro
    valor_pot = analogRead(potenciometro);
    
    digitalWrite(led, HIGH);
    delay(valor_pot);
    
    digitalWrite(led, LOW);
    delay(valor_pot);

    String message = (String)"Valor do potenciômetro = " + valor_pot + " \n";
    Serial.print(message); // Escreve no monitor serial
}
