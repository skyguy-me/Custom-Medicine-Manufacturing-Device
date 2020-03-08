#include <MemoryFree.h>
#include <Controllino.h>

int i = 0;
int j;


bool CodeStop = false;

int dataFrame[1][100][12];

void setup() {
  // put your setup code here, to run once:
  // initialize necessary pin as input pin
  pinMode(CONTROLLINO_A0, INPUT);
  i = 0;
  j = 0;
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  while (!CodeStop) {
    Serial.println("i=" + String(i));
    if (i < 9) {
      // put your main code here, to run repeatedly:
      // read the input on analog pin:
      // float time = micros();

      dataFrame[1][i][j] = analogRead(CONTROLLINO_A0);
      //Serial.print("i=" + String(i) + "  " + String(dataFrame[1][i][j]));
      j++;


      dataFrame[1][i][j] = analogRead(CONTROLLINO_A1);
      //  Serial.print(" ," + String(dataFrame[1][i][j]));
      j++;
      //
      dataFrame[1][i][j] = analogRead(CONTROLLINO_A2);
      //  Serial.print(" ," + String(dataFrame[1][i][j]));
      j++;
      //
      dataFrame[1][i][j] = analogRead(CONTROLLINO_A3);
      //  Serial.print(" ," + String(dataFrame[1][i][j]));
      j++;
      //
      //
      dataFrame[1][i][j] = analogRead(CONTROLLINO_A4);
      // Serial.print(" ," + String(dataFrame[1][i][j]));
      j++;
      //
      dataFrame[1][i][j] = analogRead(CONTROLLINO_A5);
      //   Serial.print(" ," + String(dataFrame[1][i][j]));
      j++;

      dataFrame[1][i][j] = analogRead(CONTROLLINO_A6);
      //Serial.print(" ," + String(dataFrame[1][i][j]));
      j++;

      dataFrame[1][i][j] = analogRead(CONTROLLINO_A7);
      // Serial.print(" ," + String(dataFrame[1][i][j]));
      j++;

      dataFrame[1][i][j] = analogRead(CONTROLLINO_A8);
      //  Serial.print(" ," + String(dataFrame[1][i][j]));
      j++;
      //
      dataFrame[1][i][j] = analogRead(CONTROLLINO_A9);
      //      //  Serial.print(" ," + String(dataFrame[1][i][j]));
      j++;
      //
      dataFrame[1][i][j] = analogRead(CONTROLLINO_A10);
      //      //Serial.print(" ," + String(dataFrame[1][i][j]));
      j++;
      //
      //      dataFrame[1][i][j] = analogRead(CONTROLLINO_A9);
      //      // Serial.print(" ," + String(dataFrame[1][i][j]) + "\n");

      i = i + 1;
      j = 0;
      delay(100);
      // print out the value you read:
      // Serial.println(time = micros() - time  );
    }

    else {
      delay(1000);
      for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 12; y++) {
          Serial.print(" ," + String(dataFrame[1][x][y]));
        }
        Serial.print("\n");
      }
      i = 0;

      // Serial.println("\n\n");

    }

    Serial.print("freeMemory()=");
    Serial.println(freeMemory());

  }
}
