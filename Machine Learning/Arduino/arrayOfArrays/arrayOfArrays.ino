/*


*/

float line1[10] = {10,11,12,13,14,15,16,17,18,19};

float line2[10] = {20,21,22,23,24,25,26,27,28,29};
float line3[10] = {30,31,32,33,34,35,36,37,38,39};

float myArray[200][10] = { { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
                       { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 },
                       { 21, 22, 23, 24, 25, 26, 27, 28, 29, 30}};


void setup() {
    Serial.begin(9600);

}

void loop() {
  int i,j = 0;
  while (i<200){
    while(j<10){
    Serial.print(String(myArray[i][j])+ ',');
      j++;
    }
    i++;
    Serial.println("");
  }
}
