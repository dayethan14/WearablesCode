#include <Adafruit_CircuitPlayground.h>

float tempCelcius, tempA, tempB;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
 tempCelcius = CircuitPlayground.temperature();
tempB = tempCelcius;
 
if (tempA - tempB > 0.1){
  
  CircuitPlayground.setPixelColor(0, 0,   0,   255);
  delay(10);
  CircuitPlayground.setPixelColor(1, 0,   0,   255);
    delay(10);
  CircuitPlayground.setPixelColor(2, 0,   0,   255);
    delay(10);
  CircuitPlayground.setPixelColor(3, 0,   0,   255);
    delay(10);
  CircuitPlayground.setPixelColor(4, 0,   0,   255);
    delay(10);
  CircuitPlayground.setPixelColor(5, 0,   0,   255);
    delay(10);
  CircuitPlayground.setPixelColor(6, 0,   0,   255);
    delay(10);
  CircuitPlayground.setPixelColor(7, 0,   0,   255);
    delay(10);
  CircuitPlayground.setPixelColor(8, 0,   0,   255);
    delay(10);
  CircuitPlayground.setPixelColor(9, 0,   0,   255);
    delay(10);

  Serial.println("colder");
  
  }else if(tempB - tempA > 0.1){
    
     CircuitPlayground.setPixelColor(9, 255,   0,   0);
  delay(10);
  CircuitPlayground.setPixelColor(8, 255,   0,   0);
    delay(10);
  CircuitPlayground.setPixelColor(7, 255,   0,   0);
    delay(10);
     CircuitPlayground.setPixelColor(6, 255,   0,   0);
  delay(10);
  CircuitPlayground.setPixelColor(5, 255,   0,   0);
    delay(10);
  CircuitPlayground.setPixelColor(4, 255,   0,   0);    
     CircuitPlayground.setPixelColor(3, 255,   0,   0);
  delay(10);
  CircuitPlayground.setPixelColor(2, 255,   0,   0);
    delay(10);
  CircuitPlayground.setPixelColor(1, 255,   0,   0);
    delay(10);
     CircuitPlayground.setPixelColor(0, 255,   0,   0);
  delay(10);
  
 Serial.println("hotter");
    
    } else{
    CircuitPlayground.clearPixels();
  }


  Serial.println("tempCelcius: ");
  Serial.println(tempCelcius);

  

tempA = tempCelcius;

  delay(1000);
}
