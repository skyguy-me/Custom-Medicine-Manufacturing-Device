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
int dataFrameRunning[1][50][12] = {{{0}}};
//end data frame




void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

}
