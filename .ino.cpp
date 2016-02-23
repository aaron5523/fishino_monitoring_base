//This is a automatic generated file
//Please do not modify this file
//If you touch this file your change will be overwritten during the next build
//This file has been generated on 2016-02-22 19:42:48

#include "Arduino.h"
#include "Arduino.h"
#include <SoftwareSerial.h>
#include <SPI.h>
#include <SD.h>
#include "Fishino.h"
#include "FishinoDebug.h"
#include "RtcDateTime.h"
#include "RtcDS1307.h"
#include "RGBTools.h"
void setRed() ;
void setGreen() ;
void setBlue() ;
void setOrange() ;
void setWhite() ;
void setBlack() ;
void setTeal() ;
void setPurple() ;
void setYellow() ;
void blinkGreen(int times) ;
void blinkRed(int times) ;
void doRGBPOST() ;
void printMac(const uint8_t *mac) ;
char readNB(void) ;
bool readConfig(void) ;
const uint8_t* getMacForUpdates() ;
void printMacAddress() ;
void setup() ;
void loop() ;
void printCurDateTime() ;
void printDateTime(const RtcDateTime& dt) ;

#include "fishino_monitoring_base.ino"

