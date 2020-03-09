#include <SPI.h>

//global variable declarations start

//state machine
bool initalBoot = true;
bool waitStage = false;
bool feederStage = false;
bool scanStage = false;
bool verificationStage = false;
bool packStage = false;


int pixySelect = 49; //change as required for mega/controllino board mapping


//for serial communication
String inputString = "";         // a string to hold incoming data
bool stringComplete = false;  // whether the string is complete
String commandString = "";

//single data frame for AI, initially set at 50

int dataFrameRunning[1][50][12] =  {{{0}}};


//global variable declarations end


void setup() {
  // put your setup code here, to run once:

if(initalBoot){
// run upon inital boot

 Serial.begin(9600); // communicate with host PC
 Serial1.begin(9600); 
 Serial2.begin(9600);



  pinMode(A0, INPUT);
  pinMode(A1, INPUT);  
  pinMode(A2, INPUT);
  pinMode(A3, INPUT); 
  pinMode(A4, INPUT); 
  pinMode(A5, INPUT); 
  pinMode(A6, INPUT); 
  pinMode(A7, INPUT); 
  pinMode(A8, INPUT); 
  pinMode(A9, INPUT);  
  pinMode(A10, INPUT); 
  pinMode(A11, INPUT);


  initalBoot =false;
  waitStage =  true;

}
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