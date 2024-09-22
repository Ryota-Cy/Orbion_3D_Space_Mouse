#ifndef JOYSTICK_H
#define JOYSTICK_H

struct Joystick {
    int xPin;      
    int yPin;      
    int xValue;    
    int yValue;    
    int rawXValue; 
    int rawYValue; 
    int deadZone;
};

void initJoystick(Joystick &joystick, int xPin, int yPin, int deadZone = 20);
void updateJoystick(Joystick &joystick);

#endif
