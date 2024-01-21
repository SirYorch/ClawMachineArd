const int receptorPinAnalogico = A0;  // Conectar el pin analógico del fotodiodo o fototransistor al pin A0

void setup() {
  pinMode(receptorPinAnalogico, INPUT);
  Serial.begin(9600);
}

void loop() {
  int valorSensor = analogRead(receptorPinAnalogico);
  
  if (valorSensor < 450) {  // Ajusta este valor según tus necesidades y la respuesta de tu sensor
    Serial.println("¡Obstrucción detectada!");
    delay(700);
  }
  
}

// este Codigo esta preparado para la conexion del led receptor en puerto A0, y leds, en donde, el receptor infrarojo tiene una resistencia de 1k
// y el led que le sigue, tiene una resistencia de 270.

// por  parte del emisor 680 para el led, y una de 2700 para el led 
