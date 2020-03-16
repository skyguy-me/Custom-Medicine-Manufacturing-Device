#include "MotorDriver.h"

MotorDriver motor;

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
String commandString = "";
String seccommandString = "";

bool Standby = true; //states
bool Dispense = false;

void getCommand();

int dispenseNum = 0; //number of balls to dispense
bool trigger;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7, INPUT);
  motor.begin();

}

void loop() {
  // put your main code here, to run repeatedly:

  if (Standby) {
    Serial.println("Standing By");
    if (stringComplete) {
      stringComplete = false;
      getCommand();

      Serial.println("Standing By");
      Serial.println(inputString);
      Serial.println(commandString);
      Serial.println(seccommandString);


      if (commandString == "DISP") {
        if (seccommandString == "RRED" || seccommandString == "BLUE" || seccommandString == "GREN") {
          dispenseNum = getTextNumber();
          Serial.println(dispenseNum, DEC);
          Standby = false; Dispense = true;
        }
      }
      inputString = "";
    }
  }

  if (Dispense) {
    Serial.println("DISPENSING");
    while (dispenseNum != 0) {

      motor.speed(0, 255);
      trigger = digitalRead(7);
      if (trigger == HIGH) {
        dispenseNum--;
        delay(1000); //for button testing, otherwise one push depletes fast
        Serial.println(dispenseNum, DEC);
      }
    }
    Dispense = false; Standby = true;
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
