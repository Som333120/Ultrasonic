// Author : Sandhan Sarma <sandhan.sarma26@gmail.com>
// Date   : 2nd December 2018

#include <Wire.h>
char c ;
void setup() {
  // put your setup code here, to run once:
  
  Wire.begin();
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(8);
  Wire.write( "R,01\r" ); 
  //Wire.write(10); 
  Wire.endTransmission(); 
  
  String dataString = "";
  float voltage = 0.0F;
  Wire.requestFrom(8,25);

  while (Wire.available()) {
    char c = Wire.read();
    dataString = dataString + c;
  }
  Serial.println(dataString);
}
