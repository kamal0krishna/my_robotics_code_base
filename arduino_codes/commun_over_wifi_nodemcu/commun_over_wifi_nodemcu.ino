#define ROSSERIAL_ARDUINO_TCP
#include <ESP8266WiFi.h>
#include <ros.h>
#include <std_msgs/String.h>

/*
   rosserial Publisher Example
   Prints "hello world!"
*/

ros::NodeHandle nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello[13] = "hello world!";


const char *ssid =  "kamal";     // replace with your wifi ssid and wpa2 key
const char *pass =  "kamal123";

IPAddress server(192, 168, 104, 160);  //40/50
const uint16_t server_port = 11211;


WiFiClient client;

void setup()
{
  Serial.begin(9600);
  delay(10);

  Serial.println("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(WiFi.localIP());
  Serial.println("WiFi connected");
  nh.getHardware()->setConnection(server, server_port);
  nh.initNode();
  nh.advertise(chatter);

  Serial.println("node initialized");
}

void loop()
{
  Serial.println("loop running");
  str_msg.data = hello;
  chatter.publish( &str_msg );
  nh.spinOnce();


}
