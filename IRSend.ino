/* Example program for from IRLib – an Arduino library for infrared encoding and decoding
   Version 1.3   January 2014
   Copyright 2014 by Chris Young http://cyborg5.com
   Based on original example sketch for IRremote library
   Version 0.11 September, 2009
   Copyright 2009 Ken Shirriff
   http://www.righto.com/
*/
#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>

#include "definitions.h"
#include "private_definitions.h"

HTTPClient http;
WiFiClient client;
IRsend My_Sender(IR_LED);

unsigned int counter = REPETITIONS;
unsigned int iterator = ITERATIONS;
short unsigned int* ptr = &AC_TEMP24C[0];
short unsigned int currentData[SIGNAL_SIZE];

String lastInput;
String currentInput;

bool isOutputtingIRSignal;

const char *ssid = STASSID;
const char *password = STAPSK;

void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  My_Sender.begin();
  setCurrentData(&AC_TEMP24C[0]);

  Serial.println("Initialized");
}

void loop() {
  if (!isOutputtingIRSignal) {
    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, GET_URL)) {  // HTTP
      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
          currentInput = payload + "\n";
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
  }

  if (lastInput != currentInput) {
    isOutputtingIRSignal = true;
    String input = currentInput;
    lastInput = currentInput;
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
      setCurrentData(&AC_TEMP22C[0]); // TODO
    } else if (input == "22\n") {
      setCurrentData(&AC_TEMP22C[0]);
    } else if (input == "23\n") {
      setCurrentData(&AC_TEMP23C[0]);
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
      isOutputtingIRSignal = false;
    }

  } else {
        delay(3000);
  }

  if (isOutputtingIRSignal) {
    My_Sender.sendRaw(currentData, SIGNAL_SIZE, KHZ);
    delay(2);
    counter--;
    if (counter <= 0) {
      counter = REPETITIONS;
      if (iterator <= 0) {
        iterator = ITERATIONS;
        Serial.print("Sent");
        isOutputtingIRSignal = false;
      } else {
        Serial.print(".");
        delay(2000);
        iterator--;
      }
    }
  }
}

void setCurrentData(short unsigned int* signalCode) {
  short unsigned int displayInt;

  for (byte k = 0; k < SIGNAL_SIZE; k++) {
    displayInt = pgm_read_word_near(signalCode + k);
    currentData[k] = displayInt;
  }
}
