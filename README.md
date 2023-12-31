Welcome to the Project Page of SoundOS!
---------------------------------------
SoundOS is a lightweight operating system
-----------------------------------------
written in C for Arduino IDE.
This project is based on the cheap, but powerful Raspberry Pico W and on an ILI9488 3.5" TFT Touchscreen,
and uses an I2C DSP integrated circuit called "ADAU1701" (from Analog Devices) to process digitally the audio signal.

 DO NOT FORGET: YOU ARE WELCOME IN THE DEV TEAM
----------------------------------------------
 
Specifications:
---------------
 - Based on the Raspberry Pico W board
 - 3.5" ILI9488 TFT Touchscreen module (with XPT2046)
 - Unlock can also be done with AS608 Generic Optical Fingerprint Sensor (optional)

Basic features:
---------------
 - You can control the DSP via the touchscreen interface (Volume, Bass, Mid, Treble)
 - You can add a fingerprint sensor to ensure the security of your music :-)
 - Based on Bodmer's OpenWeather and TFT_eSPI library (Lots of thanks to @Bodmer!)
 - Last, but not least you can activate/deactivate modules on SoundOS depending on your needs
 
Modules:
--------
 - NOW Working modules:
    - Background module (Image can be replaced(also can be solid), but can't be deactivated, must be the resolution of 480x320)
    - Lockscreen module
	- Weather forecast module

 - Coming in future releases :

   - DSP module (with the help of ADAU1701 DSP IC from AnalogDevices)
   - SD Card MP3 Player module
   - Digital Volume/Mute Control module (using the DSP ic)
   - Digital Crossover module (also using ADAU1701)
   - RGB LED Control module (using MIKROE-3078 - "RGB DRIVER CLICK")
   - Digital Potentiometer module (using MIKROE-4596 - "DIGI POT 8 CLICK")
      
Overview of modules:
--------------------
 - Simplified Block Diagram drawn by me :-D
 
 ![Alt text](/Images/SimplifiedBlockDiagram.jpg)

 - Very Simple Block Diagram drawn also by me :-D
 
 ![Alt text](/Images/VerySimplifiedBlockDiagram.jpg)

Release Notes & Versions:
-------------------------
 - Beta 0.0.1: Added Background & Lockscreen module (Sorry for bad image quality)
 
 ![Alt text](/Images/0-0-1_Beta.jpg)
 
 - v0.0.1 : Improved Background & Lockscreen module ; Added Current Weather module ; Improved sketch looking
 
 ![Alt text](/Images/v0-0-1_Fprint_Conn.gif)