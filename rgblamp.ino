
#include <SoftwareSerial.h>

const int rxPin = 13;
const int txPin = 12;
const int atPin = 8;

int val = 0;
String clr = "r";
const int led_rosso = 5;
const int led_blu = 3;
const int led_verde = 6;

SoftwareSerial bluetooth(rxPin, txPin);

void setup() {

Serial.begin(9600);
bluetooth.begin(38400);

pinMode(atPin, OUTPUT);
digitalWrite(atPin, HIGH);

   pinMode(led_rosso,OUTPUT);
    pinMode(led_verde,OUTPUT);
     pinMode(led_blu,OUTPUT);

 analogWrite(led_rosso,0);
  analogWrite(led_verde,0);
   analogWrite(led_blu,0);
}
void loop() {

while (bluetooth.available()) {
   val = bluetooth.read();
   
   if(val == 114) {
     clr = "r";
   } else if (val == 118) {
     clr = "v";
   } else if (val == 98) {
     clr = "b";
   }
   
  if(clr == "r") {
  analogWrite(led_rosso,val);
  Serial.println(val);
  }
   if(clr == "v") {
  analogWrite(led_verde,val);
  Serial.println(val);
  }
   if(clr == "b") {
  analogWrite(led_blu,val);
  Serial.println(val);
  }
  
}

}
