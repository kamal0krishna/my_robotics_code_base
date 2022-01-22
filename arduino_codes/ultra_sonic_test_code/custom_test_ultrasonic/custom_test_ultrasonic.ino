/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/
// defines pins numbers
#define trigPin 5
#define echoPin 9
#define limitPin 2
#define conveyorPin 13
#define loadedlen 6

// defines variables
long duration;
int distance;
void setup()
{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);  // Sets the echoPin as an Input

  pinMode(limitPin, INPUT_PULLUP);
  pinMode(conveyorPin, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}

int calculateDistance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(200);
  // Sets the trigPin on HIGH state for 10 micro seconds        Q`  `Q
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  return (duration * 0.034 / 2.0);
}
void loop()
{
  distance = calculateDistance();
  int sensorVal = digitalRead(limitPin);
  if (sensorVal == LOW && distance > loadedlen)
  {
    
    digitalWrite(conveyorPin, LOW);
    Serial.print("distance: ");
    Serial.println(distance);
    Serial.print("loading...");
  }
  else
  {
    digitalWrite(conveyorPin, HIGH);
    Serial.print("distance: ");
    Serial.println(distance);
    Serial.print("standby ");
  }

}
