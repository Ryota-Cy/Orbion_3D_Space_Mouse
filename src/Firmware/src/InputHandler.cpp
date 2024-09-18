#include "InputHandler.h"

void initInputDevices(InputState &input) {
    initButton(input.button1, 7); 
    initButton(input.button2, 8); 
    initButton(input.button3, 9); 
    initJoystick(input.joystick, A2, A3);  // Joystick connected to analog pins A2 and A3
    initEncoder(input.encoder, 5, 4);      // Encoder connected to digital pins 5 and 4
}

void updateInputDevices(InputState &input) {
    updateButton(input.button1);
    updateButton(input.button2);
    updateButton(input.button3);
    updateJoystick(input.joystick);
    updateEncoder(input.encoder);
}
