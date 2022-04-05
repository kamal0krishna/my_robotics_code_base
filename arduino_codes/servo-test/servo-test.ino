#include <Servo.h>

#define servoPin 5

Servo myservo;

void setup(){
  myservo.attach(servoPin,1000,2000);
  Serial.begin(9600);
}

void loop(){
  if(Serial.available()>0){
    int angle = Serial.parseInt();
    myservo.write(angle);
    Serial.print("Angle: ");
    Serial.println(angle);
  }
}
