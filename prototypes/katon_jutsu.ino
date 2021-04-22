#include <Servo.h>

Servo Servo1;

// Components Pins
const int sig = A4;   // Relay Module
const int fire = 4;   // Servo
const int butt = 2;   // Button

int s_butt = 0;

// Servos angle to ON/OFF
int ser_on = 53;
int ser_off = 90;

void setup(){
  Serial.begin(9600);
  Servo1.attach(fire);
  pinMode(sig, OUTPUT);
  pinMode(butt, INPUT);  
}

void loop(){
  s_butt = digitalRead(butt);

  if (s_butt == HIGH)
  {
    // Relay ON
    digitalWrite(sig, LOW);
    Serial.println("Relay ON");

    delay(300);
    
    // FIRE ON
    Servo1.write(ser_on);
    Serial.println("Katon Goukakyuu no Jutsu!");

    delay(1000);
   
    // Relay OFF
    digitalWrite(sig, HIGH);
    Serial.println("Relay OFF");
    
    delay(500);
    
    // FIRE OFF
    Servo1.write(ser_off);
    Serial.println("Insufficient Chakra!");
  }
}
