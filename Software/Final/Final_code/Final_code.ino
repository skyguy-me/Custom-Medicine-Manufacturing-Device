//Project Designer Drugs: Assembling Custom Dosed Personal Medicines
//NUS ESP3903 project in pursuit of Bachelor of Engineering in Engineering Science
//Primary Author and Inital Code by Gokul Nathan
//
//Author(s): Gokul Nathan
//


//libraries start
#include <I2Cdev.h>
#include <PCA9685.h>
#include <SPI.h>
//#include <MotorDriver.h>
//#include <seeed_pwm.h>
//libraries end

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
//scan flags end

//device starts
int pixySelect = 49;                //change as required for mega/controllino board mapping
int scannerStart_IntteruptPin = 20; //change as required for mega/controllino board mapping
//device ends

//start for serial communication
String inputString = "";     // a string to hold incoming data
bool stringComplete = false; // whether the string is complete
String commandString = "";
String subCommandString = "";
//end for serial communication

//single data frame for AI, initially set at 25
int dataFrameRunning[1][25][11] = {{{0}}};
int compressedDataFrame[][275] = {{0}}; //lower spec training data
int liveDataFrame[275] = {0};
//end data frame

//index variables starts
int i = 0;
int j = 0;
int x = 0;
int y = 0;
//index variables ends

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

    attachInterrupt(digitalPinToInterrupt(scannerStart_IntteruptPin), scannerStart_Interrupt, RISING);

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

  getCommands();

  while (waitStage)
  {
    //default state to always wait for input from host PC for allowing the feeder to load x balls as requested by host PC
    //example func . need to add moto commands from ZH
    if (commandString.equals("TEST"))
    {
      String text = getTextNumber();
      float data = (float)text.toFloat();
      Serial.println(data);
    }

    if (commandString.equals("ENAB"))
    {
      waitStage = false;
      feederStage = true;
    }

    inputString = "";
    commandString = "";
  }
  int itemsToBeScanned = 0;

  while (feederStage)
  {
    getCommands();

    if (commandString.equals("PARA"))
    {
      int dispenseNumber = getNumberText();
      itemsToBeScanned = dispenseNumber;
      getSecondaryCommand();
      if (subCommandString == "RRED")
      {
        serialSend("#DISP" + subCommandString + String(dispenseNumber) + "\n", Serial1); //assume the motor arduino and shield is connected via serial 1
      }
      else if (subCommandString == "RRED")
      {
        serialSend("#DISP" + subCommandString + String(dispenseNumber) + "\n", Serial1); //assume the motor arduino and shield is connected via serial 1
      }
      else if (subCommandString == "GREN")
      {
        serialSend("#DISP" + subCommandString + String(dispenseNumber) + "\n", Serial1); //assume the motor arduino and shield is connected via serial 1
      }
      feederStage = false;
      scanStage = true;
    }
  }

  while (scanStage)
  {
    while (startScan)
    {
      //to capture and store 25 LDR frames and push for data verification stage
      // float time = micros();
      for (i = 0; i < 25; i++)
      {
        for (j = 0; j < 11; j++)
        {
          switch (j)
          {
          case 0:
            compressedDataFrame[1][x] = dataFrameRunning[1][i][j] = analogRead(A0);
            liveDataFrame[x] = analogRead(A0);
            x++;
            //  Serial.print(String(  compressedDataFrame[1][x] = dataFrameRunning[1][i][j] = analogRead(A0))); //use for debugging
            break;

          case 1:
            liveDataFrame[x] = analogRead(A1);
            compressedDataFrame[1][x] = dataFrameRunning[1][i][j] = analogRead(A1);
            // Serial.print("," + String(  compressedDataFrame[1][x] = dataFrameRunning[1][i][j] = analogRead(A1)));
            x++;
            break;

          case 2:
            liveDataFrame[x] = analogRead(A2);
            compressedDataFrame[1][x] = dataFrameRunning[1][i][j] = analogRead(A2);
            //  Serial.print("," + String(  compressedDataFrame[1][x] = dataFrameRunning[1][i][j] = analogRead(A2)));
            x++;
            break;

          case 3:
            liveDataFrame[x] = analogRead(A3);
            compressedDataFrame[1][x] = dataFrameRunning[1][i][j] = analogRead(A3);
            x++;
            // Serial.print("," + String(  compressedDataFrame[1][x] = dataFrameRunning[1][i][j] = analogRead(A3)));
            break;

          case 4:
            liveDataFrame[x] = analogRead(A4);
            compressedDataFrame[1][x] = dataFrameRunning[1][i][j] = analogRead(A4);
            x++;
            // Serial.print("," + String(  compressedDataFrame[1][x] = dataFrameRunning[1][i][j] = analogRead(A4)));
            break;

          case 5:
            liveDataFrame[x] = analogRead(A5);
            compressedDataFrame[1][x] = dataFrameRunning[1][i][j] = analogRead(A5);
            x++;

            //   Serial.print("," + String(  compressedDataFrame[1][x] = dataFrameRunning[1][i][j] = analogRead(A5)));
            break;
          case 6:
            liveDataFrame[x] = analogRead(A6);
            compressedDataFrame[1][x] = dataFrameRunning[1][i][j] = analogRead(A6);
            x++;
            //Serial.print("," + String(  compressedDataFrame[1][x] = dataFrameRunning[1][i][j] = analogRead(A6)));
            break;

          case 7:
            liveDataFrame[x] = analogRead(A7);
            compressedDataFrame[1][x] = dataFrameRunning[1][i][j] = analogRead(A7);
            x++;
            // Serial.print("," + String(  compressedDataFrame[1][x] = dataFrameRunning[1][i][j] = analogRead(A7)));
            break;

          case 8:
            liveDataFrame[x] = analogRead(A8);
            compressedDataFrame[1][x] = dataFrameRunning[1][i][j] = analogRead(A8);
            x++;
            //  Serial.print("," + String(  compressedDataFrame[1][x] = dataFrameRunning[1][i][j] = analogRead(A8)));
            break;

          case 9:
            liveDataFrame[x] = analogRead(A9);
            compressedDataFrame[1][x] = dataFrameRunning[1][i][j] = analogRead(A9);
            x++;
            // Serial.print("," + String(  compressedDataFrame[1][x] = dataFrameRunning[1][i][j] = analogRead(A9)));
            break;

          case 10:
            liveDataFrame[x] = analogRead(A10);
            compressedDataFrame[1][x] = dataFrameRunning[1][i][j] = analogRead(A10);
            x++;
            //Serial.print("," + String(  compressedDataFrame[1][x] = dataFrameRunning[1][i][j] = analogRead(A10)));
            break;
          }
        }
      }
      //    i = 0;
      // Serial.println("time to complete = " + String(time = micros() - time) + " microseconds"); // speed check
      itemsToBeScanned--;
      startScan = false;
    }
    //close current state and prep for next;
    if (itemsToBeScanned == 0)
    {
      scanStage = false;
      verificationStage = true;
    }
  }

  while (verificationStage)
  {
    //code space for ML algortithm as needed
  }

  while (packStage)
  {
    //code for packer
  }
}

//interupt func for scanner optical switch start
void scannerStart_Interrupt()
{
  scanStage = true;
  startScan = true;
}
//interupt func for scanner optical switch end

//retrieve command from incoming string
void getCommands()
{
  if (inputString.length() > 0)
  {
    commandString = inputString.substring(1, 5);
    subCommandString = inputString.substring(5, 9);
  }
}
void getSecondaryCommand()
{
  if (inputString.length() > 0)
  {
    subCommandString = inputString.substring(5, 9);
  }
}

//retrieve numerical values from string;
String getTextNumber()
{
  String value = inputString.substring(9, inputString.length() - 1);
  float data = (float)value.toFloat();
  return value;
}

int getNumberText()
{
  String value = inputString.substring(9, inputString.length() - 1);
  int data = (int)value.toInt();
  return data;
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
      //  Serial.println(stringComplete);
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
      //  Serial.println(stringComplete);
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
      // Serial.println(stringComplete);
    }
  }
}
//Serial event handlers end

//serial transmit handlers start
void serialSend(String myString, Stream &Serialx)
{
  Serialx.write((const char *)&myString, sizeof(myString));
}
//serial transmit handlers end
