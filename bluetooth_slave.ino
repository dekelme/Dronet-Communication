#include <SoftwareSerial.h>

SoftwareSerial Serial1(6,7); // RX = 3, TX = 2
String str = "";

void setup() {
  Serial1.begin(9600);            
  Serial.begin(9600);           
}

void loop() {
  while (Serial1.available() > 0) {
    char c = Serial1.read(); 
    str += c; 
    if(c == '\n'){
      Serial.print(str);
      str = "";
    }
  }
}
