#include "MotorDriver.h"

MotorDriver motor;

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
String commandString = "";
String seccommandString = "";

bool Standby = true; //states
bool Dispense = false;

int dispenseNum = 0; //number of balls to dispense
bool trigger;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A7,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  while (Standby) {
    if (stringComplete)
    {
      stringComplete = false;
      getCommand();

      if (commandString.equals("DISP")) {
        if (seccommandString == "RRED" || seccommandString == "GREN" || seccommandString == "BLUE") {
          dispenseNum = getTextNumber();
          Dispense = true; Standby = false;
        }

      }
    }
  }
  while (Dispense) {
    while (dispenseNum != 0) {
      motor.speed(0, 255);
      trigger = analogRead(A7);
      if (trigger >= 0) {
        dispenseNum--;
      }
    }
    Standby = true; Dispense = false;
  }
}

int getTextNumber()
{
  String value = inputString.substring(9, inputString.length() - 1);
  int data = (int)value.toInt();
  return data;
}

void getCommand()
{
  if (inputString.length() > 0)
  {
    commandString = inputString.substring(1, 5);
    seccommandString = inputString.substring(5, 9);
  }
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    // Serial.println(inChar);
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
      //Serial.println(stringComplete);
    }
  }
}
