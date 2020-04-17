// Author : Sandhan Sarma <sandhan.sarma26@gmail.com>
// Date : 2nd December 2018
#include <stdio.h>
#include <string.h>
#include <Wire.h>

float voltage = 0.0F;
static char voltBuff0[25];

char *buffindex ;

char dataout[25] ;
static String dataString  ;

float distance ;
float distance1 ;
float distance2 ;
float distance3 ;

#define prox0 A0
#define prox1 A1
#define prox2 A2
#define prox3 A3 

int flag = 0 ;
String rcommand ;
String command = "R,01\r" ; 

static char c ;


void setup() {
  // put your setup code here, to run once:
  
  Wire.begin(8); // any 7-bit Slave address
  Wire.onRequest(requestEvent); //Interrupt for handling incomming requests
  Serial.begin(115200);
  Wire.onReceive(receiveEvent);
}

void loop() {
    if (dataString == command ){
    flag = 1 ;
    Serial.print(flag) ;
    }
}

void requestEvent() {
  if(flag ==1){
      buffindex = voltBuff0[0] ;
      Serial.println(flag);
      //voltBuff0[0] = '77' ;
      Wire.write(0x4D) ; 
      Wire.write(',');
  
      distance = analogRead(prox0); //read ultrasonic 1
      distance*= 0.3 ;
      buffindex = voltBuff0 ;
      dtostrf(distance,5,1, voltBuff0);
      Wire.write(buffindex);
      Wire.write(',');
  
      buffindex = buffindex ;
      float distance1 = analogRead(prox1); //read ultrasonic 2
      distance1*= 0.3 ;
      dtostrf(distance1,5,1, buffindex);
      Wire.write(buffindex);
      Wire.write(',');
 
      buffindex = buffindex+5 ;
      distance2 = analogRead(prox2); //read ultrasonic 2
      distance2*= 0.3 ;
      dtostrf(distance2,5,1, buffindex); 
      Wire.write(buffindex);
      Wire.write(',');
    
      buffindex = buffindex+5 ;
      distance3 = analogRead(prox3); //read ultrasonic 2
      distance3*= 0.3 ;
      dtostrf(distance3,5,1, buffindex); 
      Wire.write(buffindex);
      Wire.write('\r');
      //Serial.println(voltBuff0) ;
      }
      else if (flag ==0){
        Wire.write("waiting  for command R,01\r") ;
        } 
   
}
 

 void receiveEvent() {
  while (Wire.available()) { // loop through all but the last
    c = Wire.read(); // receive byte as a character
    dataString = dataString + c;
    }
    //Serial.println(dataString) ;
    //Serial.println() ;
}

     
