#include <Servo.h>

//ASME Servo motor
//Voltage mode

#define servoPin D4

Servo myservo;



void setup() {
  myservo.attach(servoPin);
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() > 0)
  {
    int angle = Serial.parseInt();
    rotateServo(angle);
    delay(1000);
  }
}

void rotateServo(int angle){
  if(angle>180 || angle<0){
    Serial.println("Invalid Angle");
  }
  else{
  myservo.write(angle);
  delay(1000);
  Serial.print("Angle: ");
  Serial.println(angle);}
}
