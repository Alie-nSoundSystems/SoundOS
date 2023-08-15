Welcome to the Project Page of SoundOS!
---------------------------------------
SoundOS is a lightweight operating system
-----------------------------------------
written in C for Arduino IDE.
This project is based on the cheap, but powerful Raspberry Pico W and on an ILI9488 3.5" TFT Touchscreen,
and uses an I2C modul called "MIKROE-4431" to process digitally the audio signal.

Specifications:
---------------
 - Based on the Raspberry Pico W board
 - 3.5" ILI9488 TFT Touchscreen module (with XPT2046)
 - Unlock can also be done with AS608 Generic Optical Fingerprint Sensor (optional)

Basic features:
---------------
 - You can control the DSP via the touchscreen interface (Volume, Bass, Mid, Treble)
 - You can add a fingerprint sensor to ensure the security of your music :-)
 - Based on Bodmer's OpenWeather and TFT_eSPI library (Lots of thanks to Bodmer!)
 - Last, but not least you can activate/deactivate modules on SoundOS depending on your needs
 
Modules:
--------
 - Background module (Image can be replaced, but can't be deactivated, must be the resolution of 480x320)
 - Lockscreen module
 --- Coming in future releases ---
 - Weather forecast module
 - DSP module
 - SD Card MP3 Player module
 - Digital Volume/Mute Control module (using MIKROE-4560 - "Volume 2 Click")
 - Digital Crossover module (using MIKROE-4104 - "Audio Xover Click")
 - RGB LED Control module (using MIKROE-3078 - "RGB DRIVER CLICK")
 - Digital Potentiometer module (using MIKROE-4596 - "DIGI POT 8 CLICK")
 
Versions:
---------
 - Beta 0.0.1: Added Background & Lockscreen module (Sorry for bad image quality)
 ![Alt text](/Images/0-0-1_Beta.jpg)