//XBee.read returns a single character at a time - so we need to collect them all into an array.

#include <SoftwareSerial.h>
#include <stdio.h>
#include <Servo.h> 

SoftwareSerial XBee(2, 3); // RX, TX

Servo pinky;
Servo middle;
Servo pointer;
Servo thumb;

int DO_float = 0;               //used to hold a floating point number that is the D.O. 
int buf_index = 0;

void setup()
{
  XBee.begin(9600);
  Serial.begin(9600);
  
  pinky.attach(11);
  middle.attach(10);
  pointer.attach(9);
  thumb.attach(6);
}

bool read_buf(char* buf, int read_size)
{
    if (XBee.available()) {
        buf[buf_index++] = XBee.read();
        if (buf_index >= read_size)
        {
            buf_index = 0;
            return true;
        }
    }
    return false;
}


void loop()
{
    int servopinky;
    int flexpinky;  
    int flexmiddle;    
    int servomiddle; 
    int flexpointer;
    int servopointer;
    int flexthumb;
    int servothumb;
    
    if (read_buf((char*)&DO_float, 2))
    {
        //Serial.println(DO_float);
    }

    if(DO_float/1000 == 1)
    {
      flexpinky = DO_float%1000;
      //Serial.println(flexpinky);
      servopinky = map(flexpinky, 200, 500, 180, 0);
      //Serial.println(servopinky);
      servopinky = constrain(servopinky, 0, 180);
      pinky.write(servopinky);
    }

    if(DO_float/1000 == 2)
    {
      flexmiddle = DO_float%1000;
      servomiddle = map(flexmiddle, 150, 600, 180, 0);
      //Serial.println(servomiddle);
      servomiddle = constrain(servomiddle, 0, 180);
      middle.write(servomiddle);
    }

    if(DO_float/1000 == 3)
    {
      flexpointer = DO_float%1000;
      //Serial.println(flexpointer);
      servopointer = map(flexpointer, 200, 600, 180, 0);
      //Serial.println(servopointer);
      servopointer = constrain(servopointer, 0, 180);
      pointer.write(servopointer);
    }

    if(DO_float/1000 == 5)
    {
      flexthumb = DO_float%1000;
      //Serial.println(flexthumb);
      servothumb = map(flexthumb, 100, 600, 180, 0);
      Serial.println(servothumb);
      servothumb = constrain(servothumb, 0, 180);
      thumb.write(servothumb);
    } 
    //delay(500);
}
