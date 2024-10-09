#include <ESP32Servo.h>

int servoPin = 18;
int servoPos = 0;
Servo myServo;
int delayT = 50;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(servoPin, 500, 2500);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.print("What Angle: ");
  // while(Serial.available() == 0){

  // }
  // servoPos = Serial.parseInt();
  // Serial.println(servoPos);


  // myServo.write(servoPos);
  // Serial.println(servoPos);

  for(servoPos =0; servoPos <= 180; servoPos++){
    myServo.write(servoPos);
    delay(delayT);
  }

  for(servoPos=180; servoPos >= 0; servoPos--){
    myServo.write(servoPos);
    delay(delayT);
  }

  // if(servoPos > 5){
  //   servoPos -= 1;
  // }else{
  //   servoPos = 90;
  // }
  // delay(delayT);
}