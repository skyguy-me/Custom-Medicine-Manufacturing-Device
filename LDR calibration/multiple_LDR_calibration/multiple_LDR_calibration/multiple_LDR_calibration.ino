void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  String stringOne = "A long integer: ";

}

void loop() {

  int sensorValue = analogRead(A0);

  float voltage = sensorValue * (5.0 / 1023.0);
  delay(100);
  Serial.println(voltage);
}
