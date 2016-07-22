#include <Servo.h>
Servo thumb;
Servo pointer;
Servo middle;
Servo pinky;

String letter;
String input;
int count;

void setup() {
  // put your setup code here, to run once:
  thumb.attach(6);
  pointer.attach(9);
  middle.attach(10);
  pinky.attach(11);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    input = Serial.readString();
    Serial.println("Word: " + input);
    count = 0;
    int length = input.length();

      while(count < length)
  {
    letter = input.charAt(count);
    Serial.println("Letter: " + letter);
    if(letter == "a")
    {
      thumb.write(0);
      pointer.write(180);
      middle.write(180);
      pinky.write(180);
    }
  
    if(letter == "b")
    {
      thumb.write(0);
      pointer.write(0);
      middle.write(0);
      pinky.write(0);
    }
  
    if(letter == "c")
    {
      thumb.write(0);
      pointer.write(90);
      middle.write(90);
      pinky.write(75);
    }
  
    if(letter == "d")
    {
      thumb.write(90);
      pointer.write(0);
      middle.write(120);
      pinky.write(100);
    }
  
    if(letter == "e")
    {
      thumb.write(90);
      pointer.write(130);
      middle.write(120);
      pinky.write(100);
    }
  
    if(letter == "f")
    {
      thumb.write(90);
      pointer.write(130);
      middle.write(0);
      pinky.write(0);
    }
  
    if(letter == "i")
    {
      thumb.write(70);
      pointer.write(180);
      middle.write(180);
      pinky.write(0);
    }
  
    if(letter == "l")
    {
      thumb.write(0);
      pointer.write(0);
      middle.write(180);
      pinky.write(180);
    }
  
    if(letter == "n")
    {
      thumb.write(80);
      pointer.write(130);
      middle.write(120);
      pinky.write(180);
    }
  
    if(letter == "o")
    {
      thumb.write(80);
      pointer.write(130);
      middle.write(120);
      pinky.write(100);
    }
  
    if(letter == "s")
    {
      thumb.write(90);
      pointer.write(130);
      middle.write(120);
      pinky.write(180);
    }
  
    if(letter == "u")
    {
      thumb.write(95);
      pointer.write(0);
      middle.write(0);
      pinky.write(180);
    }
  
    if(letter == "x")
    {
      thumb.write(80);
      pointer.write(120);
      middle.write(180);
      pinky.write(180);
    }
    count++;
    delay(1000);
  }
  }
}
