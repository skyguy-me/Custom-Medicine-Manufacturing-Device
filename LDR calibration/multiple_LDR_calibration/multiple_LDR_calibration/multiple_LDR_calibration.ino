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


  sensorValue = analogRead(A0);
  voltage = sensorValue * (5.0 / 1023.0);
  stringValue += String(voltage) + ",";

  sensorValue = analogRead(A1);
  voltage = sensorValue * (5.0 / 1023.0);
  stringValue += String(voltage) + ",";


  sensorValue = analogRead(A2);
  voltage = sensorValue * (5.0 / 1023.0);
  stringValue += String(voltage) + ",";


  sensorValue = analogRead(A3);
  voltage = sensorValue * (5.0 / 1023.0);
  stringValue += String(voltage) + ",";


  sensorValue = analogRead(A4);
  voltage = sensorValue * (5.0 / 1023.0);
  stringValue += String(voltage) + ",";


  sensorValue = analogRead(A5);
  voltage = sensorValue * (5.0 / 1023.0);
  stringValue += String(voltage) + ",";


  sensorValue = analogRead(A6);
  voltage = sensorValue * (5.0 / 1023.0);
  stringValue += String(voltage) + ",";


  sensorValue = analogRead(A7);
  voltage = sensorValue * (5.0 / 1023.0);
  stringValue += String(voltage) + ",";



  sensorValue = analogRead(A8);
  voltage = sensorValue * (5.0 / 1023.0);
  stringValue += String(voltage) + ",";


  sensorValue = analogRead(A9);
  voltage = sensorValue * (5.0 / 1023.0);
  stringValue += String(voltage) + ",";
  //
  //  sensorValue = analogRead(A10);
  //  voltage = sensorValue * (5.0 / 1023.0);
  //  stringValue += String(voltage) + ",";

  stringValue += "NIL"; // currently used for empty calibration
    Serial.println(stringValue);
  // delay(1000);
  stringValue = "";
  //delay(1000);
  stringValue = "";
}
