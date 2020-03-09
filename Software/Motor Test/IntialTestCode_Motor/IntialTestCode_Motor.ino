#include <MotorDriver.h>
#include <seeed_pwm.h>


MotorDriver feederMotor1;


void setup() {
  // put your setup code here, to run once:
  feederMotor1.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  feederMotor1.speed(0, 100);            // set motor0 to speed 100
  delay(1000);
  feederMotor1.brake(0);                 // brake
  delay(1000);
  feederMotor1.speed(0, -100);           // set motor0 to speed -100
  delay(1000);
  feederMotor1.stop(0);                  // stop
  delay(1000);
} 
