//include <Controllino.h>
#include <SPI.h>

//global variable declarations start

//state machine
bool initalBoot = true;
bool waitStage = false;
bool feederStage = false;
bool scanStage = false;
bool verificationStage = false;
bool packStage = false;
//state machine end

//scan flags start
bool startScan = false;
bool scanned = false;
//scan flags end

int pixySelect = 49; //change as required for mega/controllino board mapping

//for serial communication
String inputString = "";     // a string to hold incoming data
bool stringComplete = false; // whether the string is complete
String commandString = "";

int linearIntteruptPin = 35; //change as required for mega/controllino board mapping

//single data frame for AI, initially set at 50
int dataFrameRunning[1][50][12] = {{{0}}};

int i = 0;
int j;
int x = 0;
int y = 0;

//global variable declarations end

void setup()
{
  // put your setup code here, to run once:

  if (initalBoot)
  {
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

    initalBoot = false;
    waitStage = true;
  }
  //  SPI.transfer(0x00); //SPI communication with pixy
}

void loop()
{

  if (waitStage)
  {
    //default state to always wait for input from host PC for allowing the feeder to load x balls as requested by host PC

    if (commandString.equals("MOTO"))
    {
      String text = getTextNumber();
      recievedString = text;
      float data = (float)text.toFloat();
      Serial.print("Float sent");
      Serial.print(data);
      Serial.print("\n");
      // setVoltage(data);
    }
    inputString = "";
    commandString = "";
  }

  while (feederStage)
  {
  }

  while (scanStage)
  {
    if (digitalRead(linearIntteruptPin) == HIGH)
    { //randomly assigned pin 35
      startScan = true;
    }

    while (startScan)
    {
      //to capture and store 50 LDR frames and push for data verification stage
      float time = micros();
      while (!scanned)
      {
        for (i = 0; i < 50; i++)
        {
          for (j = 0; j < 12; j++)
          {
            switch (j)
            {
            case 0:
              dataFrameRunning[1][i][j] = analogRead(A0);
              //  Serial.print(String(dataFrameRunning[1][i][j] = analogRead(A0))); //use for debugging
              break;
            case 1:
              dataFrameRunning[1][i][j] = analogRead(A1);
              // Serial.print("," + String(dataFrameRunning[1][i][j] = analogRead(A1)));
              break;
            case 2:
              dataFrameRunning[1][i][j] = analogRead(A2);
              //  Serial.print("," + String(dataFrameRunning[1][i][j] = analogRead(A2)));
              break;
            case 3:
              dataFrameRunning[1][i][j] = analogRead(A3);
              // Serial.print("," + String(dataFrameRunning[1][i][j] = analogRead(A3)));
              break;
            case 4:
              dataFrameRunning[1][i][j] = analogRead(A4);
              // Serial.print("," + String(dataFrameRunning[1][i][j] = analogRead(A4)));
              break;
            case 5:
              dataFrameRunning[1][i][j] = analogRead(A5);
              //   Serial.print("," + String(dataFrameRunning[1][i][j] = analogRead(A5)));
              break;
            case 6:
              dataFrameRunning[1][i][j] = analogRead(A6);
              //Serial.print("," + String(dataFrameRunning[1][i][j] = analogRead(A6)));
              break;
            case 7:
              dataFrameRunning[1][i][j] = analogRead(A7);
              // Serial.print("," + String(dataFrameRunning[1][i][j] = analogRead(A7)));
              break;
            case 8:
              dataFrameRunning[1][i][j] = analogRead(A8);
              //  Serial.print("," + String(dataFrameRunning[1][i][j] = analogRead(A8)));
              break;
            case 9:
              dataFrameRunning[1][i][j] = analogRead(A9);
              // Serial.print("," + String(dataFrameRunning[1][i][j] = analogRead(A9)));
              break;
            case 10:
              dataFrameRunning[1][i][j] = analogRead(A10);
              //Serial.print("," + String(dataFrameRunning[1][i][j] = analogRead(A10)));
              break;
            case 11:
              dataFrameRunning[1][i][j] = analogRead(A11);
              //Serial.print("," + String(dataFrameRunning[1][i][j] = analogRead(A11)));
              break;
            case 12:
              dataFrameRunning[1][i][j] = analogRead(A12);
              //Serial.print("," + String(dataFrameRunning[1][i][j] = analogRead(A12)) + "\n");
              break;
            }
          }
          // Serial.print("\n");
          scanned = true;
        }
        //    i = 0;
        // Serial.println("time to complete = " + String(time = micros() - time) + " microseconds"); // speed check
      }
      startScan = false;
    }
  }
  if (packStage)
  {
  }
}

//retrieve command from incoming string
void getCommand()
{
  if (inputString.length() > 0)
  {
    commandString = inputString.substring(1, 5);
  }
}

//retrieve numerical values from string;
String getTextNumber()
{
  String value = inputString.substring(5, inputString.length() - 1);
  recievedString = value;

  float data = (float)recievedString.toFloat();
  return value;
}

//Serial event handlers start
void serialEvent()
{
  while (Serial.available())
  {
    char inChar = (char)Serial.read();
    // Serial.println(inChar);
    inputString += inChar;
    if (inChar == '\n')
    {
      stringComplete = true;
      Serial.println(stringComplete);
    }
  }
}
void serialEvent1()
{
  while (Serial1.available())
  {
    char inChar = (char)Serial1.read();
    // Serial.println(inChar);
    inputString += inChar;
    if (inChar == '\n')
    {
      stringComplete = true;
      Serial.println(stringComplete);
    }
  }
}
void serialEvent2()
{
  while (Serial2.available())
  {
    char inChar = (char)Serial2.read();
    // Serial.println(inChar);
    inputString += inChar;
    if (inChar == '\n')
    {
      stringComplete = true;
      Serial.println(stringComplete);
    }
  }
}
//Serial event handlers end