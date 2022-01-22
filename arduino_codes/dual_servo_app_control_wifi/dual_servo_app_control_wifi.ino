
#define ROSSERIAL_ARDUINO_TCP
#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include <ESP8266WebServer.h>   // For using server 
#include <Servo.h>

ESP8266WebServer server(80);

Servo horizontal_servo;
Servo vertical_servo;

#define servo_1 D5
#define servo_2 D6

bool automation_activation = false;


//const char* ssid    = "Deepu";         // The SSID (name) of the Wi-Fi network you want to connect to
//const char* password = "mercy0on0my0data";

const char* ssid    = "kamal";         // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "kamal123";

//char *ssid = "NITC-WIFI-Academic";
//char *password = "";


void vertical_angle_set() {
  Serial.println("changing vertical angle");
  int vertical_angle = server.arg("pos").toInt();
  vertical_servo.write(vertical_angle);
  Serial.print("vertical Angle: ");
  Serial.println(vertical_angle);
  server.send(200, "text/plain", "vertical angle changed to " + server.arg("pos"));

}


void horizontal_angle_set() {
  Serial.println("changing horizontal angle");
  int horizontal_angle = server.arg("pos").toInt();
  horizontal_servo.write(horizontal_angle);
  Serial.print("horizontal Angle: ");
  Serial.println(horizontal_angle);
  server.send(200, "text/plain", "horizntal angle changed to " + server.arg("pos"));

}

void automation_switch() {

  if (automation_activation == false) {
    server.send(200, "text/plain", "programme automated");
    automation_activation = !automation_activation;
  } 
  else if (automation_activation == true) {
    server.send(200, "text/plain", "programme under manual control");
    automation_activation = !automation_activation;
  }  
  Serial.print("automation activation set to ");
  Serial.println(automation_activation);
}

void setup() {
  Serial.begin(9600);
  horizontal_servo.attach(servo_1, 1000, 2000);
  vertical_servo.attach(servo_2, 1000, 2000);

  



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

  server.on("/horizonta_servo", horizontal_angle_set);
  server.on("/vertical_servo", vertical_angle_set);
  server.on("/automatic", automation_switch);



  server.begin();
}

void loop() {
  server.handleClient();
}
