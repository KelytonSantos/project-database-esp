#include <HTTPClient.h>
#include <WiFi.h>

const char *ssid = "MultilaserPRO_ZTE_2.4G_TDEDEd";
const char *password = "****";

void setup() {
  	Serial.begin(115200);
  	while (!Serial) {
    		;
  	}

  	delay(100);

  	WiFi.begin(ssid, password);

  	while (WiFi.status() != WL_CONNECTED) {
    	delay(1000);
    	Serial.println("Conectando ao WiFi...");
  	}

  	Serial.println("Conectado ao WiFi!");
}

void loop() {
  	if (Serial.available()) {
		HTTPClient http;
    		
		String data = Serial.readStringUntil('\n'); // Ler a entrada serial até a quebra de linha (\n)
    		
		Serial.print("Enviando dado para o servidor: ");
    		Serial.println(data);

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
}


