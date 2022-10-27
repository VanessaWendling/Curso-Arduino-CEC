const int led = 12; //pino D12
const int detectaChuva = 3; //pino D3
const int portaSerial = 9600;

int valor_detectorChuva = 0; //guarda o valor boleano

void setup(){
  pinMode(detectaChuva, INPUT);
  pinMode(led, OUTPUT); 
  Serial.begin(portaSerial); 
}

void loop(){
  valor_detectorChuva = digitalRead(detectaChuva);
  if(valor_detectorChuva == LOW){ 
      digitalWrite(led, HIGH); 
      Serial.println("Está chovendo");
  }else{ 
    digitalWrite(led, LOW); 
    Serial.println("Não está chovendo");
  }
}
