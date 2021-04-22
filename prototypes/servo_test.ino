#include <Servo.h>

Servo servo;

// Servo pin
const int serv = 4; 

// On and Off of the Plasma Lighter
const int on = 53;
const int off = 90;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(serv);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    char value = Serial.read();

    if (value == 'O')
    {
      servo.write(on);
      delay(1000);
      servo.write(off);
    }
  }
}
