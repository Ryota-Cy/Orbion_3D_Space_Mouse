#include "Button.h"

void initButton(Button &button, int pin) {
    button.pin = pin;
    button.isPressed = false;
    pinMode(pin, INPUT_PULLUP);
}

void updateButton(Button &button) {
    button.isPressed = digitalRead(button.pin) == LOW;
}
