l#define ROSSERIAL_ARDUINO_TCP
#include <ros.h>
#include <std_msgs/Int32.h>
#include <Servo.h>
#include <ESP8266WiFi.h>

#define arm_pwm D5
#define arm_dir D6
#define pitch_servo_pin D1
#define yaw_servo_pin D2

Servo pitch_servo;
Servo yaw_servo;

ros::NodeHandle nh;

const char *ssid =  "kamal";     // replace with your wifi ssid and wpa2 key
const char *pass =  "kamal123";

//Static IP Configuration

IPAddress server(192, 168, 63, 160);  //40/50
const uint16_t server_port = 11211;



void pitch(const std_msgs::Int32 &angle)
{
  int theta = angle.data;
  pitch_servo.write(theta);
}

void yaw(const std_msgs::Int32 &angle)
{ int theta = angle.data;
  yaw_servo.write(theta);
}

void arm(const std_msgs::Int32 &pwm)
{ int PWM = pwm.data;
  analogWrite(arm_pwm, abs(PWM));
  digitalWrite(arm_dir, PWM > 0);
}

ros::Subscriber<std_msgs::Int32> pitch_sub("/data/ground/pitch", &pitch);
ros::Subscriber<std_msgs::Int32> yaw_sub("/data/ground/yaw", &yaw);
ros::Subscriber<std_msgs::Int32> arm_sub("/data/ground/arm", &arm);



void setup()
{
  Serial.begin(9600);
  delay(10);

  Serial.println("void setup running");
  pinMode(arm_pwm, OUTPUT);
  pinMode(arm_dir, OUTPUT);
  pitch_servo.attach(pitch_servo_pin);
  yaw_servo.attach(yaw_servo_pin);

  Serial.println("trying to setup wifi");
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
  delay(1000);

  Serial.println("attempting to connect port");
  nh.getHardware()->setConnection(server, server_port);
  Serial.println("Connected");

  nh.initNode();

  nh.subscribe(pitch_sub);
  nh.subscribe(yaw_sub);
  nh.subscribe(arm_sub);
  Serial.println("void setup finished.");
}

void loop()
{
  Serial.println("loop running");
  nh.spinOnce();
}
