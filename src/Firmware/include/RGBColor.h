#ifndef RGBCOLOR_H
#define RGBCOLOR_H

struct RGBColor {
    uint8_t red;
    uint8_t green;
    uint8_t blue;

    // RGB値を1つにまとめた形式で返す
    uint32_t toColor() const {
        return ((uint32_t)red << 16) | ((uint32_t)green << 8) | blue;
    }
};

#endif
