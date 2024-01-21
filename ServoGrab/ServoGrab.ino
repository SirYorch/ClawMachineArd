#include <Servo.h>

const int pulsador = 4;

//Todos van a ir a la misma señal, lo que debemos controlar es el voltaje.

Servo garra;

void setup() {
  // put your setup code here, to run once:
  garra.attach(5);
  pinMode(pulsador, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(pulsador) == HIGH){
    metodoAgarrar();
    delay(1000);
  }else {}
}


void metodoAgarrar(){
  //espera 10 segundos, tiempo en que la garra baja, despues es posible que debmoa borrar la linea.

  garra.write(180);
  delay(200);// tiempo para que la garra capture el objeto
  garra.write(90);
  delay(3000);// tiempo que el premio se encuentra agarrado
  garra.write(0);
  delay(200);// tiempo para que la garra vuelva a la posicion inicial;
  
  garra.write(90);// la garra vuelve a quedar estatica.
  
  


}