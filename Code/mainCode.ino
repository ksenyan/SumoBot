#include <ESP32Servo.h>
#include <ESP32PWM.h>
#include <DabbleESP32.h>

int in1 = 14;
int in2 = 12;
int pos = 90;
int servoPin = 12;

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
Servo myservo;

void setup() {
  
  Serial.begin(115200);
  Dabble.begin("KAESP"); //Bluetooth device name
  myservo.setPeriodHertz(50);  
  myservo.attach(servoPin, 500, 2400);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  myservo.write(90);
}
void loop() {
    /*
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    delay(2000);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    delay(2000);
 */

Dabble.processInput();
/*
if (GamePad.isSquarePressed())
  {
    Serial.print("Square");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }
if (GamePad.isCirclePressed())
  {
    Serial.print("Circle");
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }
 */ 
 if (GamePad.getXaxisData()<0)
  {
    if (pos < 180)
    {
    pos = pos + 1;
    }
  }
  if (GamePad.getXaxisData()>0)
  {
    if (pos > 0){
    pos = pos - 1;
    }
  }

  if (GamePad.getXaxisData()==0)
 {
    pos = 90;
  }
  
  myservo.write(pos); 
}
