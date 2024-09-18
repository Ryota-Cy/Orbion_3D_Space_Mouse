#include "Joystick.h"
#include <Arduino.h>

void initJoystick(Joystick &joystick, int xPin, int yPin) {
    joystick.xPin = xPin;
    joystick.yPin = yPin;
    joystick.xValue = 0;
    joystick.yValue = 0;
    pinMode(xPin, INPUT);
    pinMode(yPin, INPUT);
}

void updateJoystick(Joystick &joystick) {
    joystick.xValue = analogRead(joystick.xPin);
    joystick.yValue = analogRead(joystick.yPin);
}
