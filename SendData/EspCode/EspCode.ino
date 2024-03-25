//---OnLooker

#include <HTTPClient.h>
#include <WiFi.h>
#include <DHT.h>

#define DHTPIN 23     // Pino ao qual o sensor está conectado
#define DHTTYPE DHT11 // Tipo do sensor

const char *ssid = "MultilaserPRO_ZTE_2.4G_TDEDEd";
const char *password = "****";

DHT dht(DHTPIN, DHTTYPE);

float HumiditySensor();
float TemperatureSensor();

void setup() {
  	Serial.begin(115200);
  	while (!Serial) {
    		; //fica preso no loop vazio enquanto nao estiver pronto a comunic serial
  	}

  	delay(100);

  	WiFi.begin(ssid, password);

  	while (WiFi.status() != WL_CONNECTED) {
    	delay(1000);
    	Serial.println("Conectando ao WiFi...");
  	}

  	Serial.println("Conectado ao WiFi!");
	dht.begin();
}

void loop() {
	float temperatura = TemperatureSensor();
	float umidade = HumiditySensor();

  	if (temperatura != -1 && umidade != -1) {
		HTTPClient http;
    		
		String data = String(temperatura, 2);

    		String serverAddress = "http://192.168.1.9:8080/api/data";

    		http.begin(serverAddress);
    		http.addHeader("Content-Type", "application/json");
    		
		String payload = "{\"temp\": " + data + "}";
		int httpResponseCode = http.POST(payload);
    		
		String response = http.getString();

    		Serial.print("Resposta do servidor: ");
    		Serial.println(response);

		http.end();
  	}
  	delay(1000);
}


float HumiditySensor(){
	delay(1000);
	float umidade = dht.readHumidity();         // Lê a umidade relativa

  	if (isnan(umidade)) {
    		Serial.println("Falha ao ler o sensor DHT11!");
    		return -1;
  	}

  	//Serial.print(" °C, Umidade: ");
  	//Serial.print(umidade);
  	//Serial.println("%");
	
	return umidade;
}

float TemperatureSensor(){
	delay(1000); 
	float temperatura = dht.readTemperature(); 
	
	if(isnan(temperatura)){
		Serial.println("Falha ao ler o sensor DHT11!");
		return -1;
	}

	//Serial.print("Temperatura: ");
  	//Serial.print(temperatura);

	return temperatura;
}


