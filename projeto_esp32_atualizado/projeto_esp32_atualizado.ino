#include <ArduinoJson.h>
#include <FlowMeter.h>  // https://github.com/sekdiy/FlowMeter
#include <WiFi.h>
#include <IOXhop_FirebaseESP32.h>

// Definições para Wi-Fi e Firebase

#define WIFI_SSID "***********"
#define WIFI_PASSWORD "************"
#define FIREBASE_HOST "***************************************"
#define FIREBASE_AUTH "***************************************"

// Propriedades do sensor de vazão
FlowSensorProperties MySensor = {50.0f, 4.5f, {1.2, 1.1, 1.05, 1, 1, 1, 1, 0.95, 0.9, 0.8}};
FlowMeter *Meter;

// Variáveis de cronometragem
long period = 1000;   // um segundo (em milissegundos)
long lastTime = 0;

// Pinos para o sensor ultrassônico
#define echoPin 13
#define trigPin 12
const int blueLED = 14; // Pino para a luz azul
const int redLED = 27;  // Pino para a luz vermelha


// Variáveis para o sensor ultrassônico
long duration;
int distancia;

// Rotina de serviço de interrupção (ISR) para o sensor de vazão
void MeterISR() {
    Meter->count();
}

// Configuração inicial
void setup() {
    Serial.begin(115200);

    // Conexão Wi-Fi
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status()!= WL_CONNECTED) {
        delay(300);
        Serial.println("Tentando se conectar ao Wi-Fi...");
        WiFi.reconnect(); // Tenta se reconectar automaticamente
    }

    // Inicialização do Firebase
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

    // Obtenha uma nova instância do FlowMeter para um sensor de fluxo não calibrado no pino 2
    Meter = new FlowMeter(digitalPinToInterrupt(2), MySensor, MeterISR, RISING);

    // Configuração do sensor ultrassônico
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

// Loop principal
void loop() {
    long currentTime = millis();
    long duration = currentTime - lastTime;

    if (duration >= period) {
        Meter->tick(duration);

        // produzir algum resultado de medição de vazao
        Serial.println("Sensor de Vazao - taxa fluxo atual: " + String(Meter->getCurrentFlowrate()) + " L/min, " +
                       "Volume Vazao: " + String(Meter->getTotalVolume()) + " L, " +
                       "compensated error: " + String(Meter->getCurrentError()) + " %, " +
                       "duration: " + String(Meter->getTotalDuration() / 1000) + " s.");

        float currentFlowRate = Meter->getCurrentFlowrate();
        float totalVolume = Meter->getTotalVolume();

        // Leitura do sensor ultrassônico
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
        duration = pulseIn(echoPin, HIGH);
        distancia = duration * 0.034 / 2;

        delay(60000); // aguarda 1 minuto para proxima leitura 

        
        //Mostrar dados para o Firebase
        Firebase.setFloat("/SensorVazao/VolumeVazao", totalVolume);
        Firebase.setFloat("/SensorVazao/TaxaDeFluxo", currentFlowRate);
        Firebase.setFloat("/Caixa/VolumeCaixa", distancia);

        


        lastTime = currentTime;

                // Verifica a conexão Wi-Fi e acende a luz correspondente
        if (WiFi.status() == WL_CONNECTED) {
            digitalWrite(blueLED, HIGH); // Acende a luz azul
            digitalWrite(redLED, LOW); // Desliga a luz vermelha
            delay(1000); // Espera por 1 segundo
        } else {
            digitalWrite(blueLED, LOW); // Desliga a luz azul
            digitalWrite(redLED, HIGH); // Acende a luz vermelha
            delay(1000); // Espera por 1 segundo
        }
    }
}
