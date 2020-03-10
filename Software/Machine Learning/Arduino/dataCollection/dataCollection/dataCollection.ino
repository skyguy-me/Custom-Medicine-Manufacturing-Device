//Project Designer Drugs: Assembling Custom Dosed Personal Medicines
//NUS ESP3903 project in pursuit of Bachelor of Engineering in Engineering Science
//Primary Author and Inital Code by Gokul Nathan
//
//Author(s): Gokul Nathan
//


//device starts
int linearIntteruptPin = 35; //change as required for mega/controllino board mapping
//device ends

//single data frame for AI, initially set at 50
int DAQ_Frame[100][50][12] = {{{0}}};
//end data frame

//state control


//start of composite result frame 
String predictor = "empty"; //change to indicate desired outcome 
//end of composite result frame


//start of index variables
int x,y,z,i,j,k = 0;
//end of index variables





void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
if (digitalRead(linearIntteruptPin) == 1){

}

}
