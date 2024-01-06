const int angleX = A0;
const int angleY = A1;
const int l1 =2 ;
const int l2 =3;
const int l3 =4;
const int l4 = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
  pinMode(l3,OUTPUT);
  pinMode(l4,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int anguX = analogRead(angleX);
  int anguY = analogRead(angleY);
  int angX = map(anguX, 0, 1023, 1, 5);
  int angY = map(anguY, 0, 1023, 1, 5);

  if(angX > 2){
    digitalWrite(l1,HIGH);
  } else if (angX < 2){
    digitalWrite(l3,HIGH);
  } else {
    digitalWrite(l1,LOW);
    digitalWrite(l3,LOW);
  }
  
  if(angY > 2){
    digitalWrite(l2,HIGH);
  } else if (angY < 2){
    digitalWrite(l4,HIGH);
  } else {
    digitalWrite(l2,LOW);
    digitalWrite(l4,LOW);
  }
}
