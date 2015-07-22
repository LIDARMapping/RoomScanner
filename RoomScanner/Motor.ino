// Motor control
#include <Servo.h>

Servo motor;
int motorPin = 9; //digital, motor connected here

int spinDelay = 0; //delay between changing angles on the servo
int motorPos = 0; //angle at which the motor is at

// Sets up motor stuff, returns 0 on success, negative number on failure
int setupMotor()
{
  motor.attach(motorPin);
  motor.writeMicroseconds(650); //sets the motor to proper position
  delay(100);
  return 0;
}

// Tells motor to go to position 0-3600 (10x angle to move decimal point)
int goToPosition(int pos)
{
  pos = setLim(pos); //limits the angle to only 0 - 360 degrees
  motorPos = pos;
  motor.writeMicroseconds(map(motorPos,0,3600,650,1450)); //maps angle to corresponding pulse width 
  delay(spinDelay);
  return motorPos;
}

//constrains motor movement
int setLim(int pos){
  if(pos < 0){
    return 0;  
  }
  else if(pos > 3600){
    return 3600;  
  }
  else{
    return pos;
  }  
}

//returns motor position
int getPosition()
{
  return motorPos;
}

int offsetPosition(int offset)
{
  goToPosition(motorPos + offset);
  return motorPos;
}
