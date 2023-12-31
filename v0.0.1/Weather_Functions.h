#include "User_setup.h" //User Setup for SoundOS

void printCurrentWeather()	{
  OW_forecast  *forecast = new OW_forecast;
  ow.getForecast(forecast, api_key, latitude, longitude, units, language); //Get summarized forecast
  weather.createSprite(250, 50);
  weather.setSwapBytes(true); //We want to draw images, then we must use this
  weather.fillSprite(TFT_BLACK);
  #ifdef TFT_BACKGROUND_IS_IMAGE
    weather.pushImage(-115, -150, TFT_LANDSCAPE_WIDTH, TFT_LANDSCAPE_HEIGHT, background);
  #endif

  #ifdef TFT_BACKGROUND_IS_SOLID
    weather.fillSprite(TFT_CUSTOM_COLOR);
  #endif

  weather.setFreeFont(FF21);
  weather.setTextColor(TFT_WHITE);
  tft.setFreeFont(FF21);
  uint8_t cityname_pixels = sizeof(forecast->city_name) * 12;
  tft.setCursor((TFT_LANDSCAPE_WIDTH - (cityname_pixels / 2)) / 2, 20);
  tft.print(forecast->city_name);
  weather.setCursor(20, 15);
  weather.print("Temperature now:");
  weather.setCursor(45, 40);
  weather.print("Humidity now:");
  if(forecast)  {
    weather.setCursor(170, 40);
    weather.print(forecast->humidity[0]); //First (0) value of the humidity block (so this is the humidity right now
    weather.setCursor(180, 15);
    weather.print(forecast->temp[0]); // First(0) value of the temperature block (so this is the temp right now
    weather.setCursor(225, 15);
    weather.print("*C");
    weather.setCursor(195, 40);
    weather.print("%");
  }
  weather.pushSprite(115, 150); //Push Weather Sprite to tft
  delete forecast; //Delete forecast to be able to fill it with new values
}