#include "MotorDriver.h"

MotorDriver motor;

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
String commandString = "";
String seccommandString = "";

bool Standby = true; //states
bool Pack = false;

void getCommand();

int dispenseNum = 0; //number of balls to dispense
bool trigger;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7, INPUT);
  motor.begin();
  motor.speed(0, 0);

}

void loop() {
  // put your main code here, to run repeatedly:

  if (Standby) {
    if (stringComplete) {
      stringComplete = false;
      getCommand();

      Serial.println("Standing By");
      Serial.println(inputString);
      Serial.println(commandString);
      Serial.println(seccommandString);


      if (commandString == "PACK") {
        if (seccommandString == "NULL") {
          dispenseNum = getTextNumber();
          Serial.println(dispenseNum, DEC);
          Standby = false; Pack = true;
        }
      }
      inputString = "";
    }
  }

  if (Pack) {
    Serial.println("PACKING");
    motor.speed(0, 255);
    delay(10000);
    motor.brake(0);
    Serial.println("PACKING END");
    Pack = false; Standby = true;
  }
}





int getTextNumber()
{
  String value = inputString.substring(9, inputString.length() - 1);
  //Serial.println(value);
  int data = value.toInt();
  return data;
}

void getCommand() {
  if (inputString.length() > 0)
  {
    commandString = inputString.substring(1, 5);
    seccommandString = inputString.substring(5, 9);
  }
}

void serialEvent() {
  //Serial.println("serialEvent");
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    //Serial.println(inChar);
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
      Serial.println("stringComplete");
      Serial.println(inputString);
    }
  }
}
