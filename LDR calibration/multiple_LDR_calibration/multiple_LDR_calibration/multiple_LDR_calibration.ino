String stringTitle = "A0,A1,A2,A3,A4,A5,A6,A7,A8,A8,OUTCOME";
String stringValue = "";

int sensorCount = 10;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(stringTitle);



}

void loop() {

  int index = 0;
  int sensorValue;
  float voltage;

  for (index = 0; index < sensorCount; index++) {
    String sensorCode = "A" + String(index);

    //check sensorcode
    //Serial.println(sensorCode);

    //read sesnor value and convert to voltage
    sensorValue = analogRead(sensorCode.toInt());
    voltage = sensorValue * (5.0 / 1023.0);
    stringValue += String(voltage) + ",";
  }
    stringValue += "NIL"; // currently used for empty calibration
  Serial.println(stringValue);
  delay(1000);
  stringValue="";
}
