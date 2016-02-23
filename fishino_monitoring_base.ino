#include "Arduino.h"

#include <SoftwareSerial.h>

#include <SPI.h>
#include <SD.h>

#include "Fishino.h"
#include "FishinoDebug.h"
#include "RtcDateTime.h"
#include "RtcDS1307.h"
#include "RGBTools.h"

#define countof(a) (sizeof(a) / sizeof(a[0]))
#define DBG_RX_PIN 13
#define DBG_TX_PIN 12

SoftwareSerial debugSerial = SoftwareSerial(DBG_RX_PIN, DBG_TX_PIN);

const int SSID_SIZE = 20;
const int PASS_SIZE = 20;
char *SSID = (char *) FISHINO_MALLOC(SSID_SIZE);
char *PASSWORD = (char *) FISHINO_MALLOC(PASS_SIZE);

const int SD_CS = 4;

bool has_filesystem;
Sd2Card card;
SdVolume volume;
SdFile root;
SdFile file;
RtcDS1307 Rtc;

char *MAC = (char *) FISHINO_MALLOC(13);

int REDPin = 7;    // RED pin of the LED to PWM pin 9
int GREENPin = 8;  // GREEN pin of the LED to PWM pin 11
int BLUEPin = 9;   // BLUE pin of the LED to PWM pin 10

RGBTools rgb(REDPin, GREENPin, BLUEPin, COMMON_CATHODE);

/* RGB LED Methods*/
void setRed() {
	rgb.setColor(255, 0, 0);
}

void setGreen() {
	rgb.setColor(0, 255, 0);
}

void setBlue() {
	rgb.setColor(0, 0, 255);
}

void setOrange() {
	rgb.setColor(255, 136, 0);
}

void setWhite() {
	rgb.setColor(255, 255, 255);
}

void setBlack() {
	rgb.setColor(0, 0, 0);
}

void setTeal() {
	rgb.setColor(0, 242, 255);
}

void setPurple() {
	rgb.setColor(140, 0, 255);
}

void setYellow() {
	rgb.setColor(200, 200, 0);
}

/*RGB Animations*/
void blinkGreen(int times) {
	for (int i = 0; i < times; i++) {
		setGreen();
		delay(250);
		setBlack();
		delay(250);
	}
}

void blinkRed(int times) {
	for (int i = 0; i < times; i++) {
		setRed();
		delay(250);
		setBlack();
		delay(250);
	}
}

void blinkOrange(int times) {
	for (int i = 0; i < times; i++) {
		setOrange();
		delay(250);
		setBlack();
		delay(250);
	}
}

/*Arduino Methods*/
void doRGBPOST() {
	for (int i = 0; i < 5; i++) {
		setWhite();
		delay(500);
		setBlack();
		delay(500);
	}

	setRed();
	delay(1000);
	setGreen();
	delay(1000);
	setBlue();
	delay(1000);
	setWhite();
}
void printMac(const uint8_t *mac) {

	for (int i = 0; i < 6; i++) {
		char buffer[3];
		itoa(mac[i], buffer, 16);
//    Serial.print(mac[i], HEX);
		Serial.print(F("BUFF:"));
		Serial.println(buffer);
//    if (i < 5) {
//    	Serial << F(":");
//    }
	}
}

// read next non-blank char from file
// return 0 on EOF
char readNB(void) {
	int c;
	do {
		c = file.read();
		if (c == -1 || !c)
			return 0;
	} while (isspace(c));
	return c;
}

/* Read network & sensor information from
 *  file on SD card.  The format is just
 *  key/value pairs with a ":" delimeter,
 *  whitespace is excluded
 *
 * Current Support configuration file format
 * [BEGIN CONFIG]
 * SSID: "STRING"
 * PASS: "STRING"
 * [END CONFIG]
 */
bool readConfig(void) {
	const char *fname = "CONFIG.TXT";
	char c;

	char buf[PASS_SIZE];
	uint8_t iBuf;

	// open map file
	if (!file.open(&root, fname, O_READ))
		return false;
	iBuf = 0;

	while ((c = readNB()) != 0) {
		if (c == 'S') {
			if (((c = readNB()) == 'S') && ((c = readNB()) == 'I') && ((c =
					readNB()) == 'D') && ((c = readNB()) == ':') && ((c =
					readNB()) == '"')) {
				// found 'SSID' keyword, get the value
				while ((c = readNB()) != '"') {
					buf[iBuf++] = c;
					if (iBuf > PASS_SIZE || !c) {
						return false;
					}
				}
				buf[iBuf++] = '\0';
				strncpy(SSID, buf, iBuf);
				iBuf = 0;
			}
		}
		if (c == 'P') {
			if (((c = readNB()) == 'A') && ((c = readNB()) == 'S') && ((c =
					readNB()) == 'S') && ((c = readNB()) == ':') && ((c =
					readNB()) == '"')) {
				// found 'SSID' keyword, get the value
				while ((c = readNB()) != '"') {
					buf[iBuf++] = c;
					if (iBuf > PASS_SIZE || !c) {
						return false;
					}
				}
				buf[iBuf++] = '\0';
				strncpy(PASSWORD, buf, iBuf);
				iBuf = 0;
			}
		}
	}

	file.close();

	return true;
}

const uint8_t* getMacForUpdates() {
	const uint8_t* mac = Fishino.macAddress();
	return mac;
}

void printMacAddress() {
	Serial << F("MAC: ");
	const uint8_t* mac = getMacForUpdates();
	printMac(mac);
	Serial << F("\r\n");
}

void setup() {
	pinMode(REDPin, OUTPUT);
	pinMode(GREENPin, OUTPUT);
	pinMode(BLUEPin, OUTPUT);

	doRGBPOST();
	setPurple();
	Serial.begin(115200);
	Serial << F("Free RAM: ") << FreeRam() << "\r\n";
	setYellow();
	// initialize SPI:
	SPI.begin();
	SPI.setClockDivider(SPI_CLOCK_DIV2);
	setTeal();
	// reset and test wifi module
	Serial << F("Resetting Fishino...");
	while (!Fishino.reset()) {
		Serial << ".";
		blinkOrange(1);
		delay(500);
	}
	Serial << F("OK\r\n");
	blinkGreen(1);
	printMacAddress();
	pinMode(SD_CS, OUTPUT);       // Set the SDcard CS pin as an output
	digitalWrite(SD_CS, HIGH); // Turn off the SD card! (wait for configuration)

	// initialize the SD card.
	Serial << F("Setting up SD card...\n");
	// Pass over the speed and Chip select for the SD card
	has_filesystem = true;
	if (!card.init(SPI_FULL_SPEED, SD_CS)) {
		Serial << F("card failed\n");
		has_filesystem = false;
	}
	// initialize a FAT volume.
	if (!volume.init(&card)) {
		Serial << F("vol.init failed!\n");
		has_filesystem = false;
	}
	if (!root.openRoot(&volume)) {
		Serial << F("openRoot failed");
		has_filesystem = false;
	}

	// read appliances file
	if (has_filesystem) {
		if (!readConfig()) {
			has_filesystem = false;
		}
	}

	Serial << F("SSID: ") << SSID << "\n";
	Serial << F("PASS: ") << PASSWORD << "\n";
//  return;

	// set PHY mode 11B
	Fishino.setPhyMode(PHY_MODE_11G);

	// setup STATION mode
	// imposta la modalitè STATION
	Serial << F("Setting mode STATION_MODE\r\n");
	Fishino.setMode(STATION_MODE);

	uint8_t netCount = Fishino.scanNetworks();
	Serial << F("Found ") << netCount << F(" networks\r\n");
	// NOTE : INSERT HERE YOUR WIFI CONNECTION PARAMETERS !!!!!!
	Serial << F("Connecting AP...");
	while (!Fishino.begin(SSID, PASSWORD)) {
		blinkOrange(1);
		Serial << ".";
		delay(500);
	}
	blinkGreen(2);
	Serial << F("OK\r\n");

	Serial << F("Current SSID: ") << Fishino.SSID() << F("\r\n");
	const uint8_t *bssidMac = Fishino.BSSID();
	Serial << F("Current BSSID MAC: ");
	printMac(bssidMac);
	Serial << F("\r\n");
	Serial << F("Starting DHCP..\r\n");
	Fishino.staStartDHCP();

	// wait for connection completion
	Serial << "Waiting for IP...";
	int maxCount = 200;
	int count = 0;
	Serial << F("Status: ");
	while (Fishino.status() != STATION_GOT_IP) {
		Serial << ".";
//    Serial << Fishino.status() << "\r\n";
		delay(500);
		count++;
		if (count == maxCount) {
			break;
		}
	}
	Serial << F("OK\r\n");
	blinkGreen(3);
	// print current IP address
	Serial << F("IP Address :") << Fishino.localIP() << "\r\n";

	Rtc.Begin();
	printCurDateTime();
	Serial << F("Init done\n");
	blinkGreen(4);
	setGreen();

}

void loop() {
// if (!Rtc.IsDateTimeValid())
//    {
//        // Common Cuases:
//        //    1) the battery on the device is low or even missing and the power line was disconnected
//        Serial.println("RTC lost confidence in the DateTime!");
//    }
//
	printCurDateTime();
	delay(10000); // ten seconds
}

void printCurDateTime() {
	RtcDateTime now = Rtc.GetDateTime();
	printDateTime(now);
	Serial.println();
}

#define countof(a) (sizeof(a) / sizeof(a[0]))

void printDateTime(const RtcDateTime& dt) {
	char datestring[20];

	snprintf_P(datestring, countof(datestring),
			PSTR("%02u/%02u/%04u %02u:%02u:%02u"), dt.Month(), dt.Day(),
			dt.Year(), dt.Hour(), dt.Minute(), dt.Second());
	Serial.print(datestring);
}
