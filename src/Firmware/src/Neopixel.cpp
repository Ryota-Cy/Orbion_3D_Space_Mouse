#include "Neopixel.h"

Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

void initNeoPixel() {
    pixels.begin();
    pixels.clear(); 
    pixels.show();
}

void setNeoPixelColor(int pixelIndex, const RGBColor &color) {
    if (pixelIndex < NUMPIXELS) {
        pixels.setPixelColor(pixelIndex, color.toColor());
    }
}

void showNeoPixel() {
    pixels.show();
}
