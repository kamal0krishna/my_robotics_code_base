#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include <ESP8266WebServer.h>   // For using server 

#define in1 D2
#define in2 D4
#define in3 D6
#define in4 D8
#define enA D3
#define enB D7

const char* ssid    = "kamal";         // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "kamal123";

//char *ssid = "NITC-WIFI-Academic";
//char *password = "";

ESP8266WebServer server(80);



int s = 1024;

void forward() {
  Serial.println("moving forward");
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  server.send(200, "text/plain", "moving forward");
  
}
void right() {
  Serial.println("moving right");
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  server.send(200, "text/plain", "moving right");
  
}
void left() {
  Serial.println("moving left");
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  server.send(200, "text/plain", "moving left");
  
}
void stap() {
  Serial.println("Stopping");
  analogWrite(enA,0);
  analogWrite(enB,0);
  server.send(200, "text/plain", "stopping");
  delay(50);
}



void setup() {
  Serial.begin(9600);
   pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
  digitalWrite(enA,HIGH);
  digitalWrite(enB,HIGH);

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
  server.on("/right", right);
  server.on("/left", left);
  server.on("/stop", stap);
  server.begin();
}

void loop() {
  server.handleClient();
}
