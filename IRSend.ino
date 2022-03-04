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


    unsigned int displayInt;
    unsigned int* ptr = &temp25c[0];
    unsigned int currentData[111];
    
void setup()
{
  Serial.begin(9600);
}

void loop() {
  if (Serial.read() != -1) {
      Serial.println("start");

  //while(true){
    
    for (byte k = 0; k < 111; k++) {
      displayInt = pgm_read_word_near(ptr + k);
      currentData[k] = displayInt;
    }


//    for(int i = 0; i < 111; i++)
//    {
//      Serial.print(currentData[i]);
//      Serial.print(" ");
//    }
    
    for (int i = 0; i < 100; i++) {
      My_Sender.IRsendRaw::send(currentData, 111, 38);
    delay(100);
    }
          Serial.println("end");

    
  //  delay(0.5);  }
  }
}
