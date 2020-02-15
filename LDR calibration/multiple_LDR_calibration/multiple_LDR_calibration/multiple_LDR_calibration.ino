String stringTitle = "A1,A2,A3,A4,A5,A7,A8,A8,A10";
String stringValue = "";

int sensorCount = 10;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);



}

void loop() {

  int index = 0;
  int sensorValue;
  float voltage;

  for(index = 0;index<sensorCount;index++){  voltage = sensorValue * (5.0 / 1023.0);
}





  stringValue += voltage.ToString() + ",";
  delay(100);
  Serial.println(voltage);
}
