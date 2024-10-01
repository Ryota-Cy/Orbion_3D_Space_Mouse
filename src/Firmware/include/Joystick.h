#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <Arduino.h>
#include "Button.h"

struct Joystick {
    int xPin;      
    int yPin;      
    Button button;
    int xValue;    
    int yValue;    
    int rawXValue; 
    int rawYValue;
    int deadZone;
};

void initJoystick(Joystick &joystick, int xPin, int yPin, int buttonPin, int deadZone = 20);
void updateJoystick(Joystick &joystick);

#endif
