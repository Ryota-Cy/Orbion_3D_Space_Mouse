/**********************************************************************************************/
/*	                                      Orbion Firmware                                     */
/**********************************************************************************************/
/*                                        version 0.26.5                                      */
/*                                       Since: June 2021                                     */
/*                                Creator: Mattia Russo (FaqTotum)                            */
/**********************************************************************************************/
/*                                           LICENSE                                          */
/*                                                                                            */
/*                                      (CC BY-NC-ND 4.0)                                     */
/*               CC - Attribution-NonCommercial-NoDerivatives 4.0 International               */
/**********************************************************************************************/

#include <Arduino.h>
#include "DisplayControl.h"
#include "InputHandler.h"
#include "Menu.h"
#include "Neopixel.h"

InputState inputState;

const RGBColor red = {255, 0, 0};
const RGBColor green = {0, 255, 0};
const RGBColor blue = {0, 0, 255};
const RGBColor yellow = {255, 255, 0};
const RGBColor light_blue = {0, 255, 255};

void setup() {
    Serial.begin(115200);
    initDisplay();
    initInputDevices(inputState);
    initNeoPixel();
    showMainMenu();
}

void loop() {
    updateInputDevices(inputState);

    if (inputState.button1.isPressed) {
        displayMessage("Button 1 Pressed");
        setNeoPixelColor(0, red);
        showNeoPixel();
    }

    if (inputState.button2.isPressed) {
        displayMessage("Button 2 Pressed");
        setNeoPixelColor(1, green);
        showNeoPixel();
    }

    if (inputState.button3.isPressed) {
        displayMessage("Button 3 Pressed");
        setNeoPixelColor(2, blue);
        showNeoPixel();
    }

    if (inputState.joystick.xValue > 512) {
        handleMenuSelection(1);
        setNeoPixelColor(3, yellow);
        showNeoPixel();
    } else if (inputState.joystick.yValue > 512) {
        handleMenuSelection(2);
        setNeoPixelColor(4, light_blue);
        showNeoPixel();
    }

    delay(100);
}

