#include "Joystick.h"
#include <Arduino.h>

void initJoystick(Joystick &joystick, int xPin, int yPin, int deadZone) {
    joystick.xPin = xPin;
    joystick.yPin = yPin;
    joystick.rawXValue = 0;
    joystick.rawYValue = 0;
    joystick.xValue = 0;
    joystick.yValue = 0;
    joystick.deadZone = deadZone;
    pinMode(xPin, INPUT);
    pinMode(yPin, INPUT);
}

void updateJoystick(Joystick &joystick) {
    joystick.rawXValue = analogRead(joystick.xPin);
    joystick.rawYValue = analogRead(joystick.yPin);
    
    if (abs(joystick.rawXValue - 512) < joystick.deadZone) {
        joystick.xValue = 0;
    } else {
        joystick.xValue = joystick.rawXValue;
    }
    
    if (abs(joystick.rawYValue - 512) < joystick.deadZone) {
        joystick.yValue = 0;
    } else {
        joystick.yValue = joystick.rawYValue;
    }
}
