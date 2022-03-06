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
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <uri/UriBraces.h>
#include "definitions.h"

#ifndef STASSID
#define STASSID "NETGEAR"
#define STAPSK  "123456789"
#endif


ESP8266WebServer server(80);
IRsend My_Sender(IR_LED);

unsigned int counter = REPETITIONS;
short unsigned int* ptr = &AC_TEMP24C[0];
short unsigned int currentData[SIGNAL_SIZE];

String lastInput;
String currentInput;

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

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on(F("/"), []() {
    server.send(200, "text/plain", "hello from esp8266!");
  });

  server.on(UriBraces("/command/{}"), []() {
    String command = server.pathArg(0);
    currentInput = command  + "\n";
    server.send(200, "application/json", "{\"status\": \"success\", \"command\": \"" + command +"\"}");
  });

  server.begin();
  Serial.println("HTTP server started");

  My_Sender.begin();
  setCurrentData(&AC_TEMP24C[0]);

  Serial.println("Initialized");
}

void loop() {
  server.handleClient();
  if (lastInput != currentInput) {
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
      setCurrentData(&AC_TEMP22[0]);
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
    }

  }

  My_Sender.sendRaw(currentData, SIGNAL_SIZE, KHZ);
  delay(2);
  counter--;
  if (counter <= 0) {
    delay(2000);
    Serial.print(".");
    counter = REPETITIONS;
  }
}

void setCurrentData(short unsigned int* signalCode) {
  short unsigned int displayInt;

  for (byte k = 0; k < SIGNAL_SIZE; k++) {
    displayInt = pgm_read_word_near(signalCode + k);
    currentData[k] = displayInt;
  }
}

void handleNotFound() {
  server.send(404, "application/json", "{\"status\": \"error\"}");
}
