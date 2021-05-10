#include <virtuabotixRTC.h>

#define buzzer 12

virtuabotixRTC myRTC(5, 6, 7); //virtuabotixRTC myRTC(CLK,DAT,RST);

void setup(){

  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);

  

  //Comment the method below after the clock is set up.

  //Order of parameters in the method below:seconds, minutes, hours, day of the week, day of the month, month, year

//  myRTC.setDS1302Time(15, 51, 13, 4, 04, 03, 2021);  

}



void loop(){

  myRTC.updateTime();



  if(myRTC.hours == 13 && myRTC.minutes == 50 && myRTC.seconds==0 && myRTC.seconds<=3){

  digitalWrite(buzzer, 1); 
  delay(200);  
  digitalWrite(buzzer, 0);
  delay(200);  
  digitalWrite(buzzer, 1); 
  delay(200);  
  digitalWrite(buzzer, 0);
  delay(200); 
  digitalWrite(buzzer, 1);
  delay(200);
  digitalWrite(buzzer, 0);
  delay(100);
  digitalWrite(buzzer, 1); 

  }

  else{

  digitalWrite(buzzer, 0);  

  }

  Serial.print("Current Time: ");

  Serial.print(myRTC.year);

  Serial.print("-");

  Serial.print(myRTC.month<10?"0":""); 

  Serial.print(myRTC.month);

  Serial.print("-");

  Serial.print(myRTC.dayofmonth<10?"0":"");

  Serial.print(myRTC.dayofmonth);

  Serial.print(" ");

  Serial.print(myRTC.hours<10?"0":"");

  Serial.print(myRTC.hours);

  Serial.print(":");

  Serial.print(myRTC.minutes<10?"0":""); 

  Serial.print(myRTC.minutes);

  Serial.print(":");

  Serial.print(myRTC.seconds<10?"0":"");

  Serial.println(myRTC.seconds);

  delay(1000);  //Print after every second

}  
