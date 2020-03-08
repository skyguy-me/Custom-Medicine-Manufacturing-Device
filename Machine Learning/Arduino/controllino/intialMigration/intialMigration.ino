#include <MemoryFree.h>
#include <Controllino.h>

int i = 0;
int j;
int x = 0;
int y = 0;


bool CodeStop = false;

int dataFrame[1][100][12];

void setup() {
  // put your setup code here, to run once:
  // initialize necessary pin as input pin
  pinMode(CONTROLLINO_A0, INPUT);
  i = 0;
  j = 0;
  // initialize serial communication at 9600 bits per second:
  Serial.begin(2000000);


  while (!CodeStop) {
    float time = micros();
    while (i < 100) {
      //      // put your main code here, to run repeatedly:
      //      // read the input on analog pin:
      //
      //      Serial.println("i=" + String(i));
      //      dataFrame[1][i][j] = analogRead(CONTROLLINO_A0);
      //      //Serial.print("i=" + String(i) + "  " + String(dataFrame[1][i][j]));
      //      j++;
      //
      //
      //      dataFrame[1][i][j] = analogRead(CONTROLLINO_A1);
      //      //  Serial.print(" ," + String(dataFrame[1][i][j]));
      //      j++;
      //      //
      //      dataFrame[1][i][j] = analogRead(CONTROLLINO_A2);
      //      //  Serial.print(" ," + String(dataFrame[1][i][j]));
      //      j++;
      //      //
      //      dataFrame[1][i][j] = analogRead(CONTROLLINO_A3);
      //      //  Serial.print(" ," + String(dataFrame[1][i][j]));
      //      j++;
      //      //
      //      //
      //      dataFrame[1][i][j] = analogRead(CONTROLLINO_A4);
      //      // Serial.print(" ," + String(dataFrame[1][i][j]));
      //      j++;
      //      //
      //      dataFrame[1][i][j] = analogRead(CONTROLLINO_A5);
      //      //   Serial.print(" ," + String(dataFrame[1][i][j]));
      //      j++;
      //
      //      dataFrame[1][i][j] = analogRead(CONTROLLINO_A6);
      //      //Serial.print(" ," + String(dataFrame[1][i][j]));
      //      j++;
      //
      //      dataFrame[1][i][j] = analogRead(CONTROLLINO_A7);
      //      // Serial.print(" ," + String(dataFrame[1][i][j]));
      //      j++;
      //
      //      dataFrame[1][i][j] = analogRead(CONTROLLINO_A8);
      //      //  Serial.print(" ," + String(dataFrame[1][i][j]));
      //      j++;
      //      //
      //      dataFrame[1][i][j] = analogRead(CONTROLLINO_A9);
      //      //      //  Serial.print(" ," + String(dataFrame[1][i][j]));
      //      j++;
      //      //
      //      dataFrame[1][i][j] = analogRead(CONTROLLINO_A10);
      //      //      //Serial.print(" ," + String(dataFrame[1][i][j]));
      //      j++;
      //      //
      //      //      dataFrame[1][i][j] = analogRead(CONTROLLINO_A9);
      //      //      // Serial.print(" ," + String(dataFrame[1][i][j]) + "\n");
      //
      //      i = i + 1;
      //      j = 0;
      //      // print out the value you read:
      //    }
      //    //    Serial.println(time = micros() - time  );
      //    //
      for (i = 0; i < 100; i++) {
        for (j = 0; j < 12; j++) {
          switch (j) {
            case 0:   Serial.print(String(analogRead(CONTROLLINO_A0)));
              break;
            case 1: Serial.print("," + String(analogRead(CONTROLLINO_A1)));
              break;
            case 2: Serial.print("," + String(analogRead(CONTROLLINO_A2)));
              break;
            case 3: Serial.print("," + String(analogRead(CONTROLLINO_A3)));
              break;
            case 4: Serial.print("," + String(analogRead(CONTROLLINO_A4)));
              break;
            case 5: Serial.print("," + String(analogRead(CONTROLLINO_A5)));
              break;
            case 6: Serial.print("," + String(analogRead(CONTROLLINO_A6)));
              break;
            case 7: Serial.print("," + String(analogRead(CONTROLLINO_A7)));
              break;
            case 8: Serial.print("," + String(analogRead(CONTROLLINO_A8)));
              break;
            case 9: Serial.print("," + String(analogRead(CONTROLLINO_A9)));
              break;
            case 10: Serial.print("," + String(analogRead(CONTROLLINO_A10)));
              break;
            case 11: Serial.print("," + String(analogRead(CONTROLLINO_A11)));
              break;
            case 12: Serial.print("," + String(analogRead(CONTROLLINO_A12)) + "\n");
              break;
          }
        }
        Serial.print("\n");
      }
      //    i = 0;

          Serial.println("time to complete = " + String(time = micros() - time) +"microseconds" );


    }
  }
}

void loop() {
  //  while (!CodeStop) {
  //    float time = micros();
  //    while (i < 100) {
  //      // put your main code here, to run repeatedly:
  //      // read the input on analog pin:
  //
  //      Serial.println("i=" + String(i));
  //      dataFrame[1][i][j] = analogRead(CONTROLLINO_A0);
  //      //Serial.print("i=" + String(i) + "  " + String(dataFrame[1][i][j]));
  //      j++;
  //
  //
  //      dataFrame[1][i][j] = analogRead(CONTROLLINO_A1);
  //      //  Serial.print(" ," + String(dataFrame[1][i][j]));
  //      j++;
  //      //
  //      dataFrame[1][i][j] = analogRead(CONTROLLINO_A2);
  //      //  Serial.print(" ," + String(dataFrame[1][i][j]));
  //      j++;
  //      //
  //      dataFrame[1][i][j] = analogRead(CONTROLLINO_A3);
  //      //  Serial.print(" ," + String(dataFrame[1][i][j]));
  //      j++;
  //      //
  //      //
  //      dataFrame[1][i][j] = analogRead(CONTROLLINO_A4);
  //      // Serial.print(" ," + String(dataFrame[1][i][j]));
  //      j++;
  //      //
  //      dataFrame[1][i][j] = analogRead(CONTROLLINO_A5);
  //      //   Serial.print(" ," + String(dataFrame[1][i][j]));
  //      j++;
  //
  //      dataFrame[1][i][j] = analogRead(CONTROLLINO_A6);
  //      //Serial.print(" ," + String(dataFrame[1][i][j]));
  //      j++;
  //
  //      dataFrame[1][i][j] = analogRead(CONTROLLINO_A7);
  //      // Serial.print(" ," + String(dataFrame[1][i][j]));
  //      j++;
  //
  //      dataFrame[1][i][j] = analogRead(CONTROLLINO_A8);
  //      //  Serial.print(" ," + String(dataFrame[1][i][j]));
  //      j++;
  //      //
  //      dataFrame[1][i][j] = analogRead(CONTROLLINO_A9);
  //      //      //  Serial.print(" ," + String(dataFrame[1][i][j]));
  //      j++;
  //      //
  //      dataFrame[1][i][j] = analogRead(CONTROLLINO_A10);
  //      //      //Serial.print(" ," + String(dataFrame[1][i][j]));
  //      j++;
  //      //
  //      //      dataFrame[1][i][j] = analogRead(CONTROLLINO_A9);
  //      //      // Serial.print(" ," + String(dataFrame[1][i][j]) + "\n");
  //
  //      i = i + 1;
  //      j = 0;
  //      // print out the value you read:
  //    }
  //    Serial.println(time = micros() - time  );
  //
  //        for (x = 0; x < i; x++) {
  //          for (y = 0; y < 12; y++) {
  //            Serial.print(" ," + String(dataFrame[1][x][y]));
  //          }
  //          Serial.print("\n");
  //        }
  //        //    i = 0;
  //    //
  //    //    Serial.println("\n\n");
  //
  //  }

}
