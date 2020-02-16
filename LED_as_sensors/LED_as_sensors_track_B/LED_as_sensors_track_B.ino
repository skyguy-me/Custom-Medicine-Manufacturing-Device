int led = 13;                                        // the pin where you will put the LED
int sensorpin = A1;                           // the analog pin where you put your sensorLED
int resetteller = 0;                              // the rest are counters and variables to calculate with
int sens = 0;
int teller = 0;
int basis = 1024;
int test = 1024;
int test2 = 1024;
int test3 = 1024;

// this are the values to play with to get better (or worse) results
int marge = 5;                         // the space between a positive and negative reading
int vertraging = 1;                  // the speed of the readings; a lower number is a higher speed
int samples = 70;                   // the amount of samples to compare to make one reading
int resetsamples = 30;          // how many cycles to run the light on before you don't trust the value anymore

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);                                   // no real part of the program, just for debugging
  for(teller =0; teller < samples; teller++) {// remember the lowest value out of many readings
   sens = analogRead(sensorpin);
   if (sens < basis){basis = sens;}
   delay(vertraging);                                     // the sensor needs a delay here to catch its breath
  }
}


void loop() {                                            
for(teller =0; teller < samples; teller++) {// remember the lowest value out of many readings
   sens = analogRead(sensorpin);
   delay(vertraging);                                   // the sensor needs a delay here to catch its breath
   if (sens < test){
   test3 = sens;                                            // remember the 3 lowest readings
   test2 = test3;
   test = test2;}
  }
  if (test < basis-marge && test2 < basis-marge && test3 < basis-marge){//all 3 low readings mus be < the basis reading
    digitalWrite(led, LOW);
    resetteller++;                                         // count how long the LED stays on
  }
    else{
      digitalWrite(led, HIGH);
      basis = test;                                         // if the lowest test reading is higher than the basis, basis will be reset
      resetteller = 0;
    }
    if (resetteller > resetsamples){basis = test;}//if LED stays on to long, we don't trust it and reset basis
    Serial.print(basis);Serial.print("  ");Serial.print(test);Serial.print("  ");Serial.println(sens);//just for debugging
    test = 1024;
}
