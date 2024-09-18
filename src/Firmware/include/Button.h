#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

struct Button {
    int pin;
    bool isPressed;
};

void initButton(Button &button, int pin);
void updateButton(Button &button);

#endif
