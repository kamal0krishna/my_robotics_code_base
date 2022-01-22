#define ROSSERIAL_ARDUINO_TCP
#include <ros.h>
#include <riggu2021/Motors.h>

//motor 1 or back
#define motorLEa D1
#define motorLEb D2

//motor 2 or left
#define motorREa D5
#define motorREb D6

int posL = 0;
int posR = 0;



//static ip setup - 172.16.38.196
//IPAddress server(10, 10,10, 50);
IPAddress server(172, 16,38, 196);
const uint16_t server_port = 12213;

ros::NodeHandle nh;
char ssid[] = "NITC-WIFI-Academic";
char pass[] = "";
//
//char ssid[] = "Aero Suddu";//NITC-WIFI-Academic
//char pass[] = "onewordallcaps";
  
riggu2021::Motors encoder_data;

ros::Publisher encoder_data_pub("sensorData/encoderData", &encoder_data);


void setup()
{
 Serial.begin(115200);
  //input pins
  //motorL back
  pinMode(motorLEa, INPUT_PULLUP);
  pinMode(motorLEb, INPUT_PULLUP);
  //motorR left
  pinMode(motorREa, INPUT_PULLUP);
  pinMode(motorREb, INPUT_PULLUP);

  //attaching interrupts

  attachInterrupt(digitalPinToInterrupt(motorLEa), readEncoderL, FALLING);
  attachInterrupt(digitalPinToInterrupt(motorREa), readEncoderR, FALLING);
 

  Serial.println('\n');
  WiFi.begin(ssid, pass); // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(ssid);
  Serial.println(" ...");

  int i = 0;
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(++i);
    Serial.print(' ');
  }
  Serial.println('\n');
  Serial.println("Connection established!");
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());

  //node initialized
  nh.getHardware()->setConnection(server, server_port);
  nh.initNode();

  nh.advertise(encoder_data_pub);

}
unsigned long currentMillis = millis();
void loop()
{

  if (millis() - currentMillis >= 1000) //publish every 1000 milliseconds
  {

    encoder_data.motorL = posL;
    encoder_data.motorR = posR;

    Serial.print(" posL");
    Serial.print(posL);
    Serial.print(" posR");
    Serial.print(posR);
    Serial.println("");

    posL = posL - encoder_data.motorL;
    posR = posR - encoder_data.motorR;



    
    encoder_data_pub.publish(&encoder_data);
    currentMillis = millis();
  }

  nh.spinOnce();
}


ICACHE_RAM_ATTR void readEncoderL()
{
  int a = digitalRead(motorLEb);
  if (a > 0)
  {
    posL--;
  }
  else
  {
    posL++;
  }
}


ICACHE_RAM_ATTR void readEncoderR()
{
  int c = digitalRead(motorREb);
  if (c > 0)
  {
    posR--;
  }
  else
  {
    posR++;
  }
}
