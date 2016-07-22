#include <stdio.h>
#include <SoftwareSerial.h>      

const int pinkypin = 1;
const int middlepin = 2;
const int pointerpin = 3;
const int thumbpin = 5; 

SoftwareSerial XBee(2, 3); // RX, TX

void setup()
{
     Serial.begin(9600);          //enable the hardware serial port
     XBee.begin(9600);          
}

void loop(){
   int flexpinky = 1000 + analogRead(pinkypin);
   XBee.write((unsigned char*)&flexpinky, 2);
   Serial.print("pinky:");              //print out "DO:"  
   Serial.print(" ");
   Serial.println(flexpinky, 2);
   
   int flexmiddle = 2000 + analogRead(middlepin);
   XBee.write((unsigned char*)&flexmiddle, 2);
   Serial.print("middle:");              //print out "DO:"  
   Serial.print(" ");
   Serial.println(flexmiddle, 2);
   
   int flexpointer = 3000 + analogRead(pointerpin);
   XBee.write((unsigned char*)&flexpointer, 2);
   Serial.print("pointer:");              //print out "DO:"  
   Serial.print(" ");
   Serial.println(flexpointer, 2);

   int flexthumb = 5000 + analogRead(thumbpin);
   XBee.write((unsigned char*)&flexthumb, 2);
   Serial.print("thumb:");              //print out "DO:"  
   Serial.print(" ");
   Serial.println(flexthumb, 2);
   
   //XBee.write((unsigned char*)&DO_float, 2);
   /*Serial.print("DO:");              //print out "DO:"  
   Serial.print(" ");
   Serial.println(DO_float, 2);*/
  
  delay(1000);      // delay half a second between transmission

 }  



