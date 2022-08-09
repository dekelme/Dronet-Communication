#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <SoftwareSerial.h>

const char* ssid = "ESPWebServer";
const char* password = "12345678";

ESP8266WebServer server(80);

void handleRoot() {
  String message = "" + server.argName(0) + '\n';
  Serial1.print(message);
  server.send(200, "text/plain", message);
}

void setup(void){
  Serial1.begin(9600);

  WiFi.mode(WIFI_AP);          
  WiFi.softAP(ssid, password);  

  IPAddress myIP = WiFi.softAPIP(); 
  server.on("/", handleRoot);      // GET endpoint
  server.begin();                  
}

void loop(void){
  server.handleClient();          
}
