# Chasing-Colors
Chasing Colors is our product. For more information see: https://digitalsocietyschool.org/project/chasing-colors/

# Prerequisites 
To open and execute the project you will need to download [Arduino IDE](https://www.arduino.cc/en/Main/Software?)

You also need the following libaries installed:
- [Adafruit NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel)
- [ADXL335 Accelerometer](https://github.com/Seeed-Studio/Accelerometer_ADXL335)

# How to install
After downloading the .ino file, you will have to setup your ADXL libary to use the right analog ports:

### line 35-38
```c++
/*macro definitions of Analog read pins*/
#define X_AXIS_PIN A0 //RED
#define Y_AXIS_PIN A1 //GREEN
#define Z_AXIS_PIN A2 //WHITE
```

# The Circuit:
For the creatino of the circuitry we used:
- 7 Adafruit NeoPixels
- 1 Adafruit ADXL335 
- 1 Adafruit Pro Trinket - 5V 16MHz

![Schematic Picture](https://hnt.soaringnetwork.com/imgs/schematic.jpg "Chasing Colours Schematic")
