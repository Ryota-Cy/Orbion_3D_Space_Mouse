#include "Encoder.h"

void initEncoder(Encoder &encoder, int pinA, int pinB) {
    encoder.pinA = pinA;
    encoder.pinB = pinB;
    encoder.position = 0;
    pinMode(pinA, INPUT);
    pinMode(pinB, INPUT);
}

void updateEncoder(Encoder &encoder) {
    int aState = digitalRead(encoder.pinA);
    int bState = digitalRead(encoder.pinB);
    if (aState != bState) {
        encoder.position += (aState == HIGH) ? 1 : -1;
    }
}
