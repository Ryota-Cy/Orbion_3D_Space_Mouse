#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

struct Button {
    int pin;               
    bool isPressed;        
    unsigned long lastDebounceTime;  // デバウンス用のタイマー
    unsigned long debounceDelay;     // デバウンスの遅延時間
    bool lastButtonState;            // ボタンの直前の状態
};

void initButton(Button &button, int pin, unsigned long debounceDelay = 50);
void updateButton(Button &button);

#endif
