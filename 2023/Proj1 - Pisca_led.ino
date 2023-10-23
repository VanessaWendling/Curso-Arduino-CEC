// Colar os dados do projeto
#define BLYNK_TEMPLATE_ID "DADOS_DO_PROJETO"
#define BLYNK_TEMPLATE_NAME "DADOS_DO_PROJETO"
#define BLYNK_AUTH_TOKEN "DADOS_DO_PROJETO"

#include <ESP8266WiFi.h> //Biblioteca para conectar a uma rede Wi-Fi
#include <BlynkSimpleEsp8266.h> //Biblioteca para uso da plataforma Blynk

// Configurações do aplicativo e da rede Wi-Fi
char auth[] = BLYNK_AUTH_TOKEN; //Armazena o AuthToken no array auth
char ssid[] = "NOME_REDE"; //Rede WiFi
char pass[] = "SENHA"; //Senha da rede WiFi

int ledPin = 5; // Corresponde ao pino D1

BLYNK_WRITE(V0){
  digitalWrite(ledPin, param.asInt());
}

void setup() {
  Blynk.begin(auth, ssid, pass); //Inicializa o Blynk passando parâmetros
  pinMode(ledPin, OUTPUT); // Define ledPin como de saída
}

void loop() {
    Blynk.run(); //Chama a função Blynk.run
}
