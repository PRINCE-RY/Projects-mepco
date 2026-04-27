#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
const char* mqtt_server = "YOUR_PI_IP_ADDRESS";

WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length) {
  String message = "";
  for (int i = 0; i < length; i++) { message += (char)payload[i]; }
 
  Serial.print("Message arrived: ");
  Serial.println(message);

  // Respond back to Pi
  String response = "ESP32 (ID: 1) received: " + message;
  client.publish("home/esp32/responses", response.c_str());
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    if (client.connect("ESP32_Client_1")) {
      client.subscribe("home/esp32/commands");
    }
  }
  client.loop();
}
