#include "Weather_Functions.h"
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
////////////////////// VOID Setup Begin/////////////////////////
////////////////////////////////////////////////////////////////
void setup(void)  {
if(Setup_IS_Complete == 0)  {
  #ifdef FINGERPRINT_AUTH
    finger.begin(57600);
  #endif

  ////////////// Setting up the TFT_eSPI library //////////////
  tft.begin();
  tft.setRotation(1); //Landscape
  touch_calibrate(); //Touch calibration function
  tft.fillScreen(TFT_BLACK); //Clear Screen

  /////////// Creating Sprites to avoid Flickering ////////////
  login.createSprite(TFT_LANDSCAPE_WIDTH, 100);
  clockNTP.createSprite(300, 80);
  wifi.createSprite(24, 24);
  wifi.setSwapBytes(true); //If we draw images we must set this
  tft.setSwapBytes(true);
  login.setSwapBytes(true);
  #ifdef TFT_BACKGROUND_IS_IMAGE
    tft.pushImage(0, 0, TFT_LANDSCAPE_WIDTH, TFT_LANDSCAPE_HEIGHT, background); //Push background
  #endif

  ////////////////// BootAnimation Function //////////////////
  BootAnimation();
}
if(Setup_IS_Complete == 1)  {
  ///////////////////// Wi-Fi Functions //////////////////////
  #ifdef TFT_BACKGROUND_IS_IMAGE
    tft.pushImage(0, 0, TFT_LANDSCAPE_WIDTH, TFT_LANDSCAPE_HEIGHT, background); //Push background
  #endif

  #ifdef TFT_BACKGROUND_IS_SOLID
    tft.fillScreen(TFT_CUSTOM_COLOR);
  #endif

  WiFi.begin(ssid, password); // Begin Wi-Fi
  if( WiFi.status() == WL_CONNECTED ) {
    wifi.pushImage(0, 0, 24, 24, Wifi_Icon); // If Wi-Fi is connected, push the wifi icon to the right upper corner
    wifi.pushSprite(446, 0, TFT_WHITE);
  } else  {
    wifi.pushImage(0, 0, 24, 24, Wifi_Icon); // If Wi-Fi isn't connected, push the wifi icon to the right upper corner and draw a line across it
    wifi.pushSprite(446, 0, TFT_WHITE);
    tft.drawLine(446, 24, 470, 0, TFT_BLACK);
    delay(1000); // Some Delay
    rp2040.reboot(); // Rebooting the RasPi
  }

  ////////////////// TimeClient Function ////////////////////
  timeClient.begin(); //Begin Time Client
}
}
////////////////////////////////////////////////////////////////
/////////////////////// VOID Setup End//////////////////////////
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
////////////////////// VOID Loop Begin//////////////////////////
////////////////////////////////////////////////////////////////
void loop() {
  timeClient.update();

  #ifdef TFT_BACKGROUND_IS_IMAGE
    login.pushImage(0, -30, TFT_LANDSCAPE_WIDTH, TFT_LANDSCAPE_HEIGHT, background);
  #endif

  #ifdef TFT_BACKGROUND_IS_SOLID
    login.fillSprite(TFT_CUSTOM_COLOR);
  #endif

  clockNTP.fillSprite(TFT_BLACK);
  clockNTP.setFreeFont(FF24);
  clockNTP.setTextColor(TFT_WHITE);
  clockNTP.setCursor(25, 70);
  clockNTP.print(timeClient.getFormattedTime());
  clockNTP.pushToSprite(&login, 120, 10, TFT_BLACK); //Push ClockNTP sprite to Login Sprite
  if(AuthState == 0)  {
    login.pushSprite(0, 30);
    printCurrentWeather(); // Print Current Weather Info Function
    tft.setFreeFont(FF21);
    tft.setCursor(163, 310);
    tft.print("- SoundOS v0.0.1 -");
  }
  #ifdef FINGERPRINT_AUTH
    getFingerprintIDez(); //FingerPrint Reading Cycle
    if(AuthState == 1)  {
      tft.fillScreen(TFT_BLACK);
    }
  #endif
}
////////////////////////////////////////////////////////////////
/////////////////////// VOID Loop End///////////////////////////
////////////////////////////////////////////////////////////////