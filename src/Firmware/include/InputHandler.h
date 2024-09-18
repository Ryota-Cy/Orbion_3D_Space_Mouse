#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "Button.h"
#include "Joystick.h"
#include "Encoder.h"

struct InputState {
    Button button1;
    Button button2;
    Button button3;
    Joystick joystick;
    Encoder encoder;
};

void initInputDevices(InputState &input);
void updateInputDevices(InputState &input);

#endif
