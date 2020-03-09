char mystr[6] = "#30P3" + "\n"; //String data
char mystr1[6] = "#35P3" + "\n";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial1.write(mystr, 6); //Write the serial data
  Serial.println("message 1 sent");
  delay(1000);
  Serial1.write(mystr1, 6); //Write the serial data
  Serial.println("message 2 sent");

  delay(1000);
}
