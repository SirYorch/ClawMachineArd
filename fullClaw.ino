#include <Servo.h>

const int infrarojoCoin = A0;  // pin analógico Entrada
const int infrarojoOut = A1;   // pin analógico salida
const int infrarojoX = A2;     // pin analógico limiteX
const int infrarojoZ = A3;     // pin analógico limiteZ
const int button = 2;


Servo servoX;
Servo servoZ;
const int s1 = 3;
const int s2 = 5;
const int movX = A4;
const int movZ = A5;




const int sensorCoin = 450;  // valor de lectura de obstrucción del sensor de moneda
const int sensorOut = 450;   // valor de lectura de obstrucción del sensor de salida
const int sensorX = 450;     // valor de lectura de conducción del limite X
const int sensorZ = 450;     // valor de lectura de conducción del limite Z



void setup() {
  pinMode(infrarojoCoin, INPUT);
  pinMode(infrarojoOut, INPUT);
  pinMode(infrarojoX, INPUT);
  pinMode(infrarojoZ, INPUT);

  pinMode(button, INPUT);

  servoX.attach(3);  // servo eje y
  servoY.attach(5);  // servo eje z





  Serial.begin(9600);  // abierto solo para fines didacticos en pruebas;
}

void loop() {
  int valorSensor = analogRead(infrarojoCoin);

  if (valorSensor < sensorCoin) {  // Ajusta este valor según tus necesidades y la respuesta de tu sensor
    Serial.println("¡Obstrucción detectada!");
    encendido();
    delay(700);  // delay para que no buguee.
  }
}

void encendido() {
  bool activo = true;

  delay(200);

  while (activo) {
    int valorSensor = analogRead(infrarojoCoin);
    int X = analogRead(movX);
    int Z = analogRead(movZ);


    if (valorSensor < sensorCoin) {  // Ajusta este valor según tus necesidades y la respuesta de tu sensor
      Serial.println("¡Obstrucción detectada!");
      terminarJuego(3)
        delay(700);  // delay para que no buguee.
    }


    if (digitalRead(button) == HIGH) {
      activo = false;

      /// for para revisar si algo cayó en la salida y enviar el terminarJuego 1 o 2;
    }

    int movimientoX = map(X, 0, 1023, 0, 12);
    int movimientoZ = map(Z, 0, 1023, 0, 12);

    if (movimientoX >= 8) {
      servoX.write(0);
    } else if (movimientoX <= 3) {
      servoX.write(180);
    } else {
      servoX.write(90);
    }
    if (movimientoZ >= 8) {
      servoY.write(0);
    } else if (movimientoZ <= 3) {
      servoY.write(180);
    } else {
      servoY.write(90);
    }
  }
}

void terminarJuego(int numero) {
  // bajar carrete

  metodoAgarrar();

  // subir carrete

  // colocar eje X

  // colocar eje Z

  metodoSoltar();
}



void metodoAgarrar(){
  

  garra.write(90);
  
}
void metodoSoltar(){
  garra.write(30);

}