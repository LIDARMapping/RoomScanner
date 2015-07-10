// Motor control
#include <Servo.h>

Servo motor;
int motorPin = 9; //digital, motor connected here

int spinDelay = 50; //delay between changing angles on the servo
int motorPos = 0; //angle at which the motor is at

// Sets up motor stuff, returns 0 on success, negative number on failure
int setupMotor()
{
  motor.attach(motorPin);
  return 0;
}

// Tells motor to go to pos (0-1800), returns current position
int goToPosition(int pos)
{
  motorPos = pos;
  motor.writeMicroseconds(map(motorPos,0,1800,525,2260)); 
  delay(spinDelay);
  return motorPos;
}

int getPosition()
{
  return motorPos;
}

int offsetPosition(int offset)
{
  goToPosition(motorPos + offset);
  return motorPos;
}
