#include <ADXL335.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

int power = 0;
int timer = 0;
int xAvg = 0;
int yAvg = 0;
int zAvg = 0;
float offset = 120; //the higher, the more you have to move

//////////////////////////////////////////////

#define PIN            8

#define NUMPIXELS      7

int ii;

int amount = 7; //if amount is hoger dan 7 amount is 7

int num;

int changeValue = 150;

int blnk = 1;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 150; // delay for half a second

ADXL335 accelerometer;

void setup()
{
  pixels.begin(); // This initializes the NeoPixel library.
  Serial.begin(9600);
  accelerometer.begin();

  pixels.setBrightness(64);
  setColor(0, 0, 0);
  pixels.show();
}
void loop()
{
  int x, y, z;
  accelerometer.getXYZ(&x, &y, &z);
  x -= 295; y -= 705; z -= 1000;

  if ((x > (xAvg + offset) || x < (xAvg - offset)) || (y > (yAvg + offset) || y < (yAvg - offset)))
  {
    Serial.println("Movement Detected.");
    power += 5;
    timer = 30;
    xAvg = x;
    yAvg = y;
  }

  if (power < changeValue * 8) {
    colorLights();
  }

  if (timer > 0)
  {
    timer -= 0.015;
  }
  if (timer == 0)
  {
    power = 0;
    setColor(0, 0, 0);
    pixels.show();
  }
  Serial.print("Power: ");
  Serial.print(power);
  Serial.print(" | Timer: ");
  Serial.println(timer);
  delay(50);
}

void colorLights() {
  if (power >= 0 && power < changeValue) {
    reset();
  }
  else if (power >= changeValue && power < changeValue * 2 || num % 7 == 1) {
    ii = 0;
    setColor(148, 0, 211);
  }
  else if (power >= changeValue * 2 && power < changeValue * 3 || num % 7 == 2) {
    ii = 1;
    setColor(75, 0, 150);
  }
  else if (power >= changeValue * 3 && power < changeValue * 4 || num % 7 == 3) {
    ii = 2;
    setColor(0, 0, 255);
  }
  else if (power >= changeValue * 4 && power < changeValue * 5 || num % 7 == 4) {
    ii = 3;
    setColor(0, 255, 0);
  }
  else if (power >= changeValue * 5 && power < changeValue * 6 || num % 7 == 5) {
    ii = 4;
    setColor(255, 255, 0);
  }
  else if (power >= changeValue * 6 && power < changeValue * 7 || num % 7 == 6) {
    ii = 5;
    setColor(255, 150, 0);
  }
  else if (power >= changeValue * 7 && power < changeValue * 8 || num % 7 == 0) {
    ii = 6;
    setColor(255, 0 , 0);
  }
  pixels.show();
  //blnk *= -1;
}

void setColor(int r, int g, int b) {
  for (ii; ii < amount; ii++) {
    pixels.setPixelColor(ii, pixels.Color(r, g, b));
  }
}

void colorEffect() {
  colorLights();
  num ++;
}

void reset(){
    for (int i = 0; i < amount; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  }
}

