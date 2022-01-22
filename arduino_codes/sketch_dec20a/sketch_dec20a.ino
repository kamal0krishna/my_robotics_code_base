#define ROSSERIAL_ARDUINO_TCP
#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include <ESP8266WebServer.h>   // For using server 

#define pwmMl D0
#define pwmMr D1


#define dirMl D5
#define dirMr D6


const char* ssid    = "Deepu";         // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "mercy0on0my0data";

//char *ssid = "NITC-WIFI-Academic";
//char *password = "";

ESP8266WebServer server(80);

//Ml-motor left
//Mr-motor right

int s = 1024;

void forward() {
  Serial.println("for");
  digitalWrite(dirMl, 1);
  analogWrite(pwmMl, s);
  digitalWrite(dirMr, 1);
  analogWrite(pwmMr, s);
  server.send(200, "text/plain", "moving forward");
  
}


void backward() {
  Serial.println("back");
  digitalWrite(dirMl, 0);
  analogWrite(pwmMl, s);
  digitalWrite(dirMr, 0);
  analogWrite(pwmMr, s);
  server.send(200, "text/plain", "moving backward");
  
}

void stap() {
  Serial.println("Stopping");
  analogWrite(pwmMl, 0);
  analogWrite(pwmMr, 0);
  server.send(200, "text/plain", "stopping");
  delay(50);
}

void speedControl() {
  Serial.println("speed");
  s = server.arg("val").toInt();
  server.send(200, "text/plain", "speed changed to " + server.arg("val"));
}

void setup() {
  Serial.begin(9600);
  pinMode(dirMl, OUTPUT);
  pinMode(dirMr, OUTPUT);


  pinMode(pwmMl, OUTPUT);
  pinMode(pwmMr, OUTPUT);


  Serial.println('\n');
  WiFi.begin(ssid, password);             // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(ssid); Serial.println(" ...");

  int i = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(++i); Serial.print(' ');
  }

  Serial.println('\n');
  Serial.println("Connection established!");
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer

  server.on("/forward", forward);
  server.on("/reverse", backward);
  server.on("/stop", stap);
  

  server.begin();
}

void loop() {
  server.handleClient();
}
