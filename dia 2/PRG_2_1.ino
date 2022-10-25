
// Declarando terminais, constantes e variáveis
const int portaSerial = 9600; // Inicia dados para 9600 bps 

// Configurações
void setup(){
  Serial.begin(portaSerial); // Configura a taxa de transferência para transmissão serial.
}

// Código principal
void loop(){
    Serial.println("Oi Mundo"); // Escreve no monitor serial
}
