//This is a automatic generated file
//Please do not modify this file
//If you touch this file your change will be overwritten during the next build
//This file has been generated on 2016-02-21 14:34:59

#include "Arduino.h"
#include "Arduino.h"
#include <SoftwareSerial.h>
#include <SPI.h>
#include <SD.h>
#include "Fishino.h"
#include "FishinoDebug.h"
#include "RtcDateTime.h"
#include "RtcDS1307.h"
void printMac(const uint8_t *mac) ;
char readNB(void) ;
bool readConfig(void) ;
void setup() ;
void loop() ;
void printCurDateTime() ;
void printDateTime(const RtcDateTime& dt) ;

#include "fishino_monitoring_base.ino"

