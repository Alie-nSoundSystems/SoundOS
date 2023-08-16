  #include <Adafruit_Fingerprint.h>
  #include <SoftwareSerial.h>
  TFT_eSprite boot = TFT_eSprite(&tft);
  uint8_t loadbar = 0;
  int cntr = 0;
  uint8_t Setup_IS_Complete = 0;

  void reboot_text()  {
      switch(cntr)  {
          case 0:
            tft.setCursor(150, 250);
            tft.print("Trying again in: ");
            tft.setCursor(320, 250);
            tft.print("5");
            break;
          case 1:
            tft.setCursor(150, 250);
            tft.print("Trying again in: ");
            tft.setCursor(320, 250);
            tft.print("4");
            break;
          case 2:
          tft.setCursor(150, 250);
            tft.print("Trying again in: ");
            tft.setCursor(320, 250);
            tft.print("3");
            break;
          case 3:
            tft.setCursor(150, 250);
            tft.print("Trying again in: ");
            tft.setCursor(320, 250);
            tft.print("2");
            break;
          case 4:
            tft.setCursor(150, 250);
            tft.print("Trying again in: ");
            tft.setCursor(320, 250);
            tft.print("1");
            break;
          case 5:
            tft.setCursor(140, 250);
            tft.print("REBOOTING NOW!");
            break;
        }
  }

  void BootAnimation()  {
    if (finger.verifyPassword()) {
      //tft.fillScreen(TFT_WHITE);
      tft.drawRect(140, 255, 200, 5, TFT_BLACK);
      for(uint8_t compload; compload<=199; ++compload){
        tft.setFreeFont(FF24);
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(45, 140);
        tft.print("SoundOS");
        tft.fillRect(141, 256, compload, 3, TFT_BLACK);
        delay(10);
      }
      /////////////////////////////////////////////////////////////
      Setup_IS_Complete=1;
      setup();
    } else {
      boot.createSprite(480, 320);
      boot.setSwapBytes(true);
      tft.drawRect(140, 255, 200, 5, TFT_BLACK);
      for(loadbar; loadbar<=99; ++loadbar){
        tft.fillRect(141, 256, loadbar, 3, TFT_BLACK);
        delay(10);
      }
      tft.setFreeFont(FF18);
      while(1)  {
        tft.fillScreen(TFT_PURPLE);
        boot.fillSprite(TFT_BLACK);
        boot.pushImage(0, 0, 480, 320, background);
        boot.drawRect(140, 255, 200, 5, TFT_BLACK);
        boot.fillRect(141, 256, 99, 3, TFT_BLACK);
        boot.pushSprite(0, 0);
        tft.setCursor(190, 100);
        tft.print("SoundOS");
        tft.setCursor(90, 200);
        tft.print("Waiting for fingerprint sensor.  ");
        reboot_text();
        //BtLOOP();
        delay(1000);
        tft.fillScreen(TFT_PURPLE);
        boot.fillSprite(TFT_BLACK);
        //boot.pushImage(0, 0, 480, 320, background);
        boot.drawRect(140, 255, 200, 5, TFT_BLACK);
        boot.fillRect(141, 256, 99, 3, TFT_BLACK);
        boot.pushSprite(0, 0);
        tft.setCursor(190, 100);
        tft.print("SoundOS");
        tft.setCursor(90, 200);
        tft.print("Waiting for fingerprint sensor . ");
        reboot_text();
        //BtLOOP();
        delay(1000);
        tft.fillScreen(TFT_PURPLE);
        boot.fillSprite(TFT_BLACK);
        //boot.pushImage(0, 0, 480, 320, background);
        boot.drawRect(140, 255, 200, 5, TFT_BLACK);
        boot.fillRect(141, 256, 99, 3, TFT_BLACK);
        boot.pushSprite(0, 0);
        tft.setCursor(190, 100);
        tft.print("SoundOS");
        tft.setCursor(90, 200);
        tft.print("Waiting for fingerprint sensor  .");
        reboot_text();
        //BtLOOP();
        delay(1000);
        cntr++;
        if (cntr > 5)  {
          cntr=0;
          rp2040.reboot();
        }
      }
    }
  }