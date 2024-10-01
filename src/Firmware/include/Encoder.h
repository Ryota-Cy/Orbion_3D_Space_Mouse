#ifndef ENCODER_H
#define ENCODER_H

#include <Arduino.h>

struct Encoder {
    int pinA;
    int pinB;
    int position;
};

void initEncoder(Encoder &encoder, int pinA, int pinB);
void updateEncoder(Encoder &encoder);

#endif
