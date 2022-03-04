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
//const   unsigned int  temp25c[111] = {1000,600, 1000,550, 1000,2550, 1000,550, 1000,600, 1000,550, 1050,2550, 950,600, 1000,600, 1000,550, 1000,2550, 1000,600, 1000,2500, 1050,550, 1000,550, 1050,550, 1050,2550, 1000,550, 1000,2550, 1000,550, 1000,600, 1000,2500, 1050,2550, 1000,2550, 1000,550, 1050,550, 1000,550, 1050,2500, 1050,2500, 1000,600, 1000,550, 1000,2600, 1000,550, 1000,600, 1000,550, 1000,600, 1000,550, 1000,600, 1000,550, 1000,650, 1000,550, 1000,600, 950,600, 1000,550, 1000,600, 1000,600, 1000,550, 1050,550, 1050,2500, 1000,550, 1000,600, 1000,600, 1000,2550, 950,600, 1000,600, 950}; 

IRsend My_Sender;

void setup()
{
  Serial.begin(9600);
}

void loop() {
  if (Serial.read() != -1) {
    //send a code  every time a character is received from the serial port
    //Sony DVD power A8BCA

unsigned int displayInt;
unsigned int* ptr = &temp25c[0];
    for (byte k = 0; k < 111; k++) {
    displayInt = pgm_read_word_near(ptr + k);
    Serial.println(displayInt);
    }
    //        My_Sender.IRsendRaw::send(temp25c, 111, 38);
    Serial.print(".");
  }
}
