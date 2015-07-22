double previous = 0.0;
int angleStep = 10;
int nMeasure = 10;

void setup()
{
  Serial.begin(9600);
  setupLIDAR();
  setupMotor();
  setTimeBase(150);
  delay(1000);
  Serial.println("Start!");
  Serial.print(getTimeBase());
  Serial.print(' ');
  Serial.print(nMeasure);
  Serial.print(' ');
  Serial.println(angleStep);
}

void loop() {
  spin(0);525
  //spin(1);
  Serial.println("End!");
}

void spin(int dir) { //spins the motor. 0 - CCW, 1 - CW
  if (dir == 0) {
    for (int angle = 0; angle <= 3600; angle += angleStep) {
      goToPosition(angle); //maps degree measure to microseconds, since it uses integer math we multiply everything by 10
      outputPoint(angle / 10.0, takeMeasurement(nMeasure) * 1000);
    }
  }
  else if (dir == 1) {
    for (int angle = 3600; angle >= 0; angle -= angleStep) {
      goToPosition(angle); //maps degree measur80e to microseconds, since it uses integer math we multiply everything by 10
      outputPoint(angle / 10.0, takeMeasurement(nMeasure) * 1000);
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
