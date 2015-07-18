double previous = 0.0;

void setup()
{
  Serial.begin(9600);
  setupLIDAR();
  setupMotor();
  setTimeBase(150);
  Serial.println("Start!");
}

void loop() {
  spin(0);
  spin(1);
}

void spin(int dir) { //spins the motor. 0 - CCW, 1 - CW
  if (dir == 0) {
    for (int angle = 0; angle <= 1800; angle += 10) {
      goToPosition(angle); //maps degree measure to microseconds, since it uses integer math we multiply everything by 10
      outputPoint(angle / 10.0, takeMeasurement(80) * 1000);
    }
  }
  else if (dir == 1) {
    for (int angle = 1800; angle >= 0; angle -= 10) {
      goToPosition(angle); //maps degree measure to microseconds, since it uses integer math we multiply everything by 10
      outputPoint(angle / 10.0, takeMeasurement(80) * 1000);
    }
  }
}

// millimeters because android precision is not based on sig figs
void outputPoint(double angle, int millimeters)
{
  Serial.print(angle);
  Serial.print(' ');
  if (millimeters < 0.0)
    Serial.println(previous);
  else
    Serial.println(previous = millimeters);
}
