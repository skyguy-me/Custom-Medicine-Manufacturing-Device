
//state machine
bool waitStage = true;
bool feederStage = false;
bool scanStage = false;
bool packStage = false;





void setup() {
  // put your setup code here, to run once:

 Serial.begin(9600); // communicate with host PC
 Serial1.begin(2000000);

}

void loop() {

  if (waitStage){
    
  }

  if (feederStage){

  }
  if (scanStage){

  }
  if(packStage){

  }

}   