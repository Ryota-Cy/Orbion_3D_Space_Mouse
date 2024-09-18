#ifndef NEOPIXEL_H
#define NEOPIXEL_H

#include <Adafruit_NeoPixel.h>
#include "RGBColor.h" 
#define NUMPIXELS 7       
#define LED_PIN   15        

void initNeoPixel();
void setNeoPixelColor(int pixelIndex, const RGBColor &color);  // RGBColor構造体を引数に
void showNeoPixel();

#endif
