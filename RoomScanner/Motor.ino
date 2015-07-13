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
  motor.writeMicroseconds(525); //sets the motor to proper position
  delay(100);
  return 0;
}

// Tells motor to go to position 0-1800 (10x angle to move decimal point)
int goToPosition(int pos)
{
  pos = setLim(pos);  
  motorPos = pos;
  motor.writeMicroseconds(map(motorPos,0,1800,525,2260)); 
  delay(spinDelay);
  return motorPos;
}

//constrains motor movement
int setLim(int pos){
  if(pos < 0){
    return 0;  
  }
  else if(pos > 1800){
    return 1800;  
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
