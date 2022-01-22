#define ROSSERIAL_ARDUINO_TCP
#include <ros.h>
#include <robocon2021/Ground.h>
#include <Servo.h>

#define pitch D2
#define yaw D3
#define pwm D6
#define dir D7
#define lswitch D1
int repeat = 0, t;
int pitch_angle = 0;

Servo pitch_servo;
Servo yaw_servo;

IPAddress server(192, 168, 63, 14); //40 or 50
const uint16_t server_port = 11213;




ros::NodeHandle nh;
char ssid[] = "kamal";
char pass[] = "kamal123";

robocon2021::Ground ground_data;
ros::Publisher ground_pub("serial/ground", &ground_data);

void ground(const robocon2021::Ground &msg)
{
  //  digitalWrite(rotate, msg.dcmotor > 0 );
  //  digitalWrite(grip, msg.gripper <= 0);
  ground_data = msg;
  ground_pub.publish(&msg);
  if (msg.upDown && !repeat)
  {
    pitch_servo.write(90);
    yaw_servo.write(60);
    digitalWrite(dir, LOW);
    digitalWrite(pwm, HIGH);
    Serial.println("motor_on");
    t  = millis();

    //    while(lswitch){
    //      Serial.println("vaaathi coming");
    //      }
    repeat = 1;
  }
  else if (!lswitch && repeat == 1)
  {
    digitalWrite(pwm, LOW);
    repeat = 2;
  }
  else if (!msg.upDown)
  {
    if (pitch_angle = 0)
    {
      pitch_servo.write(0);
      digitalWrite(dir, HIGH);
      digitalWrite(pwm, HIGH);
      Serial.println("motor_on");
      t  = millis();
    }
    if (pitch_angle < 4)
    {
      pitch_servo.write(pitch_angle * 60);
      pitch_angle += 1;
    }
    if (pitch_angle >= 3)
    {
      digitalWrite(pwm, LOW);
      Serial.println("motor_ofof");
      Serial.println(millis() - t);
      repeat = 0;
    }
    if (repeat == 0)
    {
      if (!msg.orient)
      {
        yaw_servo.write(60 + 90);
        if (yaw_servo.read() >= 145)
        {
          pitch_servo.write(0);
        }
      }
      else
      {
        yaw_servo.write(60 - 90);
        if (yaw_servo.read() >= 145)
        {
          pitch_servo.write(0);
        }
      }
    }
  }
}

ros::Subscriber<robocon2021::Ground> ground_sub("/data/ground", &ground);

void rosDelay(int delayTime) {
  unsigned long startTime = millis();
  while (startTime - millis() < delayTime)
  {
    nh.spinOnce();
  }
}

void setup()
{
  Serial.begin(115200);
  pitch_servo.attach(pitch);
  yaw_servo.attach(yaw);
  pinMode(pwm, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(lswitch, INPUT_PULLUP);
  //  pinMode(rotate, OUTPUT);
  //
  //  pinMode(grip, OUTPUT);
  //  digitalWrite(rotate, HIGH);
  //  digitalWrite(grip, HIGH);

  Serial.println('\n');
  WiFi.begin(ssid, pass); // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(ssid);
  Serial.println(" ...");

  int i = 0;
  while (WiFi.status() != WL_CONNECTED)
  {
    rosDelay(500);
    Serial.print(++i);
    Serial.print(' ');
  }
  Serial.println('\n');
  Serial.println("Connection established!");
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());

  nh.getHardware()->setConnection(server, server_port);
  nh.initNode();

  nh.subscribe(ground_sub);
  nh.advertise(ground_pub);
}

void loop()
{
  nh.spinOnce();
  rosDelay(10);
}
