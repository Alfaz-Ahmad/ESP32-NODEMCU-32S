#include<IRremote.h>

int receiver = 33;  
int relayPin = 4;
int btnPin = 2;

bool LED = false;
unsigned long press;

long currTime;
long prevTime;
int interval = 50;

int val;

IRrecv irrecv(receiver);

void setup()                 
{
  pinMode(relayPin, OUTPUT); 
  pinMode(btnPin, INPUT_PULLUP);
  Serial.begin(9600);
  prevTime = millis();
  val = HIGH;
  irrecv.enableIRIn();                       
}

void loop()                              
{
  val = digitalRead(btnPin);
  if(val == LOW){
    while(val == LOW){
      val = digitalRead(btnPin);
    }
    currTime = millis();
    if(val == HIGH && currTime - prevTime >= interval){
      prevTime = currTime;
      if(LED){
        digitalWrite(relayPin, LOW);
        LED = !LED;
      }else{
        digitalWrite(relayPin, HIGH);
        LED = !LED;
      }
    }
  }
  if (irrecv.decode()){
    press = irrecv.decodedIRData.decodedRawData;
    Serial.println(press);
    if(press == 3910598400){
      if(LED){
        digitalWrite(relayPin, LOW);
        LED = !LED;
      }else{
        digitalWrite(relayPin, HIGH);
        LED = !LED;
      }
    }
    irrecv.resume();
  }
}
