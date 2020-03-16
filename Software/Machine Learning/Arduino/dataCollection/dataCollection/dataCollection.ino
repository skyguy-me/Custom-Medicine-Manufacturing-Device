//Project Designer Drugs: Assembling Custom Dosed Personal Medicines
//NUS ESP3903 project in pursuit of Bachelor of Engineering in Engineering Science
//Primary Author and Inital Code by Gokul Nathan
//
//Author(s): Gokul Nathan
//

//device starts
int scannerStart_IntteruptPin = 20; //change as required for mega/controllino board mapping
int dataFrameRunning[1][25][11] = {{{0}}};
int compressedDataFrame[][275] = {{0}}; //lower spec training data
int liveDataFrame[275] = {0};
//device ends

//single data frame for AI, initially set at 50
int DAQ_Frame[10][50][12] = {{{0}}};
//end data frame

//state control
bool DAQstart = false;
bool transmitData = false;

//start of composite result frame
String predictor = "empty"; //change to indicate desired outcome
//end of composite result frame

//start of index variables
int x, y, z, i, j, k = 0;
//end of index variables

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);

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
}

void loop()
{

  while (DAQstart)
  {
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
      k++;
      DAQstart = false;
    }

    if (k == 10)
    {
      transmitData = true;
      ;
    }
  }

  while (transmitData) //used to print data into csv for export. allDataArray = {[50x12],[50x12]..(total = first index length of DAQFrame)...[50x12]}
  {
    for (x = 0; x < k; x++)
    {
      Serial.print("[");
      for (y = 0; y < 50; y++)
      {
        for (z = 0; i < 12; z++)
        {
          Serial.print("," + String(DAQ_Frame[x][y][z]));
        }
        Serial.print(";");
      }
      Serial.print("]");
    }
  }
}

void scannerStart_Interrupt()
{
  DAQstart = true;
}