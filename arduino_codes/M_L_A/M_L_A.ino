#define ROSSERIAL_ARDUINO_TCP
#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include <ESP8266WebServer.h>   // For using server 



#define relay_1 D5
#define relay_2 D6


const char* ssid    = "Deepu";         // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "mercy0on0my0data";

//const char* ssid    = "kamal";         // The SSID (name) of the Wi-Fi network you want to connect to
//const char* password = "kamal123";

//char *ssid = "NITC-WIFI-Academic";
//char *password = "";

ESP8266WebServer server(80);





void forward() {
  Serial.println("for");
  digitalWrite(relay_1, HIGH);
  digitalWrite(relay_2, LOW);
  server.send(200, "text/plain", "moving forward");
  
}


void backward() {
  Serial.println("back");
  digitalWrite(relay_2, HIGH);
  digitalWrite(relay_1, LOW);
  server.send(200, "text/plain", "moving backward");
  
}

void stap() {
  Serial.println("Stopping");
  digitalWrite(relay_1, LOW);
  digitalWrite(relay_2, LOW);
  server.send(200, "text/plain", "stopping");
  delay(50);
}


void setup() {
  Serial.begin(9600);
  pinMode(relay_1, OUTPUT);
  pinMode(relay_2, OUTPUT);



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
  server.on("/backward", backward);
  server.on("/stop", stap);
  

  server.begin();
}

void loop() {
  server.handleClient();
}
