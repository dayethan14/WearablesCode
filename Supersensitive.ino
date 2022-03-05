

/*
 *Super Sensitive
//Ethan Day
//DIGF-3010-001 Advanced Wearable Electronics
//OCAD University
//Created on [March 4 2022]
//Based on:
//Hello_Neopixel
//Hello_Accelerometer
//Hello_LightSensor
//Arduino wiki "absolute values"
https://www.arduino.cc/reference/en/language/functions/math/abs/ 
//Arduino wiki "random"
https://www.arduino.cc/reference/en/language/functions/random-numbers/random/ 
*/

//First setting up the adafruit circuit playground express library to call it's components/features in the code
#include <Adafruit_CircuitPlayground.h>




//Declare all my variables. These variables include all sorts of data including button variables, 
// RBG values that respond to the accelerometer, the value of the light sensor, and random RBG values for the random mode
float X, Y, Z;
int buttonRight;
int buttonLeft;
int value;
int red;
int green;
int blue;
int randred;
int randgreen;
int randblue;


//Start up the serial monitor and the CircuitPlayground functions before anything else happens
void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();

 // intialize the pins that my 2 buttons are going to be connected to
     pinMode(9, INPUT_PULLUP);
   pinMode(10, INPUT_PULLUP);
}

void loop() {



 //Assign values to variables. This is where I connect my sensors to my outputs. The "value" variable
 //is the value of the lightsensor on the CPX. I divided it by 16 since the value is very high and I'm going to be
 // using it to multiply the RBG values of Neopixels. Red, green, and blue are absolute values and connected to 
 // the X,Y, and Z coordinates of the accelerometer on the CPX. 
 
 //The red green and blue will be the variables used in the Neopixel RBG values,
 // which is why I'm multiplying by the lightsensor factor for reach. The neopixel outputs are a direct result of the accelerometer and light sensor, with the darker
 // the light sensor being, the lower the RBG brightness. The left and right buttons are connected via alligator clips and pins on the CPX. 
 
 // there are random red, green, and blue values being multiplied by the light sensor value as well, set between 0 and 12, roughly the same range of values
 // that the accelerometer will be outputting. This way, in the random mode, the output will have roughly the same brightness and range of colour as the
 // motion sensor mode. 
 
  value = CircuitPlayground.lightSensor()/16; 
  red = abs(X)*value;
  green = abs(Y)*value;
  blue = abs(Z)*value;
   X = CircuitPlayground.motionX();
  Y = CircuitPlayground.motionY();
  Z = CircuitPlayground.motionZ();
  buttonRight = digitalRead(10);
  buttonLeft = digitalRead(9);
  randred = random(0,12)*value;
  randgreen = random(0,12)*value;
  randblue = random(0,12)*value;


// only go into this state if the right button is being pressed down. This is the random state, repeatedly 
// Cycling through a vast range of colours on the 7 chosen Neopixels, all doing the same colour at once, also 
// able to be altered by the lightsensor in terms of brightness

if(buttonRight == 0){
  CircuitPlayground.setPixelColor(3, randred, randgreen, randblue);
  CircuitPlayground.setPixelColor(4, randred, randgreen, randblue);
  CircuitPlayground.setPixelColor(5, randred, randgreen, randblue);
  CircuitPlayground.setPixelColor(6, randred, randgreen, randblue);
  CircuitPlayground.setPixelColor(7, randred, randgreen, randblue);
  CircuitPlayground.setPixelColor(8, randred, randgreen, randblue);
  CircuitPlayground.setPixelColor(9, randred, randgreen, randblue);
  
// When the left button is pressed while the right is already being pressed, the current state of the random cycling will come to a halt for
// 7 seconds, giving the user a chance to see the random colour they ended up with, and take a picture of it or try for a 
// new random colour
    if(buttonLeft == 0){
    delay(7000);
  
    }
}

// if the right button isn't being held down, the default state is to show colours based on the XYZ coordinates of the CPX. Rotating
// the CPX steadily changes the colour, and each position will have a unique and specific colour. The RGB values here are the XYZ coordinate values being 
// multiplied by the chosen brightness, controlled by the light sensor. Same as the random mode, only it's controlled by the user's hand rotation. 
else{
  CircuitPlayground.setPixelColor(5, red,   green,   blue);
  CircuitPlayground.setPixelColor(6, red,   green,   blue);
    CircuitPlayground.setPixelColor(7, red,   green,   blue);
  CircuitPlayground.setPixelColor(8, red,   green,   blue);
    CircuitPlayground.setPixelColor(9, red,   green,   blue);
    CircuitPlayground.setPixelColor(3, red,   green,   blue);
  CircuitPlayground.setPixelColor(4, red,   green,   blue);

  // If the left button is pressed, freeze the coordinate detection and show the current colour for 7 straight seconds, allowing the user to
  // take a picutre of it if they wish
  if(buttonLeft == 0){
    delay(7000);
  }

}

//These if-statements are used to smooth the colour outputs a little bit, where if the XY or Z values go below 1, they will simply stay at 0.1 until they
// go back above 1 again in order to save the RBG values from outputting trivial differences of less than 1, and causing too much flickering
// in the Neopixels at any given moment. This helps reduce human error as well, reducing the chance of minor shaking impacting the colour.

  if(abs(X)<1){
    X = 0.1;
  }
    if(abs(Y)<1){
    Y = 0.1;
  }
    if(abs(Z)<1){
    Z = 0.1;
  }

 //If the lightsensor value is less than 1, keep it at 1 in order to keep it from becoming a trivial number thats less than 1 
 
  if(value <=1){
    value = 1;
  }
  
// Simple serial monitor outputs so I can see what values I'm recieving in my 2 sensors.

  Serial.print("X: ");
  Serial.print(X);
  Serial.print("  Y: ");
  Serial.print(Y);
  Serial.print("  Z: ");
  Serial.println(Z);
  Serial.println(value);
// Delay 100 to set the pace at which the code updates. This pace is 1/10th of a second, which is very fast. 
  delay(100);
}
