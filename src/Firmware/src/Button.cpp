#include "Button.h"

void initButton(Button &button, int pin, unsigned long debounceDelay) {
    button.pin = pin;
    button.isPressed = false;
    button.lastDebounceTime = 0;
    button.debounceDelay = debounceDelay;
    button.lastButtonState = HIGH;
    pinMode(pin, INPUT_PULLUP); 
}

void updateButton(Button &button) {
    bool currentState = digitalRead(button.pin);

    if (currentState != button.lastButtonState) {
        button.lastDebounceTime = millis();
    }

    if ((millis() - button.lastDebounceTime) > button.debounceDelay) {
        if (currentState == LOW && !button.isPressed) {
            button.isPressed = true;
        } else if (currentState == HIGH && button.isPressed) {
            button.isPressed = false;
        }
    }

    button.lastButtonState = currentState;
}
