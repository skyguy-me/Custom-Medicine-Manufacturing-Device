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
  if (digitalRead(linearIntteruptPin) == 1)
  {
    DAQstart = true;
  }

  while (DAQstart)
  {
    for (i = 0; i < 50; i++)
    {
      for (j = 0; j < 12; j++)
      {
        switch (j)
        {
        case 0:
          DAQ_Frame[k][i][j] = analogRead(A0);
          //  Serial.print(String(DAQ_Frame[1][i][j] = analogRead(A0))); //use for debugging
          break;
        case 1:
          DAQ_Frame[k][i][j] = analogRead(A1);
          // Serial.print("," + String(DAQ_Frame[1][i][j] = analogRead(A1)));
          break;
        case 2:
          DAQ_Frame[k][i][j] = analogRead(A2);
          //  Serial.print("," + String(DAQ_Frame[1][i][j] = analogRead(A2)));
          break;
        case 3:
          DAQ_Frame[k][i][j] = analogRead(A3);
          // Serial.print("," + String(DAQ_Frame[1][i][j] = analogRead(A3)));
          break;
        case 4:
          DAQ_Frame[k][i][j] = analogRead(A4);
          // Serial.print("," + String(DAQ_Frame[1][i][j] = analogRead(A4)));
          break;
        case 5:
          DAQ_Frame[k][i][j] = analogRead(A5);
          //   Serial.print("," + String(DAQ_Frame[1][i][j] = analogRead(A5)));
          break;
        case 6:
          DAQ_Frame[k][i][j] = analogRead(A6);
          //Serial.print("," + String(DAQ_Frame[1][i][j] = analogRead(A6)));
          break;
        case 7:
          DAQ_Frame[k][i][j] = analogRead(A7);
          // Serial.print("," + String(DAQ_Frame[1][i][j] = analogRead(A7)));
          break;
        case 8:
          DAQ_Frame[k][i][j] = analogRead(A8);
          //  Serial.print("," + String(DAQ_Frame[1][i][j] = analogRead(A8)));
          break;
        case 9:
          DAQ_Frame[k][i][j] = analogRead(A9);
          // Serial.print("," + String(DAQ_Frame[1][i][j] = analogRead(A9)));
          break;
        case 10:
          DAQ_Frame[k][i][j] = analogRead(A10);
          //Serial.print("," + String(DAQ_Frame[1][i][j] = analogRead(A10)));
          break;
        case 11:
          DAQ_Frame[k][i][j] = analogRead(A11);
          //Serial.print("," + String(DAQ_Frame[1][i][j] = analogRead(A11)));
          break;
        case 12:
          DAQ_Frame[k][i][j] = analogRead(A12);
          //Serial.print("," + String(DAQ_Frame[1][i][j] = analogRead(A12)) + "\n");
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

  while (transmitData)
  {
    for (x = 0; x < k; x++)
    {
      for (y = 0; y < 50; y++)
      {
        for (z = 0; i < 12; z++)
        {
          Serial.print("," + String(DAQ_Frame[x][y][z]));
        }
        Serial.print(";");
      }
    }
  }
}
