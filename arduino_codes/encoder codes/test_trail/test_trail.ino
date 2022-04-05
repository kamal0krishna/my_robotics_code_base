//these pins can not be changed 2/3 are special pins
int encoderPin1 = 2;
int encoderPin2 = 3;
int encodervalue1 = 0;
int encodervalue2 = 0;


void setup() {
  Serial.begin (9600);
  
  pinMode(encoderPin1, INPUT); 
  pinMode(encoderPin2, INPUT); 
  
  //call updateEncoder() when any high/low changed seen
  //on interrupt 0 (pin 2), or interrupt 1 (pin 3) 
  attachInterrupt(digitalPinToInterrupt(encoderPin1), updateEncoderValue1, CHANGE); 
  attachInterrupt(digitalPinToInterrupt(encoderPin2), updateEncoderValue2, RISING);

}

void loop(){ 
      Serial.print(encodervalue1);
      Serial.print('\t');
      Serial.print(encodervalue2);
      Serial.print('\n');
  delay(1000); //just here to slow down the output, and show it will work  even during a delay
}


void updateEncoderValue1(){
  encodervalue1++;

}

void updateEncoderValue2(){
  encodervalue2++;
}
