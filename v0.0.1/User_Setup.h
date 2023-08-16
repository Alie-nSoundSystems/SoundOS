////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// SoundOS - Release v0.0.1 /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
#define TFT_LANDSCAPE_HEIGHT  320 // Your TFT's height in pixels in LANDSCAPE mode
#define TFT_LANDSCAPE_WIDTH   480 // Your TFT's width in pixels in LANDSCAPE mode
//#define TFT_BACKGROUND_IS_SOLID // Comment out to Disable Solid Backgroud ; Uncomment to Enable Solid Background
#define TFT_BACKGROUND_IS_IMAGE // Uncomment to Enable Image Background ; Comment out to Disable Image Background
#define TFT_CUSTOM_COLOR 0xB731 //You must use RGB565 Color codes (for example: https://chrishewett.com/blog/true-rgb565-colour-picker/)
//^- Select your color; copy RGB565 format code (like "#b731") ; then replace the "#" with "0x" ; you MUST get something like this "0xb731"

///////////////////////////////////////////////////////////////////////////////
///////////////// First, write here your Wi-Fi credientails ///////////////////
///////////////////////////////////////////////////////////////////////////////
const char *ssid = "HuaweiP10";
const char *password = "e2ed28be4890";

///////////////////////////////////////////////////////////////////////////////
// Second, comment out this line if you don't want to use Fingerprint Sensor //
///////////////////////////////////////////////////////////////////////////////
#define FINGERPRINT_AUTH

///////////////////////////////////////////////////////////////////////////////
#include "Declarations.h"
////////////// Third, set up Time Client to match your Timezone ///////////////
///////////////////////////////////////////////////////////////////////////////
// Do NOT edit the first parameter!
// The second parameter is the NTP Time Server (Not recommended to change).
// The third parameter is the offset from UTC (must be given in seconds).
// The fourth parameter is the Update Interval (must be in milliseconds).
NTPClient timeClient(ntpUDP, "pool.ntp.org", 7200, 10000); //europe.

///////////////////////////////////////////////////////////////////////////////
///////////// Fourth, set up OpenWeatherMap API, lat., lon., etc. //////////////
///////////////////////////////////////////////////////////////////////////////
String api_key = "9db29e54978f4f86e814859cd3f642b1"; // Put here your OpenWeatherMap API
String latitude =  "47.4980"; // Put here your city's latitude
String longitude = "19.0399"; // Put here your city's longtitude
String units = "metric"; // Choose the unit system - "metric" or "imperial"
String language = "en"; // Choose your language  <<<<<--------------------------------
/////////////////////////////////////////////////////////////////////////////////////^^\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
||||||||||||||||||||||||||||||||||||||||||||| SUPPORTED LANGUAGES(Write the 2/5 character code inside the LANGUAGE STRING) |||||||||||||||||||||||||||||||||||||||||||||
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
af: Africans, ar: Arabic, az: Azerbaijani, bg: Bulgarian, ca: Catalan, cs: Czech, da: Danish, de: German, el: Greek, en: English, eu: Basque, fa: Persian (Farsi),
fi: Finnish, fr: French, gl: Galician, he: Hebrew, hi: Hindi, hr: Croatian, hu: Hungarian, id: Indonesian, it: Italian, ja: Japanese, kr: Korean, la: Latvian,
lt: Lithuanian, mk: Macedonian, no: Norwegian Bokmål, nl: Dutch, pl: Polish, pt: Portuguese, pt_br: Português Brasil, ro: Romanian, ru: Russian, sk: Slovak,
sl: Slovenian, sp/es: Spanish, sr: Serbian, sv/se: Swedish, th: Thai, tr: Turkish, ua/uk: Ukrainian, vi: Vietnamese, zh_cn: Chinese Simplified, zh-tw: Chinese Traditional,
zu: Zulu
*/