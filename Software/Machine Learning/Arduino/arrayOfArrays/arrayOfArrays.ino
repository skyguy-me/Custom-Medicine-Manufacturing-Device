/*


*/



int myArray[3][3][3] =   {
  { { 01, 02, 03 },
    { 011, 012, 013 },
    { 021, 022, 023}
  },

  { { 11, 12, 13 },
    { 111, 112, 113 },
    { 121, 122, 123}
  },
 
  { { 21, 22, 23 },
    { 211, 212, 213 },
    { 221, 222, 223}
  },
  
};


void setup() {
  Serial.begin(9600);

}

void loop() {
  int i, j = 0;
  while (i < 3) {
    while (j < 3) {
      Serial.print(String(myArray[1][i][j]) + ',');
      j++;
    }
    i++;
    Serial.println("");
  }
}
