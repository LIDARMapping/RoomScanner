void setup()
{
  Serial.begin(9600);
  setupLIDAR();
  setupMotor();
}

void loop(){
  spin(0);
  spin(1);
}

void spin(int dir){ //spins the motor. 0 - CCW, 1 - CW
  if(dir == 0){
    for(int angle = 0; angle <= 1800; angle += 2){                                  
      goToPosition(angle); //maps degree measure to microseconds, since it uses integer math we multiply everything by 10
      outputPoint(angle/100.0, takeMeasurement(1)*1000);
    } 
  }
  else if(dir == 1){
    for(int angle = 1800; angle >= 0; angle -= 2){                                    
      goToPosition(angle); //maps degree measure to microseconds, since it uses integer math we multiply everything by 10
      outputPoint(angle/100.0, takeMeasurement(1)*1000);
    } 
  }  
}

// millimeters because android precision is not based on sig figs
void outputPoint(double angle, double millimeters)
{
  Serial.print(angle);
  Serial.print(' ');
  Serial.println(millimeters);
}
