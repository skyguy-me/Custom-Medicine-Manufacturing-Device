//Project Designer Drugs: Assembling Custom Dosed Personal Medicines
//NUS ESP3903 project in pursuit of Bachelor of Engineering in Engineering Science
//Primary Author and Inital Code by Gokul Nathan
//
//Author(s): Gokul Nathan
//

//device starts
int scannerStart_IntteruptPin = 22; //change as required for mega/controllino board mapping
//int dataFrameRunning[1][25][11] = {{{0}}};
int compressedDataFrame[1][275] = {{0}}; //lower spec training data
int liveDataFrame[275] = {0};
//device ends

//single data frame for AI, initially set at 50
//int DAQ_Frame[10][50][12] = {{{0}}};
//end data frame

//state control
bool DAQstart = true;
bool transmitData = false;

//start of composite result frame
String predictor = "empty"; //change to indicate desired outcome
//end of composite result frame

//start of index variables
int x, y, z, i, j, k = 0;
//end of index variables



const int buttonPin = 2;
const int buttonPin2 = 13;
int buttonState = 0;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);

  k = 0;

  pinMode(buttonPin, INPUT);

  pinMode(buttonPin2, INPUT);

  attachInterrupt(digitalPinToInterrupt(scannerStart_IntteruptPin), scannerStart_Interrupt, FALLING);

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

}

void loop()
{

  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    DAQstart = true;
  }
  buttonState = digitalRead(buttonPin2);
  if (buttonState == HIGH) {
    transmitData = true;
  }



  if (DAQstart == true) {
    for (j = 0; j < 275; j++)
    {
      switch (j % 11)
      {

        case 0:
          liveDataFrame[x] = analogRead(A0);
          x++;
          break;

        case 1:
          liveDataFrame[x] = analogRead(A1);
          x++;
          break;

        case 2:
          liveDataFrame[x] = analogRead(A2);
          x++;
          break;

        case 3:
          liveDataFrame[x] = analogRead(A3);
          x++;
          break;

        case 4:
          liveDataFrame[x] = analogRead(A4);
          x++;
          break;

        case 5:
          liveDataFrame[x] = analogRead(A5);
          x++;
          break;
        case 6:
          liveDataFrame[x] = analogRead(A6);
          x++;
          break;

        case 7:
          liveDataFrame[x] = analogRead(A7);
          x++;
          break;

        case 8:
          liveDataFrame[x] = analogRead(A8);
          x++;
          break;

        case 9:
          liveDataFrame[x] = analogRead(A9);
          x++;
          break;

        case 10:
          liveDataFrame[x] = analogRead(A10);
          x++;
          break;
      }
    }
    DAQstart = false;
  }

  if (transmitData == true) {
    for (i = 0; i < 275; i++)
    {

      if (i % 11 == 0) {
        Serial.println("");

        Serial.print(String(liveDataFrame[i]));
      }
      else {
        Serial.print("," + String(liveDataFrame[i]));
      }


    }
    transmitData = false;
  }
  j = x = k = i = 0;
}

void scannerStart_Interrupt()
{
  Serial.println("interrupt");
  DAQstart = true;
}
