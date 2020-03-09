// the setup routine runs once when you press reset:

void setup() {

  // initialize serial communication at 9600 bits per second:

  pinMode(13, OUTPUT);

  Serial.begin(9600);

}

// the loop routine runs over and over again forever:

void loop() {

  // read the input on analog pin 1:

  int sensorValue = analogRead(A1);

  Serial.println(sensorValue);

  if (sensorValue < 240) {
    digitalWrite(13, HIGH);
  }

  else if (sensorValue >= 240) {
    digitalWrite(13, LOW);
  }

  delay(300);



}
