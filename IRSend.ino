/* Example program for from IRLib – an Arduino library for infrared encoding and decoding
 * Version 1.3   January 2014
 * Copyright 2014 by Chris Young http://cyborg5.com
 * Based on original example sketch for IRremote library 
 * Version 0.11 September, 2009
 * Copyright 2009 Ken Shirriff
 * http://www.righto.com/
 */
#include <IRLib.h>
#include "definitions.h"

IRsend My_Sender;
unsigned int counter = 10;
unsigned int* ptr = &temp25c[0];
unsigned int currentData[111];
bool flag = true;
   
void setup()
{
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
      while (Serial.available() > 0) Serial.read();
      Serial.println("got input");
      
      unsigned int displayInt;
      if (flag) {
        Serial.println("19c");
        ptr = &temp19c[0];
            for (byte k = 0; k < 111; k++) {
              displayInt = pgm_read_word_near(ptr + k);
              currentData[k] = displayInt;
            }
      } else {
        Serial.println("25c");
        ptr = &temp25c[0];
            for (byte k = 0; k < 111; k++) {
              displayInt = pgm_read_word_near(ptr + k);
              currentData[k] = displayInt;
            }
      }
      flag = !flag;
  }
     
  My_Sender.IRsendRaw::send(currentData, 111, 38);
  delay(2);
  counter--;
  if (counter <= 0) {
    delay(2000);
    Serial.print(".");
    counter = 10;
  }
}
