#include <SoftwareSerial.h>

SoftwareSerial Serial_1(5,4);
SoftwareSerial Serial_2(7,6);
SoftwareSerial Serial_3(9,8);
SoftwareSerial Serial_4(11,10);
 
void setup(void){
  Serial_1.begin(9600);
  Serial_2.begin(9600);
  Serial_3.begin(9600);
  Serial_4.begin(9600);
  Serial.begin(9600);
}

void loop(void){
  if(Serial.available()){
    char c = Serial.read();
    Serial_1.print(c);
    Serial_2.print(c);
    Serial_3.print(c);
    Serial_4.print(c); 
  }
  delay(1);
}
