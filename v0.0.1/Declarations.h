#include <FS.h>
#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
#include "Free_Fonts.h"
#include "Background.h"
#include <TFT_eSPI.h>
#include <SPI.h>
#include "NTPClient.h"
#include <WiFi.h>
#include <WiFiUdp.h>
#include <JSON_Decoder.h>
#include <OpenWeather.h>
#include "Wifi_Icon.h"

/////////////////////////////////////////////
///////////////// Functions /////////////////
/////////////////////////////////////////////
// Network Time Protocol
WiFiUDP ntpUDP;
// Touchscreen TFT
TFT_eSPI tft = TFT_eSPI();
// TFT Sprites
TFT_eSprite clockNTP = TFT_eSprite(&tft);
TFT_eSprite wifi = TFT_eSprite(&tft);
TFT_eSprite login = TFT_eSprite(&tft);
TFT_eSprite weather = TFT_eSprite(&tft);
// OpenWeather
OW_Weather ow;

/////////////////////////////////////////////
////////// IFDEF FINGERPRINT_AUTH ///////////
/////////////////////////////////////////////
#ifdef FINGERPRINT_AUTH
  SoftwareSerial FingerSerial(5, 4);
  Adafruit_Fingerprint finger = Adafruit_Fingerprint(&FingerSerial);
  #define CALIBRATION_FILE "/TouchCalData1"
  #define REPEAT_CAL false
  #include "Touch_Setup.h"
  #include "Bootanimation.h"
  unsigned short AuthState = 0;
  // Fingerprint Scanning Function
  int getFingerprintIDez() {
    uint8_t p = finger.getImage();
    if (p != FINGERPRINT_OK)  return -1;
    p = finger.image2Tz();
    if (p != FINGERPRINT_OK)  return -1;
    p = finger.fingerFastSearch();
    if (p == FINGERPRINT_OK) {
      //if(finger.fingerID == 3)  {
      AuthState=1;
      //}
    } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
      AuthState=0;
      return p;
    } else if (p == FINGERPRINT_NOTFOUND) {
      AuthState=0;
      return p;
    } else {
      AuthState=0;
      return p;
    }
    return finger.fingerID;
  }
#endif