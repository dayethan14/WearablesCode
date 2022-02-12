/*Blinkorama
//Ethan Day
//DIGF-3010-001 Advanced Wearable Electronics
//OCAD University
//Created on [Feb 10 2022]
//Based on:
//Hello_Neopixel
//Input Pullup Example
//Serial.printin example
//Lecture 2 part 2, feb 4th 2022 Kate Hartman
*/


#include <Adafruit_CircuitPlayground.h>

int maskSwitch;
int maskSwitch2;

void setup() {
  // put your setup code here, to run once:
   CircuitPlayground.begin();
   Serial.begin(9600);
   pinMode(2, INPUT_PULLUP);
   pinMode(0, INPUT_PULLUP);

}

void loop() {
  maskSwitch = digitalRead(2);
  maskSwitch2 = digitalRead(0);
  
  Serial.println(maskSwitch);
 if(maskSwitch == 1 && maskSwitch2 == 1){

  CircuitPlayground.clearPixels();
  delay(300);
  // put your main code here, to run repeatedly:
 CircuitPlayground.setPixelColor(0, 255,   0,   0 );
 CircuitPlayground.setPixelColor(1, 255,   0,   0);
 CircuitPlayground.setPixelColor(2, 255,   0,   0);
 CircuitPlayground.setPixelColor(3, 255,   0,   0);
 CircuitPlayground.setPixelColor(4, 255,   0,   0);
 CircuitPlayground.setPixelColor(5, 255,   0,   0);
 CircuitPlayground.setPixelColor(6, 255,   0,   0);
 CircuitPlayground.setPixelColor(7, 255,   0,   0);
 CircuitPlayground.setPixelColor(8, 255,   0,   0);
 CircuitPlayground.setPixelColor(9, 255,   0,   0);

 delay(400);

 }if(maskSwitch == 0 && maskSwitch2 == 0){
  
 CircuitPlayground.setPixelColor(0,  0,   0, 255);
 CircuitPlayground.setPixelColor(1,  0,   0, 255);
 CircuitPlayground.setPixelColor(2,  0,   0, 255);
 CircuitPlayground.setPixelColor(3,  0,   0, 255);
 CircuitPlayground.setPixelColor(4,  0,   0, 255);
 CircuitPlayground.setPixelColor(5,  0,   0, 255);
 CircuitPlayground.setPixelColor(6,  0,   0, 255);
 CircuitPlayground.setPixelColor(7,  0,   0, 255);
 CircuitPlayground.setPixelColor(8,  0,   0, 255);
 CircuitPlayground.setPixelColor(9,  0,   0, 255);  
  
  
  
  }if(maskSwitch  == 0 && maskSwitch2 == 1){
  CircuitPlayground.clearPixels();
  delay(400);
    
 CircuitPlayground.setPixelColor(0, 255, 100, 0);
 CircuitPlayground.setPixelColor(1, 255, 100, 0);
 CircuitPlayground.setPixelColor(2, 255, 100, 0);
 CircuitPlayground.setPixelColor(3, 255, 100, 0);
 CircuitPlayground.setPixelColor(4, 255, 100, 0);
 CircuitPlayground.setPixelColor(5, 255, 100, 0);
 CircuitPlayground.setPixelColor(6, 255, 100, 0);
 CircuitPlayground.setPixelColor(7, 255, 100, 0);
 CircuitPlayground.setPixelColor(8, 255, 100, 0);
 CircuitPlayground.setPixelColor(9, 255, 100, 0);
delay(500);
 
 }
}
