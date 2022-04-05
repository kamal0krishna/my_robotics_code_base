/*
  Gearmotor Rotary Encoder Test
  motor-encoder-rpm.ino
  Read pulses from motor encoder to calculate speed
  Control speed with potentiometer
  Displays results on Serial Monitor
  Use Cytron MD10C PWM motor controller
  DroneBot Workshop 2019
  https://dronebotworkshop.com
*/
 
// Motor encoder output pulse per rotation (change as required)
#define ENC_COUNT_REV 95
 
// Encoder output to Arduino Interrupt pin
#define ENC_IN 3 

// Pulse count from encoder
volatile long encoderValue = 0;
 
// One-second interval for measurements
int interval = 1000;
 
// Counters for milliseconds during interval
long previousMillis = 0;
long currentMillis = 0;
 
// Variable for RPM measuerment
int rpm = 0;

// Variable for number of rotations
int rotations = 0;

void setup()
{
  // Setup Serial Monitor
  Serial.begin(9600); 
  
  // Set encoder as input with internal pullup  
  pinMode(ENC_IN, INPUT_PULLUP); 

  // Attach interrupt 
  attachInterrupt(digitalPinToInterrupt(ENC_IN), updateEncoder, RISING);
  
  // Setup initial values for timer
  previousMillis = millis();
}
 
void loop()
{
  // Update RPM value every second
  currentMillis = millis();
  if (currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;
 
 
    // Calculate RPM
    rpm = (float)(encoderValue * 60 / ENC_COUNT_REV);

     // Calculate RPM
    rotations = (float)(encoderValue / ENC_COUNT_REV);
 
    // Only update display when there is a reading
    if (rpm > 0) {
      Serial.print(" PULSES: ");
      Serial.print(encoderValue);
      Serial.print('\t');
      Serial.print(" total rotations: ");
      Serial.print(rotations);
      Serial.print('\t');
      Serial.print(" SPEED: ");
      Serial.print(rpm);
      Serial.println(" RPM");
    }
  }
}
 
void updateEncoder()
{
  // Increment value for each pulse from encoder
  encoderValue++;
}
