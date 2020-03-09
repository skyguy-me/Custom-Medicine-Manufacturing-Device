#include <SPI.h>



//state machine
bool waitStage = true;
bool feederStage = false;
bool scanStage = false;
bool verificationStage = false;
bool packStage = false;


// int MOSI = 51;
// int MISO = 50;
// int SCK = 52;
// int RESET =  48; //change as required for mega/controllino board mapping

int pixySelect = 49; //change as required for mega/controllino board mapping


//for serial communication
String inputString = "";         // a string to hold incoming data
bool stringComplete = false;  // whether the string is complete
String commandString = "";


void setup() {
  // put your setup code here, to run once:

 Serial.begin(9600); // communicate with host PC
 Serial1.begin(9600); 
 Serial2.begin(9600);

//  SPI.transfer(0x00); //SPI communication with pixy
}

void loop() {

  if (waitStage){
    //default state to always wait for input from host PC for allowing the feeder to load x balls as requested by host PC


  }

  if (feederStage){

  }
  if (scanStage){
    //to capture and store 50 LDR frames and push for data verification stage
  }
  if(packStage){

  }

}   




//Serial event handlers start
void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
   // Serial.println(inChar);
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    Serial.println(stringComplete);
    }
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
void serialEvent2() {
  while (Serial2.available()) {
    char inChar = (char)Serial2.read();
   // Serial.println(inChar);
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    Serial.println(stringComplete);
    }
  }
}
//Serial event handlers end