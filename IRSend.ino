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
unsigned int* ptr = &AC_TEMP25C[0];
unsigned int currentData[111];
bool flag = true;
   
void setup()
{
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readString();
      Serial.println("got input" + input);
      
      if (input == "on\n") {
        setCurrentData(&AC_ONOFFA[0]);
      } else if (input == "off\n") {
        setCurrentData(&AC_ONOFFB[0]);
      } else if (input == "mode\n") {
        setCurrentData(&AC_MODE[0]);
      } else if (input == "turbo\n") {
        setCurrentData(&AC_TURBO[0]);
      } else if (input == "swing\n") {
        setCurrentData(&AC_SWINGON[0]);
      } else if (input == "16\n") {
        setCurrentData(&AC_TEMP16C[0]);
      } else if (input == "17\n") {
        setCurrentData(&AC_TEMP17C[0]);
      } else if (input == "18\n") {
        setCurrentData(&AC_TEMP18C[0]);
      } else if (input == "19\n") {
        setCurrentData(&AC_TEMP19C[0]);
      } else if (input == "20\n") {
        setCurrentData(&AC_TEMP20C[0]);
      } else if (input == "21\n") {
        setCurrentData(&AC_TEMP21C[0]);
      } else if (input == "22\n") {
        setCurrentData(&AC_TEMP22C[0]);
      } else if (input == "23\n") {
        setCurrentData(&AC_TEMP24C[0]); // TODO
      } else if (input == "24\n") {
        setCurrentData(&AC_TEMP24C[0]);
      } else if (input == "25\n") {
        setCurrentData(&AC_TEMP25C[0]);
      } else if (input == "26\n") {
        setCurrentData(&AC_TEMP26C[0]);
      } else if (input == "27\n") {
        setCurrentData(&AC_TEMP27C[0]);
      } else if (input == "28\n") {
        setCurrentData(&AC_TEMP28C[0]);
      } else {
        Serial.println("Unknown input"); 
      }
       
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

void setCurrentData(unsigned int* signalCode) {
  unsigned int displayInt;
  
  for (byte k = 0; k < SIGNAL_SIZE; k++) {
    displayInt = pgm_read_word_near(signalCode + k);
    currentData[k] = displayInt;
  }
}
