/* prevents multiple, redundant includes */
/* make sure to use a symbol that is fairly sure to be unique */
#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define SIGNAL_SIZE 111
#define KHZ 38
#define REPETITIONS 10
#define ITERATIONS 3
#define IR_LED 2

const PROGMEM short unsigned int AC_ONOFFA[SIGNAL_SIZE] = {1050,500, 1100,500, 1050,2500, 1000,600, 950,600, 1050,550, 1050,2450, 1050,550, 1050,550, 1050,500, 1050,2500, 1050,550, 1050,2500, 1000,550, 1050,500, 1100,500, 1100,2450, 1000,600, 1000,600, 1000,550, 1000,600, 950,2550, 1050,2500, 1050,2500, 1100,500, 1000,600, 1000,550, 1050,2500, 1050,500, 1100,2450, 1050,2550, 1000,2550, 1000,550, 1050,550, 1050,500, 1050,550, 1000,600, 1000,550, 1050,500, 1000,600, 1100,500, 1050,500, 1100,500, 1050,550, 1000,550, 1050,550, 1050,500, 1050,600, 1000,2500, 1050,550, 1000,550, 1050,550, 1050,2450, 1100,500, 1050,550, 1000}; 
const PROGMEM short unsigned int AC_ONOFFB[SIGNAL_SIZE] = {1050,550, 1050,500, 1050,2500, 1050,550, 1000,550, 1050,550, 1050,2500, 1000,550, 1050,550, 1050,550, 1000,2500, 1050,550, 1000,2550, 1000,550, 1050,550, 1050,550, 1050,500, 1050,550, 1050,500, 1050,550, 1000,550, 1000,2550, 1050,2500, 1050,2550, 1000,550, 1050,550, 950,600, 1000,2550, 1050,500, 1050,2550, 1000,2500, 1050,2550, 1000,550, 1050,550, 1050,500, 1050,550, 1000,550, 1050,550, 950,600, 1050,550, 1050,550, 1050,550, 1000,550, 1050,550, 950,600, 1050,500, 1100,500, 1050,550, 1050,2500, 1050,550, 950,600, 1050,550, 1050,2500, 1000,550, 1050,550, 1000};  
const PROGMEM short unsigned int AC_MODE[SIGNAL_SIZE] = {1000,550, 1050,550, 950,2550, 1050,550, 1050,550, 1000,550, 1050,2500, 1000,600, 1000,550, 1050,550, 1000,2550, 950,600, 1000,550, 1050,2500, 1050,550, 1000,600, 1050,2500, 1000,550, 1000,600, 950,600, 1000,600, 1000,2550, 1050,2500, 1000,2550, 1000,600, 950,600, 1000,550, 1050,2550, 1000,550, 1050,2500, 1000,2550, 1000,2550, 1050,550, 1000,550, 1050,550, 1000,550, 1050,550, 950,600, 1050,550, 1000,600, 1050,550, 950,600, 1000,550, 1000,600, 1050,500, 1050,550, 1050,550, 1000,600, 1000,2500, 1050,550, 1050,500, 1050,550, 1050,2500, 1000,600, 1000,550, 950};  
const PROGMEM short unsigned int AC_TURBO[SIGNAL_SIZE] = {1100,500, 1000,600, 1050,2450, 1000,600, 1050,500, 1050,550, 1050,2500, 1050,550, 1050,500, 1050,550, 1050,2500, 1000,550, 1050,2500, 1050,500, 1100,500, 1050,550, 1000,2550, 1000,550, 1050,2500, 1050,550, 1050,500, 1050,2500, 1000,2550, 1000,2600, 1000,550, 1000,550, 1050,550, 1000,2550, 1050,500, 1100,2450, 1050,2500, 1050,2500, 1050,550, 1050,500, 1100,500, 1050,550, 1050,500, 1050,550, 1050,500, 1050,550, 1100,500, 1050,550, 1050,500, 1050,500, 1050,550, 1000,550, 1100,500, 1000,600, 1000,2550, 1050,500, 1000,600, 1050,500, 1050,2500, 1050,550, 1050,550, 1000};  
const PROGMEM short unsigned int AC_SWINGON[SIGNAL_SIZE] = {1050,550, 1000,550, 1000,2550, 950,600, 1050,550, 1000,600, 1000,2500, 1050,550, 1000,600, 1000,550, 1050,2500, 1050,550, 950,2550, 1050,550, 1000,600, 1000,600, 1000,2500, 1000,600, 1000,2550, 1000,550, 1000,600, 1050,500, 1050,550, 1000,600, 1000,550, 1000,600, 1000,550, 1050,2500, 1050,550, 1000,2550, 1000,2550, 950,2600, 1000,550, 1050,550, 1050,550, 1000,550, 1050,550, 1000,550, 1000,600, 1000,600, 1000,550, 1050,550, 1000,550, 1000,600, 1000,550, 1050,550, 1000,600, 1000,600, 1000,2500, 1000,600, 1000,550, 1050,550, 1050,2500, 1050,500, 1000,600, 1000};  
const PROGMEM short unsigned int AC_UNKNOWN[SIGNAL_SIZE] = {1000,550, 1050,550, 1000,2500, 1000,600, 1000,550, 1050,550, 1050,2500, 1000,600, 1000,550, 1000,600, 1000,2550, 1000,550, 950,2600, 1000,550, 1050,550, 1000,600, 1050,2500, 1000,550, 1050,2500, 1000,600, 950,600, 1000,2550, 1050,2500, 1050,2500, 1050,550, 950,600, 1050,550, 1050,2500, 1000,600, 1000,2500, 1000,2550, 1000,2550, 1050,550, 1050,550, 1000,550, 1050,550, 1000,550, 950,650, 1000,550, 1050,550, 1050,550, 1000,550, 1050,550, 950,600, 1050,550, 1050,550, 1000,550, 1000,600, 1000,2550, 950,600, 1050,550, 1000,600, 1000,2500, 1000,600, 1000,550, 1000}; 
const PROGMEM short unsigned int AC_TEMP16C[SIGNAL_SIZE] = {1050,500, 1100,500, 1050,2500, 1000,600, 1000,550, 1000,600, 950,2550, 1050,550, 1000,600, 1050,500, 1050,2500, 1000,550, 1050,2550, 1000,550, 1000,600, 1000,600, 950,2550, 1050,550, 1050,2500, 1000,550, 1000,600, 1050,2500, 950,2550, 1050,2550, 1050,500, 1100,500, 1050,550, 1000,2500, 1050,550, 1050,500, 1050,550, 1050,550, 1050,550, 1050,500, 1050,550, 1050,500, 1050,500, 1100,500, 1050,550, 1050,550, 1050,500, 1050,550, 1050,500, 1100,500, 1050,550, 1000,550, 1050,550, 1000,550, 1100,2450, 1100,500, 1050,550, 1050,500, 1050,2500, 1050,500, 1050,550, 1050};  
const PROGMEM short unsigned int AC_TEMP17C[SIGNAL_SIZE] = {1100,500, 1050,500, 1100,2450, 1050,550, 1050,550, 1000,550, 1050,2500, 1050,550, 1000,550, 1050,550, 1050,2450, 1100,500, 1050,2500, 1050,550, 1000,550, 1050,550, 1050,2500, 1050,500, 1050,2500, 1050,500, 1100,500, 1050,2500, 1050,2500, 1050,2500, 1050,550, 1050,550, 1000,550, 1050,2500, 1000,550, 1050,550, 1050,500, 1050,2550, 1050,500, 1050,550, 1050,500, 1050,550, 1050,500, 1050,550, 1050,550, 1000,600, 1000,550, 1050,500, 1100,500, 1050,500, 1100,500, 1050,550, 1000,550, 1000,600, 1050,2500, 1050,550, 1050,500, 1050,550, 1050,2500, 1050,500, 1050,550, 1050};
const PROGMEM short unsigned int AC_TEMP18C[SIGNAL_SIZE] = {1050,500, 1050,550, 1050,2450, 1100,500, 1050,550, 1000,550, 1050,2500, 1050,550, 1050,500, 1050,550, 1050,2500, 1050,500, 1050,2500, 1050,550, 1000,550, 1050,550, 1050,2500, 1050,500, 1100,2450, 1050,550, 1050,550, 1000,2500, 1050,2500, 1050,2500, 1100,500, 1050,550, 1000,550, 1050,2500, 1050,550, 1050,500, 1050,2500, 1050,550, 1050,550, 1000,550, 1000,600, 1050,500, 1050,500, 1100,500, 1050,550, 1000,600, 1000,550, 1050,550, 1050,500, 1050,550, 1050,550, 1000,550, 1050,500, 1050,550, 1100,2450, 1050,550, 1000,600, 1000,550, 1050,2500, 1050,500, 1050,550, 1050};
const PROGMEM short unsigned int AC_TEMP19C[SIGNAL_SIZE] = {1050,550, 1050,500, 1050,2500, 1050,550, 1050,500, 1050,550, 1050,2500, 1050,550, 1000,550, 1050,550, 1050,2450, 1050,550, 1050,2500, 1050,500, 1050,550, 1050,550, 1050,2500, 1050,500, 1050,2500, 1050,500, 1050,550, 1050,2500, 1050,2500, 1000,2550, 1050,550, 1050,500, 1050,550, 1050,2500, 1000,550, 1050,550, 1050,2450, 1100,2500, 1050,550, 1000,550, 1050,550, 1050,500, 1050,500, 1100,500, 1050,550, 1000,600, 1000,550, 1050,550, 1050,500, 1050,550, 1050,550, 1000,550, 1050,500, 1050,550, 1100,2450, 1050,550, 1050,550, 1000,550, 1050,2500, 1050,500, 1050,550, 1050};
const PROGMEM short unsigned int AC_TEMP20C[SIGNAL_SIZE] = {1050,500, 1100,500, 1050,2500, 1050,550, 1000,550, 1050,500, 1050,2500, 1050,550, 1050,550, 1050,500, 1050,2500, 1050,500, 1100,2500, 1000,550, 1050,550, 1000,600, 1000,2500, 1050,550, 1050,2450, 1100,500, 1050,550, 1050,2500, 1000,2500, 1050,2550, 1050,500, 1050,550, 1050,550, 1000,2500, 1050,550, 1050,2500, 1050,500, 1050,550, 1050,550, 1050,500, 1050,550, 1050,500, 1050,550, 1050,500, 1050,550, 1050,550, 1050,550, 1050,500, 1050,500, 1100,500, 1050,550, 1050,500, 1050,550, 1000,600, 1050,2500, 1050,550, 1000,550, 1050,500, 1050,2500, 1050,550, 1050,500, 1050};
const PROGMEM short unsigned int AC_TEMP22C[SIGNAL_SIZE] = {1000,600, 950,600, 1000,2550, 950,600, 1000,600, 1000,600, 950,2550, 1000,600, 1000,600, 950,650, 950,2550, 1000,550, 1050,2500, 1000,600, 1000,600, 950,650, 950,2550, 1050,550, 1000,2550, 950,600, 1000,550, 1000,2600, 950,2550, 1000,2600, 1000,600, 950,600, 950,650, 950,2550, 1000,600, 1000,2550, 950,2550, 1000,600, 1050,550, 1000,600, 1000,550, 1000,600, 1000,550, 1000,600, 1000,550, 1000,600, 1000,600, 1000,550, 1000,600, 1000,550, 1000,600, 1000,600, 950,600, 1000,600, 1000,2550, 1000,600, 950,600, 1000,600, 1000,2550, 950,600, 1000,550, 1000};  
const PROGMEM short unsigned int AC_TEMP23C[SIGNAL_SIZE] = {1000,550, 1050,550, 1000,2550, 1000,600, 950,600, 1000,600, 950,2550, 1050,550, 1000,600, 950,600, 1000,2550, 1000,600, 1000,2550, 950,600, 1000,600, 950,650, 950,2550, 1000,600, 1000,2500, 1050,550, 1000,600, 1000,2550, 950,2550, 1050,2550, 1000,600, 950,650, 950,600, 950,2550, 1000,600, 1000,2550, 950,2550, 1050,2550, 1000,600, 950,600, 1000,550, 1000,600, 1000,600, 1000,550, 1000,600, 950,650, 1000,550, 1000,600, 1000,600, 950,600, 1000,550, 1000,600, 950,600, 1000,600, 1050,2550, 950,600, 1000,550, 1000,600, 1000,2550, 950,600, 1000,600, 1000};  
const PROGMEM short unsigned int AC_TEMP24C[SIGNAL_SIZE] = {1000,600, 1000,550, 1000,2550, 1000,550, 1000,600, 1000,600, 1000,2550, 950,600, 1000,600, 1000,550, 1050,2500, 1000,600, 950,2550, 1050,550, 1000,600, 1000,600, 1000,2500, 1050,550, 1000,2550, 950,600, 1000,600, 1000,2500, 1050,2550, 1000,2550, 1000,550, 1000,600, 1000,550, 1000,2550, 1000,2550, 1000,600, 950,600, 1000,650, 950,600, 1000,550, 1000,600, 1000,550, 1000,600, 1000,550, 1000,600, 1000,600, 1000,600, 950,600, 1000,600, 950,600, 1000,550, 1050,550, 1050,550, 1000,600, 1000,2550, 950,600, 1000,600, 1000,550, 1050,2500, 1000,600, 950,600, 1000}; 
const PROGMEM short unsigned int AC_TEMP25C[SIGNAL_SIZE] = {1000,600, 1000,550, 1000,2550, 1000,550, 1000,600, 1000,550, 1050,2550, 950,600, 1000,600, 1000,550, 1000,2550, 1000,600, 1000,2500, 1050,550, 1000,550, 1050,550, 1050,2550, 1000,550, 1000,2550, 1000,550, 1000,600, 1000,2500, 1050,2550, 1000,2550, 1000,550, 1050,550, 1000,550, 1050,2500, 1050,2500, 1000,600, 1000,550, 1000,2600, 1000,550, 1000,600, 1000,550, 1000,600, 1000,550, 1000,600, 1000,550, 1000,650, 1000,550, 1000,600, 950,600, 1000,550, 1000,600, 1000,600, 1000,550, 1050,550, 1050,2500, 1000,550, 1000,600, 1000,600, 1000,2550, 950,600, 1000,600, 950}; 
const PROGMEM short unsigned int AC_TEMP26C[SIGNAL_SIZE] = {1000,600, 1000,550, 1000,2550, 950,600, 1000,600, 1000,600, 950,2550, 1050,550, 1000,600, 1000,600, 950,2550, 1000,550, 1000,2550, 1000,600, 1000,600, 950,650, 950,2550, 1000,600, 1000,2550, 950,600, 1000,550, 1050,2500, 1000,2550, 1000,2600, 950,600, 1000,600, 950,650, 950,2550, 1050,2500, 1000,600, 950,2550, 1000,600, 1050,550, 1000,600, 950,600, 1000,600, 950,600, 1000,550, 1000,600, 1000,600, 1000,600, 1000,550, 1050,550, 1000,550, 1000,600, 1000,600, 1000,550, 1000,600, 1000,2550, 1000,550, 1050,550, 1000,600, 950,2550, 1000,600, 1000,550, 1000};  
const PROGMEM short unsigned int AC_TEMP27C[SIGNAL_SIZE] = {1000,600, 1000,550, 1000,2550, 1000,550, 1050,550, 1000,600, 1000,2550, 950,650, 950,600, 1000,600, 950,2550, 1050,550, 950,2550, 1050,550, 1050,550, 1000,550, 1050,2550, 950,600, 1000,2550, 1000,550, 1000,600, 950,2550, 1050,2550, 1000,2550, 1000,550, 1000,600, 1000,550, 1050,2500, 1000,2550, 1000,600, 1000,2550, 950,2600, 1000,550, 1050,550, 1000,600, 1000,550, 1000,600, 950,600, 1000,600, 1000,600, 1000,550, 1000,600, 1000,550, 1000,600, 1000,550, 1050,550, 1000,600, 950,650, 1000,2500, 1000,600, 1000,550, 1050,550, 1000,2550, 1000,550, 1000,600, 1000};
const PROGMEM short unsigned int AC_TEMP28C[SIGNAL_SIZE] = {1000,600, 1000,550, 1000,2550, 1000,550, 1000,600, 1000,600, 1000,2550, 950,650, 950,600, 1000,550, 1000,2550, 1000,600, 950,2550, 1000,600, 1000,600, 1000,550, 1050,2550, 950,600, 1000,2550, 1000,550, 1000,600, 950,2550, 1050,2550, 1000,2550, 1000,550, 1000,600, 1000,550, 1050,2500, 1000,2550, 1000,2550, 1000,600, 950,650, 1000,550, 1000,600, 1000,550, 1000,600, 1000,550, 1000,600, 1000,600, 950,650, 1000,550, 1000,600, 950,600, 1000,550, 1000,600, 1000,550, 1050,550, 1050,550, 1000,2550, 1000,600, 950,600, 1000,600, 1000,2550, 1000,550, 1000,600, 950};  

#endif
