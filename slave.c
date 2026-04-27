#include <WiFi.h>
#include <PubSubClient.h>

// --- Update these with your details ---
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
const char* mqtt_server = "192.168.1.XX"; // Your Pi's IP

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
 
  // 1. Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected!");
  Serial.print("ESP32 IP: ");
  Serial.println(WiFi.localIP());

  // 2. Set MQTT Server
  client.setServer(mqtt_server, 1883);
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection to Pi...");
    if (client.connect("ESP32_Test_Node")) {
      Serial.println("CONNECTED!");
    } else {
      Serial.print("FAILED, rc=");
      Serial.print(client.state()); // -2 means IP is wrong, -4 means Pi blocked it
      Serial.println(" retrying in 5 seconds...");
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // 3. Send a test heartbeat every 3 seconds
  static unsigned long lastMsg = 0;
  if (millis() - lastMsg > 3000) {
    lastMsg = millis();
    String msg = "Connection OK - Uptime: " + String(millis()/1000) + "s";
    client.publish("test/connection", msg.c_str());
    Serial.println("Sent: " + msg);
  }
}
