
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
String commandString = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (stringComplete)
  {

    stringComplete = false;
    getCommand();

    if (commandString.equals("30P3"))
    {
  //    Serial.print("30P3");
    }
    else if (commandString.equals("35P3"))
    {
//      Serial.print("35P3");
    }

    Serial.println(inputString);
    inputString = "";
    Serial.println(inputString);
  }
}

void getCommand()
{
  if (inputString.length() > 0)
  {
    commandString = inputString.substring(1, 5);
  }
}

void serialEvent1() {
  while (Serial1.available()) {
    char inChar = (char)Serial1.read();
   // Serial.println(inChar);
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    Serial.println(stringComplete);
    }
  }
}
