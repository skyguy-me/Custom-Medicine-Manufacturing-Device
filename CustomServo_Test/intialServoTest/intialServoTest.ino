void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);                                                                                                                                                                                                                                        
  pinMode(2, OUTPUT);
}

void loop() {

  // put your main code here, to run repeatedly:
  analogWrite(2, 255);
  Serial.println("running");
  delay(2500);
  analogWrite(2, 0);
  Serial.println("stopped");
  
  delay(2500);

}
