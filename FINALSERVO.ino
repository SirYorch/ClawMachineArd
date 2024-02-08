#include <Servo.h>

int sensor = A3;
int umbral = 220;

int sensor1 = A2;
int umbral1 = 10;
bool monedaDetectada = false;
bool objeto = false;
int lectura = 0;
int lectura1 = 0;

const int pulsador = 4;

Servo garra;
Servo carrete;

const int movX = A0;
const int movZ = A1;

Servo servoX;
Servo servoZ;

void setup() {
  carrete.attach(10);
  garra.attach(9);
  pinMode(pulsador, INPUT);
  Serial.begin(9600);
  garra.write(30);
  servoX.attach(3);
  servoZ.attach(5);
}

void loop() {
  lectura = analogRead(sensor);
  //Serial.println(lectura);
  detectarMoneda1(lectura, umbral);
  int boton =0;

  while (monedaDetectada == true) {
    lectura = analogRead(sensor);
    if(analogRead(sensor)<umbral){
        Serial.println("Fraude");
        delay(300);
        
        monedaDetectada=false;
        break;
      }
    int X = analogRead(movX);
    int Z = analogRead(movZ);
    int movimientoX = map(X, 0, 1023, 0, 12);
    int movimientoZ = map(Z, 0, 1023, 0, 12);
    //Serial.println(movimientoX);
    //Serial.println(movimientoZ);
    delay(200);

    if (movimientoX > 8) {
      servoX.write(0);
    } else if (movimientoX < 3) {
      servoX.write(180);
    } else {
      servoX.write(90);
    }

    if (movimientoZ > 9) {
      servoZ.write(0);
    } else if (movimientoZ < 4) {
      servoZ.write(180);
    } else {
      servoZ.write(90);
    }

    if (digitalRead(pulsador) == HIGH && boton ==0) {
      // subir carrete
      carrete.write(0);
      delay(4400);
      carrete.write(90);
      delay(200);

      metodoAgarrar();
      carrete.write(180);
      delay(4350);
      carrete.write(90);
      boton++;

    }else if(digitalRead(pulsador) == HIGH && boton ==1) {
      
      metodoSoltar();
      boton =0;
      monedaDetectada=false;
      break;
      }
    
    // Leer el segundo sensor
    
  }
}

void metodoAgarrar() {
  garra.write(90);
}

void metodoSoltar() {
  delay(1000);
  garra.write(30);
  int contador =0;
  while(objeto==false){
      lectura1= analogRead(sensor1);
      if (lectura1 < umbral1) {
        Serial.println("¡Objeto detectado!");
        // Reiniciar la detección de moneda y salir del bucle
        monedaDetectada = false;
        break;
      }
      else{
          contador++;
          delay(2);
          if(contador>3000){
              Serial.println("OBjeto no detectado");
              monedaDetectada = false;
              break;
            }

          
        }
    }
}

unsigned long ultimaDeteccion = 0; // Variable para almacenar el tiempo de la última detección de moneda

void detectarMoneda(int lectura, int umbral) {
  if (lectura < umbral) {
    // Si se detecta la moneda
    unsigned long tiempoActual = millis();
    if (tiempoActual - ultimaDeteccion > 1000) {
      // Si ha pasado al menos 1 segundo desde la última detección de moneda, se considera como una nueva detección válida
      Serial.println("¡Moneda detectada!");
      monedaDetectada = true;
      ultimaDeteccion = tiempoActual; // Actualizar el tiempo de la última detección de moneda
    } else {
      // Si se detecta la moneda nuevamente dentro de 1 segundo, se considera como un fraude
      Serial.println("Fraude: La moneda ha regresado!");
      monedaDetectada = false;
    } delay(300);
  } else {
    monedaDetectada = false;
  }
}
void detectarMoneda1(int lectura, int umbral) {
  if (lectura < umbral) {
      Serial.println("¡Moneda detectada!");
      monedaDetectada = true;
      delay(300);
  } 
}
