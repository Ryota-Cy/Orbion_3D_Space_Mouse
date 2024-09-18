#ifndef DISPLAYCONTROL_H
#define DISPLAYCONTROL_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

void initDisplay();
void clearDisplay();
void displayMessage(const char* message);

#endif
