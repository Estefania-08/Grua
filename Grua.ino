#include <Servo.h>

Servo servo1;
Servo servo2;

int eje1 = 90; 
int eje2 = 90; 

const int botonPin = 8; 
const int umbralBajo = 200; 
const int umbralAlto = 700; 

void setup() {  
  servo1.attach(7);
  servo2.attach(6);
  pinMode(botonPin, INPUT_PULLUP); 

  servo1.write(90);
  servo2.write(90);
}

void loop() {
  if (digitalRead(botonPin) == LOW) { 
    if (eje1 < 180) {
      eje1++; 
    }
    if (eje2 > 0) {
      eje2--; 
    }
    servo1.write(eje1);
    servo2.write(eje2);
    delay(15);
  } else { 
    if (analogRead(0) < umbralBajo && eje1 < 180) {
      eje1++;
      servo1.write(eje1);
    }
    if (analogRead(0) > umbralAlto && eje1 > 0) {
      eje1--;
      servo1.write(eje1);
    }
    if (analogRead(1) < umbralBajo && eje2 < 180) {
      eje2++;
      servo2.write(eje2);
    }
    if (analogRead(1) > umbralAlto && eje2 > 0) {
      eje2--;
      servo2.write(eje2);
    }
    delay(15);
  }
}
