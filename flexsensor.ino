// Include the servo library to add servo-control functions:

#include <Servo.h> 

// Create a servo "object", called servo1. Each servo object
// controls one servo (you can have a maximum of 12):

Servo pinky;
Servo middle;
Servo pointer;
Servo thumb;

// Define the analog input pin to measure flex sensor position:

const int pinkypin = 1;
const int middlepin = 2;
const int pointerpin = 3;
const int thumbpin = 4; 


void setup() 
{ 
  // Use the serial monitor window to help debug our sketch:
   
  Serial.begin(9600);
  
  // Enable control of a servo on pin 9:

  pinky.attach(11);
  middle.attach(10);
  pointer.attach(9);
  thumb.attach(6);
  
} 


void loop() 
{ 
  int flexpinky;    // Input value from the analog pin.
  int servopinky;   // Output value to the servo.
  int flexmiddle;    
  int servomiddle; 
  int flexpointer;
  int servopointer;
  int flexthumb;
  int servothumb;

  // Read the position of the flex sensor (0 to 1023):
  
  flexpinky = analogRead(pinkypin);
  flexmiddle = analogRead(middlepin);
  flexpointer = analogRead(pointerpin);
  flexthumb = analogRead(thumbpin);

  // Because the voltage divider circuit only returns a portion
  // of the 0-1023 range of analogRead(), we'll map() that range
  // to the servo's range of 0 to 180 degrees. The flex sensors
  // we use are usually in the 600-900 range:
  
  servopinky = map(flexpinky, 500, 800, 0, 180);
  servopinky = constrain(servopinky, 0, 180);
  servomiddle = map(flexmiddle, 400, 800, 0, 180);
  servomiddle = constrain(servomiddle, 0, 180);
  servopointer = map(flexpointer, 400, 800, 0, 180);
  servopointer = constrain(servopointer, 0, 180);
  servothumb = map(flexthumb, 400, 800, 0, 180);
  servothumb = constrain(servothumb, 0, 180);

  // Now we'll command the servo to move to that position:

  pinky.write(servopinky);
  middle.write(servomiddle);
  pointer.write(servopointer);
  thumb.write(servothumb);

  // Because every flex sensor has a slightly different resistance,
  // the 600-900 range may not exactly cover the flex sensor's
  // output. To help tune our program, we'll use the serial port to
  // print out our values to the serial monitor window:
  
  /*Serial.print("flexpinky: ");
  Serial.print(flexpinky);
  Serial.print("  servopinky: ");
  Serial.println(servopinky);*/

  /*Serial.print("sensor2: ");
  Serial.print(flexposition2);
  Serial.print("  servo2: ");
  Serial.println(servoposition2);*/
  
  // Note that all of the above lines are "print" except for the
  // last line which is "println". This puts everything on the
  // same line, then sends a final carriage return to move to
  // the next line.

  // After you upload the sketch, turn on the serial monitor
  // (the magnifying-glass icon to the right of the icon bar).
  // You'll be able to see the sensor values. Bend the flex sensor
  // and note its minimum and maximum values. If you replace the
  // 600 and 900 in the map() function above, you'll exactly match
  // the flex sensor's range with the servo's range.
  
  delay(20);  // wait 20ms between servo updates
} 

