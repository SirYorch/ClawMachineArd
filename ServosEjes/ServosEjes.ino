#include <Servo.h>
Servo servoX;
Servo servoY;
const int s1 = 3;
const int s2 = 5;
const int movX = A0;
const int movY = A1;



void setup() {
  // put your setup code here, to run once:
  servoX.attach(3);
  servoY.attach(5);
}

void loop() {
  // put your main code here, to run repeatedly:
  int X = analogRead(movX);
  int Y = analogRead(movY);

  int movimientoX = map(X,0,1023,0,5);
  int movimientoY = map(Y,0,1023,0,5);

  if(movimientoX>2){
    servoX.write(0);
  } else if(movimientoX<2){
    servoX.write(180);
  } else {
    servoX.write(90);
  }
  if(movimientoY>2){
    servoY.write(0);
  } else if(movimientoY<2){
    servoY.write(180);
  } else {
    servoY.write(90);
  }
}
