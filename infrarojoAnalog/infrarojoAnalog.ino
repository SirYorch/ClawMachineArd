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